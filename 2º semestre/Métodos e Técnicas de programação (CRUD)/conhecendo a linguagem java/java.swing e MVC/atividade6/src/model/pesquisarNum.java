package model;
public class pesquisarNum {
    public static int contarUnidade(String numero, char unidade) {
        return contarUnidadeRecursivamente(numero, unidade, 0, 0);
    }

    private static int contarUnidadeRecursivamente(String numero, char unidade, int index, int count) {
        if (index >= numero.length()) return count;
        
        if (numero.charAt(index) == unidade) count++;
        return contarUnidadeRecursivamente(numero, unidade, index + 1, count);
    }
}
