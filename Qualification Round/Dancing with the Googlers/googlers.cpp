#include <iostream>

using namespace std;

int main(){
    int t; // test cases
    int n; // number of googlers
    int s; // number of suprising scores
    int p; // best result of at least p
    int g[100];
    
    cin >> t;
    
    // for each test case
    for(int i = 0; i < t; i++){
            cin >> n;
            cin >> s;
            cin >> p;
            
            // if the googler has at list L points, it's ok
            int L = p; // L is the minimal total score that is not surprising;
            int Laux = (p-1)*2;
            if(Laux < 0) Laux = 0;
            L += Laux;
             
            int LS = p; // LS is the minimal total score that is suprising;
            int LSaux = + (p-2)*2;
            if(LSaux < 0) LSaux = 0;
            LS += LSaux;
 
 
            int sure = 0;
            int maybe = 0;             
            
            // read for each googler
            for(int j = 0; j < n; j++){
                    
                    // read data
                    cin >> g[j];
                    
                    // update sure and maybe
                    if(g[j] >= L){
                            sure++;        
                    }
                    else if(g[j] >= LS){
                         maybe++;     
                    }         
            }

            // only S maybes could reach p
            if(maybe > s)
                     maybe = s;

            // add surprising
            
            int result = sure + maybe;
            
            cout << "Case #" << i+1 << ": " << result << endl;
            }
}
