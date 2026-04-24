public class Main {
    public static void main(String[] args) {

        Produto p1 = new Produto("Caneta", 2.5, 100);
        ProdutoEletronico p2 = new ProdutoEletronico("Lampada", 10, 1, 6, "110V");
        ProdutoAlimenticio p3 = new ProdutoAlimenticio("Arroz", 6.0, 5, "03/07/2026", 5);

        // Teste dos toStrings
        System.out.println(p1);
        System.out.println(p2);
        System.out.println(p3);
        System.out.println();

        CarrinhoDeCompras carrinho = new CarrinhoDeCompras(5);

        // Teste do add ----------------------------------------------------------------------------------

        int falta = carrinho.adicionarItem(p1, 2);

        System.out.println(falta == 0 ? "Adicionado 2 Canetas" : "Falta: " + falta + " caneta(s)");

        falta = carrinho.adicionarItem(p2, 2);

        System.out.println(falta == 0 ? "Adicionado 2 Lampadas" : "Falta: " + falta + " lampada(s)");

        falta = carrinho.adicionarItem(p3, 5);

        System.out.println(falta == 0 ? "Adicionado 5 Arroz" : "Falta: " + falta + "kg(s) de arroz");
        System.out.println();

        // -----------------------------------------------------------------------------------------------

        carrinho.exibirItens();
        System.out.println();

        // Teste do calcularTotal ------------------------------------------------------------------------

        double total = p3.getPreco() * 5 + p1.getPreco() * 2;

        if(carrinho.calcularTotal() == total)
            System.out.println("Carrinho: R$" + carrinho.calcularTotal());
            System.out.println();

        // -----------------------------------------------------------------------------------------------

        // Teste da remoçãwn -----------------------------------------------------------------------------

        boolean removido = carrinho.removerItem(p3, 1);

        System.out.println(removido ? "1KG de arroz removido." : "Falha ao remover.");
        System.out.println();

        carrinho.exibirItens();
        System.out.println();

        // -----------------------------------------------------------------------------------------------

        // Estoque depois das alterações
        System.out.println(p1.getNome() + ": " + p1.getEstoque());
        System.out.println(p2.getNome() + ": " + p2.getEstoque());
        System.out.println(p3.getNome() + ": " + p3.getEstoque());
    }
}
