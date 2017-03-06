/***
 *  Author: Daniel Palacio
 */
 #include <fstream>
 #include<iostream>
 #include <map>
 #include<string>
 #include<algorithm>
 #include<cctype>
 #include<sstream>
 #include<bits/stdc++.h>


 using namespace std;

 int min(int x,int y,int z){
   return min(min(x,y),z);
 }
  int editDistance(string n , string m ,int _n, int _m){
  if(_n == 0) return _m;
  if(_m == 0) return _n;
  if(n[_n-1] == m[_m-1]) return editDistance(n,m,_n-1,_m-1);
  return 1 + min(editDistance(n,m,_n,_m-1),editDistance(n,m,_n-1,_m),editDistance(n,m,_n-1,_m-1));
}

 int main(int argc, char const *argv[]){
   ifstream txt(argv[1]);
   string line;
   string vocab;
   string input;
   int feq;

   std::map<string,int> map;
   std::map<string,int> newMap;
   std::map<string,int>::iterator it;
   std::map<string,int>::iterator _it;
   std::map<string,int>::iterator pt;
   int count=0;



   if(txt.is_open()){
     do{

       getline(txt,line);
       if(!line.empty()){
         istringstream is(line);
         string sub;
         is>>sub;
         vocab=sub;
         //std::cout << sub << std::endl;
         is>>sub;
         feq = stoi(sub);
         map.emplace(vocab,feq);
         //std::cout << feq << vocab << std::endl;
       }

     }while(!line.empty());

   }
   while(cin >> input){


    for(it = map.begin();it!=map.end();++it){


      int distance = editDistance(input,it->first,input.length(),it->first.length());
      if(distance == 0){
        // if(count!=0)   it->second++;
        // count=count+1;

        std::cout << it->first << " "  << it->second << std::endl;
        it->second++;
        break;
      }






  }


   }




return 0;
 }
