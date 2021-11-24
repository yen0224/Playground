class road():
    def __init__(self, snode, enode, length, width, limit):
        self.snode = snode
        self.enode = enode
        self.rl = float(length)
        self.rw = float(width)
        self.limit = limit

    def exam(self, n):
        errmsg=''
        invalid = False #1 is invalid, 0 is valid
        n=int(n)
        try:
            self.snode = int(self.snode)
            self.enode = int(self.enode)
            self.limit = self.limit

            if self.snode>= n or self.snode<0 or self.enode>=n or self.enode<0:
                invalid = True
                errmsg += 'node out of range'
            if self.snode==self.enode:
                invalid = True
                errmsg+='self loop'
            if self.rl<=0:
                invalid = True
                errmsg+='route length is invalid (negative)'
            if self.rw<=0:
                invalid = True
                errmsg += 'route width is invalid (negative)'
        except :
            errmsg+='One or Both node aren\'t reals' 
            invalid = True
        if invalid:
            self.printInfo()
            return errmsg
        else:
            return 'OK'

    def printInfo(self):
        print('from node {0} to node {1},length is {2},width is {3} and limit is {4}'.format(self.snode,self.enode,self.rl,self.rw,self.limit)) 


def writeMap(roads, n, approach):
    Map = []
    approach_width = [0.5, 1.5, 2, 4, 6]
    for i in range(n):
        Map.append([])
        for j in range(n):
            Map[i].append(float("inf"))

    for i in roads:
        if i.limit[5 - approach] == "0":
            continue
        if i.rw < approach_width[approach - 1]:
            continue
        else:
            if Map[i.snode][i.enode] == float("inf"):
                Map[i.snode][i.enode] = i.rl
            elif Map[i.snode][i.enode] > i.rl:
                Map[i.snode][i.enode] = i.rl

    for i in roads:
        if not Map[i.snode][i.enode] == i.rl:
            roads.remove(i)
    return Map, roads


def Guide(Map, start, end):
    dis = []
    path = []
    output = {}
    for i in range(len(Map)):
        dis.append(Map[start][i])
        path.append([start, i])
    for i in range(len(Map)):
        if not i == start:
            for j in range(len(Map[i])):
                if dis[i] + Map[i][j] < dis[j]:
                    dis[j] = dis[i] + Map[i][j]
                    path[j] = path[i] + [j]
    if not dis[end] == float("inf"):
        output["path"] = list(map(str, path[end]))
        output["length"] = dis[end]
    else:
        output["length"] = float("inf") 
    return output

Map = []
roads = []
start = -1
end = -1
approach = 0
approach_list = [1, 2, 3, 4, 5]
output = {}
output_str = ""
output_list = []

File = open("test3.txt", "r")
read_list = File.readlines()
File.close()
read_list[-1] += "\n"
n = int(read_list[0][0:-1])
read_list.pop(0)
for i in read_list:
    i = i[0:-1]
    split_list = i.split(" ")
    start = split_list[0]
    end = split_list[1]
    length = float(split_list[2])
    width = float(split_list[3])
    limit = ""
    if len(split_list) == 4:
        approach_width = [6, 4, 2, 1.5, 0.5]
        for i in approach_width:
            if float(split_list[3]) <= i:
                limit += "1"
            else:
                limit += "0"
    else:
        limit = str(split_list[4])
    new_road = road(start, end, length, width, limit)
    check = new_road.exam(n)
    if check == "OK":
        roads.append(new_road)
    else:
        print(check)

input_list = input("Please input start node, end node, and approach: ").split(" ")
start = int(input_list[0])
end = int(input_list[1])
approach = int(input_list[2])
Map, roads = writeMap(roads, n, approach)
output = Guide(Map, start, end)
if not output["length"] == float("inf"):
    output_str += "path: " + " -> ".join(output["path"])
    output_str += "\ntotal length: " + str(output["length"])
    for i in range(len(output["path"]) - 1):
        for j in roads:
            if str(j.snode) == output["path"][i] and str(j.enode) == output["path"][i + 1]:
                output_list.append(j.printInfo())
else:
    output_str = "There's no path from " + str(start) + " to " + str(end)
print(output_str)

File = open("t2_out.txt", "w")
File.write(output_str)
File.close()
#os.system("PAUSE")