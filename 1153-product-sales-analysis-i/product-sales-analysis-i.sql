# Write your MySQL query statement below

## here alos we will use left JOIN beacuse he have to show all data of sales table and only common data of Product table 

select p.product_name , s.year, s.price 
from Sales s
LEFT JOIN Product p
ON s.product_id = p.product_id; 