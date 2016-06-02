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
  string arr;
  for((!newdic[i]==EOF)||(newdic[i].first>=maxlen)){
    if(newdic[i].left=ILL){
      arr=sort_letters(newdic[i].second);
      if(arr.equals(str)){
	maxlen=newdic[i].first;
	cout<<newdic[i].second<<endl;
      }
      i++;
    }      
    else if(newdic[i].first<ILL){
      int j=0,k=0;
      arr=sort_letters(newdic[i].second);
      while(k<=ILL){
	if(arr[j]=str[k]){
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
  mk_newdic(open_dic());
  str=sort_letters(read_letters());
  
}

