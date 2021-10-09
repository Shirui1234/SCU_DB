with prod as (
select Product.Id,ProductName
from Product,OrderDetail,'Order',Customer
where CustomerId=Customer.Id and 'Order'.Id=OrderId and ProductId=Product.Id 
and CompanyName='Queen Cozinha' and date(OrderDate)='2014-12-25'
group by Product.Id),
temp as (
select row_number() over (order by Id) as n,ProductName
from prod),
result as (
select n,ProductName
from temp
where n=1
union all
select temp.n,result.ProductName||', '||temp.ProductName
from temp,result
where temp.n=result.n+1)
select ProductName 
from result
order by n desc
limit 1;