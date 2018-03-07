
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#include "mf1.h"


int mf12JsonFile(char *nombreFichero,mf1_t *mf1)
{
FILE *ou = fopen(nombreFichero,"w");
if (!ou) return(-1);
mf12Json(ou , mf1);
fclose(ou);
return(0);
}
size_t mf12JsonBuf(char **buf,mf1_t *mf1)
{
size_t size=0;
FILE *ou=open_memstream (buf, &size);
if (!ou) return(-1);
mf12Json(ou, mf1 );
fclose(ou);
}

mf12Json(FILE *ou,mf1_t *mf1)
{
int count=0;
int i;
fprintf(ou,"{\n");


if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"tipoTabla\":\"%s\"",mf1->tipoTabla);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"versionTabla\":\"%s\"",mf1->versionTabla);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"name\":\"%s\"",mf1->name);
count++;






if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"fuentes\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf1->fuentes[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"includes\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf1->includes[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"proyectos\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf1->proyectos[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"outherDirInclude\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf1->outherDirInclude[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"outherDirLib\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf1->outherDirLib[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"outherLibs\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf1->outherLibs[i]);
 }
fprintf(ou,"]");
count++;



fprintf(ou,"\n}");

}



// Utilidades para generar la lista

mf1List2Json(FILE *ou,mf1Lista_t *mf1)
{
int i;
fprintf(ou,"[\n");
for (i=0;i<mf1->num;i++)
{
 if (i>0)
  fprintf(ou,",");
 mf12Json(ou,&mf1->data[i]);
}


fprintf(ou,"]\n");
}
int mf1List2JsonFile(char *nombreFichero,mf1Lista_t *mf1)
{
FILE *ou = fopen(nombreFichero,"w");
if (!ou) return(-1);
mf1List2Json(ou , mf1);
fclose(ou);
return(0);
}
size_t mf1List2JsonBuf(char **buf,mf1Lista_t *mf1)
{
size_t size=0;
FILE *ou=open_memstream (buf, &size);
if (!ou) return(-1);
mf1List2Json(ou, mf1);
fclose(ou);
}

