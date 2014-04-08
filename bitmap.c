#include <stdio.h>
#include <stdlib.h>

#include <bitmap.h>


typedef struct bitmap_tag{
    unsigned char *bits;
    int size;
} bitmap;


static const int CHAR_BYTE_NUM = sizeof(char);
static const int CHAR_BIT_NUM = sizeof(char) * 8;

pbitmap bitmap_init(int size){
    pbitmap p = (pbitmap)malloc(sizeof(bitmap));
    p->bits = malloc( CHAR_BYTE_NUM * ((size-1)/CHAR_BIT_NUM + 1));
    p->size = size;
}

/* get the k-th bit */
int bitmap_get(pbitmap p, int k){
    int n = k / CHAR_BIT_NUM;
    k %  CHAR_BIT_NUM
}



int main(int argc, char *argv[]){
    printf("%d %d\n", CHAR_BYTE_NUM, CHAR_BIT_NUM);
    
    return 0;
}
