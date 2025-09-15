# Write your MySQL query statement below

select 
    e.employee_id 
    ,e.name
    ,count(e1.employee_id) as reports_count 
    ,Round(avg(e1.age)) as average_age
from Employees e
JOIN Employees e1
    on e.employee_id = e1.reports_to

Group by e.Employee_id , e.name
order by e.employee_id