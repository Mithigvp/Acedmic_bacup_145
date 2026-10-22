create table book_catalog (
    book_code int primary key,
    title varchar(100),
    publisher_name varchar(100),
    category_name varchar(50),
    yr_of_release int,
    total_copies int
);

create table member (
    member_code int primary key,
    member_name varchar(100),
    mem_ship_dt date
);

create table issue (
    issue_id int primary key,
    member_code int,
    book_code int,
    issu_ret char(1)
        check (issu_ret in ('i', 'r')),
    issue_date date,
    issue_ret_dt date
);

insert into book_catalog values (101, 'dbms', 'pearson', 'education', 2022, 10);
insert into book_catalog values (102, 'oracle sql', 'mcgraw hill', 'education', 2023, 8);
insert into book_catalog values (103, 'java programming', 'bpb', 'programming', 2021, 5);
insert into book_catalog values (104, 'python basics', 'oreilly', 'programming', 2024, 12);
insert into book_catalog values (105, 'computer networks', 'pearson', 'networking', 2020, 6);
insert into book_catalog values (106, 'operating systems', 'wiley', 'education', 2022, 7);
insert into book_catalog values (107, 'data structures', 'mcgraw hill', 'programming', 2023, 9);
insert into book_catalog values (108, 'web development', 'bpb', 'programming', 2024, 4);



insert into member values (1, 'amit sharma', to_date('11-10-2026', 'dd-mm-yyyy'));
insert into member values (2, 'priya verma', to_date('21-09-2026', 'dd-mm-yyyy'));
insert into member values (3, 'rahul singh', to_date('22-08-2026', 'dd-mm-yyyy'));
insert into member values (4, 'neha gupta', to_date('13-07-2026', 'dd-mm-yyyy'));
insert into member values (5, 'rohit kumar', to_date('24-05-2026', 'dd-mm-yyyy'));
insert into member values (6, 'sneha joshi', to_date('16-10-2026', 'dd-mm-yyyy'));
insert into member values (7, 'vikas rawat', to_date('04-04-2026', 'dd-mm-yyyy'));
insert into member values (8, 'anjali mehta', to_date('06-09-2026', 'dd-mm-yyyy'));


insert into issue values (1001, 1, 101, 'i', to_date('01-10-2026', 'dd-mm-yyyy'), to_date('15-10-2026', 'dd-mm-yyyy'));
insert into issue values (1002, 2, 102, 'i', to_date('06-10-2026', 'dd-mm-yyyy'), to_date('18-10-2026', 'dd-mm-yyyy'));
insert into issue values (1003, 3, 103, 'r', to_date('11-09-2026', 'dd-mm-yyyy'), to_date('21-09-2026', 'dd-mm-yyyy'));
insert into issue values (1004, 4, 104, 'i', to_date('11-10-2026', 'dd-mm-yyyy'), to_date('26-10-2026', 'dd-mm-yyyy'));
insert into issue values (1005, 5, 105, 'r', to_date('01-09-2026', 'dd-mm-yyyy'), to_date('16-09-2026', 'dd-mm-yyyy'));
insert into issue values (1006, 6, 101, 'i', to_date('09-10-2026', 'dd-mm-yyyy'), to_date('19-10-2026', 'dd-mm-yyyy'));
insert into issue values (1007, 7, 106, 'i', to_date('26-09-2026', 'dd-mm-yyyy'), to_date('11-10-2026', 'dd-mm-yyyy'));
insert into issue values (1008, 8, 107, 'r', to_date('03-10-2026', 'dd-mm-yyyy'), to_date('13-10-2026', 'dd-mm-yyyy'));
insert into issue values (1009, 1, 102, 'i', to_date('13-10-2026', 'dd-mm-yyyy'), to_date('28-10-2026', 'dd-mm-yyyy'));
insert into issue values (1010, 2, 108, 'r', to_date('21-09-2026', 'dd-mm-yyyy'), to_date('01-10-2026', 'dd-mm-yyyy'));
insert into issue values (1011, 3, 105, 'i', to_date('07-10-2026', 'dd-mm-yyyy'), to_date('20-10-2026', 'dd-mm-yyyy'));
insert into issue values (1012, 6, 103, 'i', to_date('16-10-2026', 'dd-mm-yyyy'), to_date('31-10-2026', 'dd-mm-yyyy'));

-- 1

select b.*, m.member_name, i.issue_date, i.issue_ret_dt
from book_catalog b
join issue i on b.book_code = i.book_code
join member m on i.member_code = m.member_code
where i.issu_ret = 'i'
  and i.issue_ret_dt < sysdate
order by i.issue_ret_dt;

-- 2

select count(*) as total_members
from member
where mem_ship_dt >= add_months(sysdate, -3)
  and mem_ship_dt <= sysdate;
  
-- 3

create or replace function bhindi (
    p_book_code in number
)
return number
is
    v_total number;
    v_issued number;
begin
    select total_copies
    into v_total
    from book_catalog
    where book_code = p_book_code;

    select count(*)
    into v_issued
    from issue
    where book_code = p_book_code
      and issu_ret = 'i';

    return v_total - v_issued;
end;
/

select bhindi(101) as available_copies from dual;


-- 4

create or replace package book_package as
    function get_book_title (
        p_book_code in number
    )
    return varchar2;
end book_package;
/

-- 5

create or replace package body book_package as

    function get_book_title(
        p_book_code in number
    )
    return varchar2
    is
        v_title varchar2(100);
    begin
        select title
        into v_title
        from book_catalog
        where book_code = p_book_code;

        return v_title;
    end get_book_title;

end book_package;
/


select book_package.get_book_title(101) as book_title from dual;

