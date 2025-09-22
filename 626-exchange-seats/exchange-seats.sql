# Write your MySQL query statement below

select 
    case 
        when 
            id = (select max(id) from Seat) and mod(id ,2) = 1
            then id
        when 
            Mod(id ,2) = 1
            then id + 1
        else 
                id - 1
    END as id ,student
from Seat
order by id ASC