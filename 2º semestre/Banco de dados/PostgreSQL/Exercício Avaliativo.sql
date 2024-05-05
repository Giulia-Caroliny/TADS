--Exercício Avaliativo--
--Questão 1--
CREATE TABLE livros (
	id INT PRIMARY KEY,
	titulo VARCHAR(255),
	autor VARCHAR(255),
	ano_publicacao INT
);

INSERT INTO livros (id, titulo, autor, ano_publicacao)
VALUES
	(1, ‘Dom Casmurro’, ‘Machado de Assis’, 1899),
	(2, ‘1984’, ‘George Orwell, 1950),
	(3, ‘O Pequeno Príncipe, ‘Antonie de Saint-Exupéry’, 1943),
	(4, ‘O Senhor dos Anéis, ‘J. R. R. Tolkien’, 1954);
 
SELECT *
FROM livros
WHERE ano_publicacao < 1950;

SELECT COUNT(*) as “Quantidade”
FROM livros;

UPDATE livros
SET tituto = “Mil Novecentos e Oitenta e Quatro”
WHERE id = 2;

DELETE FROM livros WHERE id = 4;

--Questão 3--

SELECT *
FROM Produtos
ORDER BY nome_produto DESC;

SELECT qtde_estoque, nome_produto
FROM Produtos
WHERE preco NOT BETWEEN 1.00 AND 10.00;

--Questão 4--

SELECT Funcionarios.Nome, Funcionarios.Cargo, Departamentos.NomeDepartamento
FROM Funcionarios
INNER JOIN Departamentos ON Funcionarios.DepartamentoID = Departamentos.ID;

SELECT Funcionarios.Nome
FROM Funcionarios
INNER JOIN Departamentos
ON Funcionarios.DepartamentoID = Departamentos.ID
WHERE Departamentos.NomeDepartamento = 'Marketing';

SELECT Departamentos.NomeDepartamento AS "Departamento",
ROUND(AVG(Funcionarios.Salario),2) AS "Salario Médio por Departamento"
FROM Funcionarios
INNER JOIN Departamentos
ON Funcionarios.DepartamentoID = Departamentos.ID
GROUP BY Departamentos.NomeDepartamento;
