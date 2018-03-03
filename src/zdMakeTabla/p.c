#include <stdio.h>



typedef struct linea_s
{
int x;
char pepe[10];

} linea_t;
typedef struct
{
int data;
linea_t *cosa;

} data_t;
linea_t lista[]={
{2,"quetal"},
{3,"quetal"}

    
};
data_t data={1, lista };

int main()
{
}

