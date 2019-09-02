#include <stdio.h>
#include <conio.h>
char name[10][15];//ARRAY WHICH STORE NAME OF TRANSCATION
int i,n,j;
int trans[10][5];//ARRAY WHICH STORE AMOUNT OF TRANSCATION
int  items () //THIS FUNCTION WILL ACCEPT NAME OF THE TRANSCATION
{
   printf("How many transcation you want to enter:");
   scanf("%d", &n);
   printf("Enter Name of %d transcation Like 'Food' or 'Cake'\n", n);
   for (i = 0; i < n; i++)
       {
	printf("Enter The Name:");
	scanf("%s", name[i]);
       }
return (n);
}
int trans_amt() //THIS FUNCTION WILL ACCEPT AMOUNT OF TRANSCATION FROM M1 TO M4
{
   for(i=0;i<n;i++)
      {
	 printf("Amount of trasncation for %s:\n",name[i]);
	    for(j=1;j<=4;j++)
	       {
		printf("Amount By M%d=",j);
		scanf("%d",&trans[i][j]);
	       }
	 printf("\n");
      }
return 0;
}
int print()//THIS FUNCTION WILL PRINT THE BILL RECIPT INITIAL AND FINAL
{
    printf("---------TRANSCATION STATEMENT----------\n");
    printf("\t M1\t M2\t M3\t M4\t TOTAL\n");

	 for(i=0;i<n;i++)
	    {
	      printf("%s\t",name[i]);
		for(j=1;j<=5;j++)
		   {
		    printf(" %d\t",trans[i][j]);
		   }
	      printf("\n");
	    }
return 0;
}
int bill_split_2(int amount,int eql,int temp,int t)//THIS FUCTION WILL CALCULATE AMOUNT WHICH USER HAVE TO PAY AND BY HOW MUCH TO WHOM
{
	for(j=1;j<=4;j++)
	   {
	     if(trans[t][j]>eql)
	       {
		trans[t][j]-=amount;
		trans[t][temp]+=amount;
		printf("\nM%d Given Rs %d to M%d",temp,amount,j);
		break;
	       }
	   }
     check(t);
 return 0;
}
int bill_split(int t ) //THIS FUNCTION WILL CALLUATE THE EQUAL AMOUNT WHICH USER HAVE TO PAY AND PASS THE AMOUNT TO ABOVE FUCTION
{   int eql, sum=0,amt,temp;
	 for(j=1;j<=4;j++)
	    {
	     sum+=trans[t][j];
	    }
	trans[t][5]=sum;
	eql=sum/4;
	 for(j=1;j<=4;j++)
	    { if(trans[t][j]!=eql)
		{  if(trans[t][j]<eql)
		    {
		     amt=eql-trans[t][j];
		     bill_split_2(amt,eql,j,t);
		    }

		}
	    }
return 0;
}
int check(int t) //THIS FUNCTION WILL CHECK WEATHER EVERYONE HAVE EQUALL AMOUNT OR NOT
{    int sum=0,eql;
     for(j=1;j<=4;j++)
	{
	 sum+=trans[t][j];
	}
     eql=sum/4;

     for(j=1;j<=4;j++)
	{ if(trans[t][j]!=eql)
	    {
	     bill_split(t);
	    }
	}
return 0;
}
void main()
{
 clrscr();
 items();
 trans_amt();
 print();
   for(i=0;i<n;i++)
      {
	printf("\n---------BILL SPLIT FOR %s--------",name[i]);
	bill_split(i);
      }
 printf("\n");
 print();
 getch();
}
