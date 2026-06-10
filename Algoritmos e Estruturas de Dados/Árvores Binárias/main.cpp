#include <iostream>
#include "TreeBin.hpp"

using namespace std;

class TreeBinary : public TreeBinaryTDA{
private:
    TreeBinaryTDA* parent;                     // Ponteiro para o nó pai
    int item;                         // Item armazenado no nó
    TreeBinaryTDA* left;
    TreeBinaryTDA* right;

    int alturaAux(TreeBinaryTDA* );
public:
    // Construtor
    TreeBinary(int value){
        this->item = value;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }

    // Destrutor
    ~TreeBinary() {
        delete left;              // Libera a memória dos filhos
        delete right;
    }

    void addLeft(TreeBinaryTDA* tree){
        this->left = tree;
    }
    void addRight(TreeBinaryTDA* tree){
        this->right = tree;
    }

    TreeBinaryTDA* removeLeft(){
        TreeBinaryTDA* temp = this->left;
        this->left = nullptr;
        TreeBinary* treeTemp = dynamic_cast<TreeBinary*>(temp);
        treeTemp->parent = nullptr;
        return temp;
    }
    TreeBinaryTDA* removeRight(){
        TreeBinaryTDA* temp = this->right;
        this->right = nullptr;
        TreeBinary* treeTemp = dynamic_cast<TreeBinary*>(temp);
        treeTemp->parent = nullptr;
        return temp;
    }

        // Obtém o item armazenado no nó
    int getItem() const {
        return item;
    }

    // Obtém o nó pai
    TreeBinaryTDA* getParent() const {
        return parent;
    }

    int altura(){
        int left = 0;
        int right = 0;
        TreeBinary* left2 = dynamic_cast<TreeBinary*>(this->left);
        TreeBinary* right2 = dynamic_cast<TreeBinary*>(this->right);
        if(this->left != nullptr){
            left = left2->altura();
        }
        if(this->right != nullptr){
            right = right2->altura();
        }
        if(left < right) return right + 1;
        return left + 1;
    }

     //Conta o número de filhos
    int childrenCount() const {
        return children.size();
    }

     //Obtém o tamanho da árvore (neste exemplo, o número de nós)
    int size() const {
        int totalSize = 1; // Contando o nó atual
        for (TreeBinaryTDA* child : children) {
            totalSize += child->size(); // Contando nós filhos
        }
        return totalSize;
    }


    
    bool dfs(int value){
        if(this->item == value) return true;
        for(TreeBinaryTDA* filho : children){
            TreeBinaryTDA* filho2 = dynamic_cast<TreeBinaryTDA*>(filho); 
            if(filho2->dfs(value))return true;
        }
        return false;
    }

};



int main(){
    TreeBinaryTDA* arv = new Tree(1);
    TreeBinaryTDA* arv2 = new Tree(2);
    arv->addChild(arv2);

    cout << "Item do nó raiz: " << arv->getItem() << endl;
    cout << "Size: " << arv->size() << endl;
    cout << "Procurando 2: " << arv->dfs(1) << endl;
}