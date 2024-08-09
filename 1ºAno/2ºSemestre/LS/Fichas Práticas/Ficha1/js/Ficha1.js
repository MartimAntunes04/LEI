'use strict'; 
let n1=3;
let n2=6;
let n3;
console.log(n1+n2); // 1)
console.log(n1+"n3"); // 2)
console.log(n1+"5"); // 3)
console.log(n1+"n2"); // 4)
console.log(n1+n3); // 5)
console.log(n3); // 6)
console.log(`Variavel n1*n2 = ${n1*n2} ( n1=${n1} e n2=${n2})`); //7)
n3=n1+n2; 
console.log(n3); //8)
n3=n1+"---"+n2; 
console.log(n3); //9)
n3="6"; 
console.log(n1+n3); // 10
console.log(n2===n3); // 11 True ou False ?
console.log(n2==n3); // 12 True ou False ?
console.log(n2!==n3); // 13 True ou False ?
console.log(n2!=n3); // 14 True ou False ?
console.log(n1++); // 15
console.log('n1='+n1); // 16
n1=4; 
console.log(++n1); // 17
console.log('n1='+n1); // 18

let variavel;
variavel = '3' + 2;
console.log(variavel)
variavel = '3' + true;
console.log(variavel);
variavel = '3' + undefined;
console.log(variavel);
variavel = '3' + null;
console.log(variavel);

let n = 50

if (true) {
console.log(n);
n = 2
console.log(n)
}
console.log(n);

const n6=1
const n7=4
let soma=0


for(let i=n6;i<=n7;i++){
    soma+=i;

}console.log('Soma='+ soma);


let soma1=0,numero,totalnumeros=0;

numero=parseInt(prompt("Numero: "));
do{
if(numero>0){
soma1+=numero;
}
totalnumeros++;
}while(numero!==0)

console.log("Soma: ${soma1}");
console.log("O numero total de numero é ${totalnumeros}");