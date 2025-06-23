#include <iostream>
#include <conio2.h>
#include <ctime>
using namespace std;

int todoalx(int a[], int nro){
	int aux = 0;
	for(int i=0;i<5;i++) { 
		if(a[i] == nro){
			aux = aux + a[i];
		}
	}
	return aux;
}

int full(int a[]){
	if( (todoalx(a,1)==3 || todoalx(a,2)==6 || todoalx(a,3)==9 || todoalx(a,4)==12 || todoalx(a,5)==15 || todoalx(a,6)==18) && (todoalx(a,1)==2 || todoalx(a,2)==4 || todoalx(a,3)==6 || todoalx(a,4)==8 || todoalx(a,5)==10 || todoalx(a,6)==12)){
		return 30;
	}
	return 0;
}
	
int poker(int a[]){
	
	if(todoalx(a,1)==4 || todoalx(a,2)==8 || todoalx(a,3)==12 || todoalx(a,4)==16 || todoalx(a,5)==20 || todoalx(a,6)==24){
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
	for(int i=0;i<6;i++){
		puntos = max(puntos,todoalx(a,i+1));
	}
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

