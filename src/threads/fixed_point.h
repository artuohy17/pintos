#ifndef __THREAD_FIXED_POINT_H
#define __THREAD_FIXED_POINT_H
#define FP_SHIFT 16
typedef int fixed_t;


int FP_INT(int x);
int FP_ADD(int x, int y);
int FP_ADD_MIX(int x, int n);
int FP_SUB(int x, int y);
int FP_SUB_MIX(int x, int n);
int FP_MULT(int x, int y);
int FP_MULT_MIX(int x, int n);
int FP_DIV(int x, int y);
int FP_DIV_MIX(int x, int n);
int FP_ROUND(int x);
int INT_FP(int n);

int INT_FP(int n){
    return ((fixed_t)(n << FP_SHIFT));
}

int FP_ADD(int x, int y){
    return x + y;
}
int FP_ADD_MIX(int x, int n){
    return x + (n << FP_SHIFT);
}
int FP_SUB(int x, int y){
   return x - y;
}
int FP_SUB_MIX(int x, int n){
   return x - (n << FP_SHIFT);
}
int FP_MULT(int x, int y){
    return ((fixed_t)(((int64_t) x) * y >> FP_SHIFT));
}
int FP_MULT_MIX(int x, int n){
    return x * n;
} 
int FP_DIV(int x, int y){
    return ((fixed_t)((((int64_t) x) << FP_SHIFT) / y ));
}
int FP_INT(int x){
    return x >> FP_SHIFT;
} 
int FP_ROUND(int x){
    return (x >= 0 ? ((x + (1 << (FP_SHIFT - 1))) >> FP_SHIFT)
                   : ((x - (1 << (FP_SHIFT - 1))) >> FP_SHIFT));
} 
#endif
