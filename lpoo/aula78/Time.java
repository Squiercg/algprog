package aula78;

public class Time {
	private int hour;
	private int minute;
	private int second;

	public Time() {

	}

	public Time(int hour, int minute, int second) {
		setTime(hour, minute, second);
	}

	public Time(int hour) {
		setTime(hour, 0, 0);
	}

	public void setHour(int hour) {
		if(hour < 24 && hour >= 0)
			this.hour = hour;
		else
			this.hour = 0;
	}

	public void setMinute(int minute) {
		if(minute >= 0 && minute < 60)
			this.minute = minute;
		else
			this.minute = 0;
	}

	public void setSecond(int second) {
		if(second >= 0 && second < 60)
			this.second = second;
		else
			this.second = 0;
	}

	public void setTime(int hour, int minute, int second) {
		setHour(hour);
		setMinute(minute);
		setSecond(second);
	}

	public int getHour() {
		return hour;
	}

	public String toUniversalString() {
		return String.format("%02d:%02d:%02d", hour, minute, second);
	}
}