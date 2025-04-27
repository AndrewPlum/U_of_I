<!DOCTYPE html>
<html>
<head>
    <title>User Input Page</title>
</head>
<body>

<h2>Submission ID to check:</h2>
<form method="post" action="">
    <input type="number" name="user_input" required>
    <button type="submit" name="submit">Submit</button>
</form>

<hr>

<?php
// Check if form is submitted
if (isset($_POST['submit'])) {
    // Retrieve and sanitize the user input
    $userInput = filter_input(INPUT_POST, 'user_input', FILTER_SANITIZE_NUMBER_INT);
    require_once 'algorithm.php';
    require_once 'main.php';
    // Execute code based on user input
    if ($userInput !== null) {
        mainfunct($userInput);

        // You can add more code based on different user input scenarios here...
    } else {
        echo "<p>Please enter a valid number.</p>";
    }
}
?>

</body>
</html>