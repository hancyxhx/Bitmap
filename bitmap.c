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

 
/* init a bitmap whose size is BIT_NUM */
pbitmap bitmap_create(int bit_num){
    pbitmap p = (pbitmap)malloc(sizeof(bitmap));
    p->bits = malloc((bit_num-1)/8 + 1);
    p->size = bit_num;

    bitmap_reset(p);
    return p;
}


/* reset the bitmap which is referenced by paramater p */
void bitmap_reset(pbitmap p){
    if (p == NULL)
	return;

    byte_num = (p->size-1)/8 + 1;
    for (int i = 0; i < byte_num; i++)
	p->bits[i] = 0x00;
}


/* get the k-th bit, k count from zero */
int bitmap_get(pbitmap p, int k){
    if (p == NULL || p->size <= k)
	return -1;
    
    int k_byte = k / 8; /* the bit in which byte */
    int k_bit = k %  8; /* the bit in which bit of the byte*/

    int bit = p->bits[k_byte] & ((unsighned char)1 << (8 - 1 - k_bit));
    return bit;
}


/* set the k-th bit, k count from zero */
void bitmap_set(pbitmap p, int k){
    if (p == NULL || p->size <= k)
	return -1;
    
    int k_byte = k / 8; /* the bit in which byte */
    int k_bit = k %  8; /* the bit in which bit of the byte*/

    int bit = p->bits[k_byte] | ((unsighned char)1 << (8 - 1 - k_bit));
    return bit;
}


int main(int argc, char *argv[]){
    printf("%d %d\n", CHAR_BYTE_NUM, CHAR_BIT_NUM);
    
    return 0;
}
