#include "include/factory.h"
#include "fechaSistema.h"
#include "iostream"

void main_datos();
void main_cambiarFechaSistema();
void main_comandos();

void main_altaDeUsuario();
void main_listarUsuarios();
void main_altaDeProducto();
void main_consultarProducto();
void main_dejarComentario();
void main_eliminarComentario();
void main_crearPromocion();
void main_consultarPromocion();
void main_suscribirseANotificaciones();
void main_consultarNotificaciones();
void main_eliminarSuscripciones();
void main_realizarCompra();
void main_enviarProducto();
void main_expedienteDeUsuario();

int main() {
    /*************************MENSAJE INICIAL**************************/
    cout << "Mercado Finger v2.0\n" << endl
        << "Programación 4 Curso 2024\n"
        << "Laboratorio 4 - Grupo 8: Federico González, Marcos Baptista, Matías Silvera, Roque Serrato y Juan Pablo Otero\n"
        << "Docente: Miguel Machado\n";
    /*********************OBTENER FECHA DE SISTEMA*********************/
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
    FechaSistema* fechaSistema = FechaSistema::getInstancia();
    fechaSistema->setFecha(fechaActual);
    delete[] fecha;
    /*******************MENSAJE DE BIENVENIDA Y MENÚ*******************/
    cout << endl << "¡Bienvenido a Mercado Finger! Ingrese 'comandos' para ejecutar un caso de uso\n";
    string entrada;
    bool continuar = true;
    while (continuar) {
        cout << endl << ">>";
        cin >> entrada;
        getline(cin, aux);
        if ((entrada.compare("altaDeUsuario") == 0) || (entrada.compare("1") == 0))
            main_altaDeUsuario();
        else if ((entrada.compare("listarUsuarios") == 0) || (entrada.compare("2") == 0))
            main_listarUsuarios();
        else if ((entrada.compare("altaDeProducto") == 0) || (entrada.compare("3") == 0))
            main_altaDeProducto();
        else if ((entrada.compare("consultarProducto") == 0) || (entrada.compare("4") == 0))
            main_consultarProducto();
        else if ((entrada.compare("dejarComentario") == 0) || (entrada.compare("5") == 0))
            main_dejarComentario();
        else if ((entrada.compare("eliminarComentario") == 0) || (entrada.compare("6") == 0))
            main_eliminarComentario();
        else if ((entrada.compare("crearPromocion") == 0) || (entrada.compare("7") == 0))
            main_crearPromocion();
        else if ((entrada.compare("consultarPromocion") == 0) || (entrada.compare("8") == 0))
            main_consultarPromocion();
        else if ((entrada.compare("suscribirseANotificaciones") == 0) || (entrada.compare("9") == 0))
            main_suscribirseANotificaciones();
        else if ((entrada.compare("consultarNotificaciones") == 0) || (entrada.compare("10") == 0))
            main_consultarNotificaciones();
        else if ((entrada.compare("eliminarSuscripciones") == 0) || (entrada.compare("11") == 0))
            main_eliminarSuscripciones();
        else if ((entrada.compare("realizarCompra") == 0) || (entrada.compare("12") == 0))
            main_realizarCompra();
        else if ((entrada.compare("enviarProducto") == 0) || (entrada.compare("13") == 0))
            main_enviarProducto();
        else if ((entrada.compare("expedienteDeUsuario") == 0) || (entrada.compare("14") == 0))
            main_expedienteDeUsuario();
        else if ((entrada.compare("datos") == 0) || (entrada.compare("15") == 0))
            main_datos();
        else if ((entrada.compare("cambiarFecha") == 0) || (entrada.compare("16") == 0))
            main_cambiarFechaSistema();
        else if (entrada.compare("comandos") == 0)
            main_comandos();
        else if ((entrada.compare("exit") == 0) || (entrada.compare("0") == 0)) {
            FechaSistema* fechaSistema = FechaSistema::getInstancia();
            Factory* f = Factory::getInstancia();
            IUsuarios* iUsrs = f->getIUsuarios();
            IPromoProd* iPP = f->getIPromoProd();
            delete fechaSistema;
            delete iUsrs;
            delete iPP;
            delete f;
            continuar = false;
        } else
            cout << endl << "[ERROR] Comando no reconocido. Ingrese 'comandos' para ver los comandos disponibles\n";
    }
    return 0;
}

void main_datos() {
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    IPromoProd* iPP = f->getIPromoProd();
    string aux;

    /*****************************USUARIOS*****************************/

    DataFecha fecha1 = DataFecha(15,5,1988);
    cout << endl << iUsrs->crearVendedor("ana23", "qwer1234", fecha1, "21234567800");

    DataFecha fecha2 = DataFecha(18,6,1986);
    cout << iUsrs->crearVendedor("carlos78", "asdfghj", fecha2, "356789012345");

    DataFecha fecha3 = DataFecha(28,7,1993);
    cout << iUsrs->crearVendedor("diegom", "zxcvbn", fecha3, "190123456789");

    DataFecha fecha4 = DataFecha(20,10,1992);
    cout << iUsrs->crearCliente("juan87", "1qaz2wsx", fecha4, "Av. 18 de Julio", "456", "Melo");

    DataFecha fecha5 = DataFecha(22,9,1979);
    cout << iUsrs->crearCliente("laura", "3edc4rfv", fecha5, "Rondeau", "1617", "Montevideo");

    DataFecha fecha6 = DataFecha(25,3,1985);
    cout << iUsrs->crearVendedor("maria01", "5tgb6yhn", fecha6, "321098765432");

    DataFecha fecha7 = DataFecha(14,4,1982);
    cout << iUsrs->crearCliente("natalia", "poiuyt", fecha7, "Paysandú", "2021", "Salto");

    DataFecha fecha8 = DataFecha(30,11,1995);
    cout << iUsrs->crearCliente("pablo10", "lkjhgv", fecha8, "Av. Rivera", "1819", "Mercedes");

    DataFecha fecha9 = DataFecha(12,8,1990);
    cout << iUsrs->crearCliente("roberto", "mnbvcx", fecha9, "Av. Brasil", "1011", "Montevideo");

    DataFecha fecha10 = DataFecha(07,12,1983);
    cout << iUsrs->crearVendedor("sofia25", "1234asdf", fecha10, "445678901234");

    /****************************PRODUCTOS*****************************/

    cout << endl << iPP->crearProducto("carlos78", "Camiseta Azul", "Camiseta de poliester, color azul", ropa, 50, 1400); //prd01

    cout << iPP->crearProducto("ana23", "Televisor LED", "Televisor LED 55 pulgadas", electrodomestico, 30, 40500); //prd02

    cout << iPP->crearProducto("carlos78", "Chaqueta de Cuero", "Chaqueta de cuero, color negro", ropa, 20, 699.99); //prd03

    cout << iPP->crearProducto("ana23", "Microondas Digital", "Microondas digital, 30L", electrodomestico, 15, 1199.99); //prd04

    cout << iPP->crearProducto("diegom", "Luz LED", "Luz Bluetooth LED", otro, 40, 599.99); //prd05

    cout << iPP->crearProducto("carlos78", "Pantalones Vaqueros", "Pantalones vaqueros, talla 32", ropa, 25, 60); //prd06

    cout << iPP->crearProducto("diegom", "Auriculares Bluetooth", "Auriculares bluethooth para celular", otro, 35, 199.99); //prd07

    cout << iPP->crearProducto("ana23", "Refrigerador", "Refrigerador de doble puerta", electrodomestico, 10, 15499); //prd08

    cout << iPP->crearProducto("ana23", "Cafetera", "Cafetera de goteo programable", electrodomestico, 50, 23000); //prd09

    cout << iPP->crearProducto("carlos78", "Zapatillas Deportivas", "Zapatillas para correr, talla 42", ropa, 20, 5500); //prd10

    cout << iPP->crearProducto("carlos78", "Mochila", "Mochila de viaje, 40L", otro, 30, 9000); //prd11

    cout << iPP->crearProducto("diegom", "Plancha de Ropa", "Plancha a vapor, 1500W", electrodomestico, 25, 2534); //prd12

    cout << iPP->crearProducto("sofia25", "Gorra", "Gorra para deportes, color rojo", ropa, 50, 200); //prd13

    cout << iPP->crearProducto("diegom", "Tablet", "Tablet Android de 10 pulgadas", electrodomestico, 15, 15000); //prd14

    cout << iPP->crearProducto("sofia25", "Reloj de Pared", "Reloj de pared vintage", otro, 20, 150.50); //prd15

    /***************************PROMOCIONES***************************/

    DataFecha fecha11 = DataFecha(25,10,2024);
    vector<DataProdCantidad> prodCant1;
    DataProdCantidad dpc1_1 = DataProdCantidad("prd02", 1);
    prodCant1.push_back(dpc1_1);
    DataProdCantidad dpc1_2 = DataProdCantidad("prd04", 1);
    prodCant1.push_back(dpc1_2);
    DataProdCantidad dpc1_3 = DataProdCantidad("prd08", 1);
    prodCant1.push_back(dpc1_3);
    cout << endl << iPP->crearPromocion("ana23", prodCant1, "Casa nueva", "Para que puedas ahorrar en la casa nueva", 0.7, fecha11); //prm01

    DataFecha fecha12 = DataFecha(26,10,2024);
    vector<DataProdCantidad> prodCant2;
    DataProdCantidad dpc2_1 = DataProdCantidad("prd03", 2);
    prodCant2.push_back(dpc2_1);
    DataProdCantidad dpc2_2 = DataProdCantidad("prd06", 3);
    prodCant2.push_back(dpc2_2);
    cout << iPP->crearPromocion("carlos78", prodCant2, "Fiesta", "Para que no te quedes sin ropa para las fiestas", 0.8, fecha12); //prm02

    DataFecha fecha13 = DataFecha(26,10,2024);
    vector<DataProdCantidad> prodCant3;
    DataProdCantidad dpc3_1 = DataProdCantidad("prd05", 2);
    prodCant3.push_back(dpc3_1);
    cout << iPP->crearPromocion("diegom", prodCant3, "Domotica", "Para modernizar tu casa", 0.9, fecha13); //prm03

    DataFecha fecha14 = DataFecha(26,3,2024);
    vector<DataProdCantidad> prodCant4;
    DataProdCantidad dpc4_1 = DataProdCantidad("prd14", 1);
    prodCant4.push_back(dpc4_1);
    cout << iPP->crearPromocion("diegom", prodCant4, "Liquidacion", "Hasta agotar stock", 0.9, fecha14); //prm04

    /*****************************COMPRAS*****************************/

    DataFecha fecha15 = DataFecha(1,5,2024);
    vector<DataProdCantidad> prodCant5;
    DataProdCantidad dpc5_1 = DataProdCantidad("prd02", 2);
    prodCant5.push_back(dpc5_1);
    DataProdCantidad dpc5_2 = DataProdCantidad("prd04", 1);
    prodCant5.push_back(dpc5_2);
    DataProdCantidad dpc5_3 = DataProdCantidad("prd08", 1);
    prodCant5.push_back(dpc5_3);
    cout << endl << iPP->realizarCompra("juan87", prodCant5, fecha15); //cmp01

    DataFecha fecha16 = DataFecha(1,5,2024);
    vector<DataProdCantidad> prodCant6;
    DataProdCantidad dpc6_1 = DataProdCantidad("prd05", 1);
    prodCant6.push_back(dpc6_1);
    cout << iPP->realizarCompra("juan87", prodCant6, fecha16); //cmp02

    DataFecha fecha17 = DataFecha(15,5,2024);
    vector<DataProdCantidad> prodCant7;
    DataProdCantidad dpc7_1 = DataProdCantidad("prd14", 10);
    prodCant7.push_back(dpc7_1);
    cout << iPP->realizarCompra("laura", prodCant7, fecha17); //cmp03

    DataFecha fecha18 = DataFecha(25,4,2024);
    vector<DataProdCantidad> prodCant8;
    DataProdCantidad dpc8_1 = DataProdCantidad("prd11", 1);
    prodCant8.push_back(dpc8_1);
    DataProdCantidad dpc8_2 = DataProdCantidad("prd12", 1);
    prodCant8.push_back(dpc8_2);
    DataProdCantidad dpc8_3 = DataProdCantidad("prd13", 1);
    prodCant8.push_back(dpc8_3);
    cout << iPP->realizarCompra("natalia", prodCant8, fecha18); //cmp04

    DataFecha fecha19 = DataFecha(20,5,2024);
    vector<DataProdCantidad> prodCant9;
    DataProdCantidad dpc9_1 = DataProdCantidad("prd03", 2);
    prodCant9.push_back(dpc9_1);
    DataProdCantidad dpc9_2 = DataProdCantidad("prd06", 3);
    prodCant9.push_back(dpc9_2);
    cout << iPP->realizarCompra("juan87", prodCant9, fecha19); //cmp05

    DataFecha fecha20 = DataFecha(12,5,2024);
    vector<DataProdCantidad> prodCant10;
    DataProdCantidad dpc10_1 = DataProdCantidad("prd01", 2);
    prodCant10.push_back(dpc10_1);
    cout << iPP->realizarCompra("laura", prodCant10, fecha20); //cmp06

    DataFecha fecha21 = DataFecha(13,5,2024);
    vector<DataProdCantidad> prodCant11;
    DataProdCantidad dpc11_1 = DataProdCantidad("prd01", 3);
    prodCant11.push_back(dpc11_1);
    cout << iPP->realizarCompra("natalia", prodCant11, fecha21); //cmp07

    DataFecha fecha22 = DataFecha(14,5,2024);
    vector<DataProdCantidad> prodCant12;
    DataProdCantidad dpc12_1 = DataProdCantidad("prd01", 4);
    prodCant12.push_back(dpc12_1);
    cout << iPP->realizarCompra("pablo10", prodCant12, fecha22); //cmp08

    DataFecha fecha23 = DataFecha(15,5,2024);
    vector<DataProdCantidad> prodCant13;
    DataProdCantidad dpc13_1 = DataProdCantidad("prd01", 5);
    prodCant13.push_back(dpc13_1);
    cout << iPP->realizarCompra("roberto", prodCant13, fecha23); //cmp09

    cout << endl << iPP->marcarComoEnviado("prd02", "cmp01");
    cout << iPP->marcarComoEnviado("prd05", "cmp02");
    cout << iPP->marcarComoEnviado("prd14", "cmp03");
    cout << iPP->marcarComoEnviado("prd11", "cmp04");
    cout << iPP->marcarComoEnviado("prd12", "cmp04");
    cout << iPP->marcarComoEnviado("prd13", "cmp04");
    cout << iPP->marcarComoEnviado("prd06", "cmp05");
    cout << iPP->marcarComoEnviado("prd01", "cmp07");

    /***************************COMENTARIOS***************************/

    DataFecha fecha24 = DataFecha(1,6,2024);
    cout << endl << iUsrs->crearComentario("prd01", "", "juan87", "¿La camiseta azul esta disponible en talla M?", fecha24); //cmt01

    DataFecha fecha25 = DataFecha(1,6,2024);
    cout << iUsrs->crearComentario("prd01", "cmt01", "carlos78", "Si, tenemos la camiseta azul en talla M.", fecha25); //cmt02

    DataFecha fecha26 = DataFecha(2,6,2024);
    cout << iUsrs->crearComentario("prd01", "cmt02", "laura", "¿Es de buen material? Me preocupa la durabilidad.", fecha26); //cmt03

    DataFecha fecha27 = DataFecha(2,6,2024);
    cout << iUsrs->crearComentario("prd01", "cmt03", "juan87", "He comprado antes y la calidad es buena.", fecha27); //cmt04

    DataFecha fecha28 = DataFecha(2,6,2024);
    cout << iUsrs->crearComentario("prd01","", "natalia", "¿Como es el ajuste? ¿Es ajustada o holgada?", fecha28); //cmt05

    DataFecha fecha29 = DataFecha(2,6,2024);
    cout << iUsrs->crearComentario("prd02", "", "laura", "¿Cual es la resolucion del Televisor LED?", fecha29); //cmt06

    DataFecha fecha30 = DataFecha(2,6,2024);
    cout << iUsrs->crearComentario("prd02", "cmt06", "ana23", "El televisor LED tiene una resolucion de 4K UHD", fecha30); //cmt07

    DataFecha fecha31 = DataFecha(3,6,2024);
    cout << iUsrs->crearComentario("prd02", "", "pablo10", "¿Tiene soporte para HDR10?", fecha31); //cmt08

    DataFecha fecha32 = DataFecha(3,6,2024);
    cout << iUsrs->crearComentario("prd02", "cmt08", "ana23", "Si, soporta HDR10.", fecha32); //cmt09

    DataFecha fecha33 = DataFecha(3,6,2024);
    cout << iUsrs->crearComentario("prd03", "", "natalia", "¿La chaqueta de cuero es resistente al agua?", fecha33); //cmt10

    DataFecha fecha34 = DataFecha(3,6,2024);
    cout << iUsrs->crearComentario("prd03", "cmt10", "carlos78", "No, la chaqueta de cuero no es resistente al agua", fecha34); //cmt11

    DataFecha fecha35 = DataFecha(4,6,2024);
    cout << iUsrs->crearComentario("prd03", "cmt10", "laura", "¿Viene en otros colores?", fecha35); //cmt12

    DataFecha fecha36 = DataFecha(4,6,2024);
    cout << iUsrs->crearComentario("prd03", "cmt12", "carlos78", "Si, tambien esta disponible en marron.", fecha36); //cmt13

    DataFecha fecha37 = DataFecha(4,6,2024);
    cout << iUsrs->crearComentario("prd03", "cmt10", "roberto", "¿Es adecuada para climas frios?", fecha37); //cmt14

    DataFecha fecha38 = DataFecha(4,6,2024);
    cout << iUsrs->crearComentario("prd04", "", "pablo10", "¿El microondas digital tiene funcion de descongelacion rapida?", fecha38); //cmt15

    DataFecha fecha39 = DataFecha(4,6,2024);
    cout << iUsrs->crearComentario("prd04", "cmt15", "ana23", "Si, el microondas digital incluye una funcion de descongelacion rapida.", fecha39); //cmt16

    DataFecha fecha40 = DataFecha(5,6,2024);
    cout << iUsrs->crearComentario("prd04", "cmt15", "natalia", "¿Cuantos niveles de potencia tiene?", fecha40); //cmt17

    DataFecha fecha41 = DataFecha(5,6,2024);
    cout << iUsrs->crearComentario("prd04", "cmt17", "ana23", "Tiene 10 niveles de potencia. ", fecha41); //cmt18

    DataFecha fecha42 = DataFecha(5,6,2024);
    cout << iUsrs->crearComentario("prd04", "cmt15", "roberto", "¿Es facil de limpiar?", fecha42); //cmt19
    
    DataFecha fecha43 = DataFecha(5,6,2024);
    cout << iUsrs->crearComentario("prd05", "", "roberto", "¿La luz LED se puede controlar con una aplicacion movil?", fecha43); //cmt20

    DataFecha fecha44 = DataFecha(5,6,2024);
    cout << iUsrs->crearComentario("prd05", "cmt20", "diegom", "Si, la luz LED se puede controlar a traves de una aplicacion movil.", fecha44); //cmt21

    DataFecha fecha45 = DataFecha(6,6,2024);
    cout << iUsrs->crearComentario("prd05", "cmt20", "pablo10", "¿Es compatible con Alexa o Google Home?", fecha45); //cmt22

    DataFecha fecha46 = DataFecha(6,6,2024);
    cout << iUsrs->crearComentario("prd05", "cmt22", "diegom", "Si, es compatible con ambos.", fecha46); //cmt23

    DataFecha fecha47 = DataFecha(6,6,2024);
    cout << iUsrs->crearComentario("prd05", "cmt20", "natalia", "¿Cuanto dura la bateria?", fecha47); //cmt24
    
    DataFecha fecha48 = DataFecha(7,6,2024);
    cout << iUsrs->crearComentario("prd05", "cmt20", "pablo10", "¿La aplicacion movil es facil de usar?", fecha48); //cmt25

    cout << endl << "Datos cargados en sistema\n";
}

void main_cambiarFechaSistema() {
    string aux;
    int* fecha = new int[3];
    bool fechaInvalida = true;
    while (fechaInvalida) {
        cout << endl << "Fecha actual: (dd/mm/aaaa): ";
        scanf("%d/%d/%d", &fecha[0], &fecha[1], &fecha[2]);
        getline(cin, aux);
        if ((fecha[0] > 31) || (fecha[0] < 1) || (fecha[1] > 12) || (fecha[1] < 1) || (fecha[2] < 1))
            cout << endl << "[ERROR] Fecha inválida\n";
        else
            fechaInvalida = false;
    }
    DataFecha dF = DataFecha(fecha[0], fecha[1], fecha[2]);
    FechaSistema* fechaSistema = FechaSistema::getInstancia();
    fechaSistema->setFecha(dF);
    delete[] fecha;
    cout << endl << "Fecha cambiada a " << dF.toString() << endl;
    cout << endl << "[ADVERTENCIA] Cambiar la fecha actual puede provocar que ciertos productos pertenezcan a más \nde una promoción vigente, sin embargo solamente tendrán efecto en la más reciente de ellas\n";
}

void main_comandos() {
    cout << endl << "[1] altaDeUsuario: Ingresa un nuevo usuario al sistema\n" 
    << "[2] listarUsuarios: Muestra los datos de todos los usuarios en sistema\n"
    << "[3] altaDeProducto: Ingresa un nuevo producto al sistema\n"
    << "[4] consultarProducto: Muestra la información de un producto seleccionado\n"
    << "[5] dejarComentario: Comenta un producto o responde a un comentario existente\n"
    << "[6] eliminarComentario: Elimina un comentario y todas sus respuestas en cascada\n"
    << "[7] crearPromocion: Ingresa una nueva promoción al sistema\n" 
    << "[8] consultarPromocion: Muestra los datos del vendedor y la información de todos los productos de una promoción\n"
    << "[9] suscribirseANotificaciones: Suscribe un cliente a uno o varios vendedores\n"
    << "[10] consultarNotificaciones: Muestra las notificaciones nuevas de un cliente\n"
    << "[11] eliminarSuscripciones: Elimina una o varias suscripciones de un cliente\n"
    << "[12] realizarCompra: Ingresa una nueva compra de uno o varios productos, según las promocines vigentes\n"
    << "[13] enviarProducto: Marca un envío pendiente como entregado\n"
    << "[14] expedienteDeUsuario: Muestra información de actividad en el sistema de un usuario\n"
    << endl <<"[15] datos: Ingresa en el sistema datos predeterminados\n" 
    << "[16] cambiarFecha: Cambia la fecha actual\n"
    << endl << "[0] exit: Libera la memoria y finaliza la ejecución\n"; 
}

void main_altaDeUsuario() {
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
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

                string nroPuerta;
                cout << "Número de puerta: ";
                cin >> nroPuerta;
                getline(cin, aux);

                string ciudad;
                cout << "Ciudad: ";
                getline(cin, ciudad);

                cout << endl << iUsrs->crearCliente(nickname, contrasena, fechaNacimiento, calle, nroPuerta, ciudad);
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
                cout << endl << iUsrs->crearVendedor(nickname, contrasena, fechaNacimiento, stringRut);
            }
        } else
            cout << endl << "[ERROR] Entrada inválida\n";
    }
}

void main_listarUsuarios() {
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    vector<DataCliente> listadoClientes = iUsrs->listarClientes();
    vector<DataVendedor> listadoVendedores = iUsrs->listarVendedores();
    if ((listadoClientes.size() == 0) && (listadoVendedores.size() == 0))
        cout << endl << "No hay usuarios en sistema\n";
    else {
        if (listadoClientes.size() != 0) {
            cout << endl << "Clientes en sistema:\n";
            for (unsigned int i = 0; i < listadoClientes.size(); i++) {
                DataCliente dCl = listadoClientes[i];
                cout << endl << "Nickname: " << dCl.getNickname() << endl;
                cout << "Fecha de nacimiento: " << dCl.getFechaNacimiento().toString() << endl;
                cout << "Dirección: " << dCl.getCalle() << " " << dCl.getNroPuerta() << endl;
                cout << "Ciudad: " << dCl.getCiudad() << endl;
            }
        }
        if (listadoVendedores.size() != 0) {
            cout << endl << "Vendedores en sistema:\n";
            for (unsigned int i = 0; i < listadoVendedores.size(); i++) {
                DataVendedor dVd = listadoVendedores[i];
                cout << endl << "Nickname: " << dVd.getNickname() << endl;
                cout << "Fecha de nacimiento: " << dVd.getFechaNacimiento().toString() << endl;
                cout << "Número de RUT: " << dVd.getNroRut() << endl;
            }
        }
    }
}

void main_altaDeProducto() {
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    IPromoProd* iPP = f->getIPromoProd();
    vector<string> nicknameVendedores = iUsrs->nicknameVendedores();
    if (nicknameVendedores.size() == 0)
        cout << endl << "No hay vendedores en sistema\n";
    else {
        for (unsigned int i = 0; i < nicknameVendedores.size(); i++)
            cout << endl << nicknameVendedores[i];
        /*********************USUARIO INGRESA VENDEDOR*********************/
        cout << endl;
        string nickname, aux;
        bool nicknameInvalido = true;
        while (nicknameInvalido) {
            cout << endl << "Vendedor del producto: ";
            cin >> nickname;
            getline(cin, aux);
            unsigned int i = 0;
            while ((i < nicknameVendedores.size()) && (nickname.compare(nicknameVendedores[i]) != 0))
                i++;
            if (i < nicknameVendedores.size())
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
        bool categoriaInvalida = true;
        Categoria categoria = otro;
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
        bool stockInvalido = true;
        while (stockInvalido) {
            cout << "Stock: ";
            scanf("%d", &stock);
            getline(cin, aux);
            if (stock < 0)
                cout << endl << "[ERROR] Stock inválido\n" << endl;
            else
                stockInvalido = false;
        }
        /***********************USUARIO INGRESA PRECIO**********************/
        float precio;
        bool precioInvalido = true;
        while (precioInvalido) {
            cout << "Precio: UYU ";
            scanf("%f", &precio);
            getline(cin, aux);
            if (precio < 0)
                cout << endl << "[ERROR] Precio inválido\n" << endl;
            else
                precioInvalido = false;
        }
        /**************************ALTA DE PRODUCTO*************************/
        cout << endl << iPP->crearProducto(nickname, nombre, descripcion, categoria, stock, precio);
    }
}

void main_consultarProducto() {
    Factory* f = Factory::getInstancia();
    IPromoProd* iPP = f->getIPromoProd();
    vector<DataProdBasica> listadoProductos = iPP->listarProductos();
    if (listadoProductos.size() == 0)
        cout << endl << "No hay productos en sistema\n";
    else {
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
        printf("Precio: UYU %.2f\n", dpc.getPrecio());
    }
}

void main_dejarComentario() {
    FechaSistema* fechaSistema = FechaSistema::getInstancia();
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    IPromoProd* iPP = f->getIPromoProd();
    vector<string> nicknameUsuarios = iUsrs->nicknameUsuarios();
    vector<DataProdBasica> listadoProductos = iPP->listarProductos();
    if (nicknameUsuarios.size() == 0)
        cout << endl << "No hay usuarios en sistema\n";
    else  if (listadoProductos.size() == 0)
        cout << endl << "No hay productos en sistema\n";
    else {
        /*********************USUARIO INGRESA NICKNAME*********************/
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
        vector<DataComentario> comentariosDeProducto = iPP->comentariosDeProducto(codigoProducto);
        string respuesta = "n"; 
        bool respuestaInvalida = true;
        if (comentariosDeProducto.size() != 0) {
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
            for (unsigned int i = 0; i < comentariosDeProducto.size(); i++)
                cout << endl << comentariosDeProducto[i].getStrComentario() << endl;
            bool codigoInvalido = true;
            while (codigoInvalido) {
                cout << endl << "Comentario (cmt#): ";
                cin >> codigoPadre;
                getline(cin, aux);
                unsigned int i = 0;
                while ((i < comentariosDeProducto.size()) && (codigoPadre.compare(comentariosDeProducto[i].getCodigo()) != 0))
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
        cout << endl << iUsrs->crearComentario(codigoProducto, codigoPadre, nickname, texto, fechaSistema->getFecha());
    }
}

void main_eliminarComentario() {
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    vector<string> nicknameUsuarios = iUsrs->usuariosConComentarios();
    if (nicknameUsuarios.size() == 0)
        cout << endl << "No hay comentarios en sistema\n";
    else {
        /*********************USUARIO INGRESA NICKNAME*********************/
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
        vector<DataComentario> comentariosDeUsuario = iUsrs->comentariosDeUsuario(nickname);
        for (unsigned int i = 0; i < comentariosDeUsuario.size(); i++)
            cout << endl << comentariosDeUsuario[i].getStrComentario() << endl;
        string codigoComentario;
        bool codigoInvalido = true;
        while (codigoInvalido) {
            cout << endl << "Comentario (cmt#): ";
            cin >> codigoComentario;
            getline(cin, aux);
            unsigned int i = 0;
            while ((i < comentariosDeUsuario.size()) && (codigoComentario.compare(comentariosDeUsuario[i].getCodigo()) != 0))
                i++;
            if (i < comentariosDeUsuario.size())
                codigoInvalido = false;
            else
                cout << endl << "[ERROR] No existe comentario de " << nickname << " con código '" << codigoComentario << "'\n";
        }
        /***********************ELIMINAR COMENTARIO************************/
        cout << endl << iUsrs->eliminarComentario(nickname, codigoComentario);
    }
}

void main_crearPromocion() {
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    IPromoProd* iPP = f->getIPromoProd();
    FechaSistema* fechaSistema = FechaSistema::getInstancia();
    vector<string> nicknameVendedores = iUsrs->vendedoresConProductoDisponible(fechaSistema->getFecha());
    if (nicknameVendedores.size() != 0) {
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
        vector<DataProdBasica> productosDisponibles = iUsrs->productosDisponiblesVendedor(nickname, fechaSistema->getFecha());
        vector<DataProdCantidad> productosPromocion;
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
                    productosDisponibles.erase(productosDisponibles.begin() + i);
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
            DataProdCantidad dPP = DataProdCantidad(codigoProducto, minimoProducto);
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
        cout << endl << iPP->crearPromocion(nickname, productosPromocion, nombre, descripcion, descuento, vencimiento);
    } else
        cout << endl << "No hay productos disponibles (sin promoción vigente) en sistema\n";
}

void main_consultarPromocion() {
    FechaSistema* fechaSistema = FechaSistema::getInstancia();
    Factory* f = Factory::getInstancia();
    IPromoProd* iPP = f->getIPromoProd();
    vector<DataPromoConsulta> listadoPromociones = iPP->listarPromoVigentes(fechaSistema->getFecha());
    if (listadoPromociones.size() != 0) {
        /**********************LISTADO DE PROMOCIONES**********************/
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
            cout << endl << "Vendedor de la promoción: \n"; 
            DataVendedor dV = iPP->infoVendedorPromo(nombrePromocion);
            cout << endl << "Nickname: " << dV.getNickname() << endl;
            cout << "Fecha de nacimiento: " << dV.getFechaNacimiento().toString() << endl;
            cout << "Número de RUT: " << dV.getNroRut() << endl;
            vector<DataProdPromo> infoProductos = iPP->infoProductosPromo(nombrePromocion);
            cout << endl << "Productos de la promoción:\n";
            string strCategoria;
            for (unsigned int i = 0; i < infoProductos.size(); i++) {
                cout << endl << "Nombre: " << infoProductos[i].getNombre() << endl;
                cout << "Descripción: " << infoProductos[i].getDescripcion() << endl;
                if (infoProductos[i].getCategoria() == ropa)
                    strCategoria = "Ropa";
                else if (infoProductos[i].getCategoria() == electrodomestico)
                    strCategoria = "Electrodoméstico";
                else
                    strCategoria = "Otro";
                cout << "Categoría: " << strCategoria << endl;
                printf("Stock: %d\n", infoProductos[i].getStock());
                printf("Precio: UYU %.2f\n", infoProductos[i].getPrecio());
                printf("Mínimo para promoción: %d\n", infoProductos[i].getMinimo());
            }
        }
    } else
        cout << endl << "No existen promociones vigentes en el sistema\n";
}

void main_suscribirseANotificaciones() {
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    vector<string> nicknameClientes = iUsrs->nicknameClientes();
    if (!nicknameClientes.empty()) {
        cout << endl;
        for (unsigned int i = 0; i < nicknameClientes.size(); i++)
            cout << nicknameClientes[i] << endl;
        /**********************USUARIO INGRESA CLIENTE*********************/
        string nicknameCliente, aux;
        bool clienteInvalido = true;
        while (clienteInvalido) {
            cout << endl << "Cliente: ";
            cin >> nicknameCliente;
            getline(cin, aux);
            unsigned int i = 0;
            while ((i < nicknameClientes.size()) && (nicknameCliente.compare(nicknameClientes[i]) != 0))
                i++;
            if (i < nicknameClientes.size())
                clienteInvalido = false;
            else
                cout << endl << "[ERROR] No existe el cliente '" << nicknameCliente << "'\n";
        }
        /********************USUARIO INGRESA VENDEDORES********************/
        vector<string> nicknameVendedores = iUsrs->vendedoresParaSuscripcion(nicknameCliente);
        if (nicknameVendedores.size() != 0) {
            vector<string> suscripciones;
            string nicknameVendedor, respuesta;
            bool vendedorInvalido, respuestaInvalida;
            bool continuarSuscribiendo = true;
            while (continuarSuscribiendo) {
                cout << endl;
                for (unsigned int i = 0; i < nicknameVendedores.size(); i++)
                    cout << nicknameVendedores[i] << endl;
                vendedorInvalido = true;
                while (vendedorInvalido) {
                    cout << endl << "Vendedor a suscribir: ";
                    cin >> nicknameVendedor;
                    getline(cin, aux);
                    unsigned int i = 0;
                    while ((i < nicknameVendedores.size()) && (nicknameVendedor.compare(nicknameVendedores[i]) != 0))
                        i++;
                    if (i < nicknameVendedores.size()) {
                        vendedorInvalido = false;
                        suscripciones.push_back(nicknameVendedor);
                        nicknameVendedores.erase(nicknameVendedores.begin() + i);
                    } else
                        cout << endl << "[ERROR] El vendedor '" << nicknameVendedor << "' no existe o no está disponible para suscripción\n";
                }
                /******************CONTINUAR O FINALIZAR*******************/
                continuarSuscribiendo = !nicknameVendedores.empty();
                respuestaInvalida = true;
                while ((respuestaInvalida) && (continuarSuscribiendo)) {
                    cout << "Ingrese 'c' para continuar realizando suscripciones, 'f' para finalizar: ";
                    cin >> respuesta;
                    getline(cin, aux);
                    if (respuesta.compare("c") == 0)
                        respuestaInvalida = false;
                    else if (respuesta.compare("f") == 0) {
                        respuestaInvalida = false;
                        continuarSuscribiendo = false;
                    } else
                        cout << endl << "[ERROR] Entrada inválida\n" << endl;
                }
            }
            /********************REALIZAR SUSCRIPCIONES********************/
            cout << endl << iUsrs->realizarSuscripciones(nicknameCliente, suscripciones);
        } else
            cout << endl << "El cliente " << nicknameCliente << " no tiene vendedores disponibles para suscribirse\n";
    } else
        cout << endl << "No hay clientes en sistema\n";
}

void main_consultarNotificaciones() {
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    vector<string> nicknameClientes = iUsrs->nicknameClientes();
    if (nicknameClientes.size() != 0) {
        cout << endl;
        for (unsigned int i = 0; i < nicknameClientes.size(); i++)
            cout << nicknameClientes[i] << endl;
        /**********************USUARIO INGRESA CLIENTE*********************/
        string nicknameCliente, aux;
        bool clienteInvalido = true;
        while (clienteInvalido) {
            cout << endl << "Cliente: ";
            cin >> nicknameCliente;
            getline(cin, aux);
            unsigned int i = 0;
            while ((i < nicknameClientes.size()) && (nicknameCliente.compare(nicknameClientes[i]) != 0))
                i++;
            if (i < nicknameClientes.size())
                clienteInvalido = false;
            else
                cout << endl << "[ERROR] No existe el cliente '" << nicknameCliente << "'\n";
        }
        /******************IMPRIMIR Y BORRAR NOTIFICACIONES****************/
        vector<DataNotificacion> notificacionesCliente = iUsrs->notificacionesCliente(nicknameCliente);
        if (notificacionesCliente.size() != 0)
            for (unsigned int i = 0; i < notificacionesCliente.size(); i++) {
                DataNotificacion dN = notificacionesCliente[i];
                vector<DataProdBasica> productosPromo = dN.getProductosPromo();
                cout << endl << "Nueva promoción de " << dN.getNicknameVendedor() << ": '" << dN.getNombrePromo() << "'\n";
                cout << "Productos de la promoción:\n" << endl;
                for (unsigned int j = 0; j < productosPromo.size(); j++)
                    cout << "[" << productosPromo[j].getCodigo() << "] " << productosPromo[j].getNombre() << endl;
            }
        else
            cout << endl << "No hay notificaciones nuevas\n";
    } else
        cout << endl << "No hay clientes en sistema\n";
}

void main_eliminarSuscripciones() {
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    vector<string> nicknameClientes = iUsrs->nicknameClientes();
    if (nicknameClientes.size() != 0) {
        cout << endl;
        for (unsigned int i = 0; i < nicknameClientes.size(); i++)
            cout << nicknameClientes[i] << endl;
        /**********************USUARIO INGRESA CLIENTE*********************/
        string nicknameCliente, aux;
        bool clienteInvalido = true;
        while (clienteInvalido) {
            cout << endl << "Cliente: ";
            cin >> nicknameCliente;
            getline(cin, aux);
            unsigned int i = 0;
            while ((i < nicknameClientes.size()) && (nicknameCliente.compare(nicknameClientes[i]) != 0))
                i++;
            if (i < nicknameClientes.size())
                clienteInvalido = false;
            else
                cout << endl << "[ERROR] No existe el cliente '" << nicknameCliente << "'\n";
        }
        /********************USUARIO INGRESA VENDEDORES********************/
        vector<string> nicknameVendedores = iUsrs->suscripcionesDeCliente(nicknameCliente);
        if (nicknameVendedores.size() != 0) {
            vector<string> suscripcionesAEliminar;
            string nicknameVendedor, respuesta;
            bool vendedorInvalido, respuestaInvalida;
            bool continuarEliminando = true;
            while (continuarEliminando) {
                cout << endl;
                for (unsigned int i = 0; i < nicknameVendedores.size(); i++)
                    cout << nicknameVendedores[i] << endl;
                vendedorInvalido = true;
                while (vendedorInvalido) {
                    cout << endl << "Suscripcion a eliminar: ";
                    cin >> nicknameVendedor;
                    getline(cin, aux);
                    unsigned int i = 0;
                    while ((i < nicknameVendedores.size()) && (nicknameVendedor.compare(nicknameVendedores[i]) != 0))
                        i++;
                    if (i < nicknameVendedores.size()) {
                        vendedorInvalido = false;
                        suscripcionesAEliminar.push_back(nicknameVendedor);
                        nicknameVendedores.erase(nicknameVendedores.begin() + i);
                    } else
                        cout << endl << "[ERROR] El cliente " << nicknameCliente << " no está suscrito a '" << nicknameVendedor << "'\n";
                }
                /********************CONTINUAR O FINALIZAR*********************/
                continuarEliminando = !nicknameVendedores.empty();
                respuestaInvalida = true;
                while ((respuestaInvalida) && (continuarEliminando)) {
                    cout << "Ingrese 'c' para continuar eliminando suscripciones, 'f' para finalizar: ";
                    cin >> respuesta;
                    getline(cin, aux);
                    if (respuesta.compare("c") == 0)
                        respuestaInvalida = false;
                    else if (respuesta.compare("f") == 0) {
                        respuestaInvalida = false;
                        continuarEliminando = false;
                    } else
                        cout << endl << "[ERROR] Entrada inválida\n" << endl;
                }
            }
            cout << endl << iUsrs->eliminarSuscripciones(nicknameCliente, suscripcionesAEliminar);
        } else
            cout << endl << "El cliente " << nicknameCliente << " no tiene suscripciones\n";
    } else
        cout << endl << "No hay clientes en sistema\n";
}

void main_realizarCompra() {
    FechaSistema* fechaSistema = FechaSistema::getInstancia();
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    IPromoProd* iPP = f->getIPromoProd();
    vector<DataProdCompra> productosDisponibles = iPP->listarProductosDisponibles();
    if (productosDisponibles.size() == 0)
        cout << endl << "No hay productos disponibles en sistema\n";
    else {
        vector<string> nicknameClientes = iUsrs->nicknameClientes();
        if (nicknameClientes.size() == 0) 
            cout << endl << "No hay clientes en sistema\n";
        else {
            for (unsigned int i = 0; i < nicknameClientes.size(); i++)
                cout << endl << nicknameClientes[i];
            cout << endl;
            /**********************USUARIO INGRESA CLIENTE*********************/
            string nicknameCliente, aux;
            bool clienteInvalido = true;
            while (clienteInvalido) {
                cout << endl << "Cliente: ";
                cin >> nicknameCliente;
                getline(cin, aux);
                unsigned int i = 0;
                while ((i < nicknameClientes.size()) && (nicknameCliente.compare(nicknameClientes[i]) != 0))
                    i++;
                if (i < nicknameClientes.size())
                    clienteInvalido = false;
                else
                    cout << endl << "[ERROR] No existe cliente '" << nicknameCliente << "'\n";
            }
            /*********************USUARIO INGRESA PRODUCTOS********************/
            vector<DataProdCantidad> productosCompra;
            string codigoProducto, respuesta;
            int cantidadProducto;
            bool productoInvalido, respuestaInvalida;
            bool continuar = true;
            while (continuar) {
                /*********************PRODUCTO EN CANTIDAD*********************/
                cout << endl;
                for (unsigned int i = 0; i < productosDisponibles.size(); i++)
                    cout << "[" << productosDisponibles[i].getCodigo() << "] " << productosDisponibles[i].getNombre() << " (" << to_string(productosDisponibles[i].getStock()) << " unidad(es) en stock)\n";
                productoInvalido = true;
                while (productoInvalido) {
                    cout << endl << "Producto a comprar (prd#): ";
                    cin >> codigoProducto;
                    getline(cin, aux);
                    cout << "Cantidad de producto a comprar: ";
                    scanf("%d", &cantidadProducto);
                    getline(cin, aux);
                    unsigned int i = 0;
                    while ((i < productosDisponibles.size()) && (codigoProducto.compare(productosDisponibles[i].getCodigo()) != 0))
                        i++;
                    if (i < productosDisponibles.size())
                        if (cantidadProducto <= productosDisponibles[i].getStock()) {
                            productoInvalido = false;
                            productosDisponibles.erase(productosDisponibles.begin()+i);
                        } else
                            cout << endl << "[ERROR] Stock insuficiente\n";
                    else
                        cout << endl << "[ERROR] El producto '" << codigoProducto << "' no existe o no está disponible\n";
                }
                /*****************AGREGO PRODUCTO CON CANTIDAD*****************/
                DataProdCantidad dPP = DataProdCantidad(codigoProducto, cantidadProducto);
                productosCompra.push_back(dPP);
                /*********************CONTINUAR O FINALIZAR********************/
                continuar = (!(productosDisponibles.empty()));
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
            /************************DETALLES DE COMPRA************************/
            DataCompra dCmp = iPP->getDetallesCompra(productosCompra, fechaSistema->getFecha());
            vector<DataProdPrecio> infoProductos = dCmp.getProductos();
            cout << endl << "Detalles de su compra:\n";
            for (unsigned int i = 0; i < infoProductos.size(); i++) {
                cout << "--------------------------" << endl;
                cout << "x" << to_string(infoProductos[i].getCantidad()) << " [" << infoProductos[i].getCodigo() << "] " << infoProductos[i].getNombre() << endl;
                cout << "Descuento: ";
                if (infoProductos[i].getDescuento() == 0)
                    cout << "No aplica\n";
                else {
                    float descuentoPorcentaje = (1 - infoProductos[i].getDescuento()) * 100;
                    printf("%.0f%%\n", descuentoPorcentaje);
                }
                printf("Subtotal: UYU %.2f\n", infoProductos[i].getSubtotal());
            }
            cout << "--------------------------" << endl;
            cout << "Fecha: " << fechaSistema->getFecha().toString() << endl;
            printf("Monto final: UYU %.2f\n", dCmp.getMonto());
            /***********************CONFIRMAR O CANCELAR***********************/
            respuestaInvalida = true;
            while (respuestaInvalida) {
                cout << endl << "Ingrese 'confirmar' para realizar la compra, 'cancelar' para anularla: ";
                cin >> respuesta;
                getline(cin,aux);
                if (respuesta.compare("confirmar") == 0) {
                    continuar = true;
                    respuestaInvalida = false;
                } else if (respuesta.compare("cancelar") == 0) {
                    continuar = false;
                    respuestaInvalida = false;
                } else
                    cout << endl << "[ERROR] Entrada inválida\n";
            }
            if (continuar) {
                cout << endl << iPP->realizarCompra(nicknameCliente, productosCompra, fechaSistema->getFecha());
            } else
                cout << endl << "Compra anulada\n";
        }
    }
}

void main_enviarProducto() {
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    IPromoProd* iPP = f->getIPromoProd();
    vector<string> nicknameVendedores = iUsrs->nicknameVendedores();
    if (nicknameVendedores.size() == 0)
        cout << endl << "No hay vendedores en sistema\n";
    else {
        for (unsigned int i = 0; i < nicknameVendedores.size(); i++)
            cout << endl << nicknameVendedores[i];
        /***********************SELECCIONAR VENDEDOR***********************/
        cout << endl;
        string nickname, aux;
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
                cout << endl << "[ERROR] No existe vendedor '" << nickname << "'\n";
        }
        /***********************SELECCIONAR PRODUCTO***********************/
        vector<DataProdBasica> productos = iUsrs->enviosPendientesVendedor(nickname);
        if (productos.size() == 0)
            cout << endl << "El vendedor " << nickname << " no tiene productos pendientes de envío\n";
        else {
            cout << endl << "Productos con envíos pendientes de " << nickname <<":\n" << endl;
            for (unsigned int i = 0; i < productos.size(); i++)
                cout << "[" << productos[i].getCodigo() << "] " << productos[i].getNombre() << endl;
            string codigo;
            bool procesoInvalido = true;
            while (procesoInvalido) {
                cout << endl << "Producto (prd#): ";
                cin >> codigo;
                getline(cin, aux);
                unsigned int i = 0;
                while ((i < productos.size()) && (codigo.compare(productos[i].getCodigo()) != 0))
                    i++;
                if (i < productos.size())
                    procesoInvalido = false;
                else
                    cout << endl << "[ERROR] No hay producto de código '" << codigo << "' con envíos pendientes de " << nickname << endl;
            }
            /*****************SELECCIONAR SOLICITUD DE ENVIO*******************/
            vector<DataCompraPendiente> solicitudes = iPP->comprasPendientesProducto(codigo);
            cout << endl << "Solicitudes de envío pendiente del producto [" << codigo <<"]:\n" << endl;
            for (unsigned int i = 0; i < solicitudes.size(); i++)
                cout << "[" << solicitudes[i].getCodigo() << "] Solicitado por " << solicitudes[i].getNickname() << " el " << solicitudes[i].getFecha().toString() << endl;
            string solicitud;
            procesoInvalido = true;
            while (procesoInvalido) {
                cout << endl << "Solicitud (cmp#): ";
                cin >> solicitud;
                getline(cin, aux);
                unsigned int i = 0;
                while ((i < solicitudes.size()) && (solicitud.compare(solicitudes[i].getCodigo()) != 0))
                    i++;
                if (i < solicitudes.size())
                    procesoInvalido = false;
                else
                    cout << endl << "[ERROR] Solicitud inválida\n";
            }
            /************************MARCAR COMO ENVIADO***********************/
            cout << endl << iPP->marcarComoEnviado(codigo, solicitud);
        }
    }
}

void main_expedienteDeUsuario() {
    FechaSistema* fechaSistema = FechaSistema::getInstancia();
    Factory* f = Factory::getInstancia();
    IUsuarios* iUsrs = f->getIUsuarios();
    /************************LISTADO DE USUARIOS***********************/
    vector<string> nicknameUsuarios = iUsrs->nicknameUsuarios();
    unsigned int i = nicknameUsuarios.size();
    if (i == 0) {
        cout << endl << "No hay usuarios en sistema\n";
    } else {
        for (i = 0; i < nicknameUsuarios.size(); i++)
            cout << endl << nicknameUsuarios[i];
        /******************ADMINISTRADOR INGRESA USUARIO*******************/
        cout << endl;
        string nickname, aux;
        bool nicknameInvalido = true;
        while(nicknameInvalido){
            cout << endl << "Usuario a consultar: ";
            cin >> nickname;
            getline(cin,aux);
            unsigned int i = 0;
            while((i < nicknameUsuarios.size()) && (nickname.compare(nicknameUsuarios[i]) != 0))
                i++;
            if(i < nicknameUsuarios.size())
                nicknameInvalido = false;
            else
                cout << endl << "[ERROR] No existe usuario '" << nickname << "'\n";
        }
        cout << endl;
        bool boolCliente = iUsrs->esCliente(nickname);
        /***********************LISTADO DE INFO CLIENTE********************/
        if (boolCliente) {
            DataCliente infoBasica = iUsrs->getDataCliente(nickname);
            vector<DataCompraExp> infoCompras = iUsrs->getCompraExpediente(nickname);
            cout << "Expediente de usuario para " << infoBasica.getNickname() << ":\n"<< endl;
            cout << "Fecha de nacimiento: " << infoBasica.getFechaNacimiento().toString() << endl;
            cout << "Dirección: " << infoBasica.getCalle() << " " << infoBasica.getNroPuerta() << endl;
            cout << "Ciudad: " << infoBasica.getCiudad() << endl;

            if (infoCompras.size() != 0) {
                cout << endl << "Compras realizadas:" << endl;
                for (unsigned int i = 0; i < infoCompras.size(); i++) {
                    cout << endl << "--------------------------" << endl;
                    DataCompraExp dce = infoCompras[i];
                    cout << endl << "[" << dce.getCodigo() << "] " << dce.getFecha().toString() << endl; 
                    printf("Importe: UYU %.2f\n", dce.getMonto());
                    cout << endl << "Productos de la compra: " << endl;
                    vector<DataProdExp> productos = dce.getProductos();

                    for (unsigned int j = 0; j < productos.size(); j++) {
                        DataProdExp dpe = productos[j];
                        cout << endl << "x" << dpe.getCantidad() << " [" << dpe.getCodigo() << "] " << dpe.getNombre() << endl; 
                        cout << "Vendedor: " << dpe.getVendedor() << endl;
                        cout << "Descripción: " << dpe.getDescripcion() << endl;
                        cout << "Categoria: ";
                        if (dpe.getCategoria() == ropa)
                            cout << "Ropa\n";
                        else if (dpe.getCategoria() == electrodomestico)
                            cout << "Electrodoméstico\n";
                        else
                            cout << "Otro\n";
                        cout << "Estado: ";
                        if (dpe.getEstado() == pendiente)
                            cout << "Pendiente\n";
                        else
                            cout << "Entregado\n";
                    }
                }
            } else
                cout << endl << "No hay compras realizadas por el cliente\n"; 
        /***********************LISTADO DE INFO VENDEDOR*******************/
        } else {
            DataVendedor infoBasica = iUsrs->getDataVendedor(nickname);
            cout << "Expediente de usuario para " << infoBasica.getNickname() << ":\n" << endl;
            cout << "Fecha de nacimiento: " << infoBasica.getFechaNacimiento().toString() << endl;
            cout << "Número de RUT: " << infoBasica.getNroRut() << endl;

            vector<DataProducto> productosVendedor = iUsrs->getProductosVendedor(nickname);
            if (productosVendedor.size() != 0) {
                cout << endl << "Productos a la venta: " << endl;
                for (unsigned int i = 0; i < productosVendedor.size(); i++) {
                    DataProducto dPrd = productosVendedor[i];
                    cout << endl << "[" << dPrd.getCodigo() << "] " << dPrd.getNombre() << endl;
                    cout << "Descripción: " << dPrd.getDescripcion() << endl;
                    cout << "Categoría: ";
                    if (dPrd.getCategoria() == ropa)
                        cout << "Ropa\n";
                    else if (dPrd.getCategoria() == electrodomestico)
                        cout << "Electrodoméstico\n";
                    else
                        cout << "Otro\n";
                    cout << "Stock: " << to_string(dPrd.getStock()) << endl;
                    printf("Precio: UYU %.2f\n", dPrd.getPrecio());
                }

                vector<DataPromoConsulta> promosVendedor = iUsrs->getPromosVendedor(nickname, fechaSistema->getFecha());
                if (promosVendedor.size() != 0) {
                    cout << endl << "Promociones vigentes: " << endl;
                    for (unsigned int i = 0; i < promosVendedor.size(); i++) {
                        DataPromoConsulta dpc = promosVendedor[i];
                        cout << endl << "Nombre: " << dpc.getNombre() << endl;
                        cout << "Descripción: " << dpc.getDescripcion() << endl;
                        float descuento = (1 - dpc.getDescuento()) * 100;
                        printf("Descuento: %.0f%%\n", descuento);
                        cout << "Vencimiento: " << dpc.getVencimiento().toString() << endl;
                    }
                } else
                    cout << endl << "No hay promociones vigentes del vendedor\n";
            } else
                cout << endl << "No hay productos a la venta del vendedor\n";
        }
    }
}