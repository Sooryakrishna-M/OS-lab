#include<stdio.h>
#include<stdlib.h>
#include<direct.h>

struct dirent*dptr;
int main (int argc,char*argv[]){
char buff[100]
DIR*dirp;
printf("\n\nEnter the Directory Name");
scanf("%s",buff);
if((dirp=opendir(buff))==NULL){
    printf("The given directory doesnt exist");
    exit(1);

}
while(dptr=readdir(dirp)){
    printf("%s\n",dprt->d_name);
}
closedir(dirp);
}