#include "../include/dataEnvioPendiente.h"

DataEnvioPendiente::DataEnvioPendiente(string solicitud, string nombreCliente, DataFecha fecha){
    this->solicitud = solicitud;
    this->nombreCliente = nombreCliente;
    this->fecha = fecha;
}
//DataEnvioPendiente::~DataEnvioPendiente(){}

string DataEnvioPendiente::getSolicitud(){
    return this->solicitud;
}

string DataEnvioPendiente::getNombreCliente(){
    return this->nombreCliente;
}

DataFecha DataEnvioPendiente::getFecha(){
    return this->fecha;
}