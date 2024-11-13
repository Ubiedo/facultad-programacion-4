#ifndef FECHASISTEMA
#define FECHASISTEMA

#include "dataFecha.h"

class FechaSistema {
    private:
        static FechaSistema* instancia; //Singleton
        DataFecha fecha;
        FechaSistema();
    public:
        ~FechaSistema();
        static FechaSistema* getInstancia();
        DataFecha getFecha();
        void setFecha(DataFecha);
};

#endif