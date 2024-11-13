#ifndef FACTORY
#define FACTORY

#include "iUsuarios.h"
#include "ctrlUsuarios.h"

#include "iPromoProd.h"
#include "ctrlPromoProd.h"

#include "iSuscNotif.h"
#include "ctrlSuscNotif.h"

class Factory {
    private:
        static Factory* instancia;
        Factory();
    public:
        ~Factory();
        static Factory* getInstancia();
        IUsuarios* getIUsuarios();
        IPromoProd* getIPromoProd();
        IPromoProd* getIPromoProd();
        ISuscNotif* getISuscNotif();
};

#endif