//ex1
select nome,sal,premios from emp;

//ex2
select *
from emp 
where ndep between 20 and 30;

//ex3
select nome from emp
where funcao='Contabilista' 
and ndep between 10 and 20;

//ex4
select nome,funcao from emp
where nome like '%n%' or nome like '%t%';

//ex5
select nome,funcao from emp
where(nome like 'B%' and nome like '%en%') or (nome like 'M%' and nome like '%ri%');

//ex6
select nome,funcao,(sal + premios) as remuneracao
from emp;

//ex7
select nome,(sal*12*0.15) from emp
where funcao = 'Gestor' and sal<(sal*12*0.15)
order by (sal*12*0.15),nome;


//ex8
select *from emp
where nome like 'Maria';

//ex9
select nome,data_entrada 
from emp
where funcao='Presidente';

//ex10
select nome
from emp
where emp.dep=dep.ndep
and dep.nome='Contabilidade';
