#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void main()
 {
  int ch;

do{

   printf("\n MENU DRIVEN\n1.FCFS\n2.SJF\n3.priority scheduling\n4.Round Robin\n");
   printf("enter the choice\n");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1: printf("enter the number of processes\n");
             int n,i,j;
          double awt,atat,temp,tat[100],wt[100],bt[100],ct[100];
           scanf("%d",&n);
           for(i=0;i<n;i++)
           {
            printf("enter the burst time of P%d\n",i+1);
            scanf("%lf",&bt[i]);
           }
            printf("process\tBT\tWT\tTAT\n");
           for(i=0;i<n;i++)
           {
            wt[i]=0;
            tat[i]=0;
            for(j=0;j<i;j++)
            {
             wt[i]=wt[i]+bt[j];
            }
             tat[i]=wt[i]+bt[i];
             awt=awt+wt[i];
             atat=atat+tat[i];

            printf("P%d\t%.2f\t%.2f\t%.2f\n",i,bt[i],wt[i],tat[i]);
           }
          awt=awt/n;
          atat=atat/n;
          printf("avg wt=%f\n",awt);
          printf("avg TAT=%f\n",atat);

          break;

    case 2:

           printf("enter the number of processes\n");
           int p[100],pos=0,ns;
          double sawt,satat,stemp,stat[100],swt[100],sbt[100],sct[100];
           scanf("%d",&ns);
           for(i=0;i<ns;i++)
           {
            printf("enter the burst time of P%d\n",i+1);
            scanf("%lf",&sbt[i]);
            p[i]=i+1;
           }
      for(i=0;i<ns;i++)
      {
        pos=i;
        for(j=i+1;j<ns;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        stemp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=stemp;

        stemp=p[i];
        p[i]=p[pos];
        p[pos]=stemp;
      }
       i=0,j=0;

  printf("process\tBT\tWT\tTAT\n");
           for(i=0;i<ns;i++)
           {
            swt[i]=0;
            stat[i]=0;
            for(j=0;j<i;j++)
            {
             swt[i]=swt[i]+sbt[j];
            }
             stat[i]=swt[i]+sbt[i];
             sawt=sawt+swt[i];
             satat=satat+stat[i];

            printf("P%d\t%.2f\t%.2f\t%.2f\n",i,sbt[i],swt[i],stat[i]);
           }
          sawt=sawt/ns;
          satat=satat/ns;
          printf("avg wt=%f\n",sawt);
          printf("avg TAT=%f\n",satat);

          break;

case 3:
         printf("Enter Total Number of Process:");
         double pbt[20],pwt[20],ptat[20],pr[20],total=0,ptemp,pawt,patat;
         int np,p1[20],pos1;
         scanf("%d",&np);

         printf("\nEnter Burst Time and Priority\n");
         for(i=0;i<np;i++)
        {
          printf("\nP[%d]\n",i+1);
          printf("Burst Time:");
          scanf("%lf",&pbt[i]);
          printf("Priority:");
          scanf("%lf",&pr[i]);
          p1[i]=i+1;
    }


    for(i=0;i<np;i++)
    {
        pos1=i;
        for(j=i+1;j<np;j++)
        {
            if(pr[j]<pr[pos1])
                pos1=j;
        }

        ptemp=pr[i];
        pr[i]=pr[pos1];
        pr[pos1]=ptemp;

        ptemp=pbt[i];
        pbt[i]=pbt[pos1];
        pbt[pos1]=ptemp;

        ptemp=p1[i];
        p1[i]=p1[pos1];
        p1[pos1]=ptemp;
    }

    pwt[0]=0;
    for(i=1;i<np;i++)
    {
        pwt[i]=0;
        for(j=0;j<i;j++)
            pwt[i]+=pbt[j];

        total+=pwt[i];
    }

    pawt=total/np;      //average waiting time
    total=0;

    printf("\npriority\tProcess\t\t  Burst Time \t\tWaiting Time\t\t   Turnaround Time");
    for(i=0;i<np;i++)
    {
        ptat[i]=pbt[i]+pwt[i];     //calculate turnaround time
        total+=ptat[i];
        printf("\n%lf\tP[%d]\t\t  %lf\t\t    %lf\t\t\t%lf",pr[i],p1[i],pbt[i],pwt[i],ptat[i]);
    }

    patat=total/np;     //average turnaround time
    printf("\n\nAverage Waiting Time=%lf",pawt);
    printf("\nAverage Turnaround Time=%lf\n",patat);

return 0;

break;




 case 4:
        printf("enter the no of processes\t");

        int nr,quantum,processes;
        double rbt[100],rwt[100],rem_bt[200],rtat[200],avg_tat,avg_wt;
          scanf("%d",&nr);
       for(i=0;i<nr;i++)
           {
            printf("enter the burst time of P%d\n",i+1);
            scanf("%lf",&rbt[i]);
            rem_bt[i]=rbt[i];
           }
        printf("enter the time slice\t");
        scanf("%d",&quantum);

        double total_wt = 0, total_tat = 0;

    int t = 0;
        while(true)
        {
            bool done = true;
            for (int i = 0 ; i < nr; i++)
            {

                if (rem_bt[i] > 0)
                {
                    done = false;

                    if (rem_bt[i] > quantum)
                    {
                        t += quantum;
                        rem_bt[i] -= quantum;
                    }

                    else
                    {

                        t = t + rem_bt[i];
                        rwt[i] = t - rbt[i];
                        rem_bt[i] = 0;
                    }
                }
            }
            if (done == true)
            break;
        }

        for (int i = 0; i < nr ; i++)
            rtat[i] = rbt[i] + rwt[i];




        printf("Processes  Burst time   Waiting time  Turn around time\n");
        for (int i = 0; i < nr; i++)
        {
            total_wt = total_wt + rwt[i];
            total_tat = total_tat + rtat[i];
           printf("P%d\t\t%.2f\t%.2f\t\t%.2f\n",i+1,rbt[i],rwt[i],rtat[i]);
        }
        printf("\n");
     avg_wt=total_wt /(float)nr;
     avg_tat=total_tat /(float)nr;

      printf("Average waiting time =%lf \n",avg_wt);
        printf("Average turn around time =%lf \n",avg_tat);
            break;
  default:printf("EXITING.........");
           }
}
            while(ch<5);

 }
