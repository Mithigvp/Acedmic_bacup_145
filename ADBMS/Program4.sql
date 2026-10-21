create database Movis;
use Movis;


CREATE TABLE SCREEN
(
    Screen_Id VARCHAR(5) PRIMARY KEY,
    Location VARCHAR(2),
    Seating_Capacity INT,

    CONSTRAINT chk_screen_id
    CHECK (Screen_Id LIKE 'S%'),

    CONSTRAINT chk_location
    CHECK (Location IN ('FF', 'SF', 'TF'))
);


CREATE TABLE MOVIE
(
    Movie_Id INT PRIMARY KEY,
    Movie_Name VARCHAR(50),
    Date_Of_Release DATE
);


CREATE TABLE CURRENT_MOVIE
(
    Screen_Id VARCHAR(5),
    Movie_Id INT,
    Date_Of_Arrival DATE,
    Date_Of_Closure DATE,

    PRIMARY KEY (Screen_Id, Movie_Id, Date_Of_Arrival),

    FOREIGN KEY (Screen_Id)
    REFERENCES SCREEN(Screen_Id),

    FOREIGN KEY (Movie_Id)
    REFERENCES MOVIE(Movie_Id),

    CONSTRAINT chk_dates
    CHECK (Date_Of_Arrival < Date_Of_Closure)
);


INSERT INTO SCREEN VALUES ('S1', 'FF', 200);
INSERT INTO SCREEN VALUES ('S2', 'SF', 150);
INSERT INTO SCREEN VALUES ('S3', 'TF', 100);
INSERT INTO SCREEN VALUES ('S4', 'FF', 250);
INSERT INTO SCREEN VALUES ('S5', 'SF', 180);



INSERT INTO MOVIE VALUES (101, 'RRR', '2021-03-25');
INSERT INTO MOVIE VALUES (102, 'KGF Chapter 2', '2022-04-14');
INSERT INTO MOVIE VALUES (103, 'Pushpa', '2021-12-17');
INSERT INTO MOVIE VALUES (104, 'Dangal', '2016-12-23');
INSERT INTO MOVIE VALUES (105, 'Bahubali 2', '2017-04-28');



INSERT INTO CURRENT_MOVIE
VALUES ('S1', 101, '2011-12-01', '2011-12-20');
INSERT INTO CURRENT_MOVIE
VALUES ('S2', 102, '2011-11-01', '2011-12-24');
INSERT INTO CURRENT_MOVIE
VALUES ('S3', 103, '2011-12-05', '2011-12-18');
INSERT INTO CURRENT_MOVIE
VALUES ('S4', 104, '2011-11-15', '2011-12-10');
INSERT INTO CURRENT_MOVIE
VALUES ('S4', 105, '2011-11-01', '2011-12-24');
INSERT INTO CURRENT_MOVIE
VALUES ('S5', 101, '2011-10-01', '2011-11-15');


SELECT * FROM SCREEN;



SELECT * FROM MOVIE;


SELECT * FROM CURRENT_MOVIE;



SELECT m.Movie_Name,
       DATEDIFF(c.Date_Of_Closure, c.Date_Of_Arrival) AS Duration
FROM MOVIE m
JOIN CURRENT_MOVIE c
ON m.Movie_Id = c.Movie_Id
ORDER BY Duration DESC
LIMIT 1;



SELECT AVG(DATEDIFF(Date_Of_Closure, Date_Of_Arrival))
       AS Average_Duration
FROM CURRENT_MOVIE
WHERE Screen_Id = 'S4';



SELECT m.Movie_Id,
       m.Movie_Name,
       m.Date_Of_Release,
       c.Screen_Id,
       c.Date_Of_Arrival,
       c.Date_Of_Closure
FROM MOVIE m
JOIN CURRENT_MOVIE c
ON m.Movie_Id = c.Movie_Id
WHERE c.Date_Of_Closure = '2011-12-24';