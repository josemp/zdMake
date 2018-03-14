
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "mfB.h"
#include "metaTab.h"
#include "mfGeneric.h"

int mfGenericLee(char *nombreFichero,mfGeneric_t *mfGeneric);
void quitaCyponO(char *file);

metaTab_t *getMetaTab_mfB();
int mfBLee(char *nombre, mfB_t *mfB);
int _mfBGeneraMakefile(mfB_t *mfB,char *nombreFicheroOutput );


int mfBGeneraMakefile(char *nombreFicheroInput, char *nombreFicheroOutput)
{
mfB_t mfB;
memset(&mfB,0, sizeof(mfB_t));
int ret=mfBLee(nombreFicheroInput,&mfB);
if (ret<0) return(ret);
ret=_mfBGeneraMakefile(&mfB,nombreFicheroOutput);
// Por ahora no controlo el error
return(0);



}
int _mfBGeneraMakefile(mfB_t *mfB,char *nombreFicheroOutput )
{
int i,j;
mfGeneric_t mfGeneric;
int ret;

char tabFile[200];
char objetoFile[200];
char includeFile[200];
FILE *ou= fopen(nombreFicheroOutput,"w");
if (!ou) return(-1);
fprintf(ou,"# nombre de la biblioteca \n\n");

fprintf(ou,"NAME         := %s\n",mfB->name);
fprintf(ou,"LIBRARY_NAME := lib$(NAME).a\n");


fprintf(ou,"\n# Lista de objetos e includes del proyecto\n\n");


// Objetos

fprintf(ou,"OBJETOS  := "); 

// De los directorios vamos a sacar los objetos del make.tab
for(i=0;i<20;i++)
{
   if (strlen(mfB->directorios[i])==0) continue;
   // Escogemos el directorio y leemos el make.tab para ver los objetos que necesitaos
   sprintf(tabFile,"%s/make.tab",mfB->directorios[i]);
   memset(&mfGeneric,0,sizeof(mfGeneric_t));
   if (mfGenericLee(tabFile,&mfGeneric)<0) continue;
   for (j=0;j<20;j++)
    {
       if (strlen(mfGeneric.fuentes[j])<3) continue;
     sprintf(objetoFile,"%s/%s",mfB->directorios[i],mfGeneric.fuentes[j]);
     quitaCyponO(objetoFile);
     fprintf(ou," %s",objetoFile);
    }
}
fprintf(ou,"\n\n");



// includes para instalar

fprintf(ou,"INCLUDES  := "); 

// De los directorios vamos a sacar los objetos del make.tab
for(i=0;i<20;i++)
{
   if (strlen(mfB->directorios[i])==0) continue;
   // Escogemos el directorio y leemos el make.tab para ver los objetos que necesitaos
   sprintf(tabFile,"%s/make.tab",mfB->directorios[i]);

   memset(&mfGeneric,0,sizeof(mfGeneric_t));
   if (mfGenericLee(tabFile,&mfGeneric)<0) continue;
   for (j=0;j<20;j++)
    {
       if (strlen(mfGeneric.includesForInstall[j])<3) continue;
     sprintf(includeFile,"%s/%s",mfB->directorios[i],mfGeneric.includesForInstall[j]);
     fprintf(ou," %s",includeFile);
    }
}
for(i=0;i<20;i++)
   if (strlen(mfB->includesForInstall[i])!=0)
      fprintf(ou," %s",mfB->includesForInstall[i]);

fprintf(ou,"\n\n");
fprintf(ou,"\n# install directorios\n\n");

fprintf(ou,"OUTPUT_LIB_INSTALL ?= %s\n",mfB->outputLibInstall);
fprintf(ou,"OUTPUT_INCLUDE_INSTALL ?= %s\n",mfB->outputIncludeInstall);



fprintf(ou,"\n# -------- RULES ------------------\n\n");

fprintf(ou,"all: compila  $(INCLUDES) $(LIBRARY_NAME)\n\n");

fprintf(ou,"$(LIBRARY_NAME): $(OBJETOS)\n");
fprintf(ou,"\t- rm -f $@\n");
fprintf(ou,"\tar -rf $@ $^\n");

fprintf(ou,"\ncompila:\n");

// Cada directorio un make

for(i=0;i<20;i++)
{
   if (strlen(mfB->directorios[i])==0) continue;
   fprintf(ou,"\t$(MAKE) -C %s\n",mfB->directorios[i]);
}

fprintf(ou,"\nclean:\n");

// Cada directorio un make

for(i=0;i<20;i++)
{
   if (strlen(mfB->directorios[i])==0) continue;
   fprintf(ou,"\t$(MAKE) -C %s clean\n",mfB->directorios[i]);
}




fprintf(ou,"install:\n");
fprintf(ou,"\t- mkdir -p $(OUTPUT_LIB_INSTALL)\n");
fprintf(ou,"\t- mkdir -p $(OUTPUT_INCLUDE_INSTALL)\n");
fprintf(ou,"\tcp $(LIBRARY_NAME) $(OUTPUT_LIB_INSTALL)\n");
fprintf(ou,"\tcp $(INCLUDES) $(OUTPUT_INCLUDE_INSTALL)\n");



fclose(ou);
return(0);


}

int mfBGeneraTabla(char *namefile,char *tipo,char *version)
{
int i,j;
itemChar_t *itemChar;
itemLista_t *itemLista;
itemObjeto_t *itemObjeto;
metaTab_t *tabla=getMetaTab_mfB();
//char namefile[200];
//sprintf(namefile,"%s.tab",nombre);
FILE *ou = fopen(namefile,"w");
if (!ou) return(-1);


for (i=0;i<tabla->numItems;i++)
{
 if (tabla->item[i].tipo=='C')
  {
      itemChar=tabla->item[i].data;
      if (strcmp(itemChar->nombre,"tipoTabla")==0)
          fprintf(ou,"%s: %s\n",itemChar->nombre,tipo);
      else if (strcmp(itemChar->nombre,"versionTabla")==0)
          fprintf(ou,"%s: %s\n",itemChar->nombre,version);
      else    
          fprintf(ou,"%s: ...\n",itemChar->nombre);

  }

 if (tabla->item[i].tipo=='L')
  {
      itemLista=tabla->item[i].data;
      fprintf(ou,"%s: ... : ...\n",itemLista->nombre);
  }

 if (tabla->item[i].tipo=='O')
    {
      itemObjeto=tabla->item[i].data;
      fprintf(ou,"%s",itemObjeto->nombre);
      for (j=0;j<itemObjeto->numItems;j++)
       {
         fprintf(ou,":%s",itemObjeto->item[j].nombre);
       }
      fprintf(ou,"\n");

    }
/*
 if (tabla->item[i].tipo=='Y')
    {
      itemLista=tabla->item[i].data;
      fprintf(ou,"%s: miCb : eventoCallBack \n",itemLista->nombre);
    }
*/
}
fclose(ou);
return(0);

}
void quitaCyponO(char *file)
{
 if (strlen(file)>2)
     if (file[strlen(file)-2]=='.' && file[strlen(file)-1]=='c')
      file[strlen(file)-1]='o';
}

