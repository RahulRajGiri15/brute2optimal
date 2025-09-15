# Write your MySQL query statement below

select
Round(sum(first_deli = cust_fpre) / count(*) * 100.0 , 2) as immediate_percentage

from (
    select 
    customer_id
    , min(order_date) as first_deli
    , min(customer_pref_delivery_date) as cust_fpre
    from Delivery 
    Group BY customer_id 
) as x