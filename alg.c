#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

// Declaração das funções
int** AlocarMemoria(int q, int p);
void LerMatriz(int **m, int q, int p);
void MostrarMatriz(int **m, int q, int p);
int Quadrada(int q, int p);
void LinhaXporY(int **m, int q, int p);
void ColunaXporY(int **m, int q, int p);
void DPporDS(int **m, int q, int p);
void Simetria(int **m, int q, int p);
void QuadLatino(int **m, int q, int p);
void QuadMagico(int **m, int q, int p);
void Permuta(int **m, int q, int p);
void clearbuff();
void freememory(int **m, int q);

// Função principal
int main(){
  int q, p;
  printf("Digite o numero de linhas e colunas da sua matriz: ");
  scanf("%d %d", &q, &p);
  
  int **m = AlocarMemoria(q, p);

  freememory(m, q);
  return 0;
}

// Funções auxiliares
int** AlocarMemoria(int q, int p){
  int **m = (int **) malloc(q * sizeof(*m));
  for(int i = 0; i < q; i++){
    m[i] = (int *) malloc(p * sizeof(*m[i]));
  }
  return m;
}

void LerMatriz(int **m, int q, int p){
  printf("Digite os elementos da matriz:\n");
  for(int i = 0; i < q; i++){
    for(int j = 0; j < p; j++){
      printf("M[%d][%d]: ", i, j);
      scanf("%d", &m[i][j]);
    }
  }
}

void MostrarMatriz(int **m, int q, int p){
  printf("\nMATRIZ:\n");
  for(int i = 0; i < q; i++){
    for(int j = 0; j < p; j++){
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}

void LinhaXporY(int **m, int q, int p){
  int x, y, aux = 0;
  
  printf("Selecione as linhas que deseja inverter: ");
  scanf("%d %d", &x, &y);

  do{
    clearbuff();
    printf("Selecione linhas validas: ");
    scanf("%d %d", &x, &y); 
  }while(x - 1 < 0 || x - 1 >= q || y - 1 < 0 || y - 1 >= q);
  
  for(int j = 0; j < p; j++){
    aux = m[x][j];
    m[x][j] = m[y][j];
    m[y][j] = aux;
  }
}

void ColunaXporY(int **m, int q, int p){
  int x, y, aux = 0;
  
  printf("Selecione as colunas que deseja inverter: ");
  scanf("%d %d", &x, &y);

  do{
    clearbuff();
    printf("Selecione colunas validas: ");
    scanf("%d %d", &x, &y); 
  }while(x - 1 < 0 || x - 1 >= p || y - 1 < 0 || y - 1 >= q);
  
  for(int i = 0; i < q; i++){
    aux = m[i][x];
    m[i][x] = m[i][y];
    m[i][y] = aux;
  }
}

void DPporDS(int **m, int q, int p){
  int aux = 0;

  if(!(Quadrada(q, p))){
    printf("\nMATRIZ NAO QUADRADA\n");
    return;
  }

  for(int i = 0; i < q; i++){
    aux = m[i][i];
    m[i][i] = m[i][q-i-1];
    m[i][q-i-1] = aux;
  }
}

void Simetria(int **m, int q, int p){

  if(!(Quadrada(q, p))){
    printf("\nMATRIZ NAO QUADRADA\n");
    return;
  }

  for(int i = 0; i < q; i++){
    for(int j = 0; j < i; j++){
      if(m[i][j] != m[j][i]){
        printf("A matriz não é simétrica.\n");
        return;
      }
    }
  }
   printf("A matriz é simétrica.\n");
}

void QuadLatino(int **m, int q, int p){
  int i, j, k, v[q];
  
  if(!(Quadrada(q, p))){
    printf("\nMATRIZ NAO QUADRADA\n");
    return;
  }

  for (i = 0; i < q; i++){
    v[i] = 0;
    for (j = 0; j < q; j++){
      v[i] += m[i][j];
      for (k = 0; k < q; k++){
        if (m[i][j] == m[i][k] && j != k){
          printf("A matriz não é um Quadrado Latino.\n");
          return;
        }
      }
    }
  }

  for (i = 0; i < q - 1; i++)
    if (v[i] != v[i + 1])
    {
      printf("A matriz não é um Quadrado Latino.\n");
      return;
    }

  for (j = 0; j < q; j++){
    v[j] = 0;
    for (i = 0; i < q; i++){
      v[j] += m[i][j];
      for (k = 0; k < q; k++){
        if (m[i][j] == m[k][j] && i != k){
          printf("A matriz não é um Quadrado Latino.\n");
          return;
        }
      }
    }
  }

  for (i = 0; i < q - 1; i++)
    if (v[i] != v[i + 1]){
      printf("A matriz não é um Quadrado Latino.\n");
      return;
    }

  printf("A matriz é um Quadrado Latino.\n");
  return; 
}


void QuadMagico(int **m, int q, int p){

  if(!(Quadrada(q, p))){
    printf("\nMATRIZ NAO QUADRADA\n");
    return;
  }

  int somaC = 0, somaL = 0, somaDs = 0, somaDp = 0;
  for(int i = 0; i < q; i++){
    somaDp += m[i][i];
    somaDs += m[i][q-i-1];
  }

  if(somaDp != somaDs){
    printf("\nMatriz nao eh um quadrado mágico\n");
    return;
  }

  for(int i = 0; i < q; i++){
    somaC = 0, somaL = 0;
    for(int j = 0; j < p; j++){
      somaL += m[i][j];
      somaC += m[j][i];
    }
    if(somaC != somaL){
      printf("\nMatriz nao eh um quadrado mágico\n");
      return;
    }
  }
  printf("\nMatriz eh um quadrado mágico\n");
  return;
}

int Quadrada(int q, int p){
  if(q == p){
    return 1;
  }else{
    return 0;
  }
}

void Permuta(int **m, int q, int p){
  int i, j;
  int somacol[q], soma;

  if(!(Quadrada(q, p))){
    printf("\nMATRIZ NAO QUADRADA\n");
    return;
  }
  
  for(i = 0; i < q; i++){
    somacol[i] = 0;
  }

  for(i = 0; i < q; i++){
    soma = 0;
    for(j = 0; j < q; j++){
      if(m[i][j] != 1 && m[i][j] != 0){
        printf("\nNao eh uma Matriz Permutacao\n");
        return;
      }else{
        somacol[j] += m[i][j];
        soma += m[i][j];
      }
    }
    if(soma != 1){
      printf("\nNao eh uma Matriz Permutacao\n");
      return;
    }
  }

  for(i = 0; i < q; i++){
    if(somacol[i] != 1){
      printf("\nNao eh uma Matriz Permutacao\n");
      return;
    }
  }

  printf("\nEh uma Matriz Permutacao\n");
  return;
}

void clearbuff() {
    while (getchar() != '\n');
}

void freememory(int **m, int q){
    for (int i = 0; i < q; i++) {
        free(m[i]);
    }
    free(m);
}
