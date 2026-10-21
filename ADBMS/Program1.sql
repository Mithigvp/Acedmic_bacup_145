--  create database shops;
--  use shops;

-- create table CUST(
-- 	Custno int primary key,
-- 	Custname varchar(20)  not null  UNIQUE key,
--      Addln1 varchar (20),
--      Addln2 varchar(20),
--      City varchar(20) not null,
--      State varchar (20) not null,
--      Phone bigint not null
--  ); 

--  create table ITEM(
--  	Itemno int primary key,
--      Itemname varchar(20)  not null  UNIQUE key,
--      Itemprice int not null,
--      Qty_On_Hand int not null
--  ); 

--  create table INVOICE(
--  	Invno int primary key,
--      Invdate datetime not null,
--      Custno int not null,
--       foreign key (Custno) references CUST(Custno)
--  ); 

--  create table INV_ITEM(
--  	Invno int,
--      Itemno int,
--      Qty_Used int not null,
--      foreign key (Invno) references INVOICE(Invno),
--      foreign key (Itemno) references ITEM(Itemno),
--      PRIMARY KEY (Invno, Itemno)
--  ); 

--  INSERT INTO CUST (Custno, Custname, Addln1, Addln2, City, State, Phone) VALUES 
--  (101, 'mithilesh', 'vijalpor', 'vijalpor', 'navsari', 'gujarat', 9876543210), 
--  (102, 'mitesh', 'Lalbaug', 'Lalbaug', 'Ahmedabad', 'gujarat', 9876543211), 
--  (103, 'ram', 'kabirpor', 'kabirpor', 'valsad', 'gujarat', 9876543212), 
--  (104, 'aman', 'shubhasnagar', 'shubhasnagar', 'bhopal', 'mp', 9876543213), 
--   (105, 'kabir', 'sardarnagar', 'sardarnagar', 'kashi', 'up', 9876543214),
--  (106, 'parth', 'kabirpor', 'kabirpor', 'navrangpor', 'rajesthan', 98762154210);

--  insert into ITEM (Itemno,Itemname,Itemprice,Qty_On_Hand) values
--  	(01 , 'keyboad', 2000, 200),
--      (02 , 'mouse', 150, 500 ),
--      (03 , 'moniter', 500, 100),
--      (04 , 'motherboard' ,25000, 30 ),
--      (05 , 'ram', 8000, 25 );

--  insert into INVOICE (Invno,Invdate,Custno) values
--  	(51 , '2025-06-07 14:50:00', 101),
--     (52 , '2024-08-11 6:40:00', 102 ),
--     (53 , '2026-05-21 15:20:00', 101),
--      (54 , '2025-02-15 11:30:00' ,103 ),
--      (55 , '2026-07-19 7:21:00', 104),
--  	(56 , '2026-04-12 8:01:00', 105);

--  insert into INV_ITEM (Invno,Itemno,Qty_Used) values
--  	(51 ,01,60),
--      (52 ,02,100),
--      (53 ,01,70),
--     (54 ,03,50),
-- 	(55 ,04,10),
--      (56 ,05,5);

-- alter table ITEM add colour varchar(20);
-- select * from  ITEM;


-- select concat(Itemname ,' ' , Itemprice) from ITEM;

-- select Itemprice * Qty_On_Hand from ITEM;

-- SELECT * FROM CUST WHERE State = 'gujarat';

-- select * from ITEM where Itemprice between 100 and 500;

-- select * from CUST where Custname  LIKE 'P%';

-- SELECT 
-- 	SUM(Itemprice) AS Total_Price,
--     AVG(Itemprice) AS Average_Price,
--     MAX(Itemprice) AS Highest_Price,
--     MIN(Itemprice) AS Lowest_Price
-- FROM ITEM;







