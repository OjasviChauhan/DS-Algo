// https://leetcode.com/problems/accounts-merge/

class dsu{
public:
    vector<int> par,rank;
	dsu(int v){
		par.resize(v);
        rank.resize(v);
		for(int i=0;i<v;i++){
			par[i] = i;
			rank[i] = 1;
		}
	}

	int get(int i){
		return par[i]==i ? i : par[i]=get(par[i]);
	}

	void unite(int x,int y){
		int s1 = get(x);
		int s2 = get(y);
		if(s1!=s2){
			if(rank[s2]>rank[s1]){
				par[s1] = s2;
				rank[s2] += rank[s1];
			}
			else{
				par[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> email_id;
        unordered_map<int,string> id_email, id_name;

        int k=0;
        for(vector<string> v:accounts){
            id_name[k] = v[0];
            for(int i=1;i<v.size();i++){
                if(email_id.find(v[i]) == email_id.end()){
                    email_id[v[i]] = k;
                    id_email[k] = v[i];
                    k++;
                }
            }
        }
        
        dsu g(k);
        for(vector<string> acc : accounts){
            int p = email_id[acc[1]];
            for(int i=2;i<acc.size();i++){
                g.unite(p, email_id[acc[i]]);
            }
        }
        
        unordered_set<int> ss;
        for(int i=0;i<k;i++){
            int p = g.get(i);
            if(ss.find(p) == ss.end()){
                ss.insert(p);
            }
        }
        
        vector<vector<string>> ans;
        for(auto x:ss){
            vector<string> emails;
            for(int i=0;i<k;i++){
                if(g.par[i]==x){
                    emails.push_back(id_email[i]);
                }
            }
            sort(emails.begin(),emails.end());
            emails.insert(emails.begin(),id_name[x]);
            ans.push_back(emails);
        }
        return ans;
    }
};
