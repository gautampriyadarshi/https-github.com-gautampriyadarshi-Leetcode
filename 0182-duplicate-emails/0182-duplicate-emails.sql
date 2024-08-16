# Write your MySQL query statement below
SELECT email
FROM Person
GROUP BY Email
HAVING COUNT(*) > 1;