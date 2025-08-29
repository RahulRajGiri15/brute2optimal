# Write your MySQL query statement below

select e1.name
from Employee e1
INNER JOIN Employee e2
ON e1.id = e2.managerId
Group BY e2.managerId
HAVING count(e2.managerId) >= 5;