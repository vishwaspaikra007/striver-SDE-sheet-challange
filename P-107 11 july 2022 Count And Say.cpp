// striver SDE sheet challange Count And Say
// author Vishwas Paikra
string writeAsYouSpeak(int n) 
{
    string str = "1";
	while(--n) {
        int cnt = 1;
        int m = str.size();
        char a = str[0];
        string temp = "";
        for(int i = 1; i < m; ++i) {
            if(a == str[i]) ++cnt;
            else {
                temp += ('0'+cnt);
                temp += a;
                a = str[i];
                cnt = 1;
            }
        }
        temp += ('0'+cnt);
        temp += a;
        str = temp;
    }	
    return str;
}
