#ifndef ___Reverse_String_344_h___
#define ___Reverse_String_344_h___
#incldue<stack>



class Solution {
public:
    struct testCase
    {
        /*
        input ["A"," ","m","a","n",","," ","a"," ","p","l","a","n",","," ","a"," ","c","a","n","a","l",":"," ","P","a","n","a","m","a"]
        answer ["a","m","a","n","a","P"," ",":","l","a","n","a","c"," ","a"," ",",","n","a","l","p"," ","a"," ",",","n","a","m"," ","A"]
        
        */
    }
    void swap(vector<char>& s, int idx1, int idx2) {
        char c = s[idx1];
        s[idx1] = s[idx2];
        s[idx2] = c;
    }
    void reverser(vector<char>& s, int idx1, int idx2)
    {
        if (idx1 >= idx2)
            return;
        swap(s, idx1, idx2);
        reverser(s, ++idx1, --idx2);

    }
    void reverseString(vector<char>& s) {
        int idx1 = 0;
        int idx2 = s.size() - 1;
        reverser(s, idx1, idx2);
    }
};

#endif // !1
