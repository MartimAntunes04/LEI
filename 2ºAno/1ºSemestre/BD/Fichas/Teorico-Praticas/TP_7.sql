//ex1

CREATE TABLE emp2 AS
SELECT
    NEMP,
    INITCAP(NOME) AS NOME,
    FUNCAO,
    ENCAR,
    DATA_ENTRADA,
    SAL,
    PREMIOS,
    NDEP
FROM emp
WHERE SAL > 1000;
    
//ex2
INSERT INTO EMP2 (NEMP,NOME,FUNCAO,ENCAR,DATA_ENTRADA,SAL,PREMIOS,NDEP)
VALUES (5555,'Agir','Cantor',NULL,to_char(sysdate,'YY.MM.DD'),10000,NULL,40);

//ex3
DELETE FROM EMP2
WHERE NEMP=4902 AND NEMP=4369;

//ex4
DELETE FROM EMP2
WHERE NEMP=4654;

//ex5
DELETE FROM EMP2
WHERE SAL >(
    SELECT avg(sal)
    from EMP2
);

//ex6
DROP TABLE EMP2;
CREATE TABLE emp2 AS
SELECT
    NEMP,
    INITCAP(NOME) AS NOME,
    FUNCAO,
    ENCAR,
    DATA_ENTRADA,
    SAL,
    PREMIOS,
    NDEP
FROM emp
WHERE SAL > 1000;
UPDATE EMP2 e2
SET (NDEP,SAL,PREMIOS)=(
SELECT
 CASE
    WHEN e1.NDEP=10 THEN 20
    WHEN e1.NDEP=20 THEN 30
    WHEN e1.NDEP=30 THEN 40
    ELSE e1.NDEP
    END,
    SAL=SAL + AVG(SAL)*O.20,
    PREMIOS=PREMIOS + AVG(PREMIOS)*0.5,
FROM emp e1
WHERE e1.NEMP = e2.NEMP
AND e1.SAL < (SELECT MAX(SAL) FROM emp e3 WHERE e3.DEPTNO = e1.DEPTNO)
    
);

//ex7
CREATE TABLE EVENTOS(
    nevento NUMBER(7,0),
    designacao VARCHAR2(20 BYTE) NOT NULL,
    descricao VARCHAR2(60 BYTE) NOT NULL,
    CONSTRAINT nevento_pk PRIMARY KEY (nevento),
    CONSTRAINT designcao_unica UNIQUE (designacao)
);

//ex8
CREATE SEQUENCE seq_nevento
  START WITH 10
  INCREMENT BY 10
  NOMAXVALUE
  NOCYCLE;

ALTER TABLE EVENTOS
MODIFY DESIGNACAO VARCHAR2(50 BYTE);
//ex9
INSERT INTO EVENTOS (nevento,designacao,descricao)
VALUES (seq_nevento.NEXTVAL,'AL-BAUHAUS','Festival AL-BAUHAUS Dream Factory');

INSERT INTO Eventos (nevento, designacao, descricao)
VALUES (seq_nevento.NEXTVAL, 'Quando Neva na Anatólia', 'Filme de Ferit Karahan');

INSERT INTO Eventos (nevento, designacao, descricao)
VALUES (seq_nevento.NEXTVAL, 'MANA Timor', 'Exposição de Gabriela Carrascalão');

//ex10
CREATE TABLE EMP3 AS
SELECT 
    NEMP,
   UPPER (NOME) AS NOME ,
    FUNCAO,
    ENCAR,
    DATA_ENTRADA,
    SAL ,
    PREMIOS,
    NDEP
FROM EMP
WHERE SAL > 800;

//ex11
ALTER TABLE EMP3
ADD (
CONSTRAINT EMP_PK PRIMARY KEY(NEMP),
CONSTRAINT ENCAR_FK FOREIGN KEY (ENCAR)
    REFERENCES EMP3(ENCAR),
CONSTRAINT NDEP_FK FOREIGN KEY(NDEP)
    REFERENCES DEP(NDEP)
    );
    
//ex12
CREATE SEQUENCE emp3_key
    START WITH 5
    INCREMENT BY 5
    NOMAXVALUE
    NOCYCLE;
    

ALTER TABLE EMP3
MODIFY NOME VARCHAR2(30 BYTE);


//ex13
INSERT INTO EMP3 (NEMP,NOME,FUNCAO,ENCAR,DATA_ENTRADA,SAL,PREMIOS,NDEP)
VALUES (emp3_key.NEXTVAL,'Carolina Deslandes','Cantor',NULL,to_char(sysdate,'YY.MM.DD'),4500,NULL,40);

INSERT INTO EMP3 (NEMP,NOME,FUNCAO,ENCAR,DATA_ENTRADA,SAL,PREMIOS,NDEP)
VALUES(emp3_key.NEXTVAL,'Toy','Cantor',NULL,to_char(sysdate,'YY.MM.DD'),4000,100,30);

INSERT INTO EMP3 (NEMP,NOME,FUNCAO,ENCAR,DATA_ENTRADA,SAL,PREMIOS,NDEP)
VALUES (emp3_key.NEXTVAL,'António Zambujo','Cantor',NULL,to_char(sysdate,'YY.MM.DD'),5000,200,10);

//ex14



ALTER TABLE EMP3
ADD CONSTRAINT premio_anual CHECK( PREMIOS <= SAL);

//ex15
ALTER TABLE EMP3
ADD data_nascimento DATE;

//ex16
CREATE VIEW inf_emp AS
SELECT
    NEMP AS "Número",
    NOME AS "Nome",
    SAL AS "Salário Mensal",
    PREMIOS AS "Prémio Anual",
     (SELECT NOME FROM EMP3 e_encar WHERE e_encar.ENCAR = EMP3.ENCAR) AS "Nome do Encarregado",
    (SELECT NOME FROM DEP d WHERE d.NDEP = EMP3.NDEP) AS "Nome do Departamento"
FROM EMP3;

//ex17
SELECT "Nome"
FROM inf_emp
WHERE "Nome do Departamento" = 'Vendas' AND "Salário Mensal" > 3000;

//ex18
ALTER SEQUENCE emp3_key INCREMENT BY 10;

//ex19
DROP SEQUENCE emp3_key;

//ex20
CREATE TABLE GASTOS(
    ID_GASTO NUMBER(4,0),
    NDEP NUMBER (2,0),
    VALOR_GASTO NUMBER (10,0),
    DATA_GASTO DATE,
    CONSTRAINT numdep_fk FOREIGN KEY (NDEP)
        REFERENCES DEP(NDEP)
);