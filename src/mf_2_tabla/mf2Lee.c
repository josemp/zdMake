
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#include "mf2.h"

mf2Lee(char *nombreFichero,mf2_t *mf2)
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
 mf2LimpiaBuf(buf);
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
mf2LimpiaBuf(label); 


// Char tipoTabla
if (strcmp(label,"tipoTabla")==0)
 {
    mf2Trunca(resto,10);
    mf2LimpiaBuf(resto);
   strcpy(mf2->tipoTabla,resto);
   continue;
 }






// Char versionTabla
if (strcmp(label,"versionTabla")==0)
 {
    mf2Trunca(resto,10);
    mf2LimpiaBuf(resto);
   strcpy(mf2->versionTabla,resto);
   continue;
 }






// Char name
if (strcmp(label,"name")==0)
 {
    mf2Trunca(resto,50);
    mf2LimpiaBuf(resto);
   strcpy(mf2->name,resto);
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
    mf2Trunca(campo,100);
    mf2LimpiaBuf(campo);
    strcpy(mf2->fuentes[i],campo);
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
    mf2Trunca(campo,100);
    mf2LimpiaBuf(campo);
    strcpy(mf2->includes[i],campo);
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
    mf2Trunca(campo,100);
    mf2LimpiaBuf(campo);
    strcpy(mf2->proyectos[i],campo);
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
    mf2Trunca(campo,100);
    mf2LimpiaBuf(campo);
    strcpy(mf2->outherDirInclude[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }







// LISTA includesForInstall
if (strcmp(label,"includesForInstall")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    mf2Trunca(campo,100);
    mf2LimpiaBuf(campo);
    strcpy(mf2->includesForInstall[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }






// Char outputLibInstall
if (strcmp(label,"outputLibInstall")==0)
 {
    mf2Trunca(resto,200);
    mf2LimpiaBuf(resto);
   strcpy(mf2->outputLibInstall,resto);
   continue;
 }






// Char outputIncludeInstall
if (strcmp(label,"outputIncludeInstall")==0)
 {
    mf2Trunca(resto,200);
    mf2LimpiaBuf(resto);
   strcpy(mf2->outputIncludeInstall,resto);
   continue;
 }







// LISTA test
if (strcmp(label,"test")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    mf2Trunca(campo,100);
    mf2LimpiaBuf(campo);
    strcpy(mf2->test[i],campo);
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
//        mf2_t *mf2Lista;
//       numItems = mf2LeeLista(nombreFichero,&mf2Lista);
mf2LeeLista(char *nombreFichero,mf2_t **mf2Lista)
{
mf2_t mf2x;
mf2_t *mf2=&mf2x;
int i;
char buf[20001];
int numItems=0;
char *pun,*pun1,*resto,*campo,*label;

memset(mf2,0,sizeof(mf2_t));

FILE *in = fopen(nombreFichero,"r");
if (!in) return(-1);
while(1)
{
if (!fgets(buf,20000,in))
         break;
 if (strlen(buf)<3) continue;
 buf[strlen(buf)-1]=0;
 mf2LimpiaBuf(buf);
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
    mf2Trunca(campo,10);
    mf2LimpiaBuf(campo);
   strcpy(mf2->tipoTabla,campo);





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
    mf2Trunca(campo,10);
    mf2LimpiaBuf(campo);
   strcpy(mf2->versionTabla,campo);





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
    mf2Trunca(campo,50);
    mf2LimpiaBuf(campo);
   strcpy(mf2->name,campo);




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

   mf2Trunca(campo,100);
   mf2LimpiaBuf(campo);
   strcpy(mf2->fuentes[i],campo);
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

   mf2Trunca(campo,100);
   mf2LimpiaBuf(campo);
   strcpy(mf2->includes[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  





// LISTA proyectos
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

   mf2Trunca(campo,100);
   mf2LimpiaBuf(campo);
   strcpy(mf2->proyectos[i],campo);
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

   mf2Trunca(campo,100);
   mf2LimpiaBuf(campo);
   strcpy(mf2->outherDirInclude[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  





// LISTA includesForInstall
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

   mf2Trunca(campo,100);
   mf2LimpiaBuf(campo);
   strcpy(mf2->includesForInstall[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  






// Char outputLibInstall
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    mf2Trunca(campo,200);
    mf2LimpiaBuf(campo);
   strcpy(mf2->outputLibInstall,campo);





// Char outputIncludeInstall
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    mf2Trunca(campo,200);
    mf2LimpiaBuf(campo);
   strcpy(mf2->outputIncludeInstall,campo);




// LISTA test
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

   mf2Trunca(campo,100);
   mf2LimpiaBuf(campo);
   strcpy(mf2->test[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  




if (numItems==0) *mf2Lista=malloc(sizeof(mf2_t));
else *mf2Lista=realloc(*mf2Lista,(numItems+1)*sizeof(mf2_t));
(*mf2Lista)[numItems]=*mf2;
memset(mf2,0,sizeof(mf2_t));
numItems++;
continue;
}
fclose(in);
return(numItems);
}



// este lee lista alternativo lo he creado para rellenar el mf2Lista_t directamente
//  mf2Lista ha de estar creado y limpio
mf2LeeLista1(char *nombreFichero,mf2Lista_t *mf2Lista)
{
mf2_t *mf2;

int ret=mf2LeeLista(nombreFichero,&mf2);
if (ret<0) return(ret);
mf2Lista->num=ret;
mf2Lista->data=mf2;
}



mf2Pinta(mf2_t *mf2)
{
int i;
printf("tipoTabla = %s\n",mf2->tipoTabla);
printf("versionTabla = %s\n",mf2->versionTabla);
printf("name = %s\n",mf2->name);
for (i=0;i<20;i++)
  printf("fuentes[i] = %s\n",mf2->fuentes[i]);
for (i=0;i<20;i++)
  printf("includes[i] = %s\n",mf2->includes[i]);
for (i=0;i<20;i++)
  printf("proyectos[i] = %s\n",mf2->proyectos[i]);
for (i=0;i<20;i++)
  printf("outherDirInclude[i] = %s\n",mf2->outherDirInclude[i]);
for (i=0;i<20;i++)
  printf("includesForInstall[i] = %s\n",mf2->includesForInstall[i]);
printf("outputLibInstall = %s\n",mf2->outputLibInstall);
printf("outputIncludeInstall = %s\n",mf2->outputIncludeInstall);
for (i=0;i<20;i++)
  printf("test[i] = %s\n",mf2->test[i]);
}


int mf2Write(mf2_t *mf2, char *nameFile)
{
int i;
FILE *ou=fopen(nameFile,"w");
if (ou ==NULL) return(-1);
fprintf(ou,"\n# Tipo de la tabla\n");
fprintf(ou,"tipoTabla:%s\n",mf2->tipoTabla);





fprintf(ou,"\n# Version de la tabla\n");
fprintf(ou,"versionTabla:%s\n",mf2->versionTabla);





fprintf(ou,"\n# Nombre del output\n");
fprintf(ou,"name:%s\n",mf2->name);





fprintf(ou,"\n# Lista de fuentes[20]\n");
fprintf(ou,"fuentes");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf2->fuentes[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de includes[20]\n");
fprintf(ou,"includes");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf2->includes[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de directorios de proyectos dependientes[20]\n");
fprintf(ou,"proyectos");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf2->proyectos[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de otros includes[20]\n");
fprintf(ou,"outherDirInclude");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf2->outherDirInclude[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de includes para instalar[20]\n");
fprintf(ou,"includesForInstall");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf2->includesForInstall[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Directorio de instalacion\n");
fprintf(ou,"outputLibInstall:%s\n",mf2->outputLibInstall);





fprintf(ou,"\n# Directorio de inst includes\n");
fprintf(ou,"outputIncludeInstall:%s\n",mf2->outputIncludeInstall);





fprintf(ou,"\n# Lista de files *.tab que compila test[20]\n");
fprintf(ou,"test");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mf2->test[i]);
fprintf(ou,"\n");





return(0);
}

// Limpieza de buffer personalizado
mf2LimpiaBuf(char *buf)
{
return(mf2LimpiaBuffer(buf,strlen(buf)));
}
mf2LimpiaBuffer(char *buf,int len)
{
 int lenp,ret;
 lenp=mf2quita_espacios_iniciales(buf,len);
 ret=mf2quita_espacios_finales(buf,lenp);
 return(ret);
}
mf2quita_espacios_iniciales(char *buf ,int len)
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
mf2quita_espacios_finales(char *buf ,int len)
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

mf2Trunca(char *buf,int len)
{
if (strlen(buf)>len)
   buf[len]=0;
}
