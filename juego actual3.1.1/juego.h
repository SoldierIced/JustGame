#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include "enemigos.h"
void JUEGO() {
 /***
 1) LISTO
 2)listo
 3)ARREGLAR TODO BUG ENCONTRADO -----paja
 4) listo
 5) CONFIGURAR TIMES DEL MENU  - LISTO?
 6) AGREGAR PUNTOS PARA SUBIR LVL DE HAB Y CONFIGURAR TODO LO DE LA HAB PUÑO - listo
 9) HACER BOSS.
 10) PONER GET SET Y HERENCIA LISTO
 11) BACKUP y sonido
 12) menu?
 13) creditos
 14) bla bla se feliz lince

*/
    ///variables importantes:
    bool fin = false;
int pointpos=0,pointlvl=0,aux=0;;
    char timme[20], lecdhab1[5],lecdhab2[5],lecdhab3[5],chartext[5];
char  frasesegun[30]="Tiempo jugado: ",vida[10];
char  damh1[10],damh2[10],damh3[10],charcdh1[10],charcdh2[10],charcdh3[10];
       int frame = 0;
       int sum=0;
       int  segundos=0,cdhab1=0,cdhab2=0,cdhab3=0,contador=0;
       bool time1skill=true,time1skill2=false,time1skill3=false;
    timer fps;


int vectoraux[10]={0}, vectoraux2[10]={0};
/// HABILIDADES ANIMACIONNES ///

SDL_Surface* hab22= cargarImagen("sprites/habilidades/habi22.bmp");
//SDL_Surface* hab3= cargarImagen("sprites/habilidades/punio.bmp");
SDL_Surface* habpunio =cargarImagen("sprites/habilidades/rayofuego.bmp");
/// //////BOTONES//////////
SDL_Surface* botonrayo=cargarImagen("sprites/habilidades/botones/botonrayo.bmp");
SDL_Surface* botonspe=cargarImagen("sprites/habilidades/botones/botonspeed.bmp");
SDL_Surface* botoncd=cargarImagen("sprites/habilidades/botones/botoncd.bmp");
SDL_Surface* botonpunio=cargarImagen("sprites/habilidades/botones/botonpunio.bmp");
/// ////////////////
SDL_Surface* tirajugador=cargarImagen("sprites/Personaje/achicado.bmp");

/// ////////////Texturas mapa ///////////////
	SDL_Surface* fondo =cargarImagen("sprites/fondo.bmp"); /// declarando fondo
	SDL_Surface* fondo2=cargarImagen("sprites/fondodefondo.bmp");
	SDL_Surface* Habimenu=cargarImagen("sprites/menuhabilidades.bmp");
/// //////CONTADORES, VARIABLES ETC//////
	SDL_Surface* reloj=NULL;
	SDL_Surface* segu=NULL;
	SDL_Surface* timehab1=NULL;
	SDL_Surface* timehab2=NULL;
	SDL_Surface* timehab3=NULL;
/// //////////////////// transparencias
SDL_SetAlpha(botoncd,SDL_SRCALPHA,128);
SDL_SetAlpha(hab22,SDL_SRCALPHA,128);
/// menu habi derecha
	SDL_Surface* vidajugador=NULL;
	SDL_Surface* danioh1=NULL;
	SDL_Surface* danioh2=NULL;
	SDL_Surface* danioh3=NULL;
	SDL_Surface* cdh1=NULL;
	SDL_Surface* cdh2=NULL;
	SDL_Surface* cdh3=NULL;
	SDL_Surface* textTeo=NULL;
int posy=0, posyE=0, posyM=0;
	/// ..CRIP

		SDL_Surface* enemy1=cargarImagen("sprites/Enemigos/FramesEnemigos.bmp");
		SDL_Surface* Iboss=cargarImagen("sprites/Enemigos/text.bmp");
	//SDL_Surface*
	/// SPAWN DE COSAS ACA ///////////////////////////////
jugador pj;

enemigo1 creep[10];
variablesenemigo1 crip;
habilidad skill;
habilidad2 skill2;
habilidad3 skill3;
mapa Map;
lvleohabi lvl;
 Minotauro Boss;
pj.spawn();
SDL_Rect  recJugador[26];
SDL_Rect  recEnemigo[34];
SDL_Rect  recMinotauro[74];
for (int i =0; i<26; i++) {

	recJugador[i].x = 0;
	recJugador[i].y = posy;
	recJugador[i].w = 50;
	recJugador[i].h = 80;
	posy+=80;
}
/// enemigo cuadrito jhermoso ////
for (int i =0; i<34; i++) {

	recEnemigo[i].x = 0;
	recEnemigo[i].y = posyE;
	recEnemigo[i].w = 78;
	recEnemigo[i].h = 120;
	posyE+=120;
}

for (int i =0; i<74; i++) {

	recMinotauro[i].x = 0;
	recMinotauro[i].y = posyM;
	recMinotauro[i].w = 216;
	recMinotauro[i].h = 220;
	posyM+=220;
}



/// ///////////////////////////////////////////
/// CAMBIOS DE VARIABLES.
/// SegSpawn=1; /// Tiempo de spawn entre creep y creep.
/// skill.cd=1; /// tiempo de cd de hablidad de rayito..
/// skill2.cd=2; /// tiempo de cd de hablidad de escudo..


/// ///////////////////////////////////////////

    ///inicio del JUEGO:///////////////////////////////////////////////////////////////////////////////////////////////////
    while(fin == false) {


/// borrar.-.

/// borrar.-.
        ///Todas las cosas relacionadas al framerate:
	///no tocar

        fps.start();
        frame++;



        pj.Setframek(pj.Getframek()+1);
				if(pj.Getframek()>=60) {pj.Setframek(0);}
        if (frame == fpeses) {///no tocar =1 segundo
            frame = 0;
			if (segundos%18==0) {
				if (Boss.Getcontador_de_dogeo()<3) {
				Boss.Setcontador_de_dogeo (Boss.Getcontador_de_dogeo()+2 );}
				}
				if (segundos%4==0) {Boss.SetCD2(true);}
            segundos++;///tiempo general
          sum++;
			 contador++; ///contador de alejar enemigos

for (int i =0; i<10; i++) {

if (creep[i].GetCD()==true) {creep[i].Setcoldown(creep[i].Getcoldown()+1);}
}

for (int i =0; i<10; i++) {
	if (creep[i].Getcoldown()==5) {
		creep[i].SetCD(false);
		creep[i].Setcoldown(0);
		creep[i].Setpegar(0);}

}

           if(crip.cant==10)  { /// movimiento de mapa



           if (Map.Getcantidad()!=8) {
                Map.muveafir(&crip.cant);
                   }
                   }



           if(time1skill==false)  {cdhab1++; /// contador de habilidad 1
            }
           if(time1skill2==true)  {cdhab2++; /// contador de habilidad 2
            }
            if(time1skill3==true)  {cdhab3++; /// contador de habilidad 2
            }



        }


while(SDL_PollEvent(&evento)){
			///SI SE APRIETA UNA tecla

			if(evento.type == SDL_KEYDOWN) {///CIERRE CON SCAPE
				if(evento.key.keysym.sym == SDLK_ESCAPE) {
					fin = true;
				}
				pj.mover(&pointpos,cdhab1,cdhab2,cdhab3);

			}

			if(evento.type == SDL_KEYUP) {///frenar nave si suelta tecla
				pj.frenar(&pointpos);
			}
			if(evento.type == SDL_QUIT){ /// cierre con la cruz roja de arriba a la derecha
				fin = true;
			}

}
pj.accion();






//crip.spawnCreeps(creep, &sum); ///spawn masivo de enemigos
//crip.ReseteoCreeps(creep,&Map.seg);///reseteo de spawn masivo de enemigos


for (int a=0; a<10; a++) { /// movimiento de enemigos
		creep[a].mover(pj.Getx(),pj.Gety());

}






/// HABILIDAD NUMERO 1: ////////////////////////////////////////////////// //////////////////////////////////////////////////

			if(skill.Getactivo() == true) {///SPAWN HABI 1

				skill.mover(pj.Getderecha());
				time1skill=false;
						}


		if (cdhab1==skill.Getcd()) {time1skill=true; cdhab1=0; } ///CD DE HABI 1:
 if(pj.Gettfrayo() == true) {

				if(skill.Getactivo() == false) {


                    if (time1skill==true) {skill.spawn(pj.Getx(), pj.Gety()); }


				}

			}
			if (skill.Getx()>950 || skill.Getx()<-200) {skill.morir();pj.Setshot1(0); }
		/// //////////////////////////////////////////////////

	/// HABILIDAD NUMERO 2: ////////////////////////////////////////////////// //////////////////////////////////////////////////
			if(skill2.Getactivo() == true) { ///SPAWN HABI 2
				skill2.mover();
				time1skill2=true;
							}

		 ///CD DE HABI 2:
		 if (cdhab2==skill2.Getcd()) {time1skill2=false; cdhab2=0;}
 if(pj.Gettfspeed() == true) {

				if(skill2.Getactivo() == false) {

                        if (time1skill2==false) {skill2.spawn(pj.Getx(), pj.Gety());
                        pj.Setvida(pj.GetVIDA()+25);
                              //  time1skill2=true;
                                        }


				}

			}


	if (cdhab2==1) {skill2.morir();pj.Setshot2(0);/// MUERTE DE HABI 2:

	for (int a=0; a<10; a++) {	 vectoraux[a]=0;  }}

	/// ////////////////////////////////////////////////// ////////////////////////////////////////////////// /////////////



/// HABILIDAD NUMERO 3: //////
			if(skill3.Getactivo() == true) { ///SPAWN HABI 3
				skill3.mover(pj.Getderecha());
				time1skill3=true;
							}

		 ///CD DE HABI 3:
		 if (cdhab3==skill3.Getcd()) {time1skill3=false; cdhab3=0;}
 if(pj.Gettfpunio() == true) {

				if(skill3.Getactivo() == false) {

                        if (time1skill3==false) {skill3.spawn(pj.Getx(), pj.Gety());
                                                                      }


				}

			}


	if (cdhab3==1) {/// MUERTE DE HABI 3:
		skill3.morir();pj.Setshot3(0);

	for (int a=0; a<10; a++){ vectoraux2[a]=0;}
	 }
/// ///////////////////////////////////////////////////////////////////////////////////////


for (int i =0; i<10; i++) { /// resetear alejar enemigos


		if(contador==1) {

          creep[i].Setestado(1);

           	} }






for (int i =0; i<10; i++) {  ///atacar de enemigo



if (creep[i].atacar(pj.Getx(),pj.Gety(),pj.Gethitbox())==1) {
	pj.Setvida(pj.GetVIDA()-creep[i].Getdanio());

}




}



for (int i =0; i<10; i++) { /// colision entre creep y habilidad 1. // RAYO
if(check_collision(skill.Gethitbox(),creep[i].Gethitbox())==true){
	skill.Setx(-3000);
	creep[i].Setvida(creep[i].GetVIDA()-skill.Getdanio());
}

}

for (int i =0; i<10; i++) { /// colision entre creep y habilidad 2. // repulsion
if(check_collision(skill2.Gethitbox(),creep[i].Gethitbox())==true){

if (vectoraux[i]==0){
creep[i].Setvida(creep[i].GetVIDA()-skill2.Getdanio());
	creep[i].Setestado(2);
	contador=0;
	vectoraux[i]=1;
	}

}


}

for (int i =0; i<10; i++) { /// colision entre creep y habilidad 3. // PUÑO
if(check_collision(skill3.Gethitbox(),creep[i].Gethitbox())==true){
if (vectoraux2[i]==0){
	creep[i].Setvida(creep[i].GetVIDA()-skill3.Getdanio());

	vectoraux2[i]=1;}

}


}



for (int i =0; i<10; i++) {/// muerte de creeps.
if (creep[i].GetVIDA()<=0&&creep[i].GetVIDA()!=-10000) {
	creep[i].Setestado(0);
	creep[i].morir();
	crip.cant++;
	if (crip.cant==10) {aux=10;}
	 }
		}

if(aux==10)  { /// movimiento de mapa
			pointlvl+=1; aux=0;}



			// ACA EMPIEZA LO BUENO...
			//  BOSS
//if (Map.cantidad==8) {
			Boss.spawn();
            Boss.mover(pj.Getx(),pj.Gety());
Boss.hab1();
Boss.hab2();

if (Boss.Getskill2()==true) {

	if (check_collision(Boss.GethitbAtaque(),pj.Gethitbox())==true ) {

	pj.Setvida(pj.GetVIDA()-Boss.Getdanio2());
	Boss.Setpegar(false);

	}

}


//}









	lvl.subirlvl(&pointpos,&pointlvl,&skill,&skill2,&skill3,time1skill,time1skill2,time1skill3);
for (int i =0; i<10; i++) {creep[i].atacar(pj.Getx(),pj.Gety(),pj.Gethitbox()); }


/// //////////////////////////////////////////////////////////////////////////////
/// MENU DERECHA.
    itoa(skill.Getdanio(),damh1,10); /// DE INT A CHAR  / DAÑO HABI 1
	itoa(skill2.Getdanio(),damh2,10);/// DE INT A CHAR  / DAÑO HABI 2
	itoa(skill3.Getdanio(),damh3,10);/// DE INT A CHAR  / DAÑO HABI 3
	itoa(skill.Getcd(),charcdh1,10);/// DE INT A CHAR  / CD HABI 1
	itoa(skill2.Getcd(),charcdh2,10);/// DE INT A CHAR  / CD HABI 2
	itoa(skill3.Getcd(),charcdh3,10);/// DE INT A CHAR  / CD HABI 3
	itoa (pj.Getx(),vida,10); /// convertir vida jugador en letra
/// //////////////////////////////////////////////////////////////////////////////

	itoa(segundos,timme,10);/// convertir numero en letra //segundos
	itoa(cdhab1,lecdhab1,10);///hab 1
	itoa(cdhab2,lecdhab2,10);///hab 2
	itoa(cdhab3,lecdhab3,10);///hab 2
	itoa(Boss.Getskill(),chartext,10);/// text de teste ode cosas
	/// //////////////////////////////////////////////////////////////////////////////
    danioh1=TTF_RenderText_Solid(font3,damh1,text_color3);///daño habilidad 1
	danioh2=TTF_RenderText_Solid(font3,damh2,text_color3);///daño habilidad 2
	danioh3=TTF_RenderText_Solid(font3,damh3,text_color3);///daño habilidad 3

	cdh1=TTF_RenderText_Solid(font3,charcdh1,text_color3);///CD habilidad 1
	cdh2=TTF_RenderText_Solid(font3,charcdh2,text_color3);///CD habilidad 2
	cdh3=TTF_RenderText_Solid(font3,charcdh3,text_color3);///CD habilidad 2

	vidajugador=TTF_RenderText_Solid(font3,vida,text_color3); ///vida en imagen
	/// //////////////////////////////////////////////////////////////////////////////

	segu=TTF_RenderText_Solid(font,frasesegun,text_color);///frase de "segundos"
	reloj=TTF_RenderText_Solid(font,timme,text_color); /// SEGUNDOOOS
	timehab1=TTF_RenderText_Solid(fonti,lecdhab1,text_color2); ///hab 1
	timehab2=TTF_RenderText_Solid(fonti,lecdhab2,text_color2);///hab 2
	timehab3=TTF_RenderText_Solid(fonti,lecdhab3,text_color2);///hab 2
	textTeo=TTF_RenderText_Solid(fonti,chartext,text_color2);///hab 2





	aplicarSuperficie(0,0,fondo2,screen);

  if (Map.Getmover()==true) {Map.muve(); aplicarSuperficie(Map.Getxm(),Map.Getym(),fondo,screen);} else { aplicarSuperficie(Map.Getxm(),Map.Getym(),fondo,screen);}///FONDO PAPA
	aplicarSuperficie(pj.Getx(),pj.Gety(),tirajugador,screen, &recJugador[pj.fotito()]);
	        for (int a=0; a<10; a++) {
    aplicarSuperficie(creep[a].Getx(),creep[a].Gety(),enemy1,screen,&recEnemigo[creep[a].fotito(frame)]);
    }
			aplicarSuperficie(skill.Getx(),skill.Gety(),habpunio,screen); /// habilidad 1

			 /// MINOTAUROOOO ///

aplicarSuperficie(Boss.Getx()-100,Boss.Gety(),Iboss,screen,&recMinotauro[Boss.fotito(frame)]);

///botones //////////////////////////////////////////////////////////////////////
aplicarSuperficie(550,600,botonrayo,screen); /// boton rayo
aplicarSuperficie(530,650,botonspe,screen); /// boton speed
aplicarSuperficie(580,650,botonpunio,screen); /// boton punio
/// tapa botones ////
if (cdhab1!=0) {aplicarSuperficie(550,600,botoncd,screen); aplicarSuperficie(550,600,timehab1,screen);} /// rayo
if (cdhab2!=0) {aplicarSuperficie(526,649,botoncd,screen); aplicarSuperficie(530,650,timehab2,screen);}/// hab 2
	if (cdhab3!=0) {aplicarSuperficie(580,650,botoncd,screen); aplicarSuperficie(580,650,timehab3,screen);}/// hab puni


	 aplicarSuperficie(200,500,textTeo,screen);
	aplicarSuperficie(skill2.Getx(),skill2.Gety()-50,hab22,screen);/// habilidad 2

//aplicarSuperficie(skill3.x,skill3.y,hab3,screen);/// habilidad 2

			/// RELOJ ///
						aplicarSuperficie(800,0,Habimenu,screen);

///		//////////////////////////////////////////////////////////////////////
								/// MENU DERECHA.
				aplicarSuperficie(935,380,danioh1,screen);///daño habilidad 1
				aplicarSuperficie(935,490,danioh2,screen);/// daño habilidad 2
				aplicarSuperficie(935,610,danioh3,screen);/// daño habilidad 3
				aplicarSuperficie(914,402,cdh1,screen);/// cd hab 1
				aplicarSuperficie(914,515,cdh2,screen);/// cd hab 2
				aplicarSuperficie(914,630,cdh3,screen);/// cd hab 3

				aplicarSuperficie(900,285,vidajugador,screen); ///vida jugador
///		//////////////////////////////////////////////////////////////////////


						aplicarSuperficie(199,600,reloj,screen); /// SEGUNDOS
						aplicarSuperficie(0,600,segu,screen); /// palabra segundos

						/// /////////////////////////////////////

SDL_Flip(screen);
        if((fps.get_ticks() < 1000 / fpeses))
        {
            SDL_Delay((1000 / fpeses) - fps.get_ticks());
        }
	SDL_FreeSurface (segu);
	SDL_FreeSurface (vidajugador);
 SDL_FreeSurface (timehab1);
 SDL_FreeSurface (timehab2);
 SDL_FreeSurface (timehab3);
 SDL_FreeSurface (reloj);
 SDL_FreeSurface (danioh1);
SDL_FreeSurface (danioh2);
SDL_FreeSurface (cdh1);
SDL_FreeSurface (cdh2);
SDL_FreeSurface (cdh3);


    }
    ///Fin del ciclo///////////////////////////////////////////////////////////////////////////////////////////////////////
//sacar de ram
SDL_FreeSurface(hab22);
SDL_FreeSurface(fondo);
SDL_FreeSurface(fondo2);
SDL_FreeSurface(habpunio);
SDL_FreeSurface(botonspe);
SDL_FreeSurface(botonrayo);
SDL_FreeSurface(botoncd);
SDL_FreeSurface(botonpunio);
SDL_FreeSurface(segu);
SDL_FreeSurface(enemy1);
SDL_FreeSurface(Habimenu);
SDL_FreeSurface(tirajugador);


//SDL_FreeSurface(tirajugador);


}



#endif // JUEGO_H_INCLUDED
