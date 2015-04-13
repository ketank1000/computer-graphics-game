#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

void dda(float ,float ,float ,float );
void bresen(int ,int ,int ,int );
void dcircle(int,int,int,int);
void bcircle(int,int,int,int);
void boundary_fill(int,int,int,int);
void flood_fill(int,int,int,int);

int sign(int a);


void dda(float x1,float y1,float x2,float y2)
{
	float dx,dy,i,x,y,length;

	dx=x2-x1;
	dy=y2-y1;

	if(dx>=dy)
	{
		length=dx;
	}
	else
	{
		length=dy;
	}

	dx=(x2-x1)/length;
	dy=(y2-y1)/length;

	x=x1+0.5*sign(dx);
	y=y1+0.5*sign(dy);

	i=1;
	while(i<=length)
	{
		putpixel(x,y,15);
		x=x+dx;
		y=y+dy;
		i=i+1;
	}
}

int sign(int a)
{
   if(a>0)
      return(1);
   else if(a<0)
      return(-1);
   else
      return(0);
}





void bresen(int x1,int y1,int x2,int y2)
{
  int x,y,e,i=1;
  int s1,s2,count,dx,dy,len;
  dx=abs(x2-x1);
  dy=abs(y2-y1);
  x=x1;
  y=y1;
  s1=sign(x2-x1);
  s2=sign(y2-y1);
  e=2*dy-dx;
  if(dx>dy)
  {
    count=0;
  }
  else
  {
    len=dy;
    dy=dx;
    dx=len;
    count=1;
  }
  while(i<=dx)
  {
    putpixel(x,y,15);
    while(e>=0)
    {
      if(count==1)
	 x=x+s1;
      else
	y=y+s2;
      e=e-2*dx;
    }
    if(count==1)
      y=y+s2;
    else
      x=x+s1;
    e=e+2*dy;
    i++;
  }
}



void bcircle(int x1,int y1,int r,int color)
{
	int d,x,y;
	d=3-2*r;
	x=0;
	y=r;
	do
	{
		putpixel(x1+x,y1+y,color);
		putpixel(x1+y,y1+x,color);
		putpixel(x1+y,y1-x,color);
		putpixel(x1+x,y1-y,color);

		putpixel(x1-x,y1-y,color);
		putpixel(x1-y,y1-x,color);
		putpixel(x1-y,y1+x,color);
		putpixel(x1-x,y1+y,color);
		delay(20);
		if(d>0)
		{
			d=d+4*(x-y)+10;
			y=y-1;
		}
		else
		{
		d=d+6+(4*x);
		}
		x=x+1;

	}
	while(x<y);
}




void dcircle(int x,int y,int r,int color)
{
	float x1,y1,e,sx,sy,i=0,v,x2,y2;
	x1=r;
	y1=0;

	sx=x1;
	sy=y1;

	do
	{
		v=pow(2,i);
		i++;
	}
	while(v<r);

	e=(1/v);

	do
	{
		x2=x1+(y1*e);
		y2=y1-(e*x2);

		putpixel(x1+x,y1+y,color);

		x1=x2;
		y1=y2;
	}
	while((y1-sy)<e ||(sx-x1)>e);
}



void flood_fill(int x,int y,int f_color,int b_color)
{
	if(getpixel(x,y)==b_color)
	{
		putpixel(x,y,f_color);

		flood_fill(x+1,y,f_color,b_color);
		flood_fill(x,y+1,f_color,b_color);
		flood_fill(x-1,y,f_color,b_color);
		flood_fill(x,y-1,f_color,b_color) ;
	}
}


void boundary_fill(int x,int y,int f_color,int b_color)
{
	if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
	{
		putpixel(x,y,f_color);
		boundary_fill(x+1,y,f_color,b_color);
		boundary_fill(x,y+1,f_color,b_color);
		boundary_fill(x-1,y,f_color,b_color);
		boundary_fill( x,y-1,f_color,b_color);
	}

}