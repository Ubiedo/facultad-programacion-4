#ifndef SUBJECT
#define SUBJECT

#include "iObserver.h"

#include <set>
using namespace std;

class Subject {
    protected:
        set<IObserver*> observers;
    public:
        Subject();
        virtual ~Subject() = 0;

        void agregar(IObserver*);
        void quitar(IObserver*);
        void notificar(string);
};

#endif