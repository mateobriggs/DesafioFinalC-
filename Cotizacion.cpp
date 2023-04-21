#include "Tienda.h"

void Cotizacion::imprmirCotizacion() {

	cout << "Numero de identificacion: " << id << endl
		<< "Codigo del vendedor: " << codigoVendedor << endl
		<< "Prenda cotizada: " << definirDetallesPrenda() << endl
		<< "Precio unitario: " << precio << endl
		<< "Cantidad de unidades cotizadas: " << cantidadUnidades << endl
		<< "Precio final: " << resultado << endl << endl;

}

string Cotizacion::definirDetallesPrenda() {
	string detallesPrenda;
	if (pantalon != nullptr) {
		detallesPrenda = "Pantalon";
		if (pantalon->estilo == CHUPIN) {
			detallesPrenda = detallesPrenda + " - " + "Chupin";
		}
		if(pantalon->estilo == SUELTO) {
			detallesPrenda = detallesPrenda + " - " + "Suelto";
		}
		if (pantalon->calidad == PREMIUM) {
			detallesPrenda = detallesPrenda + " - " + "Calidad Premium";
		}
		if (pantalon->calidad == STANDARD) {
			detallesPrenda = detallesPrenda + " - " + "Calidad Standard";
		}
		return detallesPrenda;
	}
	else{
		detallesPrenda = "Camisa";
		if (camisa->manga == CORTA) {
			detallesPrenda = detallesPrenda + " - " + "Manga corta";
		}
		if(camisa->manga == LARGA) {
			detallesPrenda = detallesPrenda + " - " + "Manga larga";
		}
		if (camisa->cuello == MAO) {
			detallesPrenda = detallesPrenda + " - " + "Cuello Mao";
		}
		if (camisa->cuello == COMUN) {
			detallesPrenda = detallesPrenda + " - " + "Cuello Comun";
		}
		return detallesPrenda;
	}
	
}