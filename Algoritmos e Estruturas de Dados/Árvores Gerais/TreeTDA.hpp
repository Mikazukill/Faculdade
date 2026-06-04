#ifndef TREETDA_HPP
#define TREETDA_HPP

class TreeTDA {
    public:
    // Método para adicionar um nó filho
    virtual void addChild(TreeTDA* tree) = 0;

    // Método para adicionar um nó filho em uma posição específica
    virtual void addChild(int index, TreeTDA* tree) = 0;

    // Método para remover um nó filho na posição especificada
    virtual TreeTDA* removeChild(int index) = 0;

    // Método para obter um nó filho na posição especificada
    virtual TreeTDA* getChild(int index) const = 0;

    // Método para contar o número de filhos
    virtual int childrenCount() const = 0;

    // Método para obter o altura da árvore
    virtual int size() const = 0;

    // Método para obter o item armazenado no nó (defina o tipo de retorno)
    virtual int getItem() const = 0;

    // Método para obter o nó pai
    virtual TreeTDA* getParent() const = 0;

    //Método para printar a árvore
    virtual void printar() const = 0;

    // Método para Pré-Ordem
    virtual void preOrder() const = 0;

    // Método para Pós-Ordem
    virtual void posOrder() const = 0;
    
    // Método para Destrutor
    virtual ~TreeTDA() {};

    // Método para breadth
    virtual void breadth() = 0;

    // Método para height
    virtual int height() = 0;

    // Método para level
    virtual int level() = 0;

    // Função de busca do indice
    virtual int busca(int index) = 0;

    #endif
};