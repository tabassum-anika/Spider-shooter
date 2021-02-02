#include"iGraphics.h"
#include<stdio.h>

int i, planex, planey, shootx, shooty, shoot = 0, enemyx[6] = { 10, 90, 170, 250 , 330 , 410 },
enemyy[6] = { 512, 512, 512, 512 , 512 , 512 }, game = 0, menu = 0,score=0;

char SCORE[90];

void drawTextButton()
{

}


/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
//place your drawing codes here
		itoa(score, SCORE, 10);
	if(menu == 0)
	{
	   iShowBMP(0, 0, "image\\starting.bmp");
	}
	if (menu == 3)
	{
		exit(0);
	}

	if (menu == 1)
	{

		if (game == 1)
		{
			iClear();

			iShowBMP(0, 0, "image\\background.bmp");
			iShowBMP(planex, planey, "image\\arrow.bmp");
			if (shoot == 1)
				iShowBMP(shootx, shooty, "image\\shoot.bmp");
			for (i = 0; i < 6; i++)
				iShowBMP(enemyx[i], enemyy[i], "image\\spider.bmp");
		}

		else

		{
			iShowBMP(0, 0, "image\\end.bmp");
			iPauseTimer(0);
			iSetColor(255,0,0);

			iText(40, 100, "ScorE:", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(110, 100, SCORE, GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}

}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
	

void iMouseMove(int mx, int my)
{
//place your codes here
}
void iMouse(int button, int state, int mx, int my)
{
//place your codes here
}
void iKeyboard(unsigned char key)
{
//place your codes here
	if (key == ' ')
	{
		shoot = 1;
		shootx = planex + 19;
		shooty = planey + 55;
	}


	if (key == '1')
	{
		game = 1;
		menu = 1;
	}
	if (key == '3')
	{
		menu = 3;
	}

	if (key == 'b' || key == 'B')
	{
		menu = 0;
	}
	if (key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if (key == 'r')
	{
		iResumeTimer(0);
	}
	if (key == 'm')
	{
		PlaySound(0, 0, 0);
	}
	if (key == 'n')
	{
		PlaySound("music\\01-death-note", NULL, SND_LOOP | SND_ASYNC);
	}
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/

void iSpecialKeyboard(unsigned char key)
{
//place your codes for other keys here
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_LEFT)
	{
	  if (planex - 6 >= 0 )
		planex = planex - 15;

	}
	if (key == GLUT_KEY_RIGHT)
	{
		if (planex + 52 <= 512)
		 planex = planex + 15;
	}
	if (key == GLUT_KEY_UP)
	{
		if (planey+ 56 <= 512)
		 planey = planey + 5;
	}
	if (key == GLUT_KEY_DOWN)
	{
		if (planey - 5 >= 0)

           planey = planey - 5;
	}
	//place your codes for other keys here
}
void shootmove()
{
	if (shoot == 1)
		shooty = shooty + 30;
}

void enemymove()
{
	int x = 0;
	for (i = 0; i<6; i++)
	{
		enemyy[i] = enemyy[i] - 3;
		if (enemyy[i] <= 0)
			enemyy[i] = 512;
	}
	if (enemyy[i]<=(x+512))

		iShowBMP(0, 0, "image\\end.bmp");
	}

void kill()
{
	int x = 0,y=0;
	for (i = 0; i<6; i++)
	{
		if (shootx <= enemyx[i] + 52 && shootx + 15 >= enemyx[i]){
			if (shooty + 35 >= enemyy[i] && shooty <= enemyy[i] + 56)
			{
				enemyy[i] = 512;
				shoot = 0;
				shooty = 0;
				score += 5;
				printf("Score:%d", score);
			}
		}
		if (planex <= enemyx[i] + 52 && planex + 52 >= enemyx[i]){
			if (planey + 56 >= enemyy[i] && planey <= enemyy[i] + 56)
				game = 0;
		}
		if (x <= enemyx[i] + 52 && x + 52 >= enemyx[i]){
			if (y + 56 >= enemyy[i] && y <= enemyy[i] + 56)
				game = 0;
		}
		//if (game = 0)
			//iPauseTimer(0);
	}
}



int main()
{
//place your own initialization codes here.
	
	planex = 230;
	planey = 0;
	iSetTimer(50, shootmove);
	iSetTimer(50, enemymove);
	iSetTimer(50, kill);

	srand(time(NULL));

	PlaySound("music\\01-death-note", NULL, SND_LOOP | SND_ASYNC);

	iInitialize(500, 333, "spider killing");

return 0;
}
