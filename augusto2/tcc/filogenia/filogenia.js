function allowDrop(ev) {
    ev.preventDefault();
}

function drag(ev) {
    ev.dataTransfer.setData("Text", ev.target.id);
}

function drop(ev) {
    var data = ev.dataTransfer.getData("Text");
    ev.target.appendChild(document.getElementById(data));
    ev.preventDefault();
}

function arvore_caracteres() {
    var elements;

    elements = [
        document.getElementById("A_alutaceus1").value, 
        document.getElementById("A_alutaceus2").value,
        document.getElementById("A_alutaceus3").value,
        document.getElementById("A_alutaceus4").value,
        document.getElementById("A_alutaceus5").value,
        document.getElementById("A_angusticeps1").value, 
        document.getElementById("A_angusticeps2").value,
        document.getElementById("A_angusticeps3").value,
        document.getElementById("A_angusticeps4").value,
        document.getElementById("A_angusticeps5").value,
        document.getElementById("A_chlorocyanus1").value, 
        document.getElementById("A_chlorocyanus2").value,
        document.getElementById("A_chlorocyanus3").value,
        document.getElementById("A_chlorocyanus4").value,
        document.getElementById("A_chlorocyanus5").value,
        document.getElementById("A_cristatellus1").value, 
        document.getElementById("A_cristatellus2").value,
        document.getElementById("A_cristatellus3").value,
        document.getElementById("A_cristatellus4").value,
        document.getElementById("A_cristatellus5").value,
        document.getElementById("A_cybotes1").value, 
        document.getElementById("A_cybotes2").value,
        document.getElementById("A_cybotes3").value,
        document.getElementById("A_cybotes4").value,
        document.getElementById("A_cybotes5").value,
        document.getElementById("A_grahami1").value, 
        document.getElementById("A_grahami2").value,
        document.getElementById("A_grahami3").value,
        document.getElementById("A_grahami4").value,
        document.getElementById("A_grahami5").value,
        document.getElementById("A_lineatopus1").value, 
        document.getElementById("A_lineatopus2").value,
        document.getElementById("A_lineatopus3").value,
        document.getElementById("A_lineatopus4").value,
        document.getElementById("A_lineatopus5").value,
        document.getElementById("A_occultus1").value, 
        document.getElementById("A_occultus2").value,
        document.getElementById("A_occultus3").value,
        document.getElementById("A_occultus4").value,
        document.getElementById("A_occultus5").value,
        document.getElementById("A_olssoni1").value, 
        document.getElementById("A_olssoni2").value,
        document.getElementById("A_olssoni3").value,
        document.getElementById("A_olssoni4").value,
        document.getElementById("A_olssoni5").value,
        document.getElementById("A_ophiolepis1").value, 
        document.getElementById("A_ophiolepis2").value,
        document.getElementById("A_ophiolepis3").value,
        document.getElementById("A_ophiolepis4").value,
        document.getElementById("A_ophiolepis5").value,
        document.getElementById("A_porcatus1").value, 
        document.getElementById("A_porcatus2").value,
        document.getElementById("A_porcatus3").value,
        document.getElementById("A_porcatus4").value,
        document.getElementById("A_porcatus5").value,
        document.getElementById("A_pulchellus1").value, 
        document.getElementById("A_pulchellus2").value,
        document.getElementById("A_pulchellus3").value,
        document.getElementById("A_pulchellus4").value,
        document.getElementById("A_pulchellus5").value,
        document.getElementById("A_sagrei1").value, 
        document.getElementById("A_sagrei2").value,
        document.getElementById("A_sagrei3").value,
        document.getElementById("A_sagrei4").value,
        document.getElementById("A_sagrei5").value,
        document.getElementById("A_shelpani1").value, 
        document.getElementById("A_shelpani2").value,
        document.getElementById("A_shelpani3").value,
        document.getElementById("A_shelpani4").value,
        document.getElementById("A_shelpani5").value,
        document.getElementById("A_valencienni1").value, 
        document.getElementById("A_valencienni2").value,
        document.getElementById("A_valencienni3").value,
        document.getElementById("A_valencienni4").value,
        document.getElementById("A_valencienni5").value    
    ].join(',');
    $.post('http://localhost/augusto/tcc/filogenia/pars.php', {elements: elements});


    $.get('http://localhost/augusto/tcc/filogenia/pars_saida.txt', function (data) {
        alert(data);
    });





    document.getElementById("teste_caracter").innerHTML = "foi";
}