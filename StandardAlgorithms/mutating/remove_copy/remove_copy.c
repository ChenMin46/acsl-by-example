#include "remove_copy.h"

size_type
remove_copy(const value_type* a, size_type n, value_type* b, value_type v)
{
  size_type j = 0;

  /*@
    loop invariant bound:      0 <= j <= i <= n;
    loop invariant size:       j == i - Count{Pre}(a, i, v);
    loop invariant unchanged:  Unchanged{Pre,Here}(a, i, n);
    loop invariant retain:     MultisetRetainRest{Pre,Here}(a, i, b, j, v);
    loop invariant discard:    !HasValue(b, j, v);
    loop invariant unchanged:  Unchanged{Pre,Here}(b, j, n);
    loop assigns i, j, b[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i) {
    if (a[i] != v) {
      b[j++] = a[i];
      //@ assert retain_pre:  MultisetRetainRest{Pre,Here}(a, i,   b, j-1, v);
      //@ assert retain_now:  MultisetRetainRest{Pre,Here}(a, i+1, b, j,   v);
    }
  }

  return j;
}

