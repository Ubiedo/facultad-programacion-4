#include "include/dtfecha.h"
#include "include/dtinfoestudiante.h"
#include "include/estudiante.h"
#include "include/informacion.h"

int main(){
    cout << "\n======================================== LABORATORIO 0 ========================================\n\n";
    cout << "Grupo 08: Federico Gonzalez, Marcos Baptista, Matias Silvera, Roque Serrato y J. Pablo Otero\n";
    cout << "Tutor: Miguel Machado\n\n";

    // -------------------------------------------------------     a     ------------------------------------------------------- //
    DTFecha fecha = DTFecha(7, 3, 2024);
    string titulo = "Programación 4 Guía Semana 1 (4/3)";
    string link = "https://eva.fing.edu.uy\n/pluginfile.php/468051/mod_resource/content/4/Guia01_P42024_IntroCBasicos.pdf";
    string text = "El \nobjetivo de esta semana es contextualizar el paradigma de Orientación a Objetos (OO) \nen el marco de la Ingeniería de Software, así como comenzar a ver sus conceptos básicos \ny cómo éstos se implementan en C++.\n";
    PaginaWeb* pagina1 = new PaginaWeb(1, fecha, titulo, link, text);
    
    fecha = DTFecha(5, 3, 2024);
    titulo = "Programación orientada a objetos";
    link = "https://es.wikipedia.org\n/wiki/Programaci%C3%B3n_orientada_a_objetos";
    text = "La programación orientada a objetos \n(POO, en español) es un paradigma de programación que parte del concepto de \"objetos\" \ncomo base, los cuales contienen información en forma de campos (a veces también \nreferidos como atributos o propiedades) y código en forma de métodos. Algunas \ncaracterísticas clave de la programación orientada a objetos son herencia, cohesión, \nabstracción, polimorfismo, acoplamiento y encapsulamiento.\n";
    PaginaWeb* pagina2 = new PaginaWeb(2, fecha, titulo, link, text);

    // -------------------------------------------------------     b     ------------------------------------------------------- //
    fecha = DTFecha(8, 3, 2024);
    string pregunta = "¿Qué es el polimorfismo en orientación a objetos?";
    string respuesta = "El polimorfismo \nen programación orientada a objetos se refiere a la capacidad de un objeto de tomar \nmúltiples formas. Puede ser estático, resuelto en tiempo de compilación, basado en la \nherencia, o dinámico, resuelto en tiempo de ejecución, asociado a interfaces o métodos \nabstractos. En esencia, permite que objetos de diferentes clases respondan a la misma \ninterfaz de manera coherente, facilitando la flexibilidad y extensibilidad del código.\n";
    ChatGPT* chat1 = new ChatGPT(3, fecha, pregunta, respuesta);

    fecha = DTFecha(5, 3, 2024);
    pregunta = "¿Qué es el acoplamiento en orientación a objetos?";
    respuesta = "El acoplamiento \nen programación orientada a objetos se refiere al grado de dependencia entre las clases \no módulos de un sistema. Un bajo acoplamiento es deseable, ya que implica que las clases \nson independientes entre sí, lo que facilita la modificación, mantenimiento y reutilización \ndel código. Por otro lado, un alto acoplamiento indica una fuerte interdependencia entre \nlas clases, lo que puede hacer que el sistema sea más difícil de entender, modificar y \nmantener.\n";
    ChatGPT* chat2 = new ChatGPT(4, fecha, pregunta, respuesta);
    
    // -------------------------------------------------------     c     ------------------------------------------------------- //
    fecha = DTFecha(15, 3, 2024);
    titulo = "Applying UML and Patterns: An Introduction to Object-Oriented \nAnalysis and Design and Iterative Development";
    vector<string> autores = {"Craig Larman"};
    string resumen = "Applying UML and Patterns is \nthe world\u2019s #1 business and college introduction to “thinking in objects”―and using that \ninsight in real-world object-oriented analysis and design. Building on two widely \nacclaimed previous editions, Craig Larman has updated this book to fully reflect the new \nUML 2 standard, to help you master the art of object design, and to promote high-impact, \niterative, and skillful agile modeling practices.\n";
    Libro* libro1 = new Libro(5, fecha, titulo, autores, resumen);
    
    // -------------------------------------------------------     d     ------------------------------------------------------- //
    cout << "========================================= PARTES A:D ==========================================\n\n";
    cout << pagina1->toString() << endl;
    cout << pagina2->toString() << endl;
    cout << chat1->toString() << endl;
    cout << chat2->toString() << endl;
    cout << libro1->toString() << endl;

    // -------------------------------------------------------     e     ------------------------------------------------------- //
    cout << "========================================= PARTES E:F ==========================================\n\n";
    cout << "Se crearon los siguientes objetos de clase Estudiante:\n\n";

    string nombre = "Alex García";
    string email = "ag5678@gmail.com";
    Estudiante* estudiante1 = new Estudiante(nombre, 52365899, email);

    cout << estudiante1->toString() << endl;

    nombre = "Betina Gonzalez"; 
    email = "beg999@gmail.com";
    Estudiante* estudiante2 = new Estudiante(nombre, 49891239, email);
    
    cout << estudiante2->toString() << endl;

    // -------------------------------------------------------     f     ------------------------------------------------------- //
    estudiante1->addInfoGuardado({pagina1, pagina2, chat1});
    pagina1->addGuardadoPorEstudiante(estudiante1);
    pagina2->addGuardadoPorEstudiante(estudiante1);
    chat1->addGuardadoPorEstudiante(estudiante1);

    estudiante2->addInfoGuardado({chat1, chat2, libro1});
    chat1->addGuardadoPorEstudiante(estudiante2);
    chat2->addGuardadoPorEstudiante(estudiante2);
    libro1->addGuardadoPorEstudiante(estudiante2);

    // -------------------------------------------------------     g     ------------------------------------------------------- //   
    cout << "\n=========================================== PARTE G ===========================================\n\n";
    cout << "Información registrada a partir del día 8/3/2024 que ha sido guardada por los estudiantes:\n\n";
    
    cout << "Alex García: \n\n";
    vector<string> imprimir = estudiante1->listarInfo(DTFecha(8, 3, 2024));
    if(imprimir.size() > 0){
        for (unsigned int i = 0; i < imprimir.size(); i++) {
            cout << imprimir[i] << endl;
        }
    }

    cout << "Betina Gonzalez: \n\n";
    imprimir = estudiante2->listarInfo(DTFecha(8, 3, 2024));
    if(imprimir.size() > 0){
        for (unsigned int i = 0; i < imprimir.size(); i++) {
            cout << imprimir[i] << endl;
        }
    }

    // -------------------------------------------------------     h     ------------------------------------------------------- //
    cout << "=========================================== PARTE H ===========================================\n\n";
    cout << "Los siguientes estudiantes han guardado información que contiene el término 'Polimorfismo':\n\n";

    vector<Informacion*> ConjuntoInformacion = {pagina1, pagina2, chat1, chat2, libro1};
    vector<DTInfoEstudiante> ConjuntoRelacion;
    int aux_CI, aux_ID;
    string aux_Nombre;

    for(unsigned int i = 0; i < ConjuntoInformacion.size(); i++){
        if(ConjuntoInformacion[i]->toString().find("polimorfismo") != string::npos){ // esto esta dentro de std::string permitido por la letra del lab0
            if(ConjuntoInformacion[i]->getGuardadoPor().size() > 0){
                for(unsigned int j = 0; j < ConjuntoInformacion[i]->getGuardadoPor().size(); j++){
                    aux_CI = (ConjuntoInformacion[i]->getGuardadoPor())[j]->getCI();
                    aux_Nombre = (ConjuntoInformacion[i]->getGuardadoPor())[j]->getNombre();
                    aux_ID = ConjuntoInformacion[i]->getIdentificador();
                    DTInfoEstudiante aux_DTIE(aux_CI, aux_Nombre, aux_ID);
                    ConjuntoRelacion.push_back(aux_DTIE);
                    cout << aux_DTIE << endl;
                }
            }
        }
    }

    // -------------------------------------------------------     i     ------------------------------------------------------- //
    cout << "\n=========================================== PARTE I ===========================================\n\n";
    // cual elemento del conjunto informacion borrar, va de [0,4], 5 elementos
    int CualBorrar = 2; 
    // ir a los estudiantes que lo linkean, y eliminar el link
    if(ConjuntoInformacion[CualBorrar]->getGuardadoPor().size() > 0){
        for(unsigned int i = 0; i < ConjuntoInformacion[CualBorrar]->getGuardadoPor().size(); i++){
            ConjuntoInformacion[CualBorrar]->getGuardadoPor()[i]->removeInfoGuardado(ConjuntoInformacion[CualBorrar]->getIdentificador());
        }
    }

    // si esta en ConjuntoRelacion borrar el registro
    for(unsigned int i = 0; i < ConjuntoRelacion.size(); i++){
        if(ConjuntoInformacion[CualBorrar]->getIdentificador() == ConjuntoRelacion[i].getIdentificadorInfo()){
            ConjuntoRelacion.erase(ConjuntoRelacion.begin() + i);
            break;
        }
    }

    // borrar el dato
    delete ConjuntoInformacion[CualBorrar];
    ConjuntoInformacion.erase(ConjuntoInformacion.begin() + CualBorrar);

    cout << "Se eliminó el objeto de clase ChatGPT de identificador 3.\nA continuación se listan los objetos de clase Información en el sistrema:\n\n";
    // listar objetos en sistema
    for (unsigned int i = 0; i < ConjuntoInformacion.size(); i++){
        cout << ConjuntoInformacion[i]->toString() <<endl;
    }
    
    // ---------------------------------------------------  liberar memoria  --------------------------------------------------- //
    delete estudiante1;
    delete estudiante2;
    while (ConjuntoInformacion.size() > 0) {
        delete ConjuntoInformacion.front();
        ConjuntoInformacion.erase(ConjuntoInformacion.begin());
    }
    
    return 0;
}