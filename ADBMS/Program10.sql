create table movie (
    movie_id number primary key,
    movie_name varchar2(100) not null,
    date_of_release date
);

create table screen (
    screen_id varchar2(10) primary key,
    location varchar2(2) check (location in ('ff', 'sf', 'tf')),
    max_capacity number check (max_capacity > 0),
    constraint chk_screen_id check (screen_id like 's%')
);

 create table current_screen (
    movie_id number ,
    screen_id varchar2(10),
    date_of_arrival date,
    date_of_closure date,
    constraint chk_dates check (date_of_arrival < date_of_closure)
);


insert into movie (movie_id, movie_name, date_of_release) values 
 (1, 'drasham', to_date('03-10-2026', 'dd-mm-yyyy')),
 (2, 'frandship', to_date('05-10-2026', 'dd-mm-yyyy')),
 (3, 'avatar', to_date('18-12-2009', 'dd-mm-yyyy')),
 (4, 'ideat', to_date('18-07-2008', 'dd-mm-yyyy')),
 (5, 'makhi', to_date('20-04-2010','dd-mm-yyyy')),
 (6, 'rajmahel', to_date('08-17-2011','dd-mm-yyyy')),
 (8, 'ms_dhoni', to_date('07-07-2017','dd-mm-yyyy'));

insert into screen values ('s1', 'ff', 250);
insert into screen values ('s2', 'sf', 180);
insert into screen values ('s3', 'tf', 120);
insert into screen values ('s4', 'ff', 200);
insert into screen values ('s5', 'sf', 150);



insert into current_screen (movie_id,screen_id,date_of_arrival, date_of_closure) values 
(1, 's1', date '2026-10-01', date '2026-10-25'),
(1, 's2', date '2026-10-05', date '2026-10-22'),
(1, 's3', date '2026-10-10', date '2026-10-30'),
(2, 's1', date '2026-09-01', date '2026-09-20'),
(2, 's2', date '2026-10-01', date '2026-10-28'),
(3, 's1', date '2026-10-01', date '2026-10-31'),
(3, 's3', date '2026-10-05', date '2026-10-26'),
(3, 's4', date '2026-10-12', date '2026-10-24'),
(3, 's5', date '2026-10-15', date '2026-10-29'),
(4, 's3', date '2026-10-01', date '2026-10-15'),
(5, 's4', date '2026-10-01', date '2026-10-30'),
(5, 's5', date '2026-10-10', date '2026-10-27'),
(7, 's2', date '2026-10-12', date '2026-10-25'),
(8, 's1', date '2026-10-10', date '2026-10-23'),
(9, 's4', date '2026-09-01', date '2026-09-30');

select * from current_screen;
drop table current_screen;
-- 1

select movie_id, movie_name, screen_count
from (
    select m.movie_id,
           m.movie_name,
           count(c.screen_id) as screen_count
    from movie m
    join current_screen c
        on m.movie_id = c.movie_id
    group by m.movie_id, m.movie_name
    order by count(c.screen_id) desc, m.movie_id
)
where rownum <= 3;



-- 2


create or replace view vw_currently_screened_movies as
select m.movie_id,
       m.movie_name,
       m.date_of_release,
       s.screen_id,
       s.location,
       s.max_capacity,
       c.date_of_arrival,
       c.date_of_closure
from movie m
join current_screen c
    on m.movie_id = c.movie_id
join screen s
    on c.screen_id = s.screen_id
where trunc(sysdate) between
      c.date_of_arrival and c.date_of_closure;
      
select * from vw_currently_screened_movies;

-- 3

create table movie_log (
    movie_id number,
    movie_name varchar2(100),
    log_date date
);


create or replace trigger trg_after_movie_insert
after insert on movie
for each row
begin
    insert into movie_log (
        movie_id,
        movie_name,
        log_date
    )
    values (
        :new.movie_id,
        :new.movie_name,
        sysdate
    );
end;
/


insert into movie
values (11, 'interstellar', date '2014-11-07');

select * from movie_log;




-- 4


create or replace function fn_get_current_movie(p_screen_id in varchar2) 
return varchar2 is
    v_movie_name varchar2(100);
    v_screen_count number;
    e_screen_not_found exception;
begin
    select count(*)
    into v_screen_count
    from screen
    where lower(screen_id) = lower(p_screen_id);

    if v_screen_count = 0 then
        raise e_screen_not_found;
    end if;

    select m.movie_name
    into v_movie_name
    from movie m
    join current_screen c on m.movie_id = c.movie_id
    where lower(c.screen_id) = lower(p_screen_id)
      and sysdate between c.date_of_arrival and c.date_of_closure
      and rownum = 1;

    return v_movie_name;

exception
    when e_screen_not_found then
        raise_application_error(-20002, 'error: screen code ' || p_screen_id || ' does not exist.');
    when no_data_found then
        return 'no movie is currently being screened on this screen.';
end;
/
drop table movie_log;

