//searchdic.cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>


#define ILL 16

using namespace std;

int maxlen=0;

//these are for a new dic
typedef pair<int,string> dicpair;
vector<dicpair> newdic;


//open dic
/*int open_dic(ifstream dic){
  ifstream dic("/usr/share/dict/words");
  if(dic.fail()){
    cout<<"failed to open file"<<endl;
    exit(EXIT_FAILURE);
  }
  return 0;
}
*/

//make a new dic (also has length of the word)
int mk_newdic(ifstream ifs){
  string s;
  while(!ifs.eof()){
    getline(ifs,s);
    if(s.size()<=ILL){
      newdic.push_back(dicpair(s.size(),s));
    }
  }
  //have to make operator
  sort(newdic.begin(),newdic.end(),greater<pair<int,string> >());
  return 0;  
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
  string arr;
  while(newdic[i].first>=maxlen){
    if(newdic[i].first==ILL){
      arr=sort_letters(newdic[i].second);
      if(arr==str){
	maxlen=newdic[i].first;
	cout<<newdic[i].second<<endl;
      }
      i++;
    }      
    else if(newdic[i].first<ILL){
      int j=0,k=0;
      arr=sort_letters(newdic[i].second);
      while(k<=ILL){
	if(arr[j]==str[k]){
	  if(j==arr.size()){
	    maxlen=newdic[i].first;
	    cout<<newdic[i].second<<endl;
	    break;
	  }else{
	    j++;k=0; 
	  }	    
	}
	else{
	  k++;
	}
      }      
    }
  }
}


//main
int main(){
  string str;
  str=read_letters();
  ifstream dic;
  dic.open("/usr/share/dict/words");
  if(dic.fail()){
    cout<<"failed to open file"<<endl;
    exit(EXIT_FAILURE);
  }
  mk_newdic(dic);
  compare(str);

  return 0;
}

