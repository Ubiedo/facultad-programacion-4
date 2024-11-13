#include "include/factory.h"
#include "iostream"

void main_comandos();
void main_datos(IUsuarios* iUsrs, IPromoProd* iPP);

//Casos de uso
void main_altaDeUsuario(IUsuarios* iUsrs);
void main_listarUsuarios(IUsuarios* iUsrs);
void main_altaDeProducto(IPromoProd* iPP);
void main_consultarProducto(IPromoProd* iPP);
void main_suscribirseANotificaciones(IUsuarios* iUsrs);
void main_consultarNotificaciones(IUsuarios* iUsrs);

int main() {
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    IPromoProd* iPP = f->getIPromoProd();

    cout << "Mercado Finger v1.0.2\n"
        << "En esta versión: Usuarios y Productos\n" << endl
        << "Programación 4 Curso 2024\n"
        << "Laboratorio 4 - Grupo 8: Federico González, Marcos Baptista, Matías Silvera, Roque Serrato y Juan Pablo Otero\n"
        << "Docente: Miguel Machado\n" << endl
        << "Ingrese 'comandos' para ver los comandos disponibles\n";

    string entrada, aux;
    bool continuar = true;
    while (continuar) {
        cout << endl << ">>";
        cin >> entrada;
        getline(cin, aux);
        if (entrada.compare("altaDeUsuario") == 0) {
            main_altaDeUsuario(iUsrs);
        } else
        if (entrada.compare("listarUsuarios") == 0) {
            main_listarUsuarios(iUsrs);
        } else
        if (entrada.compare("altaDeProducto") == 0) {
            main_altaDeProducto(iPP);
        } else
        if (entrada.compare("consultarProducto") == 0) {
            main_consultarProducto(iPP);
        } else
        if (entrada.compare("suscribirseANotificaciones") == 0) {
            main_suscribirseANotificaciones(iUsrs);
        } else
        if (entrada.compare("consultarNotificaciones") == 0) {
            main_consultarNotificaciones(iUsrs);
        } else
        if (entrada.compare("datos") == 0) {
            main_datos(iUsrs, iPP);
        } else
        if (entrada.compare("comandos") == 0) {
            main_comandos();
        } else
        if (entrada.compare("exit") == 0) {
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
    << "datos: Ingresa en el sistema clientes, vendedores y productos predeterminados\n" 
    << "exit: Libera la memoria y finaliza la ejecución\n"; 
}

void main_datos(IUsuarios* iUsrs, IPromoProd* iPP) {
    string aux;

    DataFecha fecha1 = DataFecha(13,1,2003);
    DataCliente dc1 = DataCliente("jp.otero", "abc123", fecha1, "Av. Alvear", 357, "Ciudad de la Costa");
    aux = iUsrs->crearCliente(dc1);

    DataFecha fecha2 = DataFecha(11,9,2001);
    DataCliente dc2 = DataCliente("darwin_nunez", "juguito", fecha2, "Calle X", 1111, "Liverpool");
    aux = iUsrs->crearCliente(dc2);

    DataFecha fecha3 = DataFecha(24,1,1987);
    DataCliente dc3 = DataCliente("lucho.suarez9", "bolso1899", fecha3, "Calle Y", 777, "Salto");
    aux = iUsrs->crearCliente(dc3);

    DataFecha fecha4 = DataFecha(9,12,2008);
    DataVendedor dv1 = DataVendedor("sazu4", "woof", fecha4, "0123456789");
    aux = iUsrs->crearVendedor(dv1);

    DataFecha fecha5 = DataFecha(1,1,1111);
    DataVendedor dv2 = DataVendedor("chinorochet", "contraseña123", fecha5, "9876543210");
    aux = iUsrs->crearVendedor(dv2);

    DataProducto dp1 = DataProducto("Corsita 1.6 2008", "tremenda maquina. pierde aceite pero bueno", otro, 1, 12000);
    iPP->crearProducto("chinorochet", dp1);

    DataProducto dp2 = DataProducto("juguito de naranja", "natural. sin conservantes. oportunidad unica!!!!!", otro, 28, 65);
    iPP->crearProducto("chinorochet", dp2);

    DataProducto dp3 = DataProducto("pelotita de tenis mordisqueada por sazu", "acepto permutas", otro, 1, 999999999);
    iPP->crearProducto("sazu4", dp3);

    cout << endl << "Datos cargados en sistema" << endl;
}

void main_altaDeUsuario(IUsuarios* iUsrs) {
    void main_auxAdeU(IUsuarios*, string);

    string entrada, aux;
    bool entradaInvalida = true;
    cout << endl;
    while (entradaInvalida) {
        cout << "Ingrese 'c' si el usuario es cliente, 'v' si es vendedor: ";
        cin >> entrada;
        getline(cin, aux);
        if ((entrada.compare("c") == 0) || (entrada.compare("v") == 0)) {
            entradaInvalida = false;
            main_auxAdeU(iUsrs, entrada);
        } else
            cout << "[ERROR] Entrada inválida\n";
    }
}

void main_auxAdeU(IUsuarios* iUsrs, string entrada) {
    string nickname, aux;
    cout << "Nickname: ";
    cin >> nickname;
    getline(cin, aux);

    string contrasena;
    bool contrasenaInvalida = true;
    while (contrasenaInvalida) {
        cout << "Contraseña: ";
        cin >> contrasena;
        getline(cin, aux);
        if (contrasena.size() < 6)
            cout << "[ERROR] Ingrese una contraseña con al menos seis caracteres\n";
        else
            contrasenaInvalida = false;
    }

    int* fecha = new int[3];
    bool fechaInvalida = true;
    while (fechaInvalida) {
        cout << "Fecha de nacimiento (dd/mm/aaaa): ";
        scanf("%d/%d/%d", &fecha[0], &fecha[1], &fecha[2]);
        getline(cin, aux);
        if ((fecha[0] > 31) || (fecha[0] < 1) || (fecha[1] > 12) || (fecha[1] < 1) || (fecha[2] < 1))
            cout << "[ERROR] Fecha inválida\n";
        else
            fechaInvalida = false;
    }
    DataFecha fechaNacimiento = DataFecha(fecha[0], fecha[1], fecha[2]);
    delete[] fecha;

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
        long long nroRut;
        string stringRut;
        bool rutInvalido = true;
        while (rutInvalido) {
            cout << "Número de rut: ";
            scanf("%lli", &nroRut);
            getline(cin, aux);

            stringRut = to_string(nroRut);
            if (stringRut.size() == 12)
                rutInvalido = false;
            else
                cout << "[ERROR] Número de rut debe tener doce caracteres numéricos\n";
        }

        DataVendedor dv = DataVendedor(nickname, contrasena, fechaNacimiento, stringRut);
        cout << endl << iUsrs->crearVendedor(dv);
    }
}

void main_listarUsuarios(IUsuarios* iUsrs) {
    vector<string> listadoUsuarios = iUsrs->listarUsuarios();
    unsigned int i;
    for (i = 0; i < listadoUsuarios.size(); i++)
        cout << endl << listadoUsuarios[i];
    if (i == 0) 
        cout << endl << "No hay usuarios en sistema\n";
}

void main_altaDeProducto(IPromoProd* iPP) {
    if (iPP->isEmptyVendedores())
        cout << endl << "[ERROR] No hay vendedores en sistema\n";
    else {
        vector<string> res = iPP->nicknameVendedores();
        cout << endl;
        for (unsigned int i = 0; i < res.size(); i++)
            cout << res[i] << endl;

        string nicknameVendedor, aux;
        bool nicknameInvalido = true;
        while (nicknameInvalido) {
            cout << endl << "Vendedor del producto: ";
            cin >> nicknameVendedor;
            getline(cin, aux);
            
            unsigned int i = 0;
            while ((i < res.size()) && (nicknameVendedor.compare(res[i]) != 0))
                i++;
            if (i < res.size())
                nicknameInvalido = false;
            else
                cout << endl << "[ERROR] No existe vendedor '" << nicknameVendedor << "'\n";
        }
        
        string nombre;
        cout << "Nombre: ";
        getline(cin, nombre);

        string descripcion;
        cout << "Descripcion: ";
        getline(cin, descripcion);

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

        int stock;
        cout << "Stock: ";
        scanf("%d", &stock);
        getline(cin, aux);

        float precio;
        cout << "Precio: ";
        scanf("%f", &precio);

        DataProducto dp = DataProducto(nombre, descripcion, categoria, stock, precio);
        iPP->crearProducto(nicknameVendedor, dp);

        cout << endl << "Producto ingresado con éxito\n";
    }
}

void main_consultarProducto(IPromoProd* iPP) {
    if (iPP->isEmptyProductos())
        cout << endl << "[ERROR] No hay productos en el sistema\n";
    else {
        vector<DataProdBasica> listadoProductos = iPP->listarProductos();
        for (unsigned int i = 0; i < listadoProductos.size(); i++)
            cout << endl << "[" << listadoProductos[i].getCodigo() << "] " << listadoProductos[i].getNombre();
        
        cout << endl;

        bool productoInvalido = true;
        string codigoProducto, aux;
        while (productoInvalido) {
            cout << endl << "Producto (vendedor_prodX): ";
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

void main_suscribirseANotificaciones(IUsuarios* iUsrs){
    string cliente, vendedor, condition;
    /***********************SELECCIONAR CLIENTE************************/
    cout << "Ingrese el nombre del cliente: ";
    getline(cin, cliente);
    /***********************BUCLE DE SUSCRIPCION***********************/
    while (condition != "No" && condition != "no"){
        iUsrs->getVendedoresNoSuscritos(cliente);
        cout << "Ingrese el nombre del vendedor a suscribir: ";
        getline(cin, vendedor);
        iUsrs->suscribirAlVendedor(cliente, vendedor);
        cout << "Desea suscribirlo a otro vendedor(si/no)";
        cin >> condition;
    }
    /***********************SUSCRIPCION REALIZADA************************/
}

void main_consultarNotificaciones(IUsuarios* iUsrs){
    string nickname;
    /***********************SELECCIONAR CLIENTE************************/
    cout << "Ingrese el nombre del cliente: ";
    getline(cin, nickname);
    /***********************BUCLE DE NOTIFICACION************************/
    set<DataNotificacion> notificaciones = iUsrs->getNotificacionesDeCliente(nickname);
    set<DataNotificacion>::iterator it;
    for (it = notificaciones.begin(); it != notificaciones.end(); ++it){
        DataNotificacion current = *it;
        cout << "Vendedor: " << current.getNickVendedor() << endl;
        cout << "Nombre de la promocion: " << current.getNombPromo() << endl;
        
        set<DataProducto> productos = current.getProductos();
        set<DataProducto>::iterator it2;
        for(it2 = productos.begin(); it2 != productos.end(); ++it2){
            DataProducto current2 = *it2;
            cout << "Nombre del producto: " << current2.getNombre() << endl;
            cout << "Categoria del producto: " << current2.getCategoria() << endl;
            cout << "Cantidad: " <<current2.getStock() << endl;
            cout << "Precio: " << current2.getPrecio() << endl;
        }
    }
    /***********************NOTIFICACIONES DESPLEGADAS************************/
    /***********************ELIMINAR NOTIFICACIONES************************/
    iUsrs->vaciarNotificaciones(nickname);
    /***********************NOTIFICACIONES ELIMINADAS************************/
}

void main_eliminarSuscripciones(IUsuarios* iUsrs){
    string cliente, vendedor, condition;
    /***********************SELECCIONAR CLIENTE************************/
    cout << "Ingrese el nombre del cliente: ";
    getline(cin, cliente);
    /***********************BUCLE DE SUSCRIPCION***********************/
    while (condition != "No" && condition != "no"){
        iUsrs->getSuscripcionesDeCliente(cliente);
        cout << "Ingrese el nombre del vendedor a desuscribir: ";
        getline(cin, vendedor);
        iUsrs->eliminarSuscripcionClienteAVendedor(cliente, vendedor);
        cout << "Desea eliminar otra suscripcion (si/no):";
        cin >> condition;
    }
    /***********************SUSCRIPCION REALIZADA************************/
}