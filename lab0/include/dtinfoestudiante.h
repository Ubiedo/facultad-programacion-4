#ifndef DTINFOESTUDIANTE
#define DTINFOESTUDIANTE

#include <string>

using namespace std;

class DTInfoEstudiante
{
private:
    int CI, IdentificadorInfo;
    string NombreEst;
public:
    DTInfoEstudiante(int ci, string nombre, int identificador);
    ~DTInfoEstudiante();

    int getCI();
    int getIdentificadorInfo();
    string getNombreEst();
    // no tiene "\n" al final, si se quiere salto de linea agregarlo
    friend ostream& operator<<(ostream& stream, const DTInfoEstudiante dtInfoEstudiante);
};

#endif