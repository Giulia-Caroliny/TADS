-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Tempo de geração: 09-Nov-2023 às 12:30
-- Versão do servidor: 10.4.28-MariaDB
-- versão do PHP: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `banco_note`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `tb_notebook`
--

CREATE TABLE `tb_notebook` (
  `id_note` int(11) NOT NULL,
  `modelo_note` varchar(255) NOT NULL,
  `marca_note` varchar(255) NOT NULL,
  `serie_note` varchar(6) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Extraindo dados da tabela `tb_notebook`
--

INSERT INTO `tb_notebook` (`id_note`, `modelo_note`, `marca_note`, `serie_note`) VALUES
(1, 'Vaio', 'Sony', '111-11'),
(2, 'Aspiron 300', 'Dell', '222-22'),
(3, 'AC 200', 'Acer', '333-33');

--
-- Índices para tabelas despejadas
--

--
-- Índices para tabela `tb_notebook`
--
ALTER TABLE `tb_notebook`
  ADD PRIMARY KEY (`id_note`);

--
-- AUTO_INCREMENT de tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `tb_notebook`
--
ALTER TABLE `tb_notebook`
  MODIFY `id_note` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
