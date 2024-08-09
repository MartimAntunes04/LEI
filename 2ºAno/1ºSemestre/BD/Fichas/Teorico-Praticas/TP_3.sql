//ex1
select *
from emp
where sal > 2000;

//ex2
select nome, nemp
from emp
where encar = encar;

//ex3
select emp.nome,emp.funcao,dep.nome
from emp, dep
where emp.ndep = dep.ndep
order by dep.nome asc, emp.nome desc;   


//ex4
select nome,sal,ndep
from emp
where nome like 'C%' 
and SUBSTR(nome, INSTR(nome, ' ', -1) + 1) like 'M%'
and sal < 1000;


//ex5
select emp.nome,emp.data_entrada,dep.nome,dep.loc
from emp,dep
where emp.ndep = dep.ndep
and emp.sal > 1500;

//ex6
select distinct descontos.escalao, emp.funcao
from descontos,emp
order by descontos.escalao, emp.funcao;

//ex7
select emp.nome,emp.funcao,emp.sal,descontos.salinf,descontos.salsup
from emp,descontos
where descontos.escalao = '4' or descontos.escalao = '5'
order by emp.nome;

//ex8
select emp.nome,emp.funcao,emp.sal,descontos.salinf,descontos.salsup,dep.nome
from emp,descontos,dep
where descontos.escalao = '4' or descontos.escalao = '5'
order by emp.nome;

//ex9
select emp.nome,emp.funcao,emp.sal,dep.loc
from emp, dep
where emp.ndep = dep.ndep and dep.loc like '%Coimbra%' or dep.loc like '%Porto%'
and sal > 5000; 

//ex10
select emp.nome,emp.funcao,descontos.escalao,dep.nome
from emp,dep,descontos
where emp.ndep = dep.ndep
and  emp.funcao not in ('VENDEDOR', 'GESTOR')
order by descontos.escalao desc;


//ex11
select emp.nome,emp.funcao,dep.nome
from emp,dep
where emp.ndep = dep.ndep
order by dep.nome , emp.nome desc;
