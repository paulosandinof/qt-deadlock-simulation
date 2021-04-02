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
    static QMutex *mutex;
    Locks();
};

#endif // LOCK_H
