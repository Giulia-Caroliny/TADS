-- Questão 1 --

-- a) --
CREATE TABLE Editoras (
id_editora SERIAL PRIMARY KEY,
nome_editora VARCHAR(200)
);

CREATE TABLE Autor (
    id_autor SERIAL PRIMARY KEY,
    nome_autor VARCHAR(200)
);

CREATE TABLE Livros (
    id_livro SERIAL PRIMARY KEY,
    titulo VARCHAR(255),
    id_autor INT,
    id_editora INT,
    FOREIGN KEY (id_autor)
        REFERENCES Autor (id_autor),
    FOREIGN KEY (id_editora)
        REFERENCES Editoras (id_editora)
);

INSERT INTO Editoras(nome_editora) 
VALUES
('Companhia das letras'),
('Peguin Random House'),
('Editora 34');

INSERT INTO Autor (nome_autor)
VALUES
('Sun Tzu'),
('Miguel de Cervantes'),
('J.R.R Tolkien'),
('Fiódor Dostoiévski');

INSERT INTO Livros (titulo, id_autor, id_editora) 
VALUES 
('A Arte da Guerra', 1, 1),
('Dom Quixote', 2, 2),
('O Sr. Dos Anéis', 3, 1), 
('Crime e Castigo', 4, 3);

-- b) --
SELECT livros.titulo, autor.nome_autor, Editoras.nome_editora FROM Livros
INNER JOIN Autor
ON Livros.id_autor = Autor.id_autor
INNER JOIN Editoras
ON livros.id_editora = Editoras.id_editora;

-- c) --
INSERT INTO Autor (nome_autor)
VALUES
('Augusto Cury');

SELECT autor.nome_autor, count(id_livro) AS "Quantidade" FROM Autor
LEFT JOIN livros
ON autor.id_autor = livros.id_autor
GROUP BY autor.nome_autor;

-- d) --
SELECT livros.titulo, autor.nome_autor FROM Livros
INNER JOIN Autor
ON Livros.id_autor = Autor.id_autor
INNER JOIN Editoras
ON livros.id_editora = Editoras.id_editora
WHERE Editoras.nome_editora = 'Companhia das letras';