# Write your MySQL query statement below
select d.name as Department ,e.name as Employee ,e.salary as Salary
from Employee e
JOIN Department d
ON e.departmentId = d.id 
where(e.departmentId ,e.salary) IN(
    select departmentId , max(salary)
    from Employee
    Group By departmentId
)


