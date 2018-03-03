
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#include "mf1.h"

mf1Lee(char *nombreFichero,mf1_t *mf1)
{
char buf[2001];
char *pun,*pun1,*resto,*campo,*label;
FILE *in = fopen(nombreFichero,"r");
if (!in) return(-1);
while(1)
{
if (!fgets(buf,2000,in))
         break;
 if (strlen(buf)<3) continue;
 buf[strlen(buf)-1]=0;
 mf1LimpiaBuf(buf);
if (buf[0]=='#')
         continue;
resto=buf;

 
//...


// Etiquetas
label=buf;
pun=memchr(buf,':',strlen(buf));
if(!pun) continue;
*pun=0;
pun++;
resto=pun;
mf1LimpiaBuf(label); 


// Char tipoTabla
if (strcmp(label,"tipoTabla")==0)
 {
    mf1Trunca(resto,10);
    mf1LimpiaBuf(resto);
   strcpy(mf1->tipoTabla,resto);
   continue;
 }






// Char versionTabla
if (strcmp(label,"versionTabla")==0)
 {
    mf1Trunca(resto,10);
    mf1LimpiaBuf(resto);
   strcpy(mf1->versionTabla,resto);
   continue;
 }






// Char name
if (strcmp(label,"name")==0)
 {
    mf1Trunca(resto,50);
    mf1LimpiaBuf(resto);
   strcpy(mf1->name,resto);
   continue;
 }







// LISTA fuentes
if (strcmp(label,"fuentes")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    mf1Trunca(campo,100);
    mf1LimpiaBuf(campo);
    strcpy(mf1->fuentes[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }







// LISTA includes
if (strcmp(label,"includes")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    mf1Trunca(campo,100);
    mf1LimpiaBuf(campo);
    strcpy(mf1->includes[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }







// LISTA outherDirInclude
if (strcmp(label,"outherDirInclude")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    mf1Trunca(campo,100);
    mf1LimpiaBuf(campo);
    strcpy(mf1->outherDirInclude[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }







// LISTA outherDirLib
if (strcmp(label,"outherDirLib")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    mf1Trunca(campo,100);
    mf1LimpiaBuf(campo);
    strcpy(mf1->outherDirLib[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }







// LISTA outherLibs
if (strcmp(label,"outherLibs")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    mf1Trunca(campo,100);
    mf1LimpiaBuf(campo);
    strcpy(mf1->outherLibs[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }





continue;
 }


fclose(in);
return(0);
}











// PROGRAMA DE LECTURA DE LISTA

// usage:
//        mf1_t *mf1Lista;
//       numItems = mf1LeeLista(nombreFichero,&mf1Lista);
mf1LeeLista(char *nombreFichero,mf1_t **mf1Lista)
{
mf1_t mf1x;
mf1_t *mf1=&mf1x;
int i;
char buf[20001];
int numItems=0;
char *pun,*pun1,*resto,*campo,*label;

memset(mf1,0,sizeof(mf1_t));

FILE *in = fopen(nombreFichero,"r");
if (!in) return(-1);
while(1)
{
if (!fgets(buf,20000,in))
         break;
 if (strlen(buf)<3) continue;
 buf[strlen(buf)-1]=0;
 mf1LimpiaBuf(buf);
if (buf[0]=='#')
         continue;
resto=buf;

 
//...


// Inicia
resto=buf;



// Char tipoTabla
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    mf1Trunca(campo,10);
    mf1LimpiaBuf(campo);
   strcpy(mf1->tipoTabla,campo);





// Char versionTabla
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    mf1Trunca(campo,10);
    mf1LimpiaBuf(campo);
   strcpy(mf1->versionTabla,campo);





// Char name
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    mf1Trunca(campo,50);
    mf1LimpiaBuf(campo);
   strcpy(mf1->name,campo);




// LISTA fuentes
for (i=0;i<20;i++)
 {
   campo=resto; // esto para chequear el break despues del for
   if (!resto) break;  
   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if (pun)
    {
     *pun=0;
     pun++;
     resto=pun;
    }
   else
    resto=NULL;

   mf1Trunca(campo,100);
   mf1LimpiaBuf(campo);
   strcpy(mf1->fuentes[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  





// LISTA includes
for (i=0;i<20;i++)
 {
   campo=resto; // esto para chequear el break despues del for
   if (!resto) break;  
   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if (pun)
    {
     *pun=0;
     pun++;
     resto=pun;
    }
   else
    resto=NULL;

   mf1Trunca(campo,100);
   mf1LimpiaBuf(campo);
   strcpy(mf1->includes[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  





// LISTA outherDirInclude
for (i=0;i<20;i++)
 {
   campo=resto; // esto para chequear el break despues del for
   if (!resto) break;  
   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if (pun)
    {
     *pun=0;
     pun++;
     resto=pun;
    }
   else
    resto=NULL;

   mf1Trunca(campo,100);
   mf1LimpiaBuf(campo);
   strcpy(mf1->outherDirInclude[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  





// LISTA outherDirLib
for (i=0;i<20;i++)
 {
   campo=resto; // esto para chequear el break despues del for
   if (!resto) break;  
   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if (pun)
    {
     *pun=0;
     pun++;
     resto=pun;
    }
   else
    resto=NULL;

   mf1Trunca(campo,100);
   mf1LimpiaBuf(campo);
   strcpy(mf1->outherDirLib[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  





// LISTA outherLibs
for (i=0;i<20;i++)
 {
   campo=resto; // esto para chequear el break despues del for
   if (!resto) break;  
   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if (pun)
    {
     *pun=0;
     pun++;
     resto=pun;
    }
   else
    resto=NULL;

   mf1Trunca(campo,100);
   mf1LimpiaBuf(campo);
   strcpy(mf1->outherLibs[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  




if (numItems==0) *mf1Lista=malloc(sizeof(mf1_t));
else *mf1Lista=realloc(*mf1Lista,(numItems+1)*sizeof(mf1_t));
(*mf1Lista)[numItems]=*mf1;
memset(mf1,0,sizeof(mf1_t));
numItems++;
continue;
}
fclose(in);
return(numItems);
}



// este lee lista alternativo lo he creado para rellenar el mf1Lista_t directamente
//  mf1Lista ha de estar creado y limpio
mf1LeeLista1(char *nombreFichero,mf1Lista_t *mf1Lista)
{
mf1_t *mf1;

int ret=mf1LeeLista(nombreFichero,&mf1);
if (ret<0) return(ret);
mf1Lista->num=ret;
mf1Lista->data=mf1;
}



mf1Pinta(mf1_t *mf1)
{
int i;
printf("tipoTabla = %s\n",mf1->tipoTabla);
printf("versionTabla = %s\n",mf1->versionTabla);
printf("name = %s\n",mf1->name);
for (i=0;i<20;i++)
  printf("fuentes[i] = %s\n",mf1->fuentes[i]);
for (i=0;i<20;i++)
  printf("includes[i] = %s\n",mf1->includes[i]);
for (i=0;i<20;i++)
  printf("outherDirInclude[i] = %s\n",mf1->outherDirInclude[i]);
for (i=0;i<20;i++)
  printf("outherDirLib[i] = %s\n",mf1->outherDirLib[i]);
for (i=0;i<20;i++)
  printf("outherLibs[i] = %s\n",mf1->outherLibs[i]);
}


int mf1Write(mf1_t *mf1, char *nameFile)
{
int i;
FILE *ou=fopen(nameFile,"w");
if (ou ==NULL) return(-1);
fprintf(ou,"\n# Tipo de la tabla\n");
fprintf(ou,"tipoTabla:%s\n",mf1->tipoTabla);





fprintf(ou,"\n# Version de la tabla\n");
fprintf(ou,"versionTabla:%s\n",mf1->versionTabla);





fprintf(ou,"\n# Nombre del output\n");
fprintf(ou,"name:%s\n",mf1->name);





fprintf(ou,"\n# Lista de fuentes[20]\n");
fprintf(ou,"fuentes");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf1->fuentes[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de includes[20]\n");
fprintf(ou,"includes");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf1->includes[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de otros includes[20]\n");
fprintf(ou,"outherDirInclude");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf1->outherDirInclude[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de otros Dir de libreria[20]\n");
fprintf(ou,"outherDirLib");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf1->outherDirLib[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de otras librerias[20]\n");
fprintf(ou,"outherLibs");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf1->outherLibs[i]);
fprintf(ou,"\n");





return(0);
}

// Limpieza de buffer personalizado
mf1LimpiaBuf(char *buf)
{
return(mf1LimpiaBuffer(buf,strlen(buf)));
}
mf1LimpiaBuffer(char *buf,int len)
{
 int lenp,ret;
 lenp=mf1quita_espacios_iniciales(buf,len);
 ret=mf1quita_espacios_finales(buf,lenp);
 return(ret);
}
mf1quita_espacios_iniciales(char *buf ,int len)
{
 int i;
 int lenp=0;
 for (i=0;i<len;i++)
   {
     if (lenp==0 && buf[i]==' ')
               continue;
     buf[lenp]=buf[i];
     lenp++;
   }
 for (i=lenp;i<len;i++)
      buf[i]=0;
 return(lenp);
}
mf1quita_espacios_finales(char *buf ,int len)
{
 int i;
 int lenp=len;
 for (i=(len)-1;i>=0;i--)
   {
     if (buf[i]==' ')
     { buf[i]=0;lenp--;}
     else
       break;
   }
 return(lenp);
}

// buf es terminado en 0 si su longitud es mayor que len, lo trunca

mf1Trunca(char *buf,int len)
{
if (strlen(buf)>len)
   buf[len]=0;
}
