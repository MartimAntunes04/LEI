//Ficha 11

//ex4
CREATE TABLE EDITORAS_BACKUP AS (
    SELECT 
        CODIGO_EDITORA,
        NOME,
        N_CONTRIBUINTE,
        MORADA,
        TELEFONE,
        FAX
FROM EDITORAS

);


//ex5
ALTER TABLE EDITORAS_BACKUP
ADD (
    CONSTRAINT codigo_editora_pk PRIMARY KEY(CODIGO_EDITORA),
    CONSTRAINT codigo_editora_not_null CHECK (CODIGO_EDITORA IS NOT NULL),
    CONSTRAINT nome_not_null CHECK (NOME IS NOT NULL),
    CONSTRAINT contribuinte_not_null CHECK (N_CONTRIBUINTE IS NOT NULL),
    CONSTRAINT nif_unico UNIQUE (N_CONTRIBUINTE)
);


//ex6
CREATE SEQUENCE seq_editback
  START WITH 10
  INCREMENT BY 1
  NOMAXVALUE
  NOCYCLE;
  
//ex7
INSERT INTO EDITORAS_BACKUP (CODIGO_EDITORA,NOME,N_CONTRIBUINTE,MORADA,TELEFONE,FAX)
VALUES (seq_editback.NEXTVAL,'D.Quixote',901111111,'Rua Cidade de Córdova, n.2 2610-038 Alfragide, Portugal',707252252,707252253);

//ex8
INSERT INTO EDITORAS_BACKUP(CODIGO_EDITORA,NOME,N_CONTRIBUINTE,MORADA,TELEFONE,FAX)
VALUES(seq_editback.NEXTVAL,'Almedina',901212121,'Rua Fernandes Tomás, n.º 76 a 80, 3000-167 Coimbra, Portugal',239851903,239851904);

//ex9
SELECT seq_editback.CURRVAL FROM dual;

-- Avançar para o próximo valor da sequência
SELECT seq_editback.NEXTVAL FROM dual;

-- Verificar novamente o valor atual da sequência
SELECT seq_editback.CURRVAL FROM dual;

//ex10
DROP SEQUENCE seq_editback;

//ex11
CREATE VIEW livros_informatica AS
SELECT *
FROM LIVROS
WHERE GENERO = 'Informática';

//ex12
INSERT INTO livros_informatica (codigo_livro, titulo,isbn, genero) VALUES (50,'Uma noite de Verão', 8000000001,'Informática');
//Esta instrução insere um novo livro com código 50, título 'Uma noite de Verão', ISBN 8000000001 e género 'Informática' na tabela livros_informatica. Não há implicações negativas nesta inserção, desde que os valores respeitem as restrições e formatos das colunas da tabela.

INSERT INTO livros_informatica (codigo_livro, titulo,isbn, genero) VALUES (51,'O céu é azul',8000000002,'Romance');
//Semelhante à primeira instrução, esta insere um novo livro com código 51, título 'O céu é azul', ISBN 8000000002 e género 'Romance' na tabela livros_informatica. Não há problemas aparentes nesta inserção.

INSERT INTO livros (codigo_livro, codigo_editora, codigo_autor,titulo,isbn, genero) VALUES  (52,2, 2,'Longe de tudo',8000000003,'Informática');
//Esta instrução insere um novo livro com código 52, título 'Longe de tudo', ISBN 8000000003, género 'Informática', código de editora 2 e código de autor 2 na tabela livros. No entanto, há uma aparente incongruência, pois a tabela livros está sendo usada, mas os dados estão relacionados ao género 'Informática', que deveria ser tratado pela tabela livros_informatica. Isso pode resultar em inconsistências no banco de dados, especialmente se as tabelas livros e livros_informatica tiverem propósitos diferentes.

//ex13
DELETE FROM livros
WHERE CODIGO_LIVRO=50;

DELETE FROM livros
WHERE CODIGO_LIVRO=51;

DELETE FROM livros
WHERE CODIGO_LIVRO=52;

//ex14
DROP VIEW livros_informatica;

//ex15
CREATE TABLE LIVROS_BACKUP AS
SELECT
    CODIGO_LIVRO,
    CODIGO_EDITORA,
    CODIGO_AUTOR,
    TITULO,
    ISBN,
    GENERO,
    PRECO_TABELA,
    PAGINAS,
    QUANT_EM_STOCK,
    UNIDADES_VENDIDAS,
    DATA_EDICAO
FROM LIVROS;

//ex16
CREATE VIEW autor_livro AS
SELECT 
    UPPER(A.NOME) AS NOME_AUTOR,
    UPPER(L.TITULO) AS TITULO_LIVRO
FROM 
    AUTORES_BACKUP A
JOIN 
    LIVROS_BACKUP L ON A.CODIGO_AUTOR = L.CODIGO_AUTOR;
    
//ex17
SELECT *
FROM autor_livro;

//ex18
DELETE FROM LIVROS_BACKUP;

//ex19
SELECT *
FROM autor_livro;
//A CONSULTA ESTA VAZIA

//ex20
DROP TABLE livros_backup;

//ex21
SELECT *
FROM autor_livro;
// Dá erro, pois a tabela subjacente à vista não existe mais

//ex22
CREATE VIEW livros_vendidos AS
SELECT
    L.TITULO,
    A.NOME AS NOME_AUTOR,
    COUNT(V.CODIGO_LIVRO) AS QUANTIDADE_VENDIDA
FROM
    LIVROS L
JOIN
    AUTORES A ON L.CODIGO_AUTOR = A.CODIGO_AUTOR
JOIN
    VENDAS V ON L.CODIGO_LIVRO = V.CODIGO_LIVRO
GROUP BY
    L.CODIGO_LIVRO, L.TITULO, A.NOME
ORDER BY
    QUANTIDADE_VENDIDA DESC;
    
//ex23
SELECT TABLE_NAME
FROM USER_TABLES;

//ex24
SELECT TABLE_NAME, CONSTRAINT_NAME, CONSTRAINT_TYPE
FROM USER_CONSTRAINTS;