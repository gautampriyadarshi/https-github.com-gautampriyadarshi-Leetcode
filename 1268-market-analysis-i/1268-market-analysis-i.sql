# Write your MySQL query statement below
SELECT u.user_id AS buyer_id, u.join_date,
COUNT(o.order_id) AS orders_in_2019
FROM Users AS u
lEFT JOIN Orders AS o
ON u.user_id = o.buyer_id AND YEAR(order_date) = '2019'
GROUP BY user_id;