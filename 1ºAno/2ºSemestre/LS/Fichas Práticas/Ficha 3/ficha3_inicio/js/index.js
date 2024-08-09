'use strict';
const panelControl = document.querySelector('#panel-control');
const panelGame = document.querySelector('#game');
const btLevel = document.querySelector('#btLevel');
const btPlay = document.querySelector('#btPlay');

let cardsLogos=['angular', 'bootstrap','html','javascript','vue','svelte','react','css','backbone','ember'];
let card=document.querySelectorAll('.card');
let NewcardsLogo=['angular','bootstrap','html'];
// ------------------------
// Funções Genéricas
// ------------------------
// Algoritmo Fisher-Yates - Algoritmo que baralha um array.
const shuffleArray = array => { 
     for (let i = array.length - 1; i > 0; i--) { 
     const j = Math.floor(Math.random() * (i + 1)); 
     const temp = array[i]; 
     array[i] = array[j]; 
     array[j] = temp; 
     } 
    }

function showCards(){
     for(let item of card)
     item.classList.add('flipped');
}

function hideCards(){
     for(let item of card)
     item.classList.remove('flipped');
}


function reset() {

     message.classList.remove('hide');
     if (btLevel.value === '0')
          btPlay.disabled = true
     else {
          btPlay.disabled = false;
          panelGame.style.display = 'grid';
     }
     const elementos = panelControl.querySelectorAll('.list-item');
     elementos.forEach(elemento => {
          elemento.classList.remove('gameStarted');
     });
}

function startGame() {
     message.classList.add('hide');
     btLevel.disabled = true;
     btPlay.textContent = 'Terminar Jogo';
     const elementos = panelControl.querySelectorAll('.list-item');
     elementos.forEach(elemento => {
          elemento.classList.add('gameStarted')
     });
     console.table(cardsLogos);
     shuffleArray(cardsLogos);
     console.table(cardsLogos);
     showCards();
     
     //Alterar as imagens
     let i=0;
     for(let item of card){
          item.dataset.logo=cardsLogos[i];
          item.querySelector('.card-front').src='images/'+cardsLogos[i]+'.png'
          i++;
     }
     showCards();

     card.forEach((item, i) => {
          item.dataset.logo = cardsLogos[i];
          item.querySelector('.card-front').src = 'images/' + cardsLogos[i] + '.png';
        });
     showCards();

     
     

}
function stopGame() {
     btPlay.textContent = 'Iniciar Jogo'
     btLevel.disabled = false;
     reset();
     hideCards();
}

// ------------------------
// Event Listeners
// ------------------------
btLevel.addEventListener('change', reset);
btPlay.addEventListener('click', () => (btPlay.textContent == 'Terminar Jogo') ? stopGame() : startGame());


reset();


