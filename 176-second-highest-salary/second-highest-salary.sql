-- # Write your MySQL query statement below
select(
    select distinct(salary) 
    from Employee
    Order by salary desc
    Limit 1 offset 1

) as SecondHighestSalary


-- 
-- select max(e1.salary) as SecondHighestSalary
-- from employee e1 
-- JoIN employee e2
-- where e1.salary < e2.salary 