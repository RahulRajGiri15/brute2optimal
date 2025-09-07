# Write your MySQL query statement below

select p.product_id , IFNULL(ROUND(SUM(u.units * p.price) / SUM(u.units),2),0) AS average_price
from Prices p
LEFT JOIN UnitsSold u
    ON p.product_id = u.product_id
    AND u.purchase_date BETWEEN p.start_date AND p.end_date
Group BY P.product_id;
