
/******************************************/
/*  Estructuras de la tabla zdMakeTab  */ 
/******************************************/

/*  Estructura de la tabla zdMakeTab  */ 

typedef struct {  
 char tipo[10+1];   
 char nombre[20+1];   
 char descripcion[50+1];  
 int (*generaTabla)();  
 int (*generaMakefile)(); 
} zdMakeTab_t;

/*  Estructura de la tabla List zdMakeTab  */ 

typedef struct 
{
  int num;
 zdMakeTab_t *data;

} zdMakeTabLista_t;
