# Write your MySQL query statement below

select tweet_id 
from tweets
-- group by tweet_id 
-- having length(content) >= 15
where length(content) > 15