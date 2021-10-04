select CompanyName,Round(100.*(select count(*) from 'Order' where Shipper.Id='Order'.ShipVia and ShippedDate>RequiredDate)/(select count(*) from 'Order' where Shipper.Id='Order'.ShipVia),2) as delaypercent
from Shipper
order by delaypercent desc;