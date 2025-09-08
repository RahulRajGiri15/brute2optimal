# Write your MySQL query statement below

select r.contest_id ,ROUND(COUNT(DISTINCT r.user_id) / (Select COUNT(*) from Users) * 100, 2 )AS percentage
from Register r
-- LEFT JOIN Register r 
--     ON u.user_id = r.user_id
GROUP BY r.contest_id 
ORDER BY percentage DESC , contest_id ASC;