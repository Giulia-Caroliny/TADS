CREATE TABLE banco(
	codigo SERIAL PRIMARY KEY,
	nome VARCHAR(100)
);

CREATE TABLE agencia(
	numero_agencia VARCHAR(20) PRIMARY KEY,
	endereco VARCHAR(255),
	cod_banco INTEGER NOT NULL,
	FOREIGN KEY (cod_banco) REFERENCES banco(codigo)
);

CREATE TABLE cliente(
	cpf VARCHAR(20) PRIMARY KEY,
	nome VARCHAR(100),
	sexo VARCHAR(25),
	endereco VARCHAR(255)
);

CREATE TABLE conta(
	numero_conta VARCHAR(20) PRIMARY KEY,
	saldo NUMERIC(10,2),
	tipo_conta INTEGER,
	num_agencia VARCHAR(20) NOT NULL,
	FOREIGN KEY (num_agencia) REFERENCES agencia(numero_agencia)
);

CREATE TABLE historico(
	cpf VARCHAR(20) NOT NULL,
	num_conta VARCHAR(20) NOT NULL,
	data_inicio DATE,
	FOREIGN KEY (cpf) REFERENCES cliente(cpf),
	FOREIGN KEY (num_conta) REFERENCES conta(numero_conta)
);

CREATE TABLE telefone_cliente(
	cpf_cli VARCHAR(20) NOT NULL,
	telefone_cli VARCHAR(20) PRIMARY KEY,
	FOREIGN KEY (cpf_cli) REFERENCES cliente(cpf)
);