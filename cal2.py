import matplotlib.pyplot as plt
import numpy as np
import math
pi=np.pi #define pi
sin=math.sin
cos=math.cos
x=np.arange(0,50,0.1)
x1=x
num=math.ceil(50/0.1)
y=np.zeros(num)
dy=np.zeros(num)
"""
fn=(2+sin(x/pi))/(2-sin(x/pi))
diff(fn,x)
cos(x/pi)/(pi*(2 - sin(x/pi))) + (sin(x/pi) + 2)*cos(x/pi)/(pi*(2 - sin(x/pi))**2)
"""

for i in range(0,num):    
    dy[i]=(cos(x1[i]/pi)/(pi*(2 - sin(x1[i]/pi))) + (sin(x1[i]/pi) + 2)*cos(x1[i]/pi))/(pi*(2 - sin(x1[i]/pi))**2)
    y[i]=(2+sin(x[i]/pi))/(2-sin(x[i]/pi))

plt.grid()
plt.title("f(x)=(2+sin(x/pi))/(x-sin(x/pi)) and computed derivative")
plt.plot(x,y)
plt.plot(x1,dy)
plt.show()