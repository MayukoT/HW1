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
public:
  string wd;
  int len;
  bool jud;
  Words(){}
  Words(string w){
    wd = w;
    len = w.size();
    if(len>ILL){jud = false;}
    else{jud = true;}
  }  
};

Words newdic[DICLEN];

//open dic
int open_dic(){
  ifstream dic("/usr/share/dict/words");
  if(dic.fail()){
    cout<<"failed to open file"<<endl;
  } 
}

//make a new dic of class Words
int mk_newdic(ifstream ifs){
  int i=0;
  string s;
  while(){
    getline(ifs, s);
    Words wds(s);
    newdic[i]=wds;
  }  
}

//length of inp-dw
int compare_length(string inp,string dw){
  int dif;
  dif = inp.size-dw.size;
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

//sort charaters in the word
string sort_letters(string inp){
  sort(inp.begin(),inp.end());
  return inp;
}

//compare input and dicwords
void compare(string str){
  long i=0;
  for(){
    //when word len is longer than 16 :skip
    if(newdic[i].len>ILL){
      i++;
    }
    //when word len is exactly 16
    else if(newdic.len=ILL){
      string arr;
      arr=sort_letters(newdic[i].wd);
      if(arr.equals(str)){
	maxlen=newdic[i].len;
      }
      i++;
    }      
    else if(newdic[i].len<ILL){
      if(){
      }
    }
  }
}


//main
int main(){
  string str;
  str=sort_letters(read_letters());
}

