#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find largest prefix which is also a suffix 
int largest_prefix_suffix(const std::string &str) { 
    
  int n = str.length(); 
    
  if(n < 2) { 
    return 0; 
  } 
  
  int len = 0; 
  int i = n/2; 
    
  while(i < n) { 
    if(str[i] == str[len]) { 
      ++len; 
      ++i; 
    } else { 
      if(len == 0) { // no prefix 
        ++i; 
      } else { // search for shorter prefixes 
        --len; 
      } 
    } 
  } 
    
  return len; 
  
} 
  
// Driver code 
int main() { 
      
string s = "blablabla"; 
  
cout << largest_prefix_suffix(s); 
  
return 0; 
} 
