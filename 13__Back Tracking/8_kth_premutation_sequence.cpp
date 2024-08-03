class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;
        // first find factorial of n-1
        // and also keep adding the numbers to vector
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        // create empty ans string
        string ans = "";
        // decrement k by 1 as 0 based indexing
        k = k - 1;

        // loop until true
        while (true)
        {
            // store the k/fact index number to ans
            ans = ans + to_string(numbers[k / fact]);

            // remove the element from vector
            numbers.erase(numbers.begin() + (k / fact));

            // if number vector become empty break
            if (numbers.size() == 0)
                break;

            // decrement k by k%fact
            k %= fact;
            // and fact by fact/numbe vector size
            fact /= numbers.size();
        }

        // at end after all numbers are complete return the string generated
        return ans;
    }
};

// Time - O(N)
// Space - O(N)