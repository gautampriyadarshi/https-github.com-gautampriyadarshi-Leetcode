# Write your MySQL query statement below
SELECT * FROM Users
WHERE MAIL REGEXP '^[A-Za-z][A-Za-z0-9_.-]*@leetcode[.]com$';