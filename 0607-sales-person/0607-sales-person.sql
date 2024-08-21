# Write your MySQL query statement below
SELECT s.name 
FROM SalesPerson AS s
WHERE s.name NOT IN
(
    SELECT s.name 
    FROM SalesPerson AS s
    LEFT JOIN Orders AS o
    ON s.sales_id = o.sales_id 
    LEFT JOIN Company AS c 
    ON c.com_id = o.com_id 
    WHERE c.name = 'RED'
)