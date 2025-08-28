# Write your MySQL query statement below

-- select a1.machine_id , ROUND(avg(a2.timestamp - a1.timestamp),3) as Processing_time
-- from Activity a1
-- INNER JOIN Activity a2

-- ON a1.process_id = a2.process_id 
--     AND a1.machine_id = a2.machine_id
--     # AND a2.timestamp > a1.timestamp
--     AND a2.activity_type = 'end'
--     AND a1.activity_type = 'start'

-- GROUP BY a1.machine_id


############OR

select a1.machine_id , ROUND(avg(a2.timestamp - a1.timestamp),3) as Processing_time
from Activity a1
INNER JOIN Activity a2

ON a1.process_id = a2.process_id 
    AND a1.machine_id = a2.machine_id
    AND a2.activity_type = 'end'
    AND a1.activity_type = 'start'
    AND a2.timestamp >= a1.timestamp
      
GROUP BY a1.machine_id