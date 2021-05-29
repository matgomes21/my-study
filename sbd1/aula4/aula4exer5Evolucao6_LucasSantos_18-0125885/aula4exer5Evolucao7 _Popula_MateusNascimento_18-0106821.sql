-- --------  << RECEITUÁRIO - aula4exer5Evolucao7 >>  ----------
--
--                    SCRIPT DE POPULACAO (DML)
--
-- Data Criacao ...........: 19/04/2021
-- Autor(es) ..............: Mateus Gomes do Nascimento
-- Banco de Dados .........: MySQL 8.0
-- Base de Dados (nome) ...: aula4exer5Evolucao7
--
-- PROJETO => 01 Base de Dados
--         => 09 Tabelas
--         => 02 Usuarios
--
-- ---------------------------------------------------------
USE aula4exer5Evolucao7;

INSERT INTO MEDICO(nomeCompleto, crm, estado) VALUES
('Italo Silva Melo', 1030, 'RJ'),
('Marta Caixeta de Souza', 243322, 'SP'),
('Lucas Neves Pereira', 231113, 'DF'),
('Lucas Coutinho pereira', 3221140, 'CE'),
('Mateus Gomes do Nascimento', 212916, 'DF'),
('Ana Teresa Borges', 292116, 'MG'),
('Felipe Silva da Costa', 133716, 'RS');

INSERT INTO PACIENTE(nomeCompleto, dtNascimento, sexo, rua, numero, bairro, complemento, cidade, estado, cep) VALUES
('Carlos Figueireido Costa','1988-05-03', 'M',  'Rua Expedito José Sousa Farias 117', 714, 'Centro', null,'Sobral', 'CE', '72443301' ),
('Maria Ferreira de Souza','1970-03-10', 'F',  'Rua Sebastião Gomes Pereira', 798, 'Jardim Dayse', 'Em frente ao posto de gasolina','São Paulo', 'SP', '08528030'),
('Arthur Peixoto Dias', '1980-11-12', 'M',  'Beco São Jorge', 717,'Bonsucesso', 'em frente ao mercado Primor', 'Rio de Janeiro', 'RJ', '21042695'),
('Matheus Paes Lima', '1985-09-11', 'M',  'Quadra SRES Quadra 10 Bloco T1', 190, 'Cruzeiro Velho', null,'Cruzeiro Velho', 'DF', '70645201'),
('Douglas de Souza Nogueira', '1988-09-05', 'M',  'CSB 9', 4, 'Taguatinga', 'Apt 102', 'Brasília', 'DF', '72015595'),
('Juliana Ferreira Souza', '1994-01-21', 'F',  'QNL 3', 2, 'Liberdade', null,'São Paulo', 'SP', '70645277'),
('Diego Souza Fernandes', '1995-09-22', 'M',  'Araucárias', 33, 'Águas Claras', null,'Brasília', 'DF', '70335244');	

INSERT INTO MEDICAMENTO(principioAtivo) VALUES
('DIPIRONA'),
('ROSUVASTINA'),
('HIDROQUINONA'),
('IBUPROFENO'),
('ACARBOSE'),
('ABERMACICLIBE'),
('PACLITAXEL');

INSERT INTO ESPECIALIDADE(nomeEspecialidade) VALUES
 ('CARDIOLOGISTA'),
 ('DERMATOLOGISTA'),
 ('INFECTOLOGISTA'),
 ('UROLOGISTA'),
 ('GASTROLOGISTA'),
 ('FONOLOGISTA'),
 ('NEUROLOGISTA');
 
INSERT INTO CONSULTA( dataConsulta, horaConsulta, crm, estado, idPaciente) VALUES
('2017-09-16', '13:10:15', 1030, 'RJ', 3),
('2019-10-11', '14:09:12', 231113, 'DF', 2),
('2020-09-16', '19:10:10', 243322, 'SP', 1),
('2016-02-03', '16:10:55', 3221140, 'CE', 4),
('2020-10-16', '18:10:10', 243322, 'SP', 1),
('2020-11-16', '17:10:10', 243322, 'SP', 1),
('2020-12-16', '16:10:10', 243322, 'SP', 1);

INSERT INTO RECEITA(dataEmissao, posologia, idConsulta) VALUES
('2017-09-16', 'tomar dipirona 2 vezes ao dia durante 2 semanas ', 1),
('2019-10-11', 'tomar rosuvastatina 1 vez por dia durante 1 mês', 2),
('2020-09-16', 'usar todos os dias Hidroquinona por 2 meses', 3),
('2021-03-12', 'tomar ibuprofeno por 2 semanas de 8 em 8 horas', 4),
('2021-04-15', 'tomar 3 doses ao dia', 5),
('2015-12-03', 'tomar antes de dormir', 6),
('2016-07-17', 'tomar a cada 2 horas pulando a dose da noite', 7);
 
 INSERT INTO possui(crm, estado, idEspecialidade) VALUES
 (1030, 'RJ', 1),
 (243322, 'SP', 2),
 (231113, 'DF', 3),
 (212916, 'DF', 3),
 (292116, 'MG', 3),
 (133716, 'RS', 3),
 (3221140, 'CE', 4);
 

INSERT INTO telefone(idPaciente, telefone) VALUES
(1, '6198321-4401'),
(2, '6193211-3874'),
(3, '6199032-2880'),
(4, '6199032-2340'),
(5, '6199692-7595'),
(6, '6199692-2880'),
(7, '6199032-7595');


INSERT INTO contem(idReceita, idMedicamento)VALUES
  (1,1),
  (2,2),
  (3,3),
  (4,4),
  (5,5),
  (6,6),
  (7,7);