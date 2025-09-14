# Write your MySQL query statement below
select Date_format(trans_date, '%Y-%m') As month
,country
,count(*) as trans_count
,sum(state = 'approved') AS approved_count
,sum(amount) AS trans_total_amount
,sum(case when state = 'approved' THEN amount ELSE 0 END) As approved_total_amount

from Transactions t
Group By month , country