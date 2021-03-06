#include <iostream>
#include <random>

void
random_mostly (  ) { // Using  dev device block for random stuff
  
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

float
probability (  ) {

  return float ( rand () % 100 / 100.0 );
}

bool
coinflip (  ) {
  return probability (  ) > 0.5;
}

int
onehundred_coinflips (  ) {

  // srand( (unsigned)time(NULL) );
  srand ( 666 );

  for ( auto i = 0; i < 1000; i++ )
    if ( coinflip (  ) ) 
      std::cout << "Cara" << std::endl;
    else
      std::cout << "Coroa" << std::endl;

  return 0;
}


int
main (  ) {

  onehundred_coinflips (  );
  return 0;
}
