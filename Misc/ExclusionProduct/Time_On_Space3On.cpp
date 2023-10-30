INTERVIEWER: To facilitate interviewing, you can copy and paste this entire description into the Interviewer Notes area.
Link to share is https://cpad.io/9310.

### Goals
    
     1) Candidate can come to terms with a design requirement that prevents
     a single-pass solution.
    
     2) We can create a partnership with the candidate. For example, let candidate
     start with a brute force solution. Then point out repeated work in that solution.
     Continue communicating, as you both modify the original solution to only do
     work once.
    
     3) Candidate can use a greedy approach to solve a programming problem.
    
     4) Candidate can communicate clearly despite the stress and produce an
     acceptable algorithm.
```
int main()
{
  /*
     * Do not modify this block.
     */

  vector<int> vectorOfInts = { 1, 7, 3, 4 };
  std::for_each(allProducts.begin(), allProducts.end(), [](const int a){ std::cout << a << " "; });
}
```
### Example Starter Solution
The candidate might start with O(n^2) time & O(1) space solution 

O(n) time & O(n) space solution.
```
vector<int> exclusionProduct(const vector<int>& input)
{
  /*
     * Write your answer code here.
     */
  const size_t s = input.size();
  if( s < 2)
  {
    return {};
  }
  
  std::vector<int> prefixProducts(s, 1);
  std::vector<int> suffixProducts(s, 1);
  std::vector<int> productList(s, 1);

  int product = 1;
  for(size_t index = 1; index < s; ++index)
  {
     product *= input[index - 1]; 
     prefixProducts[index] = product;
  }

  product = 1;
  for(int index = s - 2; index >= 0; --index)
  {
     product *= input[index + 1]; 
     suffixProducts[index] = product;
  }
  
  for(size_t index = 0; index < s; ++index)
  {
    productList[index] = prefixProducts[index]*suffixProducts[index];
  }
  
  return productList;
}
```


The optimal soluation that we desire is O(n) time & O(1) space as follows:
```
vector<int> exclusionProduct(const vector<int>& intVector)
{
    // Getting the product of numbers at other indices requires at least 2 numbers.
    if (intVector.size() < 2)
    {
        return vector<int>(intVector.size(), 0);
    }

    // Create a vector with the length of the input vector to hold the products.
    vector<int> productsOfAllIntsExceptAtIndex(intVector.size());

    // For each integer, starting from the beginning of input vector, find the product of
    // all the integers before it, storing the total product so far each time.
    int productSoFar = 1;
    for (size_t i = 0; i < intVector.size(); ++i)
    {
        productsOfAllIntsExceptAtIndex[i] = productSoFar;
        productSoFar *= intVector[i];
    }

    // For each integer, starting from the end of input vector, find the product of all the
    // integers after it. Since each element in productsOfAllIntsExceptAtIndex already contains
    // the product of all the integers before it, just multiply by the product of all integers after it.
    productSoFar = 1;
    for (size_t i = intVector.size(); i > 0; --i)
    {
        size_t j = i - 1; // Spelled out here but can be accomodated in different ways.
        productsOfAllIntsExceptAtIndex[j] *= productSoFar;
        productSoFar *= intVector[j];
    }

    return productsOfAllIntsExceptAtIndex;
}
```

### Follow up questions:

1) How would you modify this if the input container was no longer necessary after processing?
    Answer should mention for example using the input argument itself to store the output, or using it for part of the processing, and how to refactor accordingly.

2) Can you write some unit tests for your function?

Using catch 2.
Link https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top
```
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

...

TEST_CASE(" Empty Input ")
{
  std::vector<int> input{};
  const auto result = exclusionProduct(input);
  REQUIRE(result.size() == 0);
}

TEST_CASE(" Non-empty Input")
{
  std::vector<int> input{1, 5, 6, 3};
  const auto result = exclusionProduct(input);
  std::vector<int> expectedResult = {90, 18, 15, 30};
  REQUIRE(result == expectedResult);
}
```



Here is a sample skeleton code if candidate doesn't feel confortable using catch2:
Tell the candidate to write it in a lambda function without captures or params.
```
// Snip // Paste before main ///////////////////////////////////////////////////
int unitTests = []() {
    vector< vector<int> > testInput = {
            { 1, 7, 3, 4 },
            { 1, 0, 0, 0 }
    };

    vector< vector<int> > testOutput = {
            { 84, 12, 28, 21 },
            { 0, 0, 0, 0 }
    };

    size_t numberOfTests = testInput.size();

    for (size_t i = 0; i < numberOfTests; ++i)
    {
        if (exclusionProduct(testInput[i]) == testOutput[i]) printf("Pass\n"); else printf("Fail\n");
    }
    printf("Ran all unit tests.\n\n");
    return 0;
}();
```
