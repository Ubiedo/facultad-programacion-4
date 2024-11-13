#include "../include/iSubject.h"

ISubject::ISubject() {}

ISubject::~ISubject() {}

set<IObserver*> ISubject::getObservers() {
    return this->observers;
}

void ISubject::agregar(IObserver* observer) {
    this->observers.insert(observer);
}

void ISubject::quitar(IObserver* observer) {
    this->observers.erase(observer);
}