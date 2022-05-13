#include <iostream>
#include <random>

typedef struct {
  int possitions [9] = { 1,2,3,4,5,6,7,8,9 };
  int jogadas [9] = { 0,0,0,0,0,0,0,0,0 };
  int jogada = 0;
  bool replay = false;
  bool playerTru = true;
  bool player_turn = true;
} GameTik;

void
imprimeVelha ( GameTik gameof ) {
  
  std::cout << std::endl << "###############" << std::endl;

  for (int i = 0; i < 3; i++) {

    for (int j = 0; j < 3; j++) {
      std::cout << "#";
      std::cout << " ";

      int lixo_possicao = j+(3*i);

      if ((gameof.jogadas[lixo_possicao] == 1) ||
          (gameof.jogadas[lixo_possicao] == 2)) {
        if (gameof.jogadas[lixo_possicao] == 1) {

          std::cout << 'X';
        } else {
          std::cout << 'O';
        }

      } else {

        std::cout << gameof.possitions[lixo_possicao];
      }

      std::cout << " ";
      std::cout << "#";
    }

    std::cout << std::endl << "###############" ;
    std::cout << std::endl;
  }
}

bool
verificaJogadaValida ( GameTik gameof ) {

  if ( ( ( gameof.jogada >= 1 ) &&
	( gameof.jogada <= 9 ) ) &&
      gameof.jogadas[gameof.jogada-1] == 0 ) {

    return true;
  }

  return false;
}

GameTik
clear_jogadas ( GameTik gameof ) {

  if ( gameof.replay ) {

    gameof.replay = false;
    
    for (int i = 0; i < 9; i++) {
      
      gameof.jogadas[i] = 0;
    }
  }

  return gameof;
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


char
caracterOfPlayer ( GameTik gameof ) {
  
  char caracter;

  if ( gameof.player_turn )
    caracter = 'X'; // X
  else
    caracter = 'O'; // O

  return caracter;
}

int
number_player ( GameTik gameof ) {

  int caracter_simbol_number = 0;
  
  if ( gameof.player_turn ) {
	
    caracter_simbol_number = 1; // X
  } else {
    
    caracter_simbol_number = 2; // O
  }

  return caracter_simbol_number;
}


GameTik
inputData ( GameTik gameof ) {

  int caracter_simbol_number = 0;

  std::cout << "Digite uma possicao: ";
  std::cin >> gameof.jogada;
  if ( not verificaJogadaValida ( gameof ) ) {
      
    std::cout << "Digite um numero entre 1 e 9" << std::endl;
    inputData ( gameof );
  }
  
  caracter_simbol_number = number_player ( gameof );
  
  gameof.jogadas[gameof.jogada-1] = caracter_simbol_number;
  
  return gameof;
}

void
clear_game_buffers (  ) {

  std::cin.clear();
  std::cin.ignore(80, '\n');
}

GameTik
continuePlayertru ( GameTik gameof ) {
  
  if ( verificaSeGanhou ( gameof ) ) {
    char caracter_simbol = caracterOfPlayer ( gameof );
    
    std::cout << "\nParabéns, o Jogador " << caracter_simbol
	      << " Ganhou!\n" << std::endl;

    imprimeVelha ( gameof );
    
    std::cout << "\nDeseja Continuar? \n(digite qualquer "
	      << "numero diferente de -1) \n:";
    std::cin >> gameof.jogada;

    if ( gameof.jogada != -1 ) {
      gameof.playerTru = true;
      gameof.replay = true;
    } else
      gameof.playerTru = false;
  }
  
  return gameof;
}

int
computer ( GameTik gameof ) {

  int number = 0;
  while ( number = ( rand (  ) / 100 ) % 9 ) {
    if ( gameof.jogadas [ number ] == 0 )
      break;
  }
  std::cout << gameof.jogada << std::endl;
  return number;
}

int
jogodavelha (  ) {

  GameTik gameof;

  gameof.player_turn = true;
  gameof.playerTru = true;
  
  while ( gameof.playerTru ) {
    
    imprimeVelha ( gameof );
    gameof = inputData ( gameof );
    gameof = continuePlayertru ( gameof );
    clear_game_buffers (  );
    gameof = clear_jogadas ( gameof );
    
    gameof.player_turn = not gameof.player_turn;
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
