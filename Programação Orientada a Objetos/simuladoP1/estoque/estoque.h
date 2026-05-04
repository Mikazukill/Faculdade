class Estoque {
    private:
        int quantidade;
        double valor;
    public:
        Estoque (int q = 0, double v = 0.0) {
            quantidade = q;
            valor = v;
        }
        int obtemQuantidade () const {
            return quantidade;
        }
        double obtemValor () const {
            return valor;
        }
        void defineQuantidade (int q) {
            quantidade = q;
        }
        void defineValor (double v) {
            valor = v;
        }
        double obtemValorTotal () const {
            return quantidade * valor;
        }
};