#include<stdio.h>
int main()
{
 char hoten[50];
 char lop[20];
  //Nhap ho ten
  printf(" nhap ho ten cua ban\n :");
  fflush(stdin);
  gets(hoten);
  
  //Nhap Lop
  printf(" nhap lop cua ban\n :");
  fflush(stdin);
  gets(lop);
  
  //Xuat thong tin 
  printf("\n thong tin cua ban :\n");
  printf(" ho ten : %s", hoten);
  printf(": lop : %s", lop);
  
  return 0;
  
}
	
