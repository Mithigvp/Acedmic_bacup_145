
-- 1. CREATE TABLES

create table department_master (
    dept_code varchar2(10) primary key,
    dept_name varchar2(50) not null
);

create table employee_master (
    empcode       varchar2(10) primary key,
    emp_name      varchar2(50) not null,
    dept_id       varchar2(10),
    emp_address   varchar2(100),
    dob           date,
    basic_salary  number(10, 2),
    constraint fk_emp_dept
        foreign key (dept_id)
        references department_master(dept_code)
);

-- Insert Department 


insert into department_master values ('d101', 'administration');
insert into department_master values ('d102', 'computer science');
insert into department_master values ('d103', 'accounting');
insert into department_master values ('d104', 'sales');
insert into department_master values ('d105', 'software development');
insert into department_master values ('d106', 'transportation');
insert into department_master values ('d107', 'legal services');
insert into department_master values ('d108', 'customer relations');
insert into department_master values ('d109', 'production');
insert into department_master values ('d110', 'testing');

select * from department_master;


-- Insert Employee 
insert into employee_master
values ('e1001', 'amit shah', 'd101', '15 cg road, ahmedabad',
        to_date('1990-02-10', 'yyyy-mm-dd'), 35000.00);

insert into employee_master
values ('e1002', 'riya desai', 'd102', '22 satellite road, ahmedabad',
        to_date('1995-06-18', 'yyyy-mm-dd'), 52000.00);

insert into employee_master
values ('e1003', 'jay patel', 'd103', '8 maninagar, ahmedabad',
        to_date('1988-11-25', 'yyyy-mm-dd'), 46000.00);

insert into employee_master
values ('e1004', 'isha modi', 'd104', '31 vastrapur, ahmedabad',
        to_date('1993-04-12', 'yyyy-mm-dd'), 40000.00);

insert into employee_master
values ('e1005', 'rahul joshi', 'd105', '17 navrangpura, ahmedabad',
        to_date('1989-09-20', 'yyyy-mm-dd'), 65000.00);

insert into employee_master
values ('e1006', 'neha trivedi', 'd102', '42 thaltej, ahmedabad',
        to_date('1996-01-08', 'yyyy-mm-dd'), 58000.00);

insert into employee_master
values ('e1007', 'karan parmar', 'd106', '19 bopal, ahmedabad',
        to_date('1992-07-14', 'yyyy-mm-dd'), 38000.00);

insert into employee_master
values ('e1008', 'meera raval', 'd105', '26 chandkheda, ahmedabad',
        to_date('1991-12-03', 'yyyy-mm-dd'), 62000.00);

insert into employee_master
values ('e1009', 'dhruv bhatt', 'd107', '11 paldi, ahmedabad',
        to_date('1994-03-22', 'yyyy-mm-dd'), 48000.00);

insert into employee_master
values ('e1010', 'kavya pandya', 'd108', '36 gota, ahmedabad',
        to_date('1997-08-16', 'yyyy-mm-dd'), 32000.00);


-- Create View containing Employee details along with Department Name

create or replace view vw_dept_basic as
select
    e.empcode,
    e.emp_name,
    d.dept_name,
    e.basic_salary
from employee_master e
join department_master d
    on e.dept_id = d.dept_code;

select * from vw_dept_basic;


-- Query to find employees who do NOT belong to Department D102 or D105

select empcode, emp_name, dept_id, basic_salary
from employee_master

minus

select empcode, emp_name, dept_id, basic_salary
from employee_master
where dept_id in ('d102', 'd105');

-- B: PL/SQL BLOCK FOR SALARY SLIP REPORT

set serveroutput on;
set define on;

declare
    v_emp_code     varchar2(50) := '&enter_empcode';

    v_emp_name     employee_master.emp_name%type;
    v_dept_name    department_master.dept_name%type;
    v_basic_salary employee_master.basic_salary%type;

    v_hra          number(12, 2);
    v_da           number(12, 2);
    v_medical      number(12, 2);
    v_pf           number(12, 2);
    v_deductions   number(12, 2);
    v_total_salary number(12, 2);

begin
    select e.emp_name, d.dept_name, e.basic_salary
    into v_emp_name, v_dept_name, v_basic_salary
    from employee_master e
    join department_master d
        on e.dept_id = d.dept_code
    where e.empcode = v_emp_code;

    -- calculate allowances and deductions

    v_hra        := v_basic_salary * 0.15;
    v_da         := v_basic_salary * 0.30;
    v_medical    := v_basic_salary * 0.01;
    v_pf         := v_basic_salary * 0.10;
    v_deductions := v_pf;
    
-- PF acts as deduction
    
    -- Total Salary = Basic + Allowances - Deductions
    v_total_salary := (v_basic_salary + v_da + v_hra + v_medical) - v_deductions;

-- Display Salary Slip Report
    dbms_output.put_line('===================================================');
    dbms_output.put_line('          salary slip for the month march 2012');
    dbms_output.put_line('===================================================');
    dbms_output.put_line('employee code:   ' || v_emp_code);
    dbms_output.put_line('employee name:   ' || v_emp_name);
    dbms_output.put_line('department name: ' || v_dept_name);
    dbms_output.put_line('___________________________________________________');
    dbms_output.put_line('basic salary: ' ||to_char(v_basic_salary, '999,999,990.00'));
    dbms_output.put_line('da (30%):     ' ||to_char(v_da, '999,999,990.00'));
    dbms_output.put_line('hra (15%):    ' ||to_char(v_hra, '999,999,990.00'));
    dbms_output.put_line( 'medical (1%): ' || to_char(v_medical, '999,999,990.00'));
    dbms_output.put_line('p.f. (10%):   ' ||to_char(v_pf, '999,999,990.00'));
    dbms_output.put_line( '___________________________________________________');
    dbms_output.put_line('deductions:   ' ||to_char(v_deductions, '999,999,990.00'));
    dbms_output.put_line('total salary: ' ||to_char(v_total_salary, '999,999,990.00'));
    dbms_output.put_line('===================================================');

exception
    when no_data_found then
        dbms_output.put_line(
            'error: employee with code "' ||
            v_emp_code || '" does not exist.');

    when others then
        dbms_output.put_line(
            'an unexpected error occurred: ' || sqlerrm);
end;
/