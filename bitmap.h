
#ifndef _BITMAP_H_
#define _BITMAP_H_

typedef struct bitmap_tag* pbitmap;

/* create a bitmap whose size is BIT_NUM, bitmap_reset
   is called automatically after creating */
extern pbitmap bitmap_create(int bit_num);

/* reset the bitmap which is referenced by paramater p */
extern void bitmap_reset(pbitmap p);

/* get the k-th bit, k count from zero */
extern int bitmap_get(pbitmap p, int k);

/* set the k-th bit, k count from zero */
extern void bitmap_set(pbitmap p, int k);

#endif
