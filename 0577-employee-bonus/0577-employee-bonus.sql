Select name,bonus
from Bonus b
right join Employee e on e.empId = b.empId
where b.bonus<1000 or b.bonus is null