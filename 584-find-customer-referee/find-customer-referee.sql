# Write your MySQL query statement below
select name 
from Customer
-- where referee_id is null or referee_id is not 2;
where referee_id != 2 or referee_id is NULL