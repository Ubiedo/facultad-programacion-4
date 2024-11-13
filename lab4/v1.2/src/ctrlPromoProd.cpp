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

CtrlPromoProd* CtrlPromoProd::instancia = NULL;

//Alta de Producto

void CtrlPromoProd::crearProducto(DataProducto dp) {
    CtrlUsuarios* cUsrs = CtrlUsuarios::getInstancia();
    Vendedor* v = cUsrs->findVendedor(dp.getNickname());

    int id = generadorCodigoProducto;
    generadorCodigoProducto++;
    string strId;
    if (id < 10)
        strId = "0" + to_string(id);
    else
        strId = to_string(id);
    string codigo = "prd" + strId;

    Producto* prod = new Producto(v, codigo, dp.getNombre(), dp.getDescripcion(), dp.getCategoria(), dp.getStock(), dp.getPrecio());
    
    v->agregarProducto(prod);
    productos[codigo] = prod;
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

DataProdConsulta CtrlPromoProd::consultarProducto(string key) {
    return productos[key]->getDataProdConsulta();
}

//Dejar Comentario

vector<DataCmtBasica> CtrlPromoProd::comentariosDeProducto(string key) {
    return productos[key]->getComentarios();
}

bool CtrlPromoProd::productoTieneComentarios(string key) {
    return productos[key]->tieneComentarios();
}

//Requeridas por CtrlUsuarios

Producto* CtrlPromoProd::findProducto(string key) {
    return productos[key];
}