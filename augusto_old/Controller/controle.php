<?php

require_once("Model/Contato.php");
require_once("Model/ContatoFactory.php");

class Controller {

    private $ger;

    public function __construct() {

        
        $this->ger = new ContatoFactory();

        ini_set('error_reporting', E_ALL);
        ini_set('display_errors', 1);
    }

    public function init() {

        if (isset($_GET['op'])) {
            $op = $_GET['op'];
        } else {
            $op = "";
        }

        switch ($op) {
            case 'nv':
                $this->novo();
                break;
            case 'cad':
                $this->cad();
                break;
            case 'lst':
                $this->lista();
                break;
            case 'out':
                $this->out();
                break;
            case 'cfg':
                $this->cfg();
                break;
            default:
                $this->index();
                break;
        }
    }

    public function index() {
        require 'View/index.php';
    }

    public function novo() {
        require 'View/novo.php';
    }

    public function cad() {
        if (isset($_POST['submit'])) {

            $nome = $_POST['nome'];
            $email = $_POST['email'];
            $sucesso = false;
            try {
                if ($nome == "" || $email == "")
                    throw new Exception('Erro');

                $contato = new Contato($nome, $email);

                //consulta o e-mail no banco
                $result = $this->ger->buscar($email);                
                              
                // se o resultado for igual a 0 itens, então salva contato
                if (count($result) == 0) {
                    $sucesso = $this->ger->salvar($contato);
                }
                
                if ($sucesso) {
                    $msg = "<p>O contato " . $nome . " (" . $email . ") foi cadastrado com sucesso!</p>";
                } else if (!$sucesso && count($result) > 0) {
                    $msg = "<p>O contato n&atilde;o foi adicionado. E-mail j&aacute; existente na agenda!</p>";
                } else {
                    $msg = "<p>O contato n&atilde;o foi adicionado. Tente novamente mais tarde!</p>";
                }

                unset($nome);
                unset($email);


                require 'View/mostra.php';
            } catch (Exception $e) {
                if ($nome == "") {
                    $msg = "O campo <strong>Nome</strong> deve ser preenchido!";
                } else if ($email == "") {
                    $msg = "O campo <strong>E-mail</strong> deve ser preenchido!";
                }
                require 'View/erro.php';
            }
        }
    }

    public function lista() {

        $result = $this->ger->listar();
        
        if (count($result) == 0){
            $msg = "Não há contatos cadastrados.";
            require 'View/erro.php';
        } else {
            require 'View/lista.php';
        }
    }

    public function out() {
        session_start('EmailContato');
        session_destroy();

        require 'View/index.php';
    }
    
    public function cfg() {
        require 'View/configuracao.php';
        
    }

}

?>