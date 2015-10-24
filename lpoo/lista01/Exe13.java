public class Exe13 {

    public static void main(String[] args) {
	int i,soma=0;

	for(i=1;i<100;i++){
	    if(i%5==0){
		/*System.out.println("Entrou aqui");*/
		continue;
	    }
	    soma+=i;
	}

	System.out.println(soma);

    }
}