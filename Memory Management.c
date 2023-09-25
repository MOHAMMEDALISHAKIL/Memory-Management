#include<stdio.h>
int main() {
    int i, j, k, n, page[50], frameno, frame[10], move = 0;
    int  flag, count = 0, count1[10] = {0}, repindex, leastcount;
    float rate;
    printf("enter length of the reference string: ");
    scanf("%d", &n);
    printf("Enter the reference string:\n");
    for (i=0;i<n;i++)
        scanf("%d",&page[i]);
    printf("Enter no of frames: ");
    scanf("%d",&frameno);
    for (i = 0; i<frameno;i++)
        frame[i] = -1;
    printf("\nPage reference string: \tFrames\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t\t", page[i]);
        flag =0;
        for (j=0; j<frameno;j++) {
            if (page[i]==frame[j]) {
                flag=1;
                count1[j]++;
                printf("hit \n");
                break;
            }
        }

        if (flag == 0 && count < frameno){
            frame[move] = page[i];
            count1[move] = 1;
            move = (move + 1) % frameno;
            count++;
            for (j = 0; j < frameno; j++)
                printf("%d\t", frame[j]);
            printf("\n");
        } else if (flag == 0) {
            repindex = 0;
            leastcount = count1[0];

            for (j = 1; j < frameno; j++) {
                if (count1[j] < leastcount) {
                    repindex = j;
                    leastcount = count1[j];
                }
            }
            frame[repindex] = page[i];
            count1[repindex] = 1;
            count++;
            for (j = 0; j < frameno; j++)
                printf("%d\t", frame[j]);
            printf("\n");
        }
    }
    rate = (float)count / (float)n*100;
    printf("\nNo of page faults : %d\n", count);
    printf("Page Fault rate     :  %f\n", rate);
    return 0;
}
