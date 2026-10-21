/*STUDENT (Rollno, Name, Class, Birthdate)  
COURSE (Courseno, Coursename, Max_Marks, 
Pass_Marks)  
 SC (Rollno, Courseno, Marks) 
Create the above three tables along with key constraints.  
Write an Insert script for insertion of rows with substitution 
variables and insert Appropriate data.  
Add a constraint that the marks entered should 
strictly be between 0 and 100. Display details 
of students who take the ‘Database 
Management System’ course. 
Display the average marks obtained by each student.  
Select all courses where passing marks are more than 30% of 
average maximum mark.  
Display details of students who were born in 1980 or 1982. */
create database navaz_assignment;
use navaz_assignment;
create table STUDENT (Rollno int primary key , Name varchar(20), Class varchar(10), Birthdate date );  
