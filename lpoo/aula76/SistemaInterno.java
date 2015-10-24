package aula76;

public class SistemaInterno {
	public boolean login(Autenticavel f, String usuario, String senha) {
		return f.autentica(usuario, senha);
	}
}
