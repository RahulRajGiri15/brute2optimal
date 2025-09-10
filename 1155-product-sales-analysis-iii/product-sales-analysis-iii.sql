# Write your MySQL query statement below

select product_id , year as first_year , quantity , price 
from Sales 
Where (product_id , year) IN (
    select product_id  , MIN(year) as f_year
    from sales
    GROUP BY product_id
)