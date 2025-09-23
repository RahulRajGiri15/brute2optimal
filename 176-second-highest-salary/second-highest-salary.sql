-- # Write your MySQL query statement below
-- select id , salary as SecondHighestSalary
-- from Employee
-- Limit of 1 offset 1


select max(e1.salary) as SecondHighestSalary
from employee e1 
JoIN employee e2
where e1.salary < e2.salary 