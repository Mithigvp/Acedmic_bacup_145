 use stude;

-- CREATE table test(
-- 	id int,
-- 	rollNo int,
-- 	primary key (id , rollNo)
-- );

-- create table demo (id json);

-- insert into demo values('{"id":"01"}');

-- insert into demo values('{"name" : "xyz", "course" : "MCA"} ');

-- select * from demo;

-- alter table test drop primary key;

-- alter table test add constraint primary key(id) ;

create table student (
s_id int primary key,
s_name varchar(20),
s_mark int 
);

insert into student values(101 , 'mithilesh' , 89);
insert into student values(102 , 'mitesh' , 98);
insert into student values(103 , 'ram' , 79);
insert into student values(104 , 'raghu' , 78);
insert into student values(105 , 'syam' , 96);


-- select * from student where s_mark between 0 and 80;

-- select * from student where s_name  LIKE 'm%';
-- select * from student where s_name  LIKE '%sh';
-- select * from student where s_name  LIKE '%a%';

-- select * from student where s_name like '_a%';

-- select * from student where s_mark not in(89); 

-- alter table student add column s_email varchar(30);


   -- alter table student add constraint unique(s_email);

   UPDATE student 
SET s_email = CASE s_id
    WHEN 1 THEN 'mithilesh@gmail.com'
    WHEN 2 THEN 'mitesh@gmail.com'
    WHEN 3 THEN 'ram@gmail.com'
    WHEN 4 THEN 'raghu@gmail.com'
    WHEN 5 THEN 'syam@gmail.com'
END
WHERE s_id IN (1, 2, 3, 4, 5);


   
   





