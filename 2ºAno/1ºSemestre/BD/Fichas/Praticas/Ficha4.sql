//Ficha4
//ex3
select titulo,genero,preco_tabela
from livros
where to_char (data_edicao,'YYYY') = '2020'
order by data_edicao desc;
EXEC SQLCHECK('FDTWGOFCTGHDGFG');

//ex4
select to_char(sysdate,'DDTH, Month, YYYY') as "DATA Atual",
to_char (sysdate,'HH24:MI:SS AM') as "Hora Min Sec Atual"
from dual;
EXEC SQLCHECK('FDVOLRHDBSMRHUO');

//ex5
select titulo as "Titulo",preco_tabela as "Preco",
to_char(data_edicao,'DD-MM-YYYY') as data_edicao
from livros
where data_edicao >= sysdate - 180;
EXEC SQLCHECK('FDMNLCZEJJLUIAV');


//ex6
select distinct livros.titulo, to_char (data_edicao,'DD-MM-YYYY')as "DATA"
from livros,vendas,clientes
where livros.codigo_livro = vendas.codigo_livro
and vendas.codigo_cliente = clientes.codigo_cliente
and clientes.morada like '%Lisboa%'
and vendas.data_venda between to_date ('2014-01-15','YYYY-MM-DD') and to_date ('2014-02-18','YYYY-MM-DD')
order by to_char(data_edicao,'DD-MM-YYYY'),livros.titulo;
    


//ex7
select titulo,TO_CHAR(data_edicao, 'YYYY-MM') AS ANO_MES
from livros, vendas
where livros.codigo_livro = vendas.codigo_livro
and upper(genero) = 'INFORMÁTICA'
and to_char(data_edicao, 'MM-YYYY') = to_char(data_venda, 'MM-YYYY')
order by ANO_MES;
EXEC SQLCHECK('FDOVPNBGJYYXKBW');


//ex8
select distinct nome
from livros,autores
where livros.codigo_autor = autores.codigo_autor
and data_edicao between to_date('2013-12-21','YYYY-MM-DD') and to_date ('2014-03-21','YYYY-MM-DD')
and paginas< 630
and INITCAP(genero) like 'Informática'
order by nome;
EXEC SQLCHECK('FDHHZHYHUIKALHN');


//ex9
SELECT genero, titulo AS "Titulo", TO_CHAR(data_edicao, 'dd-mm-yyyy') AS "DATA_EDICAO",TRUNC(MONTHS_BETWEEN(sysdate, data_edicao) / 12) AS "Num. de anos"
FROM livros
WHERE genero = 'Romance' OR genero = 'Aventura'
ORDER BY genero, titulo;
EXEC SQLCHECK('FDLGBFHIIJNSMYO');

//ex10
select nome
from clientes,vendas
where clientes.codigo_cliente = vendas.codigo_cliente
and data_venda = next_day (data_venda-1,7)
and to_char(data_venda,'HH24') > 20
order by nome;
EXEC SQLCHECK('FDSINCQJUJVPNCI');

//ex11
select nome,idade
from autores
MINUS
select nome,idade
from autores,livros
where autores.codigo_autor = livros.codigo_autor
order by idade;
EXEC SQLCHECK('FDKXFDFKEVZVOTU');

//ex12
select nome
from autores
where nome not in (
    select nome
    from autores,livros
    where autores.codigo_autor = livros.codigo_autor
)
or nome in(
    select nome
    from autores,livros
    where autores.codigo_autor = livros.codigo_autor
    and to_char (data_edicao,'YYYY') = '2023'
)
order by nome desc;
EXEC SQLCHECK('FDBJQVPLQMMGPLE');
