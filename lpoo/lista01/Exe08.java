public class Exe08 {

    public static void main(String[] args) {
	/*Questão 9, aqui deveria ser long?*/
	int fat;

        System.out.println("Fatoriais usando o for:");
	for(int i=1;i<=10;i++){
	    fat=1;
	    for(int j=1;j<=i;j++){
		fat=fat*j;
	    }
	    System.out.println(fat);
	}

        System.out.println("Fatoriais usando o while:");
	int i=1;
	int j=0;
	while(i<=10) {
	    fat=1;
	    j=1;
	    while(j<=i){
		fat=fat*j;
		j++;
	    }
	    System.out.println(fat);
	    i++;
	}

        System.out.println("Fatoriais usando o do-while:");
	i=1;
	j=0;
	do{
	    fat=1;
	    j=1;
	    do{
		fat=fat*j;
		j++;
	    }while(j<=i);
	    System.out.println(fat);
	    i++;
	}while(i<=10);

    }

}
