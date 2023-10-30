#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;


vector<int> exclusionProduct(const vector<int>& input)
{
    /*
     *      * Write your answer code here.
     *           */
    if (input.size() < 2)
    {
        return {};

    }

    std::vector<int> result;
    result.reserve(input.size());

    for(auto iter = input.begin(); iter != input.end(); ++iter)
    {
        int product = 1;
        for(auto iterPre = input.begin(); iterPre != iter; ++iterPre)
        {
            product *= *iterPre;

        }


        for(auto iterSuf = std::next(iter); iterSuf != input.end(); ++iterSuf)
        {
            product *= *(iterSuf);

        }

        result.push_back(product);

    }

    return result;

}

int main()
{
    /*
     *      * Do not modify this block.
     *           */

    vector<int> vectorOfInts = { 1, 7, 7, 3, 4  };
    vector<int> allProducts = exclusionProduct(vectorOfInts);
    std::cout << "\n results are \n";
    std::for_each(allProducts.begin(), allProducts.end(), [](int a){ std::cout << a << " "; });
    std::cout << "\n";


    std::cout << "results are \n";
    vector<int> vectorOfInts2;
    vector<int> allProducts2 = exclusionProduct(vectorOfInts2);
    std::for_each(allProducts2.begin(), allProducts2.end(), [](int a){ std::cout << a << " "; });
    std::cout << "\n";

    std::cout << "results are \n";
    vector<int> vectorOfInts3 = {1};
    vector<int> allProducts3 = exclusionProduct(vectorOfInts3);
    std::for_each(allProducts3.begin(), allProducts3.end(), [](int a){ std::cout << a << " "; });
    std::cout << "\n";

}

