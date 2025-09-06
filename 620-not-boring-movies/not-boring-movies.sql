# Write your MySQL query statement below

-- Select * 
-- from Cinema
-- where id%2 != 0 
--     AND description  != 'boring'
-- order by rating DESC;

-- another way ------- != can be written as <>

SELECT * 
FROM Cinema 
Where id%2 <> 0
    AND description <> 'boring'
ORDER BY rating DESC;