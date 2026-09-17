# Write your MySQL query statement below
select p.product_name,s.year,s.price FROM sales s inner join product p on  s.product_id=p.product_id;