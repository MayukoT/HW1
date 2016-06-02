//searchdic.cpp

#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>

#define ILL 16

using namespace std;

int maxlen=0;
ifstream dic;

//these are for a new dic
typedef pair<int,string> dicpair;
vector<dicpair> newdic;


//sort charaters in the word
string sort_letters(string inp){
  sort(inp.begin(),inp.end());
  return inp;
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
  l=sort_letters(l);
  return l;
}


//main
int main(){

  //read from stdin
  string str;
  str=read_letters();
  //end of read from stdin

  //open dictionary
  ifstream dic;
   dic.open("/usr/share/dict/words");
   if(dic.fail()){
     cout<<"failed to open file"<<endl;
    exit(EXIT_FAILURE);
   }
   //end of open dictionary


   // make newdictionary;
  string s;
  while(1){
    getline(dic,s);
    newdic.push_back(dicpair(s.size(),s));
    
    if(dic.eof()){
      break;
    }
  }
  sort(newdic.begin(),newdic.end(),greater<pair<int,string> >());
  //end of make newdictionary



  //compare & search 
  long i=0;
  string arr;
  while(newdic[i].first>=maxlen){
    if(newdic[i].first>ILL){
      i++;
    }
    else if(newdic[i].first==ILL){
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
	    j++;k++;
	  }	    
	}
	else{
	  k++;
	}
      }
      i++;      
    }
  }
  //end of compare & search
  
  return 0;  
  
}
