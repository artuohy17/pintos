#ifndef __THREAD_FIXED_POINT_H
#define __THREAD_FIXED_POINT_H
#define FP_SHIFT 16


#define INT_FP( n)((n << FP_SHIFT))

#define FP_ADD(x,y) (x + y)
#define FP_ADD_MIX(x,n) (x + (n << FP_SHIFT))
#define FP_SUB(x,y) (x - y)
#define FP_SUB_MIX(x,n) (x - (n << FP_SHIFT))
#define FP_MULT(x, y) ((((int64_t) x) * y >> FP_SHIFT))
#define FP_MULT_MIX(x,n) (x * n)
#define FP_DIV(x,y) (((((int64_t) x) << FP_SHIFT) / y ))
#define FP_DIV_MIX(x,n) (x / n)
#define FP_INT(x) (x >> FP_SHIFT)
#define FP_ROUND(x) (x >= 0 ? ((x + (1 << (FP_SHIFT - 1))) >> FP_SHIFT) \
                            : ((x - (1 << (FP_SHIFT - 1))) >> FP_SHIFT))
 
#endif
