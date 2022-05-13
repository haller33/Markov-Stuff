#include <iostream>
#include <random>

// using namespace std;

void
random_mostly (  ) {
  
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);
  // distribution in range [1, 6]
  
  std::cout << dist6(rng) << std::endl;
}

int
main2 (  ) {

  std::cout << "hello world";
  return 0;
}

int
random_list_quote_dice(void)
{
  unsigned long j;
  srand( (unsigned)time(NULL) );

  for( j = 0; j < 100500; ++j )
    {
      int n;

      /* skip rand() readings that would make n%6 non-uniformly distributed
      (assuming rand() itself is uniformly distributed from 0 to RAND_MAX) */
      while( ( n = rand() ) > RAND_MAX - (RAND_MAX-5)%6 )
        { /* bad value retrieved so get next one */ }

      printf( "%d,\t%d\n", n, n % 6 + 1 );
    }

  return 0;
}

int
main (  ) {

  return 0;
}
