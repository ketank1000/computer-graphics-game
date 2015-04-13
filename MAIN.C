#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include"proj.h"
#define ESC 27
#define ENTER 13
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define w 119
#define a 97
#define s 115
#define d 100
#define e 101
#define l 108



void mainmenu();
void help();
void about();
void load();
void level1();
void level2();
void bricks(int,int,int,int);
void gbricks(int,int,int,int);
void grass(int,int,int);
void water(int,int,int);
void movment(int,int,int,int,int);
int check_pixel(int,int,int,int,char);
int check_ground(int,int,int,int);
void o_door(int,int,int,int);
void flash(int,int,int,int);
void flashe(int,int,int,int);
int waterl_1(int ,int ,int ,int ,int);

void gameover();
void levelcomplete();
void youwin();

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");


	outtextxy(150,250,"Press Any Key To Continue........");
	getch();
	mainmenu();

	getch();
	closegraph();
}
///////////////////////////



////////////////////////////
void level2()
{
	int i,j;
	setfillstyle(9,6);

	bricks(0,440,640,479);
	bricks(0,20,640,59);
	bricks(0,60,20,439);
	bricks(600,60,640,439);

	bricks(240,60,260,279);

	gbricks(40,120,159,159);
	gbricks(120,240,239,279);
	gbricks(40,340,79,379);
	gbricks(260,360,299,439);
	gbricks(220,400,259,439);
	gbricks(300,400,379,439);

	water(380,400,519);

	gbricks(520,400,599,439);
	gbricks(420,380,459,399);
	gbricks(560,250,599,299);
	gbricks(520,310,559,319);

	gbricks(280,200,359,239);

	gbricks(480,120,599,139);
	gbricks(440,140,480,159);
    //	gbricks(360,160,399,179);
  //	gbricks(280,160,319,179);

  //	gbricks(380,140,419,159);

	gbricks(420,260,459,279);

	o_door(550,60,600,120);
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	bar3d(320,40,560,60,0,0);
	o_door(550,60,600,120);
}
///////////////////////////



////////////////////////////
void bricks(int x1,int y1,int x2,int y2)
{
	int i,j;
	for(i=y1;i<=y2;i+=20)
	{
		for(j=x1;j<=x2;j=j+40)
		{
			setfillstyle(9,6);
			setcolor(BLACK);
			bar3d(j,i,j+40,i+20,0,0);
			setfillstyle(1,6);
			bar3d(j+3,i+3,j+40-3,i+20-3,0,0);
			setcolor(YELLOW);
			line(j+2,i+2,j+2,i+20-2);
			line(j+2,i+2,j+40-2,i+2);
		}
	}

}
///////////////////////



////////////////////////
void gbricks(int x1,int y1,int x2,int y2)
{
	int i,j;
	for(i=y1;i<=y2;i+=20)
	{
		for(j=x1;j<=x2;j=j+40)
		{
			setfillstyle(9,6);
			setcolor(BLACK);
			bar3d(j,i,j+40,i+20,0,0);
			setfillstyle(1,6);
			bar3d(j+3,i+3,j+40-3,i+20-3,0,0);
			setcolor(YELLOW);
			line(j+2,i+2,j+2,i+20-2);
			line(j+2,i+2,j+40-2,i+2);
		}
	}
	grass(x1+4,y1+7,x2);
}
////////////////////////



/////////////////////////
void grass(int x1,int y1,int x2)
{
	int i,sta,enda,temp;
	setfillstyle(1,2);
	sta=180;
	enda=0;
	setcolor(WHITE);
	for(i=x1;i<x2;i=i+8)
	{
		arc(i,y1,sta,enda,4);
		temp=sta;
		sta=enda;
		enda=temp;
	}

	line(x1-4,y1,x1-4,y1-7);
	line(x2+1,y1,x2+1,y1-7);
	line(x1-4,y1-7,x2+1,y1-7);
	floodfill(x1,y1,WHITE);
}
////////////////////



///////////////////////
void water(int x1,int y1,int x2)
{
	int i;
	setcolor(WHITE);
	setfillstyle(1,9);
	for(i=x1+4;i<=x2;)
	{
		arc(i,y1+5,180,0,4);
		i=i+7;
		arc(i,y1+5,180,0,3);
		i=i+7;
	}

	setcolor(WHITE);
	line(x1,y1,x1,y1+40);
	line(x2,y1,x2,y1+40);
	line(x1,y1+40,x2,y1+40);
	floodfill(x1+20,y1+20,WHITE);


}
////////////////////////



///////////////////////
void movment(int x1,int y1,int x2,int y2,int lev)
{

int i=0,u,p_color,ch,wa,life;
int tx1,tx2,ty1,ty2;
char c,x,t;
tx1=x1;
tx2=x2;
ty1=y1;
ty2=y2;

life=0;

do
	{
	wa=0;
	flash(x1,y1,x2,y2);
	flushall();
	c=getche();

	switch(c)
		{
		case RIGHT:
			y2=check_ground(x1,y1,x2,y2);
			y1=y2-50;
			p_color=check_pixel(x1,y1,x2,y2,'r');

			if(p_color==0)
			{
				setcolor(BLACK);
				flashe(x1,y1,x2,y2);
				setcolor(WHITE);
				flash(x1+=2,y1,x2+=2,y2);
			}
			wa=waterl_1(x1,y1,x2,y2,lev);
			break;


		case LEFT:
			y2=check_ground(x1,y1,x2,y2);
			y1=y2-50;
			p_color=check_pixel(x1,y1,x2,y2,'l');

		       if(p_color==0)
		       {
				setcolor(BLACK);
				flashe(x1,y1,x2,y2);
				setcolor(WHITE);
				flash(x1-=2,y1,x2-=2,y2);
		       }
		       wa=waterl_1(x1,y1,x2,y2,lev);
		       break;

	       case 'c':
			y2=check_ground(x1,y1,x2,y2);
			y1=y2-50;

		      p_color=check_pixel(x1,y1,x2,y2,'u');
		      p_color=+check_pixel(x1,y1,x2,y2,'r');
		      p_color=+check_pixel(x1,y1,x2,y2,'l');
		     // p_color=+check_pixel(x1,y1,x2,y2,'d');


		      if(p_color==0)
		      {
				for(i=0;i<50&&p_color==0;i++)
				 {
					p_color=0;
					p_color=check_pixel(x1,y1,x2,y2,'u');
					 p_color=+check_pixel(x1,y1,x2,y2,'r');
					 setcolor(BLACK);
					 if(p_color==0)
					 {


					 flashe(x1,y1,x2,y2);

					 setcolor(WHITE);

					 p_color=check_pixel(x1,y1,x2,y2,'u');
					 p_color=+check_pixel(x1,y1,x2,y2,'r');
					// p_color=check_pixel(x1,y1,x2,y2,'p');
					 }
					 if(p_color==0)
					 {
						 flash(x1+=1,y1-=2,x2+=1,y2-=2);
						 delay(5);
					 }
					 else
					 {
					     y2=check_ground(x1,y1,x2,y2);
					     y1=y2-50;
					     flash(x1,y1,x2,y2);
					 }
				 }


				 for(i=50;i>2&&p_color==0;i--)
				 {
					 p_color=0;
					 setcolor(BLACK);
					 flashe(x1,y1,x2,y2);
					 p_color=check_pixel(x1,y1,x2,y2,'d');
					 if(p_color==0)
					  {
						 p_color=check_pixel(x1+1,y1+2,x2+1,y2+2,'d');
						 p_color=check_pixel(x1+1,y1+2,x2+1,y2+2,'r');
						 setcolor(WHITE);

						 flash(x1+=1,y1+=2,x2+=1,y2+=2);
						 p_color=check_pixel(x1,y1,x2,y2,'d');
						 p_color=check_pixel(x1,y1,x2,y2,'r');
						delay(5);
					  }
				 }

			p_color=0;
			p_color=check_pixel(x1,y1,x2,y2,'d');
		   //	p_color=check_pixel(x1,y1,x2,y2,'r');

			if(p_color==0)
			{
			     y2=check_ground(x1,y1,x2,y2);
			     y1=y2-50;
			     flash(x1,y1,x2,y2);
			}
		      }
		      wa=waterl_1(x1,y1,x2,y2,lev);
			 break;

		  case 'z':

		  y2=check_ground(x1,y1,x2,y2);
		  y1=y2-50;

		  p_color=check_pixel(x1,y1,x2,y2,'u');
		  p_color=+check_pixel(x1,y1,x2,y2,'l');
		  p_color=+check_pixel(x1,y1,x2,y2,'d');
		  p_color=+check_pixel(x1,y1,x2,y2,'r');

		  if(p_color==0)
		  {
		  for(i=0;i<50&&p_color==0;i++)
			 {
			 p_color=0;
			 setcolor(BLACK);
		     //	 flashe(x1,y1,x2,y2);
			 p_color=check_pixel(x1,y1,x2,y2,'u');
			  p_color=+check_pixel(x1,y1,x2,y2,'l');

			 if(p_color==0)
			  flashe(x1,y1,x2,y2);

			 if(p_color==0)
			 {
				 setcolor(WHITE);
				 p_color=check_pixel(x1,y1,x2,y2,'u');
				  p_color=+check_pixel(x1,y1,x2,y2,'l');

				 if(p_color==0)
				 {
				 flash(x1-=1,y1-=2,x2-=1,y2-=2);
				 delay(5);
				 }
			 }
			 else
			 {
				     y2=check_ground(x1,y1,x2,y2);
				     y1=y2-50;
				     flash(x1,y1,x2,y2);
			  }
			 }

			 for(i=50;i>0&&p_color==0;i--)
			 {
			 setcolor(BLACK);
			 p_color=check_pixel(x1,y1,x2,y2,'d');
			  //p_color=check_pixel(x1,y1,x2,y2,'l');

			 if(p_color==0)
			 {
				flashe(x1,y1,x2,y2);

				 setcolor(WHITE);
				  p_color=check_pixel(x1-1,y1+2,x2-1,y2+2,'d');
				  p_color=check_pixel(x1-1,y1+2,x2-1,y2+2,'l');

				 if(p_color==0)
				 {
					 flash(x1-=1,y1+=2,x2-=1,y2+=2);
					 delay(5);
				 }
			  }
			 }


		  p_color=check_pixel(x1,y1,x2,y2,'d');
		  p_color=check_pixel(x1,y1,x2,y2,'l');

		  if(p_color==0)
		  {
			 y2=check_ground(x1,y1,x2,y2);
			y1=y2-50;
			flash(x1,y1,x2,y2);
		  }

		  }
		  wa=waterl_1(x1,y1,x2,y2,lev);
			 break;

		  case ESC:mainmenu();
			   break;
		 }

		 if(wa==1)
		 {
			life++;
			cleardevice();
			if(lev==1)
				level1();
			if(lev==2)
				level2();
		       //	flashe(x1,y1,x2,y2);
			x1=tx1;
			x2=tx2;
			y2=ty2;
			y1=ty1;
		 }

	}while(x2<545 && life<2 );

	if(life==2)
	{
		gameover();
		delay(1000);
		getch();
		mainmenu();
	}
	else
	{

		levelcomplete();
		delay(1000);
		getch();
	}
}
///////////////////////////





////////////////////////////
int check_pixel(int x1,int y1,int x2,int y2,char c)
{

int cx1,cx2,cy1,cy2,i;
int flag=0;

x1-=5;
x2+=6;
//y1+=1;
//y2+=1;

if(c=='r')
{
	x2++;
	for(i=y1;i<=y2;i++)
	{
		if(getpixel(x2,i)!=BLACK)
		{
			flag=1;
			break;
		}
	}
}

if(c=='l')
{
	x1--;
	for(i=y1;i<=y2;i++)
	{
		if(getpixel(x1,i)!=BLACK)
		{
			flag=1;
			break;
		}
	}
}

if(c=='u')
{
	y1=-8;

	for(i=x1;i<=x2;i++)
	{
		if(getpixel(i,y1-2)!=BLACK)
		{
			flag=1;
			break;
		}
	}
}


if(c=='d')
{
	y2++;
	y2++;
	for(i=x1;i<=x2;i++)
	{
		if(getpixel(i,y2+2)!=BLACK)
		{
			flag=1;
			break;
		}
	}
}


if(c=='p')
{
	y2++;
	for(i=x1;i<=x2;i++)
	{
		if(getpixel(i,y2+2)!=BLACK)
		{
			flag=1;
			break;
		}
	}
}

flushall();

if(flag==1)
	return 1;
else
	return 0;
}
/////////////////////////




/////////////////////////
int check_ground(int x1,int y1,int x2,int y2)
{
int i,flag;


do
{
	y2++;
	flag=0;
	for(i=x1;i<=x2;i++)
	{
		if(getpixel(i,y2+2)!=BLACK)
		{
			flag=1;
			break;
		}
	}
	y2--;
	if(flag==0)
	{
		setcolor(BLACK);
		flashe(x1,y1,x2,y2);
		setcolor(WHITE);
		flash(x1,y1+=1,x2,y2+=1);
		delay(1);
	}

	flushall();
}while(flag==0 && !kbhit());

return y2;
}
///////////////////////




/////////////////////////
void brickl1(int x1, int y1, int x2, int y2)
{
 setfillstyle(1,4);
 setcolor(BLACK);

	bar3d(x1,y1,x2,y2,0,0);


	line(x1+25,y1,x2-25,y2-40);
	line(x1,y1+10,x2,y2-40);
	line(x1,y1+20,x2,y2-30);

	line(x1+25,y1+20,x2-25,y2-20);
	line(x1,y1+30,x2,y2-20) ;
	line(x1,y1+40,x2+50,y2-10);

	line(x1+25,y1+40,x2-25,y2);
}
/////////////////////////////



/////////////////////////////
void level1()
{
 int i,j;
 //Base
 for(i=0;i<1000;i+=50)
 {
	setcolor(BLACK);
	brickl1(0+i,440,50+i,490);
 }

 //left Wall
 for(i=0;i<450;i+=50)
 {
	setcolor(BLACK);
	brickl1(-10,0+i,40,50+i);
 }


 //top
 for(i=0;i<1000;i+=50)
 {
	setcolor(BLACK);
	brickl1(0+i,-20,50+i,30);


 }




 //Right Wall
 for(i=0;i<450;i+=50)
{
	setcolor(BLACK);
	brickl1(600,0+i,650,50+i);
}




// Water
/*  setcolor(WHITE);
  setfillstyle(1,9);
  for(i=202;i<=323;)
  {
	 arc(i,435,180,0,4);
	 i=i+7;
	 arc(i,435,180,0,3);
	 i=i+7;
  }


 line(200,438,323,438);
 line(200,438,200,480);
 line(323,480,323,438);
 floodfill(220,445,WHITE);  */


 setfillstyle(1,BLACK);
 bar3d(200,430,325,480,0,0);
 water(200,440,325);


 //Lt
 for(i=0;i<100;i+=50)
	brickl1(10+i,230,60+i,280);



 //Lb
 brickl1(115,370,165,420);
 brickl1(180,320,230,370);
 brickl1(290,320,340,370);



 //Mm
 for(i=0;i<150;i+=50)
	brickl1(360+i,240,410+i,290);
 brickl1(460,190,510,240);

 //Ltm
 for(i=0;i<100;i+=50)
	brickl1(150+i,110,200+i,160);


 for(i=0;i<100;i+=50)
	brickl1(300+i,110,350+i,160);

 brickl1(550,110,600,160);

 setcolor(WHITE);

 o_door(550,50,600,110);

}
///////////////////////



////////////////////////
void o_door(int x1,int y1,int x2,int y2)
{
	int t1,t2,t3,t4,i;
	setcolor(WHITE);
	rectangle(x1,y1,x2,y2);

	setfillstyle(0,BLACK);

	t1=x1;
	t2=y2-10;
	t3=x2;
	t4=y2;
	for(i=0;t2>y1;i++)
	{
		rectangle(t1,t2,t3,t4);
//		floodfill(t1+2,t2+2,1);
		line(t1,t2,t1+10,t2-5);
		t1=t1+10;
		t2=t2-15;
		t4=t2+10;
	}
}
//////////////////////////////



////////////////////////////
void mainmenu()
{
 int i=0,k;
 char j,x;

 do
 {
	j=getche();
	cleardevice();
	setcolor(RED);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
	outtextxy(80,50,"FLASH");
	dda(80,150,350,150);
	bresen(80,145,350,145);
	flash(170,280,185,330);

	for(k=0;k<5;k++)
		dcircle(177,305,70+k,YELLOW);


	switch(j)
	{
		case UP:if(i>0)
				i--;
			else
				i=3;
			break;

		case DOWN:if(i<3)
				i++;
			  else
				i=0;
			  break;
	}


	if(i==0)
	{
		setcolor(BLACK);
		settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
		outtextxy(400,200,"New Game");


		setcolor(RED);

		settextstyle(GOTHIC_FONT,HORIZ_DIR,7);
		outtextxy(350,180,"New Game");

		setcolor(GREEN);

		settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
		outtextxy(450,250,"Help");
		outtextxy(450,300,"About");
		outtextxy(400,350,"Exit");
	}

	if(i==1)
	{

		setcolor(BLACK);
		settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
		outtextxy(450,250,"Help");


		setcolor(GREEN);

		settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
		outtextxy(370,200,"New Game");

		setcolor(RED);

		settextstyle(GOTHIC_FONT,HORIZ_DIR,7);
		outtextxy(450,232,"Help");

		setcolor(GREEN);

		settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
		outtextxy(450,300,"About");
		outtextxy(400,350,"Exit");
	}

	if(i==2)
	{
		setcolor(BLACK);
		settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
		outtextxy(450,300,"About");

		setcolor(GREEN);

		settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
		outtextxy(400,200,"New Game");
		outtextxy(450,250,"Help");

		setcolor(RED);

		settextstyle(GOTHIC_FONT,HORIZ_DIR,7);
		outtextxy(450,282,"About");

		setcolor(GREEN);

		settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
		outtextxy(400,350,"Exit");
	}

	if(i==3)
	{
		setcolor(BLACK);
		settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
		outtextxy(400,350,"Exit");

		setcolor(GREEN);

		settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
		outtextxy(400,200,"New Game");
		outtextxy(450,250,"Help");
		outtextxy(450,300,"About");

		setcolor(RED);

		settextstyle(GOTHIC_FONT,HORIZ_DIR,7);
		outtextxy(400,350,"Exit");
	}

 }while(j!=ENTER);


 switch(i)
 {
	case 0:load();
	       break;

	case 1:help();
	       break;

	case 2:about();
	       break;

	case 3:exit(1);
	       break;
 }
}
///////////////////////////////////



//////////////////////////////////
void help()
{
 cleardevice();
 setcolor(GREEN);
 settextstyle(GOTHIC_FONT,HORIZ_DIR,7);
 outtextxy(250,50,"HELP");


 setcolor(RED);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
 outtextxy(150,120,"This is the help for the game FLASH");

 setcolor(GREEN);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
 outtextxy(50,180,"OBJECTIVE:");

 setcolor(RED);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
 outtextxy(80,220,"Help Flash to escape from the villan's citadel");
 outtextxy(50,260,"by controlling him through the obstacles.");


 setcolor(GREEN);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
 outtextxy(50,300,"CONTROLS:");

 setcolor(RED);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
 outtextxy(50,340,"Move Left: <- (Left arrow key).");
 outtextxy(50,370,"Move Right: ->(Right arrew key).");
 outtextxy(50,400,"Jump Left: 'Z' Key.");
 outtextxy(50,430,"Jump right: 'C' key.");
 getch();

 mainmenu();
}
//////////////////////////////////////



/////////////////////////////////////
void about()
{
 cleardevice();
 setcolor(GREEN);
 settextstyle(GOTHIC_FONT,HORIZ_DIR,7);
 outtextxy(250,50,"ABOUT");


 setcolor(GREEN);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
 outtextxy(50,180,"Project by:");


 setcolor(RED);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
 outtextxy(50,220,"1. Alok Karnik (2354)");
 outtextxy(50,260,"2. Ketan Khandagale (2356)");
 outtextxy(50,300,"3. Shashwat Kulkarni (2361)");


 setcolor(GREEN);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
 outtextxy(50,350,"Project Guide:");

 setcolor(RED);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
 outtextxy(50,400,"Prof. Y.K. Sharma");
 getch();
 mainmenu();
}
/////////////////////////////////////



////////////////////////////////////
void load()
{
 int i;

 cleardevice();
 setcolor(YELLOW);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
 outtextxy(225,350,"Loading...");
 do
 {
	for(i=0;i<=330;i++)
	{
		setcolor(RED);
		arc(300,250,0+i,30+i,100);
		setcolor(GREEN);
		arc(300,250,330-i,360-i,80);
		setcolor(BLUE);
		arc(300,250,60+i,90+i,60);
		delay(2);
	}

	for(i=0;i<=330;i++)
	{
		setcolor(BLACK);
		arc(300,250,0+i,30+i,100);
		setcolor(BLACK);
		arc(300,250,330-i,360-i,80);
		setcolor(BLACK);
		arc(300,250,60+i,90+i,60);
		delay(2);
	}

	for(i=0;i<=330;i++)
	{
		setcolor(RED);
		arc(300,250,0+i,30+i,100);
		setcolor(GREEN);
		arc(300,250,330-i,360-i,80);
		setcolor(BLUE);
		arc(300,250,60+i,90+i,60);
		delay(2);
	}

	delay(500);

 }while(i<0);

 cleardevice();
 level1();
 movment(100,100,115,150,1);
 //levelcomplete();
 cleardevice();
 setcolor(YELLOW);
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
 outtextxy(225,350,"Loading...");
 do
 {
	for(i=0;i<=330;i++)
	{
		setcolor(RED);
		arc(300,250,0+i,30+i,100);
		setcolor(GREEN);
		arc(300,250,330-i,360-i,80);
		setcolor(BLUE);
		arc(300,250,60+i,90+i,60);
		delay(2);
	}

	for(i=0;i<=330;i++)
	{
		setcolor(BLACK);
		arc(300,250,0+i,30+i,100);
		setcolor(BLACK);
		arc(300,250,330-i,360-i,80);
		setcolor(BLACK);
		arc(300,250,60+i,90+i,60);
		delay(2);
	}

	for(i=0;i<=330;i++)
	{
		setcolor(RED);
		arc(300,250,0+i,30+i,100);
		setcolor(GREEN);
		arc(300,250,330-i,360-i,80);
		setcolor(BLUE);
		arc(300,250,60+i,90+i,60);
		delay(2);
	}

	delay(500);

 }while(i<0);


 cleardevice();
 level2();
 movment(100,68,115,118,2);

 youwin();
 delay(2000);
 getch();
 mainmenu();
}
////////////////////////////////////



////////////////////////////////////
void flash(int x1,int y1,int x2, int y2)
{
	setcolor(RED);

	circle(x1+8,y1+7,7);
	setfillstyle(1,RED);
	floodfill(x1+8,y1+7,RED);

	arc(x1+8,y1+25,0,180,7);
	line(x1+1,y1+25,x1+3,y1+35);
	line(x2,y1+25,x2-3,y1+35);
	line(x1+3,y1+35,x2-3,y1+35);
	floodfill(x1+8,y1+25,RED);

	line(x1+3,y1+35,x1,y2);
	line(x2-3,y1+35,x2,y2);
	line(x1+3,y2,x1+8,y2-10);
	line(x2-3,y2,x1+8,y2-10);
	line(x1,y2,x1+3,y2);
	line(x2-3,y2,x2,y2);
	floodfill(x1+3,y2-2,RED);

	line(x1+1,y1+23,x1-5,y1+35);
	line(x1+1,y1+26,x1-5,y1+35);

	line(x2,y1+23,x2+6,y1+35);
	line(x2,y1+26,x2+6,y1+35);


	setcolor(YELLOW);
	line(x1+3,y1+35,x2-3,y1+35);
	line(x1+3,y1+34,x2-3,y1+34);

	line(x1+1,y1+7,x1+1,y1);
	line(x2,y1+7,x2,y1);

	line(x1,y2,x1+3,y2);
	line(x2-3,y2,x2,y2);
}
///////////////////////////////////




///////////////////////////////////
void flashe(int x1,int y1,int x2, int y2)
{

	circle(x1+8,y1+7,7);
	setfillstyle(1,BLACK);
	floodfill(x1+8,y1+7,BLACK);

	arc(x1+8,y1+25,0,180,7);
	line(x1+1,y1+25,x1+3,y1+35);
	line(x2,y1+25,x2-3,y1+35);
	line(x1+3,y1+35,x2-3,y1+35);
	floodfill(x1+8,y1+25,BLACK);

	line(x1+3,y1+35,x1,y2);
	line(x2-3,y1+35,x2,y2);
	line(x1+3,y2,x1+8,y2-10);
	line(x2-3,y2,x1+8,y2-10);
	line(x1,y2,x1+3,y2);
	line(x2-3,y2,x2,y2);
	floodfill(x1+3,y2-2,BLACK);




/*	line(x1+3,y1+35,x1,y2);
	line(x2-3,y1+35,x2,y2);
	line(x1+3,y2,x1+8,y2-10);
	line(x2-3,y2,x1+8,y2-10);
	line(x1,y2,x1+3,y2);
	line(x2-3,y2,x2,y2);
	floodfill(x1+3,y2-2,RED);  */




	line(x1+1,y1+23,x1-5,y1+35);
	line(x1+1,y1+26,x1-5,y1+35);

	line(x2,y1+23,x2+6,y1+35);
	line(x2,y1+26,x2+6,y1+35);



	line(x1+3,y1+35,x2-3,y1+35);
	line(x1+3,y1+34,x2-3,y1+34);

	line(x1+1,y1+7,x1+1,y1);
	line(x2,y1+7,x2,y1);

	line(x1,y2,x1+3,y2);
	line(x2-3,y2,x2,y2);

	rectangle(x1,y1,x2,y2);
	rectangle(x1-1,y1-1,x2+1,y2+1);
}
////////////////////////////////



int waterl_1(int x1,int y1,int x2,int y2,int lev)
{
if(lev==1)
{
if((x2>=199  && y2>430) && (x1<=326 && y2>430))
	return 1;
else
	return 0;
}
if(lev==2)
{
if((x2>=379  && y2>398) && (x1<=521 && y2>398))
	return 1;
else
	return 0;
}
return 0;
}


void gameover()
{
 int i;
 cleardevice();

 setcolor(RED);
 for(i=0;i<500;i++)
 {
	circle(320,240,i);
 }
 setcolor(WHITE);

 settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
 outtextxy(200,200,"GAMEOVER");
}


void levelcomplete()
{
 int i;
 cleardevice();
 setcolor(BLUE);
 for(i=0;i<500;i++)
 {
	circle(320,240,i);
 }
 setcolor(WHITE);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
 outtextxy(100,200,"Level Complete");

}

void youwin()
{
 int i;
 cleardevice();

 setcolor(BLUE);
 for(i=0;i<500;i++)
 {
	circle(320,240,i);
 }
 setcolor(WHITE);

 settextstyle(TRIPLEX_FONT,HORIZ_DIR,7);
 outtextxy(100,200,"YOU WIN!");
}