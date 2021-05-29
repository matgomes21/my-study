-- --------  << PROJETO Aula 4 Exercicio 5 Evolucao 7 >>  ----------
--
--                    SCRIPT DE CRIACAO (DDL)
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

-- BASE DE DADOS
CREATE DATABASE
    IF NOT EXISTS aula4exer5Evolucao7;

USE aula4exer5Evolucao7;

-- TABELAS
CREATE TABLE IF NOT EXISTS MEDICO (
	nomeCompleto VARCHAR(80) NOT NULL,
    crm VARCHAR(10) NOT NULL,
    estado CHAR(2) NOT NULL,
    CONSTRAINT MEDICO_PK PRIMARY KEY (crm, estado)
) ENGINE = InnoDB;


CREATE TABLE IF NOT EXISTS ESPECIALIDADE (
	nomeEspecialidade VARCHAR(50) NOT NULL,
    idEspecialidade INT NOT NULL AUTO_INCREMENT,
    CONSTRAINT ESPECIALIDADE_PK PRIMARY KEY (idEspecialidade)
) ENGINE = InnoDB AUTO_INCREMENT = 1;


CREATE TABLE IF NOT EXISTS PACIENTE (
    idPaciente INT AUTO_INCREMENT NOT NULL,
    nomeCompleto VARCHAR(80) NOT NULL,
    dtNascimento DATE NOT NULL,
    sexo ENUM('F','M') NOT NULL,
    rua VARCHAR(40) NOT NULL,
    numero INT,
    bairro VARCHAR(50) NOT NULL,
    complemento VARCHAR(100),
    cidade VARCHAR(30) NOT NULL,
    estado CHAR(2) NOT NULL,
    cep VARCHAR(8) NOT NULL,
    CONSTRAINT PACIENTE_PK PRIMARY KEY (idPaciente)
) ENGINE = InnoDB AUTO_INCREMENT = 1;


CREATE TABLE IF NOT EXISTS telefone (
    idPaciente INT NOT NULL,
    telefone VARCHAR(15) NOT NULL,
    CONSTRAINT telefone_PACIENTE_FK FOREIGN KEY (idPaciente)
		REFERENCES PACIENTE(idPaciente)
        ON DELETE CASCADE
) ENGINE = InnoDB;


CREATE TABLE CONSULTA (
    idConsulta INT NOT NULL AUTO_INCREMENT,
    dataConsulta DATE NOT NULL,
    horaConsulta TIME NOT NULL,
    crm VARCHAR(10) NOT NULL,
    estado CHAR(2) NOT NULL,
    idPaciente INT NOT NULL,
    CONSTRAINT CONSULTA_PK PRIMARY KEY (idConsulta),
    CONSTRAINT CONSULTA_MEDICO_FK FOREIGN KEY (crm, estado)
		REFERENCES MEDICO(crm, estado)
        ON DELETE RESTRICT,
    CONSTRAINT CONSULTA_PACIENTE_FK FOREIGN KEY (idPaciente)
		REFERENCES PACIENTE(idPaciente)
        ON DELETE RESTRICT
) ENGINE = InnoDB AUTO_INCREMENT = 1;

CREATE TABLE IF NOT EXISTS RECEITA (
    idReceita INT NOT NULL AUTO_INCREMENT,
    dataEmissao DATE NOT NULL,
    posologia VARCHAR(255) NOT NULL,
    idConsulta INT NOT NULL,
    CONSTRAINT RECEITA_PK PRIMARY KEY (idReceita),
    CONSTRAINT RECEITA_CONSULTA_FK FOREIGN KEY (idConsulta)
		REFERENCES CONSULTA(idConsulta)
		ON DELETE RESTRICT
) ENGINE = InnoDB AUTO_INCREMENT = 1;

CREATE TABLE IF NOT EXISTS MEDICAMENTO (
    idMedicamento INT NOT NULL AUTO_INCREMENT,
    principioAtivo VARCHAR(30) NOT NULL,
    CONSTRAINT MEDICAMENTO_PK PRIMARY KEY (idMedicamento)
) ENGINE = InnoDB AUTO_INCREMENT = 1;

CREATE TABLE IF NOT EXISTS possui (
    crm VARCHAR(10),
    estado CHAR(2),
    idEspecialidade INT,
    CONSTRAINT possui_MEDICO_FK FOREIGN KEY (crm, estado)
		REFERENCES MEDICO(crm, estado)
		ON DELETE RESTRICT,
	CONSTRAINT possui_ESPECIALIDADE_FK FOREIGN KEY (idEspecialidade)
		REFERENCES ESPECIALIDADE(idEspecialidade)
		ON DELETE RESTRICT
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS contem (
    idReceita INT NOT NULL,
    idMedicamento INT NOT NULL,
    CONSTRAINT contem_RECEITA_FK FOREIGN KEY (idReceita)
		REFERENCES RECEITA(idReceita)
		ON DELETE RESTRICT,
    CONSTRAINT contem_MEDICAMENTO_FK FOREIGN KEY (idMedicamento)
		REFERENCES MEDICAMENTO(idMedicamento)
        ON DELETE RESTRICT
) ENGINE = InnoDB;