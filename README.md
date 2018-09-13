# Backtracking
Trabalho de Algoritmos Avançados


* O tabuleiro inicia em (0,0) e termina em (linha-1, coluna-1);


* Primeira ideia do backtracking:

  * Backtracking(Nº Peças, Jogada){
    * if( Nº Peças == 1 ) return;
    * if( ilha ) return;

    * Para cada peça:
      * Para cada jogada:
        * Backtracking( Nº Peças--,  Jogada);
  * }
