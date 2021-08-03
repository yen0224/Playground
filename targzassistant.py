import subprocess
print("=============Command Description============")
print("[0] -c: compress filess       打包檔案")
print("[1] -x: decompress files      解開壓縮檔")
print("[2] -t: view compressed files 檢視壓縮檔內容")
print("[3] -z: use GZIP to compress  使用GZIP來壓縮")
print("[4] -v: show process          顯示執行過程")
print("[5] -p: use definite path     使用絕對路徑")
print("[6] -f: use defined file name 指定壓縮檔檔名")
print("============================================")
print("請輸入命令數量：")
commandNum=int(input())
command=["c","x","t","z","v","p","f"]
print("請以數字輸入命令，以逗號分格")
ENTERcommand="-"
whetherDFN=0
for i in input().split(" "):
    i=int(i)
    ENTERcommand=ENTERcommand+command[i]

print("壓縮檔路徑")
add=input()
#print("tar",ENTERcommand,add)
subprocess.run(["tar",ENTERcommand,add])

