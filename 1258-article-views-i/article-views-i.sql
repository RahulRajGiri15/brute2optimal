# Write your MySQL query statement below
# DISTINCT -- here we use distinct to ensure each author is listed only once even if they have seen multiple of their own articles

select DISTINCT author_id AS id 
from Views 
where author_id = viewer_id 
order BY id ASC ;