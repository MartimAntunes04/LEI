//Ficha6

//ex3
select titulo,
MIN(preco_tabela) as "Preco_Mais_Baixo"
from livros
where genero = 'Fantástico' 
and preco_tabela = (select min(preco_tabela)
                  from livros
                  where genero='Fantástico')
group by titulo;
EXEC SQLCHECK('FFKMXQQCCWIZINA');


//ex4
select titulo,
paginas as "N_Paginas",
MIN(preco_tabela) as "Preco_mais_Baixo"
from livros
where genero = 'Fantástico'
and preco_tabela =  ALL(select min(preco_tabela)
                        from livros
                        where genero = 'Fantástico')
group by paginas,titulo;
EXEC SQLCHECK('FFDJTIRDJJNSJGQ');

//ex5
select MIN(preco_tabela) as "Preco_Mais_Baixo",
titulo
from livros l1
where genero = 'Fantástico'
and  NOT EXISTS           (select preco_tabela
                          from livros l2
                            where l1.preco_tabela > l2.preco_tabela
                            and genero ='Fantástico')
group by titulo;
EXEC SQLCHECK('FFZMRWEEXQNJKIQ');

//ex6
select titulo as "Livro Mais Barato"
from livros l, (select min(preco_tabela) as Preco_tabela
                from livros
                where genero = 'Fantástico')Min
where l.preco_tabela = min.preco_tabela;
EXEC SQLCHECK('FFOIHIAFORVLLSJ');


//ex7
select distinct nome
from autores,livros
where autores.codigo_autor = livros.codigo_autor
and livros.paginas > (select AVG(paginas)
                      from livros)
                      order by autores.nome;
EXEC SQLCHECK('FFBKSPCGAZHRMTE');

//ex8
select autores.nome,autores.idade,autores.nacionalidade
from autores,livros
where autores.codigo_autor = livros.codigo_autor
group by autores.nome,autores.idade,autores.nacionalidade
having count(livros.codigo_livro)>(select AVG(COUNT(livros.codigo_livro))
                            from livros,autores
                            where autores.codigo_autor=livros.codigo_autor
                            group by nome);
EXEC SQLCHECK('FFIIHBGHVJSENIL');


//ex9
select livros.codigo_autor,
livros.titulo,
livros.preco_tabela as "PRECO",
aa.pt as "PRECO_MINIMO",
livros.preco_tabela - aa.pt as "DIFERENCA_PRECO"
from livros,   (select livros.codigo_autor,min(livros.preco_tabela) pt 
                from livros
                group by livros.codigo_autor) aa
where genero = 'Fantástico'
and livros.codigo_autor = aa.codigo_autor
order by livros.codigo_autor,livros.preco_tabela;
EXEC SQLCHECK('FFHAWDXINTAMOTO');


//ex10
select genero,titulo,unidades_vendidas
from livros
where (genero,unidades_vendidas)
IN (select genero, min(unidades_vendidas)
    from livros
    group by genero)
order by unidades_vendidas desc, genero;
EXEC SQLCHECK('FFEFGOFJFOVYPMP');

//ex11
select livros.titulo,
to_char(round(100*livros.unidades_vendidas/B.Soma,1),'990.99') as "PERCENTAGEM"
from livros,editoras , (select sum (livros.unidades_vendidas) as "SOMA"
                        from livros,editoras
                        where livros.codigo_editora = editoras.codigo_editora
                        and  editoras.nome like '%Gradiva%') B
where livros.codigo_editora = editoras.codigo_editora
and editoras.nome like '%Gradiva%'
order by PERCENTAGEM DESC,livros.titulo;
EXEC SQLCHECK('FFUSZQRKODGHQZN');

//ex12
select titulo,genero
from livros,clientes,vendas
where livros.codigo_livro=vendas.codigo_livro
and vendas.codigo_cliente = clientes.codigo_cliente
and clientes.morada like '%Lisboa%'
and vendas.quantidade = (select max(quantidade)
                        from clientes,vendas
                        where vendas.codigo_cliente = clientes.codigo_cliente
                        and clientes.morada like '%Lisboa%');
EXEC SQLCHECK('FFEATZOLGSNMRRV');