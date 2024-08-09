import React, { useEffect } from "react";
import { useState } from "react";
import "./game-panel.css";
import { Card } from "../index";
import  {checkIfIsFlipped}  from "../../helpers";
import {checkIfIsMatched} from "../../helpers";



function GamePanel({cards,selectedLevel,gamestart}) {

  let gameClass="";
  if(selectedLevel==="2") gameClass="Intermedio";
  if(selectedLevel==="3") gameClass="Avancado";
  const [flippedCards,setFlippedCards]=useState([]);
  const [matchedCards,setMatchedCards]=useState([]);

  const handleClickCard=(card) =>{
      setFlippedCards((previousState)=>[...previousState,card])

  }

  const processMatchingCards = () => {
    const [card1, card2] = flippedCards;
    const cardsAreEqual = card1.name === card2.name;
    if (cardsAreEqual) {
    setTimeout(() => {
    setMatchedCards((previousState) =>
    [...previousState, ...flippedCards]);
    setFlippedCards([]);
    }, 500);
    } else {
    setTimeout(() => {
    setFlippedCards([]);
    }, 500);
    }
    };

    useEffect(()=>{
      if(gamestart){
        setFlippedCards([]);
        setMatchedCards=([]);
      }
    },[gamestart]);

    useEffect(()=>{
      if(matchedCards.length===cards.length){
          gamestart(false);
      }
    },[matchedCards,cards]);


    useEffect(()=>{
      if(gamestart && flippedCards.length===2)
      processMatchingCards();
    },gamestart,flippedCards,processMatchingCards);

    useEffect(()=>{
      setMatchedCards([]);
    },[]);

    
  return (  
    <section className="game-panel">
      <h3 className="sr-only">Peças do Jogo</h3>
      <div id="game" className={gameClass}>
        
        {cards.map((card)=>(
          <Card key={card.key} 
          card={card} 
          onClickCard={handleClickCard}
          flippedCards={checkIfIsFlipped(matchedCards,flippedCards,card.id)}
          matchedCards={checkIfIsMatched(matchedCards,card.id)}

          
          />
        ))}
      </div>
    </section>
  );
}
export default GamePanel;
