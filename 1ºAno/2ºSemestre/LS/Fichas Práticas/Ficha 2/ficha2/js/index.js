'use strict';
const panelControl=document.querySelector('#panel-control');
const panelGame= document.querySelector('#game');
const btLevel= document.querySelector('#btLevel');
const message=document.querySelector('#message');
const btPlay=document.querySelector('#btPlay');
const gameStarted=document.querySelectorAll('.list-item')


function reset()
{
    panelGame.style.display='none';
    message.textContent=' ';
    message.classList.remove('hide');
    
    for (let i of gameStarted) {
        i.classList.add('hide');
    }
    if (btLevel.value ='0'){
        btPlay.disabled = true;
    }
    else{
        btPlay.disabled = false;
        panelGame.style.display = 'grid';
    }
}   
reset();   
    
 if(btLevel.value='0')
    btPlay.disabled=true;
 else
    btPlay.disabled=false;

if(btLevel.value='0')
    btPlay.disabled=true;
else
    btPlay.disable=false;
    panelGame.style.display='grid';



btPlay.addEventListener('click',reset);


btPlay.addEventListener('click',function(){
    if(btPlay.textContent='Iniciar Jogo'){
        startGame();
    }

    else if(btPlay.textContent='Terminar Jogo'){
        stopGame();
    }
    });


function startGame()
{
    btPlay.textContent='Terminar jogo';
    btLevel.disabled=true;
    for(let i of gameStarted){
    i.classList.remove('hide');
    }
    message.classList.add('hide');

}


function stopGame()
{
    btPlay.textContent='Iniciar Jogo';
    btLevel.disabled=false;
    reset();
}

panelGame.addEventListener('click',function()
{
    if(message.textContent=' ')
        message.textContent ='Clique em Iniciar Jogo';

    else if(message.textContent='Clique em Iniciar Jogo')
        message.textContent=' ';
});

