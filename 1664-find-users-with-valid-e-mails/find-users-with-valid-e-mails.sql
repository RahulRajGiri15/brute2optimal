# Write your MySQL query statement below
-- select *
-- from Users
-- where mail REGEXP '^[A-Za-z][A-Za-z0-9_\.\-]*@leetcode[.]com$'

-- where Lower(mail) REGEXP '^[a-z][a-z0-9_.-]*@leetcode[.]com$'

SELECT *
FROM
  Users
WHERE
  REGEXP_LIKE(mail, '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$', 'c')
