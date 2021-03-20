#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 30 && x < 330)
                x+=10;
            else if (x == 330 && y < 150)
                y+=10;
            else if (x > 60 && y == 150)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (y == 30 && x <600)
                x+=10;
            else if (x == 600 && y < 150)
                y+=10;
            else if (x > 330 && y == 150)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3:
            if (y == 30 && x < 870)
                x+=10;
            else if (x == 870 && y < 150)
                y+=10;
            else if (x > 600 && y == 150)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);
            break;
        case 4:
            if (y == 280 && x > 470)
                x-=10;
            else if (x == 470 && y > 150)
                y-=10;
            else if (y == 150 && x < 740)
                x+=10;
            else
                y+=10;
            emit updateGUI(ID, x,y);
            break;
        case 5:
            if (y == 280 && x > 200)
                x-=10;
            else if (x == 200 && y > 150)
                y-=10;
            else if (y == 150 && x < 470)
                x+=10;
            else
                y+=10;
            emit updateGUI(ID, x,y);
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

int Trem::get_velocidade(){
    return this->velocidade;
}

void Trem::set_velocidade(int valor_slider){
    int velocidade = 200 - valor_slider;
    this->velocidade = velocidade;
}


