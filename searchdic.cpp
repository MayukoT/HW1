//searchdic.cpp

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

#define ILL 16
#define DICLEN 1000000

using namespace std;

int maxlen=0;


class Words
{
  string wd;
  int len;
  bool jud;
public:
  Words(){}
  Words(string w){
    wd << w;
    len << w.size();
    if(len>ILL){jud << false;}
    else{jud << true;}
  }  
};

//open dic
int open_dic(){
  ifstream dic("/usr/share/dict/words");
  if(!dic){
    cout<<"failed to open file"<<endl;
    exit(EXIT_FAILURE);
  } 
}

int mk_newdic(){

}

//length of inp-dw
int compare_length(string inp,string dw){
  int dif;
  dif << (inp.size-dw.size);
  return dif;
}

//read 16 letters from console
//while the length is not good, repeat reading
string read_letters(){
  string l;  
  do{
    cout << "please put " << ILL <<" letters."<<endl;
    cout << "your input is:"<<endl;
    cin >> l;
  }while(l.size()!=ILL);
  return l;
}

//sort
string sort_letters(string inp, int ilen){
  sort(inp.begin(),inp.end());
  return inp;
}

//main
int main(){
  read_letters();
}

void compare(){

} 
