#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int main()
{
    int a[16],i,j;
    Fillvalue(a);
    a[15]=' ';
    rules();
    gotoxy(0,3);
    // ( To print matrix of array
    for(i=0;i<=15;i=i+4)
    {
        for(j=i;j<i+4;j++)
        {
            if(a[j]<10)
                printf("|%d  ",a[j]);
            else if(a[j]>=10&&a[j]<=15)
                printf("|%d ",a[j]);
                else
                    printf("|   ");
        }
        printf("\n");
    }// To Print matrix of array )
    gotoxy(13,6);
    play(a,15,13,6);
}
/* To initialize array with random values */
Fillvalue(int a[])
{

    int i,j;
    srand(time(NULL));
    for(i=0;i<=14;i++)
        {
            a[i]=rand()%15+1;
            for(j=i-1;j>=0;j--)
            {
                if(a[i]==a[j])
                    i-=1;
            }
        }
}
play(int a[], int k, int x, int y)
{
    int i,n=200;
    char ch;
    while(n)
    {
        for(i=0;i<=14;i++)
            if(a[i]!=i+1)
                break;
        if(i==15)
        {
            printf("\n\n      YOU WIN");
            break;
        }
        gotoxy(0,1);
        printf("MOVES REMAINING: %d  ",n);
        gotoxy(x,y);
        ch=getch();
        switch(ch)
            {
            case 'w':
                if(k+4<=15)
                {
                    a[k]=a[k+4];
                    a[k+4]=' ';
                    printf("%d",a[k]);
                    gotoxy(x,y+1);
                    printf("   ");
                    k=k+4;
                    gotoxy(x,y+1);
                    y=y+1;
                    n--;
                }
                break;
            case 's':
                if(k-4>=0)
                {
                    printf("%d",a[k-4]);
                    gotoxy(x,y-1);
                    printf("   ");
                    a[k]=a[k-4];
                    a[k-4]=' ';
                    k=k-4;
                    gotoxy(x,y-1);
                    y=y-1;
                    n--;
                }
                break;
            case 'a':
                if(k!=15 && k!=11 && k!=7 && k!=3)
                {
                    printf("%d",a[k+1]);
                    gotoxy(x+4,y);
                    printf("   ");
                    a[k]=a[k+1];
                    a[k+1]=' ';
                    k=k+1;
                    gotoxy(x+4,y);
                    x=x+4;
                    n--;
                }
                break;
            case 'd':
                if(k!=0 && k!=4 && k!=8 && k!=12)
                {
                    printf("%d",a[k-1]);
                    gotoxy(x-4,y);
                    printf("   ");
                    a[k]=a[k-1];
                    a[k-1]=' ';
                    k=k-1;
                    gotoxy(x-4,y);
                    x=x-4;
                    n--;
                }
                break;
            case 'e':
                exit(0);
            }
    }
    if(n==0)
        printf("\n          GAME OVER");
}
// To print rules of the game
void rules()
{
    char name[20];
    printf("                                        WELCOME TO 'THE NUMBER SORTING GAME'\n\n");
    printf("Enter your name ");
    fgets(name,19,stdin);
    printf("                            RULES OF THE GAME\n\n");

    printf("1. You can move only one step at time\n");
    printf("Move Up   : By pressing 'w' key\n");
    printf("Move Down : By pressing 's' key\n");
    printf("Move Right: By pressing 'd' key\n");
    printf("Move Left : By pressing 'a' key\n\n");
    printf("2. You can move at empty position only\n\n");
    printf("3. For each valid move your total number of moves will decrease by 1\n\n");
    printf("4. You can exit the game at any time by pressing 'e'\n\n");
    printf("WINNING SITUATION : Number in the 4*4 matrix must be ordered from 1 to 15\n\n");
    printf("|1  |2  |3  |4  \n");
    printf("|5  |6  |7  |8  \n");
    printf("|9  |10 |11 |12 \n");
    printf("|13 |14 |15 |   \n\n");
    printf("                        Best of Luck\n");
    printf("press any key to start....");
    getch();
    system("cls");
    printf("NAME: %s",name);
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
