#ifndef DATACMTBASICA
#define DATACMTBASICA

#include <string>
using namespace std;

class DataCmtBasica {
    private:
        string codigo, strComentario;
    public:
        DataCmtBasica(string codigo, string strComentario);
        ~DataCmtBasica() = default;

        string getCodigo();
        string getStrComentario();
};

#endif