#include <iostream>
#include <istream>
using namespace std;

int main(){

    char letters[256];
    for(int i = 0; i < 256; i++){
            letters[i] = i;        
    }
    letters['a'] = 'y';
    letters['b'] = 'h';
    letters['c'] = 'e';
    letters['d'] = 's';
    letters['e'] = 'o';
    letters['f'] = 'c';
    letters['g'] = 'v';
    letters['h'] = 'x';
    letters['i'] = 'd';
    letters['j'] = 'u';
    letters['k'] = 'i';
    letters['l'] = 'g';
    letters['m'] = 'l';
    letters['n'] = 'b';
    letters['o'] = 'k';
    letters['p'] = 'r';
    letters['q'] = 'z';
    letters['r'] = 't';
    letters['s'] = 'n'; 
    letters['t'] = 'w';
    letters['u'] = 'j';
    letters['v'] = 'p';
    letters['w'] = 'f';
    letters['x'] = 'm';
    letters['y'] = 'a';
    letters['z'] ='q';
    
    int t;
    cin >> t;
    char w[101];
    char r[101];
    cin.getline(w, 101);
    for(int i = 0; i < t; i++){
            cin.getline(w, 101);
            //cout << w << endl;
            int j = 0;
            for(j = 0; j < strlen(w); j++){
                    r[j] = letters[w[j]];
            }
            r[j] = '\0';
            cout << "Case #" << i+1 << ": " << r << endl; 
    }
    
}
