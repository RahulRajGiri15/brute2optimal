# Write your MySQL query statement below

## solve is using LEFT JOIN

-- select EmployeeUNI.unique_id , Employees.name
-- FROM Employees 
-- LEFT JOIN EmployeeUNI 
-- ON Employees.id = EmployeeUNI.id;

####OR

-- Select euni.unique_id , e.name 
-- from Employees as e
-- LEFT JOIN EmployeeUNI as euni
-- ON e.id = euni.id;


####or

Select euni.unique_id as unique_id , e.name as name  
from Employees  e
LEFT JOIN EmployeeUNI  euni
ON e.id = euni.id;