# 第一章
# 第一題
print("-----第一題-----")
print("請輸入：->",end='')
inp=int(input())
print(inp-1, inp, inp+1)
# 第二題
print("-----第二題-----")
print("請輸入：->",end='')
inp=int(input())
ones=inp%10
tens=inp//10
print(tens,tens,ones,ones,sep='')
# 第三題
print("-----第三題-----")
print("請輸入三角形層數->",end='')
inp=int(input())
for i in range(0,inp):
    for j in range(0,i+1):
        print(i+1,end=' ')
    print()
# 第四題
print("第四題：輸出非7,9倍數：")
for i in range(10,100):
    if i%7==0:
        pass
    elif i%9==0:
        pass
    else:
        print(i)