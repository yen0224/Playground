import random

def ri(a,b):
    return random.randint(a, b)
def rr(a):
    return random.randrange(a)
"""
原程式碼
print("-----第一題-----")
print(ri(1,39),ri(1,39),ri(1,39),ri(1,39),ri(1,39),"特別號",ri(1,8))
"""
lottery=[5]
print("-----第一題-----")
#for i in range(0,5):


print("-----第二題-----")
print("n=(請輸入) ",end='')
inp=int(input())
rd=list(range(0,inp))
for i in range(0,inp):
    rd[i]=rr(9)+1
for j in range(0,inp):
    print("%2d"%rd[j],"|",rd[j]*"*")

print("-----第三題-----")
count=[0,0,0,0,0,0]
for i in range(0,50):
    j=rr(6)
    count[j]=count[j]+1
for i in range(0,6):
    print(i+1,"->",count[i])
count=sorted(count,reverse=True)
print("max ->",count[0])