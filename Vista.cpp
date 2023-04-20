#include "Presentador.h"

Vista::Vista() {
	presentador = new Presentador(this);
	presentador->realizarPasos();
}

void Vista::mostrarPaginaPrincipal() {

	cout << "COTIZADOR EXPRESS - MENU PRINCIPAL" << endl
		<< "-------------------------------------------------" << endl
		<< presentador->tienda.nombre << "|" << presentador->tienda.direccion << endl
		<< "-------------------------------------------------" << endl
		<< presentador->tienda.vendedor.nombre << " " << presentador->tienda.vendedor.apellido << "|" << "Codigo: " << presentador->tienda.vendedor.id << endl
		<< "-------------------------------------------------" << endl
		<< "SELECCIONE UNA OPCION DEL MENU:" << endl
		<< "1) Historial de Cotizaciones" << endl
		<< "2) Realizar Cotizacion" << endl
		<< "3) Salir" << endl;

}

void Vista::mostrarSeleccionarPrenda() {

	cout << "PASO 1: Selecciona la prenda a cotizar:" << endl
		<< "1) Camisa" << endl
		<< "2) Pantalon" << endl;

}

void Vista::mostrarSeleccionarManga() {

	cout << "PASO 2.a: La camisa a cotizar tiene manga: " << endl
		<< "1) Corta" << endl
		<< "2) Larga" << endl;

}

void Vista::mostrarSeleccionarCuello() {

	cout << "Paso 2.b: La camisa a cotizar tiene cuello:" << endl
		<< "1) Mao" << endl
		<< "2) Comun" << endl;

}

void Vista::mostrarSeleccionarPantalon() {

	cout << "PASO 2: El pantalon a cotizar es:" << endl
		<< "1) Chupin" << endl
		<< "2) Suelto" << endl;

}

void Vista::mostrarSeleccionarCalidad() {

	cout << "PASO 3: Seleccione la calidad de la prenda:" << endl
		<< "1) Premium" << endl
		<< "2) Standard" << endl;

}

void Vista::mostrarIngresarPrecio() {

	cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar:" << endl
		<< "-";

}

void Vista::mostrarIngresarCantidad() {

	cout 
		<< "\n" << "PASO 5: Ingrese la cantidad de unidades a cotizar: " << endl
		<< "-";
}

void Vista::mostrarCotizacion() {

	presentador->tienda.vendedor.mostrarUltimaCotizacion();

}

void Vista::mostrarHeader() {

	cout << "COTIZADOR EXPRESS - COTIZAR" << endl
		<< "-------------------------------------------------" << endl
		<< "Presione X para volver al menu principal" << endl
		<< "-------------------------------------------------" << endl;

}

void Vista::mostrarCrearVendedorNombre() {
	cout << "Ingrese su nombre: ";
}

void Vista::mostrarCrearVendedorApellido() {
	cout << "Ingrese su apellido: ";
}

void Vista::mostrarCrearVendedorId() {
	cout << "Ingrese su id de vendedor: ";
}

void Vista::mostrarCrearTiendaNombre() {
	cout << "Bienvenido a Cotizar.app" << endl
		<< "Por favor complete los siguientes campos para empezar:" << endl 
		<< "Ingrese el nombre de la tienda: ";
}

void Vista::mostrarCrearTiendaDireccion() {
	cout << "Ingrese la direccion de la tienda: ";
}

void Vista::mostrarMensajeError() {
	cout << "Ingreso incorrecto, por favor elija una opcion valida" << endl;
}

void Vista::mostrarMensajeContinuar() {
	cout << "Toca enter para continuar" << endl;
}