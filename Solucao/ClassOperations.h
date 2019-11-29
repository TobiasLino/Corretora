#include <iostream>
#include <stack>
#include <algorithm>
#include <deque>
#include <list>
#include <queue>
#include "ClassDados.h"
using namespace std;

/*
 * Arquivo com as classes de operações dentro do programa, bem como suas funções
 * 
 * Contém as classes de ordenação, pesquisa e salvar,acessar e remover no arquivo
 * 
*/
/*
 

 ********** CLASSES *********


*/
template<class Type>
class List{};
class Stack {};
class Tree {};
class Ordenation{};
class BinaryOrd {};
class BinarySearchTree {};
class GetFromFile {};
class Quicksort {};
/*
 
  
 
 **********  PROTÓTIPOS DAS FUNÇÕES **********
  
  
  
*/
void setClientQuant(); // Define os parâmetros de inicialização dos objetos de cliente
void setNewClient(int); // Adiciona novos clientes
void setBrokerQuant(); // Define os Parâmetros de inicialização dos objetos de Corretor
void setNewBroker(int); // Adiciona novos Corretores
void setProductQuant(); // Define os parâmetros de inicialização dos objetos de Produto
void setNewProduct(int); // Adiciona novos Produtos
void OrdinFIle(char*);  // Ordena as classes no arquivo
void SeCinF(char*); // Pesquisa as classes no arquivo
void SeSinF(char*); // Pesquisa as Strings dentro dos dados das classes
void SaCtoFile(char*, Cliente x); // Salva o Cliente no Arquivo 
void SaBtoFile(char*, Corretor x); // Salva o corretor no arquivo
void SaPtoFile(char*, Produto x); // Salva o produto no arquivo
void saReltoFile(char*, Relatorio x); // Salva o relatório no arquivo