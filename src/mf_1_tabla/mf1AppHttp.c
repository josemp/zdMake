
// prefix mf1AppHttp

// Intefaz de programa para modulos 0 de zHttpServer
// Este programa no se añade a la compilacion y no se testea

// NECESITA una funcion externa : mf1AppHttp(MHD_Connection_t *connection,mf1_t *data )

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include </usr/local/include/microhttpd.h>
#include "spaServer.h"

#include "mf1.h"

// Evento de datos de la peticion HTTP

int appMf1DataCB(mf1_t *data, char *key, char *value)
{
// appLoginData_t *data = (appLoginData_t *) dataCls;

// Set key and value

mf1GetKeys( data,key,value);

}


// Evento final de la peticion/respueta HTTP

appMf1EndCB(mf1_t *data)
{
// free Data
if (data != NULL)
   free(data);


}

/*
 * Evento de proceso de la peticion ya recibida
 * Exige una funcion externa que procese la peticion mf1AppHttp(connection,data);
*/

int appMf1ProcesoCB(MHD_Connection_t *connection,mf1_t *data )
{
return mf1AppHttp(connection,data);
//return spaServerResponseOK(connection
//                , MHD_HTTP_OK
//                , "de puta madre");

}


// Evento de inicio de la peticion

int appMf1InitCB(void (**appDataCB)()
        , void (**appProcesoCB)()
        , void (**appEndCB)()
        , void (**dataCls)() )
{

// inicia and set Closure

mf1_t  *data=malloc(sizeof( mf1_t ));
memset(data,0,sizeof( mf1_t ));
*dataCls=(void *)data;

// set CallBack Events

  *appDataCB= (void (*)())   appMf1DataCB;
  *appProcesoCB=(void (*)()) appMf1ProcesoCB;
  *appEndCB=(void (*)())     appMf1EndCB;

return(0);
}

