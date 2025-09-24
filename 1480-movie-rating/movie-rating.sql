# Write your MySQL query statement below
WITH UserCounts AS (
    SELECT u.name,
           COUNT(*) AS total_ratings
    FROM MovieRating mr
    JOIN Users u
      ON mr.user_id = u.user_id
    GROUP BY u.name
),
TopUser AS (
    SELECT name
    FROM UserCounts
    ORDER BY total_ratings DESC, name ASC
    LIMIT 1
),

MovieAvgs AS (
    SELECT m.title,
           AVG(mr.rating) AS avg_rating
    FROM MovieRating mr
    JOIN Movies m
      ON mr.movie_id = m.movie_id
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY m.title
),
TopMovie AS (
    SELECT title
    FROM MovieAvgs
    ORDER BY avg_rating DESC, title ASC
    LIMIT 1
)

SELECT name AS results FROM TopUser
UNION ALL
SELECT title AS results FROM TopMovie
