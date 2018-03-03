
// prefix mfGenericAppHttp

// Intefaz de programa para modulos 0 de zHttpServer
// Este programa no se añade a la compilacion y no se testea

// NECESITA una funcion externa : mfGenericAppHttp(MHD_Connection_t *connection,mfGeneric_t *data )

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include </usr/local/include/microhttpd.h>
#include "spaServer.h"

#include "mfGeneric.h"

// Evento de datos de la peticion HTTP

int appMfGenericDataCB(mfGeneric_t *data, char *key, char *value)
{
// appLoginData_t *data = (appLoginData_t *) dataCls;

// Set key and value

mfGenericGetKeys( data,key,value);

}


// Evento final de la peticion/respueta HTTP

appMfGenericEndCB(mfGeneric_t *data)
{
// free Data
if (data != NULL)
   free(data);


}

/*
 * Evento de proceso de la peticion ya recibida
 * Exige una funcion externa que procese la peticion mfGenericAppHttp(connection,data);
*/

int appMfGenericProcesoCB(MHD_Connection_t *connection,mfGeneric_t *data )
{
return mfGenericAppHttp(connection,data);
//return spaServerResponseOK(connection
//                , MHD_HTTP_OK
//                , "de puta madre");

}


// Evento de inicio de la peticion

int appMfGenericInitCB(void (**appDataCB)()
        , void (**appProcesoCB)()
        , void (**appEndCB)()
        , void (**dataCls)() )
{

// inicia and set Closure

mfGeneric_t  *data=malloc(sizeof( mfGeneric_t ));
memset(data,0,sizeof( mfGeneric_t ));
*dataCls=(void *)data;

// set CallBack Events

  *appDataCB= (void (*)())   appMfGenericDataCB;
  *appProcesoCB=(void (*)()) appMfGenericProcesoCB;
  *appEndCB=(void (*)())     appMfGenericEndCB;

return(0);
}

