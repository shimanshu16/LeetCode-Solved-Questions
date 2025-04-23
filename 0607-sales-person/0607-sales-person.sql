select SP.name from SalesPerson SP
except
select SP.name from Orders O join SalesPerson SP on O.sales_id = SP.sales_id 
join Company C on (O.com_id = C.com_id and C.name = 'RED')