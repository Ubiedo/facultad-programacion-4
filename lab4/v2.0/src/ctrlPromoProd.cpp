#include "../include/ctrlPromoProd.h"

CtrlPromoProd::CtrlPromoProd() {}
CtrlPromoProd::~CtrlPromoProd() {
    map<string, Producto*>::iterator itPrd;
    for (itPrd = productos.begin(); itPrd != productos.end(); ++itPrd)
        delete itPrd->second;

    map<string, Promocion*>::iterator itPrm;
    for (itPrm = promociones.begin(); itPrm != promociones.end(); ++itPrm)
        delete itPrm->second;
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

vector<DataProdBasica> CtrlPromoProd::listarProductos() {
    vector<DataProdBasica> res;
    map<string, Producto*>::iterator itProd;
    for (itProd = productos.begin(); itProd != productos.end(); ++itProd) {
        DataProdBasica dpb = itProd->second->getDataProdBasica();
        res.push_back(dpb);
    }
    return res;
}

Producto* CtrlPromoProd::findProducto(string key) {
    if (productos.count(key) != 0)
        return productos[key];
    else
        return NULL;
}

/***********************************ALTA DE PRODUCTO***********************************/

string CtrlPromoProd::crearProducto(string nickname, string nombre, string descripcion, Categoria categoria, int stock, float precio) {
    CtrlUsuarios* cUsrs = CtrlUsuarios::getInstancia();
    Vendedor* v = cUsrs->findVendedor(nickname);

    if (v != NULL) {
        int id = generadorCodigoProducto;
        generadorCodigoProducto++;
        string strId;
        if (id < 10)
            strId = "0" + to_string(id);
        else
            strId = to_string(id);
        string codigo = "prd" + strId;

        Producto* prod = new Producto(v, codigo, nombre, descripcion, categoria, stock, precio);
        v->agregarProducto(prod);
        productos[codigo] = prod;

        return "Producto ingresado con éxito\n";
    } else
        return "[ERROR] Vendedor no encontrado\n";
}

/**********************************CONSULTAR PRODUCTO**********************************/

DataProdConsulta CtrlPromoProd::consultarProducto(string key) {
    if (productos.count(key) != 0)
        return productos[key]->getDataProdConsulta();
    else {
        DataProdConsulta dpcNull = DataProdConsulta("", "", otro, -1, -1);
        return dpcNull;
    }
}

/***********************************DEJAR COMENTARIO***********************************/

vector<DataComentario> CtrlPromoProd::comentariosDeProducto(string key) {
    if (productos.count(key) != 0) 
        return productos[key]->getComentarios();
    else {
        vector<DataComentario> dcbNull;
        return dcbNull;
    }
}

/***********************************CREAR PROMOCION************************************/

vector<string> CtrlPromoProd::nombrePromociones() {
    map<string, Promocion*>::iterator itPrm;
    vector<string> res;
    for (itPrm = promociones.begin(); itPrm != promociones.end(); ++itPrm)
        res.push_back(itPrm->first);
    return res;
}

string CtrlPromoProd::crearPromocion(string nickname, vector<DataProdCantidad> productosPromocion, string nombre, string descripcion, float descuento, DataFecha vencimiento) {
//Pre-C: Verificar previamente que los productos existen y pertenecen al mismo vendedor que la promoción
//Pre-C: Verificar previamente que los productos no pertenecen a una promoción válida
//Pre-C: Verificar previamente que no hay productos repetidos
    CtrlUsuarios* cUsrs = CtrlUsuarios::getInstancia();
    Vendedor* v = cUsrs->findVendedor(nickname);
    Promocion* promo = NULL;

    if ((v != NULL) && (productosPromocion.size() != 0) && (promociones.count(nombre) == 0))
        promo = new Promocion(v, nombre, descripcion, descuento, vencimiento);
    else
        if (v == NULL)
            return "[ERROR] Vendedor no encontrado\n";
        else
            if (productosPromocion.size() == 0)
                return "[ERROR] Promoción requiere al menos un producto\n";
            else
                return "[ERROR] Ya existe una promoción con el nombre dado\n";

    if (promo != NULL) {
        promociones[nombre] = promo;
        v->agregarPromocion(promo);

        vector<DataProdBasica> productosNotificacion;
        for (unsigned int i = 0; i < productosPromocion.size(); i++) {
            Producto* prod = productos[productosPromocion[i].getCodigoProducto()];
            PromoProducto* pp = new PromoProducto(promo, prod, productosPromocion[i].getCantidadProducto());
            promo->agregarPP(pp, prod->getCodigo());
            prod->setPP(pp);
            productosNotificacion.push_back(prod->getDataProdBasica());
        }

        DataNotificacion notificacion = DataNotificacion(nickname, nombre, productosNotificacion);
        v->notificar(notificacion);
    }
    return ("Promoción ingresada con éxito\n");
}

/*********************************CONSULTAR PROMOCION**********************************/

vector<DataPromoConsulta> CtrlPromoProd::listarPromoVigentes(DataFecha fecha) {
    vector<DataPromoConsulta> res;
    map<string, Promocion*>::iterator itPrm;
    for (itPrm = promociones.begin(); itPrm != promociones.end(); ++itPrm) 
        if (itPrm->second->esVigente(fecha))
            res.push_back(itPrm->second->getDataPromoConsulta());
    return res;
}

DataVendedor CtrlPromoProd::infoVendedorPromo(string nombrePromocion) {
    if (promociones.count(nombrePromocion) != 0) {
        Vendedor* v = promociones[nombrePromocion]->getVendedor();
        DataVendedor dV = DataVendedor(v->getNickname(), v->getFechaNacimiento(), v->getNroRut());
        return dV;
    } else {
        DataFecha fechaNull = DataFecha(1,1,0);
        DataVendedor dvNull = DataVendedor(NULL, fechaNull, "");
        return dvNull;
    }
}

vector<DataProdPromo> CtrlPromoProd::infoProductosPromo(string nombrePromocion) {
    if (promociones.count(nombrePromocion) != 0)
        return promociones[nombrePromocion]->infoProductos();
    else {
        vector<DataProdPromo> resNull;
        return resNull;
    }
}

/***********************************REALIZAR COMPRA************************************/

vector<DataProdCompra> CtrlPromoProd::listarProductosDisponibles() {
    vector<DataProdCompra> res;
    map<string, Producto*>::iterator itProd;
    for (itProd = productos.begin(); itProd != productos.end(); ++itProd)
        if (itProd->second->getStock() > 0) {
            DataProdCompra dpc = itProd->second->getDataProdCompra();
            res.push_back(dpc);
        }
    return res;
}

DataCompra CtrlPromoProd::getDetallesCompra(vector<DataProdCantidad> productosCompra, DataFecha fecha) {
//Pre-C: Verificar previamente que las cantidades de producto son mayores a cero
    float monto = 0;
    vector<DataProdPrecio> infoProductos;
    for (unsigned int i = 0; i < productosCompra.size(); i++) {
        DataProdCantidad dpp = productosCompra[i];
        int cantidad = dpp.getCantidadProducto();
        if (productos.count(dpp.getCodigoProducto()) == 0) {
            vector<DataProdPrecio> dppNull;
            DataCompra dcNull = DataCompra(-1, fecha, dppNull);
            return dcNull;
        }
        Producto* prod = productos[dpp.getCodigoProducto()];
        float subtotal = (prod->getPrecio() * cantidad);
        float descuento = 0;
        if (!(prod->sinPromoVigente(fecha))) {
            Promocion* promo = promociones[prod->getNombrePromo()];
            if (promo->cumpleRequisitos(productosCompra)) {
                subtotal = (subtotal * promo->getDescuento());
                descuento = promo->getDescuento();
            }
        }
        monto = monto + subtotal;
        DataProdPrecio infoProducto = DataProdPrecio(prod->getCodigo(), prod->getNombre(), cantidad, descuento, subtotal);
        infoProductos.push_back(infoProducto);
    }
    DataCompra res = DataCompra(monto, fecha, infoProductos);
    return res;
}

string CtrlPromoProd::realizarCompra(string nicknameCliente, vector<DataProdCantidad> productosCompra, DataFecha fecha) {
//Pre-C: Verificar previamente que las cantidades compradas no superan el stock
    CtrlUsuarios* cUsrs = CtrlUsuarios::getInstancia();
    Cliente* cl = cUsrs->findCliente(nicknameCliente);
    if (cl == NULL)
        return "[ERROR] Cliente no encontrado\n";

    int id = generadorCodigoCompra;
    string strId;
    if (id < 10)
        strId = "0" + to_string(id);
    else
        strId = to_string(id);
    string codigo = "cmp" + strId;

    DataCompra dCmp = getDetallesCompra(productosCompra, fecha);
    Compra* cmp = new Compra(codigo, fecha, dCmp.getMonto(), cl);
    cl->agregarCompra(cmp);

    for (unsigned int i = 0; i < productosCompra.size(); i++) {
        if (productos.count(productosCompra[i].getCodigoProducto()) == 0) {
            delete cmp; //Compra se encarga de eliminar los CompraProducto, en caso que hubiera
            return "[ERROR] Producto no encontrado\n";
        }
        Producto* prod = productos[productosCompra[i].getCodigoProducto()];
        int cantidadProducto = productosCompra[i].getCantidadProducto();
        CompraProducto* cProd = new CompraProducto(cantidadProducto, cmp, prod);
        cmp->agregarCP(cProd, prod->getCodigo());
        prod->agregarCP(cProd, codigo);
        prod->disminuirStock(cantidadProducto);
    }
    generadorCodigoCompra++;
    return "Compra ingresada con éxito\n";
}

/***********************************ENVIAR PRODUCTO************************************/

vector<DataCompraPendiente> CtrlPromoProd::comprasPendientesProducto(string codigo) {
    if (productos.count(codigo) != 0)
        return productos[codigo]->getComprasPendientes();
    else {
        vector<DataCompraPendiente> res;
        return res;
    }
}

string CtrlPromoProd::marcarComoEnviado(string codigoProducto, string codigoCompra) {
    if (productos.count(codigoProducto) != 0)
        return productos[codigoProducto]->marcarComoEnviado(codigoCompra);
    else
        return "[ERROR] Producto no encontrado\n";
}