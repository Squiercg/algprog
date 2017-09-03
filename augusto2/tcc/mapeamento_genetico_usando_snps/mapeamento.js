/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*Funcões auxiliares*/

var g1p1, g1p2, g1p3, g1p4, g1p5, g1p6, g1p7, g2p1, g2p2, g2p3, g2p4, g2p5, g2p6;
g1p1 = 0;
g1p2 = 6;


$(document).ready(function ()
{
    $("#locus").tablesorter();
    $("#tabela1").tablesorter();
    $("#tabela2").tablesorter();
}
);

function confere_pergunta01() {
    var x, text;

    // Pegando a resposta que está no input
    x = document.getElementById("pergunta01").value;

    // Se a entrada for null ou uma string vaziu, nenhuma resposta foi enviada,
    //senão dizemos se está correto ou não.
    if (isNaN(x) || x == "") {
        text = "Digite apenas o número de um dos locus";
    } else {
        if (x != 7) {
            text = '<p>Veja de novo a tabela, tente organizar no pelo locus 7, veja que os cachorros são perfeitamente separados, e além disso, cachorros brancos só tem alelos <b>A</b> enquanto os pretos só tem alelo <b>T</b></p> <img src="imagens/tab_locus7.png" height="600px">';

        } else {
            text = "<b>Parabéns, você acertou!</b>";
        }
    }
    document.getElementById("resposta01").innerHTML = text;
}

function confere_pergunta02() {
    var x, text;
    var respostas02 = [3, 13, 14];

    // Pegando a resposta que está no input
    x = document.getElementById("pergunta02").value;


    // Se a entrada for null ou uma string vaziu, nenhuma resposta foi enviada,
    //senão dizemos se está correto ou não.
    if (isNaN(x) || x == "") {
        text = "Digite apenas o número de um dos locus";
    } else {
        if (respostas02.indexOf(parseInt(x)) == -1) {
            text = '<p>Vamos pegar como exemplo o locus 3, mas existe mais de uma resposta aqui, veja que ele separa os cachorros pelas cores da sua pelagem, mas todos os cachorros brancos tem os nucleotídios <b>CC</b> enquanto os para os de pelagem preta, 3 tem os alelos <b>AC</b> e um tem <b>CC</b>, ou seja, temos uma separação, mas ela não é exata como o da resposta anterior. Existe outros locus além do 3 que caem nessa mesma categoria.</p> <img src="imagens/tab_locus3.png" height="600px">';

        } else {
            text = "Parabéns, você acertou!";
        }
    }
    document.getElementById("resposta02").innerHTML = text;
}

function confere_pergunta03() {
    var x, text;
    var respostas03 = [3, 7, 13, 14];

    // Pegando a resposta que está no input
    x = document.getElementById("pergunta03").value;


    // Se a entrada for null ou uma string vaziu, nenhuma resposta foi enviada,
    //senão dizemos se está correto ou não.
    if (isNaN(x) || x == "") {
        text = "Digite apenas o número de um dos locus";
    } else {
        if (respostas03.indexOf(parseInt(x)) != -1) {
            text = "Aqui, lembre-se que qualquer locus que não serve de resposta para as duas perguntas anteriores, é porque não tem associação com a cor da pelagem!";
        } else {
            text = "Parabéns, você acertou!";
        }
    }
    document.getElementById("resposta03").innerHTML = text;
}

function confere_pergunta04() {
    var x, text;

    // Pegando a resposta que está no input
    x = document.getElementById("pergunta04").value;


    // Se a entrada for null ou uma string vaziu, nenhuma resposta foi enviada,
    //senão dizemos se está correto ou não.
    if (x == "") {
        text = "Digite o nome do SNP como na tabela, por exemplo Chr32 1111111";
    } else {
        if (x != "Chr32 7473337") {
            text = "Resposta incorreta!";
        } else {
            text = "Parabéns, você acertou!";
        }
    }
    document.getElementById("resposta04").innerHTML = text;
}

function confere_pergunta05() {
    var x, text;

    // Pegando a resposta que está no input
    x = document.getElementById("pergunta05").value;


    // Se a entrada for null ou uma string vaziu, nenhuma resposta foi enviada,
    //senão dizemos se está correto ou não.
    if (x == "") {
        text = "Digite o nome do SNP como na tabela, por exemplo Chr32 1111111";
    } else {
        if (x != "Chr32 7420804") {
            text = "Resposta incorreta!";
        } else {
            text = "Parabéns, você acertou!";
        }
    }
    document.getElementById("resposta05").innerHTML = text;
}

function confere_pergunta06() {
    var x, text;

    // Pegando a resposta que está no input
    x = document.getElementById("pergunta06").value;


    // Se a entrada for null ou uma string vaziu, nenhuma resposta foi enviada,
    //senão dizemos se está correto ou não.
    if (x == "") {
        text = "Digite o nome do SNP como na tabela, por exemplo Chr27 1111111";
    } else {
        if (x != "Chr27 5542806") {
            text = "Resposta incorreta!";
        } else {
            text = "Parabéns, você acertou!";
        }
    }
    document.getElementById("resposta06").innerHTML = text;
}

function confere_pergunta07() {
    var entrada;

    entrada = "chi1";
    if (document.getElementById(entrada).value.toUpperCase() == 'G') {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "chi2";
    if (parseInt(document.getElementById(entrada).value) == 9) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "chi3";
    if (parseInt(document.getElementById(entrada).value) == 0) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "chi4";
    if (parseFloat(document.getElementById(entrada).value) == 4.5) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "chi5";
    if (document.getElementById(entrada).value.toUpperCase() == 'T') {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "chi6";
    if (parseInt(document.getElementById(entrada).value) == 3) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "chi7";
    if (parseInt(document.getElementById(entrada).value) == 12) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "chi8";
    if (parseFloat(document.getElementById(entrada).value) == 7.5) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "chi9";
    if (parseFloat(document.getElementById(entrada).value) == 14.4) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

}








/*
 * 
 * 
 */

window.onload = function () {
    var chart = new CanvasJS.Chart("grafico1",
            {
                title: {
                    text: "Associação"
                },
                animationEnabled: true,
                axisY: {
                    title: "Total de diferenças"
                },
                legend: {
                    verticalAlign: "bottom",
                    horizontalAlign: "center"
                },
                theme: "theme2",
                data: [

                    {
                        type: "column",

                        dataPoints: [
                            {y: g1p1, label: "Chr32 7420804"},
                            {y: g1p2, label: "Chr32 7420804"},
                            {y: g1p3, label: "Chr32 7420804"},
                            {y: g1p4, label: "Chr32 7420804"},
                            {y: g1p5, label: "Chr32 7420804"},
                            {y: g1p6, label: "Chr32 7420804"},
                            {y: g1p7, label: "Chr32 7420804"}
                        ]
                    }
                ]
            });
    chart.render();

    var chart2 = new CanvasJS.Chart("grafico2",
            {
                title: {
                    text: "Associação"
                },
                animationEnabled: true,
                axisY: {
                    title: "Total de diferenças"
                },
                legend: {
                    verticalAlign: "bottom",
                    horizontalAlign: "center"
                },
                theme: "theme2",
                data: [

                    {
                        type: "column",

                        dataPoints: [
                            {y: g2p1, label: "Chr27 5525002"},
                            {y: g2p2, label: "Chr27 5541113"},
                            {y: g2p3, label: "Chr27 5542806"},
                            {y: g2p4, label: "Chr27 5545082"},
                            {y: g2p5, label: "Chr27 5557298"},
                            {y: g2p6, label: "Chr27 5568947"}
                        ]
                    }
                ]
            });
    chart2.render();
}

function update_figura_1() {
    var chart = new CanvasJS.Chart("grafico1",
            {
                title: {
                    text: "Associação"
                },
                animationEnabled: true,
                axisY: {
                    title: "Total de diferenças"
                },
                legend: {
                    verticalAlign: "bottom",
                    horizontalAlign: "center"
                },
                theme: "theme2",
                data: [

                    {
                        type: "column",

                        dataPoints: [
                            {y: g1p1, label: "Chr32 7420804"},
                            {y: g1p2, label: "Chr32 7420804"},
                            {y: g1p3, label: "Chr32 7420804"},
                            {y: g1p4, label: "Chr32 7420804"},
                            {y: g1p5, label: "Chr32 7420804"},
                            {y: g1p6, label: "Chr32 7420804"},
                            {y: g1p7, label: "Chr32 7420804"}
                        ]
                    }
                ]
            });

    chart.render();
}

function update_figura_2() {
    var chart2 = new CanvasJS.Chart("grafico2",
            {
                title: {
                    text: "Associação"
                },
                animationEnabled: true,
                axisY: {
                    title: "Total de diferenças"
                },
                legend: {
                    verticalAlign: "bottom",
                    horizontalAlign: "center"
                },
                theme: "theme2",
                data: [

                    {
                        type: "column",

                        dataPoints: [
                            {y: g2p1, label: "Chr27 5525002"},
                            {y: g2p2, label: "Chr27 5541113"},
                            {y: g2p3, label: "Chr27 5542806"},
                            {y: g2p4, label: "Chr27 5545082"},
                            {y: g2p5, label: "Chr27 5557298"},
                            {y: g2p6, label: "Chr27 5568947"}
                        ]
                    }
                ]
            });
    chart2.render();
}

function ponto_3() {
    var entrada;

    entrada = "g1";
    if (document.getElementById(entrada).value.toUpperCase() == 'T') {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g2";
    if (parseInt(document.getElementById(entrada).value) == 3) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g3";
    if (parseInt(document.getElementById(entrada).value) == 12) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g4";
    if (parseInt(document.getElementById(entrada).value) == 9) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g5";
    if (document.getElementById(entrada).value.toUpperCase() == "G") {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g6";
    if (parseInt(document.getElementById(entrada).value) == 9) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g7";
    if (parseInt(document.getElementById(entrada).value) == 0) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g8";
    if (parseInt(document.getElementById(entrada).value) == 9) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    g1p3 = parseInt(document.getElementById("g9").value);
    if (g1p3 == 18) {
        document.getElementById("g9").style.backgroundColor = "lightgreen";
    } else {
        document.getElementById("g9").style.backgroundColor = "#F75D59";
    }
    update_figura_1();
}

function ponto_4() {
    var entrada;

    entrada = "g10";
    if (document.getElementById(entrada).value.toUpperCase() == 'T') {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g11";
    if (parseInt(document.getElementById(entrada).value) == 9) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g12";
    if (parseInt(document.getElementById(entrada).value) == 12) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g13";
    if (parseInt(document.getElementById(entrada).value) == 3) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g14";
    if (document.getElementById(entrada).value.toUpperCase() == "C") {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g15";
    if (parseInt(document.getElementById(entrada).value) == 3) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g16";
    if (parseInt(document.getElementById(entrada).value) == 0) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g17";
    if (parseInt(document.getElementById(entrada).value) == 3) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g18";
    g1p4 = parseInt(document.getElementById(entrada).value);
    if (g1p4 == 6) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }
    update_figura_1();
}

function ponto_5() {
    var entrada;

    entrada = "g19";
    if (document.getElementById(entrada).value.toUpperCase() == 'A') {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g20";
    if (parseInt(document.getElementById(entrada).value) == 5) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g21";
    if (parseInt(document.getElementById(entrada).value) == 0) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g22";
    if (parseInt(document.getElementById(entrada).value) == 5) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g23";
    if (document.getElementById(entrada).value.toUpperCase() == "G") {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g24";
    if (parseInt(document.getElementById(entrada).value) == 7) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g25";
    if (parseInt(document.getElementById(entrada).value) == 12) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g26";
    if (parseInt(document.getElementById(entrada).value) == 5) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g27";
    g1p5 = parseInt(document.getElementById(entrada).value);
    if (g1p5 == 10) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }
    update_figura_1();
}

function ponto_6() {
    var entrada;

    entrada = "g28";
    if (document.getElementById(entrada).value.toUpperCase() == 'T') {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g29";
    if (parseInt(document.getElementById(entrada).value) == 6) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g30";
    if (parseInt(document.getElementById(entrada).value) == 11) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g31";
    if (parseInt(document.getElementById(entrada).value) == 5) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g32";
    if (document.getElementById(entrada).value.toUpperCase() == "C") {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g33";
    if (parseInt(document.getElementById(entrada).value) == 6) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g34";
    if (parseInt(document.getElementById(entrada).value) == 1) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g35";
    if (parseInt(document.getElementById(entrada).value) == 5) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g36";
    g1p6 = parseInt(document.getElementById(entrada).value);
    if (g1p6 == 10) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }
    update_figura_1();
}

function ponto_7() {
    var entrada;

    entrada = "g37";
    if (document.getElementById(entrada).value.toUpperCase() == 'C') {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g38";
    if (parseInt(document.getElementById(entrada).value) == 3) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g39";
    if (parseInt(document.getElementById(entrada).value) == 1) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g40";
    if (parseInt(document.getElementById(entrada).value) == 2) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g41";
    if (document.getElementById(entrada).value.toUpperCase() == "G") {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g42";
    if (parseInt(document.getElementById(entrada).value) == 9) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g43";
    if (parseInt(document.getElementById(entrada).value) == 11) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g44";
    if (parseInt(document.getElementById(entrada).value) == 2) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "g45";
    g1p7 = parseInt(document.getElementById(entrada).value);
    if (g1p7 == 4) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }
    update_figura_1();
}

function ponto_8() {
    var entrada;

    entrada = "h1";
    if (document.getElementById(entrada).value.toUpperCase() == 'C') {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h2";
    if (parseInt(document.getElementById(entrada).value) == 4) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h3";
    if (parseInt(document.getElementById(entrada).value) == 5) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h4";
    if (parseInt(document.getElementById(entrada).value) == 1) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h5";
    if (document.getElementById(entrada).value.toUpperCase() == "T") {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h6";
    if (parseInt(document.getElementById(entrada).value) == 6) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h7";
    if (parseInt(document.getElementById(entrada).value) == 5) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h8";
    if (parseInt(document.getElementById(entrada).value) == 1) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h9";
    g2p1 = parseInt(document.getElementById(entrada).value);
    if (g2p1 == 2) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }
    update_figura_2();
}

function ponto_9() {
    var entrada;

    entrada = "h10";
    if (document.getElementById(entrada).value.toUpperCase() == 'C') {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h11";
    if (parseInt(document.getElementById(entrada).value) == 7) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h12";
    if (parseInt(document.getElementById(entrada).value) == 4) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h13";
    if (parseInt(document.getElementById(entrada).value) == 3) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h14";
    if (document.getElementById(entrada).value.toUpperCase() == "T") {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h15";
    if (parseInt(document.getElementById(entrada).value) == 3) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h16";
    if (parseInt(document.getElementById(entrada).value) == 6) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h17";
    if (parseInt(document.getElementById(entrada).value) == 3) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h18";
    g2p2 = parseInt(document.getElementById(entrada).value);
    if (g2p2 == 6) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }
    update_figura_2();
}

function ponto_10() {
    var entrada;

    entrada = "h19";
    if (document.getElementById(entrada).value.toUpperCase() == 'C') {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h20";
    if (parseInt(document.getElementById(entrada).value) == 4) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h21";
    if (parseInt(document.getElementById(entrada).value) == 10) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h22";
    if (parseInt(document.getElementById(entrada).value) == 6) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h23";
    if (document.getElementById(entrada).value.toUpperCase() == "T") {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h24";
    if (parseInt(document.getElementById(entrada).value) == 6) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h25";
    if (parseInt(document.getElementById(entrada).value) == 0) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h26";
    if (parseInt(document.getElementById(entrada).value) == 6) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h27";
    g2p3 = parseInt(document.getElementById(entrada).value);
    if (g2p3 == 12) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }
    update_figura_2();
}

function ponto_11() {
    var entrada;

    entrada = "h28";
    if (document.getElementById(entrada).value.toUpperCase() == 'A') {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h29";
    if (parseInt(document.getElementById(entrada).value) == 4) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h30";
    if (parseInt(document.getElementById(entrada).value) == 8) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h31";
    if (parseInt(document.getElementById(entrada).value) == 4) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h32";
    if (document.getElementById(entrada).value.toUpperCase() == "G") {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h33";
    if (parseInt(document.getElementById(entrada).value) == 6) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h34";
    if (parseInt(document.getElementById(entrada).value) == 2) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h35";
    if (parseInt(document.getElementById(entrada).value) == 4) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h36";
    g2p4 = parseInt(document.getElementById(entrada).value);
    if (g2p4 == 8) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }
    update_figura_2();
}

function ponto_12() {
    var entrada;

    entrada = "h37";
    if (document.getElementById(entrada).value.toUpperCase() == 'C') {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h38";
    if (parseInt(document.getElementById(entrada).value) == 4) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h39";
    if (parseInt(document.getElementById(entrada).value) == 2) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h40";
    if (parseInt(document.getElementById(entrada).value) == 2) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h41";
    if (document.getElementById(entrada).value.toUpperCase() == "T") {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h42";
    if (parseInt(document.getElementById(entrada).value) == 6) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h43";
    if (parseInt(document.getElementById(entrada).value) == 8) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h44";
    if (parseInt(document.getElementById(entrada).value) == 2) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h45";
    g2p5 = parseInt(document.getElementById(entrada).value);
    if (g2p5 == 4) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }
    update_figura_2();
}

function ponto_13() {
    var entrada;

    entrada = "h46";
    if (document.getElementById(entrada).value.toUpperCase() == 'C') {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h47";
    if (parseInt(document.getElementById(entrada).value) == 5) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h48";
    if (parseInt(document.getElementById(entrada).value) == 6) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h49";
    if (parseInt(document.getElementById(entrada).value) == 1) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h50";
    if (document.getElementById(entrada).value.toUpperCase() == "T") {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h51";
    if (parseInt(document.getElementById(entrada).value) == 5) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h52";
    if (parseInt(document.getElementById(entrada).value) == 4) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h53";
    if (parseInt(document.getElementById(entrada).value) == 1) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }

    entrada = "h54";
    g2p6 = parseInt(document.getElementById(entrada).value);
    if (g2p6 == 2) {
        document.getElementById(entrada).style.backgroundColor = "lightgreen";
    } else {
        document.getElementById(entrada).style.backgroundColor = "#F75D59";
    }
    update_figura_2();
}