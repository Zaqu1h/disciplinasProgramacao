package lp3lampada;

public class Lampada {
    
    private boolean estado;
    private double potencia;
    private int limite;
    private int vezesLigadas;

    public Lampada(){

        estado = false;
        potencia = 15F;
        limite = 1000;
        vezesLigadas = 0;
    }

    public void acender(){

        this.vezesLigadas = (this.estado == false) ? this.vezesLigadas + 1 : this.vezesLigadas;
        this.estado = (this.estado == false) ? true : this.estado;
    }

    public void apagar(){

        this.estado = (this.estado == true) ? false : this.estado;
    }

    public boolean estaAcesa(){

        return (this.estado);
    }

    public double checarPotencia(){

        return (this.potencia);
    }

    public boolean devoTrocar(){

        return (this.vezesLigadas >= this.limite);
    }
}
