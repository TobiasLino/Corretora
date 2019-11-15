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
void setClientQuant() throw (Cliente::IndexException);         // Define os parâmetros de inicialização dos objetos de cliente
// Adiciona novos clientes
void setNewClient(int) throw (Cliente::IndexException, Cliente::EmptyInfoException, Cliente::EmptyAddressException, Cliente::EmptyContactException, Cliente::EmptyPurchaseException);                 
void setBrokerQuant() throw (Corretor::IndexException);        // Define os Parâmetros de inicialização dos objetos de Corretor
// Adiciona novos Corretores
void setNewBroker(int) throw (Corretor::EmptyInfoException, Corretor::EmptyContactException, Corretor::EmptyAddressException);                 
void setProductQuant() throw (Produto::IndexException);        // Define os parâmetros de inicialização dos objetos de Produto
// Adiciona novos Produtos
void setNewProduct(int) throw (Produto::EmptyInfoException, Produto::EmptyValueException);               
void OrdinFIle(char*);                  // Ordena as classes no arquivo
void SeCinF(char*);                     // Pesquisa as classes no arquivo
void SeSinF(char*);                     // Pesquisa as Strings dentro dos dados das classes
void SaCtoFile(char*, Cliente x) throw (FileException);       // Salva o Cliente no Arquivo 
void SaBtoFile(char*, Corretor x) throw (FileException);      // Salva o corretor no arquivo
void SaPtoFile(char*, Produto x) throw (FileException);       // Salva o produto no arquivo
void saReltoFile(char*, Relatorio x) throw (FileException);   // Salva o relatório no arquivo