//searchdic.cpp

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

#define ILL 16
#define DICLEN 1000000

using namespace std;

int maxlen=ILL;

//not used. changed to pair
/*class Words
{
public:
  string wd;
  int len;
  Words(){}
  Words(string w){
    wd = w;
    len = w.size();
  }  
};
*/

//vector  this is a new dic
vector<pair<int,string> > newdic;


//open dic
ifstream open_dic(){
  ifstream dic("/usr/share/dict/words");
  if(dic.fail()){
    cout<<"failed to open file"<<endl;
  }
  return dic;
}


//make a new dic (also has length of the word)
int mk_newdic(ifstream ifs){
  string s;
  while(!ifs.eof()){
    getline(ifs, s);
    if(s.size()<=ILL){
      newdic.push_back(<s,s.size()>);
    }
  }
  sort(newdic.begin()&left,newdic.end()&right,greater<int>());
  return 0;  
}


//length of inp-dw
int compare_length(string inp,string dw){
  int dif;
  dif = inp.size()-dw.size();
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
  for(!newdic[i]==EOF){
    if(newdic[i].left=ILL){
      string arr;
      arr=sort_letters(newdic[i].second);
      if(arr.equals(str)){
	maxlen=newdic[i].first;
      }
      i++;
    }      
    else if(newdic[i].first<ILL){

      
    }
  }
}



//main
int main(){
  string str;
  mk_newdic(open_dic());
  str=sort_letters(read_letters());
  
}

