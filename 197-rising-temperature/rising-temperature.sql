# Write your MySQL query statement below

select w1.id 
from Weather w1 
INNER JOIN weather w2
where SUBDATE(w1.recordDate,1) = W2.recordDate
And w1.temperature > w2.temperature 