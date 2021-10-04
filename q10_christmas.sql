select group_concat(ProductName)
from (select ProductName
from Product,OrderDetail,'Order',Customer
where CustomerId=Customer.Id and 'Order'.Id=OrderId and ProductId=Product.Id 
and CompanyName='Queen Cozinha' and date(OrderDate)='2014-12-25'
order by Product.Id);