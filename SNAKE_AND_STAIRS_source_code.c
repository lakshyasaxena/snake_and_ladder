#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
enum
  {
  black,
  dark_blue,
  dark_green,
  dark_cyan,
  dark_red,
  dark_magenta,
  dark_yellow,
  light_gray,
  dark_gray,
  light_blue,
  light_green,
  light_cyan,
  light_red,
  light_magenta,
  light_yellow,
  white
  };

int getcolors()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    &csbi
    );
  return csbi.wAttributes;
  }

int getfgcolor()
  {
  return getcolors() & 0x0F;
  }

int getbgcolor()
  {
  return getcolors() >> 4;
  }

void setfgcolor( int color )
  {
  SetConsoleTextAttribute(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    (getcolors() & 0xF0) | (color & 0x0F)
    );
  }

void setbgcolor( int color )
  {
  SetConsoleTextAttribute(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    ((color & 0x0F) << 4) | (getcolors() & 0x0F)
    );
  }

void setcolors( int fg, int bg )
  {
  SetConsoleTextAttribute(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    ((bg & 0x0F) << 4) | (fg & 0x0F)
    );
  }

void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void artificial_intelligence_moves1();
void artificial_intelligence_moves2();
void moves();
void message1( int pt1);
void message2( int pt2);

void boarder();
void chance();
void position();
void won1();
void won2();
void names();
void instruction();



int p1x=2,p1y=30,p2x=2,p2y=31,p1=0,p2=0,a=1,b=2,c=1;
int x_pos,x_des,y_pos,y_des,u,w;
char s1[20],s2[20],s3[20];
void main()
{
    srand(time(NULL));
      int initial_fg_color = getfgcolor();
      int initial_bg_color = getbgcolor();
      setfgcolor( light_yellow );
    printf("\n\n\n            WELCOME  TO  SNAKES  AND  STAIRS   GAME\n\n\n");
    setfgcolor(light_red);
    printf("#################################>>>\n\n\n");
    setfgcolor(light_cyan);
    printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
    printf("_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|\n");
    printf("\n\n\n");
    setfgcolor(white);
    system("pause");
    int ch;
    while(1)
    {
        system("cls");
        setfgcolor(light_red);
        printf("  <<-------- MENU -------->>");
        setfgcolor(white);
        printf("\n\n 1:  PLAY THE GAME      press --> 1");
        printf("\n\n 2:  EXIT               press --> 2");
        printf("\n\nENTER YOUR CHOICE --->>>      ");
        setfgcolor(white);
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                names();
                break;
            }
        case 2:
            {
                exit(1);
            }
        default:
            printf("CHOICE NOT MATCHED\n");
            getch();
            continue;
        }
        break;
    }

    while(1)
    {
        system("cls");
        boarder();
        position();
        artificial_intelligence_moves1();
        chance();
                if((c-1)%2!=0 && p1==p2)
            {
                p2=0;
                p2x=2;
                p2y=30;
                gotoxy(2,46);
               setfgcolor(light_red);
               printf("OPPS %s , %s BEATED YOU, NOW GET BACK TO START AND TAKE REVENGE",s3,s2);
               Beep(0,3000);
            }
                 if((c-1)%2==0 && p1==p2)
            {
                p1=0;
                p1x=2;
                p1y=30;
                gotoxy(2,46);
               setfgcolor(light_red);
               printf("OPPS %s , %s BEATED YOU, NOW GET BACK TO START AND TAKE REVENGE",s2,s3);
               Beep(0,3000);
            }
        position();
        artificial_intelligence_moves2();
    }
    gotoxy(3,45);
}
void boarder()
{
    int x,y,num=48;
    setfgcolor(light_magenta);
    gotoxy(4,43);
    printf("MESSAGE BOX  ");
    for(int i=1;i<=4;i++)
    {
    if(i==1)
    {
            gotoxy(0,0);
    printf("---------");
    gotoxy(0,1);
    printf("  FINISH\n");
    }
    if(i==2)
    {
        gotoxy(0,5);
        printf("---------");
    }
    if(i==3);
    {
        gotoxy(0,28);
        printf("---------");
        gotoxy(0,29);
        printf("  START\n");
    }
    if(i==4)
    {
        gotoxy(0,33);
        printf("----------");
    }
    }
    setfgcolor(white);
    for(int i=1;i<10;i++)
    {
        gotoxy(10,y);
        setfgcolor(light_cyan);
    printf("___________________________________________________________________\n");
    setfgcolor(white);
    if(i==9)
        break;
    y++;
    gotoxy(10,y);
    setfgcolor(white);
    // 1111111111111111111111111111111111111111
    if(i==1)
    {
    printf("|48        |47  <---  |46  <---  |45  <---  |44  <---  |43        |");
    }
    if(i==2)
    {
    printf("|37  --->  |38        |39  --->  |40  --->  |41        |42  --->  |");
    }
    if(i==3)
    {
    printf("|36  <---  |35  <---  |34  <---  |33        |32  <---  |31  <---  |");
    }
    if(i==4)
    {
    printf("|25  --->  |26  --->  |27        |28  --->  |29  --->  |30  --->  |");
    }
    if(i==5)
    {
    printf("|24  <---  |23        |22  <---  |21  <---  |20  <---  |19        |");
    }
    if(i==6)
    {
    printf("|13        |14  --->  |15  --->  |16  --->  |17  --->  |18        |");
    }
    if(i==7)
    {
    printf("|12        |11  <---  |10  <---  |9  <---   |8   <---  |7         |");
    }
    if(i==8)
    {
    printf("|1   --->  |2   --->  |3         |4   --->  |5   --->  |6   --->  |");
    }
    setfgcolor(light_cyan);
    y++;
    gotoxy(10,y);
    // 222222222222222222222222222222222222222222222222222222222222222
        if(i==1)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==2)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==3)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==4)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==5)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==6)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==7)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==8)
    {
    printf("|          |          |          |          |          |          |");
    }
    y++;
    gotoxy(10,y);
    // 333333333333333333333333333333333333333333333333333333333333333
        if(i==1)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==2)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==3)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==4)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==5)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==6)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==7)
    {
    printf("|          |          |          |          |          |          |");
    }
    if(i==8)
    {
    printf("|          |          |    16    |          |          |          |");
    }
    y++;
    //y=y+4;
    }
    color();
    // ////////////////////////////////////////////////////////////
    /*
    int q=34,w=78,z=0;
    for(int i=0;i<=35;i++)
    {
        gotoxy(w,i);
        printf("%d",i);
    }
    for(int i=0;i<=70;i++)
    {
        gotoxy(i,q);
        printf("%d",z);
        z++;
        if(z==10)
            z=1;
    }
    */
//  ///////////////////////////////////////////////////////////
}
void position()
{
    setfgcolor(light_blue);
    gotoxy(p1x,p1y);
    printf("a->%c",a);
    setfgcolor(light_yellow);
    gotoxy(p2x,p2y);
    printf("b->%c",b);
}
void chance()
{
    int pt1,pt2;
    gotoxy(2,36);
    setfgcolor(light_blue);
    printf("%c: %s's CURRENT POSITION IS  %d",a,s2,p1);
    gotoxy(2,38);
    setfgcolor(light_yellow);
    printf("%c: %s's CURRENT POSITION IS  %d",b,s3,p2);
    gotoxy(27,41);
    if(c%2!=0)
    {
        setfgcolor(light_blue);
        printf("%c: %s's CHANCE  --->  ",a,s2);
    }
    else
    {
        setfgcolor(light_yellow);
        printf("%c: %s's CHANCE  --->   ",b,s3);
    }
    setfgcolor(white);

       // player 1 chance

        if(c%2!=0)
        {
            while(1)
            {
            pt1=player();

            if(pt1>0 && pt1<7)
            {
                c++;
                p1=p1+pt1;
            }
            else
            {
                gotoxy(57,41);
                printf("INVALID MOVE\n");
                continue;
            }
            // player1 beat player 2
            if(p1==p2)
            {
                p2=0;
                p2x=2;
                p2y=30;
               gotoxy(2,46);
               setfgcolor(light_red);
               printf("OPPS %s , %s BEATED YOU, NOW GET BACK TO START AND TAKE REVENGE",s3,s2);
               Beep(0,3000);
            }
            // player won
            if(p1>49)
            {
                p1=p1-pt1;
                return;
            }
            // stairs
            if(p1==3)
            {
               p1x=46;
               p1y=22;
               p1=16;
               gotoxy(5,45);
               setfgcolor(light_green);
               printf("BRAVO %s , YOU GOT STAIRS, NOW JUMP TO 16",s2);
               Beep(0,2000);
               return;
            }
            if(p1==7)
            {
                p1x=57;
                p1y=2;
                p1=44;
                gotoxy(5,45);
                setfgcolor(light_green);
               printf("BRAVO %s , YOU GOT STAIRS, NOW JUMP TO 44",s2);
               Beep(0,2000);
                return;
            }
            if(p1==18)
            {
                p1x=35;
                p1y=10;
                p1=34;
                gotoxy(5,45);
                setfgcolor(light_green);
               printf("BRAVO %s , YOU GOT STAIRS, NOW JUMP TO 34",s2);
               Beep(0,2000);
                return;
            }
            if(p1==23)
            {
                p1x=46;
                p1y=6;
                p1=40;
                gotoxy(5,45);
                setfgcolor(light_green);
               printf("BRAVO %s , YOU GOT STAIRS, NOW JUMP TO 40",s2);
               Beep(0,2000);
                return;
            }
            if(p1==27)
            {
                p1x=35;
                p1y=6;
                p1=39;
                gotoxy(5,45);
                setfgcolor(light_green);
               printf("BRAVO %s , YOU GOT STAIRS, NOW JUMP TO 39",s2);
               Beep(0,2000);
                return;
            }
            //  snakes bites
            if(p1==12)
            {
                p1x=13;
                p1y=30;
                p1=1;
                gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW JUMP BACK TO 1",s2);
               Beep(0,2000);
                return;
            }
            if(p1==13)
            {
                p1x=68;
                p1y=30;
                p1=6;
                 gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW JUMP BACK TO 6",s2);
               Beep(0,2000);
                return;
            }
            if(p1==19)
            {
                p1x=24;
                p1y=26;
                p1=11;
                 gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW JUMP BACK TO 11",s2);
               Beep(0,2000);
                return;
            }
            if(p1==33)
            {
               p1x=57;
               p1y=22;
               p1=17;
                gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW JUMP BACK TO 17",s2);
               Beep(0,2000);
               return;
            }
            if(p1==38)
            {
                p1x=46;
                p1y=26;
                p1=9;
                 gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW JUMP BACK TO 9",s2);
               Beep(0,2000);
                return;
            }
            if(p1==41)
            {
                p1x=46;
                p1y=30;
                p1=4;
                 gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW JUMP BACK TO 4",s2);
               Beep(0,2000);
                return;
            }
            if(p1==43)
            {
                p1x=13;
                p1y=14;
                p1=25;
                 gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW JUMP BACK TO 25",s2);
               Beep(0,2000);
                return;
            }
            if(p1==48)
            {
                p1x=2;
                p1y=30;
                p1=0;
                 gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW GO BACK TO START",s2);
               Beep(0,2000);
                return;
            }
            switch(p1)
            {
            case 1:
                {
                    p1x=13;
                    p1y=30;
                    message1(pt1);
                    return;
                }
                 case 2:
                {
                    p1x=24;
                    p1y=30;
                    message1(pt1);
                    return;
                }
                 case 3:
                {
                    p1x=35;
                    p1y=30;
                    message1(pt1);
                    return;
                }
                 case 4:
                {
                    p1x=46;
                    p1y=30;
                    message1(pt1);
                    return;
                }
                 case 5:
                {
                    p1x=57;
                    p1y=30;
                    message1(pt1);
                    return;
                }
                 case 6:
                {
                    p1x=68;
                    p1y=30;
                    message1(pt1);
                    return;
                }
                 case 7:
                {
                    p1x=68;
                    p1y=26;
                    message1(pt1);
                    return;
                }
                 case 8:
                {
                    p1x=57;
                    p1y=26;
                    message1(pt1);
                    return;
                }
                 case 9:
                {
                    p1x=46;
                    p1y=26;
                    message1(pt1);
                    return;
                }
                 case 10:
                {
                    p1x=35;
                    p1y=26;
                    message1(pt1);
                    return;
                }
                 case 11:
                {
                    p1x=24;
                    p1y=26;
                    message1(pt1);
                    return;
                }
                 case 12:
                {
                    p1x=13;
                    p1y=26;
                    message1(pt1);
                    return;
                }
                 case 13:
                {
                    p1x=13;
                    p1y=22;
                    message1(pt1);
                    return;
                }
                 case 14:
                {
                    p1x=24;
                    p1y=22;
                    message1(pt1);
                    return;
                }
                 case 15:
                {
                    p1x=35;
                    p1y=22;
                    message1(pt1);
                    return;
                }
                 case 16:
                {
                    p1x=46;
                    p1y=22;
                    message1(pt1);
                    return;
                }
                 case 17:
                {
                    p1x=57;
                    p1y=22;
                    message1(pt1);
                    return;
                }
                 case 18:
                {
                    p1x=68;
                    p1y=22;
                    message1(pt1);
                    return;
                }
                 case 19:
                {
                    p1x=68;
                    p1y=18;
                    message1(pt1);
                    return;
                }
                 case 20:
                {
                    p1x=57;
                    p1y=18;
                    message1(pt1);
                    return;
                }
                 case 21:
                {
                    p1x=46;
                    p1y=18;
                    message1(pt1);
                    return;
                }
                 case 22:
                {
                    p1x=35;
                    p1y=18;
                    message1(pt1);
                    return;
                }
                 case 23:
                {
                    p1x=24;
                    p1y=18;
                    message1(pt1);
                    return;
                }
                 case 24:
                {
                    p1x=13;
                    p1y=18;
                    message1(pt1);
                    return;
                }
                 case 25:
                {
                    p1x=13;
                    p1y=14;
                    message1(pt1);
                    return;
                }
                 case 26:
                {
                    p1x=24;
                    p1y=14;
                    message1(pt1);
                    return;
                }
                 case 27:
                {
                    p1x=35;
                    p1y=14;
                    message1(pt1);
                    return;
                }
                 case 28:
                {
                    p1x=46;
                    p1y=14;
                    message1(pt1);
                    return;
                }
                 case 29:
                {
                    p1x=57;
                    p1y=14;
                    message1(pt1);
                    return;
                }
                 case 30:
                {
                    p1x=68;
                    p1y=14;
                    message1(pt1);
                    return;
                }
                 case 31:
                {
                    p1x=68;
                    p1y=10;
                    message1(pt1);
                    return;
                }
                 case 32:
                {
                    p1x=57;
                    p1y=10;
                    message1(pt1);
                    return;
                }
                case 33:
                {
                    p1x=46;
                    p1y=10;
                    message1(pt1);
                    return;
                }
                case 34:
                {
                    p1x=35;
                    p1y=10;
                    message1(pt1);
                    return;
                }
                case 35:
                {
                    p1x=24;
                    p1y=10;
                    message1(pt1);
                    return;
                }
                case 36:
                {
                    p1x=13;
                    p1y=10;
                    message1(pt1);
                    return;
                }
                case 37:
                {
                    p1x=13;
                    p1y=6;
                    message1(pt1);
                    return;
                }
                case 38:
                {
                    p1x=24;
                    p1y=6;
                    message1(pt1);
                    return;
                }
                case 39:
                {
                    p1x=35;
                    p1y=6;
                    message1(pt1);
                    return;
                }
                case 40:
                {
                    p1x=46;
                    p1y=6;
                    message1(pt1);
                    return;
                }
                case 41:
                {
                    p1x=57;
                    p1y=6;
                    message1(pt1);
                    return;
                }
                case 42:
                {
                    p1x=68;
                    p1y=6;
                    message1(pt1);
                    return;
                }
                case 43:
                {
                    p1x=68;
                    p1y=2;
                    message1(pt1);
                    return;
                }
                case 44:
                {
                    p1x=57;
                    p1y=2;
                    message1(pt1);
                    return;
                }
                case 45:
                {
                    p1x=46;
                    p1y=2;
                    message1(pt1);
                    return;
                }
                case 46:
                {
                    p1x=35;
                    p1y=2;
                    message1(pt1);
                    return;
                }
                case 47:
                {
                    p1x=24;
                    p1y=2;
                    message1(pt1);
                    return;
                }
                case 48:
                {
                    p1x=13;
                    p1y=2;
                    message1(pt1);
                    return;
                }
                case 49:
                    {
                        p1x=2;
                        p1y=2;
                        gotoxy(5,45);
                        printf("%s moves to finish",s2);
                        Beep(0,2000);
                        won1();
                    }

                }

            }
        }


           // ******************8player 2 chance;;;

            else
        {
            while(1)
            {
            pt2=player();
            if(pt2>0 && pt2<7)
            {
                c++;
                p2=p2+pt2;
            }
            else
            {
                gotoxy(57,41);
                printf("INVALID MOVE\n");
                continue;
            }
            //player 2 beat player 1;
            if(p2==p1)
            {
                p1=0;
                p1x=2;
                p1y=30;
                gotoxy(2,46);
               setfgcolor(light_red);
               printf("OPPS %s , %s BEATED YOU, NOW GET BACK TO START AND TAKE REVENGE",s2,s3);
               Beep(0,3000);
            }
            //   player won   ************************8
            if(p2>49)
            {
                p2=p2-pt2;
                return;
            }
            //  stairs **********************8
            if(p2==3)
            {
               p2x=46;
               p2y=23;
               p2=16;
                 gotoxy(5,45);
                setfgcolor(light_green);
               printf("BRAVO %s , YOU GOT STAIRS, NOW JUMP TO 16",s3);
               Beep(0,2000);
               return;
            }
            if(p2==7)
            {
                p2x=57;
                p2y=3;
                p2=44;
                gotoxy(5,45);
                setfgcolor(light_green);
               printf("BRAVO %s , YOU GOT STAIRS, NOW JUMP TO 44",s3);
               Beep(0,2000);
                return;
            }
            if(p2==18)
            {
                p2x=35;
                p2y=11;
                p2=34;
                gotoxy(5,45);
                setfgcolor(light_green);
               printf("BRAVO %s , YOU GOT STAIRS, NOW JUMP TO 34",s3);
               Beep(0,2000);
                return;
            }
            if(p2==23)
            {
                p2x=46;
                p2y=7;
                p2=40;
                gotoxy(5,45);
                setfgcolor(light_green);
               printf("BRAVO %s , YOU GOT STAIRS, NOW JUMP TO 40",s3);
               Beep(0,2000);
                return;
            }
            if(p2==27)
            {
                p2x=35;
                p2y=7;
                p2=39;
                gotoxy(5,45);
                setfgcolor(light_green);
               printf("BRAVO %s , YOU GOT STAIRS, NOW JUMP TO 39",s3);
               Beep(0,2000);
               return;
            }
            // **************8snake bites
            //  snakes bites
            if(p2==12)
            {
                p2x=13;
                p2y=31;
                p2=1;
                gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW GO BACK TO 1",s3);
               Beep(0,2000);
                return;
            }
            if(p2==13)
            {
                p2x=68;
                p2y=31;
                p2=6;
                gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW GO BACK TO 6",s3);
               Beep(0,2000);
                return;
            }
            if(p2==19)
            {
                p2x=24;
                p2y=27;
                p2=11;
                gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW GO BACK TO 19",s3);
               Beep(0,2000);
                return;
            }
            if(p2==33)
            {
               p2x=57;
               p2y=23;
               p2=17;
                gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW GO BACK TO 17",s3);
               Beep(0,2000);
               return;
            }
            if(p2==38)
            {
                p2x=46;
                p2y=27;
                p2=9;
                    gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW GO BACK TO 9",s3);
               Beep(0,2000);
                return;
            }
            if(p2==41)
            {
                p2x=46;
                p2y=31;
                p2=4;
                    gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW GO BACK TO 4",s3);
               Beep(0,2000);
                return;
            }
            if(p2==43)
            {
                p2x=13;
                p2y=14;
                p2=26;
                    gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW GO BACK TO 26",s3);
               Beep(0,2000);
                return;
            }
            if(p2==48)
            {
                p2x=2;
                p2y=31;
                p2=0;
                    gotoxy(5,45);
               setfgcolor(light_red);
               printf("OPPS %s , SNAKE BITE YOU, NOW GO BACK TO START",s3);
               Beep(0,2000);
                return;
            }
            switch(p2)
            {
            case 1:
                {
                    p2x=13;
                    p2y=31;
                    message2(pt2);
                    return;
                }
                 case 2:
                {
                    p2x=24;
                    p2y=31;
                    message2(pt2);
                    return;
                }
                 case 3:
                {
                    p2x=35;
                    p2y=31;
                    message2(pt2);
                    return;
                }
                 case 4:
                {
                    p2x=46;
                    p2y=31;
                    message2(pt2);
                    return;
                }
                 case 5:
                {
                    p2x=57;
                    p2y=31;
                    message2(pt2);
                    return;
                }
                 case 6:
                {
                    p2x=68;
                    p2y=31;
                    message2(pt2);
                    return;
                }
                 case 7:
                {
                    p2x=68;
                    p2y=27;
                    message2(pt2);
                    return;
                }
                 case 8:
                {
                    p2x=57;
                    p2y=27;
                    message2(pt2);
                    return;
                }
                 case 9:
                {
                    p2x=46;
                    p2y=27;
                    message2(pt2);
                    return;
                }
                 case 10:
                {
                    p2x=35;
                    p2y=27;
                    message2(pt2);
                    return;
                }
                 case 11:
                {
                    p2x=24;
                    p2y=27;
                    message2(pt2);
                    return;
                }
                 case 12:
                {
                    p2x=13;
                    p2y=27;
                    message2(pt2);
                    return;
                }
                 case 13:
                {
                    p2x=13;
                    p2y=23;
                    message2(pt2);
                    return;
                }
                 case 14:
                {
                    p2x=24;
                    p2y=23;
                    message2(pt2);
                    return;
                }
                 case 15:
                {
                    p2x=35;
                    p2y=23;
                    message2(pt2);
                    return;
                }
                 case 16:
                {
                    p2x=46;
                    p2y=23;
                    message2(pt2);
                    return;
                }
                 case 17:
                {
                    p2x=57;
                    p2y=23;
                    message2(pt2);
                    return;
                }
                 case 18:
                {
                    p2x=68;
                    p2y=23;
                    message2(pt2);
                    return;
                }
                 case 19:
                {
                    p2x=68;
                    p2y=19;
                    message2(pt2);
                    return;
                }
                 case 20:
                {
                    p2x=57;
                    p2y=19;
                    message2(pt2);
                    return;
                }
                 case 21:
                {
                    p2x=46;
                    p2y=19;
                    message2(pt2);
                    return;
                }
                 case 22:
                {
                    p2x=35;
                    p2y=19;
                    message2(pt2);
                    return;
                }
                 case 23:
                {
                    p2x=24;
                    p2y=19;
                    message2(pt2);
                    return;
                }
                 case 24:
                {
                    p2x=13;
                    p2y=19;
                    message2(pt2);
                    return;
                }
                 case 25:
                {
                    p2x=13;
                    p2y=15;
                    message2(pt2);
                    return;
                }
                 case 26:
                {
                    p2x=24;
                    p2y=15;
                    message2(pt2);
                    return;
                }
                 case 27:
                {
                    p2x=35;
                    p2y=15;
                    message2(pt2);
                    return;
                }
                 case 28:
                {
                    p2x=46;
                    p2y=15;
                    message2(pt2);
                    return;
                }
                 case 29:
                {
                    p2x=57;
                    p2y=15;
                    message2(pt2);
                    return;
                }
                 case 30:
                {
                    p2x=68;
                    p2y=15;
                    message2(pt2);
                    return;
                }
                 case 31:
                {
                    p2x=68;
                    p2y=11;
                    message2(pt2);
                    return;
                }
                 case 32:
                {
                    p2x=57;
                    p2y=11;
                    message2(pt2);
                    return;
                }
                case 33:
                {
                    p2x=46;
                    p2y=10;
                    message2(pt2);
                    return;
                }
                case 34:
                {
                    p2x=35;
                    p2y=11;
                    message2(pt2);
                    return;
                }
                case 35:
                {
                    p2x=24;
                    p2y=11;
                    message2(pt2);
                    return;
                }
                case 36:
                {
                    p2x=13;
                    p2y=11;
                    message2(pt2);
                    return;
                }
                case 37:
                {
                    p2x=13;
                    p2y=7;
                    message2(pt2);
                    return;
                }
                case 38:
                {
                    p2x=24;
                    p2y=7;
                    message2(pt2);
                    return;
                }
                case 39:
                {
                    p2x=35;
                    p2y=7;
                    message2(pt2);
                    return;
                }
                case 40:
                {
                    p2x=46;
                    p2y=7;
                    message2(pt2);
                    return;
                }
                case 41:
                {
                    p2x=57;
                    p2y=7;
                    message2(pt2);
                    return;
                }
                case 42:
                {
                    p2x=68;
                    p2y=7;
                    message2(pt2);
                    return;
                }
                case 43:
                {
                    p2x=68;
                    p2y=3;
                    message2(pt2);
                    return;
                }
                case 44:
                {
                    p2x=57;
                    p2y=3;
                    message2(pt2);
                    return;
                }
                case 45:
                {
                    p2x=46;
                    p2y=3;
                    message2(pt2);
                    return;
                }
                case 46:
                {
                    p2x=35;
                    p2y=3;
                    message2(pt2);
                    return;
                }
                case 47:
                {
                    p2x=24;
                    p2y=3;
                    message2(pt2);
                    return;
                }
                case 48:
                {
                    p2x=13;
                    p2y=3;
                    message2(pt2);
                    return;
                }
                case 49:
                    {
                        p2x=2;
                        p2y=3;
                        gotoxy(5,45);
                        printf("%s moves to finish",s2);
                        Beep(0,2000);
                        won2();
                    }
                }

            }
        }
}
void won1()
{
    artificial_intelligence_moves2();
    system("cls");
    setfgcolor(light_blue);
    printf("\n\n\n%c: %s  WON THE GAME\n",a,s2);
    p2=p1=0;
    p1x=p2x=2;
    p1y=30;
    p2y=31;
    c=1;
    system("pause");
    system("cls");
    main();
}
void won2()
{
    artificial_intelligence_moves2();
    system("cls");
    setfgcolor(light_yellow);
    printf("\n\n\n%c: %s WON THE GAME\n",b,s3);
    p1=p2=0;
    p1x=p2x=2;
    p1y=30;
    p2y=31;
    c=1;
    system("pause");
    system("cls");
    main();
}
void names()
{
    system("cls");
    gets(s1);
    printf("\n\nPLEASE ENTER PLAYER 1 NAME->  ");
    setfgcolor(light_blue);
    gets(s2);
    setfgcolor(white);
    printf("\n\nPLEASE ENTER PLAYER 2 NAME->  ");
    setfgcolor(light_yellow);
    gets(s3);
    setfgcolor(white);
    printf("\n\nWOULD YOU LIKE TO KNOW THE INSTRUCTION BEFORE PLAYING\n");
    printf("\nYES  :  press--> 1");
    printf("\nNO   :  press--> 2");
    int ch;
    printf("\nENTER YOUR CHOICE HERE--->   ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        {
            instruction();
            break;
        }
    case 2:
        {
            break;
        }
    default:
        printf("INVALID CHOICE\n");
    }
    setfgcolor(light_cyan);
    printf("\n\n\n                 PRESS ENTER TO START THE GAME\n");
    getch();
}
void instruction()
{
    system("cls");
    printf("SAP SIRDI HI TO HE\nKHEL LO AB\n");
    printf("PRESS ENTER\n");
    getch();
}
int player()
{
    int num;
    gotoxy(57,35);
    printf("ROLL THE DICE\n");
    gotoxy(60,37);
    //scanf("%d",&num);
    num=rand()%6+1;         //    random number
    if(num<1  ||  num >6)
    {
        return;
    }
    gotoxy(60,37);
    setfgcolor(light_magenta);
    for(int i=1;i<=3;i++)
    {

        gotoxy(60,37);
        Beep(0,50);
        gotoxy(61,38);
        printf("*");
        Beep(0,50);
        gotoxy(60,37);  //fade
        printf(" ");
        gotoxy(62,39);
        printf("*");
        Beep(0,50);
         gotoxy(61,38);  //fade
        printf(" ");
        gotoxy(61,40);
        printf("*");
        Beep(0,50);
         gotoxy(62,39);  //fade
        printf(" ");
        gotoxy(60,41);
        printf("*");
        Beep(0,50);
         gotoxy(61,40);   // fade
        printf(" ");
        gotoxy(59,40);
        printf("*");
        Beep(0,50);
        gotoxy(60,41);  //fade
        printf(" ");
        gotoxy(58,39);
        printf("*");
        Beep(0,50);
        gotoxy(59,40);  // fade
        printf(" ");
        gotoxy(59,38);
        printf("*");
        Beep(0,50);
        gotoxy(58,39);
        printf(" ");
        gotoxy(59,38); // fade
        printf(" ");
    }
    gotoxy(61,39);
    printf("%d",num);
    gotoxy(58,41);
    setfgcolor(white);
    printf("YOU GOT %d",num);
    Beep(0,700);
    return num;
}
color()
{
    setfgcolor(light_red);
    gotoxy(14,1);    // 1  sn
    printf("SNAKE");
    gotoxy(12,2);
    printf("move to");
    gotoxy(13,3);
    printf("start");

        gotoxy(14,21);    // 2 sn
    printf("SNAKE");
    gotoxy(12,22);
    printf("move to");
    gotoxy(13,23);
    printf("   6");

        gotoxy(14,25);    // 3 sn
    printf("SNAKE");
    gotoxy(12,26);
    printf("move to");
    gotoxy(13,27);
    printf("   1");


            gotoxy(25,5);    // 4 sn
    printf("SNAKE");
    gotoxy(23,6);
    printf("move to");
    gotoxy(23,7);
    printf("   9");

            gotoxy(25,17);    // 1 st
    setfgcolor(light_green);
    printf("STAIRS");
    gotoxy(23,18);
    printf("jump to");
    gotoxy(25,19);
    printf("  40");

    gotoxy(36,13);
      printf("STAIRS");  // 2st
    gotoxy(34,14);
    printf("jump to");
    gotoxy(36,15);
    printf("  39");

    gotoxy(36,29);
      printf("STAIRS");  //  3 st
    gotoxy(34,30);
    printf("jump to");
    gotoxy(36,31);
    printf("  16");
    setfgcolor(light_red);

       gotoxy(47,9);  // 5 sn
    printf("SNAKE");
    gotoxy(44,10);
    printf(" move to");
    gotoxy(47,11);
    printf(" 17");

       gotoxy(58,5);  // 5 sn
    printf("SNAKE");
    gotoxy(56,6);
    printf(" move to");
    gotoxy(57,7);
    printf("  4 ");



    gotoxy(69,1);  // 5 sn
    printf("SNAKE");
    gotoxy(67,2);
    printf(" move to");
    gotoxy(69,3);
    printf("  25");

            gotoxy(69,17);  // 3
    printf("SNAKE");
    gotoxy(67,18);
    printf(" move to");
    gotoxy(69,19);
    printf("  11");
    setfgcolor(light_green);

            gotoxy(69,21);
    printf("STAIRS");
    gotoxy(67,22);
    printf(" jump to");
    gotoxy(69,23);
    printf("  34");

            gotoxy(69,25);
    printf("STAIRS");
    gotoxy(67,26);
    printf(" jump to");
    gotoxy(69,27);
    printf("  44");

    setfgcolor(white);
}

void artificial_intelligence_moves1()
{
    if(c%2!=0 )
    {
    x_pos=p1x;
    y_pos=p1y;
    }
    if(c%2==0)
    {
        x_pos=p2x;
        y_pos=p2y;
    }
}
void artificial_intelligence_moves2()
{
    if( (c+1)%2!=0 )
    {
    x_des=p1x;
    y_des=p1y;
    setfgcolor(light_blue);
    move_body();
    }
    if(  (c+1) %2 == 0 )
    {
        x_des=p2x;
        y_des=p2y;
        move_body();
    }
}
void move_body()
{
    if( (c+1)%2!=0 )
    {
     if(y_pos<y_des)        // to move down
    {
        for(int i=y_pos;i<=y_des;i++)
        {
            gotoxy(x_pos,i);
            setfgcolor(light_blue);
            printf("a->%c",a);
            Beep(0,50);
            system("cls");
            boarder();
        }
        y_pos=y_des;
    }
     if(x_pos>x_des)                  // to move left
    {
        for(int i=x_pos;i>=x_des;i--)
        {
            gotoxy(i,y_pos);
            setfgcolor(light_blue);
            printf("a->%c",a);
            Beep(0,50);
            system("cls");
            boarder();
        }
        x_pos=x_des;
    }
     if(x_pos<x_des)                  // to move right
    {
        for(int i=x_pos;i<=x_des;i++)
        {
            gotoxy(i,y_pos);
            setfgcolor(light_blue);
            printf("a->%c",a);
            Beep(0,50);
            system("cls");
            boarder();
        }
        x_pos=x_des;
    }
     if(y_pos>y_des)        // to move up
    {
        for(int i=y_pos;i>=y_des;i--)
        {
            gotoxy(x_pos,i);
            setfgcolor(light_blue);
            printf("a->%c",a);
            Beep(0,50);
            system("cls");
            boarder();
        }
        y_pos=y_des;
    }
    }
    else

    {
         if(y_pos<y_des)        // to move down
    {
        for(int i=y_pos;i<=y_des;i++)
        {
            gotoxy(x_pos,i);
            setfgcolor(light_yellow);
            printf("a->%c",a);
            Beep(0,50);
            system("cls");
            boarder();
        }
        y_pos=y_des;
    }
     if(x_pos>x_des)                  // to move left
    {
        for(int i=x_pos;i>=x_des;i--)
        {
            gotoxy(i,y_pos);
            setfgcolor(light_yellow);
            printf("a->%c",a);
            Beep(0,50);
            system("cls");
            boarder();
        }
        x_pos=x_des;
    }
     if(x_pos<x_des)                  // to move right
    {
        for(int i=x_pos;i<=x_des;i++)
        {
            gotoxy(i,y_pos);
            setfgcolor(light_yellow);
            printf("a->%c",a);
            Beep(0,50);
            system("cls");
            boarder();
        }
        x_pos=x_des;
    }
     if(y_pos>y_des)        // to move up
    {
        for(int i=y_pos;i>=y_des;i--)
        {
            gotoxy(x_pos,i);
            setfgcolor(light_yellow);
            printf("a->%c",a);
            Beep(0,50);
            system("cls");
            boarder();
        }
        y_pos=y_des;
    }
    }
}

void message1( int pt1)
{
        gotoxy(5,45);
        printf(" %s MOVES %d BLOCKS AHEAD ",s2,pt1);
        Beep(0,2000);
}

void message2( int pt2)
{
        gotoxy(5,45);
        printf(" %s MOVES %d BLOCKS AHEAD ",s3,pt2);
        Beep(0,2000);
}
