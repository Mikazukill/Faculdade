#include <string>

using namespace std;

class questao {
    private:

        string pergunta;
        bool res;
        string just0;
        string just1;

    public:

        questao(string pergunta = "", bool resposta = false, string justificativa0 = "", string justificativa1 = "") {

            this -> pergunta = pergunta;
            res = resposta;
            just0 = justificativa0;
            just1 = justificativa1;
    }
};  