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

int indexProprietarios=0, indexVeiculos=0;

int verificaCpf(char *cpf) {
    for(int index=0;index<indexProprietarios;index++){
        if(strcmp(cpf, proprietarios[index].cpf)==0)return 1;
    }
    return 0;
}

int verificaPlaca(char *placa) {
    for(int index=0;index<indexVeiculos;index++){
        if(strcmp(placa, veiculos[index].placa)==0)return 1;
    }
    return 0;
}

void cadastraProprietario() {
    Proprietario proprietario;
    int erroEntrada;

    proprietarios = realloc(proprietarios, sizeof(Proprietario)*(indexProprietarios+2));

    system("clear");

    printf("=====     Cadastrando Proprietário     =====\n");
    do{
        erroEntrada=0;
        printf("Digite o cpf (apenas números): ");
        scanf(" %s",proprietario.cpf);

        if(strlen(proprietario.cpf)>11){
            erroEntrada=1;
        }
        for(int index=0;proprietario.cpf[index]!='\0'&&erroEntrada==0;index++){
            if(proprietario.cpf[index]<48||proprietario.cpf[index]>57){
                erroEntrada=1;
            }
        }
        if(erroEntrada)
            printf("\nEntrada inválida! O CPF deve conter apenas números e possuir 11 dígitos, tente novamente.\nExemplo: 12345678910\n\n");
    }while(erroEntrada);

    if(verificaCpf(proprietario.cpf)){
        printf("Cpf já cadastrado! Pressione enter para continuar...");
        getchar();
        scanf("%c",&enter);
    }
    else{
        printf("\nDigite o nome completo: ");
        scanf(" %[^\n]",proprietario.nome);
        
        proprietarios[indexProprietarios++] = proprietario;

        system("clear");
        printf("Proprietário cadastrado! Pressione enter para continuar...");
        getchar();
        scanf("%c",&enter);
    }
}

void cadastraVeiculo() {
    Veiculo veiculo;

    int erroEntrada;

    veiculos = realloc(veiculos,sizeof(Veiculo)*(indexVeiculos+2));

    system("clear");

    printf("=====     Cadastrando Veículo     =====\n\n");

    do{
        erroEntrada=0;
        printf("Digite o cpf do proprietário (apenas números): ");
        scanf(" %s",veiculo.cpfProprietario);

        if(strlen(veiculo.cpfProprietario)>11){
            erroEntrada=1;
        }
        for(int index=0;veiculo.cpfProprietario[index]!='\0'&&erroEntrada==0;index++){
            if(veiculo.cpfProprietario[index]<48||veiculo.cpfProprietario[index]>57){
                erroEntrada=1;
            }
        }
        if(erroEntrada)
            printf("\nEntrada inválida! O CPF deve conter apenas números e possuir 11 dígitos, tente novamente.\nExemplo: 12345678910\n\n");
    }while(erroEntrada);

    if(!verificaCpf(veiculo.cpfProprietario)){
        printf("Cpf não cadastrado! Cadastre o proprietário antes do veículo.\nPressione enter para continuar...");
        getchar();
        scanf("%c",&enter);
    }
    else{
        do{
            erroEntrada=0;

            printf("Digite a placa do veículo (apenas letras maiúsculas e números): ");
            scanf(" %s",veiculo.placa);

            if(strlen(veiculo.placa)>8)
                erroEntrada=1;

            for(int index=0;veiculo.placa[index]!='\0'&&erroEntrada==0;index++){
                if(index<=3&&(veiculo.placa[index]<65||veiculo.placa[index]>90))
                    erroEntrada=1;
                else if(index>3&&(veiculo.placa[index]<48||veiculo.placa[index]>57))
                    erroEntrada=1;
            }
            if(erroEntrada){
                printf("\nEntrada inválida! A placa deve conter apenas letras maiúsculas e números e deve possuir 8 dígitos, tente novamente.\nExemplo: ABCD1234\n\n");
            }
        }while(erroEntrada);

        if(verificaPlaca(veiculo.placa)){
            system("clear");
            printf("Veículo já cadastrado! Pressione enter para continuar...");
            getchar();
            scanf("%c",&enter);
        }

        else{
            printf("Digite a marca do veículo: ");
            scanf(" %[^\n]",veiculo.marca);
            printf("Digite o modelo do veículo: ");
            scanf(" %[^\n]",veiculo.modelo);
            printf("Digite o ano do veículo (apenas números): ");
            scanf(" %d",&veiculo.ano);
            printf("Digite a cor do veículo: ");
            scanf(" %[^\n]",veiculo.cor);
            
            veiculos[indexVeiculos++] = veiculo;

            system("clear");
            printf("Veículo cadastrado! Pressione enter para continuar...");
            getchar();
            scanf("%c",&enter);
        }
    }
}

void mostraDados() {
    int veiculoNumero;
    system("clear");
    for(int index=0;index<indexProprietarios;index++){
        veiculoNumero=0;

        printf("* Proprietário %d\n    Nome: %s\n    CPF: %s\n\n",index+1,proprietarios[index].nome,proprietarios[index].cpf);

        printf("Seus veículos: \n\n");

        for(int aux=0;aux<indexVeiculos;aux++){
            if(strcmp(proprietarios[index].cpf,veiculos[aux].cpfProprietario)==0){
                printf("    Veículo %d\n",++veiculoNumero);
                printf("    Placa: %s\n",veiculos[aux].placa);
                printf("    Marca: %s\n",veiculos[aux].marca);
                printf("    Modelo: %s\n",veiculos[aux].modelo);
                printf("    Ano: %d\n",veiculos[aux].ano);
                printf("    Cor: %s\n\n",veiculos[aux].cor);
            }
        }
    }
    printf("Pressione enter para continuar...");
    getchar();
    scanf("%c",&enter);
}

void mostraMenu() {
	char opcao;

    do{        
        system("clear");

        printf("=====     MENU    =====\n");
        printf("(1) Cadastrar proprietário\n");
        printf("(2) Cadastrar veículos\n");
        printf("(3) Imprimir dados\n");
        printf("(4) Sair\n");
        printf("Escolha uma das opções: ");

        scanf(" %c",&opcao);


        switch(opcao) {
                case '1':
                    cadastraProprietario();
                    break;
                case '2':
                    cadastraVeiculo();
                    break;
                case '3':
                    mostraDados();
                    break;
                case '4':
                    system("clear");
                    printf("Você escolheu sair, finalizando programa...\n");
                    break;
                default:
                    system("clear");
                    printf("Opção inválida, escolha uma opção entre 1 e 4\n");
                    printf("Pressione enter para continuar...\n");
                    getchar();
                    scanf("%c",&enter);
            }
    }   while(opcao!='4');
}


int main(){
    proprietarios = malloc(sizeof(Proprietario));
    veiculos = malloc(sizeof(Veiculo));

	mostraMenu();
	
    return 0;
}