#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stck.h>
#define sst "H:\\BGI"

typedef struct palos
{
    stck * st1;
    stck * st2;
    stck * st3;
}pals;

typedef struct disc
{
    int x;
    int y;
    int tamx;
    int tamy;
} disco;

pals * ipl()
{
    pals * P=malloc(sizeof(pals));
    P->st1=create();
    P->st2=create();
    P->st3=create();
    return P;
}

typedef struct ddhg
{
    int id;
    disco * diss;
}hs;

void cdisc(disco * dis)
{
    rectangle(dis->x,dis->y,dis->tamx,dis->tamy);
}

void mover(disco * dis,int dx, int dy)
{
    setcolor(0);
    cdisc(dis);
    dis->x+=dx;
    dis->y+=dy;
    dis->tamx+=dx;
    dis->tamy+=dy;
    setcolor(0xF);
    cdisc(dis);
}

void rdisc(disco * hanoi)
{
    int i,j;
    int infdisc[5][4]={{50,252,100,25},
			{60,220,80,25},
			{70,188,60,25},
			{80,156,40,25},
			{90,124,20,25}};
    for(i=0;i<5;i++)
    {
	for(j=0;j<4;j++)
	{
	    switch(j)
	    {
		case 0:
			hanoi[i].x=infdisc[i][j]; break;
		case 1:
			hanoi[i].y=infdisc[i][j]; break;
		case 2:
			hanoi[i].tamx=hanoi[i].x+infdisc[i][j]; break;
		case 3:
			hanoi[i].tamy=hanoi[i].y+infdisc[i][j]; break;
	    }
	}
    }
}

int verp(stck * o, pals * plll)
{
    if ( o == plll->st1)
	return 1;
    else if ( o == plll->st2)
	return 2;
    else
	return 3;
}

void movp(disco * hanoi,pals * plll, stck * p1, stck * p2)
{
    int elem;
    elem=del(p1);
    ins(p2,elem);
    switch(elem)
    {
	case 4:
		if(p1==plll->st1 && p2==plll->st2)
		{
			mover(&hanoi[elem],200,32*(5-p2->top));
		}
		mostrarmul(plll->st1,plll->st2,plll->st3);
		break;

    }
}

void main()
{
    int gd=DETECT,gm,i,j,n=5;
    pals * plll = ipl();
    disco * hanoi = malloc(5*sizeof(disco));
    hs * hss = malloc(5*sizeof(hs));
    initgraph(&gd,&gm,sst);
    rdisc(hanoi);
    for(i=0;i<5;i++)
    {
	cdisc(&hanoi[i]);
	ins(plll->st1,i);
    }
    movp(hanoi,plll,plll->st1,plll->st2);
    getch();
}

void hannoi(void)
{
    int i, n;
    if(n==1)
    {
	//movp
    }
    else
    {
	//hannoi
	//movp
	//hannoi
    }
}