#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
//--------------------------------------------------------------
int SetColor (char color) {
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}
//--------------------------------------------------------------
int main () {
  int i;
  for (i = 0; i <= 127; i++) {
    SetColor (i);
    printf (" Cor %d ",i);
  }  
  system ("pause");
  SetColor (23);
  system ("cls");  // clrscr();
  printf ("Bom dia");
}