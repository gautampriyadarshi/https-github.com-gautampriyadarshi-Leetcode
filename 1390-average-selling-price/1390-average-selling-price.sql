# Write your MySQL query statement below
SELECT DISTINCT p.product_id,
COALESCE (ROUND ( SUM( p.price * u.units) / SUM(units), 2), 0) AS average_price
FROM Prices AS p
LEFT JOIN UnitsSold AS u
ON p.product_id = u.product_id
AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;

-- Line 6 was missing but I had thought
-- In Line 3, I didn't used COALESCE(, 0) and instead of SUM I have written AVG.