import matplotlib.pyplot as plt
import numpy as np
import math
pi=np.pi
#func = np.cos(x)**2/np.sqrt(max(1, 2*x-1))
x=np.arange(0,10*pi,0.1)
num=math.ceil(10*pi/0.1)
y=np.zeros(num)
for i in range(0,num):
    if x[i]<1:
        sq=1
    else :
        sq=2*x[i]-1
    y[i]=(np.cos(x[i]))**2/np.sqrt(sq)
plt.grid()
plt.title("f(x)=cos(x)^2/sqrt(max(1, 2*x-1)")
plt.xlim(0,10*pi)
plt.ylim(0)
plt.plot(x,y)
plt.show()
