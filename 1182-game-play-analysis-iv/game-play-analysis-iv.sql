# Write your MySQL query statement below

-- 
SELECT ROUND(COUNT(DISTINCT player_id) /(Select COUNT(DISTINCT player_id) from Activity) , 2) AS fraction 
from Activity
WHERE(player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) IN (
    Select player_id , min(event_date) as first_login
    from Activity
    GROUP BY player_id
)

