//ex1
select emp.ndep,
dep.nome as "Nome dep",
min(emp.sal) as "Minimo sal",
max(emp.sal) as "Maximo sal",
avg(emp.sal) as "Media sal"
from emp,dep
where emp.ndep=dep.ndep
and dep.nome <> 'Vendas'
and dep.ndep not in(
 select ndep
 from emp
 group by ndep
 having min(sal) < 800
)
group by emp.ndep,dep.nome;


//ex2
select count(*) as "Num_emp"
from emp
where sal > (select AVG(emp.sal)from emp);

//ex3
select emp.ndep,
min(emp.sal) as "Sal min",
max(emp.sal) as "Sal msx",
round(AVG(emp.sal),2) as "Media sal"
from emp,dep
where emp.ndep=dep.ndep
group by emp.ndep;

//ex4
select max(sal) as "Sal mais alto"
from emp;

//ex5
select *
from emp
where sal = (
select max(sal)
from emp
);

//ex6
select e.nome,
e.funcao,
e.sal
from emp e
where e.funcao = 
(select funcao
from emp
where nome = 'Joana Santos');

//ex7
select *
from emp
where (ndep,sal) in (
select ndep,min(sal)
from emp
group by ndep);

//ex8
select *
from emp
where sal > ANY (
select sal
from emp
where ndep=40)
order by sal desc;

//ex9
select *
from emp
where sal > ALL(
select sal
from emp
where ndep=(
select ndep
from dep
where dep.nome = 'Marketing'))
order by sal desc;

//ex10
select dep.nome
from dep,emp
where emp.ndep=dep.ndep
group by emp.nome,dep.nome
having avg(sal) > (
select avg(sal)
from emp
where ndep=40);

//ex12
select *
from emp e1
where e1.sal=(
select AVG(e2.sal)
from emp e2
where e2.funcao=e1.funcao);

//ex13-Errado
SELECT d.nome_dep
FROM Gastos g
JOIN dep d ON g.ndep = d.ndep
WHERE g.gastos_pessoal > (
    SELECT AVG(g2.gastos_pessoal)
    FROM Gastos g2
);

//ex14
select *
from emp e1
where sal > 0.5 * (
select sal
from emp e2
where e2.nemp = e1.encar);

//ex15
select emp.nemp,emp.nome
from emp
where nemp in (
select encar
from emp
group by encar
having count(encar) > 1);

//ex16
SELECT e1.nemp AS encarregado, e1.nome AS nome_encarregado, COUNT(e2.nemp) AS num_empregados
FROM emp e1
JOIN emp e2 ON e1.nemp = e2.encar
GROUP BY e1.nemp, e1.nome
HAVING COUNT(e2.nemp) > 1;
