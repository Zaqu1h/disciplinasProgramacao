package lp3aluno;

import java.util.Scanner;

public class Aluno {
    
    private String nome;
    private String curso;
    private String email;
    private static int id = 1;
    private static int ano = 0;
    private int matricula;

    public Aluno(){

        this.nome  = "Exemplo";
        this.curso = "Qualquer";
        this.email = "@uesc.br";
        this.matricula = 19741;
    }

    public int getId(){

        return id;
    }
    
    public int getMatricula(){

        return matricula;
    }

    public int getAno(){

        return ano;
    }

    public String getNome(){

        return nome;
    }

    public String getCurso(){

        return curso;
    }

    public String getEmail(){

        return email;
    }

    public Aluno(int matricula){

        if(ano == 0){

            ano = matricula/10;
        }
        else if(matricula > ano){

            ano = matricula/10;
            id = 1;
        }
        else{

            matricula = ano * 10 + matricula % 10;
        }

        matricula *= 10000;
        matricula += id++;
        this.matricula = matricula;
    }

    public boolean validarInput(String linha){

        int i = 0;
        char atual;

        for(i = 0; i < linha.length(); i++){

            atual = nome.charAt(i);

            if(!(Character.isLetter(atual)) && atual != ' '){

                i = linha.length() + 1;
            }
        }

        if(i != 0){

            System.out.println("Apenas devem haver letras.");
            return false;
        }

        return true;
    }

    public Aluno inserirNome(Aluno novo, String nome){

        if(validarInput(nome.trim()) == true){

            novo.nome = nome.trim();
        }

        return novo;
    }

    public Aluno inserirCurso(Aluno novo, Scanner scan){

        System.out.println("Insira a sigla do curso: ");
        String trans = scan.nextLine();
        trans = trans.trim();

        if(trans.length() > 4 || trans.length() <= 2|| !(validarInput(trans))){

            throw new IllegalArgumentException("Incorrespondente a uma sigla de curso.\n");
        }

        novo.curso = trans;

        return novo;
    }

    public Aluno gerarEmail(Aluno novo){

        String sigla = "";
        int ultimoSpace = novo.nome.lastIndexOf(" ");
        char atual;
        char ant;

        for(int i = 0; i <= ultimoSpace + 1; i++){

            ant = (i != 0) ? novo.nome.charAt(i-1) : ' ';
            atual = novo.nome.charAt(i);

            if(ant == ' ' || i == 0){

                sigla = sigla + atual;
            }
        }

        String sobrenome = (ultimoSpace != -1) ? novo.nome.substring(ultimoSpace + 1) : "";

        novo.email = sobrenome.toLowerCase() + sigla.toLowerCase() + "@uesc.br";

        return novo;
    }

    public static boolean igualA(Aluno um, Aluno dois){

        return (um.matricula == dois.matricula);
    }

    public boolean sIgualA(Aluno that){

        return (this.matricula == that.matricula);
    }
}
