#include<stdio.h>
#define PI 3.14159
int main ()
{
	// Khai bao cac bien
	float a = 50.0;
	float b = 23.0;
	float h = 30.0;
	
	// Khai bao cac bien cho hinh tron
	float chu_vi_hinh_tron = 12.56;
	float r, dien_tich_hinh_tron;
	
	// Tinh dien tich hinh thang
	float dien_tich_hinh_thang =((a+b)*h)/2;
	
	// Tinh ban kinh hinh tron
	r = chu_vi_hinh_tron / (2*PI);

	 // Tinh dien tich hinh tron
	 dien_tich_hinh_tron =PI*r*r;
	 
	 // Tinh dien tich con lai cua san truong 
	 float dien_tich_con_lai = dien_tich_hinh_thang - dien_tich_hinh_tron;
	   
	 // Xuat thong tin
	 printf(" dien tich hinh thang:%.2f m^2\n",dien_tich_hinh_thang);
	 printf(" dien tich hinh tron:%.2f m^2\n ",dien_tich_hinh_tron);
	 printf(" dien tich con lai cua san truong :%.2f m^2\n",dien_tich_con_lai);
	    
	    return 0;
	    }
