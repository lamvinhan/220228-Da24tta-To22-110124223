#include<stdio.h>
#define MAX 255
int main()
{
	char path [50];
	FILE *fp;
	
	
	printf ("\nNhap duong dan :");
	fflush(stdin);
	gets(path);
	fp=fopen(path,"at");
	if (fp==NULL)
	{
		printf("\nLoi mo file ");
		
	}
	else
	{
		fprintf (fp ,"\nHoc phai di doi voi hanh  ");
		fprintf (fp ,"\nCo cong mai sat co ngay nen kim ");
		fprintf (fp ,"\nAi nhut thi toi dung nhi ");
		fprintf (fp ,"\nai ma hon nua thi toi dung ba ");
		fclose (fp);
		
		
	}
	
	
}

Hoc phai di doi voi hanh  
Co cong mai sat co ngay nen kim 
Ai nhut thi toi dung nhi 
ai ma hon nua thi toi dung ba 