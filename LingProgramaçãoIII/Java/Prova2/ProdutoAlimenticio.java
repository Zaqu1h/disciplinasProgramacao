public class ProdutoAlimenticio extends Produto{
    
    private String dataValidade;
    private double pesoKG;

    public ProdutoAlimenticio(String nome, double preco, int estoque, String dataValidade, double pesoKG) {

        super(nome, preco, estoque);
        this.dataValidade = dataValidade;
        this.pesoKG = pesoKG;
    }

    public String getDataValidade() {

        return dataValidade;
    }

    public void setDataValidade(String dataValidade) {

        this.dataValidade = dataValidade;
    }

    public double getPesoKG() {

        return pesoKG;
    }

    public void setPesoKG(double pesoKG) {

        if(pesoKG >= 0){
            
            this.pesoKG = pesoKG;
        }

        else this.pesoKG = 1;
    }

    @Override
    public String toString() {
        
        return super.toString() +
               ", Validade: " + dataValidade +
               ", Peso: " + pesoKG + "kg";
    }
}

