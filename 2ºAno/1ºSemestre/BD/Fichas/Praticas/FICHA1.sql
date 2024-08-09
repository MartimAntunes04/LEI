--Ficha1
exec naluno (2022141890)
select *from autores;
select titulo from livros order by titulo asc;
exec sqlcheck ('FAJOFSKBMIUXCEZ');
select distinct genero from livros order by genero asc;
exec sqlcheck ('FAEHGSQCELEEDMQ');
select titulo,genero,preco_tabela as PRECO from livros where preco_tabela between 30 and 40 order by preco_tabela;
exec sqlcheck ('FAZPHKCDDOXSEUK');
