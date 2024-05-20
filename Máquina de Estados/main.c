#include <stdio.h>
#include <string.h>

// Verifica existênicia de um estado apenas
int verificaEstado(char estados[20], char estado, int numEstados){
  for(int i = 0; i < numEstados; i++){
    if(estados[i] == estado){
      return 1;
    }
  }
  return 0;
}

// Verifica se todas letras estao no alfabeto
int verificaPalavra(char palavra[100], char alfabeto[2], int tamPalavra){
  for(int i = 0; i < tamPalavra; i++){
    int check = 0;
    for(int j = 0; j < 2; j++){
      if(palavra[i] == alfabeto[j]){
        check = 1;
      }
    }
    if(!check){
      return 0;
    }
  }
  return 1;
}

// Pega o alfabeto do usuario
void getAlfabeto(char alfabeto[2]){
  printf("Insira a primeira letra do alfabeto: ");
  scanf(" %c", &alfabeto[0]);
  printf("Insira a segunda letra do alfabeto: ");
  scanf(" %c", &alfabeto[1]);
  getchar();
}

// Retorna indice de um estado
int encontraEstado(char estados[20], char estadoAtual, int numEstados){
  for(int i = 0; i < numEstados; i++){
    if(estados[i] == estadoAtual){
      return i;
    }
  }
  return -1; // Nunca vai retornar isso
}

int encontraLetra(char alfabeto[2], char letra){
  for(int i = 0; i < 2; i++){
    if(alfabeto[i] == letra){
      return i;
    }
  }
  return -1;  // Nunca vai parar aqui
}

// Verifica a existência de uma cadeia de estados
int verificaEstados(char estados[20], char palavra[20], int numEstados, int numEstadosAceitacao){
  for(int i = 0; i < numEstadosAceitacao; i++){
    int check = 0;
    for(int j = 0; j < numEstados; j++){
      if(palavra[i] == estados[j]){
        check = 1;
      }
    }
    if(!check){
      return 0;
    }
  }
  return 1;
}

// Recebe os estados da maquina
void getEstados(char estados[20], int *numEstados){
  char temp[30] = "";
  printf("Insira os estados da maquina (separe por virgulas): ");
  fgets(temp, sizeof(temp), stdin);

  char *pont = strtok(temp, ",");
  int indice = 0;
  while(pont != NULL){
    estados[indice] = *pont;
    pont = strtok(NULL, ",");
    indice++;
    *numEstados = *numEstados + 1;
  }
}

// Recebe o estado inicial da maquina
void getEstadoInicial(char estados[20], char *estadoInicial, int numEstados){
  int check = 1;
  while(check){
    printf("Insira o estado inicial da maquina: ");
    fgets(estadoInicial, sizeof(estadoInicial), stdin);
    if(verificaEstado(estados, *estadoInicial, numEstados)){
      check = 0;
    } else {
      printf("\nEstado nao existe na maquina, tente novamente\n");
    }
  }
}

// Recebe os estados de aceitacao da maquina
void getEstadosDeAceitacao(char estados[20], char estadosDeAceitacao[20], int numEstados){
  char temp[30] = "";
  int check = 1;
  while(check){
    int numEstadosAceitacao = 0;
    printf("Insira os estados de aceitacao da maquina (separe por virgulas): ");
    fgets(temp, sizeof(temp), stdin);
    char *pont = strtok(temp, ",");
    int indice = 0;
    while(pont != NULL){
      estadosDeAceitacao[indice] = *pont;
      pont = strtok(NULL, ",");
      indice++;
      numEstadosAceitacao++;
    }
    if(verificaEstados(estados, estadosDeAceitacao, numEstados, numEstadosAceitacao)){
      check = 0;
    } else {
      printf("Alguma estado inserido nao pertence a maquina, tente novamente\n");
    }
  }
  
}

void getFuncao(char funcao[20][2], char estados[20], int numEstados, char alfabeto[2]){
  char temp;
  for(int i = 0; i < numEstados; i++){
    for(int j = 0; j < 2; j++){
      printf("Delta de '%c' quando receber '%c': ", estados[i], alfabeto[j]);
      scanf(" %c", &temp);
      if(!verificaEstado(estados, temp, numEstados)){
        printf("O estado inserido nao existe, tente novamante\n");
        j--;
      } else {
        funcao[i][j] = temp;
      }
    }
  }
}

void getPalavra(char palavra[100], char alfabeto[2]){
  char temp[100] = "";
  int check = 1;
  while(check){
    printf("Insira a palavra: ");
    fgets(temp, sizeof(temp), stdin);
    if(!verificaPalavra(temp, alfabeto, strlen(temp)-1)){
      printf("Alguma letra inserida nao pertence a maquina, tente novamente\n");
    } else {
      strcpy(palavra, temp);
      check = 0;
    }
  }
  
}

void executaMaquina(char estadoInicial, char estados[20], char alfabeto[2], char estadosDeAceitacao[20], char funcao[20][2], char palavra[100]){
  char estadoAtual = estadoInicial;
  int tamPalavra = strlen(palavra)-1;
  for(int i = 0; i < tamPalavra; i++){
    int indice = encontraEstado(estados, estadoAtual, strlen(estados)-1);
    estadoAtual = funcao[indice][]
  }
}

int main(){
  char estadoInicial, alfabeto[2] = "", estados[20] = "", estadosDeAceitacao[20] = "", funcao[20][2], palavra[100] = "";
  int numEstados = 0;
  // getEstados(estados, &numEstados);
  getAlfabeto(alfabeto);
  // getEstadosDeAceitacao(estados, estadosDeAceitacao, numEstados);
  // getEstadoInicial(estados, &estadoInicial, numEstados);
  // getFuncao(funcao, estados, numEstados);
  getPalavra(palavra, alfabeto);
  printf("%s", palavra);
  return 0;
}