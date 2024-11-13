#ifndef DATAPROMOPROD
#define DATAPROMOPROD

#include <string>

using namespace std;

class DataPromoProd {
    private:
        string codigo;
        int prodTotales;
        float descuento;
        bool prodCumpleReq;
    public:
        DataPromoProd(string codigo, int prodTotales, float descuento, bool prodCumpleReq);
        ~DataPromoProd() = default;
        
        float getCodigo();
        bool getProdTotales();
        bool getDescuento();
        bool getProdCumpleReq();
};

#endif