#include<stdio.h>

int findLRU(int time[], int n){
    int i,min=time[0],pos=0;
    for(i=1;i<n;i++){
        if(time[i]<min){
            min=time[i];
            pos=i;
        }
    }
    return pos;
}

int main(){
    int frames,pages,i,j,pos,faults=0,counter=0;
    int ref[100],frame[10],time[10],found;

    printf("Enter the number of pages :");
    scanf("%d",&pages);

    printf("Enter the reference string\n");
    for(i=0;i<pages;i++){
        scanf("%d",&ref[i]);
    }
    printf("Enter the number of frames\n");
    scanf("%s",&frames);

    for(i=0;i<frames;i++){
        frame[i]=-1;
        time[i]=0;
    }

    Printf("\n Page Replacement Process\n");

    for(i=0;i<pages;i++){
        found=0;
        for(j=0;j<frames;j++){
            if(frame[j]==ref[j]){
                found=1;
                time[j]=++counter;
                break;
            }
        }
        if (!found)
        {
            pos=findLru(time,frames);
            frame[pos]=ref[i];
            time[pos]=++counter;
            faults++;
            for(j=0;j<frames;j++){
                printf("%d",frame[j]);
                printf("<-page fault\n");
            }
        }
        else{
            for(j=0;j<frames;j++){
                printf("%d",frame[j]);
                printf("\n");
            }
            
        }  
    }
    printf("Total number of page faults: %d\n",faults);
    return 0;
}