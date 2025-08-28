# Write your MySQL query statement below

### 

select vs.customer_id , COUNT(customer_id) as count_no_trans 
from Visits vs
LEFT JOIN Transactions t
ON vs.visit_id = t.visit_id
where t.transaction_id IS NULL
GROUP BY vs.customer_id;
