#ifndef DATAPROMOPRODUCTO
#define DATAPROMOPRODUCTO

#include <string>
using namespace std;

class DataPromoProducto {
    private:
        string codigoProducto;
        int minimoProducto;
    public:
        DataPromoProducto(string codigoProducto, int minimoProducto);
        ~DataPromoProducto() = default;

        string getCodigoProducto();
        int getMinimoProducto();
};

#endif