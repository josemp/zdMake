
// prefix zdMakeTabAppHttp

// Intefaz de programa para modulos 0 de zHttpServer
// Este programa no se añade a la compilacion y no se testea

// NECESITA una funcion externa : zdMakeTabAppHttp(MHD_Connection_t *connection,zdMakeTab_t *data )

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include </usr/local/include/microhttpd.h>
#include "spaServer.h"

#include "zdMakeTab.h"

// Evento de datos de la peticion HTTP

int appZdMakeTabDataCB(zdMakeTab_t *data, char *key, char *value)
{
// appLoginData_t *data = (appLoginData_t *) dataCls;

// Set key and value

zdMakeTabGetKeys( data,key,value);

}


// Evento final de la peticion/respueta HTTP

appZdMakeTabEndCB(zdMakeTab_t *data)
{
// free Data
if (data != NULL)
   free(data);


}

/*
 * Evento de proceso de la peticion ya recibida
 * Exige una funcion externa que procese la peticion zdMakeTabAppHttp(connection,data);
*/

int appZdMakeTabProcesoCB(MHD_Connection_t *connection,zdMakeTab_t *data )
{
return zdMakeTabAppHttp(connection,data);
//return spaServerResponseOK(connection
//                , MHD_HTTP_OK
//                , "de puta madre");

}


// Evento de inicio de la peticion

int appZdMakeTabInitCB(void (**appDataCB)()
        , void (**appProcesoCB)()
        , void (**appEndCB)()
        , void (**dataCls)() )
{

// inicia and set Closure

zdMakeTab_t  *data=malloc(sizeof( zdMakeTab_t ));
memset(data,0,sizeof( zdMakeTab_t ));
*dataCls=(void *)data;

// set CallBack Events

  *appDataCB= (void (*)())   appZdMakeTabDataCB;
  *appProcesoCB=(void (*)()) appZdMakeTabProcesoCB;
  *appEndCB=(void (*)())     appZdMakeTabEndCB;

return(0);
}

