


/* Get lista de tipos de makefiles */
/* using

zdMakeTabLista_t *lista=zdMakeListaGet();

printf("lista de <%d> miembros ",lista->num);

zdMakeTab_t *data = lista->data;

data:
 char tipo[10+1];
 char nombre[20+1];
 char descripcion[50+1];

*/
zdMakeTabLista_t *zdMakeListaGet();



zdMakeTab_t *zdMakeTabListaBusca(char * tipo);

