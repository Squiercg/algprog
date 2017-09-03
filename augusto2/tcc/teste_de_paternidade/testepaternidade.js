/* 
 *Váriaveis globais para manter as respostas, inicializadas quando a página
 *é aberta
 */
//Pergunta 01
var resposta01 = Math.floor(Math.random() * (10 - 5 + 1)) + 5;
//Interpretando teste de paternidade
var tabela_paternidade = [
    [13, 14, 11, 13],
    [29, 30, 29, 30],
    [8, 10, 10, 11],
    [11, 11, 11, 12],
    [15, 17, 14, 15],
    [7, 9, 7, 9],
    [11, 13, 11, 11],
    [11, 12, 11, 11],
    [20, 24, 23, 24],
    [13, 13, 13, 14],
    [14, 17, 17, 17],
    [8, 11, 8, 8],
    [14, 17, 13, 14],
    [11, 12, 11, 12],
    [21, 24, 21, 24]
];


/*
 * Função para iniciar tudo no body
 */
function inicio() {
    geraseq01();
    geraseq_tabela()
}

/*
 * Função que gera uma sequência de dna aleatória do dicionario atgc, recebe
 * 
 */
function sequencia_aleatoria(n) {
    var dna = "";
    var possible = "atgc";

    for (var i = 0; i < n; i++)
        dna += possible.charAt(Math.floor(Math.random() * possible.length));
    return dna;
}

/*
 * Gera sequência para a pergunta 01
 */

function geraseq01() {
    var ms = "gata";
    var saida = sequencia_aleatoria(10);

    saida += '<font color="blue">';

    for (var i = 0; i < resposta01; i++) {
        saida += ms;
    }

    saida += '</font>';

    saida += sequencia_aleatoria(10);

    document.getElementById("sequencia01").innerHTML = saida;
}

/*
 * Resposta da pergunta 1
 */

function confere_pergunta01() {
    var x, text;

    // Pegando a resposta que está no input
    x = document.getElementById("pergunta01").value;

    // Se a entrada for null ou uma string vaziu, nenhuma resposta foi enviada,
    //senão dizemos se está correto ou não.
    if (isNaN(x) || x == "") {
        text = "Entre com o número de repetições que você contou!";
    } else {
        if (x != resposta01) {
            text = "Resposta incorreta!";

        } else {
            text = "Parabéns, você acertou!";
        }
    }
    document.getElementById("resposta01").innerHTML = text;
}

/*
 * Tabela de paternidade
 */

function geraseq_tabela() {

    for (var j = 0; j < 15; j++) {
        for (var i = 0; i < 4; i++) {
            document.getElementById("t".concat(j,"_", i)).innerHTML = tabela_paternidade[j][i];
        }
    }
}


function confere_tabela_paternidade(linha) {
    var x, text, linha;

    // Pegando a resposta que está no input
    x = document.querySelector('input[name="pai_linha'.concat(linha,'"]:checked')).value;

    if (tabela_paternidade[linha][x] === tabela_paternidade[linha][0] || tabela_paternidade[linha][x] === tabela_paternidade[linha][1]) {
        text = "Correto";
        if (x == 3) {
            document.getElementById("t".concat(linha,"_", x)).innerHTML = "<font color='green'><strong>".concat(tabela_paternidade[linha][x], "</strong></font>");
        } else {
            document.getElementById("t".concat(linha,"_", x)).innerHTML = "<font color='green'><strong>".concat(tabela_paternidade[linha][x], "</strong></font>");           
        }

    } else {
        text = "Errado";
        if (x == 3) {
            document.getElementById("t".concat(linha,"_", x)).innerHTML = "<font color='red'><strong>".concat(tabela_paternidade[linha][x], "</strong></font>");
        } else {
            document.getElementById("t".concat(linha,"_", x)).innerHTML = "<font color='red'><strong>".concat(tabela_paternidade[linha][x], "</strong></font>");           
        }
    }
    document.getElementById("resposta_tabela").innerHTML = text.concat(" x vale ", x);
}


/*
 * Funções auxiliates
 */


