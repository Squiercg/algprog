public class Exe12 {

    public static void main(String[] args) {
	int i;

	for(i=1;i<1000000;i++){
	    if(i%11==0 && i%13==0 && i%17==0){
		break;
	    }
	}

	System.out.println(i);

    }
}