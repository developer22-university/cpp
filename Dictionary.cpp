#include <iostream>
using namespace std;

struct Trie{
    bool isend;
    unordered_map<char,Trie*>mp;
    string  meaning;
};

Trie* getnode(){
    Trie* node=new Trie;
    node->isend=false;
    return node;
}

void insert(Trie*& root,const string &a,const string &b){
    if(root==NULL){
     root=getNode();
    }
    
    Trie* temp=root;
    for(int i=0;i<a.length();i++){
        char c=a[i];
        if(temp->mp.find(c)==temp->mp.end()){
            temp->mp[c]=getnode();
        }
        temp=temp->mp[c];
    }
   temp->isend=false;
   temp->meaning=b;
}


string getmeaning(Trie* root,const string& word){
    if(root==NULL){
        return "";
    }

   Trie* temp=root;
   for(int i=0;i<word.length();i++){
       temp=temp->mp[word[i]];
       if(temp==NULL){
           return "";
       }
   }
if(temp->isend){
    return temp->meaning;
}
  
  return "";  
}

int main(){
    Trie* root=NULL;
   insert(root, "language", "the method of human communication"); 
    insert(root, "computer", "A computer is a machine that can be \ 
    instructed to carry out sequences of arithmetic or \ 
logical operations automatically via computer programming"); 
    insert(root, "map", "a diagrammatic representation \ 
of an area"); 
    insert(root, "book", "a written or printed work \ 
consisting of pages glued or sewn together along one \ 
side and bound in covers."); 
    insert(root, "science", "the intellectual and \ 
practical activity encompassing the systematic study \ 
of the structure and behaviour of the physical and \ 
natural world through observation and experiment."); 
string str="science";
cout<<getmeaning(root,str)<<endl;
}




