select Id,OrderDate,PreOrderDate,Round(julianday(OrderDate)-julianday(PreOrderDate),2)
from (select Id,OrderDate,lag(OrderDate,1,OrderDate) over (order by OrderDate asc) as PreOrderDate
from 'Order'
where CustomerId='BLONP'
order by OrderDate
limit 10);