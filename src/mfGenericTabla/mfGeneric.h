
/******************************************/
/*  Estructuras de la tabla mfGeneric  */ 
/******************************************/

/*  Estructura de la tabla mfGeneric  */ 

typedef struct {  
 char tipoTabla[10+1];   
 char versionTabla[10+1];   
 char name[50+1];  
 char fuentes[20][100+1];  
 char includesForInstall[20][100+1]; 
} mfGeneric_t;

/*  Estructura de la tabla List mfGeneric  */ 

typedef struct 
{
  int num;
 mfGeneric_t *data;

} mfGenericLista_t;
