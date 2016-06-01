//searchdic.cpp

#include<iostream>
#include<string>

#define ILL 16

using namespace std;

//target:
//not sort all of the word in dic.
//pick up a word and sort
//
int maxlen=0;

class Words
{
public:
  string name;
  int len;
  bool jud;
  Words(){}
  Words(string n){
}

    
};

    

void compare_length(string a,string b){

}

//read 16 letters from console
//while the length is not good, repeat reading
string read_letter(){
  string l;

  do{
  cout << "please put " << ILL <<" letters."<<endl;
  cout << "your input is:"<<endl;
  cin >> l;
  }while(l.size()!=ILL);

  return l;
}



int main(){
  read_letter();
}
