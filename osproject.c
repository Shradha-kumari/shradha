#include<stdio.h>
void main()
{
 int burst_t[5],completion_t[5],turnaround_time[5],i,n;
 float atat=0,arrival_t[10];
 printf("\nEnter number of processes:");
 scanf("%d",&n);
 printf("\nEnter arrival time of processes:");
 for(i=0;i<n;i++)
 {
  printf("\nP%d:",i+1);
  scanf("%f",&arrival_t[i]);
 }
 printf("\nEnter burst time of processes:");
 for(i=0;i<n;i++)
 {
  printf("\nP%d:",i+1);
  scanf("%d",&burst_t[i]);
 }
 completion_t[0]=burst_t[0]+arrival_t[0];
 for(i=1;i<n;i++)
 {
   completion_t[i]=completion_t[i-1]+burst_t[i];
 }
 for(i=0;i<n;i++)
 {
 turnaround_time[i]=completion_t[i]-arrival_t[i];
 
 atat=atat+turnaround_time[i];
 }
 printf("Process Arrival_time Burst_Time Turn_Around_Time \n");
 for(i=0;i<n;i++)
{
 printf("P%d      %.2f	    %d	           %d\n",i+1,arrival_t[i],burst_t[i],turnaround_time[i]);
}

atat=atat/n;
printf("Average Turn around time:%.2f",atat);
}
