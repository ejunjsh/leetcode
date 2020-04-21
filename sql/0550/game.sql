select round(
              (select count(*) from activity where (player_id,event_date) 
              in    
              (SELECT player_id,DATE(MIN(event_date)+1) 
              FROM activity group by player_id))
              /count(distinct player_id)
              ,2) as fraction
from activity;