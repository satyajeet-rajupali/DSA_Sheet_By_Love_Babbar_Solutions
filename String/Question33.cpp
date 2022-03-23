#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

struct Key
{
    int freq;
    char ch;

    bool operator<(const Key &k) const
    {
        return freq < k.freq;
    }
};

void showpq(priority_queue<Key> gq)
{
    priority_queue<Key> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top().ch << "\t" << g.top().freq << "\n";
        g.pop();
    }
    cout << '\n';
}

void rearrangeString(string str)
{
    int n = str.length();
    int count[MAX_CHAR] = {0};

    for (int i = 0; i < n; i++)
        count[str[i] - 'a']++;

    priority_queue<Key> pq;

    for (char c = 'a'; c <= 'z'; c++)
    {
        int val = c - 'a';
        if (count[val])
        {
            pq.push(Key{count[val], c});
        }
    }

    str = "";

    Key prev{-1, '#'};

    while (!pq.empty())
    {
        Key k = pq.top();
        pq.pop();
        str = str + k.ch;

        if (prev.freq > 0)
            pq.push(prev);

        (k.freq)--;
        prev = k;
    }

    if (n != str.length())
    {
        cout << "Not a valid string\n";
    }
    else
        cout << str << "\n";
}

char getMaxCounterChar(const vector<char> vec)
{
    int max = -1;
    char ch;
    for (int i = 0; i < 26; i++)
    {
        if (vec[i] > max)
        {
            max = vec[i];
            ch = i + 'a';
        }
    }
    return ch;
}

string method2(string str)
{
    int n = str.length();
    if (!n)
        return "empty";

    vector<char> count(26, 0);
    for (auto it : count)
        count[it - 'a']++;

    char maxchar = getMaxCounterChar(count);
    int maxCount = count[maxchar - 'a'];

    if (maxchar > (n + 1 / 2))
        return "empty";

    string res(n, ' ');

    int ind = 0;

    while (maxCount)
    {
        str[ind] = maxchar;
        ind += 2;
        maxCount--;
    }

    for (int i = 0; i < 26; i++)
    {
        while (count[i] > 0)
        {
            ind = ind >= n ? 1 : ind;
            str[ind] = 'a' + i;
            ind += 2;
            count[i]--;
        }
    }
    return str;
}


// char getMaxCounterChar(const vector<char> c){
    
//     int max(-1);
//     char ch;
    
//     for(int i=0; i<26; i++){
//         if(c[i] > max){
//             max = c[i];
//             ch = i + 'a';
//         }
            
//     }
//     return ch;
// }


int rearrangeCharacters(string str){
    
    int n = str.length();
    cout<<"Length: "<<n<<"\n";
    if (n==0)
        return 0;

    vector<char> count(26, 0);
    for (auto it : count)
        count[it - 'a']++;

    char maxchar = getMaxCounterChar(count);
    int maxCount = count[maxchar - 'a'];

    if (maxCount > ((n + 1) / 2))
        return 0;

    string res(n, ' ');

    int ind = 0;

    while (maxCount)
    {
        str[ind] = maxchar;
        ind += 2;
        maxCount--;
    }

    for (int i = 0; i < 26; i++)
    {
        while (count[i] > 0)
        {
            ind = ind >= n ? 1 : ind;
            str[ind] = 'a' + i;
            ind += 2;
            count[i]--;
        }
    }
    
    if(res.length() == str.length())
        return 1;
    return 0;
    
    
    
}


int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    cout<<rearrangeCharacters(str)<<"\n";
	}
	return 0;
}