WITH daily_amount AS (
    SELECT 
        visited_on,
        SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),
moving_avg AS (
    SELECT 
        a.visited_on,
        SUM(b.amount) AS amount,
        ROUND(SUM(b.amount) / 7.0, 2) AS average_amount
    FROM daily_amount a
    JOIN daily_amount b
      ON b.visited_on BETWEEN DATE_SUB(a.visited_on, INTERVAL 6 DAY) AND a.visited_on
    GROUP BY a.visited_on
    HAVING COUNT(b.visited_on) = 7
)
SELECT visited_on, amount, average_amount
FROM moving_avg
ORDER BY visited_on;
