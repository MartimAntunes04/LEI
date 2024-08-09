//ex1
SELECT nome AS "Subordinados"
FROM emp
WHERE encar <> 0
UNION
SELECT nome AS "Encarregados"
FROM emp
WHERE nemp IN (SELECT DISTINCT encar FROM emp);


//ex2
select ndep,nome
from dep
MINUS
select dep.ndep,dep.nome
from emp,dep
where emp.ndep = dep.ndep;


//ex3
select UPPER(emp.nome),LOWER(emp.funcao),INITCAP(dep.nome)
from emp,dep
where emp.funcao = 'GESTOR'
order by dep.nome, emp.nome;

//ex4
select COUNT (*) as "Numero de empregados"
from emp
where sal > 900;

//ex5
select COUNT (*) as " sem premio"
from emp    
where premios is NULL;

//ex6
select COUNT(*) as "Numero empreados",
AVG(sal) as "Salario Medio Mensal", 
SUM(sal*12) as "Total da Remuneracao Anual"
from emp
where sal >= 800;

//ex7
select funcao, 
sal as "Salario Mensal",
ROUND(sal+(sal*0.015),2) as "Salario Menssal Aumentado"
from emp
where funcao = 'GESTOR';

//ex8
    select funcao, 
    sal as "Salario Mensal",
    ROUND(sal+(sal*0.015),0) as "Salario Menssal Aumentado"
    from emp
    where funcao = 'GESTOR';