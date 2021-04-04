#include "locks.h"
#include <QtCore>

Locks::Locks()
{

}

QSemaphore* Locks::sem_abc = new QSemaphore(4);
QSemaphore* Locks::sem_ab = new QSemaphore(3);
QSemaphore* Locks::sem_bc = new QSemaphore(3);
QSemaphore* Locks::sem_a = new QSemaphore(2);
QSemaphore* Locks::sem_b = new QSemaphore(2);
QSemaphore* Locks::sem_c = new QSemaphore(2);
QSemaphore* Locks::sem_0 = new QSemaphore(1);
QSemaphore* Locks::sem_1 = new QSemaphore(1);
QSemaphore* Locks::sem_2 = new QSemaphore(1);
QSemaphore* Locks::sem_3 = new QSemaphore(1);
QSemaphore* Locks::sem_4 = new QSemaphore(1);
QSemaphore* Locks::sem_5 = new QSemaphore(1);
QSemaphore* Locks::sem_6 = new QSemaphore(1);

