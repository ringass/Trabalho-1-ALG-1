#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define baixo 80
#define cima 72
#define esc 27
#define enter 13
#define f1 59

void gotoxy(int x, int y)
{
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int SetColor(char color)
{
  HANDLE h;
  h = GetStdHandle(STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute(h, color);
}

void escreveTexto(int x, int y, char texto[], int cor)
{
  SetColor(cor);
  gotoxy(y, x);
  printf("%s", texto);
}

void desenhaQuadrado(int x1, int y1, int x2, int y2, int cor)
{
  char linhaHorizontal[41]; 
  for (int i = 0; i < (y2 - y1 + 1); i++)
  { 
    linhaHorizontal[i] = '*';
  }
  linhaHorizontal[y2 - y1 + 1] = '\0'; 

  
  escreveTexto(x1, y1, linhaHorizontal, cor);

  
  for (int i = x1 + 1; i < x2; i++)
  {
    escreveTexto(i, y1, "*", cor);
    escreveTexto(i, y2, "*", cor);
  }

  
  escreveTexto(x2, y1, linhaHorizontal, cor);
}

void inicio(int op)
{
  char vet[][30] = {"INICIAR", "SAIR"};
  int i;
  system("cls");

  desenhaQuadrado(1, 20, 10, 60, 6); 

  escreveTexto(3, 25, "Bem Vindo ao Operador de Matrizes", 6);
  
  for (i = 0; i < 2; i++)
  {
    escreveTexto(6 + i, 25, vet[i], 10);
  }
  escreveTexto(6 + op - 1, 25, vet[op - 1], 6);
}

int menuInicio()
{
  int op;
  char t;
  op = 1;
  inicio(op);
  do
  {
    t = getch();
    if (t <= 0)
    {
      t = getch();
      if (t == baixo)
      {
        if (op != 2)
          op++;
        else
          op = 1;
        inicio(op);
      }
      else if (t == cima)
      {
        if (op != 1)
          op--;
        else
          op = 2;
        menuInicio(op);
      }
      else if (t == f1)
      printf("aadadada");
    }
    else if (t == enter)
    {
      fflush(stdin);
      fflush(stdin);
      system("cls");
      return op;
    }
  } while (t != esc);
  return -1;
}

void menu(int op)
{
  char vet[][20] = {"Transformar", "Verificar", "F1 para Ajuda"};
  int i;
  system("cls");
  desenhaQuadrado(1, 20, 10, 60, 6);
  escreveTexto(2, 25, "MENU INICIAL", 6);
  for (i = 0; i < 3; i++)
    escreveTexto(5 + i, 25, vet[i], 10);
  escreveTexto(4 + op, 25, vet[op - 1], 6);
}

int menuSelecao()
{
  int op = 0;
  char t;
  op = 1;
  menu(op);
  do
  {
    t = getch();
    if (t <= 0)
    {
      t = getch();
      if (t == baixo)
      {
        if (op != 3)
          op++;
        else
          op = 1;
        menu(op);
      }
      else if (t == cima)
      {
        if (op != 1)
          op--;
        else
          op = 3;
        menu(op);
      }
      else if (t == f1)
      {
        system("cls");
        ajuda1();
        op = 9;
      }
    }
    else if (t == enter)
    {
      system("cls");
      printf("Opcao selecionada: %d\n", op);
      return op;
    }
  } while (t != esc);
  system("cls");
  return -1;
}

void menuTrans(int op)
{
  char vet[][30] = {"Trocar linha X por linha Y", "Trocar coluna X por coluna Y", "Trocar diagonais", "Voltar"};
  int i;
  system("cls");
  desenhaQuadrado(1, 20, 10, 60, 4);
  escreveTexto(2, 25, "TRANSFORMACOES NA MATRIZ", 4);
  for (i = 0; i < 4; i++)
    escreveTexto(5 + i, 25, vet[i], 10);
  escreveTexto(4 + op, 25, vet[op - 1], 4);
}

int menuTransformar()
{
  int op;
  char t;
  op = 1;
  menuTrans(op);
  do
  {
    t = getch();
    if (t <= 0)
    {
      t = getch();
      if (t == baixo)
      {
        if (op != 4)
          op++;
        else
          op = 1;
        menuTrans(op);
      }
      else if (t == cima)
      {
        if (op != 1)
          op--;
        else
          op = 4;
        menuTrans(op);
      }
      else if (t == f1){
        system("cls");
        ajuda2();
        op = 9;
    }
    }
    else if (t == enter)
    {
      system("cls");
      return op;
    }
  } while (t != esc);
  return -1;
}

void menuVer(int op)
{
  char vet[][30] = {"Simetria", "Quadrado magico?", "Quadrado latino?", "Matriz permutacao", "Matriz Nula", "Voltar"};
  int i;
  system("cls");
  desenhaQuadrado(1, 20, 10, 60, 3);
  escreveTexto(2, 25, "VERIFICACOES NA MATRIZ", 3);
  for (i = 0; i < 5; i++)
    escreveTexto(5 + i, 25, vet[i], 10);
  escreveTexto(4 + op, 25, vet[op - 1], 3);
  
}


int menuVerificar()
{
  int op;
  char t;
  op = 1;
  menuVer(op);
  do
  {
    t = getch();
    if (t <= 0)
    {
      t = getch();
      if (t == baixo)
      {
        if (op != 5)
          op++;
        else
          op = 1;
        menuVer(op);
      }
      else if (t == cima)
      {
        if (op != 1)
          op--;
        else
          op = 5;
        menuVer(op);
      }
      else if (t == f1)
      {
        system("cls");
        ajuda1();
        op = 9;
      }
    }
    else if (t == enter)
    {
      system("cls");
      return op;
    }
  } while (t != esc);
  system("cls");
  return -1; 
}

// Declaração das funções
int **AlocarMemoria(int q, int p);
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
int main()
{

  int bb = menuInicio();

  if (bb == 1)
  {
    int q, p;
    printf("Digite o numero de linhas e colunas da sua matriz: ");
    scanf("%d %d", &q, &p);

    int **m = AlocarMemoria(q, p);
    int opcaoSelecionada;

  REFAZ:
    opcaoSelecionada = menuSelecao();

    if (opcaoSelecionada == 1)
    {
      int selecaoTrans;
      VOLTA:
      selecaoTrans = menuTransformar();
      if (selecaoTrans == 1)
      {
        LinhaXporY(m, q, p);
      }
      else if (selecaoTrans == 2)
      {
        ColunaXporY(m, q, p);
      }
      else if (selecaoTrans == 3)
      {
        DPporDS(m, q, p);
      }else if(selecaoTrans == 9){
        goto VOLTA;
      }else
      {
        goto REFAZ;
      }
    }
    else if (opcaoSelecionada == 2)
    {
      int selecaoVer;
      VOLTA2:
      selecaoVer = menuVerificar();
      if (selecaoVer == 1)
      {
        Simetria(m, q, p);
        MostrarMatriz(m, q, p);
      }
      else if (selecaoVer == 2)
      {
        QuadMagico(m, q, p);
      }
      else if (selecaoVer == 3)
      {
        QuadLatino(m, q, p);
      }
      else if (selecaoVer == 4)
      {
        Permuta(m, q, p);
      }else if(selecaoVer == 9){
        goto VOLTA2;
      }
      else
      {
        goto REFAZ;
      }
    }else{
      system("cls");
      desenhaQuadrado(1, 20, 3, 60, 6); 
      escreveTexto(2, 24, "::::::QUE PENA, NAO GOSTOU?::::::", 6);
      printf("\n\n\n");
      return 0;
    }
    freememory(m, q);
    return 0;
  }
  else
  {
    return 0;
  }
}

// int options (int x){
//   if(x == 1){

//   }
// }

// Funções auxiliares
int **AlocarMemoria(int q, int p)
{
  int **m = (int **)malloc(q * sizeof(*m));
  for (int i = 0; i < q; i++)
  {
    m[i] = (int *)malloc(p * sizeof(*m[i]));
  }
  return m;
}

void LerMatriz(int **m, int q, int p)
{
  printf("Digite os elementos da matriz:\n");
  for (int i = 0; i < q; i++)
  {
    for (int j = 0; j < p; j++)
    {
      printf("M[%d][%d]: ", i, j);
      scanf("%d", &m[i][j]);
    }
  }
}

void MostrarMatriz(int **m, int q, int p)
{
  for (int i = 0; i < q; i++)
  {
    for (int j = 0; j < p; j++)
    {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}

//-----------------------------------------------------------------------------------------

void LinhaXporY(int **m, int q, int p)
{
  int x, y, aux = 0;

  LerMatriz(m, q, p);

  printf("Selecione as linhas que deseja inverter: ");
  scanf("%d %d", &x, &y);
  if ((x - 1 < 0 || x - 1 > q || y - 1 < 0 || y - 1 > q))
  {
    do
    {
      clearbuff();
      printf("Selecione linhas validas: ");
      scanf("%d %d", &x, &y);
    } while (x - 1 < 0 || x - 1 > q || y - 1 < 0 || y - 1 > q);
  }
  system("cls");
  printf("\nMATRIZ ORIGINAL\n");
  MostrarMatriz(m, q, p);
  for (int j = 0; j < p; j++)
  {
    aux = m[x - 1][j];
    m[x - 1][j] = m[y - 1][j];
    m[y - 1][j] = aux;
  }
  printf("\nMATRIZ MODIFICADA\n");
  MostrarMatriz(m, q, p);
}

void ColunaXporY(int **m, int q, int p)
{
  int x, y, aux = 0;

  LerMatriz(m, q, p);

  printf("Selecione as colunas que deseja inverter: ");
  scanf("%d %d", &x, &y);

  if (x - 1 < 0 || x - 1 >= p || y - 1 < 0 || y - 1 >= q)
  {
    do
    {
      clearbuff();
      printf("Selecione colunas validas: ");
      scanf("%d %d", &x, &y);
    } while (x - 1 < 0 || x - 1 >= p || y - 1 < 0 || y - 1 >= q);
  }
  system("cls");
  printf("\nMATRIZ ORIGINAL\n");
  for (int i = 0; i < q; i++)
  {
    aux = m[i][x - 1];
    m[i][x - 1] = m[i][y - 1];
    m[i][y - 1] = aux;
  }
  
  printf("\nMATRIZ MODIFICADA\n");
  MostrarMatriz(m, q, p);
}

void DPporDS(int **m, int q, int p)
{
  LerMatriz(m, q, p);
  int aux = 0;

  if (!(Quadrada(q, p)))
  {
    printf("\nMATRIZ NAO QUADRADA\n");
    MostrarMatriz(m, q, p);
    return;
  }
  system("cls");
  printf("\nMATRIZ ORIGINAL\n");
  MostrarMatriz(m,q,p);
  for (int i = 0; i < q; i++)
  {
    aux = m[i][i];
    m[i][i] = m[i][q - i - 1];
    m[i][q - i - 1] = aux;
  }
  printf("\nMATRIZ MODIFICADA\n");
  MostrarMatriz(m, q, p);

}

void Simetria(int **m, int q, int p)
{

  LerMatriz(m, q, p);
  if (!(Quadrada(q, p)))
  {
    printf("\nMATRIZ NAO QUADRADA\n");
    MostrarMatriz(m, q, p);
    return;
  }

  for (int i = 0; i < q; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (m[i][j] != m[j][i])
      {
        printf("MATRIZ NAO SIMETRICA\n");
        MostrarMatriz(m, q, p);
        return;
      }
    }
  }
  printf("MATRIZ SIMETRICA\n");
  MostrarMatriz(m, q, p);
}

void QuadLatino(int **m, int q, int p)
{
  LerMatriz(m, q, p);
  int i, j, k, v[q];

  if (!(Quadrada(q, p)))
  {
    printf("\nMATRIZ NAO QUADRADA\n");
    MostrarMatriz(m, q, p);
    return;
  }

  for (i = 0; i < q; i++)
  {
    v[i] = 0;
    for (j = 0; j < q; j++)
    {
      v[i] += m[i][j];
      for (k = 0; k < q; k++)
      {
        if (m[i][j] == m[i][k] && j != k)
        {
          printf("MATRIZ EH UM QUADRADO LATINO\n");
          MostrarMatriz(m, q, p);
          return;
        }
      }
    }
  }

  for (i = 0; i < q - 1; i++)
    if (v[i] != v[i + 1])
    {
      printf("MATRIZ NAO EH UM QUADRADO LATINO\n");
      MostrarMatriz(m, q, p);
      return;
    }

  for (j = 0; j < q; j++)
  {
    v[j] = 0;
    for (i = 0; i < q; i++)
    {
      v[j] += m[i][j];
      for (k = 0; k < q; k++)
      {
        if (m[i][j] == m[k][j] && i != k)
        {
          printf("A MATRIZ NAO EH UM QUADRADO LATINO\n");
          MostrarMatriz(m, q, p);
          return;
        }
      }
    }
  }

  for (i = 0; i < q - 1; i++)
    if (v[i] != v[i + 1])
    {
      printf("A MATRIZ NAO EH UM QUADRADO LATINO\n");
      MostrarMatriz(m, q, p);
      return;
    }

  printf("A MATRIZ EH UM QUADRADO LATINO\n");
  MostrarMatriz(m, q, p);
  return; 
}

void QuadMagico(int **m, int q, int p)
{
  LerMatriz(m, q, p);
  if (!(Quadrada(q, p)))
  {
    printf("\nMATRIZ NAO QUADRADA\n");
    MostrarMatriz(m, q, p);
    return;
  }

  int somaC = 0, somaL = 0, somaDs = 0, somaDp = 0;
  for (int i = 0; i < q; i++)
  {
    somaDp += m[i][i];
    somaDs += m[i][q - i - 1];
  }

  if (somaDp != somaDs)
  {
    printf("A MATRIZ NAO EH UM QUADRADO MAGICO\n");
    MostrarMatriz(m, q, p);
    return;
  }

  for (int i = 0; i < q; i++)
  {
    somaC = 0, somaL = 0;
    for (int j = 0; j < p; j++)
    {
      somaL += m[i][j];
      somaC += m[j][i];
    }
    if (somaC != somaL)
    {
      printf("A MATRIZ NAO EH UM QUADRADO MAGICO\n");
      MostrarMatriz(m, q, p);
      return;
    }
  }
  printf("A MATRIZ EH UM QUADRADO MAGICO\n");
  MostrarMatriz(m, q, p);
  return;
}

int Quadrada(int q, int p)
{
  if (q == p)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void Permuta(int **m, int q, int p)
{
  LerMatriz(m, q, p);
  int i, j;
  int somacol[q], soma;

  if (!(Quadrada(q, p)))
  {
    printf("\nMATRIZ NAO QUADRADA\n");
    MostrarMatriz(m, q, p);
    return;
  }

  for (i = 0; i < q; i++)
  {
    somacol[i] = 0;
  }

  for (i = 0; i < q; i++)
  {
    soma = 0;
    for (j = 0; j < q; j++)
    {
      if (m[i][j] != 1 && m[i][j] != 0)
      {
        printf("\nNAO EH UMA MATRIZ PERMUTACAO\n");
        MostrarMatriz(m, q, p);
        return;
      }
      else
      {
        somacol[j] += m[i][j];
        soma += m[i][j];
      }
    }
    if (soma != 1)
    {
      printf("\nNAO EH UMA MATRIZ PERMUTACAO\n");
      MostrarMatriz(m, q, p);
      return;
    }
  }

  for (i = 0; i < q; i++)
  {
    if (somacol[i] != 1)
    {
      printf("\nNAO EH UMA MATRIZ PERMUTACAO\n");
      MostrarMatriz(m, q, p);
      return;
    }
  }

  printf("\nEH UMA MATRIZ PERMUTACAO\n");
        MostrarMatriz(m, q, p);
  return;
}

void clearbuff()
{
  while (getchar() != '\n');
}

void freememory(int **m, int q)
{
  for (int i = 0; i < q; i++)
  {
    free(m[i]);
  }
  free(m);
}

void ajuda1()
{ 
    system("cls");
    printf("::::: AJUDA DO MENU VERIFICADORES :::::\n");
    printf("O menu de verificacoes possui cinco tipos de funcoes para verificacao de matrizes, sendo elas:\n");
    printf("\n1- Simetrica: verifica se a matriz eh simetrica.\n");
    printf("   -> Quando a matriz eh igual a sua transposta (A=At).\n");
    printf("\n2- Quadrado Magico: verifica se a matriz eh um quadrado magico.\n");
    printf("   -> Quando a soma dos elementos de cada linha, cada coluna e das diagonais forem iguais.\n");
    printf("\n3- Quadrado Latino: verifica se a matriz eh um quadrado latino.\n");
    printf("   -> Quando cada linha e cada coluna aparecem todos os inteiros 1,2,3,...,n (com 'n' sendo a ordem a matriz).\n");
    printf("\n4- Matriz de Permutacao: verifica se a matriz eh de permutacao.\n");
    printf("   -> Quando cada linha e cada coluna houver 'n-1' elementos nulos e um elemento valendo '1'.\n");
    printf("\n5- Nula: verifica se a matriz eh do tipo nula.\n");
    printf("   -> Quando todos os elementos valem 0 (nulos).\n");
    printf("ATENCAO:\n");
    printf(ANSI_COLOR_RED "\nESC: VOLTAR PARA O MENU INICIAL || ENTER: VOLTAR PARA O MENU VERIFICADORES" ANSI_COLOR_RESET "\n");
}

void ajuda2()
{ 
    system("cls");
    printf("::::: AJUDA DO MENU TRANSFORMADORES :::::\n");
    printf("O menu de transformadores possui tres tipos de funcoes para verificacao de matrizes, sendo elas:\n");
    printf("\n1- Troca uma linha X por uma linha Y\n");
    printf("\n2- Troca uma coluna x por uma coluna Y.\n");
    printf("\n3- Inverter Diagonais: Troca a diagonal principal pela diagonal secundária\n");
    printf("   -> Essa ação primeiro verifica se sua matriz é quadrática\n");
    printf("ATENCAO:\n");
     printf(ANSI_COLOR_RED "\nESC: VOLTAR PARA O MENU INICIAL || ENTER: VOLTAR PARA O MENU VERIFICADORES" ANSI_COLOR_RESET "\n");
}

void ajudaPrimario(){
  { 
    system("cls");
    printf("::::: AJUDA PRIMARIO :::::\n");
    printf("O programa consiste em um operador de matrizes, com diversas funcionalidades para matrizes.\n");
    printf("\nINICIAR- Voce iniciara o programa e terá que digitar o numero de colunas e linhas de sua matriz desejada.\n");
    printf("   -> Certifique-se de colocar numeros validos e reais\n");
    printf("\nSAIR- Voce encerra o programa.\n");
    printf("ATENCAO:\n");
    printf(ANSI_COLOR_RED "\nESC: VOLTAR PARA O MENU" ANSI_COLOR_RESET "\n");
}

void ajudaPrincipal(){
  { 
    system("cls");
    printf("::::: AJUDA MENU PRINCIPAL :::::\n");
    printf("\nExistem duas opcoes nesse menu, Transformador e Verificador.\n");
    printf("   -> AO ENTRAR NAS TELAS DISPONIVEIS, SEJA ELA VERIFICADOR OU TRANSFORMADOR, PODERA APRETAR F1 PARA UMA EXPLICACAO MAIS DETALHADA DE CADA FUNCAO ALI PROPOSTA.\n");
    printf("ATENCAO:\n");
    printf(ANSI_COLOR_RED "\nESC: FECHAR O PROGRAMA || ENTER: VOLTAR AO MENU" ANSI_COLOR_RESET "\n");
}
}
}