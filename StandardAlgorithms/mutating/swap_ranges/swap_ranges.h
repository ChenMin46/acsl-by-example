
#ifndef SWAP_RANGES_H_INCLUDED
#define SWAP_RANGES_H_INCLUDED

#include "EqualRanges.h"

/*@
  requires valid:  \valid(a + (0..n-1));
  requires valid:  \valid(b + (0..n-1));
  requires sep:    \separated(a+(0..n-1), b+(0..n-1));

  assigns a[0..n-1];
  assigns b[0..n-1];

  ensures equal:  EqualRanges{Here,Old}(a, n, b);
  ensures equal:  EqualRanges{Here,Old}(b, n, a);
*/
void swap_ranges(value_type* a, size_type n, value_type* b);

#endif /* SWAP_RANGES_H_INCLUDED */
