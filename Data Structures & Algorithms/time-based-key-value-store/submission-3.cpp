class TimeMap {
public:

    map<string, int> mp; //key,index
    vector<map<int, string>> v; //timestamp,value

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if(mp.find(key)!=mp.end()) //key already exists
        {
            int index = mp[key];
            v[index][timestamp] = value; //v[index] is a map
        }
        else //key does not exist
        {
            map<int, string> m;
            m[timestamp] = value;
            v.push_back(m);
            int index = v.size()-1;
            mp[key] = index;
        }
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) {return "";}

        int index = mp[key];
        auto m = v[index];
        if(m.empty()) {return "";}

        if(m.find(timestamp)!=m.end()) //timestamp exists
        {
            return m[timestamp];
        }
        else 
        {
            auto it = m.upper_bound(timestamp); //find t>timestamp
            if(it == m.begin()) return "";

            it--; //if not the beginnning
            return it->second;
        }

        return "";
    }
};
