-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Tempo de geração: 27/11/2023 às 20:39
-- Versão do servidor: 10.4.28-MariaDB
-- Versão do PHP: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `db_kegiu`
--

-- --------------------------------------------------------

--
-- Estrutura para tabela `clientes`
--

CREATE TABLE `clientes` (
  `codigo_cliente` int(11) NOT NULL,
  `codigo_usuario` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Estrutura para tabela `encomenda`
--

CREATE TABLE `encomenda` (
  `codigo_encomenda` int(11) NOT NULL,
  `retirado` set('SIM','NÃO') NOT NULL,
  `tamanho` set('XS','S','M','L','XL') NOT NULL,
  `codigo_itens` int(11) NOT NULL,
  `modelo` varchar(50) NOT NULL,
  `status` set('FINALIZADO','EM ANDAMENTO') NOT NULL,
  `codigo_cliente` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Estrutura para tabela `funcionarios`
--

CREATE TABLE `funcionarios` (
  `codigo_funcionario` int(11) NOT NULL,
  `codigo_usuario` int(11) NOT NULL,
  `cargo` varchar(50) NOT NULL,
  `data_ingresso` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Estrutura para tabela `itens`
--

CREATE TABLE `itens` (
  `codigo_itens` int(11) NOT NULL,
  `nome` varchar(100) NOT NULL,
  `descricao` text DEFAULT NULL,
  `quantidade` int(11) NOT NULL,
  `imagem` blob DEFAULT NULL,
  `valor_unidade` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Estrutura para tabela `modelos`
--

CREATE TABLE `modelos` (
  `molde` varchar(50) NOT NULL,
  `tecido_tamanho` int(11) NOT NULL,
  `acessorios_necessarios` int(11) DEFAULT NULL,
  `horas_trabalho` int(11) NOT NULL,
  `tamanho` set('XS','S','M','L','XL') NOT NULL,
  `imagem` blob DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Estrutura para tabela `reservar`
--

CREATE TABLE `reservar` (
  `codigo_reserva` int(11) NOT NULL,
  `codigo_item` int(11) NOT NULL,
  `quantidade` int(11) NOT NULL,
  `codigo_cliente` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Estrutura para tabela `usuarios`
--

CREATE TABLE `usuarios` (
  `codigo` int(11) NOT NULL,
  `nome` varchar(255) NOT NULL,
  `cpf` int(9) NOT NULL,
  `email` varchar(50) NOT NULL,
  `telefone` varchar(15) DEFAULT NULL,
  `endereco` text DEFAULT NULL,
  `identificador` set('C','F') NOT NULL,
  `senha` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Índices para tabelas despejadas
--

--
-- Índices de tabela `clientes`
--
ALTER TABLE `clientes`
  ADD PRIMARY KEY (`codigo_cliente`),
  ADD KEY `especializacao_cliente` (`codigo_usuario`);

--
-- Índices de tabela `encomenda`
--
ALTER TABLE `encomenda`
  ADD PRIMARY KEY (`codigo_encomenda`),
  ADD KEY `encomenda_itens` (`codigo_itens`),
  ADD KEY `encomenda_modelo` (`modelo`,`tamanho`),
  ADD KEY `encomenda_cliente` (`codigo_cliente`);

--
-- Índices de tabela `funcionarios`
--
ALTER TABLE `funcionarios`
  ADD PRIMARY KEY (`codigo_funcionario`),
  ADD KEY `especializacao_funcionario` (`codigo_usuario`);

--
-- Índices de tabela `itens`
--
ALTER TABLE `itens`
  ADD PRIMARY KEY (`codigo_itens`);

--
-- Índices de tabela `modelos`
--
ALTER TABLE `modelos`
  ADD PRIMARY KEY (`molde`,`tamanho`);

--
-- Índices de tabela `reservar`
--
ALTER TABLE `reservar`
  ADD PRIMARY KEY (`codigo_reserva`),
  ADD KEY `reserva_item` (`codigo_item`),
  ADD KEY `reserva_cliente` (`codigo_cliente`);

--
-- Índices de tabela `usuarios`
--
ALTER TABLE `usuarios`
  ADD PRIMARY KEY (`codigo`);

--
-- AUTO_INCREMENT para tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `clientes`
--
ALTER TABLE `clientes`
  MODIFY `codigo_cliente` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de tabela `encomenda`
--
ALTER TABLE `encomenda`
  MODIFY `codigo_encomenda` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de tabela `funcionarios`
--
ALTER TABLE `funcionarios`
  MODIFY `codigo_funcionario` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de tabela `itens`
--
ALTER TABLE `itens`
  MODIFY `codigo_itens` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de tabela `reservar`
--
ALTER TABLE `reservar`
  MODIFY `codigo_reserva` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de tabela `usuarios`
--
ALTER TABLE `usuarios`
  MODIFY `codigo` int(11) NOT NULL AUTO_INCREMENT;

--
-- Restrições para tabelas despejadas
--

--
-- Restrições para tabelas `clientes`
--
ALTER TABLE `clientes`
  ADD CONSTRAINT `especializacao_cliente` FOREIGN KEY (`codigo_usuario`) REFERENCES `usuarios` (`codigo`);

--
-- Restrições para tabelas `encomenda`
--
ALTER TABLE `encomenda`
  ADD CONSTRAINT `encomenda_cliente` FOREIGN KEY (`codigo_cliente`) REFERENCES `clientes` (`codigo_cliente`),
  ADD CONSTRAINT `encomenda_itens` FOREIGN KEY (`codigo_itens`) REFERENCES `itens` (`codigo_itens`),
  ADD CONSTRAINT `encomenda_modelo` FOREIGN KEY (`modelo`,`tamanho`) REFERENCES `modelos` (`molde`, `tamanho`);

--
-- Restrições para tabelas `funcionarios`
--
ALTER TABLE `funcionarios`
  ADD CONSTRAINT `especializacao_funcionario` FOREIGN KEY (`codigo_usuario`) REFERENCES `usuarios` (`codigo`);

--
-- Restrições para tabelas `reservar`
--
ALTER TABLE `reservar`
  ADD CONSTRAINT `reserva_cliente` FOREIGN KEY (`codigo_cliente`) REFERENCES `clientes` (`codigo_cliente`),
  ADD CONSTRAINT `reserva_item` FOREIGN KEY (`codigo_item`) REFERENCES `itens` (`codigo_itens`);
COMMIT;

--
-- Exemplos de consultas que serão realizadas no programa
--
/*
SELECT `itens`.`nome`
FROM `itens`
WHERE `itens`.`quantidade` <= '20';

--

SELECT `encomenda`.`codigo_encomenda`, `encomenda`.`codigo_cliente`
FROM `encomenda`
WHERE `encomenda`.`status` = 'FINALIZADO';

--

SELECT `encomenda`.*, `usuarios`.`nome`
FROM `encomenda`, `usuarios`, `clientes`
WHERE `clientes`.`codigo_cliente` = `encomenda`.`codigo_cliente`
    AND `usuarios`.`codigo` = `clientes`.`codigo_usuario`;

--

SELECT `usuarios`.`nome`, `usuarios`.`identificador`
FROM `usuarios`;

--

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
