#include<stdio.h>
#include<time.h>
#include<string.h>



int main()
{

    int i;
    double r;
    char name[100];
    char AP[20];
    int hour, minute;
    int hour1, minute1;
    int a,p,overtimeH,overtimeM;
    time_t t;
    time(&t);
    printf(" \n Day of Attendence %s",ctime(&t));
    printf(" Enter a number of employee:- ");
    scanf("%d",&p);
    printf("\n");

    printf("\n ATTENDENCE SHEET\n\n ");
    for( i=1; i<=p; i++)
    {

        printf("Enter the %d employee Roll Number:-",i);
        scanf("%lf",&r);
        printf(" Enter the %d employee Name:-",i);
        scanf("%s",&name);
        printf(" Enter the %d employee Attendence:-",i);
        scanf("%s",&AP);
        printf(" Enter the %d employee hour: ",i);
        scanf("%d", &hour);
        printf(" Enter the %d employee minute: ",i);
        scanf("%d", &minute);
        if (8 < hour && hour < 11 && 12 <= minute && minute< 44)
        {
            printf("%d employee's Entered time is: 9:30 AM\n", i);
        }
        else if (8 < hour && hour < 11 && 45 <= minute)
        {
            printf("%d employee's Entered time is: 10:00 AM\n", i );
        }
        else
        {
            printf(" %d employee's entry time is: %02d:%02d AM\n", i,hour,minute);
        }


        printf("\nENTER THE EXIT TIME\n\n");
        printf("Enter the %d employee exit hour: ",i);
        scanf("%d", &hour1);
        printf("Enter the %d employee exit minute: ",i);
        scanf("%d", &minute1);
        printf("the EXIT TIME of %d employee: %02d:%02d PM\n",i, hour1, minute1);
        overtimeH=hour-hour1;
        overtimeM=minute-minute1;
        printf("the OVER TIME WORK of %d employee: %02d:%02d PM\n",i, overtimeH, overtimeM);
        printf("\n");

    }
    printf("\n");
    FILE *fp;
    fp = fopen("Company11.txt", "a+");
    if(fp==NULL)
    {
        printf("Error Opening File!");
        return 1;

    }
    for(int j=1; j<=p; j++)
    {
        fprintf(fp," The  Roll Number of %d employee:-%.0lf\n",j,r);
        fprintf(fp," The Name of %d employee:-%s\n",j,name);
        fprintf(fp," The Attendence of %d employee:-%s\n",j,AP);

        if(9<=hour && 11<=minute)
        {
            fprintf(fp," Employee Entry Time is: 9:30\n");
        }
        else
        {
            fprintf(fp,"The Entry Time of employee: %02d:%02d AM\n",j, hour, minute);
        }
        fprintf(fp,"The EXIT TIME of %d employee: %02d:%02d PM\n",j, hour1, minute1);
        fprintf(fp,"The OVER TIME WORK of %d employee: %02d:%02d PM\n",j, overtimeH, overtimeM);

        fprintf(fp, "-----------------------------------------------------------------\n");
    }
    fclose(fp);
    return 1;
}
