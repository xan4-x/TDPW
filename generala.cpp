#include <iostream>
#include <conio2.h>
#include <ctime>
using namespace std;

int todoal1(int a[]){
	int aux = 0;
	for(int i=0;i<5;i++) { 
		if(a[i] == 1){
			aux = aux + a[i];
		}
	}
	return aux;
}

int todoal2(int a[]){
	int aux = 0;
	for(int i=0;i<5;i++) { 
		if(a[i] == 2){
			aux = aux + a[i];
		}
	}
	return aux;
}
int todoal3(int a[]){
	int aux = 0;
	for(int i=0;i<5;i++) { 
		if(a[i] == 3){
			aux = aux + a[i];
		}
	}
	return aux;
}
int todoal4(int a[]){
	int aux = 0;
	for(int i=0;i<5;i++) { 
		if(a[i] == 4){
			aux = aux + a[i];
		}
	}
	return aux;
}
int todoal5(int a[]){
	int aux = 0;
	for(int i=0;i<5;i++) { 
		if(a[i] == 5){
			aux = aux + a[i];
		}
	}
	return aux;
}
int todoal6(int a[]){
	int aux = 0;
	for(int i=0;i<5;i++) { 
		if(a[i] == 6){
			aux = aux + a[i];
		}
	}
	return aux;
}

int full(int a[]){
	if( (todoal1(a)==3 || todoal2(a)==6 || todoal3(a)==9 || todoal4(a)==12 || todoal5(a)==15 || todoal6(a)==18) && (todoal1(a)==2 || todoal2(a)==4 || todoal3(a)==6 || todoal4(a)==8 || todoal5(a)==10 || todoal6(a)==12)){
		return 30;
	}
	return 0;
}
	
int poker(int a[]){
	
	if(todoal1(a)==4 || todoal2(a)==8 || todoal3(a)==12 || todoal4(a)==16 || todoal5(a)==20 || todoal6(a)==4){
		return 40;
	}
	return 0;
}
	
void sort(int a[],int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

int escalera(int a[]){
	sort(a,5);
	int aux = 0;
	for(int i=0;i<5;i++) { 
		if((a[i] == i+1)){
			aux++;
		}
	}
	int aux2 = 0;
	for(int i=0;i<5;i++) { 
		if((a[i] == i+2)){
			aux2++;
		}
	}
	if((aux2 == 5) || (aux == 5)){
		return 50;
	}
	return 0;
}

int generala(int a[]){
	int puntos = 0;
	puntos = max(puntos,todoal1(a));
	puntos = max(puntos,todoal2(a));
	puntos = max(puntos,todoal3(a));
	puntos = max(puntos,todoal4(a));
	puntos = max(puntos,todoal5(a));
	puntos = max(puntos,todoal6(a));
	puntos = max(puntos,full(a));
	puntos = max(puntos,poker(a));
	puntos = max(puntos,escalera(a));
	
	return puntos;
}
int main(int argc, char *argv[]) {
	
	int jugador[5];
	int pc[5];
	char tecla;
	srand(time(NULL));
	
	cout << "Presione 'P' para tirar los dados." << endl;
	tecla = getch();
	
	if (tecla == 'P' || tecla == 'p') {
		
		for(int i=0;i<5;i++) { 
			jugador[i] = rand() % 6 + 1;
		}
		
		cout<<"Jugador: "<<endl;
		for(int i=0;i<5;i++) { 
			cout<<jugador[i]<<" ";
		}
	}
	
	int puntaje_j = generala(jugador);
	cout<<endl;
	cout<<"Puntos: "<<puntaje_j;
	
	cout<<endl<<endl;
	
	for(int i=0;i<5;i++) { 
		pc[i] = rand() % 6 + 1;
	}
	
	cout<<"PC: "<<endl;
	for(int i=0;i<5;i++) { 
		cout<<pc[i]<<" ";
	}
	int puntaje_p = generala(pc);
	cout<<endl;
	cout<<"Puntos: "<<puntaje_p;
	cout<<endl<<endl;
	
	if(puntaje_j>puntaje_p){
		cout<< "Felicidades ganaste!";
	}else if(puntaje_j==puntaje_p){
		cout<<"Empataste...";
	}else{
		cout<<"Perdiste, suerte la proxima :(";
	}

	
	return 0;
}

