class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1)
            return 1;
        
        int people[n+1];
        int potentialJudge = -1;
        for(int i=0;i<=n;i++)
            people[i] =0;       
        
        for(auto iter1 = trust.begin();iter1!=trust.end();iter1++)
        {
            vector<int> tr = *iter1;
            int a = tr[0];
            int b = tr[1];
          
            //b can be the judge if not already eliminated
            if(people[b]!=-1)
            {
                people[b]++;
                if(people[b] == (n-1))
                    potentialJudge = b;
            }
            
            //Eliminate a
            people[a] = -1;
            if(potentialJudge == a)
                potentialJudge = -1;
            
        }
        return potentialJudge;
    }
};
