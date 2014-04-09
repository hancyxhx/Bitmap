#include <stdio.h>
#include <stdlib.h>

#include <bitmap.h>

/* IMPORTANT NOTE:
   this program based on the fact that POSIX require
   data type 'char' to be exactly 8 bits in size. */

typedef struct bitmap_tag{
    unsigned char *bits;
    int size;
} bitmap;

/* to update it according to Unix standard (ISO C) */
static const int CHAR_BYTE_NUM = sizeof(char);
static const int CHAR_BIT_NUM = sizeof(char) * 8;

/* init a bitmap whose bits num is SIZE*/
pbitmap bitmap_init(int size){
    pbitmap p = (pbitmap)malloc(sizeof(bitmap));
    p->bits = malloc( CHAR_BYTE_NUM * ((size-1)/CHAR_BIT_NUM + 1));
    p->size = size;
    
    return p;
}

/* get the k-th bit, k count from zero */
int bitmap_get(pbitmap p, int k){
    int k_char = k / CHAR_BIT_NUM;
    int k_bit = k %  CHAR_BIT_NUM;

    int bit = p->bits[k_char] & ((unsighned char)1 << (CHAR_BIT_NUM - k_bit));
    return bit;
}



int main(int argc, char *argv[]){
    printf("%d %d\n", CHAR_BYTE_NUM, CHAR_BIT_NUM);
    
    return 0;
}
