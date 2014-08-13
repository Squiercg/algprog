public class Exe07 {

    public static void main(String[] args) {
	int soma;

        System.out.println("Multiplos de três usando o for:");
	for(int i=1;i<=1000;i++){
	    if((i%3)==0){
		System.out.println(i);
	    }
	}


        System.out.println("Multiplos de três usando o while:");
	soma=0;
	int i=150;
	while(i<=1000) {
	    if((i%3)==0){
		System.out.println(i);
	    }
	    i++;
	}

        System.out.println("Multiplos de três usando o do-while:");
	soma=0;
	i=150;
	do{
	    if((i%3)==0){
		System.out.println(i);
	    }
	    i++;
	}while(i<=1000);

    }

}
