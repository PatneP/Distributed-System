#include<stdio.h>
//#include<conio.h>
void main()
{
 int allocated[15][15],max[15][15],need[15][15],avail[15],tres[15],work[15],flag[15];
 int pno,rno,i,j,prc,count,t,total;
 count=0;
// clrscr();
 
 printf("\n Enter number of process:");
 scanf("%d",&pno);
 printf("\n Enter number of resources:");
 scanf("%d",&rno);
 for(i=1;i <= pno;i++)
 {
  flag[i]=0;
 }
 printf("\n Enter total numbers of each resources:");
 for(i=1;i<= rno;i++)
  scanf("%d",&tres[i]);
 
 
 printf("\n Enter Max resources for each process:");
 for(i=1;i<= pno;i++)
 {
  printf("\n for process %d:",i);
  for(j=1;j<= rno;j++)
   scanf("%d",&max[i][j]);
 }
 
 
 printf("\n Enter allocated resources for each process:");
 for(i=1;i<= pno;i++)
 {
  printf("\n for process %d:",i);
  for(j=1;j<= rno;j++)
   scanf("%d",&allocated[i][j]);
 
 
 }
 
 printf("\n available resources:\n");
 for(j=1;j<= rno;j++)
 {
  avail[j]=0;
  total=0;
  for(i=1;i<= pno;i++)
  {
   total+=allocated[i][j];
  }
  avail[j]=tres[j]-total;
  work[j]=avail[j];
  printf("     %d \t",work[j]);
 }
 
 
 do
 {
 
 
 
 for(i=1;i<= pno;i++)
 {
  for(j=1;j<= rno;j++)
  {
   need[i][j]=max[i][j]-allocated[i][j];
  }
 }
 
 printf("\n Allocated matrix        Max      need");
 for(i=1;i<= pno;i++)
 {
  printf("\n");
  for(j=1;j<= rno;j++)
  {
   printf("%4d",allocated[i][j]);
  }
  printf("|");
  for(j=1;j<= rno;j++)
  {
   printf("%4d",max[i][j]);
  }
   printf("|");
  for(j=1;j<= rno;j++)
  {
   printf("%4d",need[i][j]);
  }
 }
 
 
 
 
  prc=0;
 
  for(i=1;i<= pno;i++)
  {
   if(flag[i]==0)
   {
    prc=i;
 
    for(j=1;j<= rno;j++)
    {
     if(work[j]< need[i][j])
     {
       prc=0;
       break;
     }
    }
   }
 
   if(prc!=0)
   break;
  }
 
  if(prc!=0)
  {
   printf("\n Process %d completed",i);
   count++;
   printf("\n Available matrix:");
   for(j=1;j<= rno;j++)
   {
    work[j]+=allocated[prc][j];
    allocated[prc][j]=0;
    max[prc][j]=0;
    flag[prc]=1;
    printf("   %d",work[j]);
   }
  }
 
 }while(count!=pno&&prc!=0);
 
 if(count==pno)
  printf("\nThe system is in a safe state!!");
 else
  printf("\nThe system is in an unsafe state!!");
  
//getch();
}
