#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#define sst "H:\\BGI"

typedef struct disc
{
    int x;
    int y;
    float xtam;
    float ytam;
    int des;
}dis;

dis * discos(dis * ant)
{
    float nt;
    //ant=malloc(sizeof(int));
    //x:90,y:20
    rectangle(ant->x,ant->y,ant->xtam,ant->ytam);
    //ant->des-=10;
    ant->x+=11;
    ant->y-=20;
    printf("X: %f\n",ant->xtam);
    ant->xtam/=1.2;
    ant->xtam+=11;
    ant->ytam-=20;
    return ant;
}


void main()
{
    int gd=DETECT,gm,acx,acy,i;
    dis * ant=malloc(sizeof(dis));
    char cont;
    /*do
    {*/
	initgraph(&gd,&gm,sst);
	acx=getx()+50;
	acy=gety()+200;
	ant->x=acx;
	ant->y=acy;
	ant->xtam=acx+100;
	ant->ytam=acy+20;
	printf("(%d,%d)",ant->x,ant->y);
	for(i=0;i<5;i++)
	    ant=discos(ant);
	cont=getch();
    //} while(cont != 'n');

}
