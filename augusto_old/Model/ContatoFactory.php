<?php
require_once('Contato.php');
require_once('AbstractFactory.php');

class ContatoFactory extends AbstractFactory {
    private $nomeTabela = 'tbcontato';
    private $campos = "'nome', 'email'";
    
    public function __construct() {
        parent::__construct();
    }
    
    public function listar() {        
        $sql = "select * from " . $this->nomeTabela . " ";        
        try {
            $resultado = $this->db->query($sql);
            return $this->queryRowsToListOfObjects($resultado, "Contato");
        } catch (Exception $ex) {
            $msg = "Erro no listar." . $ex;
            require 'View/erro.php';
        }      
    }
    
    public function buscar($param) {
        $sql = "select * from " . $this->nomeTabela . " where email = '" . $param . "'";
        
        try {
            $resultado = $this->db->query($sql);
            return $this->queryRowsToListOfObjects($resultado, "Contato");
        } catch (Exception $ex) {
            $msg = "Não encontrado." . $ex;
            require 'View/erro.php';
        } 
    }
    
    public function salvar($obj) {
                
        $sql = "insert into " . $this->nomeTabela . " (" . $this->campos . ") values ( ' " . $obj->getNome() . "', '" . $obj->getEmail() . "' )";
        
/* Ver erros do banco        
$this->db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_WARNING);
*/
        $resultado=$this->db->exec($sql);
                
        if($resultado){
            return true;
        } else {
            return false;
        }
        
    }
}
    


/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


?>

