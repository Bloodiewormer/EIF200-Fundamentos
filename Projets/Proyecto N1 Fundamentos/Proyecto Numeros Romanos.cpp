#include <iostream>
#include<windows.h>
using namespace std;
	PROPUESTA #1
	1- Recibir por teclado un número romano (del I al MMM)
	2- Convertir el número recibido a número en base decimal y mostrar en pantalla el resultado obtenido
	3- Convertir el número decimal a clave morse y mostrar en pantalla la secuencia correspondiente de puntos
	y rayas del código morse.
	4- Hacer sonar el resultado obtenido en clave morse*/
int main(){
	//Declaracion de variables
	string Romaninput;
	int Decimalresultint =0, num =0;
	char NumerosDecimal[]={'1','2','3','4','5','6','7','8','9','0',' '};
	string Morsecha[]={{".----"},{"..---"},{"...--"},{"....-"},{"....."},{"-...."},{"--..."},{"---.."},{"----."},{"-----"},{""}};
	string Morseresult="";
	string Sound="";
	//Roman to Decimal
	cout << "Ingrese un numero romano del I al MMM" << endl;
	cin >> Romaninput;
	cout<<"\nInsertaste este numero romano\n\n"<<Romaninput<<endl;
	for(int i = Romaninput.size()-1;i!=0;i--){
		switch(Romaninput[i]){
			case'I':num=1;break;
			case'V':num=5;break;
			case'X':num=10;break;
			case'L':num=50;break;
			case'C':num=100;break;
			case'D':num=500;break;
			case'M':num=1000;break;}
		if(4*num < Decimalresultint){
		Decimalresultint-=num;}
		else Decimalresultint+=num;}
		string Decimalresultstr(std::to_string(Decimalresultint));
		cout<<"\nEl numero en decimal es:\n\n"<<Decimalresultstr<<endl;
	//Decimal to morse
	for(int q = 0;q < Decimalresultstr.size(); q++){
		for(int j=0;j<10;j++){
			if(Decimalresultstr[q]==NumerosDecimal[j]){
			Morseresult+=Morsecha[j];
			Morseresult+=" ";}}}
	cout<<"\nEl numero en morse es:\n\n"<<Morseresult<<endl;
	//Morse to sound
	cout<<"\nEmpezando sonido en morse...\n"<<endl;
	Sleep(1500);
	for(int y = 0; y < Morseresult.size();y++){
		Sound = Morseresult[y];
		if(Sound=="-"){
			cout<<Sound;
			Beep(820,900);}
		else if(Sound=="."){
			cout<<Sound;
			Beep(700,350);}
		else{
			cout<<Sound;
			Beep(0,350);}}
	cout<<"\n\nSonido en Morse terminado"<<endl;
	system("pause");
	return 0;}
