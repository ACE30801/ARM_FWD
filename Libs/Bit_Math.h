#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(register, n)     ((register)|=(1<<(n)))
#define CLEAR_BIT(register, n)   ((register)&=(~(1<<(n))))
#define TOGGLE_BIT(register, n)  ((register)^= (1<<(n)))
#define GET_BIT(register, n)     (((register>>n)&(1)))
#define IS_BIT_CLEAR(register, n) (!(register&(1<<n)))

#endif