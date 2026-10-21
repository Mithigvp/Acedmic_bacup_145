create database worker_manegment;
use worker_manegment;

create table worker
(
    worker_id       int primary key,
    name            varchar(50),
    wage_per_hour   int,
    specialised_in  varchar(50),
    manager_id      int
);


create table job
(
    job_id       int primary key,
    type_of_job  varchar(50),
    status       varchar(20)
);


create table job_assigned
(
    worker_id       int,
    job_id          int,
    starting_date   date,
    number_of_days  int,

    primary key (worker_id, job_id),

    foreign key (worker_id)
        references worker(worker_id),

    foreign key (job_id)
        references job(job_id)
);




insert into worker
values (1, 'rahul', 500, 'electrical', null);
insert into worker
values (2, 'amit', 450, 'plumbing', 1);
insert into worker
values (3, 'raj', 400, 'carpentry', 1);
insert into worker
values (4, 'vijay', 550, 'electrical', 1);
insert into worker
values (5, 'karan', 600, 'painting', 1);



insert into job
values (101, 'building construction', 'running');
insert into job
values (102, 'electrical work', 'running');
insert into job
values (103, 'road construction', 'complete');
insert into job
values (104, 'plumbing work', 'pending');



insert into job_assigned
values (1, 101, date '2026-08-10', 30);
insert into job_assigned
values (2, 101, date '2026-08-10', 20);
insert into job_assigned
values (3, 102, date '2026-08-15', 15);
insert into job_assigned
values (4, 103, date '2010-05-10', 20);
insert into job_assigned
values (5, 104, date '2026-08-30', 10);



select
    w.worker_id,
    w.name,
    ja.job_id,
    ja.starting_date,
    ja.starting_date + ja.number_of_days as ending_date
from worker w
join job_assigned ja
on w.worker_id = ja.worker_id;



select
    w.worker_id,
    w.name,
    ja.job_id,
    ja.starting_date + ja.number_of_days as ending_date,
    greatest(
        (ja.starting_date + ja.number_of_days)
        - trunc(sysdate),
        0
    ) as days_remaining
from worker w
join job_assigned ja
on w.worker_id = ja.worker_id;



select
    worker_id,
    job_id,

    'the ' ||

    case
        when to_char(starting_date,'dd') = '01'
            then 'first'
        when to_char(starting_date,'dd') = '02'
            then 'second'
        when to_char(starting_date,'dd') = '03'
            then 'third'
        when to_char(starting_date,'dd') = '04'
            then 'fourth'
        when to_char(starting_date,'dd') = '05'
            then 'fifth'
        when to_char(starting_date,'dd') = '06'
            then 'sixth'
        when to_char(starting_date,'dd') = '07'
            then 'seventh'
        when to_char(starting_date,'dd') = '08'
            then 'eighth'
        when to_char(starting_date,'dd') = '09'
            then 'ninth'
        when to_char(starting_date,'dd') = '10'
            then 'tenth'
        when to_char(starting_date,'dd') = '11'
            then 'eleventh'
        when to_char(starting_date,'dd') = '12'
            then 'twelfth'
        when to_char(starting_date,'dd') = '13'
            then 'thirteenth'
        when to_char(starting_date,'dd') = '14'
            then 'fourteenth'
        when to_char(starting_date,'dd') = '15'
            then 'fifteenth'
        when to_char(starting_date,'dd') = '16'
            then 'sixteenth'
        when to_char(starting_date,'dd') = '17'
            then 'seventeenth'
        when to_char(starting_date,'dd') = '18'
            then 'eighteenth'
        when to_char(starting_date,'dd') = '19'
            then 'nineteenth'
        when to_char(starting_date,'dd') = '20'
            then 'twentieth'
        when to_char(starting_date,'dd') = '21'
            then 'twenty-first'
        when to_char(starting_date,'dd') = '22'
            then 'twenty-second'
        when to_char(starting_date,'dd') = '23'
            then 'twenty-third'
        when to_char(starting_date,'dd') = '24'
            then 'twenty-fourth'
        when to_char(starting_date,'dd') = '25'
            then 'twenty-fifth'
        when to_char(starting_date,'dd') = '26'
            then 'twenty-sixth'
        when to_char(starting_date,'dd') = '27'
            then 'twenty-seventh'
        when to_char(starting_date,'dd') = '28'
            then 'twenty-eighth'
        when to_char(starting_date,'dd') = '29'
            then 'twenty-ninth'
        when to_char(starting_date,'dd') = '30'
            then 'thirtieth'
        when to_char(starting_date,'dd') = '31'
            then 'thirty-first'
    END
    || ' day of the month of ' ||
    trim(to_char(starting_date,'month'))
    || ', ' ||
    to_char(starting_date,'yyyy')
    as starting_date_in_words
from job_assigned;


update job
set status = 'complete'
where job_id in
(
    select job_id
    from job_assigned
    where extract(year from starting_date) = 2010
);


select * from job;


select
    j.job_id,
    j.type_of_job,
    j.status,
    count(ja.worker_id) as number_of_workers
from job j
join job_assigned ja
on j.job_id = ja.job_id
group by
    j.job_id,
    j.type_of_job,
    j.status
having count(ja.worker_id) <= 1;


select
    job_id,
    type_of_job,
    status
from job
where status = 'complete';


-- select
--     j.job_id,
--     j.type_of_job,
--     j.status,
--     ja.starting_date
-- from job j
-- join job_assigned ja
-- on j.job_id = ja.job_id
-- where ja.starting_date
-- between trunc(sysdate)
-- and trunc(sysdate) + 14;
