create table account (
    ac_no number primary key,
    ac_name varchar2(50),
    act_type char(1) check (act_type in ('s', 'c'))
);

create table transaction (
    ac_no number references account(ac_no),
    trans_date date,
    tran_type char(1) check (tran_type in ('d', 'w')),
    tran_amount number(10, 2),
    balance number(10, 2)
);

insert into account(ac_no, ac_name, act_type) values 
 (101, 'mithilesh', 's'),
 (102, 'parth','c'),
 (103 , 'Krish','s'),
 (104 , 'nikhil','c'),
 (105, 'vishal', 's');


insert into transaction (ac_no, trans_date, tran_type, tran_amount,balance) 
values 
(101, to_date('12-jan-2011', 'dd-mon-yyyy'), 'w', 60000, 40000),
(101, to_date('15-jan-2011', 'dd-mon-yyyy'), 'w', 30000, 10000),
(102, to_date('18-jan-2011', 'dd-mon-yyyy'), 'w', 75000, 25000),
(103, to_date('21-feb-2011', 'dd-mon-yyyy'), 'd', 51000, 12000),
(104, to_date('18-feb-2011', 'dd-mon-yyyy'), 'w', 56000, 43000),
(104, to_date('01-jan-2011', 'dd-mon-yyyy'), 'd', 51000, 56000),
(105, to_date('16-jan-2011', 'dd-mon-yyyy'), 'w', 54000, 65000),
(102, to_date('19-jan-2011', 'dd-mon-yyyy'), 'w', 34000, 33000);



-- 1
select t.ac_no, a.ac_name, t.trans_date,
t.tran_type, t.tran_amount, t.balance
from transaction t
join account a on t.ac_no = a.ac_no
where lower(a.act_type) = 's'
and lower(t.tran_type) = 'w' and t.tran_amount > 50000
and t.trans_date between to_date('10-01-2011', 'dd-mm-yyyy') 
and to_date('20-01-2011', 'dd-mm-yyyy');



-- 2
create sequence seq_ac_no
start with 106
increment by 1;
insert into account (ac_no, ac_name, act_type)
values (seq_ac_no.nextval, 'amit', 's');

select * from account;


-- 3
create or replace trigger check_time
before insert or update or delete on account
begin
if to_char(sysdate, 'fmday', 'nls_date_language=english') = 'saturday'
    or to_number(to_char(sysdate, 'hh24')) < 8 
    or to_number(to_char(sysdate, 'hh24')) >= 18 then
    raise_application_error(-20001, 'dml operations on account table are no
    t allowed on saturday or outside 8:00 am to 6:00 pm');
end if;
end;
/



-- 4
create or replace package pack as
    function get_balance(p_ac_no in number) return number;
end pack;
/

create or replace package body pack as
    function get_balance(p_ac_no in number) return number is
        v_balance number(10, 2);
    begin
        select balance
        into v_balance
        from ( 
            select balance
            from transaction
            where ac_no = p_ac_no
            order by trans_date desc
        )
        where rownum = 1;
        return v_balance;
    exception
        when no_data_found then
            return null;
    end get_balance;
end pack;
/


select pack.get_balance(101) as current_balance 
from dual;





