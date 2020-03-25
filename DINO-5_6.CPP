//////DINO RUN 2018//////
//////Version:5.6.2//////
//////11:08-1712:18//////

////HEADER FILES USED////
/////////////////////////
#include<stdio.h>      //
#include<fstream.h>    //
#include<dos.h>        //
#include<stdlib.h>     //
#include<conio.h>      //
/////////////////////////


///////VARIABLES:
static int scr=0,int rn=2707+random(9999),int hisc,int au=1;
int t=0,speed=38;
char check;
int BLK=0,BLK2=0,lvl=1;

/////////////////////// CLASS DECLARATION/DEFINITIONS ///////////////////////////

class Dinosaur
{

public:
  void getup();
  void ds(int);
  void duck(int);
  void obj1();
  void obj2(char);
  void pause();
  void highscore();
  void hisout();
  void title();
  void snd();
  void level();

}obj; //OBJECT FOR FUNCTION ACCESS//

/////////////////////////USER INTERFACE FUNCTION/////////////////////////////////////
void Dinosaur::title()
{textbackground(BLACK);
 textcolor(RED);
 window(1,3,20,10);
 cprintf("DINO RUN 2018");
  window(1,4,20,10);
  textcolor(WHITE);
 cprintf("Version:5.6.2");
 textcolor(CYAN);
 window(1,18,20,19);
 cprintf("GAME CREATED BY:");
 textcolor(WHITE);
  window(1,19,24,20);
 cprintf("* Soorya Senthil");
  window(1,20,24,21);
 cprintf("* Mohamed Aqib Nishad");
  window(1,21,24,22);
 cprintf("* Sai Prithiev Adithya");
  window(1,22,24,23);
 cprintf("* Karishma Dharan");

 textcolor(12);
 window(53,17,78,18);
 cprintf("MENU:");
 textcolor(WHITE);
 window(53,18,78,19);
  cprintf("Press Space to Start Game");
 window(53,19,78,20);
  cprintf("Press M To Mute");
 window(53,20,78,21);
  cprintf("Press H to Reset HighScore");
 window(53,21,78,22);
  cprintf("Press X to Exit");

 textcolor(7);
 _setcursortype(_NOCURSOR);
	window(14,6,40,15);
	cprintf("         ��������");
	window(14,7,40,15);
	cprintf("         ��������");
	window(14,8,40,15);
	cprintf("         ��������");
	window(14,9,40,15);
	cprintf(" �      �������� ");
	window(14,10,40,15);
	cprintf(" ���  ���������  ");
	window(14,11,40,15);
	cprintf(" ������������ �  ");
	window(14,12,40,15);
	cprintf("   ���������     ");
	window(14,13,40,15);
	cprintf("    �������    ");
	window(14,14,40,15);
	cprintf("     ��  ��      ");

top:
check=getch();

   if(check==' ')
     {
      window(1,1,78,22);
       clrscr();
       obj.getup();
     }

   else  if(check=='h' || check=='H')
     {
	fstream f("hiscore.txt",ios::out);
	f<<00.0;
	 _setcursortype(_NOCURSOR);
	 textcolor(12);
	 window(53,23,78,23);
	 cprintf("Highscore Cleared");
	 delay(250);
	 clrscr();
	goto top;
     }

   else if(check=='m'|| check=='M')
     {
	au=0;
	_setcursortype(_NOCURSOR);
	textcolor(12);
	window(53,23,78,23);
	cprintf("Muted");
	delay(250);
	clrscr();
	goto top;
     }


   else if(check=='x'|| check=='X')
     {
       textcolor(12);
       _setcursortype(_NOCURSOR);
       window(53,23,78,23);
       cprintf("Exitting Game...");
       delay(250);
       exit(0);
     }

   else
      goto top;

}

/////////////////////////FUNCTIONS TO IMPLEMENT LEVELS////////////////////////////////////

void Dinosaur::level()
{
 if(scr==15)
 { BLK=BLINK;
   lvl++;
   sound(2200*au);
   obj.ds(-1);
   delay(speed*au);
   nosound();
 }

 if(scr==20)
 { speed=speed-4;
   lvl++;
   sound(2300*au);
    obj.ds(-1);
   delay(speed*au);
   nosound();
 }

 if(scr==30)
  {
   BLK=BLINK;
   BLK2=BLINK;
   speed=speed-2;
   lvl++;
   sound(2200*au);
    obj.ds(-1);
   delay(speed*au);
   nosound();
  }
}

////////////////////////GAME BODY FUNCTION_DEFINITION/////////////////////////////

void Dinosaur::getup()
{
	textcolor(WHITE);
	textbackground(BLACK);

	obj.highscore();

	/////////////////////PRINTS BODY HEADER///////////////////////////
	window(4,1,71,10);
	cprintf("Press X to Exit, Space to Jump, D to Duck, P to Pause, HighScore: ");
	cprintf("%d",hisc);
	window(64,2,80,4);
	textcolor(12);
	cprintf("SCORE: ");
	window(64,3,80,4);
	cprintf("Level: ");
	window(1,25,80,25);
	textcolor(GREEN);
	for(int x=0;x<79;x++)
		cprintf("�");

}

//////////////////////FUNCTIONS TO IMPLEMENT HIGHSCORE///////////////////////////

void Dinosaur::highscore()
{
 fstream f("hiscore.txt",ios::in);
 f>>hisc;
 f.close();
}

void Dinosaur::hisout()
{
 fstream f("hiscore.txt",ios::out);

 if(hisc<=scr)
 {
  f<<scr;
 }

 else
 f<<hisc;

  f.close();
}
//////////////////////FUNCTION DEFINITION FOR SCORE AUDIO////////////////////////////////

void Dinosaur::snd()
{
	sound(800*au);
	obj.ds(-1);
	delay(30*au);
	nosound();
	sound(1500*au);
	obj.ds(-1);
	delay(20*au);
	nosound();
}

/////////////// FUNCTION DEFINITION FOR RENDERING DINOSAUR MOTION//////////////////////

void Dinosaur::ds(int jump=0)
{
    _setcursortype(_NOCURSOR);
      textcolor(7);
	static int a=1;

	if(jump==0)
		t=0;
	else if(jump==2)
		t--;

	else if(jump==1)
	  t++;

	window(2,16-t,18,25);
	if(t>0)
	cprintf("                 ");
	cprintf("         ��������");
	cprintf("         ��������");
	cprintf("         ��������");
	cprintf(" �      �������� ");
	cprintf(" ���  ���������  ");
	cprintf(" ������������ �  ");
	cprintf("   ���������     ");

	/////SUSTAINS LEG MOTION/////
	if(a==1)
	{
	     cprintf("    ����  ���    ");
	     cprintf("      ��         ");
	     a=2;
	}

	else if(a==2)
	{
	    cprintf("     ��� ��      ");
	    cprintf("          ��     ");
	    a=1;
	}
	if(t>1)
	cprintf("                ");

	delay(speed);
}

////////////// FUNCTION DEFINITION FOR RENDERING DINOSAUR DUCKING ////////////////////

void Dinosaur::duck(int jump=0)
{
     static int a=1;
     window(2,16,17,25);
     _setcursortype(_NOCURSOR);
     if(jump==1 || jump==2)
	{
	cout<<"                      \n";
	cout<<"          ��������    \n";
	cout<<"          ��������    \n";
	cout<<" ��       ��������    \n";
	cout<<"  ���� ����������     \n";
	cout<<"   ������������       \n";

	}

       ///////SUSTAINS LEG MOTION////
       if(a==1)
	{
	cout<<"    ��������� �   \n";
	cout<<"     ����  ��     \n";
	cout<<"       ��         \n";

	a=2;
	}

      else if(a==2)
	{
	cout<<"    ��������� �   \n";
	cout<<"      ��� ��      \n";
	cout<<"           ��     \n";
	a=1;
	}
	delay(speed);
}


///////////// FUNCTION DEFINTION FOR UNDER HEAD OBSTACLE COURSE ///////////////

void Dinosaur::obj1()
{

	static int x=0;

	//CONDITION FOR FAILIRE//
	if(x==55 && t<6)
	{
	sound(250*au);
	speed=40;
	window(36,7,60,8);
	obj.hisout();
	textcolor(7);
	cprintf("Game Over :(");
	delay(90*au);
	sound(200*au);
	delay(90*au);
	sound(150*au);
	delay(200*au);
	nosound();
	window(36,8,60,9);
	textcolor(CYAN);
	cprintf("SCORE:   ");
	cprintf("%d",scr);
	window(36,9,60,9);
	textcolor(CYAN+BLINK);
	obj.highscore();
	cprintf("HISCORE: ");
	cprintf("%d",hisc);
	getch();
	window(36,7,60,8);
	cprintf("         ");
	scr=0;
	exit(0); //FORCE EXIT FUNCTION//
	}


	if(scr%2==0)
	 textcolor(2);

	else if(rn%2!=0)
	 {
	  if(rn%3==0)
	    textcolor(10+BLK2);

	  else
	     textcolor(14+BLK2);
	 }


	///OBSTACLE LIVE MOTION CODE///
	window(74-x,20,80-x,25);
	cprintf("  �    ");
	cprintf("  �� � ");
	cprintf("������ ");
	cprintf("  ��   ");
	cprintf("  ���  ");
	x++;

	if(x>=72)
	{
	window(2,18,8,23);
	clrscr();
	}

	if(x==73)
	{
	x=0;
	scr++;
	randomize();
	rn=scr+random(1000)+random(700);
	snd();
	window(70,2,80,3);
	cprintf("     ");
	window(70,2,80,3);
	textcolor(WHITE);
	cprintf("%d",scr);
	level();
	window(70,3,80,4);
	cprintf("%d",lvl);

	if(speed>20)
		speed--;
	}
}


////////////////  FUNCTION DEFINITION FOR OVER HEAD OBSTACLE ////////////////////////

void Dinosaur::obj2(char ch)
{

	static int x=0;
	window(30,8,60,9);

	//CONDITION FOR FAILURE//
	if(x==63 && ch != 'd')
	{
	sound(250*au);
	speed=30;
	window(36,7,60,8);
	obj.hisout();
	textcolor(7);
	cprintf("Game Over :(");
	delay(90*au);
	sound(200*au);
	delay(90*au);
	sound(150*au);
	delay(200*au);
	nosound();
	window(36,8,60,9);
	textcolor(CYAN);
	cprintf("SCORE:   ");
	cprintf("%d",scr);
	window(36,9,60,9);
	textcolor(CYAN+BLINK);
	obj.highscore();
	cprintf("HISCORE: ");
	cprintf("%d",hisc);
	getch();
	window(36,7,60,8);
	cprintf("         ");
	scr=0;
	exit(0);  //FORCE EXIT FUNCTION//
	}

	if(scr%16==0)
	 textcolor(scr+BLK+4);

	else
	 textcolor(scr+BLK);


	///OBSTACLE LIVE MOTION CODE///
	window(74-x,11,80-x,25);
	cprintf("�    � ");
	cprintf("�    � ");
	cprintf("������ ");
	cprintf("�_�_�� ");
	cprintf("�����  ");

	x++;
	if(x>=72)
	{
	window(1,10,9,16);
	clrscr();
	}

	if(x==73)
	{
	x=0;
	scr++;
	randomize();
	rn=scr+random(700)+random(500);
	snd();
	window(70,2,80,3);
	cprintf("     ");
	window(70,2,80,3);
	textcolor(WHITE);
	cprintf("%d",scr);
	level();
	window(70,3,80,4);
	cprintf("%d",lvl);
	if(speed>20)
		speed--;
	}
}



/////////////////// FUNCTION DEFINITION TO PAUSE GAME /////////////////////////


void Dinosaur::pause()
{
 window(28,8,60,9);
 textcolor(WHITE);
 cprintf("Press Anything To Resume");
///CHECKS FOR KEYSTROKE TO BREAK///
while(!kbhit())
 {
 _setcursortype(_NOCURSOR);
 getch();
 window(23,8,60,9);
 clrscr();

 for(int i=3;i>0;i--)
 {
  textcolor(12);
  window(32,8,60,9);
  cprintf("Game Starts In: " );
  cprintf("%d",i);
  delay(600);
 }
  window(23,8,60,9);
  clrscr();
  break;
 }
}

///////////////////////////////MAIN FUNCTION///////////////////////////////////////////////////////

void main()
{       clrscr();
	randomize();
	char ch;
	int i;

	obj.title();
	obj.getup();

      while(1)
	{

  ///CHECKS FOR KEY STROKES///
	 while(!kbhit())
		{
		obj.ds();
		if(rn%2!=0)
		obj.obj2('e');

		else if(rn%2==0)
		obj.obj1();
		}

	ch=getch();

	///COMMAND TO JUMP///
	if(ch==' '|| ch=='w')
	{
		for(i=0;i<12;i++)
		{
			obj.ds(1);
			if(rn%2==0)
			obj.obj1();
			else if(rn%2!=0)
			obj.obj2('e');

		}



		for(i=0;i<12;i++)
		{
			obj.ds(2);
			if(rn%2==0)
			obj.obj1();
			else if(rn%2!=0)
			obj.obj2('e');
		}

	}

	/////COMMAND TO DUCK//////
	else if(ch=='d'|| ch=='s')
	{
		char chi=1;
		for(i=0;i<10;i++)
		{
		   obj.duck(chi);

		      if(rn%2==0)
			obj.obj1();

		      else if(rn%2!=0)
		       {
			obj.obj2('d');
			if(chi==1) chi=2;
			if(chi==2) chi=1;
		       }

		}

	}

     //CALL TO PAUSE GAME//
     else if(ch=='p')
	      obj.pause();

     //CALL TO EXIT GAME//
     else if (ch=='x')
	{ textcolor(12);
	   window(32,7,60,8);
	   cprintf("Exitting Game...");
	   delay(250);
		 return;
	}
     }
}