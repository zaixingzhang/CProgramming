
CREATE TABLE knowledge (
		id INT PRIMARY KEY NOT NULL, 
		abbrev TEXT NOT NULL,
	   	full_name TEXT NOT NULL,
	   	chinese TEXT,
	   	description TEXT
);

INSERT INTO knowledge (id, abbrev, full_name, chinese, description) VALUES (1, "MLB", "Main Logic Board", "主板", "计算机中的一个硬件，一块电路板，用于连接计算机其他各个硬件");

