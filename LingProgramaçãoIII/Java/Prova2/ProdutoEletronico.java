public class ProdutoEletronico extends Produto {
    
    private int garantiaMeses;
    private String tensaoVoltagem;

    public ProdutoEletronico(String nome, double preco, int estoque, int garantiaMeses, String tensaoVoltagem) {

        super(nome, preco, estoque);
        this.garantiaMeses = garantiaMeses;
        this.tensaoVoltagem = tensaoVoltagem;
    }

    public int getGarantiaMeses() {

        return garantiaMeses;
    }

    public void setGarantiaMeses(int garantiaMeses) {

        if (garantiaMeses >= 0 ){
            
            this.garantiaMeses = garantiaMeses;
        }

        else this.garantiaMeses = 12;
    }

    public String getTensaoVoltagem() {

        return tensaoVoltagem;
    }

    public void setTensaoVoltagem(String tensaoVoltagem) {

        if (tensaoVoltagem == "110V" || tensaoVoltagem == "220V" || tensaoVoltagem == "Bivolt"){

            this.tensaoVoltagem = tensaoVoltagem;
        }

        else this.tensaoVoltagem = "Bivolt";
    }

    @Override
    public String toString() {

        return super.toString() + 
               ", Garantia: " + garantiaMeses + " meses" + 
               ", Tensão: " + tensaoVoltagem;
    }
}
