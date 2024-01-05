Run Length Encoding
Link:https://www.geeksforgeeks.org/problems/run-length-encoding/1

string encode(string src)
{     
  string result;
  for(int i=0; i<src.length(); ){
    char ch = src[i];
    result.push_back(ch);
    i++;
    int cnt =1;
    while(src[i] == ch){
        cnt++;
        i++;
    }
    result.append(to_string(cnt));
  }
  return result;
}