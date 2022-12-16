#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "menu.h"
#define ERROR -1
#define SALIR_MENU 5


/** \Obtiene el id de un jugador del archivo binario del id, sino genera uno
 * empezando desde el numero 371
 * \param path char*
 * \return error si no puede generar el ID, sino 0 (exito)
 *
 */
int static obtainID(char* path);


int controller_cargarIdDesdeBinario(char* path,int* lastId)
{
   int retorno = ERROR;
   FILE* pFile = fopen(path,"rb");
   if(pFile != NULL){
	   parser_IdFromBinary(pFile,lastId);
	   retorno = 0;
   }
   fclose(pFile);
   return retorno;
}


int static obtainID(char* path){
	int id = 371;
	int* lastId;
	lastId = &id;
	if(path != NULL){
		if(controller_cargarIdDesdeBinario(path,lastId) != ERROR){
			id = *lastId;
			id++;
		}
		}
	return id;
}

int controller_guardarIdModoBinario(char* path, int* lastId){
	int retorno = ERROR;
	FILE *pFile;
	if(path != NULL){
		pFile = fopen(path,"wb");
			fwrite(lastId,sizeof(int),1,pFile);

		fclose(pFile);
		retorno =0;
	}
	return retorno;
}

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = ERROR;
	FILE* pFile;
	pFile = fopen(path,"r");
	if(pFile != NULL){
		if(parser_JugadorFromText(pFile ,pArrayListJugador) != ERROR){
			puts("Se pudo cargar el archivo csv con exito\n");
			retorno = 0;
		}
		else{
			puts("Error al abrir el  archivo csv\n");
		}
	}
	fclose(pFile);
    return retorno;
}


int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
   int retorno = ERROR;
   FILE* pFile = fopen(path,"rb");
   if(pFile != NULL && pArrayListJugador != NULL){
	   parser_JugadorFromBinary(pFile, pArrayListJugador);
	   puts("Se pudo cargar el archivo binario con exito\n");
	   fclose(pFile);
	   retorno = 0;
   }

   return retorno;
}

int buscarJugadorPorId(LinkedList* pArrayListJugador, int id){
	int retorno = ERROR;
	int i;
	if(pArrayListJugador != NULL){
		int len = ll_len(pArrayListJugador);
		if(len >0){
			Jugador* jugadorBuscado;
			for(i = 0; i < len; i++){
				jugadorBuscado = ll_get(pArrayListJugador,i);
				if(jugadorBuscado->id == id){
					retorno = i;
					break;
				}
			}
		}
	}
	return retorno;
}


int buscarSeleccionPorId(LinkedList* pArrayListSeleccion, int id){
	int retorno = ERROR;
	int i;
	if(pArrayListSeleccion != NULL){
		int len = ll_len(pArrayListSeleccion);
		if(len >0){
			Seleccion* selecccionBuscada;
			for(i = 0; i < len; i++){
				selecccionBuscada = ll_get(pArrayListSeleccion,i);
				if(selecccionBuscada->id == id){
					retorno = i;
					break;
				}
			}
		}
	}
	return retorno;
}


int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno = ERROR;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion = 0;
	int flag1, flag2, flag3, flag4, flag5;
	Jugador* nuevoJugador;
	nuevoJugador = jug_new();

	if(pArrayListJugador != NULL && nuevoJugador != NULL ){
		id = obtainID("lastId.bin");
		flag1 = jug_setId(nuevoJugador,id);

		utn_getNombre(nombreCompleto,100,"Ingrese el nombre del jugador: \n","Reingrese el nombre del jugador: \n",3);
		uppercaselInitial(nombreCompleto);
		flag2 = jug_setNombreCompleto(nuevoJugador,nombreCompleto);

		utn_getNumero(&edad,"Ingrese la edad del jugador[hasta 50 anios]: \n","Reingrese la edad del jugador[hasta 50 anios]: \n",1,50,3);
		flag3 = jug_setEdad(nuevoJugador,edad);

		utn_getNombre(posicion,30,"Ingrese la posicion del jugador: [portero/defensa/centro/delantero]\n",
				"Reingrese la posicion del jugador: [portero/defensa/centro/delantero]\n",3);
		while(strcmp(posicion,"portero") != 0 && strcmp(posicion,"defensa") != 0  && strcmp(posicion,"delantero") != 0
				&& strcmp(posicion,"centro") != 0){
			utn_getNombre(posicion,30,"Ingrese la posicion del jugador: [portero/defensa/centro/delantero]\n",
							"Reingrese la posicion del jugador: [portero/defensa/centro/delantero]\n",3);
		}
		flag4 = jug_setPosicion(nuevoJugador,posicion);

		utn_getNombre(nacionalidad,30,"Ingrese la nacionalidad del jugador:\n","Ingrese la nacionalidad del jugador:\n",3);
		uppercaselInitial(nacionalidad);
		//no valide la nacionalidad del jugador
		flag5 = jug_setNacionalidad(nuevoJugador,nacionalidad);

		jug_setIdSeleccion(nuevoJugador,idSeleccion);

		if(flag1 != ERROR && flag2 != ERROR && flag3 != ERROR && flag4 != ERROR && flag5 != ERROR){
			ll_add(pArrayListJugador,nuevoJugador);
			printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n",10,"Id",30,"Nombre",10,"Edad",30,"Posicion",30,"Nacionalidad",20,"IdSeleccion");
			mostrarInfoJugador(nuevoJugador);
			controller_guardarIdModoBinario("lastId.bin",&id);
			retorno = 0;
		}
	}
    return retorno;
}



int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = ERROR;
	int i;
	int len;
	Jugador* jugadorBuscado;
	if(pArrayListJugador != NULL){
		len = ll_len(pArrayListJugador);
		if(len >0){
			printf("\n *********LISTADO DE JUGADORES*************\n");
			printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n",10,"Id",30,"Nombre",10,"Edad",30,"Posicion",30,"Nacionalidad",20,"IdSeleccion");
			for(i = 0; i< len; i++){
				jugadorBuscado = ll_get(pArrayListJugador,i);
				mostrarInfoJugador(jugadorBuscado);
				retorno =0;
			}
		}
	}
    return retorno;
}

int controller_listarJugadores2(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno = ERROR;
	int i,j, idSeleccion, IdSeleccionJug;
	int len, len2;
	char pais[20];
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		Jugador* jugadorBuscado;
		Seleccion* seleccionBuscada;
		len = ll_len(pArrayListJugador);
		len2 = ll_len(pArrayListSeleccion);
		if(len >0 && len2 >0){
			printf("\n *********LISTADO DE JUGADORES*************\n");
			printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n",10,"Id",30,"Nombre",10,"Edad",30,"Posicion",30,"Nacionalidad",30,"SELECCION");
			for(i = 0; i< len; i++){
				jugadorBuscado = ll_get(pArrayListJugador,i);
				jug_getSIdSeleccion(jugadorBuscado,&IdSeleccionJug);
					for(j =0; j <len2; j++){
						seleccionBuscada = ll_get(pArrayListSeleccion,j);
						selec_getId(seleccionBuscada,&idSeleccion);
						if(IdSeleccionJug == idSeleccion){
							selec_getPais(seleccionBuscada,pais);
							mostrarInfoJugadorYseleccion(jugadorBuscado,pais);
							break;
							}
						 if(IdSeleccionJug == 0){
							 strcpy(pais,"NO CONVOCADO");
							mostrarInfoJugadorYseleccion(jugadorBuscado,pais);
							break;
						}
					}
			}
			retorno =0;
		}
	}
    return retorno;
}


int controller_listarConvocados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	int retorno = ERROR;
	int i,j, idSeleccionJug,idSeleccion;
	int len, len2;
	char pais[20] ="NO CONVOCADO";
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		Jugador* jugadorBuscado;
		Seleccion* seleccionBuscada;
		len = ll_len(pArrayListJugador);
		len2 = ll_len(pArrayListSeleccion);
		if(len >0 && len2 >0){
			printf("\n *********LISTADO DE JUGADORES CONVOCADOS*************\n");
			printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n",10,"Id",30,"Nombre",10,"Edad",30,"Posicion",30,"Nacionalidad",30,"SELECCION");
			for(i = 0; i< len; i++){
				jugadorBuscado = ll_get(pArrayListJugador,i);
				jug_getSIdSeleccion(jugadorBuscado,&idSeleccionJug);
					for(j =0; j <len2; j++){
						seleccionBuscada = ll_get(pArrayListSeleccion,j);
						selec_getId(seleccionBuscada,&idSeleccion);
						if(idSeleccionJug == idSeleccion){
							selec_getPais(seleccionBuscada,pais);
							mostrarInfoJugadorYseleccion(jugadorBuscado,pais);
							break;
							retorno =0;
						}
					}
			}
		}
	}
    return retorno;
}



int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int retorno = ERROR;
	int id, index, opcion;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	if(pArrayListJugador !=NULL){
		int len = ll_len(pArrayListJugador);
		if(len >0){
		Jugador* jugadorBuscado;
		controller_listarJugadores(pArrayListJugador);
		utn_getNumero(&id,"Ingrese el id del jugador a buscar: \n","Reingrese el id del jugador a buscar: \n",1,1000000,3);
		index = buscarJugadorPorId(pArrayListJugador,id);
		if(index != ERROR){
			jugadorBuscado = ll_get(pArrayListJugador, index);
			mostrarInfoJugador(jugadorBuscado);
			mostrarMenuModificarJugador();
			utn_getNumero(&opcion,"Elija la opcion deseada: \n","Reelija la opcion deseada: \n",1,5,3);
			while(opcion != SALIR_MENU){
				switch(opcion){
				case 1:
					utn_getCadena(nombreCompleto,100,"Ingrese el nombre del jugador: \n","Reingrese el nombre del jugador: \n",3);
					uppercaselInitial(nombreCompleto);
					jug_setNombreCompleto(jugadorBuscado,nombreCompleto);
					break;
				case 2:
					utn_getNumero(&edad,"Ingrese la edad del jugador: \n","Reingrese la edad del jugador: \n",1,120,3);
					jug_setEdad(jugadorBuscado,edad);
					break;
				case 3:
					utn_getNombre(posicion,30,"Ingrese la posicion del jugador: [portero/defensa/centro/delantero]\n",
									"Reingrese la posicion del jugador: [portero/defensa/centro/delantero]\n",3);
					jug_setPosicion(jugadorBuscado,posicion);
					break;
				case 4:
					utn_getNombre(nacionalidad,30,"Ingrese la nacionalidad del jugador:\n","Ingrese la nacionalidad del jugador:\n",3);
					uppercaselInitial(nacionalidad);
					jug_setNacionalidad(jugadorBuscado,nacionalidad);
					break;
					retorno = 0;
				}
				mostrarInfoJugador(jugadorBuscado);
				mostrarMenuModificarJugador();
				utn_getNumero(&opcion,"Elija la opcion deseada: \n","Reelija la opcion deseada: \n",1,5,3);
			}
		}
		}
	}
    return retorno;
}


int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int retorno = ERROR;
	int id,index;
	char opcion= 'z';
	if(pArrayListJugador != NULL){
		int len = ll_len(pArrayListJugador);
		if(len >0){
			printf("\n ********* AVISO********\n");
			printf("\n Antes de eliminar si esta convocado, recuerde darle de baja en la seleccion\n");
			controller_listarJugadores(pArrayListJugador);
			utn_getNumero(&id,"Ingrese el id del jugador a eliminar: \n","Reingrese el id del jugador a eliminar: \n",1,2000,3);
			index = buscarJugadorPorId(pArrayListJugador,id);
			if(index != ERROR){
			utn_getNombre(&opcion,2,"Desea eliminar al jugador seleccionado [s/n]\n",
					"Desea eliminar al jugador seleccionado [s/n]\n",3);
			strMinuscula(&opcion);
			while(opcion != 's' && opcion != 'n'){
				utn_getNombre(&opcion,2,"Desea eliminar al jugador con id: %d [s/n]\n",
									"Desea eliminar al jugador con id: %d [s/n]\n",3);
				strMinuscula(&opcion);
			}
				if(opcion == 's'){
					ll_remove(pArrayListJugador,index);
					retorno =0;
					printf("Se ha eliminado al jugador\n");
				}
			}
		}
	}
    return retorno;
}


int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = ERROR;
	int orden;
	char opcionMenu ='z';
	if(pArrayListJugador !=NULL){
		mostrarMenuOrdenarYlistar();
		utn_getNombre(&opcionMenu,2,"Ingrese la opcion deseada:\n","Reingrese la opcion deseada: \n",3);
		strMayuscula(&opcionMenu);
		            	while(opcionMenu != 'E'){
		            		utn_getNumero(&orden,"Seleccione el orden [0 - Descendente/1 - Ascedente]: \n","Reseleccione el orden [0 - Descendente/1 - Ascedente]: \n",0,1,3);
		            		switch(opcionMenu){
		            		case 'A':
		            			ll_sort(pArrayListJugador,jugador_sortNacionalidad,orden);
		            			controller_listarJugadores(pArrayListJugador);
		            			 retorno = 0;
		            			break;
		            		case 'B':
		            			break;
		            		case 'C':
		            			ll_sort(pArrayListJugador,jugador_sortEdad,orden);
		            			controller_listarJugadores(pArrayListJugador);
		            			 retorno = 0;
		            			break;
		            		case 'D':
		           			 ll_sort(pArrayListJugador,jugador_sortNombre,orden);
		           			 controller_listarJugadores(pArrayListJugador);
		           			 retorno = 0;
		            		 break;
		            		}
		            		mostrarMenuOrdenarYlistar();
		            		utn_getNombre(&opcionMenu,2,"Ingrese la opcion deseada:\n","Reingrese la opcion deseada: \n",3);
		            	    strMayuscula(&opcionMenu);
		            	}
	}
    return retorno;
}


int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    int retorno = ERROR;
	int id;
	int lastId;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	int esHeader = 1;
	int i;
	FILE* pFile;
	pFile = fopen(path,"w");
    if(pFile != NULL && pArrayListJugador != NULL){
    	Jugador* jugadorAux;
    	for(i = 0; i < ll_len(pArrayListJugador); i++){
    		jugadorAux = ll_get(pArrayListJugador,i);
    		jug_getId(jugadorAux,&id);
    		jug_getNombreCompleto(jugadorAux,nombreCompleto);
    		jug_getPosicion(jugadorAux,posicion);
    		jug_getNacionalidad(jugadorAux,nacionalidad);
    		jug_getEdad(jugadorAux,&edad);
    		jug_getSIdSeleccion(jugadorAux,&idSeleccion);

    		if(esHeader == 1){
    			fprintf(pFile,"%s,%s,%s,%s,%s,%s\n","id","nombreCompleto","edad","posicion","nacionalidad","idSeleccion");
    			esHeader = 0;
    		}
    		fprintf(pFile,"%d,%s,%d,%s,%s,%d\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
    		retorno =0;
    	}
    	//ya que recorri todo el array obtengo el ultimo id y lo guardo
    	jug_getId(jugadorAux,&lastId);
    	controller_guardarIdModoBinario("lastId.bin",&lastId);
    	printf("Se ha guardado el archivo csv con exito\n");
    	fclose(pFile);
    }
    return retorno;
}


int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = ERROR;
	FILE* pFile;
	pFile = fopen(path,"r");
	if(pFile != NULL){
		if(parser_SeleccionFromText(pFile ,pArrayListSeleccion) != ERROR){
			puts("Se pudo cargar el archivo csv con exito\n");
			retorno = 0;
		}
		else{
			puts("Error al abrir el  archivo csv\n");
		}
	}
	fclose(pFile);
    return retorno;
}


int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
	//funcion no desarrollada porque no se pedia en el TP
	return 1;
}


int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
    int retorno = ERROR;
    int i;
    if(pArrayListSeleccion != NULL){
    	Seleccion* pSeleccion;
    	int len = ll_len(pArrayListSeleccion);
    	if(len > 0){
    		printf("\n *********** LISTADO DE SELECCIONES**********\n");
    		printf("|%*s|%*s|%*s|%*s|\n",10,"Id",30,"Pais",30,"Confederacion",12,"Convocados");
    		for(i = 0; i < len; i++){
    			pSeleccion = ll_get(pArrayListSeleccion,i);
    			mostrarInfoSeleccion(pSeleccion);
    			retorno =0;
    		}
    	}
    }
    return retorno;
}


int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = ERROR;
		int orden;
		int flag;
		char opcionMenu ='z';
		if(pArrayListSeleccion !=NULL){
			mostrarMenuOrdenarYlistar();
			utn_getNombre(&opcionMenu,2,"Ingrese la opcion deseada:\n","Reingrese la opcion deseada: \n",3);
			strMayuscula(&opcionMenu);
			            	while(opcionMenu != 'E'){
			            		utn_getNumero(&orden,"Seleccione el orden [0 - Descendente/1 - Ascedente]: \n","Reseleccione el orden [0 - Descendente/1 - Ascedente]: \n",0,1,3);
			            		switch(opcionMenu){
			            		case 'B':
									flag = ll_sort(pArrayListSeleccion,seleccion_sortConfederacion,orden);
			            			controller_listarSelecciones(pArrayListSeleccion);
			            			printf("resultado ll_sort: %d\n",flag);
			            			break;
			            		}
			            		mostrarMenuOrdenarYlistar();
			            		utn_getNombre(&opcionMenu,2,"Ingrese la opcion deseada:\n","Reingrese la opcion deseada: \n",3);
			            	    strMayuscula(&opcionMenu);
			            	}
		}
	    return retorno;
}


int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    int retorno = ERROR;
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
	int esHeader = 1;
	int i;
	FILE* pFile;
	pFile = fopen(path,"w");
    if(pFile != NULL && pArrayListSeleccion != NULL){
    	Seleccion* SeleccionAux;
    	for(i = 0; i < ll_len(pArrayListSeleccion); i++){
    		SeleccionAux = ll_get(pArrayListSeleccion,i);
    		selec_getId(SeleccionAux,&id);
    		selec_getPais(SeleccionAux,pais);
    		selec_getConfederacion(SeleccionAux,confederacion);
    		selec_getConvocados(SeleccionAux,&convocados);

    		if(esHeader == 1){
    			fprintf(pFile,"%s,%s,%s,%s\n","id","pais","confederacion","convocados");
    			esHeader = 0;
    		}
    		fprintf(pFile,"%d,%s,%s,%d\n",id,pais,confederacion,convocados);
    		retorno =0;

    	}
    	printf("Se ha guardado el archivo csv con exito\n");
    	fclose(pFile);
    }
    return retorno;
}


int controller_convocarJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
	int retorno = ERROR;
	int indexJugador, idJugador, indexSeleccion, idSeleccion, idSeleccionJug;
	int Jugconvocados;
	char nombre[100];
	char pais[30];
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		Jugador* jugadorBuscado;
		controller_listarJugadores(pArrayListJugador);
		utn_getNumero(&idJugador,"Ingrese el id del jugador a convocar: \n","Reingrese el id del jugador a convocar: \n",1,2000,3);
		indexJugador = buscarJugadorPorId(pArrayListJugador,idJugador);
		while(indexJugador == ERROR){
			utn_getNumero(&idJugador,"Ingrese el id del jugador a convocar: \n","Reingrese el id del jugador a convocar: \n",1,2000,3);
		     indexJugador = buscarJugadorPorId(pArrayListJugador,idJugador);
		}
		jugadorBuscado = ll_get(pArrayListJugador,indexJugador);
		if(jugadorBuscado != NULL){
			Seleccion* seleccionBuscada;
			controller_listarSelecciones(pArrayListSeleccion);
			utn_getNumero(&idSeleccion,"Ingrese el id de la seleccion: \n","Reingrese el id de la seleccion: \n",1,32,3);
			indexSeleccion = buscarSeleccionPorId(pArrayListSeleccion,idSeleccion);
			while(indexSeleccion == ERROR){
				utn_getNumero(&idSeleccion,"Ingrese el id de la seleccion: \n","Reingrese el id de la seleccion: \n",1,32,3);
			    indexSeleccion = buscarSeleccionPorId(pArrayListSeleccion,idSeleccion);
			}
			seleccionBuscada = ll_get(pArrayListSeleccion,indexSeleccion);
			selec_getConvocados(seleccionBuscada,&Jugconvocados);
			jug_getSIdSeleccion(jugadorBuscado,&idSeleccionJug);

			//if(indexSeleccion != ERROR && Jugconvocados <22 && jugadorBuscado->idSeleccion == 0){
			if(indexSeleccion != ERROR && Jugconvocados <22 && idSeleccionJug== 0){
				jug_setIdSeleccion(jugadorBuscado,idSeleccion);
				Jugconvocados++;
				selec_setConvocados(seleccionBuscada,Jugconvocados);
				jug_getNombreCompleto(jugadorBuscado,nombre);
				selec_getPais(seleccionBuscada,pais);
				printf("Se ha convocado al jugador: %s a la seleccion de: %s\n",nombre,pais);
				retorno =0;
			}
		}
	}
	return retorno;
}


int controller_quitarDeLaSeleccion(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion){
	int retorno = ERROR;
	int idJugador, indexJugador, indexSeleccion, idSeleccion, convocados;
	char opcion ='z';
	char nombre[100];
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL){
		controller_listarConvocados(pArrayListJugador,pArrayListSeleccion);
		Jugador* jugadorBuscado;
		utn_getNumero(&idJugador,"Ingrese el id del jugador a quitar: \n","Reingrese el id del jugador a quitar: \n",1,2000,3);
		indexJugador = buscarJugadorPorId(pArrayListJugador,idJugador);
		jugadorBuscado = ll_get(pArrayListJugador,indexJugador);
		if(indexJugador != ERROR){
			utn_getNombre(&opcion,2,"Desea quitar de la seleccion al jugador seleccionado [s/n]\n",
					"Desea quitar de la seleccion al jugador seleccionado [s/n]n",3);
			strMinuscula(&opcion);
			while(opcion != 's' && opcion != 'n'){
				utn_getNombre(&opcion,2,"Desea quitar de la seleccion al jugador  [s/n]\n",
									"Desea quitar de la seleccion al jugador [s/n]\n",3);
				strMinuscula(&opcion);
			}
				if(opcion == 's'){
					Seleccion* seleccionBuscada;
					jug_getSIdSeleccion(jugadorBuscado,&idSeleccion);
					indexSeleccion = buscarSeleccionPorId(pArrayListSeleccion,idSeleccion);
					seleccionBuscada = ll_get(pArrayListSeleccion,indexSeleccion);
					selec_getConvocados(seleccionBuscada,&convocados);
					convocados--;
					selec_setConvocados(seleccionBuscada,convocados);
					idSeleccion =0;
					jug_setIdSeleccion(jugadorBuscado,idSeleccion);
					jug_getNombreCompleto(jugadorBuscado,nombre);
					printf("Se ha quitado de la seleccion al jugador: %s\n",nombre);
					retorno = 0;
				}
		}
	}
	return retorno;
}


int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador){
	int retorno = ERROR;
	FILE *pFile;
	if(path != NULL && pArrayListJugador != NULL){
		Jugador* jugadorAuxiliar;
		pFile = fopen(path,"wb");
		int i;
		for(i= 0; i < ll_len(pArrayListJugador);i++){
			jugadorAuxiliar = ll_get(pArrayListJugador,i);
			fwrite(jugadorAuxiliar,sizeof(Jugador),1,pFile);
		}
		fclose(pFile);
		printf("Se han guardado el archivo binario con exito\n");
		retorno =0;
	}
	return retorno;
}


int controller_guardarJugadoresConvocadosPorConfederacion(char* path , LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugadorConvConf){
	int retorno = ERROR;
	int idSeleccion,idSelJugador,i,j;
	char confederacion[30];
	char confederacionBuscada[30];
	if(path != NULL && pArrayListJugador != NULL && pArrayListSeleccion != NULL && pArrayListJugadorConvConf != NULL){
		mostrarListadoConfederaciones();
		utn_getNombre(confederacionBuscada,30,"Ingrese el nombre de la confederacion: \n","Reingrese el nombre de la confederacion\n",3);
		strMayuscula(confederacionBuscada);
		while(strcmp(confederacionBuscada,"AFC") != 0 && strcmp(confederacionBuscada,"CONCACAF") != 0 &&  strcmp(confederacionBuscada,"CONMEBOL") != 0
				&& strcmp(confederacionBuscada,"CAF") != 0  && strcmp(confederacionBuscada,"UEFA") != 0){
			mostrarListadoConfederaciones();
			utn_getNombre(confederacionBuscada,30,"Ingrese el nombre de la confederacion: \n","Reingrese el nombre de la confederacion\n",3);
			strMayuscula(confederacionBuscada);
		}

		Seleccion* auxSeleccion;
		Jugador* auxJugador;
		for(i =0; i <ll_len(pArrayListSeleccion);i++){
			auxSeleccion = ll_get(pArrayListSeleccion,i);
			selec_getConfederacion(auxSeleccion,confederacion);
			selec_getId(auxSeleccion,&idSeleccion);
				if(strcmp(confederacion,confederacionBuscada) == 0){;
					for(j = 0; j < ll_len(pArrayListJugador); j++){
						auxJugador = ll_get(pArrayListJugador,j);
						jug_getSIdSeleccion(auxJugador,&idSelJugador);
						if(idSelJugador == idSeleccion){
							ll_add(pArrayListJugadorConvConf,auxJugador);
						}
				}
			}
		}
		 controller_listarConvocados(pArrayListJugador,pArrayListSeleccion);
			controller_guardarJugadoresModoBinario(path,pArrayListJugadorConvConf);
			printf("Se han guardado los jugadores convocados %s con exito\n",confederacionBuscada);
			retorno = 0;

	}
	return retorno;
}







