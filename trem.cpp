#include "trem.h"
#include "locks.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = 100;
    this->parado = true;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        if (!parado) {
            switch(ID){
            case 1:     //Trem 1
                if (x == 310 && y == 30) {
                    if (Locks::sem_abc->available() > 0 && Locks::sem_ab->available() > 0 && Locks::sem_a->available() > 0) {
                        Locks::sem_abc->acquire(1);
                        Locks::sem_ab->acquire(1);
                        Locks::sem_a->acquire(1);
                        Locks::mutex[0].lock();
                        x+=10;
                    }
                } else if(x == 330 && y == 130) {
                    Locks::mutex[2].lock();
                    y+=10;
                } else if(x == 310 && y == 150) {
                    Locks::mutex[0].unlock();
                    x-=10;
                } else if (x == 180 && y == 150) {
                    Locks::mutex[2].unlock();
                    if (Locks::sem_a->available() < 2)
                        Locks::sem_a->release(1);
                    if (Locks::sem_ab->available() < 3)
                        Locks::sem_ab->release(1);
                    if (Locks::sem_abc->available() < 4)
                        Locks::sem_abc->release(1);
                    x-=10;
                } else if (y == 30 && x < 330) {
                    x+=10;
                } else if (x == 330 && y < 150) {
                    y+=10;
                } else if (x > 60 && y == 150) {
                    x-=10;
                } else {
                    y-=10;
                }
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 2:     //Trem 2
                if (x == 580 && y == 30) {
                    if (Locks::sem_abc->available() > 0 && Locks::sem_bc->available() > 0 && Locks::sem_c->available() > 0) {
                        Locks::sem_abc->acquire(1);
                        Locks::sem_bc->acquire(1);
                        Locks::sem_c->acquire(1);
                        Locks::mutex[1].lock();
                        x+=10;
                    }
                } else if (x == 600 && y == 130) {
                    if (Locks::sem_ab->available() > 0 && Locks::sem_b->available() > 0) {
                        Locks::sem_ab->acquire(1);
                        Locks::sem_b->acquire(1);
                        Locks::mutex[4].lock();
                        y+=10;
                    }
                } else if (x == 580 && y == 150) {
                    Locks::mutex[1].unlock();
                    x-=10;
                } else if (x == 490 && y == 150) {
                    if (Locks::sem_a->available() > 0) {
                        Locks::sem_a->acquire(1);
                        Locks::mutex[3].lock();
                        x-=10;
                    }
                } else if (x == 450 && y == 150) {
                    Locks::mutex[4].unlock();
                    if (Locks::sem_c->available() < 2)
                        Locks::sem_c->release(1);
                    x-=10;
                } else if (x == 350 && y == 150) {
                    Locks::mutex[0].lock();
                    x-=10;
                } else if (x == 330 && y == 130) {
                    Locks::mutex[3].unlock();
                    if (Locks::sem_b->available() < 2)
                        Locks::sem_b->release(1);
                    if (Locks::sem_bc->available() < 3)
                        Locks::sem_bc->release(1);
                    y-=10;
                } else if (x == 350 && y == 30) {
                    Locks::mutex[0].unlock();
                    if (Locks::sem_a->available() < 2)
                        Locks::sem_a->release(1);
                    if (Locks::sem_ab->available() < 3)
                        Locks::sem_ab->release(1);
                    if (Locks::sem_abc->available() < 4)
                        Locks::sem_abc->release(1);
                    x+=10;
                } else if (y == 30 && x < 600) {
                    x+=10;
                } else if (x == 600 && y < 150) {
                    y+=10;
                } else if (x > 330 && y == 150) {
                    x-=10;
                } else {
                    y-=10;
                }
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 3:
                if (x == 760 && y == 150) {
                    if (Locks::sem_abc->available() > 0 && Locks::sem_bc->available() > 0 && Locks::sem_c->available() > 0) {
                        Locks::sem_abc->acquire(1);
                        Locks::sem_bc->acquire(1);
                        Locks::sem_c->acquire(1);
                        Locks::mutex[5].lock();
                        x-=10;
                    }
                } else if (x == 620 && y == 150) {
                    Locks::mutex[1].lock();
                    x-=10;
                } else if (x == 600 && y == 130) {
                    Locks::mutex[5].unlock();
                    y-=10;
                } else if (x == 620 && y == 30) {
                    Locks::mutex[1].unlock();
                    if (Locks::sem_c->available() < 2)
                        Locks::sem_c->release(1);
                    if (Locks::sem_bc->available() < 3)
                        Locks::sem_bc->release(1);
                    if (Locks::sem_abc->available() < 4)
                        Locks::sem_abc->release(1);
                    x+=10;
                } else if (y == 30 && x < 870) {
                    x+=10;
                } else if (x == 870 && y < 150) {
                    y+=10;
                } else if (x > 600 && y == 150) {
                    x-=10;
                } else {
                    y-=10;
                }
                emit updateGUI(ID, x,y);
                break;
            case 4:
                if (x == 490 && y == 280) {
                    if (Locks::sem_abc->available() > 0 && Locks::sem_bc->available() > 0 && Locks::sem_ab->available() > 0 && Locks::sem_b->available() > 0) {
                        Locks::sem_abc->acquire(1);
                        Locks::sem_bc->acquire(1);
                        Locks::sem_ab->acquire(1);
                        Locks::sem_b->acquire(1);
                        Locks::mutex[6].lock();
                        x-=10;
                    }
                } else if (x == 470 && y == 170) {
                    if (Locks::sem_c->available() > 0) {
                        Locks::sem_c->acquire(1);
                        Locks::mutex[4].lock();
                        y-=10;
                    }
                } else if (x == 490 && y == 150) {
                    Locks::mutex[6].unlock();
                    x+=10;
                } else if (x == 580 && y == 150) {
                    Locks::mutex[5].lock();
                    x+=10;
                } else if (x == 620 && y == 150) {
                    Locks::mutex[4].unlock();
                    if (Locks::sem_b->available() < 2)
                        Locks::sem_b->release(1);
                    if (Locks::sem_ab->available() < 3)
                        Locks::sem_ab->release(1);
                    x+=10;
                } else if (x == 740 && y == 170) {
                    Locks::mutex[5].unlock();
                    if (Locks::sem_c->available() < 2)
                        Locks::sem_c->release(1);
                    if (Locks::sem_bc->available() < 3)
                        Locks::sem_bc->release(1);
                    if (Locks::sem_abc->available() < 4)
                        Locks::sem_abc->release(1);
                    y+=10;
                } else if (y == 280 && x > 470) {
                    x-=10;
                } else if (x == 470 && y > 150) {
                    y-=10;
                } else if (y == 150 && x < 740) {
                    x+=10;
                } else {
                    y+=10;
                }
                emit updateGUI(ID, x,y);
                break;
            case 5:
                if (x == 200 && y == 170) {
                    if (Locks::sem_abc->available() > 0 && Locks::sem_ab->available() > 0 && Locks::sem_a->available() > 0) {
                        Locks::sem_abc->acquire(1);
                        Locks::sem_ab->acquire(1);
                        Locks::sem_a->acquire(1);
                        Locks::mutex[2].lock();
                        y-=10;
                    }
                } else if (x == 310 && y == 150) {
                    if (Locks::sem_bc->available() > 0 && Locks::sem_b->available() > 0) {
                        Locks::sem_bc->acquire(1);
                        Locks::sem_b->acquire(1);
                        Locks::mutex[3].lock();
                        x+=10;
                    }
                } else if (x == 350 && y == 150) {
                    Locks::mutex[2].unlock();
                    x+=10;
                } else if (x == 450 && y == 150) {
                    Locks::mutex[6].lock();
                    x+=10;
                } else if (x == 470 && y == 170) {
                    Locks::mutex[3].unlock();
                    if (Locks::sem_a->available() < 2)
                        Locks::sem_a->release(1);
                    y+=10;
                } else if (x == 450 && y == 280) {
                    Locks::mutex[6].unlock();
                    if (Locks::sem_b->available() < 2)
                        Locks::sem_b->release(1);
                    if (Locks::sem_ab->available() < 3)
                        Locks::sem_ab->release(1);
                    if (Locks::sem_bc->available() < 3)
                        Locks::sem_bc->release(1);
                    if (Locks::sem_abc->available() < 4)
                        Locks::sem_abc->release(1);
                    x-=10;
                } else if (y == 280 && x > 200) {
                    x-=10;
                } else if (x == 200 && y > 150) {
                    y-=10;
                } else if (y == 150 && x < 470) {
                    x+=10;
                } else {
                    y+=10;
                }
                emit updateGUI(ID, x,y);
                break;
            default:
                break;
            }
            if (velocidade == 200) {
                parado = true;
            }
            msleep(velocidade);
        } else {
            if (velocidade != 200)
                parado = false;
        }
    }
}

void Trem::set_velocidade(int valor_slider){
    int velocidade = 200 - valor_slider;
    this->velocidade = velocidade;
}


