/**
  @file leeMetaTab.c
  @brief hacer lista de sources de programa posiblemente para hacer una libreria
  @author Jose Miguel Parra
  @date 3/2018
  
  Para lograr esto, he modificado la tabla mfGeneric para que incluya\n
  la etiqueta fuentes.
  
  El objetivo final es que de una lista de ficheros make.tab consigamos una lista de todos los fuentes

*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void quitaCyponO(string *file);
lista_t * fuentesFromTabla(char *tabla)
{

}
lista_t *lista leeGenericFuentes(char *directoy,lista_t *lista)
{
char tabFile[200];
char fuenteFile[200];
mfGeneric_t mfGeneric;
sprintf(tabFile,"%s/make.tab",directory);
int ret=mfGenericLee(nombreFichero,&mfGeneric);
if (ret<0) return(ret);
int i;
for (i=0;i<20;i++)
{
 if (strlen(mfGeneric->fuentes[i])>2)
   {
     sprintf(fuenteFile,"%s/%s",directory,mfGeneric->fuentes[i]);
     quitaCyponO(fuenteFile);
     listaAdd(lista,fuenteFile);
   }
   
return(0);

}
}
/**
 Cambia el source .c por .o



*/
void quitaCyponO(string *file)
{
 if (strlen(file)>2)
     if (file[strlen(file)-2]=='.' && file[strlen(file)-1]=='c')
      file[strlen(file)-1]='o';
}
