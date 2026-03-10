#include <stdio.h>

int main()
{
    int n,i,t=0,completed=0;
    int at[10],bt[10],pr[10],rt[10];
    int ct[10],tat[10],wt[10];
    int min,pos;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        rt[i]=bt[i];
    }

    while(completed<n)
    {
        min=999;
        pos=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=t && rt[i]>0 && pr[i]<min)
            {
                min=pr[i];
                pos=i;
            }
        }

        if(pos!=-1)
        {
            rt[pos]--;
            t++;

            if(rt[pos]==0)
            {
                completed++;
                ct[pos]=t;
                tat[pos]=ct[pos]-at[pos];
                wt[pos]=tat[pos]-bt[pos];
            }
        }
        else
            t++;
    }

    printf("P\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}
