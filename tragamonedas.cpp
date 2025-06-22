#include <iostream>
#include <conio2.h>
#include <cstdlib>
#include <ctime>  

using namespace std;

int main() {
	int n;
	int ganadas = 0;
	char tecla;
	
	srand(time(NULL)); 
	do {
		cout << "Ingrese monedas (1 a 10): ";
		cin >> n;
	} while (n < 1 || n > 10);
	
	cout << "\n========================" << endl;
	cout << "Tienes " << n << " tiradas." << endl;
	cout << "========================\n" << endl;
	
	int tiradas = 0;
	while (tiradas < n) {
		cout << "Presione 'P' para tirar la palanca." << endl;
		tecla = getch();
		
		if (tecla == 'P' || tecla == 'p') {
			int a = rand() % 3 + 1;
			int b = rand() % 3 + 1;
			int c = rand() % 3 + 1;
			
			cout << "Resultado: " << a << " " << b << " " << c << endl;
			
			if (a == b && b == c) {
				cout << "\nSon iguales.\n";
				ganadas++;
			} else {
				cout << "\nNo hubo suerte esta vez.\n";
			}
			tiradas++;
		}
	}
	
	cout << "\nJuego terminado. Tiradas ganadas: " << ganadas << " de " << n << endl;
	cout << "\nPresione una tecla para salir..." << endl;
	getch();
	return 0;
}

