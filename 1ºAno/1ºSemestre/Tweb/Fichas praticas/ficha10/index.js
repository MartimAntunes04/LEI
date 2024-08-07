/**************************************************
 * Javascript - Ficha 10
 * ************************************************/

//exc2

const BUTTON_TITULO= document. querySelector("#btn-titulo");
const TITLE= document.querySelector(".title");

if(BUTTON_TITULO && TITLE){
    BUTTON_TITULO.addEventListener("click",function(){
       
        TITLE.textContent = "Tecnologias Web-JavaScript";
    });
}

//exc3

const BUTTON_TOGGLE_BORDER=document.querySelector(".btn-border");
const PANEL_ANIMALS=document.querySelector(".panel-animals");
const PANEL_STYLES={
    borderClass: "border-active",
    backgroundAsHex: "#FF000022",
};

if (BUTTON_TOOGLE_BORDER && PANEL_ANIMALS){
    BUTTON_TOGGLE_BORDER.addEventListener("click",function(){
        const HAS_CLASS= PANEL_ANIMALS.classList.contains(PANEL_STYLES.borderClass);
        const HAS_BACKGROUND=PANEL_ANIMALS.style.backgroundcolor - PANEL_STYLES.backgroundAsHex;
    
    });
}