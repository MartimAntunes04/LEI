//Ficha3

exec naluno (2022141890)

//ex3
select titulo,genero 
from livros ,autores
where preco_tabela < 20 
and autores.codigo_autor=livros.codigo_autor
and nome = 'J. K. Rowling'
order by titulo;
EXEC SQLCHECK('FCINKYPCGVYDGGH');

//ex4
select livros.titulo,livros.genero,autores.nome,autores.morada
from autores,livros
where morada like '%Cascais%'
and livros.codigo_autor=autores.codigo_autor
and not genero='Romance'
order by titulo;
EXEC SQLCHECK('FCEKVCZDJCDXCDF');

//ex5
select distinct  autores.nome,autores.idade,autores.genero_preferido
from livros,autores
where livros.codigo_autor=autores.codigo_autor
and livros.genero=genero_preferido
order by nome;
EXEC SQLCHECK('FCUXGHVEQFTXWVO')

//ex6
select distinct titulo,genero,preco_tabela,paginas
from livros,clientes,vendas
where paginas > 300 
and livros.codigo_livro=vendas.codigo_livro
and vendas.codigo_cliente=clientes.codigo_cliente
and clientes.morada like '%Porto%'
order by titulo;
EXEC SQLCHECK('FCOAPRNFTZUAMIP');


//ex7
select distinct nome,genero_preferido,titulo,genero as "Genero do Livro"
from livros,autores
where preco_tabela < 40
and autores.codigo_autor = livros.codigo_autor
and not livros.genero = autores.genero_preferido
order by nome,titulo; 
EXEC SQLCHECK('FCTVMKWGHTEVJOA');

//ex8
select distinct titulo,preco_tabela,unidades_vendidas,round (unidades_vendidas * preco_tabela * 0.20,2) as "Rendeu"
from livros,vendas
where genero = 'Fantástico'
order by "Rendeu" desc;
EXEC SQLCHECK('FCGBQWUHPLOLVGV');

//ex9
SELECT DISTINCT
    A.NOME AS "NOME",
    A.IDADE AS "IDADE",
    A.MORADA AS "MORADA"
FROM
    AUTORES A
JOIN
    CLIENTES C ON A.N_CONTRIBUINTE = C.N_CONTRIBUINTE
JOIN
    VENDAS V ON C.CODIGO_CLIENTE = V.CODIGO_CLIENTE
JOIN
    LIVROS L ON V.CODIGO_LIVRO = L.CODIGO_LIVRO
ORDER BY
    A.NOME;
EXEC SQLCHECK('FCHIEOUIJMGUZSG');


//ex10
select  titulo,genero,preco_tabela,trunc(preco_tabela*unidades_vendidas * 0.2,0 ) as "Rendimento"
from livros
where preco_tabela*unidades_vendidas * 0.2 > 400000 
order by preco_tabela * unidades_vendidas * 0.2 desc,preco_tabela desc;
EXEC SQLCHECK('FCTTXUUJYDKYYCO');

//ex11
select titulo,preco_tabela,paginas,round(preco_tabela/paginas*100,2) as "Custo página",
ceil (preco_tabela/paginas*100) as "Custo pág.(sup)", floor (preco_tabela/paginas*100) as "Custo pág.(inf)"
from livros
where paginas between 100 and 300
order by titulo;
EXEC SQLCHECK('FCQVTXHKQBHFJBZ');


//ex12
select LOWER (titulo) as "Titulo (em minusculas)",
UPPER (titulo) as "Titulo (em maisculas)",
initcap(titulo) as "Titulo (1a letra maiúscula)"
from livros
where genero='Informática'
order by titulo;
EXEC SQLCHECK('FCFXAVLLOEBMIEN');

//ex13
select titulo as "Titulo" ,preco_tabela as "Preco",Quant_em_stock as "Quantidade em stock"
from livros
where lower (genero) = 'romance'
order by quant_em_stock desc;
EXEC SQLCHECK('FCROYAZMYRXAHEL');


//ex14
SELECT nome AS "Nome completo",
       SUBSTR(nome, 1, INSTR(nome, ' ') - 1) AS "Primeiro Nome",
       SUBSTR(nome, INSTR(nome, ' ', -1) + 1) AS "Ultimo Nome"
FROM autores
WHERE genero_preferido = 'Informática'
ORDER BY idade, nome;
EXEC SQLCHECK('FCVMAFTNZJENMQU');   

//ex15
select LOWER(livros.titulo) as "Titulo (em minusculas)",UPPER(livros.genero) as "genero (maisculas)",
initcap(autores.nome) as "Nome Autor (1a letra)"
from livros,autores,editoras
where livros.codigo_autor=autores.codigo_autor and livros.codigo_editora=editoras.codigo_editora and editoras.nome like 'FCA%' and genero = genero_preferido
order by titulo desc;
EXEC SQLCHECK('FCKUJPVODLJWHHD');

//ex16
select titulo,genero
from livros
where titulo like '%f%' and length(titulo) >35
order by titulo;
EXEC SQLCHECK('FCYYGHXPVYZLYEN');

//ex17
select titulo,preco_tabela as "PRECO",ROUND(preco_tabela+(preco_tabela*0.08),1)  as "PRECO_COM_AUMENTO"
from livros
where preco_tabela >20 and genero='Fantástico'
order by preco_tabela+(preco_tabela*0.08) desc;
EXEC SQLCHECK('FCGQIBVQANPMAAK');

