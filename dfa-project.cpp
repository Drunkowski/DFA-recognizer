#include<iostream>
#include<string>
#include<cctype>
using namespace std;

typedef struct Node{
        string name;
        bool Final = 0;
        struct Node *a  = NULL;
        struct Node *b = NULL;
    } State;

class ab {

    State q0,q1,q2;

    public:
    ab(){
        q0.name = "q0";
        q1.name = "q1";
        q2.name = "q2";
      

        q1.Final = 1;
        
        
        
        q0.a = &q1;
        q0.b = &q2;
    
    
    
        q1.a = &q2;
        q1.b = &q1;
     
     
     
        q2.a = &q2;
        q2.b = &q2;
    }
    
    bool check(string is) {
        State * presentState = &q0;
        for(char c:is){
            if(c == 'a'){
                presentState = presentState->a;
            }else{
                presentState = presentState->b;        
            }
        }
        return presentState->Final;
    }

};


int main(){
    string alphabet ="ab";
    string input;
    ab dfa;
	getline(cin, input);
for (char c : input) {
    if (isspace(c)) {
        cout << "your input does not match the alphabet" << endl;
        return 0;
    }
    if (alphabet.find(c) == string::npos) {
        cout << "your input does not match the alphabet" << endl;
        return 0;
    }
}
    bool accepted = dfa.check(input);
    if(accepted) 
	cout<<"accepted";
    else
	cout<<"not accepted";
    return 0;
}
