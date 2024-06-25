#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define baixo 80
#define cima 72
#define esc 27
#define enter 13
#define f1 59

void gotoxy (int x, int y) {
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int SetColor (char color) {
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}

void escreveTexto (int x, int y, char texto[], int cor){
  SetColor (cor);
  gotoxy (y,x);
  printf ("%s",texto);
}

void menu (int op){
  char vet[][20] = {"OPCAO DO MENU 1", "OPCAO 2", "OPCAO 3", "OPCAO 4"};
  int i;
  system ("cls");
  for (i = 0; i < 4; i++)
    escreveTexto (3+i,10,vet[i],10);
  escreveTexto (2+op,10,vet[op-1],5);  
}

int main(){
  int op;
  char t;
  op = 1;
  menu (op);
  do{
	  t = getch();
	  // se for caracter especial
	  if (t <= 0){
	    t = getch();
	  if (t == baixo){
	    if (op != 4) op++; 
		   else op = 1;
		menu (op);
	  }
	  else if (t == cima) {
	  	if (op != 1) op--;
		else op = 4;
		menu (op);
	  }
	  else if (t == f1)
	         printf ("AJUDA");
    }
    else
      if (t == enter) {
        system("cls"); // limpa a tela quando Enter é pressionado
        printf("Opcao selecionada: %d\n", op);
        break; // sai do loop
      }
	} while (t != esc);
  
}
