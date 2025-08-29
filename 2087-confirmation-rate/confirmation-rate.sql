# Write your MySQL query statement below


Select s.user_id , IFNULL(ROUND(SUM(action = 'confirmed') / count(*),2),0.00) AS confirmation_rate
from Signups s
LEFT JOIN Confirmations cn
ON s.user_id = cn.user_id
GROUP BY s.user_id