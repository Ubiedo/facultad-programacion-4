#include "include/factory.h"
#include "iostream"

void main_comandos();
void main_usuariosPorDefecto(IUsuarios* iUsrs);
string main_altaDeUsuario(IUsuarios* iUsrs);

int main() {
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();

    cout << "Mercado Finger v1.0.1\n"
        << "En esta versión: Usuarios, Factory, IUsuarios\n"
        << endl << "Ingrese 'comandos' para ver los comandos disponibles\n";

    string entrada, aux;
    bool continuar = true;
    while (continuar) {
        cout << endl << ">>";
        cin >> entrada;
        getline(cin, aux);
        if (entrada.compare("altaDeUsuario") == 0) {
            cout << endl << main_altaDeUsuario(iUsrs);
        } else
        if (entrada.compare("listadoDeUsuarios") == 0) {
            vector<string> listadoUsuarios = iUsrs->listarUsuarios();
            for (unsigned int i = 0; i < listadoUsuarios.size(); i++)
                cout << endl << listadoUsuarios[i];
        } else
        if (entrada.compare("usuariosPorDefecto") == 0) {
            main_usuariosPorDefecto(iUsrs);
            cout << endl << "Usuarios cargados en sistema\n";
        } else
        if (entrada.compare("comandos") == 0) {
            main_comandos();
        } else
        if (entrada.compare("exit") == 0) {
            iUsrs->vaciarUsuarios();
            delete iUsrs;
            delete f;
            continuar = false;
        } else
            cout << endl << "[ERROR] Comando no reconocido. Ingrese 'comandos' para ver los comandos disponibles\n";
    }
    return 0;
}

void main_comandos() {
    cout << endl << "altaDeUsuario: Ingresa un nuevo usuario al sistema\n" 
    << "listadoDeUsuarios: Muestra los datos de todos los usuarios en sistema\n"
    << "usuariosPorDefecto: Ingresa en el sistema algunos usuarios pre-definidos\n" 
    << "exit: Libera la memoria y finaliza la ejecución\n"; 
}

void main_usuariosPorDefecto(IUsuarios* iUsrs) {
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
    DataVendedor dv1 = DataVendedor("sazu_4", "woof", fecha4, "0123456789");
    aux = iUsrs->crearVendedor(dv1);

    DataFecha fecha5 = DataFecha(1,1,1111);
    DataVendedor dv2 = DataVendedor("chinorochet", "contraseña123", fecha5, "9876543210");
    aux = iUsrs->crearVendedor(dv2);
}

string main_altaDeUsuario(IUsuarios* iUsrs) {
    string main_auxAdeU(IUsuarios*, string);

    string entrada, aux;
    bool entradaInvalida = true;
    while (entradaInvalida) {
        cout << "Ingrese 'c' si el usuario es cliente, 'v' si es vendedor: ";
        cin >> entrada;
        getline(cin, aux);
        if ((entrada.compare("c") == 0) || (entrada.compare("v") == 0)) {
            entradaInvalida = false;
            return (main_auxAdeU(iUsrs, entrada));
        } else
            cout << "[ERROR] Entrada inválida\n";
    }
    return ("[ERROR] Error inesperado\n");
}

string main_auxAdeU(IUsuarios* iUsrs, string entrada) {
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

        cout << endl;

        DataCliente dc = DataCliente(nickname, contrasena, fechaNacimiento, calle, nroPuerta, ciudad);
        return (iUsrs->crearCliente(dc));
    } else {
        string nroRut;
        cout << "Número de rut: ";
        cin >> nroRut;
        getline(cin, aux);

        cout << endl;

        DataVendedor dv = DataVendedor(nickname, contrasena, fechaNacimiento, nroRut);
        return (iUsrs->crearVendedor(dv));
    }
}