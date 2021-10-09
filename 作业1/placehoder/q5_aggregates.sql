select CategoryName,count(*),Round(avg(UnitPrice),2),min(UnitPrice),max(UnitPrice),sum(UnitsOnOrder)
from Product,Category
where CategoryId=Category.Id
group by CategoryId
having count(*)>10
order by CategoryId;