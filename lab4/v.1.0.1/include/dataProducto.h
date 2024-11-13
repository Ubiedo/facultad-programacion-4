#ifndef DATAPRODUCTO
#define DATAPRODUCTO

class DataProducto {
    private:
        string nombre, descripcion;
        int stock;
        float precio;
        Categoria categoria;
    public:
        DataProducto(string nombre, string descripcion, Categoria categoria, int stock, float precio);
        ~DataProducto() = default;

        string getNombre();
        string getDescripcion();
        int getStock();
        float getPrecio();
        Categoria getCategoria();
};

#endif