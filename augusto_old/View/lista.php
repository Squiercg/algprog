<!DOCTYPE html>
<!--
Augusto C. A. Ribas
Programação Web
-->
<html>
<head>
    <meta charset="UTF-8">
    <title>Lista</title>
</head>
<body>
    <h1>Lista de contatos</h1>
    <table>
        <thead>
            <tr>
                <th>Nome</th> <th>Email</th>
            </tr>
        </thead>
        <tbody>
            <?php
            require_once 'Model/Contato.php';
            foreach ($result as $value) {
                echo '<tr> <td>' . $value->getNome() .  '</td>';
                echo '<td>' .  $value->getEmail() . '</td></tr>';
            }
            ?>
        </tbody>
    </table>
    <br/>
    <p>
        <a href="?op=index">Voltar</a>
    </p>
</body>
</html>

