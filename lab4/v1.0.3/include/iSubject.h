#ifndef ISUBJECT
#define ISUBJECT

#include "iObserver.h"

#include <set>

using namespace std;

class ISubject {
    protected:
        set<IObserver*> observers;
    public:
        ISubject();
        virtual ~ISubject() = 0;

        set<IObserver*> getObservers();

        void agregar(IObserver* observer);
        void quitar(IObserver* observer);
        virtual void notificar() = 0;
};

#endif