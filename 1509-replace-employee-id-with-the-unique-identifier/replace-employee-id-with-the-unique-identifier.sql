# Write your MySQL query statement below

## solve is using LEFT JOIN

select EmployeeUNI.unique_id , Employees.name
FROM Employees 
LEFT JOIN EmployeeUNI 
ON Employees.id = EmployeeUNI.id;