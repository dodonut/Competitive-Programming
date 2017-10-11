public class code{

    public static boolean val(int linha, int coluna, int[] vet){
        int diag = 1;
        for (int i = linha-1; i >= 0; i--){
            if (vet[i] == coluna ||
                vet[i] == coluna - diag ||
                vet[i] == coluna + diag) return false;
            diag++;
        }
        return true;
    }

    public static void print(int[] vet){
        for (int i = 0;  i < 8; i++){
            System.out.print(vet[i]);
        }
        System.out.println();
    }
    public static void queen(int linha, int[] vet){
        if (linha != 8){
            for (int coluna = 0; coluna < 8; coluna++){
                if (val(linha, coluna, vet)){
                    vet[linha] = coluna;
                    queen(linha + 1, vet);
                }
            }
        }else print(vet);
    }


    public static void main(String[] args){
        int[] vet = new int[8];
        queen(0, vet);
    }
}