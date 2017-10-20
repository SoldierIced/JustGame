#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED


class Minotauro :public Personaje {

	private:
		int cuadro,animar;
		int danio2,danio3;
		bool skill,skill2,skill3,spawnc;
		bool CD1,CD2,CD3;

	public:



		bool Getskill() { return skill; }
		bool Getskill2() { return skill2; }
		bool Getskill3() { return skill3; }
		void Setskill (bool val) { skill= val; }
		void Setskill2(bool val) { skill2= val; }
		void Setskill3(bool val) { skill3 = val; }

		bool GetCD1() { return CD1; }
		bool GetCD2() { return CD2; }
		bool GetCD3() { return CD3; }
		void SetCD1(bool val) { CD1 = val; }
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
		vida=2000  ;	estado=1; 	derecha=false;		animar=1;		///mover
		skill= false ;		CD1 =false ;    danio=50 ;  spawnc=false;
		skill2=false  ;		CD2 =false ;	danio2=80 ;
		skill3=false  ;		CD3 =false ;	danio3=0 ;
hitbox.x = x;	hitbox.h= 40;
hitbox.y = y;   hitbox.w=40 ;
		}



};


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


default:
	break;
		///
		}


}
void Minotauro::spawn() {
if (spawnc==false) {
x=1000 ;
y=400;
spawnc=true;
}
}

void Minotauro::mover(int xx,int yy){
if (xx>x) {derecha=false;}
else {derecha=true;}


if (xx<x) {if (xx>=x-50) {estado=0; } 	else {estado=1; x-=1;}		}
	else if (xx>x) {if (xx<=x+48){estado=0;} else {estado=1; x+=1;}	}


	if (yy-120<y) {if (yy-120>=y) {estado=0; } else {estado=1; y-=1;}}

if (yy-120>y) {y++;}



if (xx-100>x) {skill=true;}
else {if (xx+100<x) {skill=true;} else  {skill=false;} }

}



#endif // BOSS_H_INCLUDED
