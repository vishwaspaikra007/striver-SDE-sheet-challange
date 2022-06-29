// striver SDE sheet challange word-break-ii
// author Vishwas Paikra
void BT(string &s, vector<string> &dictionary, vector<string> &ans, int start, string &sentence) {
    if(start == s.size()) {
        sentence.erase(sentence.size()-1);
        ans.push_back(sentence);
        sentence += " ";
        return;
    }
    string temp = "";
    for(int i = start; i < s.size(); ++i) {
        temp += s[i];
        if(find(dictionary.begin(), dictionary.end(), temp) != dictionary.end()) {
            sentence += temp + " ";
            BT(s, dictionary, ans, i+1, sentence);
            sentence.erase(sentence.size()-temp.size()-1);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    string sentence = "";
    BT(s, dictionary, ans, 0, sentence);
    return ans;
}
