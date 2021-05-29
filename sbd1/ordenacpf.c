#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct proprietario {
	char nome[200];
	char cpf[20];
} Proprietario;

typedef struct veiculo {
	char cpfProprietario[20];
	char placa[20];
	char marca[50];
	char modelo[100];
	int ano;
	char cor[20];
} Veiculo;

char enter;

Proprietario *proprietarios;
Veiculo *veiculos;

void ordenaProprietario(int indexProprietarios){
    int index,aux,c;
    Proprietario temp;
    for(index=0;index<indexProprietarios-1;index++)
        for(aux=0; aux<indexProprietarios-1;aux++){
            for(c=0;c<11&&proprietarios[aux].cpf[c]==proprietarios[aux+1].cpf[c];c++);
            if(proprietarios[aux+1].cpf[c]<proprietarios[aux].cpf[c]){
                temp = proprietarios[aux];
                proprietarios[aux] = proprietarios[aux+1];
                proprietarios[aux+1] = temp;
            }
        }
}

int main() {
    proprietarios = malloc(2*sizeof(Proprietario));
    strcpy(proprietarios[0].cpf,"12345678912");
    strcpy(proprietarios[0].nome,"maia maia");
    strcpy(proprietarios[1].cpf,"12345678911");
    strcpy(proprietarios[1].nome,"masculo maia");

    ordenaProprietario(2);

    for(int i=0;i<2;i++){
        printf("%s\n",proprietarios[i].cpf);
        printf("%s\n",proprietarios[i].nome);
    }

    return 0;
}