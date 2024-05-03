CREATE TABLE pessoa(
	cod_pessoa SERIAL PRIMARY KEY,
	nome VARCHAR(50)
);

CREATE TABLE postagem(
	cod_postagem SERIAL PRIMARY KEY,
	conteudo VARCHAR(255),
	cod_pessoa INTEGER,
	FOREIGN KEY (cod_pessoa) REFERENCES pessoa(cod_pessoa)
);

CREATE TABLE comentario(
	cod_comentario SERIAL PRIMARY KEY,
	conteudo VARCHAR(255),
	cod_pessoa INTEGER,
	com_respondido INTEGER,
	cod_postagem INTEGER,
	FOREIGN KEY (cod_pessoa) REFERENCES pessoa(cod_pessoa),
	FOREIGN KEY (com_respondido) REFERENCES comentario(cod_comentario),
	FOREIGN KEY (cod_postagem) REFERENCES postagem(cod_postagem)
);

INSERT INTO pessoa (nome)
VALUES 
('Pedro'),
('Ana'),
('Gabriel');

SELECT * FROM pessoa

INSERT INTO postagem (conteudo, cod_pessoa) 
VALUES
('Hoje eu acordei feliz =)', 1);

SELECT * FROM postagem

SELECT nome, conteudo FROM pessoa, postagem WHERE pessoa.cod_pessoa=postagem.cod_pessoa;

INSERT INTO comentario (conteudo, cod_pessoa, cod_postagem )
VALUES
('O que houve para tanta felicidade?', 2, 1);

SELECT * FROM postagem, comentario

SELECT * FROM comentario

INSERT INTO comentario (conteudo, cod_pessoa, com_respondido, cod_postagem)
VALUES
('Hoje é aula de BD!', 1, 1, 1);



--somente teste--

SELECT pessoa.nome, postagem.conteudo, comentario.cod_pessoa, comentario.conteudo
FROM pessoa
INNER JOIN postagem ON pessoa.cod_pessoa = postagem.cod_pessoa
INNER JOIN comentario ON comentario.cod_postagem=postagem.cod_postagem

SELECT pessoa.nome, postagem.conteudo
FROM pessoa
INNER JOIN postagem
ON pessoa.cod_pessoa = postagem.cod_pessoa