package aula6;

public class SistemaInterno {
	public boolean login(
			FuncionarioAutenticavel funcionarioAutenticavel, 
			String usuario, 
			String senha){
		return funcionarioAutenticavel.autentica(usuario, senha);
	}

}
