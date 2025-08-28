# Write your MySQL query statement below

-- select w1.id 
-- from Weather w1 
-- INNER JOIN weather w2
-- where SUBDATE(w1.recordDate,1) = W2.recordDate
-- And w1.temperature > w2.temperature 


########OR

-- select w1.id 
-- from Weather w1 
-- INNER JOIN weather w2
-- where DATEDIFF(w1.recordDate,w2.recordDate) = 1
-- And w1.temperature > w2.temperature 


########OR

select w1.id 
from Weather w1 
INNER JOIN weather w2
ON SUBDATE(w1.recordDate,1) = W2.recordDate And w1.temperature > w2.temperature 


####SUBDATE - it means subtract dates w1 date -1 = w2.date
####DATEDIFF - it means subtract dates w1 date - w2 date = 1