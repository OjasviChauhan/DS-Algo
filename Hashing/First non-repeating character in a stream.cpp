// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

string FirstNonRepeating(string A){
	unordered_set<char> s;
	string ans = "";
    list<char> q;
            
    for(char &c : A) {
    	if(s.find(c) == s.end()){
            q.push_back(c);
        	s.insert(c);
        }
        else if(!q.empty() and c == q.front()){
        	q.pop_front();
        }
        else{
        	q.remove(c);
        }
        ans += !q.empty() ? q.front() : '#';
	}
    return ans;
}
