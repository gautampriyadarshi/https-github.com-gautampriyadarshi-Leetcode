# Write your MySQL query statement below
SELECT  r.contest_id,
    ROUND(COUNT(DISTINCT r.user_id) / COUNT( DISTINCT u.user_id) * 100, 2) AS percentage
FROM Register AS r, Users AS u
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC;