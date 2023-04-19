#pragma once

class Presentador;

class Vista {
	Presentador* presentador;
public:
	Vista();
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
	void mostrarCrearVendedorNombre();
	void mostrarCrearVendedorApellido();
	void mostrarCrearVendedorId();
	void mostrarCrearTiendaNombre();
	void mostrarCrearTiendaDireccion();
};