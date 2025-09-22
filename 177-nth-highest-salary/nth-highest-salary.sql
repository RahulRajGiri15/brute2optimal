CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    declare offsetvalue  INT;
    set offsetvalue = N-1;
  RETURN (
      # Write your MySQL query statement below.
        select distinct(salary) as getNthHighestSalary
        from Employee
        ORDER by salary DESC 
        Limit 1 OFFSET offsetvalue
  );
END;