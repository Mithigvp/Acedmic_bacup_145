create database applicant;
use applicant;

create table applicant (
    aid varchar(10) primary key,
    aname varchar(30),
    addr varchar(40),
    abirth_dt date
);

create table entrance_test (
    etid int primary key,
    etname varchar(40),
    max_score int,
    cut_score int
);

create table etest_centre (
    etcid int primary key,
    location varchar(30),
    incharge varchar(30),
    capacity int
);

create table etest_details (
    aid varchar(10),
    etid int,
    etcid int,
    etest_dt date check(weekday(etest_dt)!=6),
    score int,
    foreign key (aid) references applicant(aid),
    foreign key (etid) references entrance_test(etid),
    foreign key (etcid) references etest_centre(etcid)
);

insert into  applicant (aid,aname,addr,abirth_dt) values
('1121', 'Mithilesh', 'Navsari',  '1998-05-12'),
('1122', 'Amin', 'surat',  '1998-05-12'),
('1123', 'Jaydev', 'Mumbai',  '1998-05-12'),
('1124', 'Rahul', 'Pune',  '1999-02-15'),
('1125', 'Priya', 'Mumbai',  '1998-08-20'),
('1126', 'Amit', 'Delhi',  '1997-11-10'),
('1127', 'Sneha', 'Pune',  '1999-01-25');

insert into entrance_test (etid,etname,max_score,cut_score) values
	(1, 'Oracle Fundamentals', 100, 30),
	(2, 'DBMS', 100, 30),
	(3, 'DSA', 100, 30),
	(4, 'JAVA', 100, 30),
    (5, 'Full stack', 100, 30);

insert into etest_centre(etcid,location,incharge,capacity) values
	(101, 'Mumbai', 'Mr. Sharma', 3),
    (102, 'Pune', 'Mr. Jadeja', 3),
	(103, 'Delhi', 'Mr. Patel', 2),
	(104, 'Nashik', 'Mr. Shah', 5),
    (105, 'Nashik', 'Mr. Parmar', 5);

insert into etest_details(aid,etid,etcid,etest_dt,score) values
	('A1127', 2, 102, '2011-11-11', 25),
	('A1124', 1, 101, '2011-11-02', 78),
    ('A1123', 1, 101, '2011-11-01', 89),
    ('A1122' ,1, 103, '2011-11-02', 89),
	('A1121', 1, 101, '2011-11-01', 75),
    ('A1122' ,2, 102, '2011-11-02', 87),
    ('A1123', 3, 103, '2011-11-01', 75),
    ('A1124', 3, 101, '2011-11-02', 76),
    ('A1125', 1, 102, '2011-11-02', 60),
    ('A1126', 1, 103, '2011-11-03', 35),
    ('A1127', 5, 102, '2011-11-04', 80),
    ('A1123', 2, 101, '2011-11-05', 70),
    ('A1124', 2, 101, '2011-11-05', 45),
    ('A1125', 5, 102, '2011-11-07', 55),
    ('A1126', 2, 103, '2011-11-07', 30),
    ('A1127', 2, 102, '2011-11-08', 65),
    ('A1123', 3, 101, '2011-11-09', 80),
    ('A1124', 3, 101, '2011-11-10', 60),
	('A1124', 4, 102, '2011-11-11', 75),
    ('A1124', 5, 101, '2011-11-12', 55),
    ('A1127', 4, 102, '2011-11-14', 70),
	('A1121', 5, 101, '2011-11-14', 68),
	('A1122', 4, 102, '2011-11-15', 79);


-- 1
alter table etest_details modify aid varchar(10);
set sql_safe_updates=0;
update applicant set aid = concat('A' , aid) where 1=1;

select * from etest_details;


-- 2
select * from etest_centre
where etcid not in (select distinct etcid from etest_details where etcid );

-- 3

select ap.*, et.etname, ed.score from applicant  ap 
join etest_details  ed on ap.aid = ed.aid
join entrance_test  et on ed.etid = et.etid
where et.etname = 'Oracle Fundamentals' 
and ed.score = (
select ed2.score from applicant  ap2
join etest_details  ed2 on ap2.aid = ed2.aid
join entrance_test  et2 on ed2.etid = et2.etid
where ap2.aname = 'Jaydev' and et2.etname = 'Oracle Fundamentals');

-- 4
select a.aid, a.aname, a.addr, a.abirth_dt FROM Applicant as a
join  etest_details ed on a.aid = ed.aid
group by a.aid, a.aname, a.addr, a.abirth_dt
having  count(distinct ed.etid) = (select count(distinct etid) from entrance_test);

-- 5

select et.* from entrance_test as et 
where etid not in (select distinct ed.etid from etest_details  ed 
join entrance_test as et 
on ed.etid = et.etid
where ed.score < et.cut_score
);

-- 6
select ec.* from etest_centre as ec
join etest_details as ed on ec.etcid = ed.etcid
where ed.etest_dt between '2011-11-01' and '2011-11-15'
group by ec.etcid, ec.location, ec.incharge, ec.capacity
having count(ed.aid) >= ec.capacity;

-- 7
select ap.* from applicant  ap
where ap.aid not in (select distinct ed.aid from etest_details  ed 
join entrance_test  et 
on ed.etid = et.etid
where ed.score <= et.cut_score
);

-- 8
select et.etid, et.etname, avg(ed.score) as average_score, MAX(ed.score) as maximum_score 
from etest_details ed 
join  entrance_test et on ed.etid = et.etid
join  etest_centre ec on ed.etcid = ec.etcid
where location ="Mumbai" 
group by et.etid , et.etname;

 -- 9
select et.etname, ec.location, COUNT(ed.aid) AS number_of_applicants
from etest_details ed
join entrance_test et on ed.etid = et.etid
join etest_centre ec on ed.etcid = ec.etcid
group by et.etname, ec.location;
