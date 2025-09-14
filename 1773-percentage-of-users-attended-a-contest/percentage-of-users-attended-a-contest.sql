# Write your MySQL query statement below

select r.contest_id , Round(count(distinct r.user_id) /(select Count(Distinct user_id) from users)*100 , 2) AS percentage
from register r
Group BY r.contest_id
order by percentage desc, r.contest_id ASC;