#ifndef DATAPROMOPRODUCTO
#define DATAPROMOPRODUCTO

#include <string>
using namespace std;

class DataPromoProducto {
    private:
        string codigoProducto;
        int cantidadProducto;
    public:
        DataPromoProducto(string codigoProducto, int cantidadProducto);
        ~DataPromoProducto() = default;

        string getCodigoProducto();
        int getCantidadProducto();
};

#endif