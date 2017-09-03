<?php

require("db_info.php");

function parseToXML($htmlStr) {
    $xmlStr = str_replace('<', '&lt;', $htmlStr);
    $xmlStr = str_replace('>', '&gt;', $xmlStr);
    $xmlStr = str_replace('"', '&quot;', $xmlStr);
    $xmlStr = str_replace("'", '&apos;', $xmlStr);
    $xmlStr = str_replace("&", '&amp;', $xmlStr);
    return $xmlStr;
}

// Abre uma coneção com o banco
$connection = mysql_connect(localhost, $username, $password);
if (!$connection) {
    die('Not connected : ' . mysql_error());
}

// Seleciona o o banco de dados
$db_selected = mysql_select_db($database, $connection);
if (!$db_selected) {
    die('Can\'t use db : ' . mysql_error());
}

// Faz a query para gerar as informações de interesse
$query = "SELECT strain_name,country,source_avaliable_from,latitude,longitude FROM strain WHERE 1";
$result = mysql_query($query);
if (!$result) {
    die('Invalid query: ' . mysql_error());
}

header("Content-type: text/xml");

// Começa o arquivo xml
echo '<markers>';

// Faz um loop nas linhas, gerando um node por linha
while ($row = @mysql_fetch_assoc($result)) {
    // Adiciona a linha organizada ao arquivo
    echo '<marker ';
    echo 'strain="' . parseToXML($row['strain_name']) . '" ';
    echo 'country="' . parseToXML($row['country']) . '" ';
    echo 'origin="' . parseToXML($row['source_avaliable_from']) . '" ';
    echo 'lat="' . $row['latitude'] . '" ';
    echo 'lng="' . $row['longitude'] . '" ';
    echo '/>';
}

// Encerra o xml
echo '</markers>';
?>

