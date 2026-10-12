# Write your MySQL query statement below
select today.id
from Weather as today 
join Weather as yesterday
on DATEDIFF(today.recordDate,yesterday.recordDate)=1
where today.temperature > yesterday.temperature;