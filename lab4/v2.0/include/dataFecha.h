#ifndef DATAFECHA
#define DATAFECHA

#include <string>
using namespace std;

class DataFecha {
    private:
        int dia, mes, anio;
    public:
        DataFecha();
        DataFecha(int, int, int);
        ~DataFecha() = default;

        int getDia();
        int getMes();
        int getAnio();

        string toString();
        friend bool operator>=(const DataFecha& f1, const DataFecha& f2);
};

#endif