# 第一題
#作圓內接正N邊形
import numpy as np
import matplotlib.pyplot as plt

R=10  #圓半徑
N=6   #正N邊形
a=np.pi/80.0  #傾斜程度
plt.figure(figsize=(6,6),dpi=80)

#正N邊形的圖形
t = np.linspace(0,2*np.pi,N+1)
x=R*np.cos(t)
y=R*np.sin(t)
plt.plot(x,y,color="blue",linewidth=5)
N=8
t = np.linspace(0+a,2*np.pi,N+1)
x=R*np.cos(t)
y=R*np.sin(t)
plt.plot(x,y,color="red",linewidth=5)

plt.show()