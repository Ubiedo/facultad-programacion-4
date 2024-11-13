#include "include/factory.h"
#include "iostream"

void main_comandos();
void main_datos(IUsuarios* iUsrs, IPromoProd* iPP);

void main_altaDeUsuario(IUsuarios*);
void main_listarUsuarios(IUsuarios*);
void main_altaDeProducto(IUsuarios*, IPromoProd*);
void main_consultarProducto(IPromoProd*);
void main_dejarComentario(IUsuarios*, IPromoProd*, DataFecha);
void main_eliminarComentario(IUsuarios*);
void main_crearPromocion(IUsuarios*, IPromoProd*, DataFecha);
void main_consultarPromocion(IPromoProd*, DataFecha);

//no usar dataProductosPromo y que la funcion retorne ya el string?

int main() {
    /*******************INICIALIZACIÓN DE INTERFACES*******************/
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    IPromoProd* iPP = f->getIPromoProd();
    /*************************MENSAJE INICIAL**************************/
    cout << "Mercado Finger v1.2\n"
        << "En esta versión: Usuarios, Productos, Comentarios y Promociones\n" << endl
        << "Programación 4 Curso 2024\n"
        << "Laboratorio 4 - Grupo 8: Federico González, Marcos Baptista, Matías Silvera, Roque Serrato y Juan Pablo Otero\n"
        << "Docente: Miguel Machado\n";
    /***********************OBTENER FECHA ACTUAL***********************/
    string aux;
    int* fecha = new int[3];
    bool fechaInvalida = true;
    while (fechaInvalida) {
        cout << endl << "Ingrese la fecha actual para comenzar (dd/mm/aaaa): ";
        scanf("%d/%d/%d", &fecha[0], &fecha[1], &fecha[2]);
        getline(cin, aux);
        if ((fecha[0] > 31) || (fecha[0] < 1) || (fecha[1] > 12) || (fecha[1] < 1) || (fecha[2] < 1))
            cout << endl << "[ERROR] Fecha inválida\n";
        else
            fechaInvalida = false;
    }
    DataFecha fechaActual = DataFecha(fecha[0], fecha[1], fecha[2]);
    delete[] fecha;
    /*******************MENSAJE DE BIENVENIDA Y MENÚ*******************/
    cout << endl << "¡Bienvenido a Mercado Finger! Ingrese 'comandos' para ver los comandos disponibles\n";
    string entrada;
    bool continuar = true;
    while (continuar) {
        cout << endl << ">>";
        cin >> entrada;
        getline(cin, aux);
        if (entrada.compare("altaDeUsuario") == 0)
            main_altaDeUsuario(iUsrs);
        else if (entrada.compare("listarUsuarios") == 0)
            main_listarUsuarios(iUsrs);
        else if (entrada.compare("altaDeProducto") == 0)
            main_altaDeProducto(iUsrs, iPP);
        else if (entrada.compare("consultarProducto") == 0)
            main_consultarProducto(iPP);
        else if (entrada.compare("dejarComentario") == 0)
            main_dejarComentario(iUsrs, iPP, fechaActual);
        else if (entrada.compare("eliminarComentario") == 0)
            main_eliminarComentario(iUsrs);
        else if (entrada.compare("crearPromocion") == 0)
            main_crearPromocion(iUsrs, iPP, fechaActual);
        else if (entrada.compare("consultarPromocion") == 0)
            main_consultarPromocion(iPP, fechaActual);
        else if (entrada.compare("datos") == 0)
            main_datos(iUsrs, iPP);
        else if (entrada.compare("comandos") == 0)
            main_comandos();
        else if (entrada.compare("exit") == 0) {
            delete iUsrs;
            delete iPP;
            delete f;
            continuar = false;
        } else
            cout << endl << "[ERROR] Comando no reconocido. Ingrese 'comandos' para ver los comandos disponibles\n";
    }
    return 0;
}

void main_comandos() {
    cout << endl << "altaDeUsuario: Ingresa un nuevo usuario al sistema\n" 
    << "listarUsuarios: Muestra los datos de todos los usuarios en sistema\n"
    << "altaDeProducto: Ingresa un nuevo producto al sistema\n"
    << "consultarProducto: Muestra la información de un producto seleccionado\n"
    << "dejarComentario: Comenta un producto o responde a un comentario existente\n"
    << "eliminarComentario: Elimina un comentario y todas sus respuestas en cascada\n"
    << "crearPromocion: Ingresa una nueva promoción al sistema\n" 
    << "consultarPromocion: Muestra los datos del vendedor y la información de todos los comentarios de una promoción\n"
    << endl << "datos: Ingresa en el sistema datos predeterminados\n" 
    << "exit: Libera la memoria y finaliza la ejecución\n"; 
}

void main_datos(IUsuarios* iUsrs, IPromoProd* iPP) {
    string aux;

    DataFecha fecha1 = DataFecha(13,1,2003);
    DataCliente dc1 = DataCliente("jp.otero", "abc123", fecha1, "Av. Alvear", 357, "Ciudad de la Costa");
    aux = iUsrs->crearCliente(dc1);

    DataFecha fecha2 = DataFecha(14,7,1991);
    DataCliente dc2 = DataCliente("cj", "password", fecha2, "Grove Street", 1111, "LA");
    aux = iUsrs->crearCliente(dc2);

    DataFecha fecha3 = DataFecha(24,1,1987);
    DataCliente dc3 = DataCliente("lucho.suarez9", "bolso1899", fecha3, "rambla de lagomar", 777, "Salto");
    aux = iUsrs->crearCliente(dc3);

    DataFecha fecha4 = DataFecha(9,12,2008);
    DataVendedor dv1 = DataVendedor("sazu4", "woofwoof", fecha4, "120123456789");
    aux = iUsrs->crearVendedor(dv1);

    DataFecha fecha5 = DataFecha(31,12,1999);
    DataVendedor dv2 = DataVendedor("chinorochet", "contraseña123", fecha5, "987654321012");
    aux = iUsrs->crearVendedor(dv2);

    DataFecha fecha6 = DataFecha(1,1,2000);
    DataVendedor dv3 = DataVendedor("peter.parker", "contraseña123", fecha6, "987654321012");
    aux = iUsrs->crearVendedor(dv3);

    DataProducto dp1 = DataProducto("chinorochet", "Corsita 1.6 2008", "tremenda maquina. no pierde aceite porque no tiene", otro, 1, 385000);
    iPP->crearProducto(dp1); //prd01

    DataProducto dp2 = DataProducto("chinorochet", "jugo de naranja", "natural. sin conservantes. oportunidad unica!!!!!", otro, 28, 65);
    iPP->crearProducto(dp2); //prd02

    DataProducto dp3 = DataProducto("sazu4", "play 2 chipeada", "acepto permutas", electrodomestico, 1, 20000);
    iPP->crearProducto(dp3); //prd03

    DataProducto dp4 = DataProducto("peter.parker", "mascara de spiderman", "excelente estado", ropa, 5, 1000);
    iPP->crearProducto(dp4); //prd04

    DataFecha fecha7 = DataFecha(4,6,2024);
    DataComentario dCmt1 = DataComentario("prd04", "", "sazu4", "woof woof", fecha7); //cmt01
    iUsrs->crearComentario(dCmt1);

    DataFecha fecha8 = DataFecha(5,6,2024);
    DataComentario dCmt2 = DataComentario("prd03", "", "jp.otero", "carisima", fecha8); //cmt02
    iUsrs->crearComentario(dCmt2);

    DataFecha fecha9 = DataFecha(6,6,2024);
    DataComentario dCmt3 = DataComentario("prd04", "", "cj", "te la permuto por una bigmac", fecha9); //cmt03
    iUsrs->crearComentario(dCmt3);

    DataFecha fecha10 = DataFecha(7,6,2024);
    DataComentario dCmt4 = DataComentario("prd04", "cmt03", "peter.parker", "ni ahi", fecha10); //cmt04
    iUsrs->crearComentario(dCmt4);

    DataFecha fecha11 = DataFecha(7,6,2024);
    DataComentario dCmt5 = DataComentario("prd01", "", "lucho.suarez9", "cuantos km?", fecha11); //cmt05
    iUsrs->crearComentario(dCmt5);

    DataFecha fecha12 = DataFecha(8,6,2024);
    DataComentario dCmt6 = DataComentario("prd01", "cmt05", "chinorochet", "520k", fecha12); //cmt06
    iUsrs->crearComentario(dCmt6);

    DataFecha fecha13 = DataFecha(9,6,2024);
    DataComentario dCmt7 = DataComentario("prd02", "", "jp.otero", "espantoso", fecha13); //cmt07
    iUsrs->crearComentario(dCmt7);

    DataFecha fecha14 = DataFecha(10,6,2024);
    DataComentario dCmt8 = DataComentario("prd02", "cmt07", "sazu4", "mal", fecha14); //cmt08
    iUsrs->crearComentario(dCmt8);

    cout << endl << "Datos cargados en sistema\n";
}

void main_altaDeUsuario(IUsuarios* iUsrs) {
    string entrada, aux;
    bool entradaInvalida = true;
    while (entradaInvalida) {
        cout << endl << "Ingrese 'c' si el usuario es cliente, 'v' si es vendedor: ";
        cin >> entrada;
        getline(cin, aux);
        if ((entrada.compare("c") == 0) || (entrada.compare("v") == 0)) {
            entradaInvalida = false;
            /*********************USUARIO INGRESA NICKNAME*********************/
            string nickname;
            cout << "Nickname: ";
            cin >> nickname;
            getline(cin, aux);
            /********************USUARIO INGRESA CONTRASEÑA********************/
            string contrasena;
            bool contrasenaInvalida = true;
            while (contrasenaInvalida) {
                cout << "Contraseña: ";
                cin >> contrasena;
                getline(cin, aux);
                if (contrasena.size() < 6)
                    cout << endl << "[ERROR] Ingrese una contraseña con al menos seis caracteres\n" << endl;
                else
                    contrasenaInvalida = false;
            }
            /**********************USUARIO INGRESA FECHA***********************/
            int* fecha = new int[3];
            bool fechaInvalida = true;
            while (fechaInvalida) {
                cout << "Fecha de nacimiento (dd/mm/aaaa): ";
                scanf("%d/%d/%d", &fecha[0], &fecha[1], &fecha[2]);
                getline(cin, aux);
                if ((fecha[0] > 31) || (fecha[0] < 1) || (fecha[1] > 12) || (fecha[1] < 1) || (fecha[2] < 1))
                    cout << endl << "[ERROR] Fecha inválida\n" << endl;
                else
                    fechaInvalida = false;
            }
            DataFecha fechaNacimiento = DataFecha(fecha[0], fecha[1], fecha[2]);
            delete[] fecha;
            /*************************ALTA DE CLIENTE**************************/
            if (entrada.compare("c") == 0) {
                string calle;
                cout << "Calle: ";
                getline(cin, calle);

                int nroPuerta;
                cout << "Número de puerta: ";
                scanf("%d", &nroPuerta);
                getline(cin, aux);

                string ciudad;
                cout << "Ciudad: ";
                getline(cin, ciudad);

                DataCliente dc = DataCliente(nickname, contrasena, fechaNacimiento, calle, nroPuerta, ciudad);
                cout << endl << iUsrs->crearCliente(dc);
            } else {
            /*************************ALTA DE VENDEDOR*************************/
                long long nroRut;
                string stringRut;
                bool rutInvalido = true;
                while (rutInvalido) {
                    cout << "Número de RUT: ";
                    scanf("%lli", &nroRut);
                    getline(cin, aux);
                    stringRut = to_string(nroRut);
                    if (stringRut.size() == 12)
                        rutInvalido = false;
                    else
                        cout << endl << "[ERROR] Número de RUT debe tener doce caracteres numéricos\n" << endl;
                }

                DataVendedor dv = DataVendedor(nickname, contrasena, fechaNacimiento, stringRut);
                cout << endl << iUsrs->crearVendedor(dv);
            }
        } else
            cout << endl << "[ERROR] Entrada inválida\n";
    }
}

void main_listarUsuarios(IUsuarios* iUsrs) {
    vector<string> listadoUsuarios = iUsrs->listarUsuarios();
    unsigned int i;
    for (i = 0; i < listadoUsuarios.size(); i++)
        cout << endl << listadoUsuarios[i];
    if (i == 0) 
        cout << endl << "[ERROR] No hay usuarios en sistema\n";
}

void main_altaDeProducto(IUsuarios* iUsrs, IPromoProd* iPP) {
    if (iUsrs->isEmptyVendedores())
        cout << endl << "[ERROR] No hay vendedores en sistema\n";
    else {
        vector<string> res = iUsrs->nicknameVendedores();
        for (unsigned int i = 0; i < res.size(); i++)
            cout << endl << res[i];
        /*********************USUARIO INGRESA VENDEDOR*********************/
        cout << endl;
        string nickname, aux;
        bool nicknameInvalido = true;
        while (nicknameInvalido) {
            cout << endl << "Vendedor del producto: ";
            cin >> nickname;
            getline(cin, aux);
            unsigned int i = 0;
            while ((i < res.size()) && (nickname.compare(res[i]) != 0))
                i++;
            if (i < res.size())
                nicknameInvalido = false;
            else
                cout << endl << "[ERROR] No existe vendedor '" << nickname << "'\n";
        }
        /**********************USUARIO INGRESA NOMBRE**********************/
        string nombre;
        cout << "Nombre: ";
        getline(cin, nombre);
        /********************USUARIO INGRESA DESCRIPCIÓN*******************/
        string descripcion;
        cout << "Descripcion: ";
        getline(cin, descripcion);
        /*********************USUARIO INGRESA CATEGORÍA*********************/
        string categoriaString;
        Categoria categoria = otro;
        bool categoriaInvalida = true;
        while (categoriaInvalida) {
            cout << "Categoría (Ropa, Electrodoméstico u Otro): ";
            cin >> categoriaString;
            getline(cin, aux);
            if ((categoriaString.compare("Ropa") == 0) || (categoriaString.compare("ropa") == 0) 
            || (categoriaString.compare("ROPA") == 0)) {
                categoriaInvalida = false;
                categoria = ropa;
            } else
            if ((categoriaString.compare("Electrodoméstico") == 0) || (categoriaString.compare("electrodoméstico") == 0) 
            || (categoriaString.compare("ELECTRODOMÉSTICO") == 0) || (categoriaString.compare("Electrodomestico") == 0) 
            || (categoriaString.compare("electrodomestico") == 0) || (categoriaString.compare("ELECTRODOMESTICO") == 0)) {
                categoriaInvalida = false;
                categoria = electrodomestico;
            } else
            if ((categoriaString.compare("Otro") == 0) || (categoriaString.compare("otro") == 0) 
            || (categoriaString.compare("OTRO") == 0)) {
                categoriaInvalida = false;
                categoria = otro;
            } else
                cout << endl << "[ERROR] Categoría inválida\n" << endl;
        }
        /***********************USUARIO INGRESA STOCK***********************/
        int stock;
        cout << "Stock: ";
        scanf("%d", &stock);
        getline(cin, aux);
        /***********************USUARIO INGRESA PRECIO**********************/
        float precio;
        cout << "Precio: UYU ";
        scanf("%f", &precio);
        getline(cin, aux);
        /**************************ALTA DE PRODUCTO*************************/
        DataProducto dp = DataProducto(nickname, nombre, descripcion, categoria, stock, precio);
        iPP->crearProducto(dp);

        cout << endl << "Producto ingresado con éxito\n";
    }
}

void main_consultarProducto(IPromoProd* iPP) {
    if (iPP->isEmptyProductos())
        cout << endl << "[ERROR] No hay productos en sistema\n";
    else {
        vector<DataProdBasica> listadoProductos = iPP->listarProductos();
        for (unsigned int i = 0; i < listadoProductos.size(); i++)
            cout << endl << "[" << listadoProductos[i].getCodigo() << "] " << listadoProductos[i].getNombre();
        /*********************USUARIO INGRESA PRODUCTO*********************/
        cout << endl;
        string codigoProducto, aux;
        bool productoInvalido = true;
        while (productoInvalido) {
            cout << endl << "Producto (prd#): ";
            cin >> codigoProducto;
            getline(cin, aux);
            unsigned int i = 0;
            while ((i < listadoProductos.size()) && (codigoProducto.compare(listadoProductos[i].getCodigo()) != 0))
                i++;
            if (i < listadoProductos.size())
                productoInvalido = false;
            else
                cout << endl << "[ERROR] No existe producto '" << codigoProducto << "'\n";
        }
        /***********************IMPRIMIR INFORMACION***********************/
        DataProdConsulta dpc = iPP->consultarProducto(codigoProducto);
        cout << endl << "Vendedor: " << dpc.getVendedor() << endl;
        cout << "Descripción: " << dpc.getDescripcion() << endl;
        cout << "Categoria: ";
        if (dpc.getCategoria() == ropa)
            cout << "Ropa" << endl;
        else if (dpc.getCategoria() == electrodomestico)
            cout << "Electrodoméstico" << endl;
        else
            cout << "Otro" << endl;
        cout << "Stock: " << to_string(dpc.getStock()) << endl;
        cout << "Precio: UYU ";
        printf("%.2f\n", dpc.getPrecio());
    }
}

void main_dejarComentario(IUsuarios* iUsrs, IPromoProd* iPP, DataFecha fechaActual) {
    if (iPP->isEmptyProductos())
        cout << endl << "[ERROR] No hay productos en sistema\n";
    else {
        /*********************USUARIO INGRESA NICKNAME*********************/
        vector<string> nicknameUsuarios = iUsrs->nicknameUsuarios();
        for (unsigned int i = 0; i < nicknameUsuarios.size(); i++)
            cout << endl << nicknameUsuarios[i];
        cout << endl;
        string nickname, aux;
        bool nicknameInvalido = true;
        while (nicknameInvalido) {
            cout << endl << "Usuario: ";
            cin >> nickname;
            getline(cin, aux);
            unsigned int i = 0;
            while ((i < nicknameUsuarios.size()) && (nickname.compare(nicknameUsuarios[i]) != 0))
                i++;
            if (i < nicknameUsuarios.size())
                nicknameInvalido = false;
            else
                cout << endl << "[ERROR] No existe usuario '" << nickname << "'\n";
        }
        /*********************USUARIO INGRESA PRODUCTO*********************/
        vector<DataProdBasica> listadoProductos = iPP->listarProductos();
        for (unsigned int i = 0; i < listadoProductos.size(); i++)
            cout << endl << "[" << listadoProductos[i].getCodigo() << "] " << listadoProductos[i].getNombre();
        cout << endl;
        string codigoProducto;
        bool productoInvalido = true;
        while (productoInvalido) {
            cout << endl << "Producto (prd#): ";
            cin >> codigoProducto;
            getline(cin, aux);
            unsigned int i = 0;
            while ((i < listadoProductos.size()) && (codigoProducto.compare(listadoProductos[i].getCodigo()) != 0))
                i++;
            if (i < listadoProductos.size())
                productoInvalido = false;
            else
                cout << endl << "[ERROR] No existe producto '" << codigoProducto << "'\n";
        }
        /************************COMENTA O RESPONDE************************/
        string respuesta = "n"; 
        bool respuestaInvalida = true;
        if (iPP->productoTieneComentarios(codigoProducto)) {
            while (respuestaInvalida) {
                cout << endl << "Ingrese 'n' para realizar un comentario nuevo, 'r' para responder a uno existente: ";
                cin >> respuesta;
                getline(cin, aux);
                if ((respuesta.compare("n") == 0) || (respuesta.compare("r") == 0))
                    respuestaInvalida = false;
                else
                    cout << endl << "[ERROR] Resuesta inválida\n";
            }
        }
        /**********************RESPUESTA A COMENTARIO**********************/
        string codigoPadre = "";
        if (respuesta.compare("r") == 0) {
            vector<DataCmtBasica> comentariosDeProducto = iPP->comentariosDeProducto(codigoProducto);
            for (unsigned int i = 0; i < comentariosDeProducto.size(); i++)
                cout << endl << comentariosDeProducto[i].getStrComentario() << endl;
            bool codigoInvalido = true;
            while (codigoInvalido) {
                cout << endl << "Comentario (cmt#): ";
                cin >> codigoPadre;
                getline(cin, aux);
                unsigned int i = 0;
                while ((i < comentariosDeProducto.size()) && 
                (codigoPadre.compare(comentariosDeProducto[i].getCodigo()) != 0))
                    i++;
                if (i < comentariosDeProducto.size())
                    codigoInvalido = false;
                else
                    cout << endl << "[ERROR] No existe comentario '" << codigoPadre << "'\n";
            }
        }
        /************************ALTA DE COMENTARIO************************/
        string texto;
        cout << "Ingrese su comentario: ";
        getline(cin, texto);
        DataComentario dCmt = DataComentario(codigoProducto, codigoPadre, nickname, texto, fechaActual);
        iUsrs->crearComentario(dCmt);
        cout << endl << "Comentario ingresado con éxito\n";
    }
}

void main_eliminarComentario(IUsuarios* iUsrs) {
    if (iUsrs->isEmptyComentarios())
        cout << endl << "[ERROR] No hay comentarios en sistema\n";
    else {
        /*********************USUARIO INGRESA NICKNAME*********************/
        vector<string> nicknameUsuarios = iUsrs->usuariosConComentarios();
        for (unsigned int i = 0; i < nicknameUsuarios.size(); i++)
            cout << endl << nicknameUsuarios[i];
        cout << endl;
        string nickname, aux;
        bool nicknameInvalido = true;
        while (nicknameInvalido) {
            cout << endl << "Usuario: ";
            cin >> nickname;
            getline(cin, aux);
            unsigned int i = 0;
            while ((i < nicknameUsuarios.size()) && (nickname.compare(nicknameUsuarios[i]) != 0))
                i++;
            if (i < nicknameUsuarios.size())
                nicknameInvalido = false;
            else
                cout << endl << "[ERROR] No existe usuario '" << nickname << "'\n";
        }
        /********************USUARIO INGRESA COMENTARIO********************/
        vector<DataCmtBasica> comentariosDeUsuario = iUsrs->comentariosDeUsuario(nickname);
        for (unsigned int i = 0; i < comentariosDeUsuario.size(); i++)
            cout << endl << comentariosDeUsuario[i].getStrComentario() << endl;
        string codigoComentario;
        bool codigoInvalido = true;
        while (codigoInvalido) {
            cout << endl << "Comentario (cmt#): ";
            cin >> codigoComentario;
            getline(cin, aux);
            unsigned int i = 0;
            while ((i < comentariosDeUsuario.size()) && 
            (codigoComentario.compare(comentariosDeUsuario[i].getCodigo()) != 0))
                i++;
            if (i < comentariosDeUsuario.size())
                codigoInvalido = false;
            else
                cout << endl << "[ERROR] No existe comentario '" << codigoComentario << "'\n";
        }
        /***********************ELIMINAR COMENTARIO************************/
        iUsrs->eliminarComentario(nickname, codigoComentario);
        cout << endl << "Comentario(s) eliminado(s) con éxito\n";
    }
}

void main_crearPromocion(IUsuarios* iUsrs, IPromoProd* iPP, DataFecha fechaActual) {
    if (iPP->existeProductoDisponible(fechaActual)) {
        /**********************USUARIO INGRESA NOMBRE**********************/
        vector<string> nombrePromociones = iPP->nombrePromociones();
        bool nombreInvalido = true;
        string nombre, aux;
        while (nombreInvalido) {
            cout << endl << "Nombre de la promoción: ";
            getline(cin, nombre);
            unsigned int i = 0;
            while ((i < nombrePromociones.size()) && (nombre.compare(nombrePromociones[i]) != 0))
                i++;
            if (i < nombrePromociones.size())
                cout << endl << "[ERROR] Nombre de promoción ya existente\n";
            else
                nombreInvalido = false;
        }
        /********************USUARIO INGRESA DESCRIPCIÓN*******************/
        string descripcion;
        cout << "Descripción: ";
        getline(cin, descripcion);
        /*********************USUARIO INGRESA DESCUENTO********************/
        int intDescuento;
        bool descuentoInvalido = true;
        while (descuentoInvalido) {
            cout << "Descuento (%): ";
            scanf("%d", &intDescuento);
            getline(cin, aux);
            if ((intDescuento < 1) || (intDescuento > 100))
                cout << endl << "[ERROR] Descuento inválido. Ingrese un número entre 1 y 100\n" << endl;
            else
                descuentoInvalido = false;
        }
        float descuento = 1 - ((float) intDescuento / 100);
        /********************USUARIO INGRESA VENCIMIENTO*******************/
        int* fecha = new int[3];
        bool fechaInvalida = true;
        while (fechaInvalida) {
            cout << "Fecha de vencimiento (dd/mm/aaaa): ";
            scanf("%d/%d/%d", &fecha[0], &fecha[1], &fecha[2]);
            getline(cin, aux);
            if ((fecha[0] > 31) || (fecha[0] < 1) || (fecha[1] > 12) || (fecha[1] < 1) || (fecha[2] < 1))
                cout << endl << "[ERROR] Fecha inválida\n" << endl;
            else
                fechaInvalida = false;
        }
        DataFecha vencimiento = DataFecha(fecha[0], fecha[1], fecha[2]);
        delete[] fecha;
        /*********************USUARIO INGRESA VENDEDOR*********************/
        vector<string> nicknameVendedores = iUsrs->vendedoresConProductoDisponible(fechaActual);
        for (unsigned int i = 0; i < nicknameVendedores.size(); i++)
            cout << endl << nicknameVendedores[i];
        cout << endl;
        string nickname;
        bool nicknameInvalido = true;
        while (nicknameInvalido) {
            cout << endl << "Vendedor: ";
            cin >> nickname;
            getline(cin, aux);
            unsigned int i = 0;
            while ((i < nicknameVendedores.size()) && (nickname.compare(nicknameVendedores[i]) != 0))
                i++;
            if (i < nicknameVendedores.size())
                nicknameInvalido = false;
            else
                cout << endl << "[ERROR] El vendedor '" << nickname << "' no existe o no tiene productos disponibles (sin promoción vigente)\n";
        }
        /*********************USUARIO INGRESA PRODUCTOS********************/
        vector<DataProdBasica> productosDisponibles = iUsrs->productosDisponiblesVendedor(nickname, fechaActual);
        vector<DataPromoProducto> productosPromocion;
        string codigoProducto, respuesta;
        int minimoProducto;
        bool productoInvalido, minimoInvalido, respuestaInvalida;
        bool continuar = true;
        while (continuar) {
            /**********************CÓDIGO DE PRODUCTO**********************/
            for (unsigned int i = 0; i < productosDisponibles.size(); i++)
                cout << endl << "[" << productosDisponibles[i].getCodigo() << "] " << productosDisponibles[i].getNombre();
            cout << endl;
            productoInvalido = true;
            while (productoInvalido) {
                cout << endl << "Producto a promocionar (prd#): ";
                cin >> codigoProducto;
                getline(cin, aux);
                unsigned int i = 0;
                while ((i < productosDisponibles.size()) && (codigoProducto.compare(productosDisponibles[i].getCodigo()) != 0))
                    i++;
                if (i < productosDisponibles.size()) {
                    productoInvalido = false;
                    productosDisponibles.erase(productosDisponibles.begin()+i);
                } else
                    cout << endl << "[ERROR] El producto '" << codigoProducto << "' no existe o no está disponible\n";
            }
            /******************CANTIDAD MÍNIMA DE PRODUCTO*****************/
            minimoInvalido = true;
            while (minimoInvalido) {
                cout << "Cantidad mínima de producto: ";
                scanf("%d", &minimoProducto);
                getline(cin, aux);
                if (minimoProducto > 0)
                    minimoInvalido = false;
                else
                    cout << endl << "[ERROR] Ingrese un entero mayor a cero\n" << endl;
            }
            /******************AGREGO PRODUCTO CON MÍNIMO******************/
            DataPromoProducto dPP = DataPromoProducto(codigoProducto, minimoProducto);
            productosPromocion.push_back(dPP);
            /*********************CONTINUAR O FINALIZAR********************/
            continuar = (!productosDisponibles.empty());
            respuestaInvalida = true;
            while ((respuestaInvalida) && (continuar)) {
                cout << "Ingrese 'c' para continuar agregando productos, 'f' para finalizar: ";
                cin >> respuesta;
                getline(cin,aux);
                if (respuesta.compare("c") == 0)
                    respuestaInvalida = false;
                else if (respuesta.compare("f") == 0) {
                    respuestaInvalida = false;
                    continuar = false;
                } else
                    cout << endl << "[ERROR] Entrada inválida\n" << endl;
            }
        }
        /************************ALTA DE PROMOCIÓN*************************/
        DataPromocion dPrm = DataPromocion(nickname, productosPromocion, nombre, descripcion, descuento, vencimiento);
        iPP->crearPromocion(dPrm);
        cout << endl << "Promoción ingresada con éxito\n";
    } else
        cout << endl << "[ERROR] No hay productos disponibles (sin promoción vigente) en sistema\n";
}

void main_consultarPromocion(IPromoProd* iPP, DataFecha fechaActual) {
    if (iPP->existePromoVigente(fechaActual)) {
        /**********************LISTADO DE PROMOCIONES**********************/
        vector<DataPromoConsulta> listadoPromociones = iPP->listarPromoVigentes(fechaActual);
        for (unsigned int i = 0; i < listadoPromociones.size(); i++) {
            cout << endl << "Nombre: " << listadoPromociones[i].getNombre() << endl; 
            cout << "Descripción: " << listadoPromociones[i].getDescripcion() << endl;
            float descuento = ((1 - listadoPromociones[i].getDescuento()) * 100);
            printf("Descuento: %.0f", descuento);
            cout << "%\n" << "Vencimiento: " << listadoPromociones[i].getVencimiento().toString() << endl;
        }
        /**********************CONTINUAR O FINALIZAR***********************/
        string respuesta, aux;
        bool respuestaInvalida = true;
        while (respuestaInvalida) {
            cout << endl << "Ingrese 'c' para consultar una promoción, 'f' para finalizar: ";
            cin >> respuesta;
            getline(cin, aux);
            if ((respuesta.compare("c") == 0) || (respuesta.compare("f") == 0))
                respuestaInvalida = false;
            else
                cout << endl << "[ERROR] Entrada inválida\n";
        }
        if (respuesta.compare("c") == 0) {
            /******************USUARIO INGRESA PROMOCIÓN*******************/
            string nombrePromocion;
            bool promocionInvalida = true;
            while (promocionInvalida) {
                cout << "Promoción: ";
                getline(cin, nombrePromocion);
                unsigned int i = 0;
                while ((i < listadoPromociones.size()) && (nombrePromocion.compare(listadoPromociones[i].getNombre()) != 0))
                    i++;
                if (i < listadoPromociones.size())
                    promocionInvalida = false;
                else
                    cout << endl << "[ERROR] No existe promoción '" << nombrePromocion << "' en sistema\n" << endl;
            }
            /****************IMPRIMIR VENDEDOR Y PRODUCTOS*****************/
            cout << endl << "Vendedor de la promoción: \n" << endl << iPP->infoVendedorPromocion(nombrePromocion) << endl; 
            vector<DataProductosPromo> infoProductos = iPP->infoProductosPromocion(nombrePromocion);
            cout << "Productos de la promoción:\n";
            for (unsigned int i = 0; i < infoProductos.size(); i++) {
                DataProductosPromo dpp = infoProductos[i];
                cout << endl << "Nombre: " << dpp.getNombreProducto() << endl;
                cout << "Descripción: " << dpp.getDescripcionProducto() << endl;
                cout << "Categoria: ";
                if (dpp.getCategoriaProducto() == ropa)
                    cout << "Ropa" << endl;
                else if (dpp.getCategoriaProducto() == electrodomestico)
                    cout << "Electrodoméstico" << endl;
                else
                    cout << "Otro" << endl;
                cout << "Stock: " << to_string(dpp.getStockProducto()) << endl;
                cout << "Precio: UYU ";
                printf("%.2f\n", dpp.getPrecioProducto());
                cout << "Mínimo para promoción: " << dpp.getMinimoProducto() << endl;
            }
        }
    } else
        cout << endl << "[ERROR] No existen promociones vigentes en el sistema\n";
}   