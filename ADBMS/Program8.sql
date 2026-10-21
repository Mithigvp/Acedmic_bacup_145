create database customers;

use customers;

create table customer 
(
    cust_id int primary key,
    cust_name varchar(20) not null,
    cust_addr varchar(50) not null,
    cust_city varchar(20) not null,
    emailid varchar(30) not null,
    conact_no bigint unique key not null
); 

create table magazine
(
    mag_id int primary key,
    mag_name varchar(30) not null,
    unit_rate int not null,
    type_of_subsciption set ('week','month','quadrimester','year')
);

create table subsciption
(
    cust_id int,
    mag_id int,
    sart_date date not null,
    end_date date not null,
    foreign key (cust_id) references customer(cust_id),
    foreign key (mag_id) references magazine(mag_id)
);

insert into customer(cust_id, cust_name, cust_addr, cust_city, emailid, conact_no) values
(101, 'mithileh', 'shubhasnagar', 'navsari', 'mithiesh@gmail.com', 2645845654),
(102, 'parth', 'ramnager', 'bhavnagar', 'parth@gmail.com', 2647587854),
(103, 'krish', 'shayamnager', 'gandhinager', 'krish@gmail.com', 2645545854),
(104, 'vishal', 'shivpur', 'ahemdabad', 'vishal@gmail.com', 2641579854),
(105, 'mayur', 'sardarnagar', 'gandhinager', 'mayur@gmail.com', 9725857854),
(106, 'navin', 'navrangpura', 'ahemdabad', 'navin@gmail.com', 2645857164),
(107, 'shafil', 'oldhighcourt', 'gandhinager', 'shafil@gmail.com', 7958857854),
(108, 'deva', 'thaltej', 'bhavnagar', 'deva@gmail.com', 3975857854),
(109, 'manthan', 'ranip', 'gandhinager', 'manthan@gmail.com', 1475857854),
(110, 'nikhil', 'gitamandir', 'ahemdabad', 'nikhil@gmail.com', 2644855854);

insert into magazine(mag_id, mag_name, unit_rate, type_of_subsciption) values
(1, 'india today', 50, 'week'),
(2, 'kal tak', 1500, 'year'),
(3, 'Outlook', 750, 'quadrimester'),
(4, 'vande matram', 350, 'month');



insert into subsciption (cust_id,mag_id,sart_date,end_date) values

(104 , 2 ,'2026-08-23','2026-08-31'),
(105 , 2 ,'2026-08-15','2026-08-22');

(101,1,'2010-10-01','2010-10-08'),
(102,2,'2011-01-31','2012-01-31'),
(103,3,'2010-10-01','2011-02-01'),
(104,4,'2010-08-01','2010-09-01'),
(105,1,'2026-08-01','2026-08-08'),
(106,2,'2026-03-01','2027-03-01'),
(107,3,'2026-08-01','2026-09-01'),
(108,4,'2010-01-01','2010-02-01'),
(109,1,'2013-02-01','2013-02-08'),
(110,3,'2010-09-01','2011-02-01');



-- 1
create view abd as 
select c.cust_name,m.mag_name,m.unit_rate
from customer c
join subsciption s on c.cust_id = s.cust_id
join magazine m on s.mag_id = m.mag_id 
where s.sart_date
between '2010-09-01' and '2011-02-01';

select * from abd;

-- 2
select m.mag_id, m.mag_name, 
count(s.cust_id) as total_sale
from magazine m
join subsciption s on m.mag_id= s.mag_id 
where s.sart_date between '2026-08-01' and '2026-09-01'
group by m.mag_id, 
m.mag_name
order by total_sale desc
limit 3;

-- 3

DELIMITER //
CREATE  function cust()
RETURNS int
BEGIN
declare CUST_COUNT INT;
select count(c.cust_id)
into cust_count 
from customer c
join  subsciption s
on c.cust_id = s.cust_id
join magazine m
on s.mag_id = m.mag_id
where c.cust_city = 'gandhinager'
and m.mag_name = 'Outlook' 
and s.sart_date = '2010-10-01';
return cust_count ;
END //
DELIMITER ;

SELECT CUST();


-- 4
CREATE TABLE customer_log (
    log_id int primary key,
    customer_code int(50),      
    customer_name varchar(255),     
    inserted_at date default NOW()
);


DELIMITER //

create trigger after_insert
after insert on customer
FOR EACH ROW
BEGIN
insert into customer_log(customer_code, customer_name, inserted_at) 
values(new.cust_id , new.cust_name , now());
END //

DELIMITER ;

drop trigger after_insert;
select * from customer_log;
INSERT INTO customer(cust_id, cust_name, cust_addr, cust_city, emailid, conact_no) 
VALUES 
(111, 'mithileh', 'shubhasnagar', 'navsari', 'mithiesh01@gmail.com', 26458442554);










