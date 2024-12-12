#include <stdio.h>
#include <string.h>


int main (){
	FILE *fp;
	char str[100];
	
	// Mo file de doc
	fp = fopen("data.txt", "r");
	if (fp == NULL ) {
		printf (" Khong the mo file!\n ");
		return 1;	
	}
	  // Doc tung dong va in ra man hinh
	  while (fgets(str, 100, fp) != NULL) {
        printf("%s", str);
    }

    // Ðóng file
    fclose(fp);
	  
	  
	  
	return 0;
	
}
