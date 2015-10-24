package aula78;

public class TimeTest1 {
	public static void main(String[] args) {
		Time time1 = new Time(12, 61, 32);
		time1.toUniversalString();
		
		Time time2 = new Time();
		time2.toUniversalString();

		Time time3 = new Time(23);
		time3.toUniversalString();

		time3.setHour(32);

		// Not allowed, because attribute hour is private
		// time3.hour = 34;

		System.out.println(time1.toUniversalString());
	}
}