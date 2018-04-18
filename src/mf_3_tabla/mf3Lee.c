
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#include "mf3.h"

mf3Lee(char *nombreFichero,mf3_t *mf3)
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
 mf3LimpiaBuf(buf);
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
mf3LimpiaBuf(label); 


// Char tipoTabla
if (strcmp(label,"tipoTabla")==0)
 {
    mf3Trunca(resto,10);
    mf3LimpiaBuf(resto);
   strcpy(mf3->tipoTabla,resto);
   continue;
 }






// Char versionTabla
if (strcmp(label,"versionTabla")==0)
 {
    mf3Trunca(resto,10);
    mf3LimpiaBuf(resto);
   strcpy(mf3->versionTabla,resto);
   continue;
 }






// Char name
if (strcmp(label,"name")==0)
 {
    mf3Trunca(resto,50);
    mf3LimpiaBuf(resto);
   strcpy(mf3->name,resto);
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
    mf3Trunca(campo,100);
    mf3LimpiaBuf(campo);
    strcpy(mf3->fuentes[i],campo);
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
    mf3Trunca(campo,100);
    mf3LimpiaBuf(campo);
    strcpy(mf3->includes[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }







// LISTA proyectos
if (strcmp(label,"proyectos")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    mf3Trunca(campo,100);
    mf3LimpiaBuf(campo);
    strcpy(mf3->proyectos[i],campo);
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
    mf3Trunca(campo,100);
    mf3LimpiaBuf(campo);
    strcpy(mf3->outherDirInclude[i],campo);
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
    mf3Trunca(campo,100);
    mf3LimpiaBuf(campo);
    strcpy(mf3->outherDirLib[i],campo);
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
    mf3Trunca(campo,100);
    mf3LimpiaBuf(campo);
    strcpy(mf3->outherLibs[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }







// LISTA proyectosInstall
if (strcmp(label,"proyectosInstall")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    mf3Trunca(campo,100);
    mf3LimpiaBuf(campo);
    strcpy(mf3->proyectosInstall[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }






// Char outputInstall
if (strcmp(label,"outputInstall")==0)
 {
    mf3Trunca(resto,200);
    mf3LimpiaBuf(resto);
   strcpy(mf3->outputInstall,resto);
   continue;
 }





continue;
 }


fclose(in);
return(0);
}











// PROGRAMA DE LECTURA DE LISTA

// usage:
//        mf3_t *mf3Lista;
//       numItems = mf3LeeLista(nombreFichero,&mf3Lista);
mf3LeeLista(char *nombreFichero,mf3_t **mf3Lista)
{
mf3_t mf3x;
mf3_t *mf3=&mf3x;
int i;
char buf[20001];
int numItems=0;
char *pun,*pun1,*resto,*campo,*label;

memset(mf3,0,sizeof(mf3_t));

FILE *in = fopen(nombreFichero,"r");
if (!in) return(-1);
while(1)
{
if (!fgets(buf,20000,in))
         break;
 if (strlen(buf)<3) continue;
 buf[strlen(buf)-1]=0;
 mf3LimpiaBuf(buf);
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
    mf3Trunca(campo,10);
    mf3LimpiaBuf(campo);
   strcpy(mf3->tipoTabla,campo);





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
    mf3Trunca(campo,10);
    mf3LimpiaBuf(campo);
   strcpy(mf3->versionTabla,campo);





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
    mf3Trunca(campo,50);
    mf3LimpiaBuf(campo);
   strcpy(mf3->name,campo);




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

   mf3Trunca(campo,100);
   mf3LimpiaBuf(campo);
   strcpy(mf3->fuentes[i],campo);
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

   mf3Trunca(campo,100);
   mf3LimpiaBuf(campo);
   strcpy(mf3->includes[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  





// LISTA proyectos
for (i=0;i<100;i++)
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

   mf3Trunca(campo,100);
   mf3LimpiaBuf(campo);
   strcpy(mf3->proyectos[i],campo);
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

   mf3Trunca(campo,100);
   mf3LimpiaBuf(campo);
   strcpy(mf3->outherDirInclude[i],campo);
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

   mf3Trunca(campo,100);
   mf3LimpiaBuf(campo);
   strcpy(mf3->outherDirLib[i],campo);
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

   mf3Trunca(campo,100);
   mf3LimpiaBuf(campo);
   strcpy(mf3->outherLibs[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  





// LISTA proyectosInstall
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

   mf3Trunca(campo,100);
   mf3LimpiaBuf(campo);
   strcpy(mf3->proyectosInstall[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  






// Char outputInstall
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    mf3Trunca(campo,200);
    mf3LimpiaBuf(campo);
   strcpy(mf3->outputInstall,campo);



if (numItems==0) *mf3Lista=malloc(sizeof(mf3_t));
else *mf3Lista=realloc(*mf3Lista,(numItems+1)*sizeof(mf3_t));
(*mf3Lista)[numItems]=*mf3;
memset(mf3,0,sizeof(mf3_t));
numItems++;
continue;
}
fclose(in);
return(numItems);
}



// este lee lista alternativo lo he creado para rellenar el mf3Lista_t directamente
//  mf3Lista ha de estar creado y limpio
mf3LeeLista1(char *nombreFichero,mf3Lista_t *mf3Lista)
{
mf3_t *mf3;

int ret=mf3LeeLista(nombreFichero,&mf3);
if (ret<0) return(ret);
mf3Lista->num=ret;
mf3Lista->data=mf3;
}



mf3Pinta(mf3_t *mf3)
{
int i;
printf("tipoTabla = %s\n",mf3->tipoTabla);
printf("versionTabla = %s\n",mf3->versionTabla);
printf("name = %s\n",mf3->name);
for (i=0;i<20;i++)
  printf("fuentes[i] = %s\n",mf3->fuentes[i]);
for (i=0;i<20;i++)
  printf("includes[i] = %s\n",mf3->includes[i]);
for (i=0;i<100;i++)
  printf("proyectos[i] = %s\n",mf3->proyectos[i]);
for (i=0;i<20;i++)
  printf("outherDirInclude[i] = %s\n",mf3->outherDirInclude[i]);
for (i=0;i<20;i++)
  printf("outherDirLib[i] = %s\n",mf3->outherDirLib[i]);
for (i=0;i<20;i++)
  printf("outherLibs[i] = %s\n",mf3->outherLibs[i]);
for (i=0;i<20;i++)
  printf("proyectosInstall[i] = %s\n",mf3->proyectosInstall[i]);
printf("outputInstall = %s\n",mf3->outputInstall);
}


int mf3Write(mf3_t *mf3, char *nameFile)
{
int i;
FILE *ou=fopen(nameFile,"w");
if (ou ==NULL) return(-1);
fprintf(ou,"\n# Tipo de la tabla\n");
fprintf(ou,"tipoTabla:%s\n",mf3->tipoTabla);





fprintf(ou,"\n# Version de la tabla\n");
fprintf(ou,"versionTabla:%s\n",mf3->versionTabla);





fprintf(ou,"\n# Nombre del output\n");
fprintf(ou,"name:%s\n",mf3->name);





fprintf(ou,"\n# Lista de fuentes[20]\n");
fprintf(ou,"fuentes");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf3->fuentes[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de includes[20]\n");
fprintf(ou,"includes");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf3->includes[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de  make.tab, proyectos dependientes[100]\n");
fprintf(ou,"proyectos");
for (i=0;i<100;i++)
  fprintf(ou,":%s",mf3->proyectos[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de otros includes[20]\n");
fprintf(ou,"outherDirInclude");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf3->outherDirInclude[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de otros Dir de libreria[20]\n");
fprintf(ou,"outherDirLib");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf3->outherDirLib[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de otras librerias[20]\n");
fprintf(ou,"outherLibs");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf3->outherLibs[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de make.tab, a instalar[20]\n");
fprintf(ou,"proyectosInstall");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf3->proyectosInstall[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Directorio de instalacion\n");
fprintf(ou,"outputInstall:%s\n",mf3->outputInstall);





return(0);
}

// Limpieza de buffer personalizado
mf3LimpiaBuf(char *buf)
{
return(mf3LimpiaBuffer(buf,strlen(buf)));
}
mf3LimpiaBuffer(char *buf,int len)
{
 int lenp,ret;
 lenp=mf3quita_espacios_iniciales(buf,len);
 ret=mf3quita_espacios_finales(buf,lenp);
 return(ret);
}
mf3quita_espacios_iniciales(char *buf ,int len)
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
mf3quita_espacios_finales(char *buf ,int len)
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

mf3Trunca(char *buf,int len)
{
if (strlen(buf)>len)
   buf[len]=0;
}
