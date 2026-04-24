public class Produto {
    private String nome;
    private double preco;
    private int estoque;

    public Produto(String nome, double preco, int estoque) {

        this.nome = nome;
        this.preco = preco;
        this.estoque = estoque;
    }

    public String getNome() {
        return nome;
    }

    public double getPreco() {
        return preco;
    }

    public int getEstoque() {
        return estoque;
    }

    // Método para adicionar ao estoque
    public void adEstoque(int quant) {
        this.estoque += quant;
    }

    public boolean remEstoque(int quant) {
        if (quant <= this.estoque) {
            this.estoque -= quant;
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        return "Nome: " + nome + ", Preço: " + preco + ", Estoque: " + estoque;
    }
}
