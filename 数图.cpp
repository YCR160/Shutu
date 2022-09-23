#include<bits/stdc++.h>
using namespace std;
int N,saverow[25][10][2]={0},savecol[25][10][2]={0},matrix[25][25]={0},ans=0;
void scan(int(*save)[10][2]){    
    for(int i=1;i<=N;i++){
        string s;
        while(s[0]=='\0')cin>>s;
        save[i][0][0]=s.length();
        for(int j=1;j<=save[i][0][0];j++){
            save[i][j][0]=s[j-1]-'0';
            save[i][0][1]+=save[i][j][0];
        }
    }
}
void create(int row,int(*save)[10][2],int* attempt){
    for(int i=1;i<=N;i++)attempt[i]=0;
    int pos=0;
    for(int i=1;i<=save[row][0][0];i++){
        if(i==1)pos=pos+save[row][i][1];
        else pos=pos+save[row][i][1]-save[row][i-1][1];
        for(int j=pos;j<pos+save[row][i][0]&&j<=N;j++){
            attempt[j]=1;
        }
        pos=pos+save[row][i][0];
    }
    //cout<<row<<"|";
    //for(int i=1;i<=N;i++)cout<<attempt[i]<<" ";
    //cout<<endl;
}
bool judge(int row,int mode,int* copy,int* attempt){
    if(mode==0)for(int i=1;i<=N;i++){
        if(attempt[i]&&matrix[row][i]==-1)return 0;
        if(!attempt[i]&&matrix[row][i]==1)return 0;
    }
    else if(mode==1)for(int i=1;i<=N;i++){
        if(attempt[i]&&matrix[i][row]==-1)return 0;
        if(!attempt[i]&&matrix[i][row]==1)return 0;
    }
    for(int i=1;i<=N;i++){
        if(attempt[i])copy[i]++;
    }
    return 1;
}
long long big(int a){
    long long ans=1;
    for(int i=1;i<=a;i++)ans*=i;
    return ans;
}
void addition(int row,int mode,int times,int* copy){
    if(mode==0)for(int i=1;i<=N;i++){
        if(copy[i]==times&&!matrix[row][i]){
            matrix[row][i]=1;
            ans--;
        }
        if(!copy[i]&&!matrix[row][i]){
            matrix[row][i]=-1;
            ans--;
        }
    }
    else if(mode==1)for(int i=1;i<=N;i++){
        if(copy[i]==times&&!matrix[i][row]){
            matrix[i][row]=1;
            ans--;
        }
        if(!copy[i]&&!matrix[i][row]){
            matrix[i][row]=-1;
            ans--;
        }
    }
}
void print(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(matrix[i][j]==1)printf("■ ");
            else if(matrix[i][j]==-1)printf("□ ");
                 else if(matrix[i][j]==0)printf(". ");
        }
        printf("\n");
    }
}
void _try_(int row,int(*save)[10][2],int mode){
    int copy[25]={0},attempt[25]={0},times=0;
    long long num=big(N+1-save[row][0][1])/(big(save[row][0][0])*big(N+1-save[row][0][1]-save[row][0][0]));
    for(int i=1;i<=save[row][0][0];i++){
        save[row][i][1]=i;
    }
    save[row][save[row][0][0]][1]--;
    for(int k=1;k<=num;k++){
        save[row][save[row][0][0]][1]++;
        int i=save[row][0][0];
        while(save[row][i][1]>N+1-save[row][0][1]-(save[row][0][0]-i)&&i>1){//进位
            save[row][i-1][1]++;
            i--;
        }        
        //if(save[row][1][1]>N-save[row][0][1])return;
        for(i++;i<=save[row][0][0];i++){
            save[row][i][1]=save[row][i-1][1]+1;
        }
        //if(save[row][N][1]>N+1-save[row][0][1]){
        //    k--;
        //    continue;
        //}
        create(row,save,attempt);
        if(judge(row,mode,copy,attempt))times++;
    }
    addition(row,mode,times,copy);
}
void search(){
    //int a=10;
    for(int i=1;i<=20&&ans;i++){
        for(int i=1;i<=N&&ans;i++){
            _try_(i,saverow,0);
            system("cls");
            cout<<i<<"行"<<endl;
            print();
            //for(int j=1;j<=30000000;j++){a%=j;}
            cout<<i<<endl;       
        }
        for(int i=1;i<=N&&ans;i++){
            _try_(i,savecol,1);
            system("cls");
            cout<<i<<"列"<<endl;
            print();
            //for(int j=1;j<=30000000;j++){a%=j;}
            cout<<i<<endl;
        }
    }
}
int main(){    
    cin>>N;
    ans=N*N;
    scan(saverow);
    scan(savecol);
    search();
    system("cls");
    print();
}
