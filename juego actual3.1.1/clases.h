#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

#include "funciones.h"
class Personaje {
protected:
int vida,x,y,estado,danio;
bool derecha;
SDL_Rect hitbox;
public:
    int Getx()    { return x; }
		int	Gety()    { return y; }
		int GetVIDA() { return vida; }
		 int Getdanio() { return danio;}
		int Getestado(){return estado;}
		bool Getderecha() {return derecha;}
		void Setderecha (bool val) {derecha=val;}
		void Setestado(int val){estado = val;}
	   void Setx (int val) { x = val; }
	   void Sety (int val) {y = val; }
       void Setdanio (int val) {danio=val;}
	   void Setvida(int val) { vida= val; }
        SDL_Rect Gethitbox () {return hitbox;}


};


class skilles {
		protected:
		int x;
		int y;
		int cd;
		int danio;
		bool activo;

	public:

		int Getx() { return x; }
		void Setx(int val) { x = val; }
		int Gety() { return y; }
		void Sety(int val) { y = val; }
		int Getcd() { return cd; }
		void Setcd(int val) { cd = val; }
		int Getdanio() { return danio; }
		void Setdanio(int val) { danio = val; }
		bool Getactivo() { return activo; }
		void Setactivo(bool val) { activo = val; }

};

class jugador:public Personaje{
private:
		int xvel;
		int yvel;
		int pointslvl;
		int shot1;
		int shot2;
		int shot3;
		int framek;
		bool tfpunio;
		bool tfrayo;
		bool tfspeed;

	public:
		int Getxvel() { return xvel; }
		void Setxvel(int val) { xvel = val; }
		int Getyvel() { return yvel; }
		void Setyvel(int val) { yvel = val; }
		int Getpointslvl() { return pointslvl; }
		void Setpointslvl(int val) { pointslvl = val; }
		int Getshot1() { return shot1; }
		void Setshot1(int val) { shot1 = val; }
		int Getshot2() { return shot2; }
		void Setshot2(int val) { shot2 = val; }
		int Getshot3() { return shot3; }
		void Setshot3(int val) { shot3 = val; }
		int Getframek() { return framek; }
		void Setframek(int val) { framek = val; }
		bool Gettfpunio() { return tfpunio; }
		void Settfpunio(bool val) { tfpunio = val; }
		bool Gettfrayo() { return tfrayo; }
		void Settfrayo(bool val) { tfrayo = val; }
		bool Gettfspeed() { return tfspeed; }
		void Settfspeed(bool val) { tfspeed = val; }

void spawn ();
void mover (int *pointpos,int cdrayo,int cdrepul,int cdpunio );
void accion();
void frenar(int *pointpos);
int fotito();
jugador ()
{
pointslvl=0;
estado=0;
shot1=0;
shot2=0;
shot3=0;
framek=0;
    tfrayo=false;

 tfspeed=false;
 tfpunio=false;
       derecha=true;
  x=500;
y=400;
hitbox.x = x;
hitbox.y = y;

}

};
void jugador::spawn () {
x=500;
y=400;
xvel = 0;
yvel = 0;
vida=200;
danio=20;
hitbox.x = x;
hitbox.y = y;
hitbox.w = 40;
hitbox.h = 60;


}
void jugador::mover (int *pointpos,int cdrayo,int cdrepul,int cdpunio){
	///cuando apreta 1 boton
		switch(evento.key.keysym.sym){
			case (SDLK_UP):
				if(cdrayo==0) {
				   tfrayo=true;
				   	estado=2;
				}
                break;
            case (SDLK_DOWN):
            	if(cdpunio==0) {
                   tfpunio =true;
                   estado=4;
            	}
				break;

            case (SDLK_RIGHT):
            	if(cdrepul==0) {
                tfspeed=true;
                estado=3;
            	}
				break;

            case (SDLK_LEFT):
            	/*
                 tftormenta=true;
                estado=5; */
				break;

			case(SDLK_w):

				yvel-=3;
				break;
			case(SDLK_a):

				xvel-=3;

			derecha=false;
				break;
			case (SDLK_s):

				yvel+=3;


				break;
			case (SDLK_d):

				xvel+=3;

				derecha=true;
				break;
			case (SDLK_1):
                	*pointpos=1;
				break;

			    case (SDLK_2):
			    	*pointpos=2;
					break;
			    case (SDLK_3):
			    	*pointpos=3;
					break;
			    case (SDLK_4):
			    	*pointpos=4;
					break;



			default:
				break;
		}
}
void jugador::frenar(int *pointpos){
	///SI SE SUELTA UNA TECLA
		switch(evento.key.keysym.sym){
			case (SDLK_UP):
			   tfrayo=false;
			   framek=0;
             break;

            case (SDLK_DOWN):
                   tfpunio=false;
                   framek=0;
				break;

            case (SDLK_RIGHT):
                tfspeed=false;
                framek=0;
				break;

			case(SDLK_w):
				if (yvel<0)
				yvel+=3;

				break;
			case(SDLK_a):
				if (xvel<0)
				xvel+=3;

				break;
			case (SDLK_s):
				if (yvel>0)
				yvel-=3;

				break;
			case (SDLK_d):
				if (xvel>0)
				xvel-=3;
				break;
			case (SDLK_SPACE):
				break;
				case (SDLK_x):

                break;
                 case (SDLK_1):
                	*pointpos=666;
					break;

			    case (SDLK_2):
			    	*pointpos=666;
					break;
			    case (SDLK_3):
			    	*pointpos=666;
					break;
			    case (SDLK_4):
			    	*pointpos=666;
					break;
					default:
				break;
		}
}
void jugador::accion() {

x+=xvel;
y+=yvel;
if (x<0||x>760){
	x-=xvel;
}
if (y<320||y>500){
	y-=yvel;
}
hitbox.x = x;
hitbox.y = y;
}

int jugador::fotito() {
	int cuadro=0;

	switch (estado){

case 0:
	if(xvel != 0 || yvel != 0) {
		if (framek>=0&&framek<12) {cuadro=0;}
		else if (framek>=12&&framek<24) {cuadro=1;}
		else if (framek>=24&&framek<36) {cuadro=2;}
		else if (framek>=36&&framek<48) {cuadro=3;}
		else {cuadro=4;}
		// else if (framek>56&&framek<60) {cuadro=8;}


	}

	if(derecha == false) {
		cuadro += 13;
	}
return cuadro;
	break;
case 2:

	if (shot1==0) {
	if (framek>=0&&framek<20) {cuadro=10;}
		else if (framek>=20&&framek<40) {cuadro=11;}
if (framek>=59&&framek<=60) {shot1=1;estado=0;}
}

		if(derecha == false) {
		cuadro += 13;
	}

	return cuadro;

break;

case 3:

	if (shot2==0) {
	if (framek>=0&&framek<30) {cuadro=12;}
		else if (framek>=30&&framek<58) {cuadro=12;}
if (framek>58&&framek<=60) {shot2=1;estado=0;}
}

		if(derecha == false) {
		cuadro += 13;
	}




	return cuadro;
	break;
case 4:
	if (shot3==0) {
	if (framek>=0&&framek<10) {cuadro=6;}
		else if (framek>=10&&framek<20) {cuadro=7;}
else if (framek>=20&&framek<30) {cuadro=8;}
else if (framek>=30&&framek<40) {cuadro=9;}
else if (framek>=40&&framek<50) {cuadro=10;}
if (framek>55&&framek<=58) {shot3=1;estado=0;}
}

		if(derecha == false) {
		cuadro += 13;
	}


	return cuadro;
	break;
case 5:

	return cuadro;
	break;
default:
	break;
		}



}
/// //////////////////////////////////////////////////
class habilidad:public skilles {
private:
     bool disparado, orientacion;
     SDL_Rect habilidadpunio;
           public:
      void spawn(int xj, int yj);
      void mover(bool derecha);
      void morir();
bool Getdisparado (){return disparado;}
bool Getorientacion (){return orientacion;}
bool Setorientacion (bool val) {orientacion=val;}
bool Setdisparado   (bool val) {disparado=val;}
SDL_Rect Gethitbox() {return habilidadpunio;}


habilidad (){
	 disparado=true;
x=-3000;
y=-3000;
activo=false;
danio=40;
habilidadpunio.y=y;
habilidadpunio.x=x;
habilidadpunio.h=15;
habilidadpunio.w=40;
cd=3;
}

};
void habilidad::spawn(int xx,int yy) {
activo=true;
x=xx;
y=yy;
disparado = true;

habilidadpunio.h=15;
habilidadpunio.w=40;
habilidadpunio.y=y;
habilidadpunio.x=x;
}
void habilidad::mover(bool derecha) {

if (activo==true) {
if (disparado==true) {

if(derecha==true) {
	orientacion = true;
	disparado = false;
}
else{
	orientacion = false;
	disparado = false;
}


}
if(orientacion==true) {
x+=15;
habilidadpunio.y=y;
habilidadpunio.x=x;

}
else{
	x-=15;

habilidadpunio.y=y;
habilidadpunio.x=x;
}


if (x>950||x<-200) {activo=false; disparado=false;}





}


}

void habilidad::morir(){
x=-3000;
y=-3000;
habilidadpunio.y=y;
habilidadpunio.x=x;
activo=false;
}

/// ///////////////////////////////////////////////////// //////////////////////////////////////////////////
class habilidad2:public skilles {
private:
	 SDL_Rect speed;
      public:
      void spawn(int xj, int yj);
      void mover();
      void morir();
     SDL_Rect Gethitbox () {return speed;}


      habilidad2 (){
      	cd=3;
x=-3000;
y=-3000;
activo=false;
danio=20;
speed.y=y;
speed.x=x;
speed.h=1;
speed.w=1;
}

};
void habilidad2::spawn(int xx,int yy) {
activo=true;
x=xx-40;
y=yy;

speed.h=60;
speed.w=160;
speed.y=y;
speed.x=x;

}
void habilidad2::mover() {
int a=0;
if (activo==true) {


a+=15;

speed.y=y;
speed.x=x;

if (a>=30) {activo=false;}
  }
  a=0;


}
void habilidad2::morir(){
x=-3000;
y=-3000;
speed.x=x;
speed.y=y;

activo=false;
}

/// /////////////////////////////////////////////
class habilidad3: public skilles {
private:

     bool pegando, orientacion;
     SDL_Rect pegarbasico;
public:
      void spawn(int xj, int yj);
      void mover(bool derecha);
      void morir();
      bool Getpegando () {return pegando;}
	void Setpegando (bool val) {pegando=val;}
	  bool Getorientacion () {return orientacion;}
	void Setorientacion (bool val) { orientacion=val;}
SDL_Rect Gethitbox () {return pegarbasico;}

habilidad3 (){
	 pegando=true;
x=-3000;
y=-3000;
activo=false;
danio=10;
pegarbasico.y=y;
pegarbasico.x=x;
pegarbasico.h=60;
pegarbasico.w=60;
cd=3;
}
};
void habilidad3::spawn(int xx,int yy) {
activo=true;
x=xx;
y=yy;
pegando = true;

pegarbasico.h=60;
pegarbasico.w=60;
pegarbasico.y=y;
pegarbasico.x=x;
}
void habilidad3::mover(bool derecha) {
int aux;
if (activo==true) {
if (pegando==true) {
 aux=x;
if(derecha==true) {
	orientacion = true;
	pegando = false;
}
else{
	orientacion = false;
	pegando = false;
}


}
if(orientacion==true) {

x+=15;
pegarbasico.y=y;
pegarbasico.x=x;

}
else{

	x-=15;

pegarbasico.y=y;
pegarbasico.x=x;
}


if (x>aux||x<aux) {activo=false; pegando=false;}


}
}

void habilidad3::morir(){
x=-3000;
y=-3000;
pegarbasico.y=y;
pegarbasico.x=x;
activo=false;
}
/// /////////////////////////////////////////////

class lvleohabi {
public:
void subirlvl(int *pointpos,int *pointslvl,habilidad *skill,habilidad2 *skill2, habilidad3 *skill3,char time1skill,char time1skill2, char time1skill3 );
};

void lvleohabi::subirlvl(int *pointpos,int *pointslvl,habilidad *skill,habilidad2 *skill2, habilidad3 *skill3,char time1skill,char time1skill2, char time1skill3 ) {

if (*pointslvl>0) {


 switch (*pointpos) {

 case 1:
 	if (time1skill==true) {
 	skill->Setdanio(skill->Getdanio()+10);
 if (skill->Getcd()-2>0)	skill->Setcd(skill->Getcd()-2);
 	*pointpos=666;
 	*pointslvl-=1;
 	}
 	break;
 case 2:
 	if (time1skill2==false) {
 	skill2->Setdanio(skill2->Getdanio()+3);
 	if (skill2->Getcd()-4>0)skill2->Setcd(skill2->Getcd()-4);
 	*pointslvl-=1;
 	*pointpos=666;
 	}
	break;
 case 3:
 	if (time1skill3==false) {
 	skill3->Setdanio(skill3->Getdanio()+10);
 	if (skill3->Getcd()-3>0)skill3->Setcd(skill3->Getcd()-3);
 	*pointslvl-=1;
 	*pointpos=666;
 	}
	break;
 case 4:
	break;
 default:
	break;


 }

}

}
/// //////////////////////////////////////////////////
class mapa{
private:
bool mover;
		int xm;
		int ym;

		int cantidad;

	public:
		int seg;
		int Getxm() { return xm; }
		void Setxm(int val) { xm = val; }
		int Getym() { return ym; }
		void Setym(int val) { ym = val; }
		int Getcantidad() { return cantidad; }
		void Setcantidad(int val) { cantidad = val; }
		bool Setmover (bool val) {return mover;}
		bool Getmover () {return mover;}

void muve();
void morir();
void muveafir(int *cant);
mapa() {
xm=0;
ym=0;
seg=0;
cantidad=0;
mover=false;
}

};
void mapa::muveafir(int *cant) {
seg++;
if(seg==1||seg==2||seg==3||seg==4) { mover=true;}
    if(seg==5)
		{mover=false;
			*cant=15;
			cantidad++;
			  }

}
void mapa::muve() {

if(mover==true) {xm-=1;}

}
void mapa::morir() {


mover=false;
}




#endif // CLASES_H_INCLUDED
