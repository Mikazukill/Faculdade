#ifndef TREE_BIN_HPP
#define TREE_BIN_HPP

class TreeBinaryTDA {
public:
    // Método para adicionar um nó filho
    virtual void addLeft(TreeBinaryTDA* tree) = 0;

    // Método para adicionar um nó filho em uma posição específica
    virtual void addRight(TreeBinaryTDA* tree) = 0;

    // Método para remover um nó filho na posição especificada
    virtual TreeBinaryTDA* removeLeft() = 0;

    // Método para remover um nó filho na posição especificada
    virtual TreeBinaryTDA* removeRight() = 0;

    // Método para obter um nó filho na posição especificada
    virtual TreeBinaryTDA* getChildLeft(int index) = 0;

    // Método para obter um nó filho na posição especificada
    virtual TreeBinaryTDA* getChildRight(int index) = 0;

    // Método para contar o número de filhos
    virtual int childrenCount() const = 0;

    // Método para obter a contagem de nos na arvore
    virtual int size() const = 0;

    // Método para obter o item armazenado no nó (defina o tipo de retorno)
    virtual int getItem() const = 0;

    // Método para obter o nó pai
    virtual TreeBinaryTDA* getParent() const = 0;
};
#endif