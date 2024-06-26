/*
   ALUNO: MURILO TOMAZ GONZAGA,
   TURMA BCC-024,
   TRABALHO 2 DA MATERIA DE ALGORITMOS.
*/


//SE EU TIVESSE MAIS 1 DIA CONSEGUIRIA TRAZER UM RESULTADO AINDA MELHOR, MAIS CONSCISO, ORGANIZADO E COM MAIS FUNCIONALIDADES.


#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
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

// Declaração das funções

//Funcoes lógicas
int Quadrada(int q, int p);
void LinhaXporY(int **m, int q, int p);
void ColunaXporY(int **m, int q, int p);
void DPporDS(int **m, int q, int p);
void Simetria(int **m, int q, int p);
void QuadLatino(int **m, int q, int p);
void QuadMagico(int **m, int q, int p);
void Permuta(int **m, int q, int p);
void ApenasImp(int **m, int q, int p);
void MatrizNula(int **m, int q, int p);

//Funcoes Auxiliares
int **AlocarMemoria(int q, int p);
void LerMatriz(int **m, int q, int p);
void MostrarMatriz(int **m, int q, int p, int mod);
void clearbuff();
void freememory(int **m, int q);
void escreveTexto(int x, int y, char texto[], int cor);
void desenhaQuadrado(int x1, int y1, int x2, int y2, int cor);
void Mensagem();
void mensagem2(char i[], int x, int y);
void escreveElemento(int x, int y, int elemento, int cor);
//Ajudas
void ajuda1();
void ajuda2();
void ajudaPrimario();
void ajudaPrincipal();

//Menus

void inicio(int op);
int menuInicio();
void menu(int op);
int menuSelecao();
void menuTrans(int op);
int menuTransformar();
void menuVer(int op);
int menuVerificar();

// Função principal
// void inicio(int op)
// {
//   char vet[][30] = {"INICIAR", "SAIR"};
//   int i;
//   system("cls");

//   desenhaQuadrado(1, 20, 10, 60, 6);

//   escreveTexto(3, 25, "Bem Vindo ao Operador de Matrizes", 6);

//   for (i = 0; i < 2; i++)
//   {
//     escreveTexto(6 + i, 25, vet[i], 10);
//   }
//   escreveTexto(6 + op - 1, 25, vet[op - 1], 6);
// }
// int main()
// {
//   int bb;
// MENU1:
//   bb = menuInicio();

//   if (bb == 1)
//   {
//     int q, p;
    
//     desenhaQuadrado(1, 20, 10, 60, 6);
//     escreveTexto(3, 25, "DIGITE A ORDEM DA SUA MATRIZ", 6);
//     escreveTexto(5, 25, "Linhas: ", 6);
//     gotoxy(33, 5);
//     scanf("%d", &q);
//     escreveTexto(6, 25, "Colunas: ", 6);
//     gotoxy(34, 6);
//     scanf("%d", &p);

//     int **m = AlocarMemoria(q, p);
//     int opcaoSelecionada;

//   REFAZ:
//     opcaoSelecionada = menuSelecao();

//     if (opcaoSelecionada == 1)
//     {
//       int selecaoTrans;
//     VOLTA:
//       selecaoTrans = menuTransformar();
//       if (selecaoTrans == 1)
//       {
//         LinhaXporY(m, q, p);
//         gotoxy(0, 24);
//         printf("\n");
//       }
//       else if (selecaoTrans == 2)
//       {
//         ColunaXporY(m, q, p);
//         gotoxy(0, 24);
//         printf("\n");
//       }
//       else if (selecaoTrans == 3)
//       {
//         DPporDS(m, q, p);
//         gotoxy(0, 24);
//         printf("\n");
//       }
//       else if (selecaoTrans == 9)
//       {
//         goto VOLTA;
//       }
//       else
//       {
//         goto REFAZ;
//       }
//     }
//     else if (opcaoSelecionada == 2)
//     {
//       int selecaoVer;
//     VOLTA2:
//       selecaoVer = menuVerificar();
//       if (selecaoVer == 1)
//       {
//         Simetria(m, q, p);
//         gotoxy(0, 24);
//         printf("\n");
//       }
//       else if (selecaoVer == 2)
//       {
//         QuadMagico(m, q, p);
//         gotoxy(0, 24);
//         printf("\n");
//       }
//       else if (selecaoVer == 3)
//       {
//         QuadLatino(m, q, p);
//         gotoxy(0, 24);
//         printf("\n");
//       }
//       else if (selecaoVer == 4)
//       {
//         Permuta(m, q, p);
//         gotoxy(0, 24);
//         printf("\n");
//       }
//       else if (selecaoVer == 5)
//       {
//         MatrizNula(m, q, p);
//         gotoxy(0, 24);
//         printf("\n");
//       }
//       else if (selecaoVer == 9)
//       {
//         goto VOLTA2;
//       }
//       else
//       {
//         goto REFAZ;
//       }
//       // }else if(op == 3){
//     }
//     else if (opcaoSelecionada == 9 || opcaoSelecionada == 4)
//     {
//       ajudaPrincipal();
//       if (getch() == esc)
//       {
//         system("cls");
//         Mensagem();
//         printf("\n\n");
//         return 0;
//       }
//       goto REFAZ;
//     }else if(opcaoSelecionada == 3){
//       ApenasImp(m, q, p);
//       gotoxy(0, 24);
//     }
//     else
//     {
//       system("cls");
//       Mensagem();
//       printf("\n\n");
//       return 0;
//     }
//     freememory(m, q);
//     return 0;
//   }
//   else if (bb == 3 || bb == 9)
//   {
//     ajudaPrimario();
//     if (getch() == esc)
//     {
//       goto MENU1;
//     }
//   }
//   else
//   {
//     system("cls");
//     Mensagem();
//     return 0;
//   }
// }

//MAIN!!
int main() {
    int bb;
    int continuar = 1; 

    while (continuar) { 
        bb = menuInicio();

        if (bb == 1) {
            int q, p;

            desenhaQuadrado(1, 20, 10, 60, 6);
            escreveTexto(3, 25, "DIGITE A ORDEM DA SUA MATRIZ", 6);
            escreveTexto(5, 25, "Linhas: ", 6);
            gotoxy(33, 5);
            scanf("%d", &q);
            escreveTexto(6, 25, "Colunas: ", 6);
            gotoxy(34, 6);
            scanf("%d", &p);

            int **m = AlocarMemoria(q, p);
            int opcaoSelecionada;

        REFAZ:
            opcaoSelecionada = menuSelecao();

            if (opcaoSelecionada == 1) {
                int selecaoTrans;
            VOLTA:
                selecaoTrans = menuTransformar();
                if (selecaoTrans == 1) {
                    LinhaXporY(m, q, p);
                    gotoxy(0, 24);
                    printf("\n");
                } else if (selecaoTrans == 2) {
                    ColunaXporY(m, q, p);
                    gotoxy(0, 24);
                    printf("\n");
                } else if (selecaoTrans == 3) {
                    DPporDS(m, q, p);
                    gotoxy(0, 24);
                    printf("\n");
                } else if (selecaoTrans == 9) {
                    goto VOLTA;
                } else {
                    goto REFAZ;
                }
            } else if (opcaoSelecionada == 2) {
                int selecaoVer;
            VOLTA2:
                selecaoVer = menuVerificar();
                if (selecaoVer == 1) {
                    Simetria(m, q, p);
                    gotoxy(0, 18);
                    printf("\n");
                } else if (selecaoVer == 2) {
                    QuadMagico(m, q, p);
                    gotoxy(0, 18);
                    printf("\n");
                } else if (selecaoVer == 3) {
                    QuadLatino(m, q, p);
                    gotoxy(0, 18);
                    printf("\n");
                } else if (selecaoVer == 4) {
                    Permuta(m, q, p);
                    gotoxy(0, 18);
                    printf("\n");
                } else if (selecaoVer == 5) {
                    MatrizNula(m, q, p);
                    gotoxy(0, 18);
                    printf("\n");
                } else if (selecaoVer == 9) {
                    goto VOLTA2;
                } else {
                    goto REFAZ;
                }
            } else if (opcaoSelecionada == 9 || opcaoSelecionada == 4) {
                ajudaPrincipal();
                if (getch() == esc) {
                    system("cls");
                    Mensagem();
                    printf("\n\n");
                    break; 
                }
                goto REFAZ;
            } else if (opcaoSelecionada == 3) {
                ApenasImp(m, q, p);
                gotoxy(0, 24);
            } else {
                system("cls");
                Mensagem();
                printf("\n\n");
                break; 
            }
            freememory(m, q);
        } else if (bb == 3 || bb == 9) {
            ajudaPrimario();
            if (getch() == esc) {
                continue; 
            }
        } else {
            system("cls");
            Mensagem();
            break; 
        }

        char resposta;
        printf("Deseja executar o programa novamente? (s/n): ");
        scanf(" %c", &resposta); 
        if ((resposta == 'n' || resposta == 'N') || (resposta != 's' && resposta != 'S')) {
            system("cls");
            Mensagem();
            continuar = 0; 
        }
    }
    return 0;
}


//FUNCOES ---- ATENCAO - NAO ESTAO ORGANIZADAS COMO NA CHAMADA NO INCIO DO CODIGO!!

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

void MostrarMatriz(int **m, int q, int p, int mod)
{
  int i = 0, j = 0;
  int offset = (mod == 0) ? 4 : 15;
  for (i = 0; i < q; i++)
  {
    for (j = 0; j < p; j++)
    {
      int z = m[i][j];
      int t = j;
      if (p >= 4)
      {
        t = j - 1 * (p / 3);
      }
      escreveElemento(offset + i, 35 + t * 4, z, 6);
    }
    printf("\n");
  }
}

//-----------------------------------------------------------------------------------------



void ApenasImp(int **m, int q, int p){
  int mod = 0;
  char mes[] = "IMPRESSAO";
  LerMatriz(m,q,p);
  system("cls");
  mensagem2(mes, 63, 75);
  escreveTexto(3, 26, "MATRIZ COM LINHAS INSUFICIENTES\n", 6);
  desenhaQuadrado(1, 20, 10, 60, 6);
  MostrarMatriz(m, q, p, mod);
  return;
}
void LinhaXporY(int **m, int q, int p)
{
  int x, y, aux = 0;
  int mod;
  char mes[] = "TROCA DE LINHAS";
  LerMatriz(m, q, p);

  if (q < 2)
  {
    system("cls");
    mod = 0;
    escreveTexto(2,65 , "TROCA DE LINHAS\n", 4);
    desenhaQuadrado(1, 63, 3, 81 , 4);
    escreveTexto(3, 26, "MATRIZ COM LINHAS INSUFICIENTES\n", 6);
    desenhaQuadrado(1, 20, 10, 60, 6);
    MostrarMatriz(m, q, p, mod);
    return;
  }
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
  mod = 0;
  mensagem2(mes, 63, 82);
  desenhaQuadrado(1, 20, 10, 60, 6);
  escreveTexto(3, 32, "MATRIZ ORIGINAL\n", 6);
  MostrarMatriz(m, q, p, mod);
  printf("\n\n");
  for (int j = 0; j < p; j++)
  {
    aux = m[x - 1][j];
    m[x - 1][j] = m[y - 1][j];
    m[y - 1][j] = aux;
  }
  mod = 1;
  desenhaQuadrado(12, 20, 21, 60, 6);
  escreveTexto(14, 32, "MATRIZ MODIFICADA", 6);
  MostrarMatriz(m, q, p, mod);
  printf("\n\n");
}

void ColunaXporY(int **m, int q, int p)
{
  int x, y, aux = 0;
  char mes[] = "TROCA DE COLUNAS";
  int mod;
  LerMatriz(m, q, p);

  if (p < 2)
  {
    system("cls");
    mod = 0;                      
    mensagem2(mes, 63, 82);
    escreveTexto(3, 25, "MATRIZ COM COLUNAS INSUFICIENTES\n", 6);
    desenhaQuadrado(1, 20, 10, 60, 6);
    MostrarMatriz(m, q, p, mod);
    return;
  }

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
  mod = 0;
  mensagem2(mes, 63, 82);
  desenhaQuadrado(1, 20, 10, 60, 6);
  escreveTexto(3, 32, "MATRIZ ORIGINAL\n", 6);
  MostrarMatriz(m, q, p, mod);
  printf("\n\n");
  for (int i = 0; i < q; i++)
  {
    aux = m[i][x - 1];
    m[i][x - 1] = m[i][y - 1];
    m[i][y - 1] = aux;
  }
  mod = 1;
  desenhaQuadrado(12, 20, 21, 60, 6);
  escreveTexto(14, 32, "MATRIZ MODIFICADA", 6);
  MostrarMatriz(m, q, p, mod);
  printf("\n\n");
}

void DPporDS(int **m, int q, int p)
{
  LerMatriz(m, q, p);
  int aux = 0, mod = 0;
  char mes[] = "DP POR DS";
  if (!(Quadrada(q, p)))
  {
    system("cls");
    mensagem2(mes, 63, 75);
    desenhaQuadrado(1, 20, 10, 60, 6);
    escreveTexto(3, 26, "MATRIZ NAO QUADRADA\n", 6);
    MostrarMatriz(m, q, p, mod);
    printf("\n\n");
    return;
  }
  system("cls");
  mensagem2(mes, 63, 75);
  desenhaQuadrado(1, 20, 10, 60, 6);
  escreveTexto(3, 32, "MATRIZ ORIGINAL\n", 6);
  MostrarMatriz(m, q, p, mod);
  printf("\n\n");
  for (int i = 0; i < q; i++)
  {
    aux = m[i][i];
    m[i][i] = m[i][q - i - 1];
    m[i][q - i - 1] = aux;
  }
  mod = 1;
  desenhaQuadrado(12, 20, 21, 60, 6);
  escreveTexto(14, 32, "MATRIZ MODIFICADA", 6);
  MostrarMatriz(m, q, p, mod);
  printf("\n\n");
}

void Simetria(int **m, int q, int p)
{
  int mod = 0;
  char mes[] = "SIMETRIA";
  LerMatriz(m, q, p);
  if (!(Quadrada(q, p)))
  {
    system("cls");
    mensagem2(mes, 63, 74);
    desenhaQuadrado(1, 20, 10, 60, 6);
    escreveTexto(3, 32, "MATRIZ NAO QUADRADA\n", 6);
    MostrarMatriz(m, q, p, mod);
    printf("\n\n");
    return;
  }

  for (int i = 0; i < q; i++)
  {
    for (int j = 0; j < p; j++)
    {
      if (m[i][j] != m[q - 1 - i][p - 1 - j])
      {
        system("cls");
        mensagem2(mes, 63, 74);
        desenhaQuadrado(1, 20, 10, 60, 6);
        escreveTexto(3, 32, "MATRIZ NAO SIMETRICA\n", 6);
        MostrarMatriz(m, q, p, mod);
        printf("\n\n");
        return;
      }
    }
  }
  system("cls");
  mensagem2(mes, 63, 74);
  desenhaQuadrado(1, 20, 10, 60, 6);
  escreveTexto(3, 32, "MATRIZ SIMETRICA\n", 6);
  MostrarMatriz(m, q, p, mod);
  printf("\n\n");
  return;
}

void QuadLatino(int **m, int q, int p)
{
  char mes[] = "QUADLATINO";
  LerMatriz(m, q, p);
  int i, j, k, v[q], mod = 0;

  if (!(Quadrada(q, p)))
  {
    system("cls");
    mensagem2(mes, 63, 76);
    desenhaQuadrado(1, 20, 10, 60, 6);
    escreveTexto(3, 32, "MATRIZ NAO QUADRADA\n", 6);
    MostrarMatriz(m, q, p, mod);
    printf("\n\n");
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
          system("cls");
          mensagem2(mes, 63, 76);
          desenhaQuadrado(1, 20, 10, 60, 6);
          escreveTexto(3, 28, "MATRIZ EH UM QUADRADO LATINO\n", 6);
          MostrarMatriz(m, q, p, mod);
          printf("\n\n");
          return;
        }
      }
    }
  }

  for (i = 0; i < q - 1; i++)
    if (v[i] != v[i + 1])
    {
      system("cls");
      mensagem2(mes, 63, 76);
      desenhaQuadrado(1, 20, 10, 60, 6);
      escreveTexto(3, 28, "MATRIZ NAO EH UM QUADRADO LATINO\n", 6);
      MostrarMatriz(m, q, p, mod);
      printf("\n\n");
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
          system("cls");
          mensagem2(mes, 63, 76);
          desenhaQuadrado(1, 20, 10, 60, 6);
          escreveTexto(3, 28, "MATRIZ NAO EH UM QUADRADO LATINO\n", 6);
          MostrarMatriz(m, q, p, mod);
          printf("\n\n");
          return;
        }
      }
    }
  }

  for (i = 0; i < q - 1; i++){
    if (v[i] != v[i + 1])
    {
      system("cls");
      mensagem2(mes, 63, 76);
      desenhaQuadrado(1, 20, 10, 60, 6);
      escreveTexto(3, 28, "MATRIZ NAO EH UM QUADRADO LATINO\n", 6);
      MostrarMatriz(m, q, p, mod);
      printf("\n\n");
      return;
    }
  }
  system("cls");
  mensagem2(mes, 63, 76);
  desenhaQuadrado(1, 20, 10, 60, 6);
  escreveTexto(3, 28, "MATRIZ EH UM QUADRADO LATINO\n", 6);
  MostrarMatriz(m, q, p, mod);
  printf("\n\n");
  return;
}

void QuadMagico(int **m, int q, int p)
{
  char mes[] = "QUADMAGICO";
  int mod = 0;
  LerMatriz(m, q, p);
  if (!(Quadrada(q, p)))
  {
    system("cls");
    mensagem2(mes, 63, 76);
    desenhaQuadrado(1, 20, 10, 60, 6);
    escreveTexto(3, 32, "MATRIZ NAO QUADRADA\n", 6);
    MostrarMatriz(m, q, p, mod);
    printf("\n\n");
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
    system("cls");
    mensagem2(mes, 63, 76);
    desenhaQuadrado(1, 20, 10, 60, 6);
    escreveTexto(3, 28, "MATRIZ NAO EH QUADRADO MAGICO\n", 6);
    MostrarMatriz(m, q, p, mod);
    printf("\n\n");
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
      system("cls");
      mensagem2(mes, 63, 76);
      desenhaQuadrado(1, 20, 10, 60, 6);
      escreveTexto(3, 28, "MATRIZ NAO EH QUADRADO MAGICO\n", 6);
      MostrarMatriz(m, q, p, mod);
      printf("\n\n");
      return;
    }
  }
  system("cls");
  mensagem2(mes, 63, 76);
  desenhaQuadrado(1, 20, 10, 60, 6);
  escreveTexto(3, 28, "MATRIZ EH QUADRADO MAGICO\n", 6);
  MostrarMatriz(m, q, p, mod);
  printf("\n\n");
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
  char mes[] = "PERMUTACAO";
  LerMatriz(m, q, p);
  int i, j, mod = 0;
  int somacol[q], soma;

  if (!(Quadrada(q, p)))
  {
    system("cls");
    mensagem2(mes, 63, 76);
    desenhaQuadrado(1, 20, 10, 60, 6);
    escreveTexto(3, 32, "MATRIZ NAO QUADRADA\n", 6);
    MostrarMatriz(m, q, p, mod);
    printf("\n\n");
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
        system("cls");
        mensagem2(mes, 63, 76);
        desenhaQuadrado(1, 20, 10, 60, 6);
        escreveTexto(3, 28, "MATRIZ NAO EH PERMUTACAO\n", 6);
        MostrarMatriz(m, q, p, mod);
        printf("\n\n");
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
      system("cls");
      mensagem2(mes, 63, 76);
      desenhaQuadrado(1, 20, 10, 60, 6);
      escreveTexto(3, 28, "MATRIZ NAO EH PERMUTACAO\n", 6);
      MostrarMatriz(m, q, p, mod);
      printf("\n\n");
      return;
    }
  }

  for (i = 0; i < q; i++)
  {
    if (somacol[i] != 1)
    {
      system("cls");
      mensagem2(mes, 63, 76);
      desenhaQuadrado(1, 20, 10, 60, 6);
      escreveTexto(3, 28, "MATRIZ NAO EH PERMUTACAO\n", 6);
      MostrarMatriz(m, q, p, mod);
      printf("\n\n");
      return;
    }
  }
  system("cls");
  mensagem2(mes, 63, 76);
  desenhaQuadrado(1, 20, 10, 60, 6);
  escreveTexto(3, 28, "MATRIZ EH PERMUTACAO\n", 6);
  MostrarMatriz(m, q, p, mod);
  printf("\n\n");
  return;
}

void MatrizNula(int **m, int q, int p)
{
  char mes[] = "NULA";
  int i, j, mod = 0;
  LerMatriz(m, q, p);
  for (i = 0; i < q; i++)
  {
    for (j = 0; j < p; j++)
    {
      if (m[i][j] != 0)
      {
        system("cls");
        mensagem2(mes, 63, 69);
        desenhaQuadrado(1, 20, 10, 60, 6);
        escreveTexto(3, 32, "MATRIZ NAO NULA\n", 6);
        MostrarMatriz(m, q, p, mod);
        printf("\n\n");
        return;
      }
    }
  }
  system("cls");
  mensagem2(mes, 63, 69);
  desenhaQuadrado(1, 20, 10, 60, 6);
  escreveTexto(3, 32, "MATRIZ NULA\n", 6);
  MostrarMatriz(m, q, p, mod);
  printf("\n\n");
  return;
}

void clearbuff()
{
  while (getchar() != '\n')
    ;
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

void ajudaPrimario()
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

void ajudaPrincipal()
{
  system("cls");
  printf("::::: AJUDA MENU PRINCIPAL :::::\n");
  printf("\nExistem duas opcoes nesse menu, Transformador e Verificador.\n");
  printf("   -> AO ENTRAR NAS TELAS DISPONIVEIS, SEJA ELA VERIFICADOR OU TRANSFORMADOR, PODERA APRETAR F1 PARA UMA EXPLICACAO MAIS DETALHADA DE CADA FUNCAO ALI PROPOSTA.\n");
  printf("ATENCAO:\n");
  printf(ANSI_COLOR_RED "\nESC: FECHAR O PROGRAMA || ENTER: VOLTAR AO MENU" ANSI_COLOR_RESET "\n");
}

void escreveTexto(int x, int y, char texto[], int cor)
{
  SetColor(cor);
  gotoxy(y, x);
  printf("%s", texto);
}

void escreveElemento(int x, int y, int elemento, int cor)
{
  SetColor(cor);
  gotoxy(y, x);
  printf("%d  ", elemento);
}

void desenhaQuadrado(int x1, int y1, int x2, int y2, int cor)
{
  char linhaHorizontal[100];
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
  char vet[][30] = {"INICIAR", "SAIR (ESC)", "AJUDA (F1)"};
  int i;
  system("cls");

  desenhaQuadrado(1, 20, 10, 60, 6);

  escreveTexto(3, 25, "Bem Vindo ao Operador de Matrizes", 6);

  for (i = 0; i < 3; i++)
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
        if (op != 3)
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
          op = 3;
        inicio(op);
      }
      else if (t == f1)
        return op = 9;
    }
    else if (t == enter)
    {
      system("cls");
      return op;
    }
  } while (t != esc);
  return -1;
}

void menu(int op)
{
  char vet[][20] = {"Transformar", "Verificar", "APENAS IMPRIMIR", "F1 para Ajuda"}, mes[] = "ESC PARA ENCERRAR";
  int i;
  system("cls");
  mensagem2(mes, 63, 82);
  desenhaQuadrado(1, 20, 10, 60, 6);
  escreveTexto(2, 25, "MENU INICIAL", 6);
  for (i = 0; i < 4; i++)
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
        if (op != 4)
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
          op = 4;
        
        menu(op);
      }
      else if (t == f1)
      {
        return op = 9;
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

void menuTrans(int op)
{
  char vet[][30] = {"Trocar linha X por linha Y", "Trocar coluna X por coluna Y", "Trocar diagonais", "Voltar"}, mes[] = "F1 PARA AJUDA";
  int i;
  system("cls");
  mensagem2(mes, 63, 78);
  desenhaQuadrado(1, 20, 10, 60, 7);
  escreveTexto(2, 25, "TRANSFORMACOES NA MATRIZ", 7);
  for (i = 0; i < 4; i++)
    escreveTexto(5 + i, 25, vet[i], 10);
  escreveTexto(4 + op, 25, vet[op - 1], 7);
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
      else if (t == f1)
      {
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
    else if (t == esc)
    {
    }
  } while (t != esc);
  return -1;
}

void menuVer(int op)
{
  char vet[][30] = {"Simetria", "Quadrado magico?", "Quadrado latino?", "Matriz permutacao", "Matriz Nula", "Voltar"}, mes[] = "F1 PARA AJUDA";
  int i;
  system("cls");
  mensagem2(mes, 63, 78);
  desenhaQuadrado(1, 20, 12, 60, 3);
  escreveTexto(2, 25, "VERIFICACOES NA MATRIZ", 3);
  for (i = 0; i < 6; i++)
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
        if (op != 6)
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
          op = 6;
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

void Mensagem()
{
  puts(

      " _____  _            _                    _                       _                            \n"
      "|  _  || |          (_)                  | |                     | |                           \n"
      "| | | || |__   _ __  _   __ _   __ _   __| |  ___    _ __    ___ | |  ___    _   _  ___   ___  \n"
      "| | | || '_ \\ | '__|| | / _` | / _` | / _` | / _ \\  | '_ \\  / _ \\| | / _ \\  | | | |/ __| / _ \\ \n"
      "\\ \\_/ /| |_) || |   | || (_| || (_| || (_| || (_) | | |_) ||  __/| || (_) | | |_| |\\__ \\| (_) |\n"
      " \\___/ |_.__/ |_|   |_| \\__, | \\__,_| \\__,_| \\___/  | .__/  \\___||_| \\___/   \\__,_||___/ \\___/ \n"
      "                         __/ |                      | |                                        \n"
      "                        |___/                       |_|                                        \n");
}

void mensagem2(char i[], int x, int y){
  escreveTexto(2,65 , i, 4);
  desenhaQuadrado(1, x, 3, y , 4);
}