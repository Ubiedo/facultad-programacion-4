#ifndef ISUBJECT
#define ISUBJECT

#include "iObserver.h"

#include <set>

using namespace std;

class ISubject {
    private:
        map<string, IObserver*> observers;
    public:
        // ISubject();
        virtual ~ISubject() = 0;

        void agregar(IObserver observer);
        void quitar(IObserver observer);
        void notify();
};

#endif