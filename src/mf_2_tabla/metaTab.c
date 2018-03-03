

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metaTab.h"

char *getDescriItemTabla(metaTab_t *tabla,int itemTabla)
{


 if (itemTabla >= tabla->numItems)
   return(NULL);
 if (itemTabla< 0)
   return(NULL);
 if (tabla->item[itemTabla].tipo=='C')
   {
    itemChar_t *itemChar = (itemChar_t *) tabla->item[itemTabla].data;
    return(itemChar->descri);
   }
 if (tabla->item[itemTabla].tipo=='L')
   {
    itemLista_t *itemLista = (itemLista_t *) tabla->item[itemTabla].data;
    return(itemLista->descri);
   }
 if (tabla->item[itemTabla].tipo=='O')
   {
    itemObjeto_t  *itemObjeto = (itemObjeto_t *) tabla->item[itemTabla].data;
    return(itemObjeto->descri);
   }
 if (tabla->item[itemTabla].tipo=='Y')
   {
    itemCallBack_t  *itemCallBack = (itemCallBack_t *) tabla->item[itemTabla].data;
    return(itemCallBack->descri);
   }
return(NULL);
}

char *getNombreItemTabla(metaTab_t *tabla,int itemTabla)
{


 if (itemTabla >= tabla->numItems)
   return(NULL);
 if (itemTabla< 0)
   return(NULL);
 if (tabla->item[itemTabla].tipo=='C')
   {
    itemChar_t *itemChar = (itemChar_t *) tabla->item[itemTabla].data;
    return(itemChar->nombre);
   }
 if (tabla->item[itemTabla].tipo=='L')
   {
    itemLista_t *itemLista = (itemLista_t *) tabla->item[itemTabla].data;
    return(itemLista->nombre);
   }
 if (tabla->item[itemTabla].tipo=='O')
   {
    itemObjeto_t  *itemObjeto = (itemObjeto_t *) tabla->item[itemTabla].data;
    return(itemObjeto->nombre);
   }
 if (tabla->item[itemTabla].tipo=='Y')
   {
    itemCallBack_t  *itemCallBack = (itemCallBack_t *) tabla->item[itemTabla].data;
    return(itemCallBack->nombre);
   }
return(NULL);
}
int  getLenCharItemTabla(metaTab_t *tabla,int itemTabla)
{

 if (itemTabla >= tabla->numItems)
   return(-1);
 if (itemTabla< 0)
   return(-1);
 if (tabla->item[itemTabla].tipo=='C')
   {
    itemChar_t *itemChar = (itemChar_t *) tabla->item[itemTabla].data;
    return(itemChar->lenChar);
   }
 if (tabla->item[itemTabla].tipo=='L')
   {
    itemLista_t *itemLista = (itemLista_t *) tabla->item[itemTabla].data;
    return(itemLista->lenChar);
   }
return(-1);
}
int getLenListaItemTabla(metaTab_t *tabla,int itemTabla)
{

 if (itemTabla >= tabla->numItems)
   return(-1);
   
 if (itemTabla< 0)
   return(-1);
 if (tabla->item[itemTabla].tipo=='L')
   {
    itemLista_t *itemLista = (itemLista_t *) tabla->item[itemTabla].data;
    return(itemLista->lenLista);

   }
return(-1);
}

char *getTipoItemCallBack(metaTab_t *tabla,int itemTabla)
{

 if (itemTabla >= tabla->numItems)
   return(NULL);

 if (tabla->item[itemTabla].tipo=='Y')
   {
    itemCallBack_t *itemCallBack = (itemCallBack_t *) tabla->item[itemTabla].data;
    return(itemCallBack->tipo);
   }
return(NULL);
}

char *getNombreItemObjeto(metaTab_t *tabla,int itemTabla,int numItemObjeto)
{

 if (itemTabla >= tabla->numItems)
   return(NULL);

 if (itemTabla< 0)
   return(NULL);

 if (tabla->item[itemTabla].tipo!='O')
    return(NULL);


// Solo quedan objetos

    itemObjeto_t  *itemObjeto = (itemObjeto_t *) tabla->item[itemTabla].data;
    
    if ( numItemObjeto >= itemObjeto->numItems)
      return(NULL);
    if (numItemObjeto <0) return(NULL);
    
    return(itemObjeto->item[numItemObjeto].nombre);
}

char *getDescriItemObjeto(metaTab_t *tabla,int itemTabla,int numItemObjeto)
{

 if (itemTabla >= tabla->numItems)
   return(NULL);

 if (itemTabla< 0)
   return(NULL);

 if (tabla->item[itemTabla].tipo!='O')
    return(NULL);


// Solo quedan objetos

    itemObjeto_t  *itemObjeto = (itemObjeto_t *) tabla->item[itemTabla].data;
    
    if ( numItemObjeto >= itemObjeto->numItems)
      return(NULL);
    if (numItemObjeto <0) return(NULL);
    
    return(itemObjeto->item[numItemObjeto].descri);
}


int getLenCharItemObjeto(metaTab_t *tabla,int itemTabla,int numItemObjeto)
{

 if (itemTabla >= tabla->numItems)
   return(-1);

 if (itemTabla< 0)
   return(-1);

 if (tabla->item[itemTabla].tipo!='O')
    return(-1);


// Solo quedan objetos

    
    itemObjeto_t  *itemObjeto = (itemObjeto_t *) tabla->item[itemTabla].data;
    
    if ( numItemObjeto >= itemObjeto->numItems)
      return(-1);
    if (numItemObjeto <0) return(-1);
    
    return(itemObjeto->item[numItemObjeto].lenChar);
}

int  getNumItemsObjeto(metaTab_t *tabla,int itemTabla)
{
 if (itemTabla >= tabla->numItems)
   return(-1);

 if (itemTabla< 0)
   return(-1);

 if (tabla->item[itemTabla].tipo!='O')
    return(-1);

// Solo quedan objetos

    itemObjeto_t  *itemObjeto = (itemObjeto_t *) tabla->item[itemTabla].data;
    
    
    return(itemObjeto->numItems);
}


/* Saca los datos significativos de un meta */
/* el itemMeta ha de estar ya asignado */
int getMeta(metaTab_t *metaTab,char *label,char *labelItem,itemMeta_t *itemMeta)
{
itemLista_t *itemLista;
itemChar_t  *itemChar;
itemObjeto_t *itemObjeto;
itemCallBack_t *itemCallBack;
int i,j;
memset(itemMeta,0,sizeof(itemMeta_t));

for (i=0;i<metaTab->numItems;i++)
{
 if (strlen(labelItem)==0)
   { // no es objeto
      if(metaTab->item[i].tipo=='C')
        {
         itemChar = metaTab->item[i].data;
         if (strcmp(label,itemChar->nombre)==0)
            {
             itemMeta->descri=itemChar->descri;
             itemMeta->lenChar=itemChar->lenChar;
             return(0);
            }
        }
      if(metaTab->item[i].tipo=='L')
        {
         itemLista = metaTab->item[i].data;
         if (strcmp(label,itemLista->nombre)==0)
            {
             itemMeta->descri=itemLista->descri;
             itemMeta->lenChar=itemLista->lenChar;
             itemMeta->lenLista=itemLista->lenLista;
             return(0);
            }
        }
      if(metaTab->item[i].tipo=='Y')
        {
         itemCallBack = metaTab->item[i].data;
         if (strcmp(label,itemCallBack->nombre)==0)
            {
             itemMeta->descri=itemCallBack->descri;
             itemMeta->tipo=itemCallBack->tipo;
             return(0);
            }
        }
   }
  else
  {
      if(metaTab->item[i].tipo=='O')
       {
        itemObjeto=metaTab->item[i].data;
        if (strcmp(label,itemObjeto->nombre)==0)
         {
           if (strlen(labelItem)==0)
               {
                 itemMeta->descri=itemObjeto->descri;
                 itemMeta->lenLista=itemObjeto->numItems;
                 return(0);
               }
           for(j=0;j<itemObjeto->numItems;j++)
            {
             if (strcmp(itemObjeto->item[j].nombre,labelItem)==0)
               {
                 itemMeta->descri = itemObjeto->item[j].descri;
                 itemMeta->lenChar=itemObjeto->item[j].lenChar;
                 itemMeta->descri=itemLista->descri;
                 return(0);
               }
            }
         }
       }

  }

}
return(-1);

}

