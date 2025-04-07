#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

struct dirent *dptr;

int main() {
    char buff[100];
    DIR *dirp;

    printf("\n\nEnter the Directory Name: ");
    scanf("%s", buff);

    if ((dirp = opendir(buff)) == NULL) {
        printf("The given directory doesn't exist.\n");
        exit(1);
    }

    while ((dptr = readdir(dirp)) != NULL) {
        printf("%s\n", dptr->d_name);
    }

    closedir(dirp);
    return 0;
}
