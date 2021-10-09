with Expenditures as (
select IFNULL(CompanyName,'MISSING_NAME') as CompanyName,CustomerId,Round(sum(Quantity*UnitPrice),2) as TotalExpend
from 'Order' join OrderDetail on 'Order'.Id=OrderId left join Customer on Customer.Id=CustomerId
group by CustomerId),
Quartiles as (select *,NTILE(4) over (order by totalExpend) as Quartile from Expenditures)
select CompanyName,CustomerId,TotalExpend
from Quartiles
where Quartile=1
order by TotalExpend;