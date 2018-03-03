
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#include "zdMakeTab.h"


int zdMakeTab2JsonFile(char *nombreFichero,zdMakeTab_t *zdMakeTab)
{
FILE *ou = fopen(nombreFichero,"w");
if (!ou) return(-1);
zdMakeTab2Json(ou , zdMakeTab);
fclose(ou);
return(0);
}
size_t zdMakeTab2JsonBuf(char **buf,zdMakeTab_t *zdMakeTab)
{
size_t size=0;
FILE *ou=open_memstream (buf, &size);
if (!ou) return(-1);
zdMakeTab2Json(ou, zdMakeTab );
fclose(ou);
}

zdMakeTab2Json(FILE *ou,zdMakeTab_t *zdMakeTab)
{
int count=0;
int i;
fprintf(ou,"{\n");


if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"tipo\":\"%s\"",zdMakeTab->tipo);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"nombre\":\"%s\"",zdMakeTab->nombre);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"descripcion\":\"%s\"",zdMakeTab->descripcion);
count++;












fprintf(ou,"\n}");

}



// Utilidades para generar la lista

zdMakeTabList2Json(FILE *ou,zdMakeTabLista_t *zdMakeTab)
{
int i;
fprintf(ou,"[\n");
for (i=0;i<zdMakeTab->num;i++)
{
 if (i>0)
  fprintf(ou,",");
 zdMakeTab2Json(ou,&zdMakeTab->data[i]);
}


fprintf(ou,"]\n");
}
int zdMakeTabList2JsonFile(char *nombreFichero,zdMakeTabLista_t *zdMakeTab)
{
FILE *ou = fopen(nombreFichero,"w");
if (!ou) return(-1);
zdMakeTabList2Json(ou , zdMakeTab);
fclose(ou);
return(0);
}
size_t zdMakeTabList2JsonBuf(char **buf,zdMakeTabLista_t *zdMakeTab)
{
size_t size=0;
FILE *ou=open_memstream (buf, &size);
if (!ou) return(-1);
zdMakeTabList2Json(ou, zdMakeTab);
fclose(ou);
}

