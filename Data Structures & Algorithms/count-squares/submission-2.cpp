class CountSquares {
public:
    map<pair<int,int>, int> mp;

    CountSquares() {}
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;
        for(auto u: mp)
        {
            int x1 = u.first.first;
            int y1 = u.first.second;
            int f = u.second;

            //get only diagonal points, which are equidistant
            if(x==x1 || y==y1 || abs(x-x1) != abs(y-y1))
            {
                continue;
            }

            ans += ( f * mp[{x,y1}] * mp[{x1,y}] );
        }

        return ans;
    }
};
