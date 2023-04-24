#include "Tienda.h"

void Cotizacion::imprmirCotizacion() {

	cout << "Numero de identificacion: " << id << endl
		<< "Codigo del vendedor: " << codigoVendedor << endl
		<< "Prenda cotizada: " << detallesPrenda << endl
		<< "Precio unitario: " << precio << endl
		<< "Cantidad de unidades cotizadas: " << cantidadUnidades << endl
		<< "Precio final: " << resultado << endl << endl;

}

void Cotizacion::definirDetallesPrenda() {
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
		this->detallesPrenda = detallesPrenda;
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
		if (camisa->calidad == PREMIUM) {
			detallesPrenda = detallesPrenda + " - " + "Calidad Premium";
		}
		if (camisa->calidad == STANDARD) {
			detallesPrenda = detallesPrenda + " - " + "Calidad Standard";
		}
		this->detallesPrenda = detallesPrenda;
	}
	
}