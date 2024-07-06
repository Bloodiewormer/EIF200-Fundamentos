#include <iostream>
using namespace std;

int main() {
	long num =0,unidad =10,residuo =0;
	cout<<"insert number:\n";
	cin>>num;
	system("cls");
	cout<<"Number:"<<num<<endl;
	cout<<"\nrepresentation of number "<<num<<" in an abacus\n"<<endl;
	for(int linea=0;linea<10;++linea){
		residuo = num % unidad;
		num-=residuo;
		for(int bolita =0;bolita<(residuo/(unidad/10));bolita++){
		cout<<"O";}
	cout<<endl;
	unidad = unidad * 10;}
	system("pause");
	return 0;}
