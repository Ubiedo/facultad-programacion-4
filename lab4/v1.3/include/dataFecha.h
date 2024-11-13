#ifndef DATAFECHA
#define DATAFECHA

#include <string>
using namespace std;

class DataFecha {
    private:
        int dia, mes, anio;
    public:
        DataFecha();
        DataFecha(int dia,int mes,int anio);
        ~DataFecha() = default;

        int getDia();
        int getMes();
        int getAnio();

        friend bool operator>=(const DataFecha& f1, const DataFecha& f2);
        string toString(); //Requerida por Comentario para getDataCmtBasica
};

#endif