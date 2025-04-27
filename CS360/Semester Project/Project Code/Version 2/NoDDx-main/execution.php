<!DOCTYPE html>
<html>
<head>
    <title>PHP Exectuion Page</title>
</head>
<body>

<form method="post" action="">
    <button type="submit" name="submit">Submit</button>
</form>

<?php
if (isset($_POST['submit'])) {
    require_once 'algorithm.php';
    require_once 'main.php';
    mainfunc();
}
?>

</body>
</html>

