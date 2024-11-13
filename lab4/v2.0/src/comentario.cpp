#include "../include/comentario.h"

Comentario::Comentario(string codigo, string texto, DataFecha fecha, Usuario* usuario, Producto* producto, Comentario* padre) {
    this->codigo = codigo;
    this->texto = texto;
    this->fecha = fecha;
    this->usuario = usuario;
    this->producto = producto;
    this->padre = padre;
}

string Comentario::getCodigo() {
    return this->codigo;
}

string Comentario::getTexto() {
    return this->texto;
}

DataFecha Comentario::getFecha() {
    return this->fecha;
}

Usuario* Comentario::getUsuario() {
    return this->usuario;
}

Producto* Comentario::getProducto() {
    return this->producto;
}

Comentario* Comentario::getPadre() {
    return this->padre;
}

DataComentario Comentario::getDataComentario() {
    string codigo = this->codigo;
    string strComentario;
    if (padre != NULL)
        strComentario = "[" + this->codigo + "] R:[" + padre->getCodigo() + "] " + fecha.toString() + "\n"
        + usuario->getNickname() + " (en respuesta a " + padre->getUsuario()->getNickname() + "): " + texto;
    else
        strComentario = "[" + this->codigo + "] " + fecha.toString() + "\n" 
        + usuario->getNickname() + ": " + texto;
    return DataComentario(codigo, strComentario);
}

void Comentario::agregarRespuesta(Comentario* cmt) {
    respuestas[cmt->getCodigo()] = cmt;
}

void Comentario::removerRespuesta(string codigo) {
    respuestas.erase(codigo);
}

vector<Comentario*> Comentario::getRespuestas() {
    vector<Comentario*> res;
    map<string, Comentario*>::iterator itCmt;
    for (itCmt = respuestas.begin(); itCmt != respuestas.end(); ++itCmt)
        res.push_back(itCmt->second);
    return res;
}