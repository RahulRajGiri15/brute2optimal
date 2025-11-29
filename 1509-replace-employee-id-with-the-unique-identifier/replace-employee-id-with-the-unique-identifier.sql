# Write your MySQL query statement below

select eu.unique_id as unique_id , em.name as name 
from Employees as em
left Join EmployeeUNI as eu
on em.id = eu.id
