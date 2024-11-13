#ifndef IOBSERVER
#define IOBSERVER

#include "producto.h"
#include <set>

using namespace std;

class IObserver {
    public:
        IObserver();
        virtual ~IObserver() = 0;

        virtual void notificar() = 0;
};

#endif