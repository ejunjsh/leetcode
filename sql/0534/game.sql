SELECT
	a.player_id, 
	a.event_date, 
	SUM(b.games_played) AS games_played_so_far
FROM
	Activity a
LEFT JOIN
	Activity b
ON
	a.player_Id = b.player_Id
	AND a.event_date >= b.event_date
GROUP BY a.player_Id, a.event_date
ORDER BY a.player_Id, a.event_date ASC;
