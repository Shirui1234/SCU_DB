select ShipName as 'Bottom-Dollar Markets',substr(ShipName,0,instr(ShipName,'-')) as Bottom from (select distinct ShipName from 'Order' where ShipName Like '%-%' order by ShipName);