#ifndef LOCK_H
#define LOCK_H

#include <QSemaphore>
#include <QMutex>

class Locks
{
public:
    static QSemaphore *sem_abc;
    static QSemaphore *sem_ab;
    static QSemaphore *sem_bc;
    static QSemaphore *sem_a;
    static QSemaphore *sem_b;
    static QSemaphore *sem_c;
    static QSemaphore *sem_0;
    static QSemaphore *sem_1;
    static QSemaphore *sem_2;
    static QSemaphore *sem_3;
    static QSemaphore *sem_4;
    static QSemaphore *sem_5;
    static QSemaphore *sem_6;
    Locks();
};

#endif // LOCK_H
