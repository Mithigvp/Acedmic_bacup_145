CREATE DATABASE IF NOT EXISTS HostelManagement;
USE HostelManagement;

CREATE TABLE HOSTEL (
    Hno INT PRIMARY KEY,
    Hname VARCHAR(100) NOT NULL,
    Haddress VARCHAR(255),
    Total_Capacity INT,
    Warden_nm VARCHAR(100)
);

CREATE TABLE ROOM (
    Hno INT,
    RNo INT,
    RType VARCHAR(50),
    Location varchar(50),
    No_Of_Students INT,
    Status VARCHAR(20) DEFAULT 'Vacant',
    PRIMARY KEY (Hno, RNo),
    FOREIGN KEY (Hno) REFERENCES HOSTEL(Hno) ON DELETE CASCADE
    );
    
    CREATE TABLE STUDENT (
    Sid INT PRIMARY KEY,
    Sname VARCHAR(100) NOT NULL,
    Saddr VARCHAR(255),
    Faculty VARCHAR(100),
    Dept VARCHAR(100),
    Class VARCHAR(50),
	Hno INT,
	RNo INT,
    FOREIGN KEY (Hno, RNo) REFERENCES ROOM(Hno, RNo) ON DELETE SET NULL
);

CREATE TABLE CHARGES (
    Hno INT,
    Rtype VARCHAR(20),
    Charges DECIMAL(10,2) NOT NULL,
    PRIMARY KEY (Hno, Rtype),
    FOREIGN KEY (Hno)REFERENCES HOSTEL(Hno)ON DELETE CASCADE,
    CHECK (Rtype IN ('Single', 'Double', 'Four')),
    CHECK (Charges > 0)
);

CREATE TABLE FEES (
    Sid INT  PRIMARY KEY,
    FDate DATE,
     Famount DECIMAL(10, 2),
    FOREIGN KEY (Sid) REFERENCES STUDENT(Sid) ON DELETE CASCADE
);

INSERT INTO HOSTEL(Hno, Hname, Haddress, Total_Capacity, Warden_Nm)VALUES
(1, 'Chanakya', 'Ahmedabad', 100, 'Dr. Rajesh Kumar'),
(2, 'Ashoka', 'Gandhinagar', 80, 'Mr. Amit Shah'),
(3, 'Vivekanand', 'Vadodara', 120, 'Dr. Sunita Patel');


INSERT INTO ROOM (Hno, RNo, RType, Location, No_Of_Students,Status) VALUES
(1, 101, 'Single', 'Ground Floor', 1, 'Occupied'),
(1, 102, 'Double', 'Ground Floor', 2, 'Occupied'),
(1, 103, 'Double', 'First Floor', 1, 'Occupied'),
(1, 104, 'Four', 'First Floor', 0, 'Vacant'),
(1, 105, 'Single', 'Second Floor', 0, 'Vacant'),
(2, 201, 'Single', 'Ground Floor', 1, 'Occupied'),
(2, 202, 'Double', 'Ground Floor', 2, 'Occupied'),
(2, 203, 'Four', 'First Floor', 0, 'Vacant'),
(2, 204, 'Double', 'First Floor', 1, 'Occupied'),
(3, 301, 'Single', 'Ground Floor', 1, 'Occupied'),
(3, 302, 'Double', 'Ground Floor', 2, 'Occupied'),
(3, 303, 'Four', 'First Floor', 0, 'Vacant');


INSERT INTO STUDENT (Sid, Sname, Saddr, Faculty, Dept,Class,Hno,RNo) VALUES
(101, 'Mithilesh', 'Navsari', 'Engineering','Computer Science', '3rd', 1, 102),
(102, 'Priya', 'Surat', 'Engineering','Computer Science', '3rd', 1, 102),
(103, 'Amit', 'Rajkot', 'Science','Physics', '2nd', 1, 101),
(104, 'Neha', 'Ahmedabad', 'Engineering','Computer Science', '4th', 1, 103),
(105, 'Karan', 'Vadodara', 'Medical','Medical', '3rd', 2, 202),
(106, 'Riya', 'Surat', 'Medical','Medical', '2nd', 2, 202),
(107, 'Arjun', 'Ahmedabad', 'Commerce','Commerce', '3rd', 2, 201),
(108, 'Pooja', 'Vadodara', 'Engineering','Computer Science', '4th', 2, 204),
(109, 'Vikas', 'Rajkot', 'Medical','Medical', '3rd', 3, 302),
(110, 'Meera', 'Ahmedabad', 'Medical','Medical', '2nd', 3, 302);


INSERT INTO CHARGES (Hno, Rtype, Charges) VALUES
 (1, 'Single', 30000),
 (1, 'Double', 20000),
 (1, 'Four', 15000),
 (2, 'Single', 28000),
 (2, 'Double', 19000),
 (2, 'Four', 14000),
 (3, 'Single', 32000),
 (3, 'Double', 22000),
 (3, 'Four', 16000);

INSERT INTO FEES (Sid, FDate, Famount) VALUES
(101, '2011-11-05', 20000),
(102, '2011-11-10', 20000),
(103, '2011-10-15', 30000),
(104, '2011-11-20', 20000),
(105, '2011-09-12', 19000),
(106, '2011-11-08', 19000),
(107, '2011-12-01', 28000),
(108, '2011-11-25', 19000),
(109, '2011-10-10', 22000),
(110, '2011-11-15', 22000);
 
 
 -- 1.
 
SELECT COUNT(*) AS Total_Vacant_Rooms
FROM ROOM
WHERE Status = 'Vacant';


-- 2.

SELECT H.Hname, COUNT(S.Sid) AS Double_Seated_Students
FROM HOSTEL H
JOIN ROOM R ON H.Hno = R.Hno
LEFT JOIN STUDENT S ON R.Hno = S.Hno
AND R.Rno = S.Rno
WHERE R.Rtype = 'Double'
GROUP BY H.Hno, H.Hname;

-- 3.

SELECT S.Sname,H.Warden_Nm,H.Haddress
FROM STUDENT S
JOIN HOSTEL H ON S.Hno = H.Hno
WHERE S.Dept = 'Computer Science';


-- 4.

SELECT DISTINCT H.*
FROM HOSTEL H
JOIN ROOM R ON H.Hno = R.Hno
WHERE R.Status = 'Vacant' AND R.Rtype IN ('Single', 'Four');
  
  
  -- 5.
  
SELECT COUNT(*) AS Total_Medical_Students
FROM STUDENT WHERE Dept = 'Medical';


-- 6. 

SELECT S.*
FROM STUDENT S
JOIN ROOM R ON S.Hno = R.Hno
AND S.Rno = R.Rno
JOIN HOSTEL H ON R.Hno = H.Hno
WHERE H.Hname = 'Chanakya'
AND R.Rtype = 'Double';
  
  
  -- 7.


SELECT H.Hname,R.Rtype,
COUNT(S.Sid) AS Total_Students
FROM HOSTEL H
JOIN ROOM R ON H.Hno = R.Hno
LEFT JOIN STUDENT S ON R.Hno = S.Hno
AND R.Rno = S.Rno
GROUP BY H.Hno, H.Hname, R.Rtype
ORDER BY H.Hname, R.Rtype;


-- 8

SELECT S.*, F.Fdate, F.Famount
FROM STUDENT S
JOIN FEES F ON S.Sid = F.Sid
WHERE F.Fdate >= '2011-11-01' AND F.Fdate < '2011-12-01';
  
  -- 9
  
SELECT S.*, F.Fdate, F.Famount
FROM STUDENT S
JOIN FEES F ON S.Sid = F.Sid
WHERE MONTH(F.Fdate) = 11 
AND YEAR(F.Fdate) = 2011;
  
  
  
