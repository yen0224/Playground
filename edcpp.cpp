#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class route{
    public:
        double snode, enode,limit;
        double rl,rw;

        void setValue(double,double,double,double,double);
        bool exam(int);
        void print();
}Sample;
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

int main(int argc, char const *argv[])
{
    vector<int> starts,ends,ls,ws,limits;
    //open files
    ifstream inputfile;
    inputfile.open("test3.txt");
    if(!inputfile.is_open()){
        cout<<"Failed to open files, program stopped";
        return 0;//end program
    }
    else{
        int n;
        //nodemap:[0]road length [1]road width [2]limit
        inputfile>>n;
        float nodemap[n][n][3];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nodemap[i][j][0]=999999;
                nodemap[i][j][1]=999999;
                nodemap[i][j][2]=999999;
            }
            
        }
        double s,e,l,w,lm,sw;
        while (inputfile>>s>>e>>l>>w>>lm){
            //inputfile>>s>>e>>l>>w>>lm;
            if(s>e){
                sw=s;
                s=e;
                e=sw;
            }
            Sample.setValue(s,e,l,w,lm);
            int result = Sample.exam(n);
            if (result){
                //TODO 缺驗證內容，以路寬為基準，限制為輔
                int ints=int(s);
                int inte=int(e);
                nodemap[ints][inte][0]=l;
                nodemap[ints][inte][1]=w;
                nodemap[ints][inte][2]=lm;
            }
            cout<<s<<" "<<e<<" "<<l<<" "<<w<<" "<<lm<<" "<<(result?"Valid":"Invalid")<<endl;
            starts.push_back(s);
            ends.push_back(e);
            ls.push_back(l);
            ws.push_back(w);
            limits.push_back(lm);
        }
        inputfile.close();
    }
    return 0;
}
