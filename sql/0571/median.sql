SELECT AVG(Number) AS median
FROM
 	(
 	SELECT *, @cum AS nbeg, (@cum := @cum + Frequency)-1 AS nend
 	FROM
	 	(SELECT *
	 	FROM Numbers
	 	ORDER BY Number) t1，
	 	(SELECT SUM(Frequency) as nsum FROM Numbers) s,  
	 	(SELECT @cum := 1) t2
	 ) tmp
WHERE
	CEIL(nsum/2) BETWEEN nbeg AND nend 
	OR
	FLOOR(nsum/2+1) BETWEEN nbeg AND nend;