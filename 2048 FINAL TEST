#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#define WIN 2048
int arr[5][5];
int b[5][5];
void copy();
int check();
int getkey();
void generate();
void UP();
void DOWN();
void RIGHT();
void LEFT();
int largest();
void print();
int check();
int check_zero();
void random_create();
int count=0;

int getkey()
{
 int ch;
 ch=getch();
 if(ch==224)
 {
    ch=getch();
    return ch;
 }
 return ch;
}
void generate()
{

    int c=0;
    srand(time(NULL));
    arr[rand()%5][rand()%5]=2;
    arr[rand()%5][rand()%5]=2;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
          if(arr[i][j]==2)
            c++;
        }

        if(c==2)
            break;
    }
    if(c==1)
    arr[rand()%3][rand()%3]=2;
}
int largest()
{
    int a=2;
    for(int i=0;i<5;i++)
    {

        for(int j=0;j<5;j++)
        {
         if(arr[i][j]>a)
            a=arr[i][j];
        }
    }
    return a;
}
void print()
{

    if(check())
    {
        Beep(450,200);
        count++;
    printf("\n\n");
    for(int i=0;i<5;i++)
    {

        for(int j=0;j<5;j++)
        {
          printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    int check=largest();
    printf("\t\t\t\t\t\t\t\t\tLARGEST NUMBER REACHED:%d\n",check);
    if(check==WIN)
    {
        printf("\n\n***CONGRATULATIONS YOU WON***\a\n");
        printf("NUMBER OF VALID MOVES MADE=%d \n",(count-1));
        printf("***TRY WITH MORE MINIMUM NUMBER OF MOVES NEXT TIME***\n");

    }
    }

}
void random_create()
{
    if(check() && check_zero())
    {
   int a=rand()%5;
    int b=rand()%5;
    while(arr[a][b]!=0)
    {
        a=rand()%5;
        b=rand()%5;
    }
    arr[a][b]=2;
    }

}
int check()
{
    int flag=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
          if(b[i][j]!=arr[i][j])
            flag=1;
        }
    }
    if(flag==1)
        return 1;
    else
        return 0;
}
int check_zero()
{
    int flag=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
          if(arr[i][j]==0)
            flag=1;
        }
    }
    return flag; // returns 1 if 0 present
}
void copy()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
          b[i][j]=arr[i][j];
        }
    }
}
int check_adjacent()
{
    int (*p)[5];
    int *pint;
    int flag=0;
    for(int i=0;i<5;i++)
    {
        p=&arr[i];
        pint=(int *)p;
        for(int j=0;j<5;j++)
        {
            flag=(*(pint+j)==*(pint+j+5))?1:flag;
            flag=(*(pint+j)==*(pint+j-5))?1:flag;
          if(j!=0 && j!=4)
          {
             flag=(*(pint+j)==*(pint+j+1))?1:flag;
             flag=(*(pint+j)==*(pint+j-1))?1:flag;
          }
        }
    }
   return flag; //returns 1 if adjacent  equal element present else 0
}
void UP()
{

    int i,j;
    for(j=0;j<5;j++)
    {
        i=1;
        while(1)
        {
            while(arr[i][j]==0)
            {
                if(i==5)
                    break;
                i++;
            }
            if(i==5)
                break;
            while(i>0 && (arr[i-1][j]==0 || arr[i][j]==arr[i-1][j]))
            {
                arr[i-1][j]+=arr[i][j];
                arr[i][j]=0;
                i--;
            }
            i++;
        }
    }
}
void DOWN()
{
    int i,j;
    for(j=0;j<5;j++)
    {
        i=3;
        while(1)
        {
            while(arr[i][j]==0)
            {
                if(i==-1)
                    break;
                i--;
            }
            if(i==-1)
                break;
            while(i<4 && (arr[i+1][j]==0 || arr[i][j]==arr[i+1][j]))
            {
                arr[i+1][j]+=arr[i][j];
                arr[i][j]=0;
                i++;
            }
            i--;
        }
    }
}
void LEFT()
{

    int i,j;
    for(i=0;i<5;i++)
    {
        j=1;
        while(1)
        {
            while(arr[i][j]==0)
            {
                if(j==5)
                    break;
                j++;
            }
            if(j==5)
                break;
            while(j>0 && (arr[i][j-1]==0 || arr[i][j]==arr[i][j-1]))
            {
                arr[i][j-1]+=arr[i][j];
                arr[i][j]=0;
                j--;
            }
            j++;
        }
    }
}
void RIGHT()
{

    int i,j;
    for(i=0;i<5;i++)
    {
        j=3;
        while(1)
        {
            while(arr[i][j]==0)
            {
                if(j==-1)
                    break;
                j--;
            }
            if(j==-1)
                break;
            while(j<4 && (arr[i][j+1]==0 || arr[i][j]==arr[i][j+1]))
            {
                arr[i][j+1]+=arr[i][j];
                arr[i][j]=0;
                j++;
            }
            j--;
        }
    }
}
int ending()
{

    if(!(check_zero()))
    {
        if(!(check_adjacent()))
        {
            printf("***SORRY!!! GAME OVER***\a\n");
            printf("LARGEST NUMBER REACHED:%d\n",largest());
            printf("NUMBER OF VALID MOVES MADE=%d \a\n",(count-1));
            printf("***BETTER LUCK NEXT TIME***\n");
            exit(1);
        }
    }
    return 1;
}

int main()
{
    printf("\t\t\t%c%c%c\t\t2048 GAME \t\t\t%c%c%c\n",177,177,177,177,177,177);
    printf("***HOW TO PLAY***\n***THERE ARE SOME NUMBERS ON BOARD***\n");
    printf("***USE ARROW KEYS OR W,A,S,D KEYS TO MOVE THE NUMBERS***\n");
    printf("***A NEW NUMBER 2 WILL APPEAR AFTER EVERY MOVE***\n");
    printf("***WHEN TWO SAME NUMBERS COLLIDE THEY MERGE INTO ONE***\n");
    printf("***WHEN 5*5 BOARD IS FILLED UP, YOU LOSE***\n");
    printf("***WHEN A 2048 NUMBER IS CREATED YOU WIN***\n");
    printf("***TRY TO MAKE 2048 IN MINIMUM NUMBER OF VALID MOVES***\n");
    printf("***ENTER ESC KEY TO QUIT***\n");


    copy();
    generate();
    print();
    while(ending())
    {
     switch(getkey())
     {

        case 72:
        case 87:
        case 119:copy();
                 UP();
                 random_create();
                 print();
                 break;
        case 75:
        case 65:
        case 97:copy();
                LEFT();
                random_create();
                print();
                break;
        case 80:
        case 83:
        case 115:copy();
                 DOWN();
                 random_create();
                 print();
                 break;
        case 77:
        case 68:
        case 100:copy();
                 RIGHT();
                 random_create();
                 print();
                 break;
        case 27:printf("\nNUMBER OF VALID MOVES MADE=%d \a\n",(count-1));
                exit(1);
                break;
        default : printf("\nENTER VALID KEYS !\n");
                    Beep(750,200);
      }
    }
    return 0;
}
