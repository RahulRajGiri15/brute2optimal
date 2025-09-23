# Write your MySQL query statement below


-- select e1.name
-- from Employee e1
-- INNER JOIN Employee e2
-- ON e1.id = e2.managerId
-- Group BY e2.managerId
-- HAVING count(e2.managerId) >= 5;


####After INNER JOIN why we group by managerId?
### because we want to put all the rows with same managerId into same row(bucket)

select e1.name
from Employee e1
JOIN Employee e2
on e1.id = e2.managerId
Group by e1.id
Having count(e2.managerId) >= 5