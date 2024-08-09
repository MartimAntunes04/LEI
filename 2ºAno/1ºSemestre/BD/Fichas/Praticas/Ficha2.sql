//Ficha2

exec naluno (2022141890)
//ex3
select distinct titulo,genero,preco_tabela from livros 
where (genero='Policial' or genero='Aventura') 
and preco_tabela> 20 
order by titulo;
EXEC SQLCHECK('FBZFTYYCWMJOENW')

//ex4
select distinct nome,sexo from autores
where idade>30 and genero_preferido='Romance'
order by nome asc;
EXEC SQLCHECK('FBHYDWADZAUJFAT');

//ex5
select distinct genero from livros
where (paginas>400 or preco_tabela>25) order by genero;
EXEC SQLCHECK('FBJQNSWEVIFUGWV');

//ex6
select distinct titulo,preco_tabela as preco from livros
where genero='Informática'
order by preco_tabela;
EXEC SQLCHECK('FBHOWKTFDMPWHAI');

//ex7
select titulo,ISBN,Quant_EM_Stock from livros
where (genero='Informática' and quant_em_stock > 10)
order by preco_tabela asc;
EXEC SQLCHECK('FBLPCFWGZYXCITX');

//ex8
select distinct autores.codigo_autor from autores,livros
where livros.codigo_autor=autores.codigo_autor
order by autores.codigo_autor desc;
EXEC SQLCHECK('FBCLDRYHKXKMJXJ');

//ex9
select titulo from livros
where genero <> 'Aventura';
EXEC SQLCHECK('FBELDMQIWUXFKNT');

//ex10
select titulo,preco_tabela from livros
where not genero= 'Aventura';
EXEC SQLCHECK('FBIZEEEJGLOKLVI');

//ex11
select nome,sexo from autores
where idade>30 and genero_preferido='Romance'
order by nome asc;
EXEC SQLCHECK('FBTNEIDKPDPIMYQ');

//ex12
select nome,idade from autores
where nome like '%o%' and nome like '%u%'
order by idade;
EXEC SQLCHECK('FBCVUBULKHUONEV');

//ex13
select titulo,genero from livros
where titulo like '%O%' and titulo like '%st%' or titulo like '%W%' and titulo like '%NT%'
order by preco_tabela;
EXEC SQLCHECK('FBLTKPUMCPJWOJT');

//ex14
select titulo,genero,preco_tabela from livros
where genero='Policial' or genero='Romance' or genero='Economia'
order by titulo;
EXEC SQLCHECK('FBWUSOSNTSQGPPG');

//ex15
select titulo,paginas as "Num de Paginas" from livros
where genero='Romance' and paginas<520
order by paginas;
EXEC SQLCHECK('FBHNFMWOMZTHQNJ');

//ex16
select codigo_livro,titulo,preco_tabela,quant_em_stock as "Quantidade em stock" from livros
where genero='Policial'
order by quant_em_stock;
EXEC SQLCHECK('FBONDSEPBRRKRIO');

//ex17
select 'O livro "'|| titulo ||'" tem '|| paginas ||' paginas.'  as "Listagem paginas dos Livros" from livros 
where genero='Aventura'
order by titulo;
EXEC SQLCHECK('FBTFIETQMZONSSJ');