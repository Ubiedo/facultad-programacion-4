#ifndef DTFECHA
#define DTFECHA

class DTFecha
{
private:
    int Dia, Mes, Anio;
public:
    DTFecha();
    DTFecha(int dia,int mes,int anio);
    ~DTFecha();

    int getDia();
    int getMes();
    int getAnio();

    friend bool operator>=(const DTFecha& f1, const DTFecha& f2);
};

#endif