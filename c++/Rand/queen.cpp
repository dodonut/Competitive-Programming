#include <iostream>
using namespace std;
bool val(int linha, int coluna, int * vet){
	int diag = 1;
	for(int i = linha-1; i >= 0; i--){
		if(vet[i] == coluna || vet[i] == coluna-diag || vet[i] == coluna+diag) return false;
		diag++;
	}
	return true;

}

void print(int * vet){
	for(int i = 0; i < 8; i++) cout << vet[i];
	cout << endl;
}

void queen(int linha, int * vet){
	if(linha != 8){
		for(int coluna = 0; coluna < 8; coluna++){
			if(val(linha, coluna, vet)){
				vet[linha] = coluna;
				queen(linha+1, vet);
			}
		}
  	}else print(vet);
}

int main(){
	int * vet = new int[8];
	queen(0, vet);
}
