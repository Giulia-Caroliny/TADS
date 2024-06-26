-- Exercício 1 --

-- a) --
CREATE TABLE clientes(
	id_cliente SERIAL PRIMARY KEY,
	nome VARCHAR(255),
	cidade VARCHAR(255)
);

CREATE TABLE pedidos(
	id_pedido INTEGER PRIMARY KEY,
	id_cliente INTEGER,
	produto VARCHAR(255),
	quantidade INTEGER,
	FOREIGN KEY(id_cliente) REFERENCES clientes(id_cliente)
);

INSERT INTO clientes(id_cliente, nome, cidade) VALUES 
	(1, 'João Silva', 'São Paulo'),
	(2, 'Maria Souza', 'Rio de Janeiro'),
	(3, 'Carlos Lima', 'Belo Horizonte');
	
INSERT INTO pedidos(id_pedido, id_cliente, produto, quantidade) VALUES
	(101, 1, 'Notebook', 1),
	(102, 2, 'Smartphone', 2),
	(103, 1, 'Monitor', 1),
	(104, 3, 'Tablet', 1);

-- b) --
SELECT * FROM clientes
INNER JOIN pedidos
ON clientes.id_cliente = pedidos.id_cliente; 

-- c) --
SELECT * FROM clientes
LEFT JOIN pedidos
ON clientes.id_cliente = pedidos.id_cliente;

-- d) --
SELECT * FROM clientes
RIGHT JOIN pedidos
ON clientes.id_cliente = pedidos.id_pedido;

-- e) --
SELECT * FROM clientes
FULL OUTER JOIN pedidos
ON clientes.id_cliente = pedidos.id_cliente;

-- f) --
SELECT * FROM clientes
INNER JOIN pedidos
ON clientes.id_cliente = pedidos.id_cliente
WHERE clientes.cidade = 'São Paulo';