select customer_number
from orders
group by customer_number
having count(*) = 
(select max(cnt) from 
(select count(*) cnt
from orders
group by customer_number))