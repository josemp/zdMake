
// prefix mfBAppHttp

// Intefaz de programa para modulos 0 de zHttpServer
// Este programa no se añade a la compilacion y no se testea

// NECESITA una funcion externa : mfBAppHttp(MHD_Connection_t *connection,mfB_t *data )

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include </usr/local/include/microhttpd.h>
#include "spaServer.h"

#include "mfB.h"

// Evento de datos de la peticion HTTP

int appMfBDataCB(mfB_t *data, char *key, char *value)
{
// appLoginData_t *data = (appLoginData_t *) dataCls;

// Set key and value

mfBGetKeys( data,key,value);

}


// Evento final de la peticion/respueta HTTP

appMfBEndCB(mfB_t *data)
{
// free Data
if (data != NULL)
   free(data);


}

/*
 * Evento de proceso de la peticion ya recibida
 * Exige una funcion externa que procese la peticion mfBAppHttp(connection,data);
*/

int appMfBProcesoCB(MHD_Connection_t *connection,mfB_t *data )
{
return mfBAppHttp(connection,data);
//return spaServerResponseOK(connection
//                , MHD_HTTP_OK
//                , "de puta madre");

}


// Evento de inicio de la peticion

int appMfBInitCB(void (**appDataCB)()
        , void (**appProcesoCB)()
        , void (**appEndCB)()
        , void (**dataCls)() )
{

// inicia and set Closure

mfB_t  *data=malloc(sizeof( mfB_t ));
memset(data,0,sizeof( mfB_t ));
*dataCls=(void *)data;

// set CallBack Events

  *appDataCB= (void (*)())   appMfBDataCB;
  *appProcesoCB=(void (*)()) appMfBProcesoCB;
  *appEndCB=(void (*)())     appMfBEndCB;

return(0);
}

