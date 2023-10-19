// Cola C++.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#define MaxTamC 10

typedef int TipoDato;

int main() {
	int frente = 0, final = 0;
	TipoDato A[MaxTamC];
	int contador = 0;

	//Inicializar la cola
	frente = 0;
	final = 0;

	std::cout << "Desea agregar elementos a la cola? (s/n)";
	char respuesta;
	std::cin >> respuesta;

	while ((respuesta == 's' || respuesta == 'S') && contador < 10) {
		if ((final + 1) % MaxTamC == frente) {
			std::cout << "Desbordamiento de la cola" << std::endl;
			return 1;
		}

		std::cout << "Ingrese un elemento para la cola: ";
		TipoDato elemento;
		std::cin >> elemento;

		final = (final + 1) % MaxTamC;
		A[final] = elemento;

		contador++;
		std::cout << "Elemento " << contador << "agregado a la cola: " << elemento << std::endl;

		if (contador < 10) {
			std::cout << "Desea agregar mas elementos a la cola? (s/n): ";
			std::cin >> respuesta;
		}
	}

	//validar si la cola está vacia
	if (frente == final) {
		std::cout << "La cola esta vacia." << std::endl;
		return 1;
	}

	//Obtener el primer elemento de la cola
	TipoDato primerElemento = A[(frente + 1) % MaxTamC];
	std::cout << "El primer elemento de la cola es: " << primerElemento << std::endl;

	//Eliminar un elemento de la cola
	frente = (frente + 1) % MaxTamC;

	//Imprimir elemento de la cola en el orden en que fueron ingresados
	std::cout << "Elemento de la cola en el orden de la ingreso:" << std::endl;
	for (int i = frente + 1; i <= final; i = (i + 1) % MaxTamC) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
