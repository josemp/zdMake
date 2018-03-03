#define TIPO_ITEM(nTabla,nItem) ((nTabla)->tabla->item[(nItem)].tipo )
#define DATA_ITEM(nTabla,nItem) ((nTabla)->tabla->item[(nItem)].data )

typedef struct
{
 char nombre[200+1];
 char descri[200+1];
 int lenChar;
} itemChar_t;
typedef struct
{
 char nombre[200+1];
 char descri[200+1];
 int lenLista;
 int lenChar;
} itemLista_t;
typedef struct
{
 char nombre[200+1];
 char descri[200+1];
 itemChar_t *item;
 int numItems;
}itemObjeto_t;


/* Esta estructura es para la descripcion de un meta */

typedef struct
{
 char *descri;
 char *tipo;
 int lenChar;
 int lenLista;
}itemMeta_t;

// definira una linea en la estructura de tipo : tipo (*nombre)()
// por ejemplo int (* cbProceso)();
//cbProceso:Y:callback de proceso:int
//La tabla tendra esta pinta:
// cbProceso:appProceso
// El asignamiento sera:
// cbProceso=appProceso:
// Para realizar el test , habra que crear un : int appProceso(){}
typedef struct
{
char nombre[200+1];
char descri[200+1];
char tipo[200+1];
}itemCallBack_t;

typedef struct
{
  char tipo;
  void *data;
} metaTabItem_t;
typedef struct
{
 char titulo[100+1];
 char descri[200+1];
 int numItems; 
 metaTabItem_t *item;
} metaTab_t;

char *getNombreItemTabla(metaTab_t *tabla,int itemTabla);
char *getDescriItemTabla(metaTab_t *tabla,int itemTabla);
int  getLenCharItemTabla(metaTab_t *tabla,int itemTabla);
int  getLenListaItemTabla(metaTab_t *tabla,int itemTabla);
char *getNombreItemObjeto(metaTab_t *tabla,int itemTabla,int numItemObjeto);
char *getDescriItemObjeto(metaTab_t *tabla,int itemTabla,int numItemObjeto);
int getLenCharItemObjeto(metaTab_t *tabla,int itemTabla,int numItemObjeto);
int  getNumItemsObjeto(metaTab_t *tabla,int itemTabla);
char *getTipoItemCallBack(metaTab_t *tabla,int itemTabla);
int getMeta(metaTab_t *metaTab,char *label,char *labelItem,itemMeta_t *itemMeta);


