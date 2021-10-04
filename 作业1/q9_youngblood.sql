select RegionDescription,FirstName, LastName,max(BirthDate)
from Employee,EmployeeTerritory,Territory,Region
where Employee.Id=EmployeeId and TerritoryId=Territory.Id and RegionId=Region.Id
group by Region.Id
order by Region.Id;