/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function confere_pergunta01() {
    var x, text;

    // Pegando a resposta que está no input
    x = document.getElementById("pergunta01").value;

    // Se a entrada for null ou uma string vaziu, nenhuma resposta foi enviada,
    //senão dizemos se está correto ou não.
    if (isNaN(x) || x == "") {
        text = "Nós temos 23 cromossomos, então a resposta tem que ser um número entre 1 e 23.";
    } else {
        if (x != 11) {
            text = "De uma olhada onde você tem que olhar para conseguir achar a resposta. <img src=\"imagens/blat03R1.png\" height=\"400px\">  <img src=\"imagens/blat04R1.png\" height=\"400px\">";
        } else {
            text = "Parabéns, é isso ae!";
        }
    }
    document.getElementById("resposta01").innerHTML = text;
}

function confere_pergunta02() {
    var x, text;

    // Pegando a resposta que está no input
    inicio = document.getElementById("pergunta02_inicio").value;
    fim = document.getElementById("pergunta02_fim").value;

    // Se a entrada for null ou uma string vaziu, nenhuma resposta foi enviada,
    //senão dizemos se está correto ou não.
    if (isNaN(inicio) || inicio == "" || isNaN(fim) || fim == "") {
        text = "Você tem que preencher onde a sequência começa e termina no genoma";
    } else {
        if (inicio != 2160851 || fim != 2160910) {
            text = "De uma olhada onde você tem que olhar para conseguir achar a resposta. <img src=\"imagens/blat03R2.png\" height=\"400px\">  <img src=\"imagens/blat04R2.png\" height=\"400px\">";
        } else {
            text = "Parabéns, você acertou!";
        }
    }
    document.getElementById("resposta02").innerHTML = text;
}

function sequencia_aleatoria(n) {
    var dna = "";
    var possible = "atgc";

    for (var i = 0; i < n; i++)
        dna += possible.charAt(Math.floor(Math.random() * possible.length));
    return dna;
}

function gera_sequencia_blat() {
    var sequencia = "";
    
    sequencia = sequencia_aleatoria(60);
    
    document.getElementById("sequencia_blat").innerHTML = sequencia; 
}
