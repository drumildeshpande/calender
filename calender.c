#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

void gotoxy(int x, int y)
{
     COORD coord;
     coord.X = x;
     coord.Y = y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void logo()
{
     int i,j;
     int logo[6][41]={1,1,1,1,0,1,1,1,1,0,1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,0,0,1,1,1,1,0,1,1,1,1,
                      1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,
                      1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,1,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,1,1,0,0,1,1,1,1,
                      1,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,1,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,1,1,0,0,1,1,0,0,
                      1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,
                      1,1,1,1,0,1,0,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,0,0,1,1,1,1,0,1,0,0,1};
     for(i=0;i<6;i++)
     {
         gotoxy(20,i);
         for(j=0;j<41;j++)
         {
             if(logo[i][j]==1)
                 printf("%c",177);
             else
                 printf("%c",32);
         }
         printf("\n");
     } 
     printf("\n\nPress any key to enter:");
     getch();                                                                                       
}

void printOptions()
{
     gotoxy(30,12);
     printf("Right - Next Month\n"); 
     gotoxy(30,13);
     printf("Left - Previous Month\n");
     gotoxy(30,14);
     printf("Up - Next Year \n"); 
     gotoxy(30,15);
     printf("Down - Previous Year\n"); 
     gotoxy(30,16);
     printf("q - To Quit \n");
     gotoxy(30,17);
     printf("r - To view to do record \n");
     gotoxy(30,18);
     printf("e - To enter a record \n");
}

void toDo()
{
     system("cls");
     int i;
     char record[100];
     char ch,c;
     FILE *todo;
     todo=fopen("todo.txt","a+");
     printf("press 'y' to enter a record: ");
     ch=getch();
     if(ch=='y' || ch=='Y')
     {
         printf("Enter the record :\n");
         scanf("%[^\n]",record);
         fprintf(todo,"Record :%s\n",record);
         time_t rcrdtime;
         rcrdtime = time(NULL);
         fprintf(todo,"Entery Date :%s",ctime(&rcrdtime));
         for(i=0;i<=50;i++)
             fprintf(todo,"%c",'_');
         fprintf(todo,"\n");
         fclose(todo);
     }
     printf("wanna see past records press 'y'\n");
     ch=getch();
     system("cls");
     if(ch=='y' || ch=='Y')
     {
         todo=fopen("todo.txt","r");
         do
         {
             putchar(c=getc(todo));
         }while(c!=EOF);
     }
     getch();
     fclose(todo);
}

int main()
{
	int m,y,ld,i,s,firstday,d,col,row,a;
	long int nd,td;
	int days[ ]={31,0,31,30,31,30,31,31,30,31,30,31};
	char *months[ ]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY",
		           "AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
    logo();
	system("cls");
    SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	y=str_t.wYear;
	m=str_t.wMonth;
    while (y>0)
	{
        system("cls");
		nd=(y-1)*365L;
		ld=(y-1)/4+(y-1)/400-(y-1)/100;
		td=nd+ld;
		if ((y%400==0)||(y%100!=0 && y%4==0))
			days[1]=29;
		else
			days[1]=28;
		s=0;
		for (i=0;i<=m-2;i++)
			s=s+days[i];
		td=td+s;
		firstday=td%7;
		col=20+firstday*6;
		gotoxy(35,1);
		printf("%s  %d",months[m-1],y);
		gotoxy(20,3);
		printf("MON   TUE   WED   THU   FRI   SAT   SUN");
		row=5;
        for(d=1;d<=days[m-1];d++)
		{
			gotoxy(col,row);
			printf("%d",d);
			col=col+6;
			if(col>56)
			{	
				row++;col=20;
			}
		}
		printOptions();
 		a=getch();
		switch(a)
		{
			case RIGHT:
				m++;
				if (m>12)
				{
					y++;m=1;
				}
				break;
				
			case LEFT:
    			m--;
    			if (m<0)
    			{
    				y--;m=12;
    			}
    			break;
			
    		case UP:
    			y++;
    			break;
    			
    		case DOWN:
    			y--;
    			if(y<1)
    			{
    				y=1;
			  	  printf("\a");
    			}
    			break;
    			
   			case 81:
                 exit(1);
                 
            case 113:
                 exit(2);
            
            case 82:
                 toDo();
                 break;
                 
    		default:
    			//printf("\a");
    			break;
 		}
	}
	return 0;
}


