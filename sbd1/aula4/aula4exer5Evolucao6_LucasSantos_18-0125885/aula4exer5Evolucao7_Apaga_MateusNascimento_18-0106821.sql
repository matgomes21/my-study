-- --------  << RECEITUÁRIO - aula4exer5Evolucao7  >>  ----------
--
--                    SCRIPT DE APAGAR
--
-- Data Criacao ...........: 19/04/2021
-- Autor(es) ..............: Mateus Gomes do Nascimento
-- Banco de Dados .........: MySQL 8.0
-- Base de Dados (nome) ...: aula4exer5Evolucao7
--
-- Ultimas Alteracoes
--
-- PROJETO => 01 Base de Dados
--         => 9 Tabelas
--         => 02 Usuarios
--
-- ---------------------------------------------------------

USE aula4exer5Evolucao7;

DROP TABLE contem;
DROP TABLE MEDICAMENTO;
DROP TABLE RECEITA;
DROP TABLE CONSULTA;
DROP TABLE telefone;
DROP TABLE PACIENTE;
DROP TABLE possui;
DROP TABLE MEDICO;
DROP TABLE ESPECIALIDADE;

DROP USER 'dono'@'localhost';
DROP USER 'usuario'@'localhost';