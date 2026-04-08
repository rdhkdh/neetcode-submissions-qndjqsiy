class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int total = 0;
        int start_index = 0;
        int count = 0; //no of stations counted in the sum

        for(int i=0;i<n;i++)
        {
            total += (gas[i]-cost[i]);
        }
        if(total < 0) {return -1;}

        total = 0;
        int i = 0;
        while(count<n)
        {
            total += (gas[i]-cost[i]);
            count++;

            if(total<0) 
            {
                start_index = (i+1)%n;
                count=0;
                total=0;
            }

            i++;
            i = i%n;
        }

        return start_index;
    }
};
