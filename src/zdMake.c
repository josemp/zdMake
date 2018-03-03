/**
  @file leeMetaTab.c
  @brief Lectura de ficheros meta de configuracion z
  @author Jose Miguel Parra
  @date 8/2017
  sumario:
	  crea ficheros makeSufijo.tab y makefileSufijo
	  rellenando los campos de makeSufijo.tab crea un makefileSufijo
	  - hay distintos tipos de proyectos
  using:
  	zdMake -l -> Lista los tipos de proyectos
  	zdMake -s sufijo -> sufijo para los ficheros creados

  	zdMake   -> si no existe make.tab lo crea de tipo 1  
		-> si existe make.tab, crea el makefile	
   	zdMake tipo -> si no existe make.tab lo crea del tipo pedido
                      si exite make.tab el tipo es ignorado
 
  como añadir un nuevo tipo de proyecto:
  	- busca un nombre pequeño (maximo 10 chars) suponemos 
          que el nuevo tipo de proyecto es "Nombre"
        - Crea el directorio : mf_Nombre_tabla
        - Crea el descriptor mf_nombre_tabla/mfNombre.tab  
        - Utiliza zconfig1 mfNombre 
        - Compila la libreria generada por zconfig1
        - Crea mf_Nombre_.c y mf_Nombre_.h
        - En mf_Nombre_.c crea las funciones 
          mfNombreGeneraTabla,mfNombreGeneraMakefile
        - actualiza el makefile
        - actualiza zdMakeTabLista.c



  Notas:
	- Las tablas son creadas con zconfig1
        - La  tabla "zdMake" ./zdMakeTabla se carga en memoria
          en zdMakeTabLista.c
        - La tabla  "mfGeneric" supone que carga campos comunes
          a una o mas tablas de descripcion de proyectos
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <zdMakeTab.h>
#include "zdMakeTabLista.h"
#include "mfGeneric.h"
#include "mf_1_.h"

char version[10+1]="00.01";
char tipo[10+1]="1";
char sufijo[100]="";
char fileInput[200]="make.tab";
char fileOutput[200]="makefile";
zdMakeTab_t *item;

int mfGenericLee(char *nombreFichero,mfGeneric_t *mfGeneric);
int leeGeneric(char *nombreFichero, char *tipo,char *version);

int main(int argc, char **argv)
{
char esperaSufijo=0;
zdMakeTabLista_t * lista=zdMakeListaGet();

/* ARGUMENTOS 

 -l        -- lista tipos de makefile y return
 -s sufijo -- sufijo de los ficheros
 ultimo parametro --> el tipo (solo se usa si no existe makeSufijo.tab)

*/
int i;
for (i=1;i<argc;i++)
{
   if (strcmp(argv[i],"-l")==0)
       {
           int j;
           for (i=0;i<lista->num;i++)
             printf ("[%-10.10s]-[%-20.20ss] [%-50.50s]\n"
                 ,lista->data[i].tipo
                 ,lista->data[i].nombre
                 ,lista->data[i].descripcion
                 );
           return(0);
       }
   if (esperaSufijo==1)
       {
         strcpy(sufijo,argv[i]);
         esperaSufijo=0;
         sprintf(fileInput,"make%s.tab",sufijo);
         sprintf(fileOutput,"makefile%s",sufijo);
         continue;
       }
   if (strcmp(argv[i],"-s")==0)
       {
           if (i+1>=argc)
              {
                printf("flag -s necesita ser seguido por sufijo\n");
                return(0);
              }
            esperaSufijo=1;   
            continue;
       }
   if (i==argc-1)
       strcpy(tipo,argv[i]);
}

printf("a ver <%s><%s>\n",fileInput,tipo);

leeGeneric(fileInput, tipo,version);

item=zdMakeTabListaBusca( tipo);
if (item==NULL)
  { printf("No encontrado el tipo de makefile <%s>\n", tipo);
   printf("No es posible generar el fichero\n");
   return(0);
}
int ret=item->generaMakefile(fileInput,fileOutput);
printf("generando makefile <%d>\n",ret);
if (ret<0)
{
printf(" no existe <%s> Lo generamos\n",fileInput);
item->generaTabla(fileInput,tipo,version);
}
return(0);
}

int leeGeneric(char *nombreFichero,char *tipo,char *version)
{
mfGeneric_t mfGeneric;
memset(&mfGeneric,0, sizeof(mfGeneric_t));
int ret=mfGenericLee(nombreFichero,&mfGeneric);
if (ret<0) return(ret);
strcpy(tipo,mfGeneric.tipoTabla);
strcpy(version,mfGeneric.versionTabla);
return(0);

}
