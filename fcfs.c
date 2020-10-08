#include<stdio.h>
#include<stdlib.h>
int waiting_time(int wait_time[],int turn_time[],int burst_time[],int n)
{
    int i;
    for(i=0;i<n;i++){
        wait_time[i]=turn_time[i]-burst_time[i];
    }
}
int turnaround_time(int turn_time[],int burst_time[],int n)
{
    int i,temp=0;
    for(i=0;i<n;i++){
        temp+=burst_time[i];
        turn_time[i]=temp;
    }
}
void main_fn()
{
    int n,i;
    float temp1=0.0,temp2=0.0;
    int burst_time[10],wait_time[10],turn_time[10];
    printf("No of processes:");
    scanf("%d",&n);
    printf("Enter the burst time:");
    for(i=0;i<n;i++){
        scanf("%d",&burst_time[i]);
    }
    turnaround_time(turn_time,burst_time,n);
    waiting_time(wait_time,turn_time,burst_time,n);
    printf("\nPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\n",i+1,burst_time[i],wait_time[i],turn_time[i]);
    }
    for(i=0;i<n;i++){
        temp1+=wait_time[i];
        temp2+=turn_time[i];
    }
    printf("Avg Waiting time: %.3fms",temp1/n);
    printf("\nAvg Turnaround time: %.3fms\n",temp2/n);
}
void main(){
    int ch;
    while(1){
        printf("\nMenu\n1.FCFS Scheduling\n2.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: main_fn();
                    break;
            case 2: exit(1);
                    break;
            default: printf("Wrong choice!");
        }
    }
}
