# Write your MySQL query statement below
SELECT d.name AS Department, e.name AS Employee, e.salary 
FROM Employee AS e
JOIN Department AS d
ON d.id = e.departmentId WHERE (departmentId, salary) IN (
    SELECT departmentId, MAX(salary) AS Salary
    FROM Employee
    GROUP BY departmentId
);