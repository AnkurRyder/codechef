#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define re(i, n) for(int i = 0; i < n; i++)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define ren(i,a,b) for(int i = (a); i >= (b); i--)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)

class graph
{
    public:
    	int V;
	    list < pair<int , int> > *l;
        graph(int v)
        {
            V = v;
            l = new list<pair<int , int> > [V];
        }
        void add_edge(int u , int v , int w)
        {
            l[u].push_back(make_pair(v , w));
            l[v].push_back(make_pair(u , w));
        }
        int Disk(int src)
        {
        	std::vector<int> dist(V , INT_MAX);
        	set<pair<int , int> > s;
        	s.insert(make_pair(0 , src));
        	dist[src] = 0;
        	set<pair<int , int> >::iterator it;
        	int temp;
        	while(!s.empty())
        	{
        		auto t = *(s.begin());
        		temp = t.second;
        		s.erase(s.begin());
        		for(auto i:l[temp])
        		{
        			if((dist[i.first] > dist[temp] + i.second))
        			{
        				it = s.find(make_pair(dist[i.first] , i.first));
        				dist[i.first] = dist[temp] + i.second;
        				if(it != s.end())
        					s.erase(it);
        				s.insert(make_pair(dist[i.first] , i.first));
        			}
        		}
        	}
        for(int i :dist)
        {
        	if(i != src){
	        	if(i != INT_MAX)
	        		cout << i << " ";
	        	else
	        		cout << -1 <<" ";
	        }
        }
        cout << "\n";
    }
};

int main()
{
	int t;
	si(t);
	int n , m ,a ,b ,w , s;
	while(t--)
	{
		si(n); si(m);
		graph* g = new graph(n);
		re(i , m)
		{
			si(a); si(b); si(w);
			g->add_edge(a-1 ,b-1, w);
		}
		si(s);
		g->Disk(s-1);
		delete(g);
	}
	return 0;
}