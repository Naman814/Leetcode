# Write your MySQL query statement below
select b.unique_id, a.name FROM Employees a  Left Join EmployeeUNI b
on a.id = b.id