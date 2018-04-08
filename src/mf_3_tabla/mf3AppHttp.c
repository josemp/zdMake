
// prefix mf3AppHttp

// Intefaz de programa para modulos 0 de zHttpServer
// Este programa no se añade a la compilacion y no se testea

// NECESITA una funcion externa : mf3AppHttp(MHD_Connection_t *connection,mf3_t *data )

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include </usr/local/include/microhttpd.h>
#include "spaServer.h"

#include "mf3.h"

// Evento de datos de la peticion HTTP

int appMf3DataCB(mf3_t *data, char *key, char *value)
{
// appLoginData_t *data = (appLoginData_t *) dataCls;

// Set key and value

mf3GetKeys( data,key,value);

}


// Evento final de la peticion/respueta HTTP

appMf3EndCB(mf3_t *data)
{
// free Data
if (data != NULL)
   free(data);


}

/*
 * Evento de proceso de la peticion ya recibida
 * Exige una funcion externa que procese la peticion mf3AppHttp(connection,data);
*/

int appMf3ProcesoCB(MHD_Connection_t *connection,mf3_t *data )
{
return mf3AppHttp(connection,data);
//return spaServerResponseOK(connection
//                , MHD_HTTP_OK
//                , "de puta madre");

}


// Evento de inicio de la peticion

int appMf3InitCB(void (**appDataCB)()
        , void (**appProcesoCB)()
        , void (**appEndCB)()
        , void (**dataCls)() )
{

// inicia and set Closure

mf3_t  *data=malloc(sizeof( mf3_t ));
memset(data,0,sizeof( mf3_t ));
*dataCls=(void *)data;

// set CallBack Events

  *appDataCB= (void (*)())   appMf3DataCB;
  *appProcesoCB=(void (*)()) appMf3ProcesoCB;
  *appEndCB=(void (*)())     appMf3EndCB;

return(0);
}

