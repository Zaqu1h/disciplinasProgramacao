public class Main {

    public static void main(String[] args) {

        float somatorio = 0.0f;
        Lampada[] arrayD = new Lampada[10];
        Contador k = new Contador();
        Contador m = new Contador();

        // Questao 3, item A
        Lampada[] array = new Lampada[10];

        // Questao 3, item B
        for(int i = 0; i < array.length; i++){

            array[i] = new Lampada();
            System.out.printf("%f\n", array[i].getIntensidade());
        }

        System.out.printf("\n");

        // Teste, Questão 3B    
        for(int i = 0; i < array.length; i++){

            somatorio += array[i].getIntensidade();
        }

        if(somatorio != 0.0f){

            System.out.println("As lampadas nao inicializaram corretamente (desligadas, zeradas).");
        }

        somatorio = 0.0f;

        // Questao 3, item C
        for(int i = 0; i < array.length; i++){
            for(int j = 0; j <= i; j++){

                array[i].aumentar();
            }

            System.out.printf("%f\n", array[i].getIntensidade());
        }

        System.out.printf("\n");

        // Teste, Questão 3C
        for(int i = 1; i < array.length; i++){

            if(Math.abs((array[i].getIntensidade() - array[i-1].getIntensidade()) - 0.1f) > 0.0001f){

                System.out.println("Uma diferenca de [n] para [n-1] diferente de 0.1 foi encontrada.\n");
                break;
            }
        }

        // Questão 5, 3B
        while(k.getContador() < arrayD.length){

            arrayD[k.getContador()] = new Lampada();

            System.out.printf("%f\n", arrayD[k.getContador()].getIntensidade());

            k.incrementa();
        }

        System.out.printf("\n");

        // Teste, Questão 5, 3B
        for(int i = 0; i < arrayD.length; i++){

            somatorio += arrayD[i].getIntensidade();
        }

        if(somatorio != 0.0f){

            System.out.println("As lampadas nao inicializaram corretamente (desligadas, zeradas).");
        }

        somatorio = 0.0f;

        // Questao 5, 3C
        while(m.getContador() < arrayD.length){

            if(m.getContador() == 0){

                arrayD[0].aumentar();
            }
            else{

                arrayD[m.getContador()].setIntensidade(0.1f + (m.getContador() * 0.1f));
            }

            System.out.printf("%f\n", arrayD[m.getContador()].getIntensidade());

            m.incrementa();
        }

        System.out.printf("\n");

        // Teste, Questao 5, 3C
        for(int i = 1; i < arrayD.length; i++){

            if (Math.abs((arrayD[i].getIntensidade() - arrayD[i-1].getIntensidade()) - 0.1f) > 0.0001f){

                System.out.printf("Uma diferença de [n] para [n-1] diferente de 0.1 foi encontrada.\n");
                break;
            }
        }
    }
}
