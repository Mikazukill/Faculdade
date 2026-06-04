/*
 * Nome do arquivo: Exercicio004.cpp
  * Autor: Gabriel Verissimo da Silva
   * Finalidade: Criação de hierarquia de classes (Veiculo, Caminhao, Carro) usando herança.
    * Data: 31/05/2026
     */
     
     #include <iostream>
     #include <iomanip>
     #include <string>
     
     using namespace std;
     
     enum TipoDeCarro { OUTRO, COMPACTO, HATCH, SEDAN, SUV };
     
     // SOLUÇÃO (Inicio)
     class Veiculo {
     private:
         string nome;
             int rodas;
                 int passageiros;
                 
                 public:
                     Veiculo(string n = "", int r = 0, int p = 0) : nome(n), rodas(r), passageiros(p) {}
                         
                             string obtemNome() const { return nome; }
                                 void defineNome(string n) { nome = n; }
                                     
                                         int obtemRodas() const { return rodas; }
                                             void defineRodas(int r) { rodas = r; }
                                                 
                                                     int obtemPassageiros() const { return passageiros; }
                                                         void definePassageiros(int p) { passageiros = p; }
                                                         };
                                                         
                                                         class Caminhao : public Veiculo {
                                                         private:
                                                             int carga;
                                                             
                                                             public:
                                                                 Caminhao(string n = "", int r = 0, int p = 0, int c = 0) : Veiculo(n, r, p), carga(c) {}
                                                                     
                                                                         int obtemCarga() const { return carga; }
                                                                             void defineCarga(int c) { carga = c; }
                                                                             };
                                                                             
                                                                             class Carro : public Veiculo {
                                                                             private:
                                                                                 TipoDeCarro tipo;
                                                                                 
                                                                                 public:
                                                                                     Carro(string n = "", int r = 0, int p = 0, TipoDeCarro t = OUTRO) : Veiculo(n, r, p), tipo(t) {}
                                                                                         
                                                                                             TipoDeCarro obtemTipo() const { return tipo; }
                                                                                                 void defineTipo(TipoDeCarro t) { tipo = t; }
                                                                                                 };
                                                                                                 // SOLUÇÃO (Fim)
                                                                                                 
                                                                                                 void imprimeVeiculo(Veiculo v) {
                                                                                                     cout << "Nome: " << v.obtemNome() << endl;
                                                                                                         cout << "Rodas: " << v.obtemRodas() << endl;
                                                                                                             cout << "Passageiros: " << v.obtemPassageiros() << endl;
                                                                                                                 cout << "--------------------" << endl;
                                                                                                                 }
                                                                                                                 
                                                                                                                 void imprimeCaminhao(Caminhao c) {
                                                                                                                     cout << "Nome: " << c.obtemNome() << endl;
                                                                                                                         cout << "Rodas: " << c.obtemRodas() << endl;
                                                                                                                             cout << "Passageiros: " << c.obtemPassageiros() << endl;
                                                                                                                                 cout << "Carga: " << c.obtemCarga() << endl;
                                                                                                                                     cout << "--------------------" << endl;
                                                                                                                                     }
                                                                                                                                     
                                                                                                                                     void imprimeCarro(Carro c) {
                                                                                                                                         cout << "Nome: " << c.obtemNome() << endl;
                                                                                                                                             cout << "Rodas: " << c.obtemRodas() << endl;
                                                                                                                                                 cout << "Passageiros: " << c.obtemPassageiros() << endl;
                                                                                                                                                     cout << "Tipo: ";
                                                                                                                                                         switch(c.obtemTipo()) {
                                                                                                                                                                 case COMPACTO: cout << "COMPACTO" << endl; break;
                                                                                                                                                                         case HATCH: cout << "HATCH" << endl; break;
                                                                                                                                                                                 case SEDAN: cout << "SEDAN" << endl; break;
                                                                                                                                                                                         case SUV: cout << "SUV" << endl; break;
                                                                                                                                                                                                 default: cout << "OUTRO" << endl;
                                                                                                                                                                                                     }
                                                                                                                                                                                                         cout << "--------------------" << endl;
                                                                                                                                                                                                         }
                                                                                                                                                                                                         
                                                                                                                                                                                                         int main() {
                                                                                                                                                                                                             Veiculo moto("moto", 2, 2);
                                                                                                                                                                                                                 imprimeVeiculo(moto);
                                                                                                                                                                                                                     
                                                                                                                                                                                                                         Veiculo triciclo("triciclo", 3, 2);
                                                                                                                                                                                                                             imprimeVeiculo(triciclo);
                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                     Veiculo jipe;
                                                                                                                                                                                                                                         imprimeVeiculo(jipe);
                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                 jipe.defineNome("jipe");
                                                                                                                                                                                                                                                     imprimeVeiculo(jipe);
                                                                                                                                                                                                                                                         
                                                                                                                                                                                                                                                             jipe.defineRodas(4);
                                                                                                                                                                                                                                                                 imprimeVeiculo(jipe);
                                                                                                                                                                                                                                                                     
                                                                                                                                                                                                                                                                         jipe.definePassageiros(4);
                                                                                                                                                                                                                                                                             imprimeVeiculo(jipe);
                                                                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                                                                     Caminhao caminhao1("Mercedes Benz 710", 6, 3, 9100);
                                                                                                                                                                                                                                                                                         imprimeCaminhao(caminhao1);
                                                                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                                                 Caminhao caminhao2;
                                                                                                                                                                                                                                                                                                     imprimeCaminhao(caminhao2);
                                                                                                                                                                                                                                                                                                         
                                                                                                                                                                                                                                                                                                             caminhao2.defineNome("Caçamba");
                                                                                                                                                                                                                                                                                                                 imprimeCaminhao(caminhao2);
                                                                                                                                                                                                                                                                                                                     
                                                                                                                                                                                                                                                                                                                         caminhao2.defineRodas(10);
                                                                                                                                                                                                                                                                                                                             imprimeCaminhao(caminhao2);
                                                                                                                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                                                                                                                     caminhao2.definePassageiros(3);
                                                                                                                                                                                                                                                                                                                                         imprimeCaminhao(caminhao2);
                                                                                                                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                                                                                                 caminhao2.defineCarga(30000);
                                                                                                                                                                                                                                                                                                                                                     imprimeCaminhao(caminhao2);
                                                                                                                                                                                                                                                                                                                                                         
                                                                                                                                                                                                                                                                                                                                                             Carro carro1("VW Up!", 4, 5, COMPACTO);
                                                                                                                                                                                                                                                                                                                                                                 imprimeCarro(carro1);
                                                                                                                                                                                                                                                                                                                                                                     
                                                                                                                                                                                                                                                                                                                                                                         Carro carro2;
                                                                                                                                                                                                                                                                                                                                                                             imprimeCarro(carro2);
                                                                                                                                                                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                                                                                                                                                                     carro2.defineNome("Mitsubishi Pajero Sport");
                                                                                                                                                                                                                                                                                                                                                                                         imprimeCarro(carro2);
                                                                                                                                                                                                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                                                                                                                                                 carro2.defineRodas(4);
                                                                                                                                                                                                                                                                                                                                                                                                     imprimeCarro(carro2);
                                                                                                                                                                                                                                                                                                                                                                                                         
                                                                                                                                                                                                                                                                                                                                                                                                             carro2.definePassageiros(7);
                                                                                                                                                                                                                                                                                                                                                                                                                 imprimeCarro(carro2);
                                                                                                                                                                                                                                                                                                                                                                                                                     
                                                                                                                                                                                                                                                                                                                                                                                                                         carro2.defineTipo(SUV);
                                                                                                                                                                                                                                                                                                                                                                                                                             imprimeCarro(carro2);
                                                                                                                                                                                                                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                                                                                                                                                                                                                     return 0;
                                                                                                                                                                                                                                                                                                                                                                                                                                     }
                                                                                                                                                                                                                                                                                                                                                                                                                                     */