#include "../include/cliente.h"

Cliente::Cliente(DataCliente dc) {
    this->nickname = dc.getNickname();
    this->contrasena = dc.getContrasena();
    this->fechaNacimiento = dc.getFechaNacimiento();
    this->calle = dc.getCalle();
    this->nroPuerta = dc.getNroPuerta();
    this->ciudad = dc.getCiudad();
}

string Cliente::getCalle() {
    return this->calle;
}

int Cliente::getNroPuerta() {
    return this->nroPuerta;
}

string Cliente::getCiudad() {
    return this->ciudad;
}

map<string, Vendedor*> Cliente::getVendedores() {
    return this->vendedores;
}

set<NotiCliente*> Cliente::getNotisCliente() {
    return this->notisCliente;
}

void Cliente::setCalle(string calle) {
    this->calle = calle;
}

void Cliente::setNroPuerta(int nroPuerta) {
    this->nroPuerta = nroPuerta;
}

void Cliente::setCiudad(string ciudad) {
    this->ciudad = ciudad;
}

// falta agregarle lo de suscripcion
string Cliente::toString() {
    string res = "Nickname: " + this->nickname + "\n" 
    + "Fecha de nacimiento: " + to_string(this->fechaNacimiento.getDia()) + "/" 
    + to_string(this->fechaNacimiento.getMes()) + "/" + to_string(this->fechaNacimiento.getAnio()) 
    + "\n" + "Calle: " + this->calle + "\n" + "Número de puerta: " + to_string(this->nroPuerta) + "\n" 
    + "Ciudad: " + this->ciudad + "\n";
    return res; 
}

bool Cliente::suscritoAVendedor(Vendedor* v){
    if (!this->vendedores.empty()){
        // definimos el iterador
        map<string, Vendedor*>::iterator it = this->vendedores.begin();
        // mientras haya elementos y sean distnitos avanza
        while (it != this->vendedores.end() && it->second != v){
            ++it;
        }
        // si no se detuvo por que no habian elementos entonces no se cumple la segunda condicion
        // entonces pertenece, sino no
        return (it != this->vendedores.end());
    }
    // si esta empty entonces no hay ningun vendedor
    return false;
}

void Cliente::suscribirAVendedor(Vendedor* v){
    this->vendedores.insert({v->getNickname(), v});
    v->agregar(this);
}

set<DataNotificacion> Cliente::getNotificaciones(){
    set<DataNotificacion> lista;
    if (!this->notisCliente.empty()){
        set<NotiCliente*>::iterator it; // iterador para set<int>
        for (it = this->notisCliente.begin(); it != this->notisCliente.end(); ++it){
            lista.insert(DataNotificacion((*it)->getNickVendedor(), (*it)->getNombPromo(), (*it)->getDataProductos()));
        }
    }
    return lista;
}

void Cliente::vaciarNotificaciones(){
    if(!this->notisCliente.empty()){
        while(!this->notisCliente.empty()){
            this->notisCliente.erase(this->notisCliente.begin());
        }
    }
}

set<string> Cliente::getSuscripciones(){
    set<string> lista;
    if (!this->notisCliente.empty()){
        set<NotiCliente*>::iterator it; // iterador para set<int>
        for (it = this->notisCliente.begin(); it != this->notisCliente.end(); ++it){
            lista.insert((*it)->getNickVendedor());
        }
    }
    return lista;
}

// pre:
// el vendedor v, pertenece a la lista de vendedores suscrito
void Cliente::desuscribir(Vendedor* v){
    this->vendedores.erase(v->getNickname());
    v->quitar(this);
}

void notificar(){}