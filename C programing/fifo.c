#include <stdio.h>

int main() {
    int frames, pages, i, j, k, pos = 0, faults = 0;
    int ref[100], frame[10], found;

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    printf("Enter the reference string:\n");
    for(i = 0; i < pages; i++) {
        scanf("%d", &ref[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage Replacement Process:\n");

    for(i = 0; i < pages; i++) {
        found = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frame[pos] = ref[i];
            pos = (pos + 1) % frames;
            faults++;

            for(k = 0; k < frames; k++)
                printf("%d ", frame[k]);
            printf(" <- Page Fault\n");
        } else {
            for(k = 0; k < frames; k++)
                printf("%d ", frame[k]);
            printf("\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", faults);
    return 0;
}
