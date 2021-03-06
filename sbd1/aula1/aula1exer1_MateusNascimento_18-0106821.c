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

// Ordenação da bolha
void ordenaProprietario(){
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

// Ordenação da bolha
void ordenaVeiculo(){
    int index,aux,c;
    Veiculo temp;
    for(index=0;index<indexVeiculos-1;index++)
        for(aux=0; aux<indexVeiculos-1;aux++){
            for(c=0;c<8&&veiculos[aux].placa[c]==veiculos[aux+1].placa[c];c++);
            if(veiculos[aux+1].placa[c]<veiculos[aux].placa[c]){
                temp = veiculos[aux];
                veiculos[aux] = veiculos[aux+1];
                veiculos[aux+1] = temp;
            }
        }
}

// Verifica se o CPF já existe no armazenamento
int verificaCpf(char *cpf) {
    int index;
    for(index=0;index<indexProprietarios;index++)
        if(strcmp(cpf, proprietarios[index].cpf) == 0)
            return 1;
    return 0;
}

// Verifica se a placa do veículo já existe no armazenamento
int verificaPlaca(char *placa) {
    int index;
    for(index = 0; index < indexVeiculos; index++)
        if(strcmp(placa, veiculos[index].placa) == 0)
            return 1;
    return 0;
}

// Verifica sem o proprietário possui carros cadastrados
int verificaProprietario(char *cpf) {
    int index;
    for(index=0; index<indexVeiculos; index++)
        if(strcmp(veiculos[index].cpfProprietario,cpf) == 0)
            return 1;
    return 0;
}

// Abre os arquivos e popula os vetores de struct com os dados armazenados nos arquivos
void iniciaArquivo() {
    FILE *arquivoProprietarios = fopen("proprietarios.txt", "r");
    FILE *arquivoVeiculos = fopen("veiculos.txt", "r");

    proprietarios = malloc(sizeof(Proprietario));
    veiculos = malloc(sizeof(Veiculo));

    if(arquivoProprietarios!=NULL){
        for(indexProprietarios;fscanf(arquivoProprietarios," %[^\n]",proprietarios[indexProprietarios].cpf)>0; indexProprietarios++){
            fscanf(arquivoProprietarios," %[^\n]",proprietarios[indexProprietarios].nome);
            proprietarios = realloc(proprietarios, sizeof(Proprietario)*(indexProprietarios+2));
        }
        fclose(arquivoProprietarios);
    }
    if(arquivoVeiculos != NULL){
        for(indexVeiculos;fscanf(arquivoVeiculos," %[^\n]",veiculos[indexVeiculos].cpfProprietario)>0; indexVeiculos++){
            fscanf(arquivoVeiculos," %[^\n]",veiculos[indexVeiculos].placa);
            fscanf(arquivoVeiculos," %[^\n]",veiculos[indexVeiculos].marca);
            fscanf(arquivoVeiculos," %[^\n]",veiculos[indexVeiculos].modelo);
            fscanf(arquivoVeiculos," %d",&veiculos[indexVeiculos].ano);
            fscanf(arquivoVeiculos," %[^\n]",veiculos[indexVeiculos].cor);
            veiculos = realloc(veiculos, sizeof(Veiculo)*(indexVeiculos+2));
        }
        fclose(arquivoVeiculos);
    }
}

// Escreve os arquivos com os dados armazenados nos vetores de struct ao final do programa
void insereArquivo () {
    FILE *arquivoProprietarios = fopen("proprietarios.txt", "w");
    FILE *arquivoVeiculos = fopen("veiculos.txt", "w");

    int index;

    ordenaProprietario();
    ordenaVeiculo();

    for(index = 0; index < indexProprietarios; index++)
        if(verificaProprietario(proprietarios[index].cpf)){
            fprintf(arquivoProprietarios, "%s\n", proprietarios[index].cpf);
            fprintf(arquivoProprietarios, "%s\n", proprietarios[index].nome);
        }

    for(index=0;index<indexVeiculos;index++){
        fprintf(arquivoVeiculos, "%s\n", veiculos[index].cpfProprietario);
        fprintf(arquivoVeiculos, "%s\n", veiculos[index].placa);
        fprintf(arquivoVeiculos, "%s\n", veiculos[index].marca);
        fprintf(arquivoVeiculos, "%s\n", veiculos[index].modelo);
        fprintf(arquivoVeiculos, "%d\n", veiculos[index].ano);
        fprintf(arquivoVeiculos, "%s\n", veiculos[index].cor);
    }

    fclose(arquivoProprietarios);
    fclose(arquivoVeiculos);
}

// Cadastra um novo proprietário de veículo(s)
void cadastraProprietario() {
    Proprietario proprietario;
    int erroEntrada;
    int index;

    proprietarios = realloc(proprietarios, sizeof(Proprietario) * (indexProprietarios + 2));

    system("clear");

    printf("=======     CADASTRANDO PROPRIETÁRIO(A)     =======\n\n");
    do{
        erroEntrada = 0;
        printf("Digite o cpf (apenas números): ");
        scanf(" %s",proprietario.cpf);

        if(strlen(proprietario.cpf) != 11){
            erroEntrada = 1;
        }
        for(index = 0; proprietario.cpf[index] != '\0' && erroEntrada == 0; index++){
            if(proprietario.cpf[index] < 48 || proprietario.cpf[index] > 57){
                erroEntrada=1;
            }
        }
        if(erroEntrada)
            printf("\nEntrada inválida! O CPF deve conter apenas números e possuir 11 dígitos, tente novamente.\nExemplo: 12345678910\n\n");
    }while(erroEntrada);

    if(verificaCpf(proprietario.cpf)){
        system("clear");
        printf("Cpf já cadastrado! Pressione enter para continuar...");
        getchar();
        scanf("%c",&enter);
    }
    else{
        printf("Digite o nome completo: ");
        scanf(" %[^\n]",proprietario.nome);
        
        proprietarios[indexProprietarios++] = proprietario;

        system("clear");
        printf("Proprietário cadastrado! Pressione enter para continuar...");
        getchar();
        scanf("%c",&enter);
    }
}

// Cadastra um novo veículo (deve ser possuir um proprietário)
void cadastraVeiculo() {
    Veiculo veiculo;

    int erroEntrada;
    int index;

    veiculos = realloc(veiculos,sizeof(Veiculo) * (indexVeiculos + 2));

    system("clear");

    printf("=======     CADASTRANDO VEÍCULO     =======\n\n");

    do{
        erroEntrada=0;
        printf("Digite o cpf do proprietário (apenas números): ");
        scanf(" %s",veiculo.cpfProprietario);

        if(strlen(veiculo.cpfProprietario)!=11){
            erroEntrada = 1;
        }
        for(index = 0; veiculo.cpfProprietario[index] != '\0' && erroEntrada == 0; index++)
            if(veiculo.cpfProprietario[index] < 48 || veiculo.cpfProprietario[index] > 57)
                erroEntrada = 1;
        if(erroEntrada)
            printf("\nEntrada inválida! O CPF deve conter apenas números e possuir 11 dígitos, tente novamente.\nExemplo: 12345678910\n\n");
    }while(erroEntrada);

    if(!verificaCpf(veiculo.cpfProprietario)){
        system("clear");
        printf("Cpf não encontrado! Cadastre o proprietário antes do veículo.\nPressione enter para continuar...");
        getchar();
        scanf("%c",&enter);
    }
    else{
        do{
            erroEntrada = 0;

            printf("Digite a placa do veículo (apenas letras maiúsculas e números): ");
            scanf(" %s",veiculo.placa);

            if(strlen(veiculo.placa) != 7)
                erroEntrada = 1;

            for(index = 0; veiculo.placa[index] != '\0' && erroEntrada == 0; index++){
                if(index <= 2 && ( veiculo.placa[index] < 65 || veiculo.placa[index] > 90))
                    erroEntrada = 1;
                else if(index > 2 && (veiculo.placa[index] < 48 || veiculo.placa[index] > 57))
                    erroEntrada=1;
            }
            if(erroEntrada){
                printf("\nEntrada inválida! A placa deve conter três letras maiúsculas e quatro números, tente novamente.\nExemplo: ABC1234\n\n");
            }
        }while(erroEntrada);

        if(verificaPlaca(veiculo.placa)){
            system("clear");
            printf("Veículo já cadastrado! Pressione enter para continuar...");
            getchar();
            scanf("%c",&enter);
        }

        else{
            printf("Digite a marca do veículo (Exemplo: Fiat): ");
            scanf(" %[^\n]",veiculo.marca);
            printf("Digite o modelo do veículo (Exemplo: Uno): ");
            scanf(" %[^\n]",veiculo.modelo);
            do{
                erroEntrada=0;
                printf("Digite o ano do veículo (apenas números): ");
                scanf(" %d",&veiculo.ano);

                if(veiculo.ano > 2021 || veiculo.ano < 1870){
                    erroEntrada=1;
                    printf("\nEntrada inválida! Insira um ano entre 1870 e 2021.\n\n");
                }

            }while(erroEntrada);
            printf("Digite a cor do veículo (Exemplo: Vermelho): ");
            scanf(" %[^\n]",veiculo.cor);
            
            veiculos[indexVeiculos++] = veiculo;

            system("clear");
            printf("Veículo cadastrado! Pressione enter para continuar...");
            getchar();
            scanf("%c",&enter);
        }
    }
}

// Imprime todos os dados armazenados
void mostraDados() {
    int veiculoNumero, index, aux;

    ordenaProprietario();
    ordenaVeiculo();

    system("clear");

    printf("======     DADOS CADASTRADOS     =======\n\n");
    for(index = 0; index < indexProprietarios; index++){
        veiculoNumero=0;

        printf("Proprietário %d\n\n    Nome: %s\n    CPF: %s\n\n",index+1,proprietarios[index].nome,proprietarios[index].cpf);

        printf("    Veículos: \n\n");

        for(aux=0; aux < indexVeiculos; aux++){
            if(strcmp(proprietarios[index].cpf,veiculos[aux].cpfProprietario) == 0){
                printf("    Carro %d\n",++veiculoNumero);
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

// Menu inicial
void mostraMenu() {
	char opcao;

    do{        
        system("clear");

        printf("=======     MENU    =======\n\n");
        printf("(1) Cadastrar proprietário(a)\n");
        printf("(2) Cadastrar veículo\n");
        printf("(3) Mostrar dados\n");
        printf("(4) Sair\n");
        printf("\nEscolha uma das opções: ");

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
                    insereArquivo();
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

// Função main
int main(){

    iniciaArquivo();
	mostraMenu();
	
    return 0;
}