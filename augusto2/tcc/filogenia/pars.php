<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

$arquivo = fopen("pars_entrada.txt", "w") or die("Unable to open file!");
fwrite($arquivo, "     15    5\n");

$especies = array("A_alutaceus   ","A_angusticeps ","A_chlorocyanus","A_cristatellus","A_cybotes     ","A_grahami     ","A_lineatopus  ","A_occultus    ","A_olssoni     ","A_ophiolepis  ","A_porcatus    ","A_pulchellus  ","A_sagrei      ","A_shelpani    ","A_valencienni ");

if (isset($_POST['elements'])) {
    $vetor = explode(',', $_POST['elements']);
    $j=0;
    for ($i = 0; $i < sizeof($vetor); $i++) {
        
        if(fmod($i,5)==0){
            fwrite($arquivo, $especies[$j]." ");
            $j=$j+1;
        }
        
        
        fwrite($arquivo, $vetor[$i]);  
        
        
        if(fmod($i+1,5)==0){
            fwrite($arquivo, "\n"); 
        }

    }
}

fclose($arquivo);

$output = shell_exec( './pars < pars_parametros.txt' );
?> 



        
