#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class route{
    public:
        double snode, enode,limit;
        int intsnode,intenode,truelimit;
        double rl,rw;

        void setValue(double,double,double,double,double);
        bool exam(int);
        void print();
        void checklm();
        void transfer(int);
}Sample;

//class
//checklm(): 以路寬將錯誤的定義刪除

void route::checklm(void){
    //roadlimit=[0.5,1.5,2,4,6];
    //11111全可過
    //01111
    //00111
    //若路寬為最大，則不需改道路通行限制
    truelimit=limit;
    if(rw>=6.){
        truelimit=limit;
    }
    else if(rw>=4. and limit>10000){
        truelimit%=10000;
    }
    else if(rw>=2 and limit>111){
        truelimit%=1000;
    }
    else if(rw>=1.5 and limit>11){
        truelimit%=100;
    }
    else if(rw>=0.5 and limit>1){
        truelimit%=10;
    }
}

//class
//小數、整數轉換

void route::transfer(int result){
    if(result){
    intsnode=int(snode);
    intenode=int(enode);
    }
    else{
        intsnode=0;
        intenode=0;
    }
}

//class
//設值

void route::setValue(double s,double e,double l,double w,double lm){
    snode=s;
    enode=e;
    rl=l;
    rw=w;
    limit=lm;
}

//class
//驗證資料＆略過錯誤資料

bool route::exam(int n){
    bool valid=true;
    if (snode<0 or snode>=n or enode<0 or enode>=n){
        cout<<"Node is out of range.";
        valid=false;
    }
    if(snode!=int(snode)||enode!=int(enode)){
        cout<<"One of or Both of Node is/are not integers.";
        valid=false;
    }
    if(snode==enode){
        cout<<"self loop";
        valid=false;
    }
    if (rl<0){
        cout<<"road length is negative";
        valid=false;
    }
    if(rw<0){
        cout<<"road width is negative";
        valid=false;
    }
    
    return valid;
    
}
//輸出
void route::print(){
    cout<<"From node"<<snode<<"to"<<enode<<", the distance is"<<rl<<", road width is"<<rw<<",road limitation is"<<limit<<endl;
}


int main(int argc, char const *argv[])
{
    //read file
    int n;
    vector<int> starts,ends,ls,ws,limits;
    //open files
    ifstream inputfile;
    inputfile.open("test3.txt");
    //nodemap:[0]road length [1]road width [2]limit
    inputfile>>n;
    cout<<"n="<<n<<endl;
    double nodemap[n][n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //3D array initialize
            nodemap[i][j][0]=INT_MAX;
            nodemap[i][j][1]=INT_MAX;
            nodemap[i][j][2]=INT_MAX;
        }
    }

    double s,e,l,w,lm;
    //write file data into 3-D array
    while (inputfile>>s>>e>>l>>w>>lm){
        int is,ie;
        Sample.setValue(s,e,l,w,lm);
        bool result = Sample.exam(n);
        Sample.transfer(result);
        if (result){
            int is=s;
            int ie=e;
            Sample.checklm();
            //cout<<"write position:"<<is<<", "<<ie<<"info "<<l<<w<<lm<<endl;
            nodemap[is][ie][0]=l;
            nodemap[is][ie][1]=w;
            nodemap[is][ie][2]=Sample.truelimit;
        }
        //cout<<s<<" "<<e<<" "<<l<<" "<<w<<" "<<lm<<" "<<(result?"Valid":"Invalid")<<endl;
        starts.push_back(s);
        ends.push_back(e);
        ls.push_back(l);
        ws.push_back(w);
        limits.push_back(lm);
    }
    inputfile.close();
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"road width is "<<nodemap[i][j][1]<<" limit is"<<nodemap[i][j][2]<<endl;
        }
        
    }
    */
    cout<<"Please input start node, end node, and approach:";
    int start,end,approach;
    cin>>start>>end>>approach;
    //符合陣列的index
    start-=1;end-=1;
    int dist[n];
    bool sptSet[n];
    for (int i = 0; i < n; i++)
    {
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }
    dist[0]=0;
    for (int ct = 0; ct < n-1; ct++)
    {
        int min=INT_MAX, min_index;
        for (int v = 0; v < n; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
        int u=min_index;
        sptSet[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (!sptSet[v] && nodemap[u][v][0] && dist[u] != INT_MAX && dist[u] + nodemap[u][v][0] < dist[v])
                dist[v] = dist[u] + nodemap[u][v][0];
        }
    }
for (int i = 0; i < n; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
return 0;
}
