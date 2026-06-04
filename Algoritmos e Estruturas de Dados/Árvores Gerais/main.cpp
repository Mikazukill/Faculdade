#include <iostream>
#include <vector>
#include "TreeTDA.hpp"

using namespace std;

class Tree : public TreeTDA{
private:
    TreeTDA* parent;                     // Ponteiro para o nó pai
    int item;                         // Item armazenado no nó
    std::vector<TreeTDA*> children;      // Vetor para armazenar nós filhos

public:
    // Construtor
    Tree(int value){
        this->item = value;
        this->parent = nullptr;
    }

    // Destrutor
    ~Tree() {
        for (TreeTDA* child : children) {
            delete child;              // Libera a memória dos filhos
        }
    }

    // Adiciona um nó filho
    void addChild(TreeTDA* tree) {
        children.push_back(tree);
        Tree* tree2 = dynamic_cast<Tree*>(tree);
        tree2->parent = this;           // Define o pai do nó filho
    }


    // Adiciona um nó filho em uma posição específica
    void addChild(int index, TreeTDA* tree) {
        if (index >= 0 && index <= children.size()) {
            children.insert(children.begin() + index, tree);
            Tree* tree2 = dynamic_cast<Tree*>(tree);
            tree2->parent = this;       // Define o pai do nó filho
        }
    }

    // Remove um nó filho na posição especificada
    TreeTDA* removeChild(int index) {
        if (index >= 0 && index < children.size()) {
            Tree* removedChild = dynamic_cast<Tree*>(children[index]);
            children.erase(children.begin() + index);
            removedChild->parent = nullptr; // Remove o pai do nó
            return removedChild;
        }
        return nullptr;
    }
    // Obtém um nó filho na posição especificada
    TreeTDA* getChild(int index) const {
        if (index >= 0 && index < children.size()) {
            return children[index];
        }
        return nullptr;
    }

    // Conta o número de filhos
    int childrenCount() const {
        return children.size();
    }

    // Obtém o tamanho da árvore (neste exemplo, o número de nós)
    int size() const {
        int totalSize = 1; // Contando o nó atual
        for (TreeTDA* child : children) {
            totalSize += child->size(); // Contando nós filhos
        }
        return totalSize;
    }

    // Obtém o item armazenado no nó
    int getItem() const {
        return item;
    }

    // Obtém o nó pai
    TreeTDA* getParent() const {
        return parent;
    }

    void printar() const {
        cout << "{"<< item;

        for (int i = 0; i < childrenCount(); i++) {
            TreeTDA* child = getChild(i);
            if (child != nullptr) {
                child->printar();
                if(i < childrenCount() - 1){
                    cout << ",";
                }
            }
        }
        cout << "}";
    }

    void preOrder() const {
        printar();
        for(int i = 0; i < childrenCount(); i++) {
            getChild(i)->preOrder();
            if(i == childrenCount() - 1) {
                cout << endl;
            }
        }
    }
    void posOrder() const {
        for(int j = 0; j < childrenCount(); j++) {
            getChild(j)->posOrder();
            if(j == childrenCount() - 1) {
                cout << endl;
            }
        }
        printar();
    }

    void breadth() {
        
    }


    int height(){

        if(childrenCount() == 0){
            return 0;
        }

        int heightMAX = 0;

        for(int i = 0; i < childrenCount(); i++) {

            int aux = getChild(i)->height();

            if(aux > heightMAX) {
                heightMAX = aux;
            }
        }
        return heightMAX + 1;
    }

    int level() {
        return 0;
    }

    int busca(int index) {
        return 0;
    }

};

int main(){

    Tree* arv = new Tree(1);
    Tree* arv2 = new Tree(2);
    Tree* arv3 = new Tree(3);
    Tree* arv4 = new Tree(4);
    Tree* arv5 = new Tree(5);
    Tree* arv6 = new Tree(6);
    Tree* arv7 = new Tree(7);
    Tree* arv8 = new Tree(8);
    Tree* arv9 = new Tree(9);
    Tree* arv10 = new Tree(10);
    Tree* arv11 = new Tree(11);
    arv->addChild(arv2);
    arv->addChild(arv3);
    arv->addChild(arv4);
    arv->addChild(arv5);
    arv->addChild(arv6);
    arv->addChild(arv7);
    arv->addChild(arv8);
    arv->addChild(arv9);
    arv->addChild(arv10);
    arv->addChild(arv11);

    arv->height();

    cout << "Nivel maximo da Arvore: " << arv->height() << endl;
    cout << "Item do nó raiz: " << arv->getItem() << endl;
    cout << "Size: " << arv->size() << endl;
    arv->posOrder();
    arv->preOrder();
}