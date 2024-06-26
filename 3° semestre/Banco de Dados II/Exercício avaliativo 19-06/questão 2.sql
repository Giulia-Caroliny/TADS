-- Exercício 2

-- a) --
CREATE TABLE padeiros(
	id SERIAL PRIMARY KEY,
	nome VARCHAR(255),
	departamento VARCHAR(255),
	data_admissao DATE
);

CREATE TABLE auxiliares(
	id SERIAL PRIMARY KEY,
	nome VARCHAR(255),
	departamento VARCHAR(255),
	data_admissao DATE
);

INSERT INTO padeiros (nome, departamento, data_admissao) VALUES
	('Roberta Luna', 'Padeiro', '2015-01-01'),
	('José Santiago', 'Padeiro', '2017-02-25');

INSERT INTO auxiliares(nome, departamento, data_admissao) VALUES
	('Joaquim Borges', 'Auxiliar', '2019-01-01'),
	('Antonio França', 'Auxiliar', '2018-03-25'),
	('Emanuel Costa', 'Auxiliar', '2022-01-01');
	
-- b) --
INSERT INTO padeiros (nome, departamento, data_admissao)
SELECT nome, 'Padeiro', data_admissao
FROM auxiliares
WHERE data_admissao < '2020-01-01';