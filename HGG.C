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
int ccl=1;
void mover(disco * dis,int dx, int dy)
{
    if(ccl>=0xE)
	ccl=0;
    ccl++;
    setcolor(0);
    cdisc(dis);
    dis->x+=dx;
    dis->y+=dy;
    dis->tamx+=dx;
    dis->tamy+=dy;
    setcolor(ccl);
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

int yp=0;
int contis(stck * p1)
{
     stck * count;
     int cont=0;
     count=p1;
     /*while(count->top!=0)
     {
	del(count);
	cont++;
     }*/
     return count->top;
}
void movp(disco * hanoi,pals * plll, stck * p1, stck * p2)
{
    int elem,pp1,pp2,cp1,cp2,ap1,ap2,ypp;
    int yy[]={4,3,-1,2,-1,-1,0,1,1,0,-1,-1,2,-1,-3,0,3,1,-2,1,1,0,-1,-1,0,1,1,-2,1,-3,-4};
    ap1=contis(p1);
    ap2=contis(p2);
    elem=del(p1);
    ins(p2,elem);
    pp1=verp(p1,plll);
    pp2=verp(p2,plll);
    cp1=contis(p1);
    cp2=contis(p2);
    ypp=32 * yy[yp++];
		     if(pp1==1 && pp2==2)
		     {
		     if(ap1>ap2)
			mover(&hanoi[elem],200,ypp);
		     else
			mover(&hanoi[elem],200,ypp);
		}
		else if ( pp1==1 && pp2==3)
		{
		     if(ap1>ap2)
			mover(&hanoi[elem],400,ypp);
		     else
			mover(&hanoi[elem],400,ypp);

		}
		else if ( pp1==2 && pp2==1)
		{
		    if(ap1>ap2)
			mover(&hanoi[elem],-200,ypp);
		    else
			mover(&hanoi[elem],-200,ypp);
		}
		else if ( pp1==2 && pp2==3)
		{
		     if(ap1>ap2)
			mover(&hanoi[elem],200,ypp);
		     else
			mover(&hanoi[elem],200,ypp);
		}
		else if ( pp1==3 && pp2==1)
		{
		     if(ap1>ap2)
			mover(&hanoi[elem],-400,ypp);
		     else
			mover(&hanoi[elem],-400,ypp);
		}
		else if ( pp1==3 && pp2==2)
		{
		     if(ap1>ap2)
			mover(&hanoi[elem],-200,ypp);
		     else
			mover(&hanoi[elem],-200,ypp);
		}
		//rdisc(hanoi);
    //}
}
void hannoi(disco * hanoi,pals * plll, stck * p1, stck * p2,stck * p3,int n);
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
    //movp(hanoi,plll,plll->st1,plll->st3);
    //movp(hanoi,plll,plll->st1,plll->st2);
    getch();
    hannoi(hanoi,plll,plll->st1,plll->st2,plll->st3,n);
    getch();
}

void hannoi(disco * hanoi,pals * plll, stck * p1, stck * p2,stck * p3,int n)
{
    if(n==1)
    {
	movp(hanoi,plll,p1,p3);
	getch();
    }
    else
    {
	hannoi(hanoi,plll,p1,p3,p2,n-1);
	movp(hanoi,plll,p1,p3);
	getch();
	hannoi(hanoi,plll,p2,p1,p3,n-1);
    }
}