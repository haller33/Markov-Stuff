#include <iostream>

typedef struct {
  int possitions [9] = { 1,2,3,4,5,6,7,8,9 };
  int jogadas [9] = { 0,0,0,0,0,0,0,0,0 };
  int jogada = 0;
  bool flag = true;
} GameTik;


int
imprimeVelha ( GameTik gameof ) {

  int *p = gameof.jogadas;
  int *possicoes = gameof.possitions;
  
  std::cout << std::endl << "###############" << std::endl;

  for (int i = 0; i < 3; i++) {

    for (int j = 0; j < 3; j++) {
      std::cout << "#";
      std::cout << " ";

      int lixo_possicao = j+(3*i);

      if ((possicoes[lixo_possicao] == 1) ||
          (possicoes[lixo_possicao] == 2)) {
        if (possicoes[lixo_possicao] == 1) {

          std::cout << 'X';
        } else {
          std::cout << 'O';
        }

      } else {

        std::cout << p[lixo_possicao];
      }

      std::cout << " ";
      std::cout << "#";
    }

    std::cout << std::endl << "###############" ;
    std::cout << std::endl;
  }

  return 0;
}

bool
verificaJogadaValida ( GameTik gameof ) {

  int *jogadas = gameof.jogadas;
  int possicao = gameof.jogada;
  if (jogadas[possicao-1] == 0) {

    return true;
  }

  return false;
}

bool
verificaSeGanhou ( GameTik gameof  ) {

  int *jogadas = gameof.jogadas;
  int CON = 9;

  int contador = 0;

  for (int jogo = 1; jogo <= 2; jogo++ ) {

    contador = 0;

    for (int j = 0; j < 3; j++) {

      for (int i = 0; i < CON; i+=3) {

        int lixo_possicao = i+j;

        if (jogadas[lixo_possicao] == jogo) {

          contador++;
        } else {

          contador = 0;
        }
      }
      
      if (contador == 3) {

        return true;
      }
    }

    int contador = 0;

    for (int j = 0; j < 3; j+=3) {

      for (int i = 0; i < CON; i++) {

        int lixo_possicao = i+j;

        if (jogadas[lixo_possicao] == jogo) {

          contador++;

          if (contador == 3) {

            return true;
          }
        } else {

          contador = 0;
        }
      }

      contador = 0;
    }

    if ( ( ( jogadas[0] == jogo ) && ( jogadas[4] == jogo ) &&
	   ( jogadas[8] == jogo ) ) ||
	 ( ( jogadas[2] == jogo ) && ( jogadas[4] == jogo ) &&
	   ( jogadas[6] == jogo ) )
	 ) {

      return true;
    }

  }

  return false;
}

int
jogodavelha (  ) {

  GameTik gameof;

  gameof.flag = true;

  std::cout << "Digite -1 para sair: " << std::endl;

  imprimeVelha ( gameof );

  while ( gameof.jogada >= 0 ) {

    std::cout << "Digite uma possicao: ";
    std::cin >> gameof.jogada;
    if ( ( gameof.jogada >= 1 ) && ( gameof.jogada <= 9 ) ) {

      if ( verificaJogadaValida ( gameof ) ) {

        int caracter = 0;

        if ( gameof.flag ) {

          caracter = 1; // X
        } else {

          caracter = 2; // O
        }

        gameof.jogadas[gameof.jogada-1] = caracter;
      } else {

        std::cout << "Digite uma possicao valida" <<
	  std::endl;

        gameof.flag = !gameof.flag;
      }

    } else {
      std::cout << "Digite um numero entre 1 e 9" <<
	std::endl;
    }
    
    if ( verificaSeGanhou ( gameof ) ) {

      char caracter;

      if ( gameof.flag ) {

        caracter = 'X'; // X
      } else {

        caracter = 'O'; // O
      }

      imprimeVelha ( gameof );

      std::cout << "Parabéns, o Jogador " << caracter << " Ganhou! \n \n" << std::endl;

      std::cout << "Deseja Continuar? \n(digite qualquer numero diferente de -1) \n:";
      std::cin >> gameof.jogada;

      if ( gameof.jogada != -1 ) {

        for (int i = 0; i < 9; i++) {

          gameof.jogadas[i] = 0;
        }
      }
    }

    std::cin.clear();
    std::cin.ignore(80, '\n'); // for space problems with cin
    imprimeVelha ( gameof );

    gameof.flag = !gameof.flag;
  }


  return 0;
}

int
testaSeJogadorGanhou (  ) {

  GameTik some_test_game;
  
  int jogadas [9] = { 2,0,2,1,2,1,2,1,2 };  // OK To verify horizontal values of game velha

  for (int i = 0; i < 9; i++)
    some_test_game.jogadas[i] = jogadas[i];
  
  if (  verificaSeGanhou ( some_test_game ) ) {

    std::cout << "Ganhou" << std::endl;
  } else {

    std::cout << "Não Ganhou" << std::endl;
  }
  return 0;
}
