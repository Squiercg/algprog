
public class Triangle {

	/**
	 * Desenha um triangulo
	 */
	public static void main(String[] args) {
		double t = Math.sqrt(3.0) / 2.0;
        StdDraw.line(0.0, 0.0, 1.0, 0.0);
        StdDraw.line(1.0, 0.0, 0.5, t);
        StdDraw.line(0.5, t, 0.0, 0.0);
        StdDraw.setXscale(0, 1);
        StdDraw.setYscale(0, 1);
        StdDraw.point(0.5, t/3.0);
        for(int i=0 ; i<10 ; i++) {
        	StdDraw.point(Math.random(),Math.random());
        }               
        System.out.println(t/3.0);
	}

}
