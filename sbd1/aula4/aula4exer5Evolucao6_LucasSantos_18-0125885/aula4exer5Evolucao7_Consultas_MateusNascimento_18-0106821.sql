-- ---------------------   << PROJETO Aula 4 Exercicio 5 Evolucao 7  >>   ---------------------
--
--                    SCRIPT DE CONSULTA (DQL)
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

-- A) Apresentar todos os dados dos médicos de uma determinada especialidade fornecida pelo usuário
SELECT M.*
FROM possui as P 
RIGHT JOIN MEDICO as M 
    on P.crm = M.crm
WHERE P.idEspecialidade = 3;

-- B) Consultar paciente(s) por qualquer parte do nome fornecido pelo usuário
SELECT *
FROM PACIENTE as P
WHERE nomeCompleto like '%Souza%';

-- C) Mostrar o médico e o nome do paciente que tiveram consultas em uma data no padrão DE... ATÉ..
SELECT M.*, P.nomeCompleto
FROM CONSULTA AS C
INNER JOIN MEDICO AS M
	ON C.crm = M.crm
INNER JOIN PACIENTE AS P
	ON C.idPaciente = P.idPaciente
WHERE DATE(dataConsulta) > '2016-01-01' AND DATE(dataConsulta) < '2021-03-15';

-- D) Pesquisar quantos médicos existem por especialidade
SELECT P.idEspecialidade, COUNT(DISTINCT M.crm) AS quantidadeMedicos
FROM possui as P 
RIGHT JOIN MEDICO as M 
    on P.crm = M.crm
GROUP BY P.idEspecialidade
ORDER BY P.idEspecialidade;