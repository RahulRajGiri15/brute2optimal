# Write your MySQL query statement below

### 

select vs.customer_id , COUNT(customer_id) as count_no_trans 
from Visits vs
LEFT JOIN Transactions t
ON vs.visit_id = t.visit_id
where t.transaction_id IS NULL
GROUP BY vs.customer_id;


### working of each line 

-- LEFT JOIN → keeps all rows from Visits even if there’s no match in Transactions.

-- ON vs.visit_id = t.visit_id → links visits to any transactions made during that   visit.

-- WHERE t.transaction_id IS NULL → filters only those visits where no transaction was made.

-- COUNT(customer_id) → counts how many such no-transaction visits each customer had.

-- GROUP BY vs.customer_id → groups by customer so we get one row per customer.




#####OR

-- select vs.customer_id , COUNT(*) as count_no_trans 
-- from Visits vs
-- LEFT JOIN Transactions t
-- ON vs.visit_id = t.visit_id
-- where t.transaction_id IS NULL
-- GROUP BY vs.customer_id;
