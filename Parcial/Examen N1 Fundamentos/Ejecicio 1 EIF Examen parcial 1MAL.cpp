#include <iostream>
using namespace std;

int main() {
	string Entrada = "";
	string abaco[]={{"0"},{"00"},{"000"},{"0000"},{"00000"},{"000000"},{"0000000"},{"00000000"},{"000000000"},{" "},{""}};
	string Number;
	string result;
	char NumerosDecimal[]={'1','2','3','4','5','6','7','8','9','0',' '};
	cout<<"insert number:\n";
	cin>>Entrada;
	cout<<"\nNumber:"<<Entrada<<endl;
	cout<<"\nrepresentation of number "<<Entrada<<" in an abacus"<<endl;
	for(int q = 0;q < Entrada.size(); q++){
		for(int j=0;j<10;j++){
			if(Entrada[q]==NumerosDecimal[j]){
				Number+=abaco[j];
				Number+=" ";
				}}}
	
	for(int y = 0; y < Number.size();y++){
		result = Number[y];
		if(result=="0")
			cout<<result;
		else if(result==" "){
			cout<<result<<endl;}}
	cout<<endl<<endl;
	system("pause"); //==> Detener la ejecusion.
	return 0;
}

