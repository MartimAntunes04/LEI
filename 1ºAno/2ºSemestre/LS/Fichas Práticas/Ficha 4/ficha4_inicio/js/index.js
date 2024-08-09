'use strict';
const panelControl = document.querySelector('#panel-control');
const panelGame = document.querySelector('#game');
const btLevel = document.querySelector('#btLevel');
const btPlay = document.querySelector('#btPlay');

let cardsLogos = ['angular', 'bootstrap', 'html', 'javascript', 'vue', 'svelte', 'react', 'css', 'backbone', 'ember'];
let cards = document.querySelectorAll('.card');

let flippedCards=[];
let totalFlippedCards;


// ------------------------
// Funções Genéricas
// ------------------------
// Algoritmo Fisher-Yates -  Algoritmo que baralha um array.
const shuffleArray = array => {
     for (let i = array.length - 1; i > 0; i--) {
          const j = Math.floor(Math.random() * (i + 1));
          const temp = array[i];
          array[i] = array[j];
          array[j] = temp;
     }
}

function reset() {
     btLevel.disabled = true;
     btLevel.value = 1;
     btPlay.disabled = false;

     panelGame.style.display = "none";
     message.textContent = '';
     message.classList.remove('hide');
     panelGame.style.display = 'grid';

     const elementos = panelControl.querySelectorAll('.list-item');
     elementos.forEach(elemento => {
          elemento.classList.remove('gameStarted');
     });
}

function showCards(){
     for(let card of cards){
          card.classList.add('flipped');
     }
}

function hideCards(){
     for(let card of cards){
          card.classList.remove('flipped');
     }
}

function flipCard(selectedCard) {
     selectedCard.classList.add('flipped');
     flippedCards.push(selectedCard)
     if(flippedCards.length===2)
          checkPair();

}

function checkPair(){
     let [card1,card2]= flippedCards;
     const isMatch=(card1.dataset.logo===card2.dataset.logo)
     if(isMatch){
          console.log('Iguais');
          card1.classList.add('inative');
          card2.classList.add('inative');
          card1.querySelector(".card-front").classList.add('grayscale');
          card2.querySelector(".card-front").classList.add('grayscale');
          totalFlippedCards+=2;
          if(gameOver(totalFlippedCards,totalCards)){
               stopGame()
          }
     }
     else{
          console.log('Não são iguais');
          setTimeout(() => {
          
          card1.classList.remove('flipped');
          card2.classList.remove('flipped');
          card1.addEventListener('click', function () {
               flipCard(this);
               });
          card2.addEventListener('click', function () {
               flipCard(this);
               });
                    
               
          
     }, 500);
     }
     flippedCards=[];
}

function gameOver(totalFlippedCards, totalCards) {
     return totalFlippedCards === totalCards;
   }



function startGame() {
     btLevel.disabled = true;
     btPlay.textContent = 'Terminar Jogo';
     const elementos = panelControl.querySelectorAll('.list-item');
     elementos.forEach(elemento => {
          elemento.classList.add('gameStarted')
     });
     message.classList.add('hide');

     shuffleArray(cardsLogos);
     let [indice, newCardLogos] = [0, cardsLogos.slice(0, cards.length / 2)];
     newCardLogos = [...newCardLogos, ...newCardLogos];
     shuffleArray(newCardLogos)

     for (let card of cards) {
          card.querySelector('.card-front').src = `images/${newCardLogos[indice]}.png`;
          card.dataset.logo = newCardLogos[indice++];
          function funcClickCard(e) {
               flipCard(this);
               }
               card.addEventListener('click', funcClickCard, { once: true });
          }
          totalFlippedCards=0;
     
}

function stopGame() {
     btPlay.textContent = 'Iniciar Jogo'
     reset();
     hideCards();
     modalGameOver.style.display = 'block';
     cards.forEach(card => {
          card.classList.remove('flipped', 'inactive', 'grayscale');
          card.removeEventListener('click', flipCard);
          
     });
     modalGameOver.style.display = 'block'
     
}

// ------------------------
// Event Listeners
// ------------------------

btPlay.addEventListener('click', function () {
     if (btPlay.textContent === 'Terminar Jogo')
          stopGame()
     else startGame();
});

panelGame.addEventListener('click', () =>
     message.textContent === '' ? message.textContent = 'Clique em Iniciar o Jogo!' : message.textContent = ''
);

reset();
