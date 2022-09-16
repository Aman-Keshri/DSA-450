/*
    approach 1
    Time - O(N^2)

    we can use insertion sort for running stream T - O(N^2)
    step 1 sort stream using insertion sort
    step 2 find median odd - (size/2)   even -  avg((size-1/2) + (size/2) / 2)

*/

/*
    approach 2
    Time - O(N log N)

    Output will also be in stream (like each element we process need to print
    the median of it taking the rest of stream of elements)

    step 1 loop through all elements one by one
    step 2 call the find median function to return median
    step 3 store the current median in vector
    step 4 return vector

    MEDIAN Funcn
        it will take array, max heap, min heap, and medain as prototype

        Idea that will use in this function to find median will be
        median is the middle element of the stream here we need median of sorted
        array but the I/P is not sorted

        so we need to use min heap and max heap

        if odd size then median will be n/2
        if even size then median will be avg(n-1/2 + n/2)

        now median will be middle element so there are 3 cases in it
        CASE I    if(left size == right size)
        CASE II   if(left size(n-1) and right size(n))
        CASE III  if(left size(n) and right size(n-1))

        and since the array of stream must be sorted
        then we can consider that the left part will be smaller than median and
        the right part will be greater than median
        So, In order to sort the array we can use maxheap and min heap to do so

        We are only considering the 1st left and right element of median
        So, in order to get the 1st left and right element of median we can use Maxheap and Min heap

        the max of left side will be 1st left of median and - Max Heap
        the min of right side will be 1st right of median   - Min Heap


        each stream of element we get need to decide whether to put it in right or left

        PROPERTY - and in no case the left and right diffrence should become > 1
        as mid element will only be either n or n-1 th element in array



        now in FUNCn
        step 1 find the appropriate case by passing the size of max heap and min heap
                case 0: if(max heap size == min heap size)
                case -1: if(max heap size > min heap size)
                case 1: if(max heap size < min heap size)

        step 2:
            case 0: check if the curr element is > median then insert in min heap
                    else push in max heap
                    and update median in both case

                    what we see here is if we add 1 element to any side the property
                    of median is not violated diffrence of max and min is still <= 1

                    and since by adding one element to either left or right makes it's
                    one side as n-1 and other as n so median will be from side with
                    n elements

            case 1: check if the curr element is > median then insert in min heap
                    else if we push in max heap the difrrence of maxi and mini will > 1
                    so need to take maxi top and push in mini now
                    maxi has 1 element less and if we add the difrrence will me <= 1
                    so add to maxi

                    and since by adding one element to either left or right makes it's
                    one side as n and other as n so median will be avg of top of mini and maxi

            case -1: check if the curr element is > median
                    we push in min heap the difrrence of maxi and mini will > 1
                    so need to take mini top and push in maxi now
                    mini has 1 element less and if we add the difrrence will me <= 1
                    so add to mini
                    else if then insert in max heap

                    and since by adding one element to either left or right makes it's
                    one side as n and other as n so median will be avg of top of mini and maxi

*/
#include <bits/stdc++.h>
#include <queue>

void findMedian(int element, priority_queue<int> &maxi,
                priority_queue<int, vector<int>, greater<int>> &mini, int &median)
{
    // case 0  left(maxi) = n   right(mini) = n
    if (maxi.size() == mini.size())
    {
        if (element > median)
        {
            mini.push(element);
            median = mini.top();
        }
        else
        {
            maxi.push(element);
            median = maxi.top();
        }
    }

    // case 1   left(maxi) = n   right(mini) = n-1
    else if (maxi.size() > mini.size())
    {
        if (element > median)
        {
            mini.push(element);
        }
        else
        {
            mini.push(maxi.top());
            maxi.pop();

            maxi.push(element);
        }

        median = (mini.top() + maxi.top()) / 2;
    }

    // case -1   left(maxi) = n-1   right(mini) = n
    else if (maxi.size() < mini.size())
    {
        if (element > median)
        {
            maxi.push(mini.top());
            mini.pop();

            mini.push(element);
        }
        else
        {
            maxi.push(element);
        }

        median = (mini.top() + maxi.top()) / 2;
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{
    // declare a vecotr for storing median
    //  create a max heap and min heap and a median variable
    vector<int> ans;
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    int median = 0;
    int element;

    // loop through each elements of array stream and call median function
    // then store the median to ans for each element added to stream
    for (int i = 0; i < n; i++)
    {
        element = arr[i];
        findMedian(element, maxi, mini, median);
        ans.push_back(median);
    }

    return ans;
}
