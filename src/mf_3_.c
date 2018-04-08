
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <libgen.h>
#include "mf3.h"
#include "metaTab.h"
#include "mfGeneric.h"
#include "zdMakeTabUtil.h"

metaTab_t *getMetaTab_mf3();
int mf3Lee(char *nombre, mf3_t *mf3);
int _mf3GeneraMakefile(mf3_t *mf3,char *nombreFicheroOutput );
int mfGenericLee(char *nombreFichero,mfGeneric_t *mfGeneric);


int mf3GeneraMakefile(char *nombreFicheroInput, char *nombreFicheroOutput)
{
mf3_t mf3;
memset(&mf3,0, sizeof(mf3_t));
int ret=mf3Lee(nombreFicheroInput,&mf3);
if (ret<0) return(ret);
ret=_mf3GeneraMakefile(&mf3,nombreFicheroOutput);
// Por ahora no controlo el error
return(0);



}
int _mf3GeneraMakefile(mf3_t *mf3,char *nombreFicheroOutput )
{
int i;
char tabFile[200];
mfGeneric_t mfGeneric;
printf("al ataquer\n");
FILE *ou= fopen(nombreFicheroOutput,"w");
if (!ou) return(-1);
fprintf(ou,"# output program\n\n");

fprintf(ou,"NAME    := %s\n",mf3->name);

fprintf(ou,"\n# fuentes e includes del proyecto\n\n");

fprintf(ou,"FUENTES  := "); 
for(i=0;i<20;i++)
   if (strlen(mf3->fuentes[i])!=0)
      fprintf(ou," %s",mf3->fuentes[i]);
fprintf(ou,"\n\n");

fprintf(ou,"INCLUDES :=");
for(i=0;i<20;i++)
   if (strlen(mf3->includes[i])!=0)
      fprintf(ou," %s",mf3->includes[i]);
fprintf(ou,"\n");

fprintf(ou,"\n# directorios de includes externos\n\n");

fprintf(ou,"OUTHER_DIR_INCLUDE :=");
// los proyectos tambien tienen que ser directorios de include
for(i=0;i<20;i++)
{
   char path[201];
 
   if (strlen(mf3->proyectos[i])<1) continue; // un proyecto puede ser el "."
   strcpy(path,mf3->proyectos[i]);
      fprintf(ou," %s",dirname(path));
}

for(i=0;i<20;i++)
   if (strlen(mf3->outherDirInclude[i])!=0)
      fprintf(ou," %s",mf3->outherDirInclude[i]);
fprintf(ou,"\n\n");

fprintf(ou,"OUTHER_DIR_LIB:=");
// los proyectos tambien tienen que ser directorios de LIB
for(i=0;i<20;i++)
{
   char path[201];
   strcpy(path,mf3->proyectos[i]);
   if (strlen(mf3->proyectos[i])<1) continue; // un proyecto puede ser el "."
      fprintf(ou," %s",dirname(path));
}
for(i=0;i<20;i++)
   if (strlen(mf3->outherDirLib[i])!=0)
      fprintf(ou," %s",mf3->outherDirLib[i]);
fprintf(ou,"\n");

fprintf(ou,"\n# librerias utilizadas\n\n");

fprintf(ou,"OUTHER_LIBS:= ");

// De los proyectos vamos a sacar las librerias necesarias
for(i=0;i<20;i++)
{
   if (strlen(mf3->proyectos[i])==0) continue;
   // Escogemos el nombre de la libreria
   //sprintf(tabFile,"%s/make.tab",mf3->proyectos[i]);
   memset(&mfGeneric,0,sizeof(mfGeneric_t));
   if (mfGenericLee(mf3->proyectos[i],&mfGeneric)<0) continue;
     fprintf(ou," -l%s",mfGeneric.name);
}

for(i=0;i<20;i++)
   if (strlen(mf3->outherLibs[i])!=0)
      fprintf(ou," %s",mf3->outherLibs[i]);
fprintf(ou,"\n");


//LIBRERIAS DE LAS QUE DEPENDE TEST, SI ESTAS LIBRERIAS CAMBIAN SE COMPILARA TEST, SI ESTAS LIBRERIAS NO EXISTEN, ERROR EN COMPILACION

fprintf(ou,"DEPEND_LIBS:= ");
for(i=0;i<20;i++)
{
   if (strlen(mf3->proyectos[i])==0) continue;

   // Escogemos el nombre de la libreria
   sprintf(tabFile,"%s/make.tab",mf3->proyectos[i]);
   memset(&mfGeneric,0,sizeof(mfGeneric_t));
   if (mfGenericLee(tabFile,&mfGeneric)<0) continue;
     fprintf(ou," %s/lib%s.a",mf3->proyectos[i],mfGeneric.name);
}
fprintf(ou,"\n");


fprintf(ou,"\n# variables intermedias\n\n");


fprintf(ou,"CFLAGS = $(OUTHER_DIR_INCLUDE:%%=-I%%)\n");
fprintf(ou,"LDFLAGS = $(OUTHER_DIR_LIB:%%=-L%%)\n");
fprintf(ou,"LDLIBS =     $(OUTHER_LIBS)\n");
fprintf(ou,"OBJETOS      := $(FUENTES:%%.c=%%.o)\n");
fprintf(ou,"\n# -------- RULES ------------------\n\n");
fprintf(ou,"all: compila  $(NAME)\n");
fprintf(ou,"$(OBJETOS):$(FUENTES) $(INCLUDES) $(DEPEND_LIBS)\n");
fprintf(ou,"$(NAME): $(OBJETOS)\n");
fprintf(ou,"\t$(CC) $(LDFLAGS)  $(OBJETOS) $(LDLIBS) -o $(NAME)\n");

// Compila
fprintf(ou,"\ncompila:\n");

// Cada directorio un make

for(i=0;i<20;i++)
{
   if (strlen(mf3->proyectos[i])==0) continue;
   char sufijoData[200];
   char *sufijo;
   char path[201];
   strcpy(path,mf3->proyectos[i]);

   sufijo=pathSufijo(mf3->proyectos[i],"libs",sufijoData);
   if (strlen(sufijo)==0)
    fprintf(ou,"\t$(MAKE) -C %s \n",dirname(path),sufijo);
   else
   fprintf(ou,"\t$(MAKE) -C %s -f makefile%s\n",dirname(path),sufijo);
}













fprintf(ou,"\nclean:\n");
fprintf(ou,"\t - rm -f $(OBJETOS) $(NAME)\n");

// Cada proyecto dependiente un clean

for(i=0;i<20;i++)
{
   if (strlen(mf3->proyectos[i])==0) continue;
   char sufijoData[200];
   char *sufijo;
   char path[201];
   strcpy(path,mf3->proyectos[i]);

   sufijo=pathSufijo(mf3->proyectos[i],"libs",sufijoData);
   if (strlen(sufijo)==0)
    fprintf(ou,"\t$(MAKE) -C %s clean\n",dirname(path),sufijo);
   else
    fprintf(ou,"\t$(MAKE) -C %s -f makefile%s clean\n",dirname(path),sufijo);
}


// Install
fprintf(ou,"\ninstall:\n");
if (strlen(mf3->outputInstall)>0)
fprintf(ou,"\tcp $(NAME) %s\n",mf3->outputInstall);

// Cada proyecto dependiente un install

for(i=0;i<20;i++)
{
   if (strlen(mf3->proyectosInstall[i])==0) continue;
   char sufijoData[200];
   char *sufijo;
   char path[201];
   strcpy(path,mf3->proyectosInstall[i]);

   sufijo=pathSufijo(mf3->proyectosInstall[i],"libs",sufijoData);
   if (strlen(sufijo)==0)
    fprintf(ou,"\t$(MAKE) -C %s install\n",dirname(path),sufijo);
   else
    fprintf(ou,"\t$(MAKE) -C %s -f makefile%s install\n",dirname(path),sufijo);
}



fclose(ou);
return(0);


}

int mf3GeneraTabla(char *namefile,char *tipo,char *version)
{
int i,j;
itemChar_t *itemChar;
itemLista_t *itemLista;
itemObjeto_t *itemObjeto;
metaTab_t *tabla=getMetaTab_mf3();
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
      fprintf(ou,"#%s\n",itemLista->descri);
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

