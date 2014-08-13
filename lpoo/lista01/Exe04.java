public class Exe04 {

    public static void main(String[] args) {

        System.out.println("Imprimindo usando o for:");
	for(int i=150;i<=300;i++){
	    System.out.println(i);
	}

        System.out.println("Imprimindo usando o while:");
	int i=150;
	while(i<=300) {
	    System.out.println(i);
	    i++;
	}

        System.out.println("Imprimindo usando o while:");
	i=150;
	do{
	    System.out.println(i);
	    i++;
	}while(i<=300);

        System.out.println("Fim!");


    }

}