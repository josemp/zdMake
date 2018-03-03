
// prefix mf2AppHttp

// Intefaz de programa para modulos 0 de zHttpServer
// Este programa no se añade a la compilacion y no se testea

// NECESITA una funcion externa : mf2AppHttp(MHD_Connection_t *connection,mf2_t *data )

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include </usr/local/include/microhttpd.h>
#include "spaServer.h"

#include "mf2.h"

// Evento de datos de la peticion HTTP

int appMf2DataCB(mf2_t *data, char *key, char *value)
{
// appLoginData_t *data = (appLoginData_t *) dataCls;

// Set key and value

mf2GetKeys( data,key,value);

}


// Evento final de la peticion/respueta HTTP

appMf2EndCB(mf2_t *data)
{
// free Data
if (data != NULL)
   free(data);


}

/*
 * Evento de proceso de la peticion ya recibida
 * Exige una funcion externa que procese la peticion mf2AppHttp(connection,data);
*/

int appMf2ProcesoCB(MHD_Connection_t *connection,mf2_t *data )
{
return mf2AppHttp(connection,data);
//return spaServerResponseOK(connection
//                , MHD_HTTP_OK
//                , "de puta madre");

}


// Evento de inicio de la peticion

int appMf2InitCB(void (**appDataCB)()
        , void (**appProcesoCB)()
        , void (**appEndCB)()
        , void (**dataCls)() )
{

// inicia and set Closure

mf2_t  *data=malloc(sizeof( mf2_t ));
memset(data,0,sizeof( mf2_t ));
*dataCls=(void *)data;

// set CallBack Events

  *appDataCB= (void (*)())   appMf2DataCB;
  *appProcesoCB=(void (*)()) appMf2ProcesoCB;
  *appEndCB=(void (*)())     appMf2EndCB;

return(0);
}

