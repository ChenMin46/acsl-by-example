
#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>
#include "numeric.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a {1, 3, -6, 0, 4};
  std::vector<value_type> result1(a.size());
  std::vector<value_type> result2(a.size());

  partial_sum(&a[0], a.size(), &result1[0]);
  std::partial_sum(a.begin(), a.end(), result2.begin());

  //for(size_t i = 0; i < a.size(); ++i)
  //std::cout << a[i] << '\t' << result1[i] << '\t' << result2[i] << std::endl;

  assert(result1 == result2);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

