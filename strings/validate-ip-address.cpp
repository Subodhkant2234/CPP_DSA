class Solution {
  public:
    int isValid(string &s) {
        int count = 0;
        string tmp = "";
        s += '.';
        for(char c : s){
         
         if(c =='.'){
            if(tmp.empty() || tmp.size() > 3)
                return 0;
            
            for(char ch : tmp){
                if(!isdigit(ch)) return 0;
            }
            
            if(tmp.size() > 1 && tmp[0] == '0')
                return 0;
            int num = stoi(tmp);
            if(num < 0 || num > 255) 
                return 0;
            tmp = "";
            count++;
         } else {
            tmp += c;    
         }
         
        }
        return count == 4;
    }
};
