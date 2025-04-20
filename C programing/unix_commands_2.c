#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    char fn[10],pat[10],temp[200];
    FILE*fp;
    printf("Enter the file name");
    scanf("%s",fn);
    printf("Enter the patern to be searched\n");
    scanf("%s",pat);
    fp=fopen(fn,"r");
    while (!feof(fp))
    {
        fgets(temp,1000,fp);
        if (strstr(temp,pat))
        {
            printf("%s",temp);
        }
        fclose(fp);
        
    }
    

}