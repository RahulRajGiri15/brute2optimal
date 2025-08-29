# Write your MySQL query statement below
###well,  i don't think this is a easy problem

#### Here we will use CROSS JOIN 
##  In cross join -- we have cartesian product of two tables (every elemnt of table A will be paired with every element of table B) 

select s.student_id, s.student_name,sub.subject_name , count(e.subject_name) as attended_exams
from Students s 
CROSS JOIN Subjects sub 
LEFT JOIN Examinations e
ON s.student_id = e.student_id AND sub.subject_name = e.subject_name

Group BY s.student_id , s.student_name,sub.subject_name
order BY student_id, subject_name