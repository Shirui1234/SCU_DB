select ProductName,CompanyName,ContactName
from (select ProductName,min(OrderDate),CompanyName,ContactName
from Product,OrderDetail,'Order',Customer
where Product.Id=ProductId and OrderId='Order'.Id and CustomerId=Customer.Id 
group by ProductId
having count(*)=sum(Discontinued))
order by ProductName;
