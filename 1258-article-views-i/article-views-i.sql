-- # Write your MySQL query statement below
-- select distinct author_id as id
-- from views
-- -- where count(author_id = viewer_id) >= 1
-- where author_id = viewer_id 
-- order by id asc;

--

-- select author_id as id
-- from views
-- where author_id = viewer_id
-- group by author_id
-- having count(*) >= 1
-- order by id asc

-- 
select author_id as id
from views
where author_id = viewer_id
group by author_id
having count(id) >= 1
order by id asc
