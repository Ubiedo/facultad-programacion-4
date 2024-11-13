#ifndef IOBSERVER
#define IOBSERVER

#include "dataNotificacion.h"

class IObserver {
    public:
        IObserver();
        virtual ~IObserver() = 0;

        virtual void notificar(DataNotificacion) = 0;
};

#endif