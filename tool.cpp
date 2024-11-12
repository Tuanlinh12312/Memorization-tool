#include <bits/stdc++.h>
#define ld double
#define ll int
#define pll pair<ll, ll>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(a) ((ll)(a).size())
using namespace std;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll random(ll l, ll r) {return l+rng()%(r-l+1);}

const ll YCNT=1; // # of yes(es) needed to remove a question
const ll YSKIP=5; // # of rounds skipped if responded yes
const ll USKIP=2; // # of rounds skipped if responded unsure
const ll NSKIP=1; // # of rounds skipped if responded no

int main()
{
    // change question file by changing ifstream inp
    ifstream inp("questions_senses.txt");
    ll n; inp >> n;
    vector <string> questions(n);
    for (string& s:questions) getline(inp, s);
    vector <string> round[100]; 
    round[1]=questions;
    ll crmax=1;
    map <string, ll> cnt;
    // ask question s at round r
    auto push=[&](string s, ll r)
    {
        if (cnt[s]==2) return; // if a question gets Y
        round[r].pb(s);
        crmax=max(crmax, r);
    };
    // iterate through rounds as long as there are still unsure questions
    for (ll i=1, acc=0; i<=crmax; i++) 
    {
        shuffle(round[i].begin(), round[i].end(), rng);
        // accumulator: if a round has no questions then skip and indices are shifted
        if (!sz(round[i])) {acc++; continue;}
        cout << "Round " << i-acc << ":\n";
        for (ll j=0; j<sz(round[i]); j++)
        {
            string s=round[i][j];
            cout << "(" << j+1 << "/" << sz(round[i]) << "): " << s << " (Y/N/U)\n";
            char response; cin >> response; // is Y/N/U
            if (response=='Y') push(s, i+YSKIP), cnt[s]++;
            else if (response=='U') push(s, i+NSKIP);
            else push(s, i+NSKIP);
        }
    }
}