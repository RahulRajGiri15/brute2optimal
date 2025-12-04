# Write your MySQL query statement below

-- select a.machine_id , round(avg(b.timestamp - a.timestamp),3) as processing_time
-- -- select a.machine_id , b.timestamp , a.timestamp
-- from Activity a
-- join Activity b
-- on a.machine_id = b.machine_id
-- and a.process_id = b.process_id
-- and a.timestamp < b.timestamp
-- group by a.machine_id

select a1.machine_id, round(avg(a2.timestamp - a1.timestamp),3) as Processing_time
from Activity a1
Join activity a2
on a1.machine_id = a2.machine_id
and a2.activity_type = 'end'
and a1.activity_type = 'start'
group by a1.machine_id
