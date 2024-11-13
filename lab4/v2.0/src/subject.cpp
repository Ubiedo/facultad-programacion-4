#include "../include/subject.h"

Subject::Subject() {}

Subject::~Subject() {}

void Subject::agregar(IObserver* obs) {
    observers.insert(obs);
}

void Subject::quitar(IObserver* obs) {
    observers.erase(obs);
}

void Subject::notificar(DataNotificacion notificacion){
    set<IObserver*>::iterator itObs;
    for (itObs = observers.begin(); itObs != observers.end(); ++itObs){
        (*itObs)->notificar(notificacion);
    }
}