#ifndef ENEMIGOS_H_INCLUDED
#define ENEMIGOS_H_INCLUDED



class enemigo1:public Personaje {

	private:
		int cantidad;
		int pegar;
		int coldown;
		bool CD;
		bool animacion;
		bool c;
		bool spawneo;
		SDL_Rect hitbAtaque;

		public:
		int Getcantidad() { return cantidad; }
		void Setcantidad(int val) { cantidad = val; }
		int Getpegar() { return pegar; }
		void Setpegar(int val) { pegar = val; }
		int Getcoldown() { return coldown; }
		void Setcoldown(int val) { coldown = val; }
		bool GetCD() { return CD; }
		void SetCD(bool val) { CD = val; }
		bool Getanimacion() { return animacion; }
		void Setanimacion(bool val) { animacion = val; }
		bool Getc() { return c; }
		void Setc(bool val) { c = val; }
		bool Getspawneo() { return spawneo; }
		void Setspawneo(bool val) { spawneo = val; }
		SDL_Rect GethitbAtaque() { return hitbAtaque; }
		void SethitbAtaque(SDL_Rect val) { hitbAtaque = val; }

	void spawns();
	void mover(int xx,int yy);
	int atacar(int xx,int yy,SDL_Rect pj);
	void morir ();
	int fotito(int framek);
	enemigo1 () {
		derecha=false;
		///atacar
		CD=false;
		animacion=false;
		pegar=0;
		coldown=0;
   ///0////      /////////

	x = 8000;	danio=20;	cantidad=0;
	y = 8000;	estado=1;	vida=40;
c=0;
	spawneo=false;
	hitbox.x=x;
	hitbox.y=y;
hitbox.w=60;
hitbox.h=60;

	hitbAtaque.x=x;
	hitbAtaque.y=y;
	hitbAtaque.h=60 ;
	hitbAtaque.w=100 ;

	}

};


void enemigo1::spawns() {
		vida = 40;
		spawneo= true;
	c=(rand()%6)+1;
switch (c) {

case 1:
x=790;
y=450;
	break;
case 2:
x=790;
y=300;
	break;
case 3:
	x=-100;
	y=300;
	break;
case 4:
		x=-100;
	y=450;
	break;
case 5:
		x=-100;
	y=350;
	break;
case 6:
	x=790;
y=450;
	break;
}



	hitbox.x=x ;
	hitbox.y=y ;
	hitbAtaque.x=x-30;
	hitbAtaque.y=y;



}


void enemigo1::mover (int xx,int yy) {

 if (vida>0) {
switch (estado) {
case 1: ///MOVER
    if (xx<x) {if (xx>=x-40) {} else { x-=3;derecha=false;}  }
	if (xx>x) {if (xx<=x+40){}  else  {x+=3;derecha=true;}  }
     if (yy<y+15) {y-=2;}
   else if (yy>y+15) {y+=2;}




    break;
case 2:/// pa tras
	 if (xx<x) {x+=1;}
    if (xx>x) {x-=1;}
    if (yy>y) {y-=1;}

	break;
default:
	break;



}


hitbox.x=x ;
	hitbox.y=y ;
	hitbAtaque.x=x;
	hitbAtaque.y=y;
}
}
void enemigo1::morir(){
 x=8000;
 cantidad++;
  y=8000;
  vida=-10000;
 spawneo=false;

 hitbAtaque.x=x-40;
	hitbAtaque.y=y;
	hitbox.x=x;
	hitbox.y=y;
estado=3;
}

int enemigo1::atacar(int xx,int yy,SDL_Rect pj) {





if (pegar==0) {
	if (check_collision(pj,hitbAtaque)==true) {


	estado=4;

	CD=true;
	pegar=1;
	return 1;





}/// colision
}///pegar





return 0;
	}

int enemigo1::fotito(int framek) {
	int cuadro=0;

	switch (estado){

case 1:/// caminar

		if (framek>=0&&framek<7) {cuadro=0;}
		else if (framek>=7&&framek<14) {cuadro=1;}
		else if (framek>=14&&framek<21) {cuadro=2;}
		else if (framek>=21&&framek<28) {cuadro=3;}
		else if (framek>=35&&framek<42) {cuadro=4;}
		else if (framek>=42&&framek<49) {cuadro=5;}
		else if (framek>=49&&framek<63) {cuadro=6;}
		else {cuadro=7;}





	if(derecha == false) {
		cuadro += 17;
	}
return cuadro;
	break;
case 2:
if (framek>=0&&framek<30) {cuadro=15;}
		else if (framek>=30&&framek<60) {cuadro=14;}


		if(derecha == false) {
		cuadro += 17;
	}
	return cuadro;

break;


case 4: ///pegar
if (framek>=0&&framek<10) {cuadro=8;}
		else if (framek>=10&&framek<20) {cuadro=9;}
		else if (framek>=20&&framek<30) {cuadro=10;}
		else if (framek>=30&&framek<40) {cuadro=11;}
		else if (framek>=40&&framek<50) {cuadro=12;}
		else if (framek>=40&&framek<50) {cuadro=13;}
		else if   (framek>=50&&framek<58) {cuadro=14;}


				if(derecha == false) {
		cuadro += 17;
	}
if (framek>=58&&framek<=60) {estado=1;}

	return cuadro;
	break;
default:
	break;
		}
}
/// //////////////////////////////////////////////////
class variablesenemigo1{
public:
	 void spawnCreeps (enemigo1 *crii, int *sum) ;
	 void ReseteoCreeps (enemigo1 *crii,int *seg);
	int cantidadEnemigos,SegSpawn,cant;
variablesenemigo1(){
cantidadEnemigos=10;
SegSpawn=1;
cant=0;
}
};
void variablesenemigo1::spawnCreeps(enemigo1 *crii, int *sum) {

if (cant<=cantidadEnemigos) { ///spawn de creeps.
if (*sum==SegSpawn) {
	int az=0;
	while (az<=10) {
		if (crii[az].GetVIDA()>0) {if( crii[az].Getspawneo()==false) {crii[az].spawns(); az=15; }  }
az++;
	}	*sum=0;}
}

}

void variablesenemigo1::ReseteoCreeps(enemigo1 *crii,int *seg) {
if (cant==15) {/// reseteo de creeps .
	for (int az=0; az<10; az++)  {



	crii[az].Setspawneo(false);
	crii[az].Setvida(40);
	crii[az].Setestado(1);


	}
	cant=0;
*seg=0;

}

}
/// //////////////////////////////////////////////////



#endif // ENEMIGOS_H_INCLUDED
