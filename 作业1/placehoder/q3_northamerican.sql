select Id,ShipCountry,test
from (select *,'NorthAmerican' as test from 'Order' where ShipCountry='USA' or ShipCountry='Mexico' or ShipCountry='Canada'
union
select *,'OtherPlace' as test from 'Order' where ShipCountry<>'USA' and ShipCountry<>'Mexico' and ShipCountry<>'Canada')
where id>15444 and id<15465
order by Id;
