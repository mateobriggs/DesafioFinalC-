#pragma once
#include "Presentador.h"


class Vista {
public:
	Presentador presentador;
	void mostrarPaginaPrincipal();
	void mostrarSeleccionarPrenda();
	void mostrarSeleccionarManga();
	void mostrarSeleccionarCuello();
	void mostrarSeleccionarPantalon();
	void mostrarSeleccionarCalidad();
	void mostrarIngresarPrecio();
	void mostrarIngresarCantidad();
	void mostrarCotizacion();
	void mostrarHeader();
};
