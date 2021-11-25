#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class route{
    public:
        double snode, enode,limit;
        int intsnode,intenode;
        double rl,rw;

        void setValue(double,double,double,double,double);
        bool exam(int);
        void print();
        void transfer(int);
}Sample;
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
void route::setValue(double s,double e,double l,double w,double lm){
    snode=s;
    enode=e;
    rl=l;
    rw=w;
    limit=lm;

}
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
void route::print(){
    cout<<"From node"<<snode<<"to"<<enode<<", the distance is"<<rl<<", road width is"<<rw<<",road limitation is"<<limit<<endl;
}

int miniDistance(int dist[],bool sptSet[],int V){
    int min=INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
int main(int argc, char const *argv[])
{
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
            nodemap[i][j][0]=INT_MAX;
            nodemap[i][j][1]=INT_MAX;
            nodemap[i][j][2]=INT_MAX;
        }
    }

    double s,e,l,w,lm;
    while (inputfile>>s>>e>>l>>w>>lm){
        int is,ie;
        //inputfile>>s>>e>>l>>w>>lm;
        Sample.setValue(s,e,l,w,lm);
        bool result = Sample.exam(n);
        Sample.transfer(result);
        if (result){
            //TODO 缺驗證內容，以路寬為基準，限制為輔
            int is=s;
            int ie=e;
            cout<<"write position:"<<is<<","<<ie<<"info"<<l<<w<<lm<<endl;
            nodemap[is][ie][0]=l;
            nodemap[is][ie][1]=w;
            nodemap[is][ie][2]=lm;
        }
        cout<<s<<" "<<e<<" "<<l<<" "<<w<<" "<<lm<<" "<<(result?"Valid":"Invalid")<<endl;
        starts.push_back(s);
        ends.push_back(e);
        ls.push_back(l);
        ws.push_back(w);
        limits.push_back(lm);
    }
    inputfile.close();

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
        int u=miniDistance(dist,sptSet,n);
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
