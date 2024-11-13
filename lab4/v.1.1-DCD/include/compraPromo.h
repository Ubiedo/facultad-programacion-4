#ifndef COMPRAPROMO
#define COMPRAPROMO

#include <string>

using namespace std;

class CompraPromo {
    protected:
        string identificador;
        int prodTotales, prodEfectivos;
        float montoAcum, descuento;
    public:
        CompraPromo(string identificador, int prodTotales, int prodEfectivos, float montoAcum, float descuento);
        virtual ~CompraPromo() = default;
        
        string getIdentificador();
        int getProdTotales();
        int getProdEfectivos();
        float getMontoAcum();
        float getDescuento();
        
        void getIdentificador(string identificador);
        void getProdTotales(int prodTotales);
        void getProdEfectivos(int prodEfectivos);
        void getMontoAcum(float montoAcum);
        void getDescuento(float descuento);

        void agregarProd(float precioTot, bool prodCumpleReq);
        float getMontoFinal();
};

#endif