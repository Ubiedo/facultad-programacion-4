#include "../include/dataEnvioPendiente.h"

DataEnvioPendiente::DataEnvioPendiente(string nombreCliente, DataFecha fecha){
    this->nombreCliente = nombreCliente;
    this->fecha = fecha;
}
DataEnvioPendiente::~DataEnvioPendiente(){}

string DataEnvioPendiente::getNombreCliente(){
    return this->nombreCliente;
}

DataFecha DataEnvioPendiente::getFecha(){
    return this->fecha;
}