/**
 * @file antenas.h
 * @brief Declarações das funções e estruturas para gerenciamento de antenas.
 * @author Alexandre Barbosa
 * @date 2024
 */

 #ifndef ANTENAS_H
 #define ANTENAS_H
 
 #define MAP_SIZE 12 ///< Tamanho do mapa
 
 /**
  * @struct Antena
  * @brief Representa uma antena no mapa.
  */
 typedef struct Antena {
     char frequencia; ///< Frequência da antena
     int x, y; ///< Coordenadas da antena
     struct Antena *prox; ///< Ponteiro para a próxima antena
 } Antena;
 
 /**
  * @brief Cria uma nova antena.
  * @param frequencia A frequência da antena (A-Z).
  * @param x Coordenada X.
  * @param y Coordenada Y.
  * @return Ponteiro para a nova antena.
  */
 Antena* criarAntena(char frequencia, int x, int y);
 
 /**
  * @brief Insere uma antena na lista ligada.
  * @param lista Ponteiro para a lista de antenas.
  * @param frequencia A frequência da antena.
  * @param x Coordenada X.
  * @param y Coordenada Y.
  */
 void inserirAntena(Antena **lista, char frequencia, int x, int y);
 
 /**
  * @brief Remove uma antena da lista ligada.
  * @param lista Ponteiro para a lista de antenas.
  * @param x Coordenada X da antena a ser removida.
  * @param y Coordenada Y da antena a ser removida.
  */
 void removerAntena(Antena **lista, int x, int y);
 
 /**
  * @brief Imprime todas as antenas cadastradas.
  * @param lista Ponteiro para a lista de antenas.
  */
 void imprimirAntenas(Antena *lista);
 
 /**
  * @brief Exibe o mapa de antenas.
  * @param lista Ponteiro para a lista de antenas.
  */
 void exibirMapa(Antena *lista);
 
 /**
  * @brief Detecta interferências entre antenas próximas com a mesma frequência.
  * @param lista Ponteiro para a lista de antenas.
  */
 void detectarInterferencia(Antena *lista);
 
 /**
  * @brief Exibe o menu interativo.
  */
 void menu();
 
 #endif /* ANTENAS_H */