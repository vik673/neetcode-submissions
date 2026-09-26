class Solution {
public:

    bool isSubString(string a, string b)
    {
        int j=0;
        int m = b.size();
        for(int i=0; i<=a.size() - m; i++)
        {
            j=0;
            while(j<m && a[i+j] == b[j]) j++;
            if(j==m) return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
         vector<string> stringMatchingArray;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size(); j++)
            {
                if(isSubString(words[j], words[i])){
                   stringMatchingArray.push_back(words[i]);
                   break;
                }
            }
        }
        return stringMatchingArray;
    }
};