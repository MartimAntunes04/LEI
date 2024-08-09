CREATE TABLE dep (
  ndep NUMBER(2,0),
  nome  VARCHAR2(14),
  loc    VARCHAR2(13),
  CONSTRAINT pk_dep PRIMARY KEY (ndep)
);

INSERT INTO dep VALUES(10, 'CONTABILIDADE', 'NEW YORK');
INSERT INTO dep VALUES(20, 'INVESTIGAÇÃO', 'DALLAS');
INSERT INTO dep VALUES(30, 'VENDAS', 'CHICAGO');
INSERT INTO dep VALUES(40, 'OPERACOES', 'BOSTON');
COMMIT;

CREATE TABLE emp (
  nemp    NUMBER(4,0),
  nome    VARCHAR2(10),
  funcao      VARCHAR2(9),
  encar      NUMBER(4,0),
  data_entrada DATE,
  sal      NUMBER(7,2),
  premios     NUMBER(7,2),
  ndep   NUMBER(2,0),
  CONSTRAINT pk_emp PRIMARY KEY (nemp),
  CONSTRAINT fk_ndep FOREIGN KEY (ndep) REFERENCES dep (ndep)
  CONSTRAINT fk_encar FOREIGN KEY (encar) REFERENCES emp (nemp)
);

INSERT INTO emp VALUES(
 7839, 'KING', 'PRESIDENTE', null,
 to_date('17-11-1981','dd-mm-yyyy'),
 5000, null, 10 );

INSERT INTO emp VALUES(
 7698, 'BLAKE', 'GESTOR', 7839,
 to_date('1-5-1981','dd-mm-yyyy'),
 2850, null, 30);

INSERT INTO emp VALUES(
 7782, 'CLARK', 'GESTOR', 7839,
 to_date('9-6-1981','dd-mm-yyyy'),
 2450, null, 10);

INSERT INTO emp VALUES(
 7566, 'JONES', 'GESTOR', 7839,
 to_date('2-4-1981','dd-mm-yyyy'),
 2975, null, 20);

INSERT INTO emp VALUES(
 7788, 'SCOTT', 'ANALISTA', 7566,
 to_date('13-JUL-87','dd-mm-rr') - 85,
 3000, null, 20);

INSERT INTO emp VALUES(
 7902, 'FORD', 'ANALISTA', 7566,
 to_date('3-12-1981','dd-mm-yyyy'),
 3000, null, 20 );

INSERT INTO emp VALUES(
 7369, 'SMITH', 'CONTABILISTA', 7902,
 to_date('17-12-1980','dd-mm-yyyy'),
 800, null, 20 );

INSERT INTO emp VALUES(
 7499, 'ALLEN', 'VENDEDOR', 7698,
 to_date('20-2-1981','dd-mm-yyyy'),
 1600, 300, 30);

INSERT INTO emp VALUES(
 7521, 'WARD', 'VENDEDOR', 7698,
 to_date('22-2-1981','dd-mm-yyyy'),
 1250, 500, 30 );

INSERT INTO emp VALUES(
 7654, 'MARTIN', 'VENDEDOR', 7698,
 to_date('28-9-1981','dd-mm-yyyy'),
 1250, 1400, 30 );

INSERT INTO emp VALUES(
 7844, 'TURNER', 'VENDEDOR', 7698,
 to_date('8-9-1981','dd-mm-yyyy'),
 1500, 0, 30);

INSERT INTO emp VALUES(
 7876, 'ADAMS', 'CONTABILISTA', 7788,
 to_date('13-JUL-87', 'dd-mm-rr') - 51,
 1100, null, 20 );

INSERT INTO emp VALUES(
 7900, 'JAMES', 'CONTABILISTA', 7698,
 to_date('3-12-1981','dd-mm-yyyy'),
 950, null, 30 );

INSERT INTO emp VALUES(
 7934, 'MILLER', 'CONTABILISTA', 7782,
 to_date('23-1-1982','dd-mm-yyyy'),
 1300, null, 10 );
COMMIT;

CREATE TABLE descontos (
  escalao NUMBER,
  salinf NUMBER,
  salsup NUMBER
);
INSERT INTO descontos VALUES (1, 700, 1200);
INSERT INTO descontos VALUES (2, 1201, 1400);
INSERT INTO descontos VALUES (3, 1401, 2000);
INSERT INTO descontos VALUES (4, 2001, 3000);
INSERT INTO descontos VALUES (5, 3001, 9999);
COMMIT;


//Ficha TP01

//ex1
select *from emp;

//ex2
select nome,funcao,data_entrada,ndep from emp;

//ex3
select nome,ndep,sal from emp
where sal between 1000 and 2000;

//ex4
select *from emp
order by data_entrada desc;

//ex5
select distinct loc from dep;