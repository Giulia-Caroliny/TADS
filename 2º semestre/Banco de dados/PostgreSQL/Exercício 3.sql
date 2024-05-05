INSERT INTO banco(codigo, nome) 
VALUES 
(1, 'Banco do Brasil'),
(4, 'CEF');

SELECT * FROM banco

INSERT INTO agencia(numero_agencia, endereco, cod_banco)
VALUES
('0562', 'Rua Joaquim Teixeira Alves, 1555', 4),
('3153', 'Av. Marcelino Pires, 1960', 1);

SELECT * FROM agencia

INSERT INTO cliente(cpf, nome, sexo, endereco)
VALUES
('111.222.333-44', 'Jennifer B Souza', 'F', 'Rua Cuiabá, 1050'),
('666.777.888-99', 'Caetano K Lima', 'M', 'Rua Ivinhema, 879'),
('555.444.777-33', 'Silvia Macedo', 'F', 'Rua Estados Unidos, 735');

SELECT * FROM cliente

INSERT INTO conta(numero_conta, saldo, tipo_conta, num_agencia)
VALUES
('86340-2', 763.05, 2, '3153'),
('23584-7', 3879.12, 1, '0562');

SELECT * FROM conta

INSERT INTO historico(cpf, num_conta, data_inicio)
VALUES
('111.222.333-44', '23584-7', '17-12-1997'),
('666.777.888-99', '23584-7', '17-12-1997'),
('555.444.777-33', '86340-2', '29-11-2010');

SELECT * FROM historico

INSERT INTO telefone_cliente(cpf_cli, telefone_cli)
VALUES
('111.222.333-44', '(67)3422-7788'),
('666.777.888-99', '(67)3423-9900'),
('666.777.888-99', '(67)8121-8833');

SELECT * FROM telefone_cliente
