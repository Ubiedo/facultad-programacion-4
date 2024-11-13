#ifndef IOBSERVER
#define IOBSERVER

#include <string>
using namespace std;

class IObserver {
    public:
        IObserver();
        virtual ~IObserver() = 0;

        virtual void notificar(string) = 0;
};

#endif