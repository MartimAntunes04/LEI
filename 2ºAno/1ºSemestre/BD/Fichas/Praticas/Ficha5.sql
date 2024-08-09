//ex3
select COUNT (*) as "Num Livros de Informática"
from livros
where genero = 'Informática'
and preco_tabela between 20 and 40;
EXEC SQLCHECK('FEKPMBHCGFHKHRG');


//ex4
select COUNT (*) as "Num Livros Editados",
SUM(unidades_vendidas) as "Total Unidades vendidas",
AVG(preco_tabela) as "Preço de Tabela Médio"
from livros
where genero = 'Romance' or genero = 'Aventura';
EXEC SQLCHECK('FEQZNHADADLXIRE');


//ex5
select genero, COUNT (*) as "Num. Livros Editados"
from livros
Group by genero
order by COUNT (codigo_livro) desc , genero;
EXEC SQLCHECK('FETUCAREYKNOJEP');


//ex6
select titulo,
MIN(preco_unitario) as "PRECO_MAIS_BAIXO", 
MAX(preco_unitario) as "PRECO_MAIS_ALTO",
ROUND(AVG(preco_unitario),2) as "PRECO_MEDIO"
from livros,vendas
WHERE genero = 'Informática' and livros.codigo_livro = vendas.codigo_livro
GROUP BY titulo
order by MAX(preco_unitario) desc , titulo; 
EXEC SQLCHECK('FEMKYWMFLFBFKTH');

//ex7
select genero,
COUNT (*) as "N_LIVROS_EDITADOS",
(MAX(preco_tabela) - MIN(preco_tabela)) as "DIFERENCA_MAX_MIN"
from livros
GROUP BY genero
order by DIFERENCA_MAX_MIN desc;
EXEC SQLCHECK('FEAUZTGGYJWBLSU');


//ex8
select titulo,
preco_tabela,
SUM (quantidade) as "NUM_VENDIDOS",
SUM (quantidade * preco_tabela) as "RECEITA_ESPERADA",
SUM (quantidade * preco_unitario)as "RECEITA_EFECTIVA"
from livros,vendas
where livros.codigo_livro = vendas.codigo_livro
and to_char(vendas.data_venda,'YYYY') = '2022'
GROUP BY titulo,preco_tabela
order by SUM(quantidade);
EXEC SQLCHECK('FELBAFEHXKEYMHB');


//ex9
select genero, ceil(AVG(preco_tabela)) as "PRECO Médio"
from livros
having COUNT (titulo) > 3
GROUP BY genero
order by AVG(preco_tabela) desc,genero;
EXEC SQLCHECK('FEMDMOHIGBIPNYO');


//ex10
select autores.nome,
MIN(livros.preco_tabela)as "Preco do Mais Barato",
MAX(livros.preco_tabela) as "Preco do Mais Caro"
from livros,autores
where livros.codigo_autor = autores.codigo_autor
GROUP BY autores.nome
HAVING not MIN(livros.preco_tabela)< 10 and not MIN(livros.preco_tabela) > 25
and  MIN(livros.preco_tabela) < MAX(livros.preco_tabela)
order by MIN(livros.preco_tabela), autores.nome;
EXEC SQLCHECK('FEFWWIEJQMYQOLI');

//ex11
select clientes.nome,
SUM (vendas.quantidade) as "N.Livros Comprados",
ROUND(AVG(vendas.preco_unitario),1) as "Preco Medio",
COUNT(distinct livros.codigo_autor) as "N.Autor Diferent"
from livros,vendas,clientes
where clientes.codigo_cliente = vendas.codigo_cliente
and livros.codigo_livro = vendas.codigo_livro
and upper (clientes.morada) not like '%LISBOA%'
GROUP BY clientes.nome,clientes.codigo_cliente
HAVING COUNT (distinct livros.codigo_editora) <= 1
order by clientes.nome;
EXEC SQLCHECK('FEXIBSQKCAWKPBN');


//ex12
select autores.nome, 
REPLACE(COUNT(codigo_livro),0,'Nenhum') as "Num de Livros escritos"
from autores,livros
where autores.codigo_autor = livros.codigo_autor(+)
and autores.idade > 50
GROUP BY autores.nome
HAVING COUNT(codigo_livro) <= 3
order by autores.nome;
EXEC SQLCHECK('FEKXNTJLDGJOQTJ');
