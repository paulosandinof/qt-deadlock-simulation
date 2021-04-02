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
QMutex* Locks::mutex = new QMutex[7]();
