import scipy.integrate as integrate
import numpy as np
# 定義lambda expression
# 原式：x*sqrt(2x-1)
# 積分式：((3x+1)(2x-1)^(3/2))/15
def fn(x): return x*np.sqrt(2*x-1)
def fi(x): return ((3*x+1)*(2*x-1)**(3/2))/15


Usum = 0
Lsum = 0
Ssum = 0
accurate = integrate.quad(fn, 1, 2)
print("數學積分：%.10f\n" % accurate[0])
print("迴圈求積：")
xs = np.linspace(1, 2, num=101, endpoint=True)
# iter
for i in range(0, 100):
    Usum += 0.01*fn(xs[i+1])
    Ssum += 0.01*fn(xs[i])
    Lsum += 0.01*fn(xs[i])

# output
print("矩形積分   \b %.10f" % round(Ssum, 10), "誤差：%.10f" % abs(Ssum-accurate[0]))
print("上矩形積分 \b %.10f" % round(Usum, 10), "誤差：%.10f" % abs(Usum-accurate[0]))
print("下矩形積分 \b %.10f" % round(Lsum, 10), "誤差：%.10f" % abs(Lsum-accurate[0]))
