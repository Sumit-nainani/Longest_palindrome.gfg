// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] 
// where 0 ≤ i ≤ j < len(S). Palindrome string: A string that reads the same backward. More formally, 
// S is a palindrome if reverse(S) = S.In case of conflict, return the substring which occurs 
// first ( with the least starting index).

/*
approach:
    we will use dp here for checking a palindrome from i to j we will check whether ith nad jth character is equal
    and i+1 to j-1 string is palindrome or not.
*/
string longestPalin (string s) {
    
        string neww;
        int mx=0;
        int sz=s.size();
        bool t[sz][sz];
        memset(t,false,sizeof(t));
        for(int i=0;i<sz;i++) t[i][i]=true;
        mx=1;
        int strt=0;
        for(int i=0;i<sz-1;i++){
            if(s[i]==s[i+1]){
                t[i][i+1]=true;
                if (strt==0 and mx==1){
                    strt=i;
                    mx=2;
                }
            }
        }
        
        for(int k=3;k<=sz;k++){
            int st(-1),e(-1);
            for(int i=0;i<sz-k+1;i++){
                if(s[i]==s[i+k-1] && t[i+1][i+k-2]){
                    t[i][i+k-1]=t[i+1][i+k-2];
                    strt=i;
                    mx=k;
                    if(st==-1 && e==-1){
                        st=strt;
                        e=mx;
                    }
                    strt=st;
                    mx=e;
                }
            }
        }
        for(int i=strt;i<strt+mx;i++) neww.push_back(s[i]);
        return neww;