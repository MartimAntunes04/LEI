//Ficha 7

//ex3
select livros.titulo,
sum(vendas.quantidade) as "SOMA_QUANTIDADE"
from livros,vendas

where livros.codigo_livro=vendas.codigo_livro
group by livros.titulo
having sum(vendas.quantidade)=(select max(quant)
                                from (select sum(vendas.quantidade)quant
                                from vendas
                                group by vendas.codigo_livro)maior)
order by livros.titulo;
EXEC SQLCHECK('FGQWRMHCENGCJFH');


//ex4
select livros.genero,livros.titulo,livros.paginas
from livros, (select genero,max(unidades_vendidas)m
               from livros
                where paginas> 600
                group by genero)aa
where livros.genero=aa.genero
and livros.unidades_vendidas =  aa.m
order by genero, titulo;
EXEC SQLCHECK('FGQQTBADOXSZKMA');

//ex5
select livros.titulo,autores.nome,livros.unidades_vendidas
from livros,autores, (select codigo_autor, max(unidades_vendidas) m
                     from livros 
                     group by codigo_autor)aa

where livros.codigo_autor=aa.codigo_autor
and autores.codigo_autor = livros.codigo_autor
and livros.unidades_vendidas=aa.m
order by autores.nome,livros.titulo;
EXEC SQLCHECK('FGJZUXGEZPNYLKV');

//ex6
select editoras.nome,livros.titulo,autores.nome as "NOME_AUTOR",livros.unidades_vendidas
from editoras,livros,autores, (select editoras.nome,max(unidades_vendidas) m
                                from editoras,livros
                                where livros.codigo_editora=editoras.codigo_editora
                                group by editoras.nome)aa
where editoras.codigo_editora=livros.codigo_editora
and livros.unidades_vendidas=aa.m
and autores.codigo_autor=livros.codigo_autor
order by editoras.nome,livros.titulo;
EXEC SQLCHECK('FGKMUHRFQTBIMZF');


//ex7
select clientes.codigo_cliente as "Código do Cliente",
clientes.nome as "Nome",
sum(vendas.quantidade) as "NUM_LIVROS_COMPRADOS"
from clientes,vendas
where clientes.codigo_cliente = vendas.codigo_cliente
and to_char(data_venda,'YYYY-q')='2020-4'
group by clientes.codigo_cliente, clientes.nome
having sum(vendas.quantidade) = (select max(sum(vendas.quantidade))
                                from clientes,vendas
                                where clientes.codigo_cliente=vendas.codigo_cliente
                                and to_char(vendas.data_venda,'YYYY-q')='2020-4'
                                 group by clientes.nome,clientes.codigo_cliente);
EXEC SQLCHECK('FGOEDODGBGAONUP');


//ex8

WITH MaxVendas AS (
    SELECT 
        CODIGO_EDITORA, 
        MAX(UNIDADES_VENDIDAS) AS Max_Unid_Vendidas
    FROM 
        LIVROS
    GROUP BY 
        CODIGO_EDITORA
)
SELECT 
    a.NOME AS Nome,
    e.NOME AS "Nome Editora",
    l.UNIDADES_VENDIDAS AS UNID_VENDIDAS
FROM 
    LIVROS l
JOIN 
    AUTORES a ON l.CODIGO_AUTOR = a.CODIGO_AUTOR
JOIN 
    EDITORAS e ON l.CODIGO_EDITORA = e.CODIGO_EDITORA
JOIN 
    MaxVendas mv ON l.CODIGO_EDITORA = mv.CODIGO_EDITORA
WHERE 
    l.UNIDADES_VENDIDAS >= 0.7 * mv.Max_Unid_Vendidas
ORDER BY 
    a.NOME, 
    e.NOME;
EXEC SQLCHECK('FGYRVQIHKSBOOLN');


//ex9
select livros.titulo,livros.genero,autores.nome
from livros,autores
where autores.codigo_autor in (
                        select livros.codigo_autor
                        from livros,vendas
                        where vendas.quantidade =(
                                                    select max(vendas.quantidade)
                                                    from vendas
                                                    where to_char(vendas.data_venda,'YYYY')='2022')
                                                    and livros.codigo_livro = vendas.codigo_livro
                                                    and to_char (vendas.data_venda,'YYYY')='2022'
                                                    )
and livros.codigo_autor=autores.codigo_autor
order by nome, titulo;  
EXEC SQLCHECK('FGSZIMRISBUYPFF');


//ex10
select clientes.nome, livros.titulo, sum(vendas.quantidade) as "QUANT_COMPRADA"
from livros, clientes, vendas
where livros.codigo_livro = vendas.codigo_livro
and vendas.codigo_cliente = clientes.codigo_cliente
and vendas.codigo_cliente = (select codigo_cliente
                            from vendas
                            where preco_unitario < 30
                            group by codigo_cliente
                            having sum(vendas.quantidade) = (select max(sum(vendas.quantidade))
                                                        from vendas
                                                        where vendas.preco_unitario < 30
                                                        group by vendas.codigo_cliente))
group by livros.titulo, clientes.nome
order by 1,2;
EXEC SQLCHECK('FGKIKZOJTUGEQTK');
                

//ex11
select a.codigo_autor, a.nome, quantidade, L.TITULO
from autores a, livros l, vendas v
where a.codigo_autor = l.codigo_autor
and l.codigo_livro = v.codigo_livro
and l.codigo_autor in (
    select l.codigo_autor
    from livros l, vendas v,(
    select min(count(v.codigo_venda)) m
    from livros l, vendas v
    where l.codigo_livro = v.codigo_livro
    group by l.codigo_autor
    ) tabl
    where l.codigo_livro = v.codigo_livro
    group by l.codigo_autor, tabl.m
    having count(v.codigo_venda)=tabl.m
    )
    order by 2;
    EXEC SQLCHECK('FGHHHQDKNXLPRFD');