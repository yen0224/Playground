from sympy import *
import scipy.integrate as integrate
import pprint
x = symbols('x')
func = 1/3*x**4+3*x**3+2*x**2-11
#第二題
print("----------2--------------")
for i in range(0, 5):
    func = diff(func, x)
    if i == 2 or i == 4:
        print(i+1, "次導函數", func)

#第三題
print("----------3--------------")
func = (x+sin(x))/x
print(limit(func, x, oo))

#第四題
print("----------4--------------")
def fn(x): return 4*x**3-x**2+2*x+sqrt(7)


print(integrate.quad(fn, -1, 1)[0])
