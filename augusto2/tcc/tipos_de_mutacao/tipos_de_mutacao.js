/* 
 *
 */



var baseDNA = "ACGT";
var baseRNA = "UGCA";

var dicionarioRNA = {"A": "U", "C": "G", "G": "C", "T": "A"};

var dicionarioProteina = {"UUU": "Phe", "UUC": "Phe", "UUA": "Leu", "UUG": "Leu",
    "UCU": "Ser", "UCC": "Ser", "UCA": "Ser", "UCG": "Ser",
    "UAU": "Tyr", "UAC": "Tyr", "UAA": "Parada", "UAG": "Parada",
    "UGU": "Cys", "UGC": "Cys", "UGA": "Parada", "UGG": "Trp",
    "CUU": "Leu", "CUC": "Leu", "CUA": "Leu", "CUG": "Leu",
    "CCU": "Pro", "CCC": "Pro", "CCA": "Pro", "CCG": "Pro",
    "CAU": "His", "CAC": "His", "CAA": "Gln", "CAG": "Gln",
    "CGU": "Arg", "CGC": "Arg", "CGA": "Arg", "CGG": "Arg",
    "AUU": "Ile", "AUC": "Ile", "AUA": "Ile", "AUG": "Met",
    "ACU": "Thr", "ACC": "Thr", "ACA": "Thr", "ACG": "Thr",
    "AAU": "Asn", "AAC": "Asn", "AAA": "Lys", "AAG": "Lys",
    "AGU": "Ser", "AGC": "Ser", "AGA": "Arg", "AGG": "Arg",
    "GUU": "Val", "GUC": "Val", "GUA": "Val", "GUG": "Val",
    "GCU": "Ala", "GCC": "Ala", "GCA": "Ala", "GCG": "Ala",
    "GAU": "Asp", "GAC": "Asp", "GAA": "Glu", "GAG": "Glu",
    "GGU": "Gly", "GGC": "Gly", "GGA": "Gly", "GGG": "Gly"};

function retira_lixo(inString, stringBase) {
// Retira caracteres fora do alfabeto
    var tempString = inString.toUpperCase();
    var outString = "";
    for (var i = 0; i < tempString.length; i++) {
        if (stringBase.indexOf(tempString.charAt(i)) >= 0) {
            outString += tempString.charAt(i);
        }
    }
    return outString;
}



function transcricao(DNAsequence) {
// This is a single-letter transliteration function
// functions called: num2String(),string2Num()
// global variables used: baseDNA, baseRNA

    var i;
    var espaco = 0;
    var stringDNA = retira_lixo(DNAsequence, baseDNA);
    var stringRNA = "";		// String to be returned

    for (i = 0; i <= stringDNA.length - 1; i++) {
        stringRNA += dicionarioRNA[stringDNA[i]];
        espaco += 1;
        /*
        if (espaco % 3 == 0) {
            espaco = 0;
            stringRNA += ' ';
        }
        */
    }
    return stringRNA;
}



function traducao(RNAsequence) {
    var rnaString = retira_lixo(RNAsequence, baseRNA);
    var peptideString = ""		// string to be returned.

    var coDon = "123";	// Three nucleotide characters read from input string.
    // number of characters defines codon size; ALWAYS 3 characters long on planet Earth
    for (var i = 0; i <= rnaString.length - coDon.length; i = i + coDon.length) {
        coDon = rnaString.substring(i, i + coDon.length);
        peptideString += dicionarioProteina[coDon];
        /*peptideString += ' ';*/
    }
    return peptideString;
}

function formatTextArea(textArea, resposta) {
    var saida=1;

    for (var i = 0; i < textArea.value.length; i++) {  
        if(textArea.value[i] != resposta[i]){
            saida=0;
        }
    }
    
    if (saida==1 && textArea.value.length !=0) {
            textArea.style.backgroundColor = 'lightgreen';
        } else {
            textArea.style.backgroundColor = 'red';
        }
}



window.onload = function () {

    /*************************
     * Dominio Extracelular 1*
     **************************/
    
    //RNA Mc1r Selvagem (Pelos claros)
    var textt_0_0 = document.getElementById("RNADEIS");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "AACUCCACCCGCACAGGCGUUCCUCACCUC");
    };
    
    var textt_0_0 = document.getElementById("AMIDEIS");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "AsnSerThrArgThrGlyValProHisLeu");
    };

    //RNA Mc1r Mutante (Pelos escuros)
    var textt_0_0 = document.getElementById("RNADEIM");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "AACUCCACCUGCACAGGCGUUCCUCACCUC");
    };
    
    var textt_0_0 = document.getElementById("AMIDEIM");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "AsnSerThrCysThrGlyValProHisLeu");
    };

   
    /*************************
     * Domínio Estracelular III*
     **************************/

    //RNA Mc1r Selvagem (Pelos claros)
    var textt_0_0 = document.getElementById("RNADE3S");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "GCCCUGGCCACCCGGGUGACUGUGGUACAG");
    };
    
    var textt_0_0 = document.getElementById("AMIDE3S");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "AlaLeuAlaThrArgValThrValValGln");
    };

    //RNA Mc1r Mutante (Pelos escuros)
    var textt_0_0 = document.getElementById("RNADE3M");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "GCCCUGGCCACCUGGGUGACUGUGGUACAG");
    };
    
    var textt_0_0 = document.getElementById("AMIDE3M");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "AlaLeuAlaThrTrpValThrValValGln");
    };
    
     /*************************
     * Domínio Intracelullar I*
     **************************/
    
    //RNA Mc1r Selvagem (Pelos claros)
    var textt_0_0 = document.getElementById("RNADIIS");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "AGUAUUGUGACACUGCCCCGGGCUCGGUGG");
    };
    
    var textt_0_0 = document.getElementById("AMIDIIS");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "SerIleValThrLeuProArgAlaArgTrp");
    };

    //RNA Mc1r Mutante (Pelos escuros)
    var textt_0_0 = document.getElementById("RNADIIM");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "AGUAUUGUGACACUGCCCUGGGCUCGGUGG");
    };
    
    var textt_0_0 = document.getElementById("AMIDIIM");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "SerIleValThrLeuProTrpAlaArgTrp");
    };
    
    /*************************
     * Transmembrane V*
     **************************/
    
    //RNA Mc1r Selvagem (Pelos claros)
    var textt_0_0 = document.getElementById("RNATRA5S");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "GUGCACAUGCUUGCA");
    };
    
    var textt_0_0 = document.getElementById("AMITRA5S");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "ValHisMetLeuAla");
    };

    //RNA Mc1r Mutante (Pelos escuros)
    var textt_0_0 = document.getElementById("RNATRA5M");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "GUGCACAUGCUCGCA");
    };
    
    var textt_0_0 = document.getElementById("AMITRA5M");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "ValHisMetLeuAla");
    };
    
    /*************************
     * Domínio Intracelular III*
     **************************/
    
    //RNA Mc1r Selvagem (Pelos claros)
    var textt_0_0 = document.getElementById("RNADI3S");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "CUUGUCCACCAAGGUUUCCGACUCAAAGGC");
    };
    
    var textt_0_0 = document.getElementById("AMIDI3S");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "LeuValHisGlnGlyPheArgLeuLysGly");
    };

    //RNA Mc1r Mutante (Pelos escuros)
    var textt_0_0 = document.getElementById("RNADI3M");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "CUUGUCCACCACGGUUUCCGACUCAAAGGC");
    };
    
    var textt_0_0 = document.getElementById("AMIDI3M");
    textt_0_0.onkeyup = function (evt) {
        formatTextArea(this, "LeuValHisHisGlyPheArgLeuLysGly");
    };
    
};



function confere_pergunta01() {
    var x, text;

    // Pegando a resposta que está no input
    x = document.getElementById("pergunta01").value;

    // Se a entrada for null ou uma string vaziu, nenhuma resposta foi enviada,
    //senão dizemos se está correto ou não.
    if (isNaN(x) || x == "") {
        text = "Digite quantas mutações você encontrou, se não encontrou, digite 0";
    } else {
        if (x != 5) {
            text = 'Confira denovo, não é essa a resposta.';

        } else {
            text = "<b>Parabéns, você acertou!</b>";
        }
    }
    document.getElementById("resposta01").innerHTML = text;
}

function confere_pergunta02() {
    var a,b,c, text;

    // Pegando a resposta que está no input
    a = document.getElementById("pergunta02a").value;
    b = document.getElementById("pergunta02b").value;
    c = document.getElementById("pergunta02c").value;

    // Se a entrada for null ou uma string vaziu, nenhuma resposta foi enviada,
    //senão dizemos se está correto ou não.
    if (isNaN(a) || a == "" || isNaN(b) || b == "" || isNaN(c) || c == "") {
        text = "Digite quantas mutações você contou em cada caso, se não contou nenhum, digite 0";
    } else {
        if (a != 5 || b != 0 || c != 0) {
            text = 'Confira denovo, não é essa a resposta.';

        } else {
            text = "<b>Parabéns, você acertou!</b>";
        }
    }
    document.getElementById("resposta02").innerHTML = text;
}


function confere_pergunta03() {
    var a,b,c, text;

    // Pegando a resposta que está no input
    a = document.getElementById("pergunta03a").value;
    b = document.getElementById("pergunta03b").value;
    c = document.getElementById("pergunta03c").value;

    // Se a entrada for null ou uma string vaziu, nenhuma resposta foi enviada,
    //senão dizemos se está correto ou não.
    if (isNaN(a) || a == "" || isNaN(b) || b == "" || isNaN(c) || c == "") {
        text = "Digite quantas mutações você contou em cada caso, se não contou nenhum, digite 0";
    } else {
        if (a != 1 || b != 4 || c != 0) {
            text = 'Confira denovo, não é essa a resposta.';

        } else {
            text = "<b>Parabéns, você acertou!</b>";
        }
    }
    document.getElementById("resposta03").innerHTML = text;
}