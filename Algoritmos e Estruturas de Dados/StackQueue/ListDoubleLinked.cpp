#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

#include "ListDoubleLinked.h"

using namespace std;

// Construtor
ListDoubleLinked::ListDoubleLinked()
{
    clear();
}

/**
* Esvazia a lista.
*/
void ListDoubleLinked::clear()
{
    header = NULL;
    trailer = NULL;
    count = 0;
}

/**
* Retorna true se a lista nao contem elementos.
* 
* @return true se a lista nao contem elementos
*/
bool ListDoubleLinked::isEmpty()
{
    return count == 0;
}

/**
* Retorna o numero de elementos armazenados na lista.
* 
* @return o numero de elementos da lista
*/
int ListDoubleLinked::size()
{
    return count;
}

/**
* Adiciona um elemento ao final da lista.
* 
* @param element elemento a ser adicionado ao final da lista
*/
void ListDoubleLinked::add(int element)
{
    Node *n = new Node(element);
    if (count != 0) // lista já tem elems?
        trailer->next = n;
    else
        header = n; // não, este é o primeiro
    trailer = n;
    count++;
}

/**
* Adiciona um elemento antes de uma pos. específica
* 
* @param index   posição a inserir o novo elemento
* @param element elemento a ser adicionado
* 
*/
void ListDoubleLinked::add(int index, int element)
{
    if ((index < 0) || (index > count))
    {
        throw "Índice inválido";
    }
    Node *n = new Node(element);
    if (index == 0)
    { // inserção no início?
        n->next = header;
        header = n;
    }
    else
    {
        Node *ant = NULL;
        Node *target = header;
        for (int pos = 0; pos < index; pos++)
        {
            ant = target;
            target = target->next;
        }
        ant->next = n;
        n->next = target;
    }
    count++;
}

/**
* Retorna o elemento de uma determinada posicao da lista.
* 
* @param index a posicao da lista
* @return o elemento da posicao especificada
* @throws exception se (index < 0 || index >= size())
*/
int ListDoubleLinked::get(int index)
{
    if (index < 0 || index >= count)
    {
        throw "Índice inválido";
    }
    Node *ptr = header;
    for (int pos = 0; pos < index; pos++)
        ptr = ptr->next;
    return ptr->item;
}

/**
 * Substitui o elemento armazenado em uma determinada posicao da lista pelo
 * elemento passado por parametro, retornando o elemento que foi substituido.
 * @param index a posicao da lista
 * @param element o elemento a ser armazenado na lista
 * @return o elemento armazenado anteriormente na posicao da lista
 * @throws exception se (index < 0 || index >= size())
 */
int ListDoubleLinked::set(int index, int element)
{
    if ((index < 0) || (index >= count))
    {
        throw "Índice inválido!";
    }
    Node *ptr = header;
    for (int pos = 0; pos < index; pos++)
        ptr = ptr->next;
    int temp = ptr->item; // salva o valor armazenado lá...
    ptr->item = element;
    return temp; // ...e retorna ele
}

/**
 * Procura pelo elemento passado por parametro na lista e retorna true se a
 * lista contem este elemento.
 * @param element o elemento a ser procurado
 * @return true se a lista contem o elemento passado por parametro
 */
bool ListDoubleLinked::contains(int element)
{
    return indexOf(element) != -1;
}

/**
 * Procura pelo elemento passado por parametro na lista, remove e retorna true se a
 * lista continha este elemento.
 * @param element o elemento a ser procurado
 * @return true se conseguir remover
 */
bool ListDoubleLinked::remove(int element)
{
    return false;
}

/**
 * Remove um elemento da lista pela sua posição
 * lista continha este elemento.
 * @param index a posição do elemento
 * @return o elemento que estava na posição
 */
int ListDoubleLinked::removeByIndex(int index)
{
    if ((index < 0) || (index >= count))
    {
        throw "Índice inválido!";
    }
    // Se for o início, basta avançar o head
    Node *aux = header;
    if (index == 0)
    {
        header = header->next;
    }
    else
    {
        Node *prev = header;
        aux = header->next;
        for (int pos = 1; pos < index; pos++)
        {
            prev = aux;
            aux = aux->next;
        }
        // Remove o elemento
        prev->next = aux->next;
        // Se for o final da lista,
        // ajusta o tail
        if (index == count - 1)
            trailer = prev;
    }
    count--;
    // Se a lista ficar vazia (count==0),
    // garante que o tail também será NULL
    if (count == 0)
        trailer = NULL;
    int valor = aux->item;
    delete aux; // libera a memória ocupada pelo nodo
    return valor;
}

/**
 * Procura pelo elemento passado por parametro na lista e retorna sua posição,
 * se encontrar
 * @param element o elemento a ser procurado
 * @return posição se encontrado, -1 se não encontrado
 */
int ListDoubleLinked::indexOf(int element)
{
    Node *ptr = header;
    for (int pos = 0; pos < count; pos++)
    {
        if (ptr->item == element)
            return pos;
        ptr = ptr->next;
    }
    return -1;
}

/**
* Retorna o conteúdo da lista como uma string
* 
* @return uma string com os elementos da lista
*/
string ListDoubleLinked::toString()
{
    ostringstream aux;
    aux << "[ ";
    Node *ptr = header;
    while (ptr)
    {
        aux << ptr->item << " ";
        ptr = ptr->next;
    }
    aux << "]";
    return aux.str();
}
