#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

std::vector<std::vector<int>> crearMatriz();
void mostrarMatriz(std::vector<std::vector<int>> matriz);
std::vector<int> elegirNumeros(std::vector<std::vector<int>> matriz);
void mostrarNumerosElegidos(std::vector<int> numeros);
double calcularPromedio(std::vector<int> numeros);
double calcularDesviacionEstandar(std::vector<int> numeros, double promedio);
	
int main(int argc, char *argv[]) {
	
	auto matriz = crearMatriz();
	
	mostrarMatriz(matriz);
	
	auto numerosElegidos = elegirNumeros(matriz);
	
	mostrarNumerosElegidos(numerosElegidos);
	
	double promedio = calcularPromedio(numerosElegidos);
	
	double desviacionEstandar = calcularDesviacionEstandar(numerosElegidos, promedio);
	
	system("pause");
	
	return 0;
}

std::vector<std::vector<int>> crearMatriz() {
	int n;
	
	cout << "Ingrese un numero impar entre 3 y 17: ";
		cin >> n;
	
	while((n % 2 == 0) || (n < 3 || n > 17)) {
		cout << "ERROR. Vuelva a ingresar el numero: ";
		cin >> n;
	}
	
	using matrix = std::vector<std::vector<int>>;
	matrix matriz(n, std::vector<int>(n));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matriz[i][j] = rand() % 99 + 1;
		}
	}

   return matriz;
}

void mostrarMatriz(std::vector<std::vector<int>> matriz) {
	
	cout << "\nLa matriz generada es:\n" << endl;
	for(unsigned i = 0; i < matriz.size(); i++) {
		for(unsigned j = 0; j < matriz[i].size(); j++) {
			if(matriz[i][j] < 10) {
				cout << " " << matriz[i][j] << " ";
			} else {
				cout << matriz[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

std::vector<int> elegirNumeros(std::vector<std::vector<int>> matriz) {
	
	int contador = 0;
	
	using vector = std::vector<int>;
	vector vectorAux(pow(matriz.size(), 2));
	
	cout << endl;
	
	for (unsigned i = 0; i < matriz.size(); i++) {
		for (unsigned j = 0; j < matriz[i].size(); j++) {
			//Cambiar las condiciones cuando cambie la zona roja
			if ((i >= j && i <= matriz.size() / 2) || ((i <= j) && (i >= matriz.size() / 2))) {
				contador++;
				vectorAux[contador - 1] = matriz[i][j];
				if (matriz[i][j] < 10) {
					cout << " " << matriz[i][j] << " ";
				} else {
					cout << matriz[i][j] << " ";
				}
			} else {
				cout << "XX ";
			}
		}
		cout << endl;
	}
	
	using vector = std::vector<int>;
	vector numerosElegidos(contador);
	
	for (int i = 0; i < contador; i++) {
		
		numerosElegidos[i] = vectorAux[i];
		
	}
	
	return numerosElegidos;
}

void mostrarNumerosElegidos(std::vector<int> numeros) {
	cout << "\nLos numeros elegidos son:" << endl;
	for(unsigned i = 0; i < numeros.size(); i++) {
		cout << numeros[i] << " ";
	}
	cout << "\n" << endl;
}

double calcularPromedio(std::vector<int> numeros) {
	double promedio, suma = 0;
	int contador = 0;
	
	for(unsigned i = 0; i < numeros.size(); i++) {
		suma += numeros[i];
		contador++;
	}
	
	promedio = suma / contador;
	
	cout << "El promedio es: " << promedio << endl;
	
	return promedio;
}

double calcularDesviacionEstandar(std::vector<int> numeros, double promedio) {
	double desviacionEstandar, suma = 0;
	int contador = 0;
	
	for(unsigned i = 0; i < numeros.size(); i++) {
		suma += pow((numeros[i] - promedio), 2);
		contador++;
	}
	
	suma /= contador;
	desviacionEstandar = sqrt(suma);
	
	cout << "La desviacion estandar de la zona marcada es: " << desviacionEstandar << endl << endl;
	
	return desviacionEstandar;
}
