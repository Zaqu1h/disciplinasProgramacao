public class Contador {
    private int valor;

    public Contador() {
        this.valor = 0;
    }

    public Contador(int i) {
        this.valor = i;
    }

    public int getContador() {
        return this.valor;
    }

    public void incrementa() {
        this.valor++;
    }

    public void decrementa() {
        this.valor--;
    }

    public boolean menorQue(int j) {
        return this.valor < j;
    }

    public boolean igualA(int j) {
        return this.valor == j;
    }

    public boolean maiorQue(int j) {
        return this.valor > j;
    }
}
