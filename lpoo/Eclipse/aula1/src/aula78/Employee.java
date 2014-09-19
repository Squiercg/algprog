package aula78;

public class Employee {
	private String name;
	private String cpf;

	private static int count = 0;

	public Employee() {
		setName("");
		setCpf("");
		count++;
	}

	public Employee(String name, String cpf) {
		setName(name);
		setCpf(cpf);
		count++;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public String getName() {
		return name;
	}

	public String getCpf(){
		return cpf;
	}

	public boolean equals(Employee e) {
		return this.name == e.name && this.cpf == e.cpf;
	}

	public String toString() {
		return "Name: " + this.name + ", Cpf: " + this.cpf;
	}

	public static int getCount() {
		return count;
	}
}