//ex1

select max(sal) as "Salario mais alto",
min(sal) as "Salario mais baixo",
ROUND(avg(sal),1) as "Salario Medio",
ROUND(AVG(sal) - MIN(sal),1) AS "Salmedio  e Baixo",
ROUND(AVG(sal) - MAX(sal),1) AS "SalMédio e Alto"
from emp;

//ex2
select dep.nome as "Nome Departamento",
ROUND(max(emp.sal)-min(emp.sal),1) as "Diferenca_sal"
from emp,dep
where emp.ndep=dep.ndep
group by dep.nome
order by "Diferenca_sal" desc;

//ex3
select funcao,
COUNT(nemp)as "Numero empregados",
min(sal) as "Salario Mais Baixo",
max(sal) as "Salario Mais Alto"
from emp
group by funcao
order by funcao;

//ex4
select funcao,
COUNT(nemp)as "Numero empregados",
min(sal) as "Salario Mais Baixo",
max(sal) as "Salario Mais Alto"
from emp
where funcao = 'ANALISTA' and nome like '%a'
group by funcao
order by funcao;

//ex5
select emp.encar as "Encarregado",
min(emp.sal) as "Salario Mais Baixo",
max(emp.sal) as "Salario Mais Alto"
from emp,descontos
where emp.sal>=descontos.salinf and emp.sal <= descontos.salsup
group by emp.encar
having min(sal)>=900
order by 2;

//ex6
select funcao,
Ceil(avg(sal)) as "Salario Medio"
from emp
group by funcao
having count(nemp)>2;

//ex7
select dep.nome as "Departamento",
emp.funcao,
max(emp.sal) as "Salario maximo",
min(emp.sal) as "Salario minimo",
avg(sal) as "Salario Medio",
COUNT(*) as "Quantidade Empregados"
from emp,dep
where emp.ndep=dep.ndep
and not emp.nome like 'António Casta'
group by dep.nome,emp.funcao
having max(sal) >1000
order by dep.nome,max(sal);

//ex8
select COUNT(nemp) as "TotalEmpregados",
COUNT (nemp) as "Empregado Vendas"
from emp
where ndep = (select ndep
              from dep
               where nome = 'Vendas');
               
//ex9
select ceil(avg(sal)) as "Salario Medio",
COUNT (*) as "Numero Trabalhadores"
from emp;

//ex10
select max(sal) as "Salario Maximo" 
from emp
where not funcao = 'Presidente';

//ex11
select ceil(avg(sal)) as "Salario Medio",
dep.nome
from emp,dep
where dep.nome = 'Marketing' or dep.nome = 'Publicidade'
group by dep.nome;

//ex12
select dep.nome as "Nome Departamento",
COUNT (emp.nemp) as "Numero Empregados"
from emp,dep
where emp.ndep=emp.ndep
group by dep.nome;

//ex13
select dep.nome as "Nome Departamento",
sum(emp.sal) as "Gasto Salarios",
sum(emp.sal + emp.premios) as "Gasto Remuneracoes"
from emp,dep
where emp.ndep= dep.ndep
group by dep.nome;

//ex14
select dep.nome as "Nome Departamento",
sum(emp.sal) as "Gasto Salarios"
from emp,dep
where emp.ndep = dep.ndep
group by dep.nome
having sum(emp.sal)=(select min(emp.sal)
                        from emp)
group by dep.nome
order by sum(emp.sal);

 
//ex15
select nome as "Nome Empregado"
from emp
where data_entrada = (select min(data_entrada)
                        from emp);


