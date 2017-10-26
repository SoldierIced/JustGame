#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED


class Minotauro :public Personaje {

	private:
		int cuadro,animar,contador_de_dogeo;
		int danio2,danio3;
		bool skill,skill2,skill3,spawnc;
		bool pegar,CD2,CD3;
		bool moverse;
		int c;
        SDL_Rect hitbAtaque;
	public:


		SDL_Rect GethitbAtaque() { return hitbAtaque; }
		void SethitbAtaque(SDL_Rect val) { hitbAtaque = val; }

		int Getdanio2 () {return danio2;}
		bool Getskill() { return skill; }
		bool Getskill2() { return skill2; }
		bool Getskill3() { return skill3; }
		void Setskill (bool val) { skill= val; }
		void Setskill2(bool val) { skill2= val; }
		void Setskill3(bool val) { skill3 = val; }
		void Setmoverse(bool val) { moverse= val; }
		void Setcontador_de_dogeo(int val) {contador_de_dogeo=val;}

		int  Getcontador_de_dogeo() {return contador_de_dogeo;}
		bool Getmoverse() { return moverse; }
		bool Getpegar() { return pegar; }
		bool GetCD2() { return CD2; }
		bool GetCD3() { return CD3; }
		void Setpegar(bool val) { pegar = val; }
		void SetCD2(bool val) { CD2 = val; }
		void SetCD3(bool val) { CD3 = val; }


		void hab1();
		void hab2();
		void hab3();
		void morir();
		void spawn();
		void mover(int xx,int yy);
		int fotito(int framek);
		Minotauro() {

		x=8000 ;
		y=8000 ;
		vida=2000  ;	estado=1; 	contador_de_dogeo=0;	derecha=false;		animar=0;		///mover
		skill= false ;		pegar =true ;    danio=50 ;  spawnc=false;
		skill2=false  ;		CD2 =false ;	danio2=80 ; moverse=true;
		skill3=false  ;		CD3 =false ;	danio3=0 ;
hitbox.x = x;	hitbox.h= 40;
hitbox.y = y;   hitbox.w=40 ;

	hitbAtaque.x=8000;
	hitbAtaque.y=8000;
	hitbAtaque.h=60 ;
	hitbAtaque.w=120 ;



		}



};


void Minotauro::spawn() {
if (spawnc==false) {
x=1100 ;
y=400;
spawnc=true;
}
}

void Minotauro::mover(int xx,int yy){
	if (moverse==true) {

if (xx>x) {derecha=false;}
else {derecha=true;}


if (xx<x) {if (xx>=x-50) {estado=4; } 	else {estado=1; x-=1;}		}
	else if (xx>x) {if (xx<=x+48){estado=4;} else {estado=1; x+=1;}	}


	if (yy-120<y) {if (yy-120>=y) {estado=4; } else {estado=1; y-=1;}}

if (yy-120>y) {y++;}




}
if (xx-200>x&&xx-400<x) {skill=true; moverse=false; estado=3;}
else {if (xx+200<x&&xx+400>x) {
	skill=true;
moverse=false;
estado=3;} else  {skill=false;} }
}


void Minotauro::hab1 () {




if (estado==3) {
	if (skill==true) {

c=1;

	}

}
if (c==1) {
	if (contador_de_dogeo>=1) {
			if (derecha==false) {
				if (animar==1) {
	x+=9; estado=3;}
if (x>=1000) {estado=1; moverse=true;
 contador_de_dogeo--;c=0;animar=0;}

		}
			else {
			if (animar==1) {
				x-=9;estado=3;}
			if (x<=-200) {
				estado=1; moverse=true;
			contador_de_dogeo--;c=0;animar=0;}
}


}
else {estado=1; moverse=true;
			c=0;animar=0; }
}

}


void Minotauro::hab2() {
if (estado==4) {
	if (CD2==true) {
	estado=2;


	}
	else{estado=0;hitbAtaque.x=8000;
	hitbAtaque.y=8000;}


}
if (pegar==true) {
	skill2=true;

if (derecha==false) {

	hitbAtaque.x=x+40;
	hitbAtaque.y=y;

}
else {

	hitbAtaque.x=-40;
	hitbAtaque.y=y;

}
}
else {hitbAtaque.x=8000;
	hitbAtaque.y=8000;

	}
}





int Minotauro::fotito(int framek) {
cuadro=0;

switch (estado){

case 0:

		if (framek>=0&&framek<7) {cuadro=0;}
		else if (framek>=7&&framek<14) {cuadro=1;}
		else if (framek>=14&&framek<21) {cuadro=2;}
		else if (framek>=21&&framek<28) {cuadro=3;}
		else if (framek>=28&&framek<35) {cuadro=4;}
		else if (framek>=35&&framek<42) {cuadro=5;}
		else if (framek>=42&&framek<49) {cuadro=6;}
		else if (framek>=49&&framek<56) {cuadro=7;}






	if(derecha == false) {
		cuadro += 37;
	}
return cuadro;

	break;

case 1:

		if (framek>=0&&framek<7) {cuadro=8;}
		else if (framek>=7&&framek<14) {cuadro=9;}
		else if (framek>=14&&framek<21) {cuadro=10;}
		else if (framek>=21&&framek<28) {cuadro=9;}
		else if (framek>=28&&framek<35) {cuadro=8;}
		else if (framek>=35&&framek<42) {cuadro=9;}
		else if (framek>=42&&framek<49) {cuadro=10;}
		else if (framek>=49&&framek<56) {cuadro=9;}
		else if (framek>=56&&framek<60) {cuadro=8;}






	if(derecha == false) {
		cuadro += 37;
	}
return cuadro;


	break;
case 2:
			if (framek>=0&&framek<3) {cuadro=12;}
		else if (framek>=3&&framek<6) {cuadro=13;}
		else if (framek>=6&&framek<9) {cuadro=14;}
		else if (framek>=9&&framek<12) {cuadro=15;}
		else if (framek>=12&&framek<15) {cuadro=16;}
		else if (framek>=15&&framek<18) {cuadro=17;}
		else if (framek>=18&&framek<21) {cuadro=18;}
		else if (framek>=21&&framek<24) {cuadro=19;}
		else if (framek>=24&&framek<27) {cuadro=20;}
		else if (framek>=30&&framek<33) {cuadro=21;}
		else if (framek>=33&&framek<36) {cuadro=22;}

		else if (framek>=36&&framek<40) {cuadro=23;}
		else if (framek>=40&&framek<44) {cuadro=24;}
		else if (framek>=44&&framek<48) {cuadro=25;}
		else if (framek>=48&&framek<52) {cuadro=26;pegar=true;}
		else if (framek>=52&&framek<56) {cuadro=27;}
		else if (framek>=56&&framek<60) {cuadro=28;}






	if(derecha == false) {
		cuadro += 37;
	}
return cuadro;

	break;

case 3:

		if (framek>=0&&framek<12) {cuadro=28;}
		else if (framek>=12&&framek<24) {cuadro=29;}
		else if (framek>=24&&framek<36) {cuadro=30;}
		else if (framek>=36&&framek<48) {cuadro=30;animar=1;}
		if (animar==1) {cuadro=31;}







	if(derecha == false) {
		cuadro += 37;
	}
return cuadro;
	break;



default:
	break;
		///
		}


}
#endif // BOSS_H_INCLUDED
