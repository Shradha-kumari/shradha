#include<stdio.h>
void main()
{
    int bt[10],p[15],ct[30],tat[10],i,j,n,pos,temp;
    float average_tat,at[20];
    printf("Enter process required:");
    scanf("%d",&n);
    printf("\nEnter Burst Time of process:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;        
    }
    printf("Enter arrival time of processes:\n");
    for(i=0;i<n;i++)
    {
     printf("P%d:",i+1);
     scanf("%f",&at[i]);
    }
    for(i=0;i<n;i++)
    {
     pos=i;
     for(j=i+1;j<n;j++)
     {
      if(bt[j]<bt[pos])
        pos=j;
     }
     temp=bt[i];
     bt[i]=bt[pos];
     bt[pos]=temp;
     temp=p[i];
     p[i]=p[pos];
     p[pos]=temp;
    }
     ct[0]=bt[0]+at[0];
     for(i=1;i<n;i++)
     {
      ct[i]=ct[i-1]+bt[i];
     }
    for(i=0;i<n;i++)
    {
      tat[i]=ct[i]-at[i];
      average_tat=average_tat+tat[i];
    }
     printf("Process  Arrival_Time   Burst_Time Turn_Around_Time \n");
     for(i=0;i<n;i++)
     {
      printf("P%d        %.1f\t	     %d	           %d	        \n",p[i],at[i],bt[i],tat[i]);
     }
     average_tat=average_tat/n; 
     printf("\nAverage Turnaround Time=%f\n",average_tat);
}
