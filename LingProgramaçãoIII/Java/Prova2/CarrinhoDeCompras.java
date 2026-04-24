public class CarrinhoDeCompras {

    private Produto[] itens;
    private int[] quantidade;
    private int qtItens = 0;

    public CarrinhoDeCompras(int qnt){

        if(qnt > 0){

            itens = new Produto[qnt];
            quantidade = new int[qnt];
            qtItens = 0;
        }
    }

    public CarrinhoDeCompras(){

        this(10);
    }

    public int adicionarItem(Produto produto, int qtd) {

    if (produto.getEstoque() >= qtd) {

        produto.remEstoque(qtd);
        itens[qtItens] = produto;
        quantidade[qtItens] = qtd;
        qtItens++;

        return 0;

    } else {

        return qtd - produto.getEstoque();
    }
}


    public boolean removerItem(Produto produto, int qtd) {

        for (int i = 0; i < qtItens; i++) {

            if (itens[i] == produto && quantidade[i] >= qtd) {

                quantidade[i] -= qtd;

                if (quantidade[i] == 0) {

                    for (int j = i; j < qtItens - 1; j++) {

                        itens[j] = itens[j + 1];
                        quantidade[j] = quantidade[j + 1];
                    }

                    qtItens--;
                }

                produto.adEstoque(qtd);
                return true;
            }
        }

        return false;
    }

    public double calcularTotal() {

        double total = 0;

        for (int i = 0; i < qtItens; i++) {

            total += itens[i].getPreco() * quantidade[i];
        }

        return total;
    }

    public void exibirItens() {

        for (int i = 0; i < qtItens; i++) {

            System.out.println("Nome: " + itens[i].getNome() +
                               ", Preço: " + itens[i].getPreco() +
                               ", Quantidade: " + quantidade[i]);
        }
    }
}
