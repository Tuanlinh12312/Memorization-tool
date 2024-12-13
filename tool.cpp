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

const bool ShowAns=1; // 1 if the question bank contains answers
const ll YCNT=1; // # of yes(es) needed to remove a question
const ll YSKIP=5; // # of rounds skipped if responded yes
const ll USKIP=2; // # of rounds skipped if responded unsure
const ll NSKIP=1; // # of rounds skipped if responded no

struct question
{
    string Q, A;
    question(){Q=A="";}

    bool operator<(const question& o) const
    {   
        return Q<o.Q;
    }

    friend istream &operator>> (istream &stream, question &question)
    {
        getline(stream, question.Q);
        if (ShowAns) getline(stream, question.A);
        return stream;
    }

    friend ostream &operator<< (ostream &stream, question &question)
    {
        stream << question.Q;
        return stream;
    }
};

int main()
{
    // change question file by changing ifstream inp
    ifstream inp("questionsWithAns.txt");

    // read questions
    ll n; inp >> n; 
    inp.ignore(256, '\n');
    vector <question> questions(n); 
    for (question& s:questions) inp >> s;

    // initialize rounds
    vector <question> round[100]; 
    round[1]=questions;

    // count Ys of a question
    ll crmax=1;
    map <question, ll> cnt;

    // ask question s at round r
    auto push=[&](question s, ll r)
    {
        if (cnt[s]==YCNT) return; // if a question gets Y
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

        // iterate through questions in a round
        for (ll j=0; j<sz(round[i]); j++)
        {
            // print question
            question s=round[i][j];
            cout << "(" << j+1 << "/" << sz(round[i]) << "): " << s << " (Y/N/U)\n";

            // get response
            char response; cin >> response; // is Y/N/U
            if (response=='Y') cnt[s]++, push(s, i+YSKIP);
            else if (response=='U') push(s, i+USKIP);
            else push(s, i+NSKIP);

            // print answer
            if (ShowAns) cout << "Answer: " << s.A << "\n";
        }
    }
    cout << "Yay you finished it! :>\n";
}