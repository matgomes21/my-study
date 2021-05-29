-- ---------------------   << PROJETO Aula 4 Exercicio 5 Evolucao 7  >>   ---------------------
--
--                    SCRIPT DE CRIAÇÂO DE USUÁRIO
-- 
-- Data Criacao ...........: 19/04/2021
-- Autor(es) ..............: Mateus Gomes do Nascimento
-- Banco de Dados .........: MySQL 8.0
-- Banco de Dados(nome) ...: aula4exer5Evolucao7
-- 
-- 
-- PROJETO => 01 Base de Dados
--         => 09 Tabelas
--         => 02 Usuarios
-- 
-- -----------------------------------------------------------------

CREATE USER 'dono'@'localhost' IDENTIFIED BY 'dono21';
GRANT ALL PRIVILEGES ON  aula4exer5Evolucao7.* TO 'dono'@'localhost';

CREATE USER 'usuario'@'localhost' IDENTIFIED BY 'usu21';
GRANT SELECT ON  aula4exer5Evolucao7.* TO 'usuario'@'localhost';
GRANT INSERT ON  aula4exer5Evolucao7.MEDICO TO 'usuario'@'localhost';

FLUSH PRIVILEGES;