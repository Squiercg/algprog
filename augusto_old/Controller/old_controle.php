<?php
require_once '../Model/Contato.php';
//Inicia sessao
session_start();

/**
 * Material utilizado para as aulas práticas da disciplinas da Faculdade de
 * Computação da Universidade Federal de Mato Grosso do Sul (FACOM / UFMS).
 * Seu uso é permitido para fins apenas acadêmicos, todavia mantendo a
 * referência de autoria.
 * @author Profª Jane Eleutério
 */

//verifica se recebeu por GET o parâmetro op.
if (isset($_GET['op'])) {
    $op = $_GET['op'];
} else {
    $op = "";
}


// para cada valor recebido em 'op', será realizada uma ação.
switch ($op) {
    case 'nv':// requisição par a cadastrar novo contato
    include('../View/novo.php');
    break;

    case 'cad':// requisição que recebe os parametros do contato e salva na sessão
        //verifica se o formulário foi recebido via POST
    if (isset($_POST['submit'])) {
            //recebe os parâmetros
        $nome = $_POST['nome'];
        $email = $_POST['email'];

        try {
                //se algum campo não for preenchido, lança exceção
            if ($nome == "" || $email == "")
                throw new Exception('Erro');
            
            $novo = new Contato($nome,$email);

                //limpa as variáveis
            unset($nome);
            unset($email);
            
            if (empty($_SESSION['contatos'])){
                $_SESSION['contatos'] = array();
            }
            serialize(array_push($_SESSION['contatos'], $novo));

            $sucesso = true;

                //prepara as mensagens para o mostra.php
            if ($sucesso) {
                $msg = "<p>O contato " . $novo->nome . " (" . $novo->email . ") foi cadastrado com sucesso!</p>";
            } else {
                $msg = "<p>O contato não foi adicionado. Tente novamente mais tarde!</p>";
            }


                //inclui o mostra.php
            include('../View/mostra.php');
            } catch (Exception $e) {//caso tenha lançado execeção
                if ($nome == "") {
                    $msg = "O campo <strong>Nome</strong> deve ser preenchido!";
                } else if ($email == "") {
                    // essa msg nunca ocorre, o e-mail é required
                    $msg = "O campo <strong>E-mail</strong> deve ser preenchido!";
                }
                include('../View/erro.php');
            }
        }

        break;

    case 'lst'://requisição para listar os contatos cadastrados

    if (!isset($_SESSION['contatos'])){
        $msg = "Lista vazia";
        include('../View/erro.php');
    } else {

        include('../View/lista.php');
    }

    break;
    
    default:
    include('../View/index.php');
    break;
}
?>
