#include<iostream>
#include<iomanip>

using namespace std;

int main(){
	long long int n;
  	long long int m;
    int t=1,time=0;
    while(cin>>n){
      time++;
      t=1;
      m=0;
      cout<<fixed<<setw(4)<<time<<".";

      if(n/1000000000>0){
      m=n%10000000;
      n=n/10000000;
        t=2;
      }
      while(t){
      if(n/10000000>0){
      cout<<" "<<n/10000000<<" kuti";
      }
      n=n%10000000;
      
      if(n/100000>0){
      cout<<" "<<n/100000<<" lakh";
      }
      n=n%100000;
      
      if(n/1000>0){
      cout<<" "<<n/1000<<" hajar";
      }
      n=n%1000;
      
      if(n/100>0){
      cout<<" "<<n/100<<" shata";
      }
      n=n%100;

      if(n>0&&t==2){
      cout<<" "<<n<<" kuti";
      }else if(n>0){
      cout<<" "<<n;
      }
      t--;
      n=m;
        
      }
    cout<<endl;
    }
      
    }