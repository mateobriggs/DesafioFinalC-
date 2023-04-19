#include "PrendaHerencias.h"

void Cotizacion::imprmirCotizacion() {

	cout << "Numero de identificacion: " << id << endl
		<< "Codigo del vendedor: " << codigoVendedor << endl
		<< "Prenda cotizada: " << prenda << endl
		<< "Precio unitario: " << /*AÑADIR PRECIO*/ endl
		<< "Cantidad de unidades cotizadas: " << cantidadUnidades << endl
		<< "Precio final" << resultado << endl;

}