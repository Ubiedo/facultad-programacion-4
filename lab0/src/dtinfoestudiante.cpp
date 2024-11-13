#include "../include/dtinfoestudiante.h"

//Se crea un registro con ci, nombre, identificador.
DTInfoEstudiante::DTInfoEstudiante(int ci, string nombre, int identificador){
    CI = ci;
    NombreEst = nombre;
    IdentificadorInfo = identificador;
}

//Destructor default.
DTInfoEstudiante::~DTInfoEstudiante(){
}

//Retorna ci.
int DTInfoEstudiante::getCI(){
    return CI;
}

//Retorna identificador.
int DTInfoEstudiante::getIdentificadorInfo(){
    return IdentificadorInfo;
}

//Retorna nombre.
string DTInfoEstudiante::getNombreEst(){
    return NombreEst;
}

//Permite esribir los registros con el operador <<.
ostream& operator<<(ostream& stream, const DTInfoEstudiante dtInfoEstudiante) {
    stream << to_string(dtInfoEstudiante.CI) + ", " + dtInfoEstudiante.NombreEst + ", " + to_string(dtInfoEstudiante.IdentificadorInfo);
    return stream;
}