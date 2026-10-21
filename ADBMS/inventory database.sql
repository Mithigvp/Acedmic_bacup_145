CREATE DATABASE inventery;

USE inventery;

CREATE TABLE student (
    s_id INT PRIMARY KEY,
    s_name VARCHAR(20) UNIQUE key,
	gender varchar(20),
    course varchar(20) ,
    age INT ,
    parsenteg decimal
);

insert into student (s_id, s_name,genderm,course ,age,parsenteg) values(101 , 'mithilesh', 'male', 'mca', 21, 89.67);
insert into student values(102 , 'ram', 'male', 'ma', 27, 51.45);
insert into student values(103 , 'shita', 'female', 'ba', 51, 49.55);
insert into student values(104 , 'radha', 'female', 'bca', 61, 29.78);
insert into student values(105 , 'krishana', 'male', 'ma', 21, 54.54);
insert into student values(106 , 'maya', 'female', 'mca', 12, 74.97);
insert into student values(107 , 'meera', 'female', 'bca', 19, 79.67);
insert into student values(108 , 'kavi', 'male', 'ma', 41, 45.67);

select * from student;
 
