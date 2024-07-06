#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool repite(int mat[3][3],int num){
	for (int f = 0; f < 3; f++){
		for (int c = 0; c < 3; c++){
			if(num == mat[f][c]){
				return false;
			}
		}
	}
	return true;
}
int main() {
	
	int mat[3][3];
	int num;
	bool esLuna;
	int numL = 15;
	
	int sumFilas = 0;
	int sumColum = 0;
	int sumDiagonalPrinci = 0;
	int sumDiagonalSecun = 0;
	int cont = 0;
//mesclar
	srand(time(0));
	cout << "Llenar aleatoriamente las primera 3 columnas " << endl << endl;
	do{
		
	for (int f = 0; f < 3; f++){
		for (int c = 0; c < 3; c++){
			num=1+rand()%9;
			while(repite(mat, num)== false){
				num= 1+rand()%9;
			}
			mat[f][c] = num;
		}
	}
	

	for (int i = 0; i < 3 && esLuna != false; i++) {
		for (int j = 0; j < 3; j++) {
			sumFilas += mat[i][j];
			sumColum += mat[j][i];
			if (i == j) {
				sumDiagonalPrinci += mat[i][j];
			}
			if (((3 - 1) - i) == j) {
				sumDiagonalSecun += mat[i][j];
			}
		}
		if (sumFilas == sumColum) {
			cont++;
			if (cont == 3) {
				esLuna = true;
			}
			sumFilas = 0;
			sumColum = 0;
		} else {
			esLuna = false;
		}
	}
	if (esLuna == true && (sumDiagonalPrinci != sumDiagonalSecun)) {
		esLuna = false;
	}
	esLuna = true;
	

	cout << "Es cuadrado magico"<< std::endl;
		cout << "Imprimir la matriz ." << endl;
		for (int f = 0; f < 3; f++) {
			for (int c = 0; c < 3; c++){
				cout << mat[f][c] << '\t';}
				cout << endl; // saltar de linea un vez que se termina de imprimir la fila..
			}
		
	system("pause");
	esLuna = true;

	} while(esLuna=false);
	
	return 0;
}

