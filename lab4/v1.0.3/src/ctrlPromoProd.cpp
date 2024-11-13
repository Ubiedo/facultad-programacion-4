#include "../include/ctrlPromoProd.h"

CtrlPromoProd::CtrlPromoProd() {}
CtrlPromoProd::~CtrlPromoProd() {
    map<string, Producto*>::iterator itPrd;
    for (itPrd = productos.begin(); itPrd != productos.end(); ++itPrd)
        delete itPrd->second;
}

CtrlPromoProd* CtrlPromoProd::getInstancia() {
    if (instancia == NULL) {
        instancia = new CtrlPromoProd();
        return instancia;
    } else {
        return instancia;
    }
}

//Alta de Producto

bool CtrlPromoProd::isEmptyVendedores() {
    CtrlUsuarios* cUsrs = CtrlUsuarios::getInstancia();
    return cUsrs->isEmptyVendedores();
}

vector<string> CtrlPromoProd::nicknameVendedores() {
    CtrlUsuarios* cUsrs = CtrlUsuarios::getInstancia();
    return cUsrs->nicknameVendedores();
}

void CtrlPromoProd::crearProducto(string nicknameVendedor, DataProducto dp) {
    CtrlUsuarios* cUsrs = CtrlUsuarios::getInstancia();
    Vendedor* v = cUsrs->getVendedor(nicknameVendedor);
    int id = v->generarId();

    Producto* prod = new Producto(id, dp.getNombre(), dp.getDescripcion(), dp.getCategoria(), dp.getStock(), dp.getPrecio());
    
    prod->setVendedor(v);
    v->agregarProducto(prod); //implementar!

    string keyProducto = nicknameVendedor + "_PROD" + to_string(id);
    productos[keyProducto] = prod;
}

//Consultar Producto

bool CtrlPromoProd::isEmptyProductos() {
    return productos.empty();
}

vector<DataProdBasica> CtrlPromoProd::listarProductos() {
    string codigo, nombre;
    vector<DataProdBasica> res;
    map<string, Producto*>::iterator itProd;
    for (itProd = productos.begin(); itProd != productos.end(); ++itProd) {
        codigo = itProd->first;
        nombre = itProd->second->getNombre();
        DataProdBasica dpb = DataProdBasica(codigo, nombre);
        res.push_back(dpb);
    }
    return res;
}

DataProdConsulta CtrlPromoProd::consultarProducto(string id) {
    return productos[id]->getDataProdConsulta();
}

CtrlPromoProd* CtrlPromoProd::instancia = NULL;