package lp3lampada;

class SistemaIluminacao extends Lampada{

    private Lampada[] bulbos;
    private int quantidade;

    public SistemaIluminacao(){

        this.bulbos = new Lampada[30];
        this.quantidade = 0;
    }

    public SistemaIluminacao(int capacidade){

        if(capacidade > 30){

            this.bulbos = new Lampada[30];
        }
        else{

            this.bulbos = new Lampada[capacidade];
        }
    }

    public boolean addLampada(){

        if(this.quantidade < bulbos.length){

            this.bulbos[this.quantidade] = new Lampada();
            return true;
        }

        return false;
    }

    public void acenderSistema(){

        for(int i = 0; i < quantidade; i++){

            bulbos[i].acender();
        }
    }

    public void apagarSistema(){

        for(int i = 0; i < quantidade; i++){
        
            bulbos[i].apagar();
        }
    }

    public int[] devoTrocarSist(){

        int[] paraTrocar = new int[this.quantidade];

        for(int i = 0; i < this.quantidade; i++){

            this.bulbos[i].devoTrocar();
            paraTrocar[i] = 1;
        }

        return paraTrocar;
    }
}
