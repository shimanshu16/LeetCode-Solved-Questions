select Department, Employee, Salary from (
    select 
        dense_rank() over w as top,
        d.name as Department, 
        e.name as Employee,
        salary as Salary
    from Employee e
    join Department d on e.departmentId = d.id
    window w as(
        partition by e.departmentId
        order by Salary desc
    )
) x
where top = 1;