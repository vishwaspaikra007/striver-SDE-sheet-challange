// striver SDE sheet challange Reverse Words In A String
// author Vishwas Paikra
string reverseString(string str)
{
    string ans = "", temp = "";
    int n = str.size();
    for(int i = n-1; i >= 0; --i) {
        if(str[i] != ' ')
            temp = str[i] + temp;
        else if(temp != "") {
            ans += temp + ' ';
            temp = "";
        }
    }
    if(temp != "")
        ans += temp;
    return ans;
}
