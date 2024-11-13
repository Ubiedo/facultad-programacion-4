#ifndef FACTORY
#define FACTORY

#include "iUsuarios.h"
#include "iPromoProd.h"
#include "ctrlUsuarios.h"
#include "ctrlPromoProd.h"

class Factory {
    private:
        static Factory* instancia;
        Factory();
    public:
        ~Factory();
        static Factory* getInstancia();
        IUsuarios* getIUsuarios();
        IPromoProd* getIPromoProd();
};

#endif