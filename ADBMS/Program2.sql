-- CREATE DATABASE Studemt_Managment; 
USE Studemt_Managment; 


-- CREATE TABLE STUDENT( 
--     Rollno int primary key, 
--     Sname varchar(20) not null UNIQUE, 
--     Class varchar (20), 
--     Birthdate date not null 
-- ); 


-- CREATE TABLE COURSE( 
--     Courseno int primary key, 
--     Coursename varchar(20) not null UNIQUE, 
--     Max_Marks int not null, 
--     Pass_Marks int not null 
-- ); 

-- CREATE TABLE SC( 
--     Rollno int, 
--     Courseno int, 
--     Marks int not null CHECK (Marks >= 0 AND Marks <= 100), 
--     PRIMARY KEY (Rollno, Courseno), 
--     foreign key (Rollno) references STUDENT(Rollno), 
--     foreign key (Courseno) references COURSE(Courseno) 
-- ); 

-- INSERT INTO STUDENT (Rollno, Sname, Class, Birthdate) VALUES 
-- (101, 'mithilesh', 'FY_MCA', '1980-08-11'), 
-- (102, 'parth', 'TY_Database Management System', '1985-01-10'), 
-- (103, 'veer', 'FY_BCA', '1981-06-18'), 
-- (104, 'nikhil', 'SY_Database Management System', '1983-02-11'), 
-- (105, 'samir', 'SY_MCA', '1981-02-08'), 
-- (106, 'manav', 'SY_BCA', '1982-05-17'), 
-- (107, 'krish', 'FY_Database Management System', '1985-09-23'), 
-- (108, 'navin', 'TY_BCA', '1981-06-14'); 

-- INSERT INTO COURSE (Courseno, Coursename, Max_Marks, Pass_Marks) VALUES 
-- (1, 'MCA', 100, 35), 
-- (2, 'Database Management System', 100, 30), 
-- (3, 'BCA', 100, 30); 

-- INSERT INTO SC (Rollno, Courseno, Marks) VALUES 
-- (101, 1, 89), 
-- (102, 2, 70), 
-- (103, 3, 50), 
-- (104, 2, 95), 
-- (105, 1, 28), 
-- (106, 3, 25), 
-- (107, 2, 49), 
-- (108, 2, 94);


SELECT stu.*, cor.Coursename AS Coursename 
FROM STUDENT AS stu
INNER JOIN SC ON stu.Rollno = SC.Rollno
INNER JOIN COURSE AS cor ON SC.Courseno = cor.Courseno
WHERE cor.Coursename = 'MCA';


SELECT stu.Rollno, stu.Sname AS Student_Name, 
AVG(SC.Marks) AS Average_Marks
FROM STUDENT AS stu
INNER JOIN SC AS SC ON stu.Rollno = SC.Rollno
GROUP BY stu.Rollno, stu.Sname;


SELECT * FROM COURSE
WHERE Pass_Marks > (SELECT AVG(Max_Marks) * 0.30 FROM COURSE);


SELECT Rollno, Sname, Birthdate 
FROM STUDENT
WHERE Birthdate BETWEEN '1980-01-01' AND '1982-12-31';

CREATE VIEW Student_Course_Marks AS
SELECT st.Rollno,st.Sname AS Student_Name,sc.Courseno,sc.Marks
FROM SC AS sc INNER JOIN STUDENT AS st ON sc.Rollno = st.Rollno;

SELECT * FROM Student_Course_Marks;

