#ifndef __THREAD_FIXED_POINT_H
#define __THREAD_FIXED_POINT_H
#define FP_SHIFT 16
typedef int fixed_t;


//int FP_INT(int x);
//int FP_ADD(int x, int y);
//int FP_ADD_MIX(int x, int n);
//int FP_SUB(int x, int y);
//int FP_SUB_MIX(int x, int n);
//int FP_MULT(int x, int y);
//int FP_MULT_MIX(int x, int n);
//int FP_DIV(int x, int y);
//int FP_DIV_MIX(int x, int n);
//int FP_ROUND(int x);
//int INT_FP(int n);

#define INT_FP( n)((fixed_t)(n << FP_SHIFT))

#define FP_ADD(x,y) (x + y)
#define FP_ADD_MIX(x,n) (x + (n << FP_SHIFT))
#define FP_SUB(x,y) (x - y)
#define FP_SUB_MIX(x,n) (x - (n << FP_SHIFT))
#define FP_MULT(x, y) ((fixed_t)(((int64_t) x) * y >> FP_SHIFT))
#define FP_MULT_MIX(x,n) (x * n)
#define FP_DIV(x,y) ((fixed_t)((((int64_t) x) << FP_SHIFT) / y ))
#define FP_DIV_MIX(x,n) (x / n)
#define FP_INT(x) (x >> FP_SHIFT)
#define FP_ROUND(x) (x >= 0 ? ((x + (1 << (FP_SHIFT - 1))) >> FP_SHIFT) \
                            : ((x - (1 << (FP_SHIFT - 1))) >> FP_SHIFT))
 
#endif
