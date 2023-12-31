// T7

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <unistd.h>
#define TAM 50

int checa_carro(char * placa);
int checa_cliente(char * cpf);

char opcionais[][TAM]={ {"4.portas"}, {"cambio.automatico"}, {"vidros.eletricos"}, {"abs"}, {"air.bag"}, {"ar.condicionado"}, {"banco.couro"}, {"sensor.estacionamento"}};

char fabricantes[][TAM] = {{"chevrolet"}, {"fiat"}, {"toyota"}, {"volkswagen"}};

char modelosss[][TAM] = {{"onix"}, {"s10"}, {"celta"}, {"strada"}, {"palio"}, {"corolla"}, {"hillux"}, {"saveiro"}, {"voyage"}, {"gol"}};

// Retorna um número aleatório dentro do limite estabelecido
int nAleatorio(int menor, int maior){
  return menor + (rand() % (maior - menor + 1));
}

struct CARRO {
  char placa[9]; //AAA-1234
  char modelo[TAM]; //gol, celta, palio, ...
  char fabricante[TAM]; //chevrolet, fiat, ...
  int ano_fabricacao; //1980 à 2016
  int ano_modelo; //1980 à 2017
  char combustivel[TAM]; //alcool, gasolina, flex, diesel
  char cor[TAM]; //branca, prata, preta
  int opcional[8]; //ver matriz opcionais
  float preco_compra;
};

struct ENDERECO {
  char rua[TAM];
  int numero;
  char bairro[TAM];
  char cidade[TAM];
  char estado[3];
  char cep[11]; //99.999-999
};

struct TELEFONE {
 char telefone[14]; //99 99999-9999
};

struct CLIENTE {
  char nome[TAM];
  char cpf[15]; //999.999.999-99
  struct ENDERECO endereco;
  struct TELEFONE residencial;
  struct TELEFONE celular[5];
  float renda_mensal;
};

struct DATA {
  int dia, mes, ano;
};

struct VENDA_CARRO {
  char placa_car[9];
  char cpf_cli[15];
  float preco_venda;
  struct DATA data_venda;
};

// Gera todas as informações necessárias do carro 
void geraCarroInfo(char * modelo, char * fabricante, int * anoFab, int * anoMod, char * combustivel, char * cor, int * opcional, float * preco){
  char * modelos[] = {"onix", "s10", "celta", "strada", "palio", "corolla", "hillux", "saveiro", "voyage", "gol"};

  strcpy(fabricante, "");

  int n = nAleatorio(0, 9);

  if(n < 3){
    strcpy(fabricante, "chevrolet");
  } else if(n < 5){
    strcpy(fabricante, "fiat");
  }else if(n < 7){
    strcpy(fabricante, "toyota");
  } else {
    strcpy(fabricante, "volkswagen");
  }

  strcpy(modelo, modelos[n]);

  switch (n){
    case 0:
      *anoMod = 2011 + (rand() % (2023 - 2011 + 1)); 
      *anoFab = 2011; 
      break;
    case 1:
      *anoFab = 1993; 
      *anoMod = 1993 + (rand() % (2023 - 1993 + 1)); 
      break;
    case 2:
      *anoFab = 2000; 
      *anoMod = 2000 + (rand() % (2023 - 2000 + 1)); 
      break;
    case 3:
      *anoFab = 1997; 
      *anoMod = 1997 + (rand() % (2023 - 1997 + 1)); 
      break;
    case 4:
      *anoFab = 1996; 
      *anoMod = 1996 + (rand() % (2023 - 1996 + 1)); 
      break;
    case 5:
      *anoFab = 2000; 
      *anoMod = 2000 + (rand() % (2023 - 2000 + 1)); 
      break;
    case 6:
      *anoFab = 1984; 
      *anoMod = 1984 + (rand() % (2023 - 1984 + 1)); 
      break;
    case 7:
      *anoFab = 2008; 
      *anoMod = 2008 + (rand() % (2023 - 2008 + 1)); 
      break;
    case 8:
      *anoFab = 1982; 
      *anoMod = 1982 + (rand() % (2023 - 1982 + 1)); 
      break;
    case 9:
      *anoFab = 1991;
      *anoMod = 1991 + (rand() % (2023 - 1991 + 1));
    default:
      break;
  }

  char * combustiveis[] = {"flex", "gasolina", "alcool", "diesel"};
  strcpy(combustivel, combustiveis[nAleatorio(0, 3)]);

  char * cores[] = {"preto", "marrom", "branco", "prata", "vermelho", "amarelo", "cinza", "laranja", "verde"};
  strcpy(cor, cores[nAleatorio(0, 8)]);

  *opcional = nAleatorio(0, 7);
  *preco = nAleatorio(6000, 190000);
}

// Gera uma placa aleatória
void geraPlaca(char * placa){
  char letras[27][2];
  char *numeros[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

  for(int i = 0; i < 26; i++){
    letras[i][0] = 'A' + i;
    letras[i][1] = '\0';
  }


  for(int i = 0; i < 3; i++){
    int nAleatorio = rand() % 26;
    strcat(placa, letras[nAleatorio]);
  }
  strcat(placa, "-");
  for(int i = 0; i < 4; i++){
    int nAleatorio = rand() % 9;
    strcat(placa, numeros[nAleatorio]);
  }

}

// Insere um carro no cadastro gerando todas as informações necessárias
void inserirCarro(){
  char placa[9], modelo[11], fabricante[11], combustivel[8], cor[10], esc;
  int anoFab, anoMod, opcional;
  float preco;
  struct CARRO car;

  geraPlaca(placa);
  geraCarroInfo(modelo, fabricante, &anoFab, &anoMod, combustivel, cor, &opcional, &preco);
  do{
    system("cls");
    printf("=-=-= DESEJA O SEGUINTE CARRO? =-=-=\n");
    printf("-             PLACA -> %s\n", placa);
    printf("-            MODELO -> %s\n", modelo);
    printf("-        FABRICANTE -> %s\n", fabricante);
    printf("- ANO DE FABRICACAO -> %d\n", anoFab);
    printf("-     ANO DO MODELO -> %d\n", anoMod);
    printf("-       COMBUSTIVEL -> %s\n", combustivel);
    printf("-               COR -> %s\n", cor);
    printf("-          OPCIONAL -> %s\n", opcionais[opcional]);
    printf("-   PRECO DE COMPRA -> R$%.2f\n", preco);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("S/N -> ");
    scanf(" %c", &esc);
    esc = toupper(esc);
    if(esc == 'S'){
      strcpy(car.placa, placa);
      strcpy(car.modelo, modelo);
      strcpy(car.fabricante, fabricante);
      car.ano_fabricacao = anoFab;
      car.ano_modelo = anoMod;
      strcpy(car.combustivel, combustivel);
      strcpy(car.cor, cor);
      car.opcional[0] = opcional;
      car.preco_compra = preco;
      FILE * fp = fopen("carros.bin", "ab");

      if(fp == NULL){
        printf("ERRO DE ABERTURA DE ARQUIVO!\n");
        exit(100);
      }

      fwrite(&car, sizeof(car), 1, fp);
      fclose(fp);
      printf("------------ SUCESSO ------------\n");
      printf("| CARRO CADASTRADO COM SUCESSO! |\n");
      printf("---------------------------------\n");

    } else if(esc == 'N'){
      printf("-------- AVISO --------\n");
      printf("| OPERACAO CANCELADA! |\n");
      printf("-----------------------\n");
    } else {
      printf("-------- ERRO -------\n");
      printf("| ENTRADA INVALIDA! |\n");
      printf("---------------------\n");
      system("pause");
    }
  } while(esc != 'S' && esc != 'N');
}

// Retorna a existência da venda de um carro
int checa_venda_carro(char * placa){
  const char *teste = "vendas.bin";
  if(access(teste, F_OK) == -1){
    return 0;
  }

  FILE * fp = fopen("vendas.bin", "rb");
  struct VENDA_CARRO venda;

  if(fp == NULL){
    printf("ERRO AO ABRIR O ARQUIVO PARA CHECAR VENDA DO CARRO!\n");
    exit(100);
  }

  fseek(fp, 0, SEEK_SET);

  while(!feof(fp)){
    if(fread(&venda, sizeof(venda), 1, fp) > 0){
      if(strcmp(placa, venda.placa_car) == 0){
        fclose(fp);
        return 1;
      } 
    }
  }

  fclose(fp);
  return 0;
}

// Realiza a remoção de um carro
void apaga_carro(char * placa){
  FILE * original = fopen("carros.bin", "rb");
  if(original == NULL){
    printf("ERRO AO ABRIR O ARQUIVO ORIGINAL!\n");
    exit(100);
  }

  FILE * temporario = fopen("temp.bin", "ab");
  if(temporario == NULL){
    printf("ERRO AO ABRIR O ARQUIVO TEMPORARIO!\n");
    fclose(original);
    exit(100);
  }

  fseek(original, 0, SEEK_SET);
  fseek(temporario, 0, SEEK_SET);

  struct CARRO carro;
  while(!feof(original)){ // Copia todos os carros ignorado aquele que deseja excluir
    if(fread(&carro, sizeof(carro), 1, original) > 0){
      if(strcmp(placa, carro.placa) != 0){
        fwrite(&carro, sizeof(carro), 1, temporario);
      }
    }
  }

  fclose(original);
  fclose(temporario);

  if(remove("carros.bin") != 0){  // Apaga arquivo de carros original
    printf("ERRO AO DELETAR ARQUIVO!\n");
    exit(100);
  }

  if(rename("temp.bin", "carros.bin") != 0){  // Renomeia arquivo temporario
    printf("ERRO AO RENOMEAR ARQUIVO!\n");
    exit(100);
  }

  printf("EXCLUSAO REALIZADA COM SUCESSO!\n");
}

// Retorna de forma crescente o fabricante dos carros recebidos
int comparar_carros_fabricante(const void *a, const void *b){
  const char *fabricante1 = ((struct CARRO *)a)->fabricante;
  const char *fabricante2 = ((struct CARRO *)b)->fabricante;
  return strcmp(fabricante1, fabricante2);
}

// Mostra os carros ordenados pelo fabricante
void listar_carro_fabricante(){
  struct CARRO carros[100];

  FILE * fp = fopen("carros.bin", "rb");
  if(fp == NULL){
    printf("ERRO AO ABRIR ARQUIVO PARA LISTAGEM DOS CARROS!\n");
    exit(100);
  }

  fseek(fp, 0, SEEK_SET);

  int n = 0;
  while(fread(&carros[n], sizeof(struct CARRO), 1, fp) == 1) n++; // Conta todos os carros e armazena num vetor

  fclose(fp);

  qsort(carros, n, sizeof(carros[0]), comparar_carros_fabricante);  // Função de ordenação da biblioteca stdlib.h

  system("cls");
  for(int i = 0; i < n; i++){
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("-             PLACA -> %s\n", carros[i].placa);
    printf("-            MODELO -> %s\n", carros[i].modelo);
    printf("-        FABRICANTE -> %s\n", carros[i].fabricante);
    printf("- ANO DE FABRICACAO -> %d\n", carros[i].ano_fabricacao);
    printf("-     ANO DO MODELO -> %d\n", carros[i].ano_modelo);
    printf("-       COMBUSTIVEL -> %s\n", carros[i].combustivel);
    printf("-               COR -> %s\n", carros[i].cor);
    printf("-          OPCIONAL -> %s\n", opcionais[carros[i].opcional[0]]);
    printf("-   PRECO DE COMPRA -> R$%.2f\n", carros[i].preco_compra);
  }
}

// Lista os carros com os opcionais escolhidos
void listar_carros_opcionais(int opcional[], int tam){
  int cont = 0;
  FILE * fp = fopen("carros.bin", "rb");
  if(fp == NULL){
    printf("ERRO AO ABRIR ARQUIVO PARA LISTAGEM POR OPCIONAL\n");
    exit(100);
  }

  struct CARRO carro;

  system("cls");
  while (fread(&carro, sizeof(carro), 1, fp) > 0) { // Exibe todos os carros com os opcionais escolhidos
        for (int i = 0; i < tam; i++) {
            if (carro.opcional[0] == opcional[i]-1) {
                printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                printf("-             PLACA -> %s\n", carro.placa);
                printf("-            MODELO -> %s\n", carro.modelo);
                printf("-        FABRICANTE -> %s\n", carro.fabricante);
                printf("- ANO DE FABRICACAO -> %d\n", carro.ano_fabricacao);
                printf("-     ANO DO MODELO -> %d\n", carro.ano_modelo);
                printf("-       COMBUSTIVEL -> %s\n", carro.combustivel);
                printf("-               COR -> %s\n", carro.cor);
                printf("-          OPCIONAL -> %s\n", opcionais[carro.opcional[0]]);
                printf("-   PRECO DE COMPRA -> R$%.2f\n", carro.preco_compra);
                cont++;
            }
        }
    }

  fclose(fp);
  if(!cont){
    printf("NAO FOI ENCONTRADO NENHUM CARRO!\n");
  }
}

// Lista os carros com o ano de fabricação dentro do limite recebido
void listar_carros_ano(int anoInicio, int anoFim){
  int cont = 0;
  FILE * fp = fopen("carros.bin", "rb");
  if(fp == NULL){
    printf("ERRO AO ABRIR ARQUIVO PARA LISTAGEM POR OPCIONAL\n");
    exit(100);
  }

  struct CARRO carro;

  system("cls");
  while (fread(&carro, sizeof(carro), 1, fp) > 0){  // Exibe todos os carros no intervalo definido
            if (carro.ano_fabricacao >= anoInicio && carro.ano_fabricacao <= anoFim) {
                printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
                printf("-             PLACA -> %s\n", carro.placa);
                printf("-            MODELO -> %s\n", carro.modelo);
                printf("-        FABRICANTE -> %s\n", carro.fabricante);
                printf("- ANO DE FABRICACAO -> %d\n", carro.ano_fabricacao);
                printf("-     ANO DO MODELO -> %d\n", carro.ano_modelo);
                printf("-       COMBUSTIVEL -> %s\n", carro.combustivel);
                printf("-               COR -> %s\n", carro.cor);
                printf("-          OPCIONAL -> %s\n", opcionais[carro.opcional[0]]);
                printf("-   PRECO DE COMPRA -> %.2f\n", carro.preco_compra);
                cont++;
            }
        }

  fclose(fp);
  if(!cont){
    printf("NAO FOI ENCONTRADO NENHUM CARRO!\n");
  }
}

// Menu de carro
void menuCarro(){
  int esc;
  do{
    esc = 0;
    system("cls");
    printf("------------------------------------------------------------------------------\n");
    printf("| 1. INSERIR UM CARRO                                                        |\n");
    printf("| 2. EXCLUIR UM CARRO                                                        |\n");
    printf("| 3. CARROS DISPONIVEIS PARA VENDA ORDENADOS POR FABRICANTE E MODELO         |\n");
    printf("| 4. CARROS DISPONIVEIS PARA VENDA POR SELECAO DE UM OU MAIS OPCIONAIS       |\n");
    printf("| 5. CARROS DISPONIVEIS PARA VENDA POR SELECAO DA FAIXA DO ANO DE FABRICACAO |\n");
    printf("| 6. VOLTAR                                                                  |\n");
    printf("------------------------------------------------------------------------------\n");
    printf("-> ");
    scanf("%d", &esc);
    switch (esc){
      case 1:
        inserirCarro();
        system("pause");
        break;
      case 2:{
        char placa[9];
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("- INSIRA A PLACA DO CARRO -> ");
        getchar();
        fgets(placa, sizeof(placa), stdin);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        if(checa_carro(placa) == 2){
          if(!checa_venda_carro(placa)){
            apaga_carro(placa);
          } else {
            printf("--------- ERRO ----------\n");
            printf("| CARRO JA FOI VENDIDO! |\n");
            printf("-------------------------\n");
          }
        } else {
          printf("------- ERRO --------\n");
          printf("| CARRO INEXISENTE! |\n");
          printf("---------------------\n");
        }
      }
        system("pause");
        break;
      case 3:
        listar_carro_fabricante();
        system("pause");
        break;
      case 4:{
        int opcional[8], cont = 0, opc = 0;
        system("cls");
        printf("-------------------------------------------------------\n");
        printf("| 1. 4 PORTAS           | 2. CAMBIO AUTOMATICO        |\n");
        printf("| 3. VIDROS ELETRICOS   | 4. ABS                      |\n");
        printf("| 5. AIR BAGS           | 6. AR CONDICIONADO          |\n");
        printf("| 7. BANCO DE COURO     | 8. SENSOR DE ESTACIONAMENTO |\n");
        printf("-------------------------------------------------------\n");
        printf("INSIRA OS OPCIONAIS QUE DESEJA (INSIRA -1 PARA FINALIZAR) \n");
        while(opc != -1 && cont < 8){
          printf("-> ");
          scanf("%d", &opc);
          if(opc > 8){
            system("cls");
            printf("-------- ERRO -------\n");
            printf("| ENTRADA INVALIDA! |\n");
            printf("---------------------\n");
            system("pause");
            continue;
          }
          if(opc < 1){
            break;
          }
          opcional[cont++] = opc;
        }
        listar_carros_opcionais(opcional, cont);
      }
        system("pause");

        break;
      case 5: {
        int anoInicio, anoFim;
        system("cls");
        printf("---------------------------\n");
        printf("- INSIRA O ANO INICIAL -> ");
        scanf("%d", &anoInicio);
        printf("---------------------------\n");
        printf("- INSIRA O ANO FINAL -> ");
        scanf("%d", &anoFim);
        printf("---------------------------\n");
        listar_carros_ano(anoInicio, anoFim);
      }
        system("pause");
      break;
      case 6:
        break;
      default:
        printf("-------- ERRO -------\n");
        printf("| ENTRADA INVALIDA! |\n");
        printf("---------------------\n");
        system("pause");
        break;
    }
  } while(esc != 6);
}

char * gera_nome(){
  char *nomes[20] = {"Alice", "Bob", "Carol", "David", "Eve", "Frank", "Grace", "Hannah", "Isaac", "Jack", "Katherine", "Liam", "Mia", "Noah", "Olivia", "Peter", "Quinn", "Rachel", "Samuel", "Taylor"};
  static char nome[20];

  strcpy(nome, nomes[nAleatorio(0, 19)]);
  return nome;
}

// Retorna um CPF válido
char* gera_cpf_valido() {
    int soma = 0, resto = 0;
    int multiplicador1[9] = { 10, 9, 8, 7, 6, 5, 4, 3, 2 };
    int multiplicador2[10] = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 };

    // srand(time(NULL));
    char semente[14];
    // Gera valor aleatório, formata para ter 9 dígitos e insere no vetor
    sprintf(semente, "%09d", rand() % 900000000 + 100000000);

    for (int i = 0; i < 9; i++)
        // Mulitiplica cada número do CPF pelo mulitiplicador respectivo
        soma += (semente[i] - '0') * multiplicador1[i];

    resto = soma % 11;
    // Gera primeiro dígito verificador
    if (resto < 2)
        resto = 0;
    else
        resto = 11 - resto;

    // Insere primeiro dígito verificador no vetor
    sprintf(semente + 9, "%d", resto);
    soma = 0;

    for (int i = 0; i < 10; i++)
        // Mulitiplica cada número do CPF pelo mulitiplicador respectivo
        soma += (semente[i] - '0') * multiplicador2[i];

    resto = soma % 11;
    // Gera segundo dígito verificador
    if (resto < 2)
        resto = 0;
    else
        resto = 11 - resto;

    // Insere primeiro dígito verificador no vetor
    sprintf(semente + 10, "%d", resto);


    // Formata CPF no modelo 999.999.999-99
    static char cpf_formatado[15];
    sprintf(cpf_formatado, "%c%c%c.%c%c%c.%c%c%c-%c%c", semente[0], semente[1], semente[2], semente[3], semente[4], semente[5], semente[6], semente[7], semente[8], semente[9], semente[10]);

    return cpf_formatado;
}

// Retorna um CEP
void * gera_cep() {
  static char cep[11];
  int parte1 = rand() % 100;
  int parte2 = rand() % 1000;
  int parte3 = rand() % 1000;

  sprintf(cep, "%02d.%03d-%03d", parte1, parte2, parte3);
  return cep;
}

// Retorna um endereço
struct ENDERECO gera_endereco(){
  char * ruas[20] = { "Rua A", "Rua B", "Rua C", "Rua D", "Rua E", "Rua F", "Rua G", "Rua H", "Rua I", "Rua J", "Rua K", "Rua L", "Rua M", "Rua N", "Rua O", "Rua P", "Rua Q", "Rua R", "Rua S", "Rua T" };
  char * bairros[20] = { "Bairro da Amizade", "Bairro das Flores", "Bairro da Liberdade", "Bairro do Sol", "Bairro Esperanca", "Bairro Felicidade", "Bairro Harmonia", "Bairro Primavera", "Bairro Recanto Verde", "Bairro Sossego", "Bairro Vila Alegre", "Bairro Vista Bela", "Bairro Novo Horizonte", "Bairro Jardim Azul", "Bairro Vale Encantado", "Bairro do Lago", "Bairro das Montanhas", "Bairro da Lua", "Bairro da Paz", "Bairro Estrela Brilhante" };
  char * cidades[20] = { "Cidade das Maravilhas", "Cidade Encantada", "Cidade Radiante", "Cidade dos Sonhos", "Cidade Luz", "Cidade da Alegria", "Cidade da Esperanca", "Cidade Magica", "Cidade das Cores", "Cidade Bela Vista", "Cidade Serrana", "Cidade Oasis", "Cidade do Futuro", "Cidade Celestial", "Cidade Paradisiaca", "Cidade do Arco-Iris", "Cidade das Mares", "Cidade das Estrelas", "Cidade dos Ventos", "Cidade Harmoniosa" };
  char * estados[20] = { "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN" };
  static struct ENDERECO endereco;
  strcpy(endereco.rua, ruas[rand() % 20]);
  strcpy(endereco.bairro, bairros[rand() % 20]);
  strcpy(endereco.cidade, cidades[rand() % 20]);
  strcpy(endereco.estado, estados[rand() % 20]);
  strcpy(endereco.cep, gera_cep());
  endereco.numero = 100 + (rand() % 9999 - 100 + 1);
  return endereco;
}

// Retorna um número de telefone eleatório
struct TELEFONE gera_telefone(){
  struct TELEFONE telefone;
  int parte1 = rand() % 99;
  int parte2 = rand() % 9999;
  int parte3 = rand() % 9999;

  sprintf(telefone.telefone, "%02d 9%04d-%04d", parte1, parte2, parte3);
  return telefone;
}

// Insere um cliente no cadastro gerando todas as informações necessárias
void inserirCliente(){
  char * nome = gera_nome();
  char * cpf = gera_cpf_valido();
  struct ENDERECO endereco = gera_endereco();
  struct TELEFONE residencial = gera_telefone();
  struct TELEFONE celular[5];
  celular[0] = gera_telefone(); celular[1] = gera_telefone(); celular[2] = gera_telefone(); celular[3] = gera_telefone(); celular[4] = gera_telefone();
  float renda_mensal = nAleatorio(1200, 10000);
  char esc;
  do{
    system("cls");
    printf("=-= VOCE DESEJA INSERIR O SEGUINTE CLIENTE? =-=\n");
    printf("-                NOME -> %s\n", nome);
    printf("-                 CPF -> %s\n", cpf);
    printf("- ENDERECO: \n");
    printf("  -    RUA -> %s\n", endereco.rua);
    printf("  - NUMERO -> %d\n", endereco.numero);
    printf("  - BAIRRO -> %s\n", endereco.bairro);
    printf("  - CIDADE -> %s\n", endereco.cidade);
    printf("  - ESTADO -> %s\n", endereco.estado);
    printf("  -    CEP -> %s\n", endereco.cep);
    printf("- TELEFONE RESIDENCIAL -> %s\n", residencial.telefone);
    printf("- TELEFONE CELULAR: \n");
    for(int i = 0; i < 5; i++){
      printf("  -           %d -> %s\n", i+1, celular[i].telefone);
    }
    printf("-         RENDA MENSAL -> R$%.2f\n", renda_mensal);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("S/N -> ");
    scanf(" %c", &esc);
    esc = toupper(esc);

    switch (esc){
      case 'S':{
        struct CLIENTE cliente;
        strcpy(cliente.nome, nome);
        strcpy(cliente.cpf, cpf);
        cliente.endereco = endereco;
        cliente.residencial = residencial;
        for(int i = 0; i < 5; i++){
          cliente.celular[i] = celular[i];
        }
        cliente.renda_mensal = renda_mensal;
        FILE * fp = fopen("clientes.bin", "ab");
        if(fp == NULL){
          printf("ERRO NA ABERTURA DO ARQUIVO!\n");
          exit(100);
        }
        fwrite(&cliente, sizeof(cliente), 1, fp);
        fclose(fp);
        printf("------------- SUCESSO -------------\n");
        printf("| CLIENTE CADASTRADO COM SUCESSO! |\n");
        printf("-----------------------------------\n");
      }
      break;
      case 'N':
        printf("-------- AVISO --------\n");
        printf("| OPERACAO CANCELADA! |\n");
        printf("-----------------------\n");
        break;
      default:
        printf("-------- ERRO -------\n");
        printf("| ENTRADA INVALIDA! |\n");
        printf("---------------------\n");
        system("pause");
        break;
    }
  } while(esc != 'S' && esc != 'N');
}

// Retorna se um cliente já realizou uma venda
int checa_venda_cliente(char * cpf){
  const char *teste = "vendas.bin";
  if(access(teste, F_OK) == -1){
    return 0;
  }

  struct VENDA_CARRO venda;
  FILE * fp = fopen("vendas.bin", "rb");

  if(fp == NULL){
    printf("ERRO AO ABRIR O ARQUIVO PARA CHECAR COMPRA DO CLIENTE!\n");
    exit(100);
  }

  fseek(fp, 0, SEEK_SET);

  while(!feof(fp)){
    if(fread(&venda, sizeof(venda), 1, fp) > 0){
      if(strcmp(cpf, venda.cpf_cli) == 0){
        fclose(fp);
        return 1;
      };
    }
  }
  
  fclose(fp);
  return 0;
}

// Realiza a remoção de um cliente desejado
void apaga_cliente(char * cpf){
  FILE * original = fopen("clientes.bin", "rb");
  if(original == NULL){
    printf("ERRO AO ABRIR ARQUIVO ORIGINAL PARA APAGAR CLIENTE!\n");
    exit(100);
  }

  FILE * temporario = fopen("temp.bin", "ab");
  if(temporario == NULL){
    printf("ERRO AO ABRIR ARQUIVO TEMPORARIO PARA APAGAR CLIENTE!\n");
    fclose(original);
    exit(100);
  }

  struct CLIENTE cliente;

  fseek(original, 0, SEEK_SET);
  fseek(temporario, 0, SEEK_SET);

  while(!feof(original)){ // Copia clientes ignorando aquele que deseja apagar
    if(fread(&cliente, sizeof(cliente), 1, original) > 0){
      if(strcmp(cpf, cliente.cpf) != 0){
        fwrite(&cliente, sizeof(cliente), 1, temporario);
      }
    }
  }

  fclose(original);
  fclose(temporario);

  if(remove("clientes.bin") != 0){  // Remove arquivo de clientes original
    printf("ERRO AO DELETAR ARQUIVO DE CLIENTES!\n");
    exit(100);
  }

  if(rename("temp.bin", "clientes.bin") != 0){  // Renomeia arquivo temporário
    printf("ERRO AO RENOMEAR ARQUIVO DE CLIENTES!\n");
    exit(100);
  }
  printf("------------- SUCESSO -------------\n");
  printf("| EXCLUSAO REALIZADA COM SUCESSO! |\n");
  printf("-----------------------------------\n");

}

// Retorna de forma crescente os nomes dos clientes recebidos
int comparar_clientes_nome(const void *a, const void *b){
  const char *nome1 = ((struct CLIENTE *)a)->nome;
  const char *nome2 = ((struct CLIENTE *)b)->nome;
  return strcmp(nome1, nome2);
}

// Mostra os clientes ordenados pelo nome
void listar_clientes_nome(){
  struct CLIENTE clientes[100];

  FILE * fp = fopen("clientes.bin", "rb");
  if(fp == NULL){
    printf("ERRO AO ABRIR ARQUIVO PARA LISTAGEM!\n");
    exit(100);
  }

  fseek(fp, 0, SEEK_SET);

  int n = 0;
  while(fread(&clientes[n], sizeof(struct CLIENTE), 1, fp) == 1) n++; // Conta quantos clietes existem e armaneza num vetor

  fclose(fp);

  qsort(clientes, n, sizeof(clientes[0]), comparar_clientes_nome);  // Função de ordenação da biblioteca stdlib.h

  system("cls");
  for(int i = 0; i < n; i++){
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("-                 NOME -> %s\n", clientes[i].nome);
    printf("-                  CPF -> %s\n", clientes[i].cpf);
    printf("-   ENDERECO:\n");
    printf("  -    RUA -> %s\n", clientes[i].endereco.rua);
    printf("  - NUMERO -> %d\n", clientes[i].endereco.numero);
    printf("  - BAIRRO -> %s\n", clientes[i].endereco.bairro);
    printf("  - CIDADE -> %s\n", clientes[i].endereco.cidade);
    printf("  - ESTADO -> %s\n", clientes[i].endereco.estado);
    printf("  -    CEP -> %s\n", clientes[i].endereco.cep);
    printf("- TELEFONE RESIDENCIAL -> %s\n", clientes[i].residencial.telefone);
    printf("- TELEFONE CELULAR:\n");
    for(int j = 0; j < 5; j++){
      printf(" -            %d -> %s\n", j+1, clientes[i].celular[j].telefone);
    }
    printf("-         RENDA MENSAL -> R$%.2f\n", clientes[i].renda_mensal);
  }
}

// Retorna de forma crescente a renda dos clientes recebidos
int comparar_clientes_renda(const void *a, const void *b){
  const float renda1 = ((struct CLIENTE *)a)->renda_mensal;
  const float renda2 = ((struct CLIENTE *)b)->renda_mensal;
  return (renda1 - renda2);
}

// Mostra os clientes ordenados pela renda mensal
void listar_clientes_renda(){
  struct CLIENTE clientes[100];

  FILE * fp = fopen("clientes.bin", "rb");
  if(fp == NULL){
    printf("ERRO AO ABRIR ARQUIVO PARA LISTAGEM!\n");
    exit(100);
  }

  fseek(fp, 0, SEEK_SET);

  int n = 0;
  while(fread(&clientes[n], sizeof(struct CLIENTE), 1, fp) == 1) n++; // Conta quantos clientes existem e armazena num vetor

  fclose(fp);

  qsort(clientes, n, sizeof(clientes[0]), comparar_clientes_renda); // Função de ordenação da biblioteca stdlib.h

  system("cls");
  for(int i = 0; i < n; i++){
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("-                 NOME -> %s\n", clientes[i].nome);
    printf("-                  CPF -> %s\n", clientes[i].cpf);
    printf("-   ENDERECO:\n");
    printf("  -    RUA -> %s\n", clientes[i].endereco.rua);
    printf("  - NUMERO -> %d\n", clientes[i].endereco.numero);
    printf("  - BAIRRO -> %s\n", clientes[i].endereco.bairro);
    printf("  - CIDADE -> %s\n", clientes[i].endereco.cidade);
    printf("  - ESTADO -> %s\n", clientes[i].endereco.estado);
    printf("  -    CEP -> %s\n", clientes[i].endereco.cep);
    printf("- TELEFONE RESIDENCIAL -> %s\n", clientes[i].residencial.telefone);
    printf("- TELEFONE CELULAR:\n");
    for(int j = 0; j < 5; j++){
          printf(" -            %d -> %s\n", j+1, clientes[i].celular[j].telefone);
    }
    printf("-         RENDA MENSAL -> R$%.2f\n", clientes[i].renda_mensal);
  }
}

// Menu de cliente
void menuCliente(){
  int esc;
  do{
    system("cls");
    printf("-------------------------------------------------------------\n");
    printf("| 1. INSERIR UM CLIENTE                                     |\n");
    printf("| 2. EXCLUIR UM CLIENTE                                     |\n");
    printf("| 3. CLIENTES ORDENADOS POR NOME                            |\n");
    printf("| 4. CLIENTES ORDENADOS PELA FAIXA DE RENDA SALARIAL MENSAL |\n");
    printf("| 5. VOLTAR                                                 |\n");
    printf("-------------------------------------------------------------\n");
    printf("-> ");
    scanf("%d", &esc);
    switch (esc){
      case 1:
        inserirCliente();
        system("pause");
        break;
      case 2:{
        char cpf[15];
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("- INSIRA O CPF DO CLIENTE -> ");
        getchar();
        fgets(cpf, sizeof(cpf), stdin);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        if(checa_cliente(cpf) == 3){
          if(!checa_venda_cliente(cpf)){
            apaga_cliente(cpf);
          } else {
            printf("--------------- ERRO --------------\n");
            printf("| CLIENTE JA REALIZOU UMA COMPRA! |\n");
            printf("-----------------------------------\n");
          }
        } else {
          printf("--------- ERRO ---------\n");
          printf("| CLIENTE INEXISTENTE! |\n");
          printf("------------------------\n");
        }
      }
        system("pause");
        break;
      case 3:
        listar_clientes_nome();
        system("pause");
        break;
      case 4:
        listar_clientes_renda();
        system("pause");
        break;
      case 5:
        break;
      default:
        printf("------ ERRO -------\n");
        printf("| OPCAO INVALIDA! |\n");
        printf("-------------------\n");
        break;
    }
  }while(esc != 5);
}

// Retorna a existência de um carro
int checa_carro(char * placa){
  FILE * fp = fopen("carros.bin", "rb");
  struct CARRO carro;
  int check = 0;

  if(fp == NULL){
    printf("ERRO AO ABRIR O ARQUIVO PRA CHECAR CARRO!\n");
    exit(100);
  }

  fseek(fp, 0, SEEK_SET);

  while(!feof(fp)){
    if(fread(&carro, sizeof(carro), 1, fp) > 0){
      if(strcmp(placa, carro.placa) == 0){
        check = 2;
      }
    }
  }
  fclose(fp);
  return check;
}

// Retorna a existência de um cliente
int checa_cliente(char * cpf){
  FILE * fp = fopen("clientes.bin", "rb");
  struct CLIENTE cliente;
  int check = 0;

  if(fp == NULL){
    printf("ERRO AO ABRIR O ARQUIVO!\n");
    exit(100);
  }

  fseek(fp, 0, SEEK_SET);

  while(!feof(fp)){
    if(fread(&cliente, sizeof(cliente), 1, fp) > 0){
      if(strcmp(cpf, cliente.cpf) == 0){
        check = 3;
      }
    }
  }

  fclose(fp);
  return check;
}

// Retorna dia, mês e ano atual
struct DATA retorna_data(){
  struct DATA data; 
  time_t tempo;
  struct tm * tempo_info;
  time(&tempo);
  tempo_info = localtime(&tempo);
  data.dia = tempo_info->tm_mday;
  data.mes = tempo_info->tm_mon + 1;
  data.ano = 1900 + tempo_info->tm_year;
  return data;
}

// Realiza uma venda
void realiza_venda(char * placa, char * cpf){
  FILE * arc = fopen("vendas.bin", "ab");
  struct VENDA_CARRO venda;

  if(arc == NULL){
    printf("ERRO AO ABRIR O ARQUIVO!\n");
    exit(100);
  }

  strcpy(venda.placa_car, placa);
  strcpy(venda.cpf_cli, cpf);
  venda.preco_venda = 30000 + (rand() % 300000);  // Gera preço entre 30000 e 300000
  venda.data_venda = retorna_data();
  fwrite(&venda, sizeof(venda), 1, arc);
  fclose(arc);

}

// Realiza a remoção de uma venda de um carro desejado
void apaga_venda(char * placa){
  FILE * original = fopen("vendas.bin", "rb");
  if(original == NULL){
    printf("ERRO AO ABRIR ARQUIVO ORIGINAL PARA APAGAR VENDA!\n");
    exit(100);
  }

  FILE * temporario = fopen("temp.bin", "ab");
  if(temporario == NULL){
    printf("ERRO AO ABRIR ARQUIVO TEMPORARIO PARA APAGAR VENDA!\n");
    fclose(original);
    exit(100);
  }

  struct VENDA_CARRO venda;

  fseek(original, 0, SEEK_SET);


  while(!feof(original)){ // Copia para um novo arquivo ignorando o que deseja apagar
    if(fread(&venda, sizeof(venda), 1, original) > 0){
      if(strcmp(placa, venda.placa_car) != 0){
        fwrite(&venda, sizeof(venda), 1, temporario);
      }
    }
  }

  fclose(original);
  fclose(temporario);

  if(remove("vendas.bin") != 0){  // Apaga arquivo de vendas
    printf("ERRO AO DELETAR ARQUIVO DE VENDAS! REINICIE O PROGRAMA E TENTE NOVAMENTE\n");
    exit(100);
  }

  if(rename("temp.bin", "vendas.bin") != 0){  // Renomeia arquivo temporário
    printf("ERRO AO RENOMEAR ARQUIVO DE VENDAS!\n");
    exit(100);
  }

  printf("-------------- SUCESSO ------------\n");
  printf("| EXCLUSAO REALIZADA COM SUCESSO! |\n");
  printf("-----------------------------------\n");
}

// Retorna modelo ordenado de forma crescente dos carros recebidos
int comparar_vendas_modelo(const void *a, const void *b){
  const char *carro1 = ((struct CARRO *)a)->modelo;
  const char *carro2 = ((struct CARRO *)b)->modelo;
  return strcmp(carro1, carro2);
}

// Printa os carros vendidos ordenados pelo fabricante
void carros_vendidos_fabricante(int opc){
  FILE * fp = fopen("carros.bin", "rb");
  if(fp == NULL){
    printf("ERRO ABRIR ARQUIVO DE CARROS\n");
    exit(100);
  }

  FILE * vd = fopen("vendas.bin", "rb");
  if(vd == NULL){
    printf("ERRO ABRIR ARQUIVO DE CARROS\n");
    fclose(fp);
    exit(100);
  }

  FILE * cli = fopen("clientes.bin", "rb");
  if(cli == NULL){
    printf("ERRO ABRIR ARQUIVO DE CLIENTES\n");
    fclose(fp);
    fclose(vd);
    exit(100);
  }

  fseek(fp, 0, SEEK_SET);

  struct CARRO carro;
  struct VENDA_CARRO venda;
  struct CLIENTE cliente;
  struct CARRO carros[100];

  int n = 0;
  while(!feof(fp)){
    if(fread(&carro, sizeof(carro), 1, fp) > 0){
      if(strcmp(carro.fabricante, fabricantes[opc-1]) == 0){  // Compara fabricante recebido com a lista de fabricantes
        fseek(vd, 0, SEEK_SET);
        while(!feof(vd)){
          if(fread(&venda, sizeof(venda), 1, vd) > 0){
            if(strcmp(carro.placa, venda.placa_car) == 0){  // Compara se o carro atual com o modelo já foi vendido
              carros[n++] = carro;
            }
          }
        }
      }
    }
  }

  qsort(carros, n, sizeof(carros[0]), comparar_vendas_modelo);  // Função de ordenação da biblioteca stdlib.h

  for(int i = 0; i < n; i++){ // Exibe carro
    printf("#================#=================#\n");
    printf("-            MODELO -> %s\n", carros[i].modelo);
    printf("-             PLACA -> %s\n", carros[i].placa);
    printf("- ANO DE FABRICACAO -> %d\n", carros[i].ano_fabricacao);
    fseek(vd, 0, SEEK_SET);
    while(!feof(vd)){
      if(fread(&venda, sizeof(venda), 1, vd) > 0){
        if(strcmp(venda.placa_car, carros[i].placa) == 0){
          fseek(cli, 0, SEEK_SET);
          while(!feof(cli)){
            if(fread(&cliente, sizeof(cliente), 1, cli) > 0){
              if(strcmp(cliente.cpf, venda.cpf_cli) == 0){
                printf("-           CLIENTE -> %s\n", cliente.nome);
              }
            }
          }
        }
      }
    }
  }

  fclose(fp);
  fclose(vd);
  fclose(cli);
}

// Retorna os anos ordenados de forma crescente dos carros recebidos
int comparar_vendas_fabricacao(const void *a, const void *b){
  const int ano1 = ((struct CARRO *)a)->ano_fabricacao;
  const int ano2 = ((struct CARRO *)b)->ano_fabricacao;
  return (ano1 - ano2);
}

// Printa na tela os carros vendidos ordenados pelo modelo
void carros_vendidos_modelo(int opc){
  FILE * fp = fopen("carros.bin", "rb");
  if(fp == NULL){
    printf("ERRO ABRIR ARQUIVO DE CARROS\n");
    exit(100);
  }

  FILE * vd = fopen("vendas.bin", "rb");
  if(vd == NULL){
    printf("ERRO ABRIR ARQUIVO DE CARROS\n");
    fclose(fp);
    exit(100);
  }

  FILE * cli = fopen("clientes.bin", "rb");
  if(cli == NULL){
    printf("ERRO ABRIR ARQUIVO DE CLIENTES\n");
    fclose(fp);
    fclose(vd);
    exit(100);
  }

  fseek(fp, 0, SEEK_SET);

  struct CARRO carro;
  struct VENDA_CARRO venda;
  struct CLIENTE cliente;
  struct CARRO carros[100];

  int n = 0;
  while(!feof(fp)){
    if(fread(&carro, sizeof(carro), 1, fp) > 0){
      if(strcmp(carro.modelo, modelosss[opc-1]) == 0){  // Compara modelo recebido com lista de modelos
        fseek(vd, 0, SEEK_SET);
        while(!feof(vd)){
          if(fread(&venda, sizeof(venda), 1, vd) > 0){
            if(strcmp(carro.placa, venda.placa_car) == 0){  // Compara carro com o modelo atual foi vendido
              carros[n++] = carro;  // Adiciona carro ao vetor
            }
          }
        }
      }
    }
  }

  qsort(carros, n, sizeof(carros[0]), comparar_vendas_fabricacao); // Função de ordenação da biblioteca stdlib.h

  for(int i = 0; i < n; i++){ // Exibe carros ordenados
    printf("#================#=================#\n");
    printf("- ANO DE FABRICACAO -> %d\n", carros[i].ano_fabricacao);
    printf("-             PLACA -> %s\n", carros[i].placa);
    fseek(vd, 0, SEEK_SET);
    while(!feof(vd)){
      if(fread(&venda, sizeof(venda), 1, vd) > 0){
        if(strcmp(venda.placa_car, carros[i].placa) == 0){
          fseek(cli, 0, SEEK_SET);
          while(!feof(cli)){
            if(fread(&cliente, sizeof(cliente), 1, cli) > 0){
              if(strcmp(cliente.cpf, venda.cpf_cli) == 0){
                printf("-           CLIENTE -> %s\n", cliente.nome);
              }
            }
          }
        }
      }
    }
  }

  fclose(fp);
  fclose(vd);
  fclose(cli);
}

// Printa  quantidade e valores das vendas
void checa_vendas(){
  FILE * fp = fopen("vendas.bin", "rb");
  if(fp == NULL){
    printf("ERRO AO ABRIR ARQUIVO DE VENDAS PARA CHECAGEM\n");
    exit(100);
  }

  fseek(fp, 0, SEEK_SET);

  struct VENDA_CARRO venda;
  float total_precos = 0;
  int quant_vendas = 0;

  while(!feof(fp)){   // Soma todos os preços de venda e conta quantas vendas forma feitas
    if(fread(&venda, sizeof(venda), 1, fp) > 0){
      quant_vendas++;
      total_precos += venda.preco_venda;
    }
  }

  fclose(fp);
  printf("#==============#================#\n");
  printf("- QUANTIDADE DE VENDAS -> %d\n", quant_vendas);
  printf("#-------------------------------#\n");
  printf("- VALOR TOTAL -> R$%.2f\n", total_precos);
  printf("#==============#================#\n");
}

// Printa na tela a diferença entre os preços de venda os preços dos carros
void checa_lucro(){
  FILE * vd = fopen("vendas.bin", "rb");
  if(vd == NULL){printf("ERRO AO ABRIR ARQUIVO DE VENDAS\n"); exit(100);}

  fseek(vd, 0, SEEK_SET);

  struct VENDA_CARRO venda;
  float soma_lucro = 0;

  while(!feof(vd)){   // Soma todos os preços de vendas
    if(fread(&venda, sizeof(venda), 1, vd) > 0){
      soma_lucro += venda.preco_venda;  
    }
  }

  fclose(vd);

  FILE * cr = fopen("carros.bin", "rb");
  if(cr == NULL) {printf("ERRO AO ABRIR ARQUIVO DE VENDAS\n"); exit(100);}

  fseek(cr, 0, SEEK_SET);

  struct CARRO carro;

  while(!feof(cr)){   // Subtrai por todos os preços dos carros
    if(fread(&carro, sizeof(carro), 1, cr) > 0){
      soma_lucro -= carro.preco_compra;
    }
  }

  fclose(cr);

  printf("#=================#===============#\n");
  printf("- O LUCRO TOTAL FOI DE -> R$%.2f\n", soma_lucro); //  Exibe lucro
  printf("#=================#===============#\n");
}

// Menu de Vendas
void menuVenda(){
  int esc, check = 0;
  char cpf[15], placa[9];
  do{
    system("cls");
    printf("-------------------------------------------------------------------------------\n");
    printf("|1. INSERIR UMA VENDA                                                         |\n");
    printf("|2. EXCLUIR UMA VENDA                                                         |\n");
    printf("|3. CARROS VENDIDOS DE UM DETERMINADO FABRICANTE                              |\n");
    printf("|4. CARROS VENDIDOS DE UM DETERMINADO MODELO                                  |\n");
    printf("|5. QUANTIDADE DE CARROS VENDIDOS COM O VALOR TOTALIZADO DOS PRECOS VENDIDOS  |\n");
    printf("|6. LUCRO TOTAL DAS VENDAS                                                    |\n");
    printf("|7. VOLTAR                                                                    |\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("-> ");
    scanf("%d", &esc);
    system("cls");
    switch (esc){
      case 1:
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("- INSIRA O CPF DO CLIENTE -> ");
        getchar();
        fgets(cpf, sizeof(cpf), stdin);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("- INSIRA A PLACA DO CARRO -> ");
        getchar();
        fgets(placa, sizeof(placa), stdin);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        check = checa_carro(placa);
        check += checa_cliente(cpf);
        system("cls");
        switch (check){ // Realiza decisão aritmética de acordo com as checagens realizadas
          case 0:
            printf("------------- ERRO -------------\n");
            printf("| CLIENTE E CARRO INEXISTENTE! |\n");
            printf("--------------------------------\n");
            system("pause");
            break;
          case 2:
            printf("---------- ERRO --------\n");
            printf("| CLIENTE INEXISTENTE! |\n");
            printf("------------------------\n");
            system("pause");
            break;
          case 3:
            printf("-------- ERRO --------\n");
            printf("| CARRO INEXISTENTE! |\n");
            printf("----------------------\n");
            system("pause");
            break;
          case 5:
            realiza_venda(placa, cpf);
            printf("------------- SUECESSO ------------\n");
            printf("| OPERACAO REALIZADA COM SUCESSO! |\n");
            printf("-----------------------------------\n");
            system("pause");
            break;
          default:
            break;
        }
        break;
      case 2:{
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("- INSIRA A PLACA DO CARRO -> ");
        getchar();
        fgets(placa, sizeof(placa), stdin);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        if(checa_carro(placa) == 2){
          apaga_venda(placa);
        } else {
          printf("-------- ERRO --------\n");
          printf("| CARRO INEXISTENTE! |\n");
          printf("----------------------\n");
        }
      }
      system("pause");
        break;
      case 3:{
        int opc = 0;
        printf("-----------------------------------\n");
        printf("| 1. CHEVROLET    | 2. FIAT       |\n");
        printf("| 3. TOYOTA       | 4. VOLKSWAGEN |\n");
        printf("-----------------------------------\n");
        printf("- INSIRA O FABRICANTE -> ");
        scanf("%d", &opc);
        if(opc < 1 || opc > 4){
          printf("------- ERRO ------\n");
          printf("| OPCAO INVALIDA! |\n");
          printf("-------------------\n");
          system("pause");
          continue;
        }
        system("cls");
        carros_vendidos_fabricante(opc);
      }
        system("pause");
        break;
      case 4: {
        int opc;
        system("cls");
        printf("--------------------------------------------------------------\n");
        printf("| 1. ONIX     | 2. S10         | 3. CELTA       | 4. STRADA  |\n");
        printf("| 5. PALIO    | 6. COROLLA     | 7. HILLUX      | 8. SAVEIRO |\n");
        printf("| 9. VOYAGE   | 10. GOL                                      |\n");
        printf("--------------------------------------------------------------\n");
        printf("- INSIRA O MODELO -> ");
        scanf("%d", &opc);
        if(opc < 1 || opc > 10){
          printf("------- ERRO ------\n");
          printf("| OPCAO INVALIDA! |\n");
          printf("-------------------\n");
          continue;
        }
        system("cls");
        carros_vendidos_modelo(opc);
      }
        system("pause");
        break;
      case 5:
        checa_vendas();
        system("pause");
        break;
      case 6:
        checa_lucro();
        system("pause");
        break;
      default:
        break;
    }
  }while(esc != 7);
}

int main(){
  srand(time(NULL));
  int esc;
  do{
    system("cls");
    printf("-----------------\n");
    printf("|1. CARRO       |\n");
    printf("|2. CLIENTE     |\n");
    printf("|3. VENDA       |\n");
    printf("|4. SAIR        |\n");
    printf("-----------------\n");
    printf("-> ");
    scanf("%d", &esc);

    switch (esc){
      case 1:
        menuCarro();
        break;
      case 2:
        menuCliente();
        break;
      case 3:
        menuVenda();
        break;
      case 4:
        printf("------- AVISO --------\n");
        printf("| PROGRAMA ENCERRADO |\n");
        printf("----------------------\n");
        printf("  TENHA UM OTIMO DIA\n");
        break;
      default:
        printf("ENTRADA INVALIDA!\n");
        system("pause");
        break;
    }
  } while(esc != 4);

  return 0;
}