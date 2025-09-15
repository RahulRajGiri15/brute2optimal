# Write your MySQL query statement below


-- select
-- Round(Count(*) / (Select count(Distinct player_id) from Activity) , 2) 
-- As fraction

-- from(
--     select
--     a.player_id 
--     from Activity a
--     JOIN(
--         select player_id, min(event_date) as first_date
--         from Activity 
--         Group BY player_id
--     ) b
--     on b.player_id = a.player_id
--     and a.event_date = DATE_ADD(first_date , interval 1 Day)
-- ) as s;


-- -----------------------------

select Round(count(player_id) / (select count(distinct player_id) from Activity) ,2)  AS fraction

from Activity 
where(player_id, DATE_SUB(event_date , INTERVAL 1 DAY)) in (
    select
    player_id,
    min(event_date) as first_date
    from Activity 
    Group By player_id
) 


