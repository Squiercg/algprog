public class Exe05 {

    public static void main(String[] args) {
	int soma;

        System.out.println("Contagem usando o for:");
	for(int i=150;i<=300;i++){
        System.out.println(i);
	}

        System.out.println("Contagem usando o while:");
	int i=150;
	while(i<=300) {
            System.out.println(i);
	    i++;
	}

        System.out.println("Contagem usando o while:");
	i=150;
	do{
            System.out.println(i);
	    i++;
	}while(i<=300);
    }

}
