<!DOCTYPE html>
<!--
Augusto C. A. Ribas
Programação web
-->

<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <title>Novo contato</title>
</head>
<body>
    <h1>Novo contato</h1>
    <form action="?op=cad" method="post">

        <p>
            <!--Sem required ou não entra no erro nunca. -->
            <label for="nome">Nome: </label>
            <input type="text" id="nome" name="nome"/>
        </p>

        <p>
            <label for="email">Email: </label>
            <input type="email" id="email" name="email" required/>
        </p>

        <p>

           <input type="submit" name="submit" value="Cadastrar"/>
       </p>

       <br/>

       <p>
        <a href="?op=index">Voltar</a>
    </p>

</form>
</body>
</html>
