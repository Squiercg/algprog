<?php

/*
Contato.php - classe PHP com nome e email
*/

    class Contato {

    public $nome;
    public $email;

    function __construct($nome, $email) {
        $this->nome = $nome;
        $this->email = $email;
    }

    function getNome() {
        return $this->nome;
    }

    function getEmail() {
        return $this->email;
    }

    function setNome($nome) {
        $this->nome = $nome;
    }

    function setEmail($email) {
        $this->email = $email;
    }

}
