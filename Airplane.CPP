#include <graphics.h>
#include <conio.h>
#include <math.h>

int point[8][3]={0};
int LINE[12][2]={0};
int X=0,Y=0,Z=0;
int x= 300,y= 200;


int FUNC_KEY(int *C)
{
	int T = 1;
	*C = getch();
	if ((*C) != 0)
		T = 0;
	else
		*C = getch();
	return T;
}

void Move(int h)
{
	setcolor(0);
	for (int I = 0;I < 12;I++)
		line(x + point[LINE[I][0]][0],y + point[LINE[I][0]][1],x + point[LINE[I][1]][0],y + point[LINE[I][1]][1]);
	if(h==0)
		y-=1;
	else if(h==1)
		x+=1;
	else if(h==2)
		x-=1;
	else if(h==3)
		y+=1;

}

void init(void)
{
	point[0][0] = -10; point[0][1] =-10;point[0][2] = -10;
	point[1][0] = -10;point[1][1] = -10;point[1][2] = 10;
	point[2][0] = 10;point[2][1] = -10; point[2][2] = -10;
	point[3][0] = -10; point[3][1] = 10; point[3][2] =-10;
	point[4][0] = 10; point[4][1] = 10; point[4][2] = -10;
	point[5][0] = -10; point[5][1] = 10; point[5][2] =10;
	point[6][0] = 10; point[6][1] = -10; point[6][2] = 10;
	point[7][0] = 10; point[7][1] = 10; point[7][2] = 10;

	LINE[0][0] = 0; LINE[0][1] = 3;
	LINE[1][0] = 0; LINE[1][1] = 1;
	LINE[2][0] = 0; LINE[2][1] = 2;
	LINE[3][0] = 1; LINE[3][1] = 5;
	LINE[4][0] = 1; LINE[4][1] = 6;
	LINE[5][0] = 2; LINE[5][1] = 4;
	LINE[6][0] = 2; LINE[6][1] = 6;
	LINE[7][0] = 3; LINE[7][1] = 5;
	LINE[8][0] = 3; LINE[8][1] = 4;
	LINE[9][0] = 4; LINE[9][1] = 7;
	LINE[10][0] = 5; LINE[10][1] = 7;
	LINE[11][0] = 6; LINE[11][1] = 7;
}
void charkh(void)
{

	for (int I = 0;I<12;I++)
	{
		int X_ROT,Y_ROT,Z_ROT;
		Y_ROT = point[I][1];
		Z_ROT = point[I][2];
		X_ROT = point[I][0];
		Z_ROT = point[I][2];

		point[I][0] = X_ROT*cos(Z*sin(5)) - Y_ROT*sin(Z*sin(5));
		point[I][1] = X_ROT*sin(Z*sin(5)) + Y_ROT*cos(Z*sin(5));
	}
	setcolor(7);
	for (I = 0;I < 28;I++)
		line(x + point[LINE[I][0]][0],y + point[LINE[I][0]][1],x + point[LINE[I][1]][0],y + point[LINE[I][1]][1]);

}

void Zz()
{
	setcolor(0);
	for (int I = 0;I < 12;I++)
		line(x + point[LINE[I][0]][0],y + point[LINE[I][0]][1],x + point[LINE[I][1]][0],y + point[LINE[I][1]][1]);
	setcolor(7);
	for (I = 0;I < 12;I++)
		line(x + point[LINE[I][0]][0],y + point[LINE[I][0]][1],x + point[LINE[I][1]][0],y + point[LINE[I][1]][1]);
}


void main(void)
{
	int GDRIVER = DETECT,GMODE;
	int KEY , FUNC,fish = 0;
	initgraph(&GDRIVER,&GMODE,"");
	init();
       while(!fish)
	{
		charkh();
		Zz();
		FUNC = FUNC_KEY(&KEY);
		if (!FUNC && KEY  == 27)
			fish = 1;
		else if (!FUNC && KEY == 'z') Z++;
		else if (!FUNC && KEY == 'y') Y++;
		else if (!FUNC && KEY == 'x') X++;
		else if (FUNC && KEY == 72 && y>50  ) Move(0);
		else if (FUNC && KEY == 77 && x<550 ) Move(1);
		else if (FUNC && KEY == 75 && x>50 ) Move(2);
   }    getch();
	closegraph();
}