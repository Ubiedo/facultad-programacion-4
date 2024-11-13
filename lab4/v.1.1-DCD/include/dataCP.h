#ifndef DATACP
#define DATACP

class DataCP {
    private:
        float precioTot;
        bool promoVigente;
    public:
        DataCP(float precioTot, bool promoVigente);
        ~DataCP() = default;
        
        float getPrecioTot();
        bool getPromoVigente();
};

#endif