# Write your MySQL query statement below
SELECT DISTINCT a.num AS ConsecutiveNums
FROM Logs AS a
JOIN Logs AS b
ON a.id = b.id + 1 AND a.num = b.num
JOIN Logs AS c
on a.id = c.id + 2 AND a.num = c.num