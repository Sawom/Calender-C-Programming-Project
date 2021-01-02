#include<stdio.h>

int firstDay(int year){
  int day;
  day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
  return day;
}

int main(){
    int year;
    printf("Enter which year to show calender...\n");
    scanf("%d",&year);
    char *month[]={"January" , "February" , "March" , "April" , "May", "June" , "July" , "August" , "September", "October" ,  "November" , "December" };
    int monthDay[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i,j,weekDay=0,space=0,totalDay;

    if((year%4==0 && year%100!=0) || (year%400==0) ){
        monthDay[1]=29;
    }

    weekDay= firstDay(year);

    printf("\nHappy New Year ' %d ' \n",year);
    for(i=0;i<12;i++){
        printf("\n\n---------------%s-------------------\n",month[i]);
        printf("\n   Sun   Mon   Tue   Wed   Thur   Fri   Sat\n");
        for(space=1;space<=weekDay;space++){
            printf("      ");
        }

        totalDay=monthDay[i];
         for(j=1;j<=totalDay;j++){
            printf("%6d",j);
            weekDay++;
            if(weekDay>6){
            weekDay=0;
            printf("\n");
            }
         }
    }

}
