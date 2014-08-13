public class Exe06 {

    public static void main(String[] args) {
	int soma;

        System.out.println("Soma usando o for:");
	soma=0;
	for(int i=150;i<=1000;i++){
	    soma=soma+i;
	}
        System.out.println("Resultado: "+soma);


        System.out.println("Soma usando o while:");
	soma=0;
	int i=150;
	while(i<=1000) {
	    soma=soma+i;
	    i++;
	}
        System.out.println("Resultado: "+soma);

        System.out.println("Soma usando o while:");
	soma=0;
	i=150;
	do{
	    soma=soma+i;
	    i++;
	}while(i<=1000);
        System.out.println("Resultado: "+soma);
    }

}
