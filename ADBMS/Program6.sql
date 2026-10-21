CREATE DATABASE LIBRARY;
USE LIBRARY;

CREATE TABLE PUBLISHER
(
    publ_id         int PRIMARY KEY,
    publ_name       VARCHAR(100),
    contact_person  VARCHAR(100),
    contact_addr    VARCHAR(200),
    contact_phone   VARCHAR(20)
);


CREATE TABLE CATEGORY
(
    cat_id       int PRIMARY KEY,
    cat_details  VARCHAR(100),
    max_books    int,
    duration     int
);


CREATE TABLE BOOK_MASTER
(
    book_id       int PRIMARY KEY,
    bname         VARCHAR(100),
    isbn_no       VARCHAR(30),
    total_copies  int,
    publ_id       int,

    FOREIGN KEY (publ_id)
        REFERENCES PUBLISHER(publ_id)
);


CREATE TABLE MEMBER
(
    member_id    int PRIMARY KEY,
    mname        VARCHAR(100),
    cat_id       int,
    mem_ship_dt  DATE,

    FOREIGN KEY (cat_id)
        REFERENCES CATEGORY(cat_id)
);


CREATE TABLE ISSUE
(
    ISSUE_id       int PRIMARY KEY,
    member_id      int,
    book_id        int,
    issu_ret       CHAR(1),
    issue_ret_dt   DATE,

    FOREIGN KEY (member_id)
        REFERENCES MEMBER(member_id),

    FOREIGN KEY (book_id)
        REFERENCES BOOK_MASTER(book_id)
);



INSERT INTO PUBLISHER
VALUES(1, 'Pearson', 'John Smith','New York', '9876543210');
INSERT INTO PUBLISHER
VALUES(2, 'McGraw Hill', 'David Brown','Chicago', '9876543211');
INSERT INTO PUBLISHER
VALUES(3, 'Oxford Press', 'Robert John','London', '9876543212');
INSERT INTO PUBLISHER
VALUES(4, 'Wiley', 'Michael Lee','Boston', '9876543213');
INSERT INTO CATEGORY
VALUES(1, 'Student', 3, 1);
INSERT INTO CATEGORY
VALUES(2, 'Faculty', 10, 3);
INSERT INTO CATEGORY
VALUES(3, 'Researcher', 15, 5);
INSERT INTO BOOK_MASTER
VALUES(101, 'Database Management System','9781111111111', 5, 1);
INSERT INTO BOOK_MASTER
VALUES(102, 'Data Structures','9782222222222', 4, 1);
INSERT INTO BOOK_MASTER
VALUES(103, 'Computer Networks','9783333333333', 3, 2);
INSERT INTO BOOK_MASTER
VALUES(104, 'Data Science Fundamentals','9784444444444', 2, 1);
INSERT INTO BOOK_MASTER
VALUES(105, 'Operating System','9785555555555', 2, 3);
INSERT INTO MEMBER
VALUES(1, 'Rahul', 1, DATE '2025-01-10','Ahmedabad');
INSERT INTO MEMBER
VALUES(2, 'Amit', 2, DATE '2024-06-15','Nadiad');
INSERT INTO MEMBER
VALUES(3, 'Raj', 1, DATE '2025-08-20','Vadodara');
INSERT INTO MEMBER
VALUES(4, 'Vijay', 3, DATE '2023-02-10','Surat');
INSERT INTO MEMBER
VALUES(5, 'Karan', 2, DATE '2024-10-05','Ahmedabad');
INSERT INTO ISSUE
VALUES(1, 1, 101, 'I', DATE '2011-01-15');
INSERT INTO ISSUE
VALUES(2, 2, 102, 'R', DATE '2011-02-10');
INSERT INTO ISSUE
VALUES(3, 3, 102, 'R', DATE '2011-03-15');
INSERT INTO ISSUE
VALUES(4, 4, 103, 'I', DATE '2011-04-20');
INSERT INTO ISSUE
VALUES(5, 5, 104, 'I', DATE '2011-05-10');
INSERT INTO ISSUE
VALUES(6, 1, 102, 'R', DATE '2011-06-15');
INSERT INTO ISSUE
VALUES(7, 2, 102, 'R', DATE '2011-07-20');
INSERT INTO ISSUE 
VALUES(8, 3, 105, 'I', DATE '2011-08-10');




ALTER TABLE ISSUE
ADD CONSTRAINT chk_issu_ret
CHECK (issu_ret IN ('I','R'));


ALTER TABLE MEMBER
ADD member_address VARCHAR(200);

CREATE TABLE LIBRARY_USERS
AS
SELECT *
FROM MEMBER
WHERE 1 = 2;

SELECT * FROM LIBRARY_USERS;

-- COMMIT;


SELECT DISTINCT
    M.member_id,
    M.mname,
    M.cat_id,
    M.mem_ship_dt,
    M.member_address,
    B.book_id,
    B.bname,
    B.isbn_no
FROM MEMBER M
JOIN ISSUE I
    ON M.member_id = I.member_id
JOIN BOOK_MASTER B
    ON I.book_id = B.book_id
WHERE I.issu_ret = 'I'
AND UPPER(B.bname) LIKE '%DATA%';



SELECT
    B.book_id,
    B.bname,
    COUNT(I.issue_id) AS Number_Of_Times_Issued
FROM BOOK_MASTER B
JOIN ISSUE I
    ON B.book_id = I.book_id
WHERE I.issu_ret = 'I'
AND EXTRACT(YEAR FROM I.issue_ret_dt) = 2011
GROUP BY
    B.book_id,
    B.bname
HAVING COUNT(I.issue_id) <= 3;



SELECT
    B.book_id,
    B.bname,
    B.isbn_no,
    B.total_copies,
    P.publ_id,
    P.publ_name
FROM BOOK_MASTER B
JOIN PUBLISHER P
    ON B.publ_id = P.publ_id
JOIN ISSUE I
    ON B.book_id = I.book_id
WHERE I.issu_ret = 'I'
AND UPPER(P.publ_name) = 'PEARSON';

SELECT
    B.book_id,
    B.bname,
    B.isbn_no,
    B.total_copies,
    COUNT(I.issue_id) AS Issued_Copies
FROM BOOK_MASTER B
LEFT JOIN ISSUE I
    ON B.book_id = I.book_id
    AND I.issu_ret = 'I'
GROUP BY
    B.book_id,
    B.bname,
    B.isbn_no,
    B.total_copies
HAVING COUNT(I.issue_id) = B.total_copies;

SELECT * FROM BOOK_MASTER;






