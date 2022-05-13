#include <iostream>

int
imprimeVelha ( int *p, int *possicoes ) {

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
verificaJogadaValida ( int *jogada, int possicao ) {

  if (jogada[possicao-1] == 0) {

    return true;
  }

  return false;
}

bool
verificaSeGanhou ( int *jogadas ) {

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

struct {
  int vet [9] = { 1,2,3,4,5,6,7,8,9 };
  int jogadas [9] = { 0,0,0,0,0,0,0,0,0 };
  int jogo = 0;
  bool flag = false;
} JogoVelha;

int
jogodavelha (  ) {

  int flag = true;

  int vet [9] = { 1,2,3,4,5,6,7,8,9 };
  int jogadas [9] = { 0,0,0,0,0,0,0,0,0 };
  int jogo = 0;

  std::cout << "Digite -1 para sair: " << std::endl;

  imprimeVelha ( vet, jogadas );

  while ( jogo >= 0 ) {

    std::cout << "Digite uma possicao: ";
    std::cin >> jogo;
    if ( ( jogo >= 1 ) && ( jogo <= 9 ) ) {

      if ( verificaJogadaValida ( jogadas, jogo ) ) {

        int caracter = 0;

        if (flag) {

          caracter = 1; // X
        } else {

          caracter = 2; // O
        }

        jogadas[jogo-1] = caracter;
      } else {

        std::cout << "Digite uma possicao valida" <<
	  std::endl;

        flag = !flag;
      }

    } else {
      std::cout << "Digite um numero entre 1 e 9" <<
	std::endl;
    }
    
    if ( verificaSeGanhou ( jogadas ) ) {

      char caracter;

      if ( flag ) {

        caracter = 'X'; // X
      } else {

        caracter = 'O'; // O
      }

      imprimeVelha ( vet, jogadas );

      std::cout << "Parabéns, o Jogador " << caracter << " Ganhou! \n \n" << std::endl;

      std::cout << "Deseja Continuar? \n(digite qualquer numero diferente de -1) \n:";
      std::cin >> jogo;

      if ( jogo != -1 ) {

        for (int i = 0; i < 9; i++) {

          jogadas[i] = 0;
        }
      }
    }

    std::cin.clear();
    std::cin.ignore(80, '\n'); // for space problems with cin
    imprimeVelha (vet, jogadas);

    flag = !flag;
  }


  return 0;
}

int
testaSeJogadorGanhou (  ) {
  int vet [9] =     { 1,2,3,4,5,6,7,8,9 };
  int jogadas [9] = { 2,0,2,
		      1,2,1,
		      2,1,2 };  // OK To verify horizontal values of game velha
  if (  verificaSeGanhou ( jogadas ) ) {

    std::cout << "Ganhou" << std::endl;
  } else {

    std::cout << "Não Ganhou" << std::endl;
  }
  return 0;
}
