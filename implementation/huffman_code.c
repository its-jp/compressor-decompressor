#include "code.h"
#include <stdlib.h>
boolean init_code (huffman_code* c /* por referência */)
{
    c->byte=(U8*)malloc(1*sizeof(U8));
    if (c->byte==NULL) return false;

    c->capacity=8;
    c->size=0;
    return true;
}

void free_code (huffman_code* c /* por referência */)
{
    if (c->byte!=NULL) free(c->byte);
    c->byte=NULL;
}

boolean add_bit (huffman_code* c /* por referência */,
                      U8 valor /* 0 ou 1 */)
{
    if (csize==c->capacity)
    {
        U8* novo=(U8*)malloc((c->capacity/8+1)*sizeof(U8));
        if (novo==NULL) return false;

        for(int i=0;i<c->size/8;i++)
            novo[i]=c->byte[i];

        free(c->byte);
        c->byte=novo;

        c->capacity+=8;
    }

    c->byte[c->capacity/8-1]<<=1;

    if (valor==1)
        c->byte[c->capacity/8-1]|=1;

    c->size++;
    return true;
}


boolean throw_bit (huffman_code* c /* por referência */)
{
    if (c->size==0) return false;

    c->byte[c->capacity/8-1]>>=1;
    c->size--;

    if (c->capacity>8 && c->capacity-c->size==8)
    {
        U8* novo=(U8*)malloc((c->capacity/8-1)*sizeof(U8));
        if (novo==NULL) return false;

        for(int i=0;i<c->size/8;i++)
            novo[i]=c->byte[i];

        free(c->byte);
        c->byte=novo;

        c->capacity-=8;
    }
}

boolean clone (huffman_code original, /* por valor */
               huffman_code* copia    /* por referencia */)
{
    copia->byte=(U8*)malloc(original.capacity*sizeof(U8));
    if (copia->byte==NULL) return false;


    for(int i=0;i<original.capacity/8;i++)
        copia->byte[i]=original.byte[i];

    copia->capacity=original.capacity;
    copia->size=original.size;
    return true;
}
