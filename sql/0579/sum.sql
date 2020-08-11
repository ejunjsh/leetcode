SELECT e1.id, e1.month, SUM (e2.salary)
FROM Employee e1,
Employee e2,
(SELECT id, MAX (month) recent
FROM [Employee]
group by id) e3
where e1.Id = e3.Id and e1.month <> e3.recent
and e1.Id = e2.Id and e1.month >= e2.month
group by e1.id,e1.month
order by e1.id asc,e1.month desc;