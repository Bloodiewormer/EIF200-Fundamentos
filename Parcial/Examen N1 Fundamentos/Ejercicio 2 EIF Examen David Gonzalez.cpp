#include <iostream>
using namespace std;

int main() {
	// declaraciones
	string Nombrejugador1,Nombrejugador2;
	char jugada1, jugada2;
	int Winj1=0, winj2=0, empate=0;
	char seguirJugando;
	
	
	//zonda de datos
	cout<<"ingrese su nombre jugador 1"<<endl;
	cin>>Nombrejugador1;
	cout<<"ingrese su nombre jugador 2"<<endl;
	cin>>Nombrejugador2;
	system("cls");
	
	cout<<"Cada jugador debera de ingresar su seleccion\n";
	cout<<"(P) piedra \n";
	cout<<"(A)  papel \n";
	cout<<"(T) tijera \n";
	cout<<"que vas a jugar [P,A,T] \n";
		do{
		cout<<"es turno de "<<Nombrejugador1<<",ingrese su jugada"<<endl;
		cin>>jugada1;
			
		switch (jugada1){
			case'P':
				cout<<"es turno de "<<Nombrejugador2<<",ingrese su jugada"<<endl;
				cin>>jugada2;
				if (jugada2 == 'P'){
					cout << "Es un empate!\n"<<endl;
					empate += 1;
				}else if (jugada2 == 'A'){
					cout << Nombrejugador2<<" a Ganado"<<endl;
					winj2 += 1;
				}else if (jugada2 == 'T'){
					cout << Nombrejugador1<<" a Ganado"<<endl;
					Winj1+= 1;}
				else
					cout <<"Eso no es valido"<<endl;
				break;
			case'A':
				cout<<"es turno de "<<Nombrejugador2<<",ingrese su jugada"<<endl;
				cin>>jugada2;
				if (jugada2 == 'P'){
					cout << Nombrejugador1<<" a Ganado"<<endl;
					Winj1+= 1;
				}else if (jugada2 == 'A'){
					cout << "Es un empate!\n"<<endl;
					empate += 1;
				}else if (jugada2 == 'T'){
					cout << Nombrejugador2<<" a Ganado"<<endl;
					winj2 += 1;}
				else
					cout << "Eso no es valido"<<endl;  
				break;  
			case'T':
				cout<<"es turno de "<<Nombrejugador2<<",ingrese su jugada"<<endl;
				cin>>jugada2;
				if (jugada2 == 'P'){
					cout << Nombrejugador2<<" a Ganado"<<endl;
					winj2 += 1;
				}else if (jugada2 == 'A'){
					cout << Nombrejugador1<<" a Ganado"<<endl;
					Winj1+= 1;
				}else if (jugada2 == 'T'){
					cout << "Es un empate!\n"<<endl;
					empate += 1;}
				else
					cout << "Eso no es valido"<<endl;  
				break;  
			default:
				cout << "Eso no es valido"<<endl;        
			}
		cout<<"El jugador 1:"<<Nombrejugador1<<" ha ganado "<<Winj1;
		if(Winj1==1);
			cout<<"vez"<<endl;
		else
			cout<<"veces";
		cout<<"El jugador 2:"<<Nombrejugador2<<" ha ganado "<<winj2<<"<<endl;
		cout<<"Se reporto un empate un total de:"<<empate<<" veses"<<endl;
		cout << "\n\nSeguir Jugando?[S/N]\n";
		cin >> seguirJugando;
		}while(seguirJugando=='S');
		cout << "has elejido no segir jugado, presiona enter para salir";
	return 0;
}

