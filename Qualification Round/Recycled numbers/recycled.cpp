#include <iostream>

using namespace std;

bool isCalculated[2000001];

int permutations[2000001][4];

int numPermutations[2000001];

int intlen(int n) { 
    int result = 0;
    //cout << n;
     
    while(n >= 1) { 
                n = n/10; 
                result++; 
    }
    //cout << " is of length " << result << endl; 
    return result; 
}

int nextPermutation(int n,int lenn, int len){
    int aux = 1;
    for(int i = 0; i < len; i++)
            aux*=10;
    
    int div = n/aux;
    int mod = n%aux;
    
    len = 4-lenn;
    aux = 1;
    for(int i = 0; i < len; i++)
            aux*=10;
    return mod*aux+div;    
}

void calculatePermutations(int n){
     int perm = n;
     permutations[n][0] = n; // n is a permutation of itself

     int len = intlen(n); // length
     // always n-1 permutations

     int auxH = 10;
     int auxT = 1;
     for(int i = 0; i < len-1; i++)
             auxT*=10;
     
     int head, tail;
     for(int i = 1; i < len; i++){
            head = n/auxH;
            tail = n%auxH;
            
            permutations[n][i] = tail*auxT+head;
            
            auxH*=10;
            auxT/=10;
            //cout << permutations[n][i] << " is a permutation of " << n << endl;        
     }

     numPermutations[n] = len;
     isCalculated[n] = true;                                                              
}

int check(int n, int m){ // check if 
    int len = numPermutations[n];
    
    for(int i = 0; i < len; i++){
            if(m == permutations[n][i]) return 1;        
    }
    return 0;
}

int main(){

    int t; // number of tests cases
    int a;
    int b;
    int result;
    
    //for(int i = 0; i < 1001; i++) isCalculated[i] = false;
    
    cin >> t;
    
    
    // fore each test case
    for(int i = 0; i < t; i++){
            
            // Input
            cin >> a;
            cin >> b;
            // Logic
            
            result = 0;
            
            // Calculate permutations
            
            for(int j = a; j <=b; j++){
                    if(!isCalculated[j])
                                        calculatePermutations(j);        
            }
            
            // Calculate recycled numbers
            for(int n = a; n < b; n++){
                    for(int m = n+1; m <= b; m++){
                            result += check(n,m); 
                    }
            }
            
            // Output
            
            cout << "Case #" << i+1 << ": " << result << endl;  
            
            
    }   
    
}
