
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include "metaTab.h"
#include "mf1.h"

main()
{
int ret;

//Crea e inicia estructura

mf1_t mf1;
memset(&mf1,0, sizeof(mf1_t));

//Lee tabla
ret=mf1Lee("mf1.tab",&mf1);
if (ret<0) printf("No se pudo leer correctamente mf1.tab\n");
else printf("Leido correctamente \n");

// Muestra la lectura
printf("------------- tab print -------------------\n");
mf1Pinta(&mf1);
printf("------------- tab print -------------------\n");

// Lee lista
mf1_t *mf1Lista;
ret=mf1LeeLista("mf1List.tab",&mf1Lista);
printf("Leidos <%d> registros\n",ret);

// Genera Json
printf("Generando Json\n");
ret=mf12JsonFile("mf1.json",&mf1);

// Parse Json
printf("Parse JSON generado\n");
char *jsonString;
ret=leeFileTest("mf1.json",&jsonString);
if (ret<0)
    printf("Error de lectura del fichero <%s>\n","mf1.json");

mf1_t mf11;
memset(&mf11,0,sizeof(mf1_t));
ret=mf1ParseJson(jsonString, &mf11);
if (ret<0) printf("Error ParseJson <%s>\n",jsonString);
// Muestra la lectura json
printf("------------- tab print json parsed-------------------\n");
mf1Pinta(&mf11);
printf("------------- tab print json parsed-------------------\n");
}



int leeFileTest(char *file, char **template)
{
char *buf;
FILE *in=fopen(file,"r");
if (!in) return(-1);
buf=malloc(1);
strcpy(buf,"");
while(1)
 {

   buf=realloc(buf,strlen(buf)+1001);
   if (!fgets(buf+strlen(buf),1000,in)) break;
 }
fclose(in);

*template=buf;
return(strlen(buf));

}
int creaFileMeta_mf1(metaTab_t *metaTab,char *nameFile)
{
int i,j;
itemCallBack_t *itemCallBack;
itemLista_t *itemList;
itemChar_t *itemChar;
itemObjeto_t *itemObjeto;
FILE *ou;
ou=fopen(nameFile,"w");
if (!ou) return(-1);
for (i=0;i<metaTab->numItems;i++)
{
 if (metaTab->item[i].tipo=='C')
   {
     itemChar=(itemChar_t *)metaTab->item[i].data;
     fprintf(ou,"%s:C:%s:%d\n",itemChar->nombre,itemChar->descri,itemChar->lenChar);
   }

 if (metaTab->item[i].tipo=='L')
   {
     itemList=(itemLista_t *)metaTab->item[i].data;
     fprintf(ou,"%s:L:%s:%d:%d\n",itemList->nombre,itemList->descri,itemList->lenLista,itemList->lenChar);
   }
 if (metaTab->item[i].tipo=='Y')
   {
     itemCallBack=(itemCallBack_t *)metaTab->item[i].data;
     fprintf(ou,"%s:Y:%s:%s\n",itemCallBack->nombre,itemCallBack->descri,itemCallBack->tipo);
   }
 if (metaTab->item[i].tipo=='O')
   {
     itemObjeto=(itemObjeto_t *)metaTab->item[i].data;
     fprintf(ou,"%s:O:%s",itemObjeto->nombre,itemObjeto->descri);
     for(j=0;j<itemObjeto->numItems;j++)
      {
       fprintf(ou,":%s:%s:%d",itemObjeto->item[j].nombre,itemObjeto->item[j].descri,itemObjeto->item[j].lenChar);
      }
    fprintf(ou,"\n");
   }
fclose(ou);
return(0);
}

}

