<?php
include('menu.php'); // includes the menu bar
// Include auth_session.php file on all user panel pages
include("auth_session.php");
require('db.php'); // required to interact with the database
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Dashboard - Client area</title>
    <link rel="stylesheet" href="style.css" />
</head>
<body>
    <div class="form">
        <p>Hey, <?php echo $_SESSION['username']; ?>!</p>
        <p>You are in user dashboard page.</p>
        <h2>User Table</h2>
        <table border="1">
            <tr>
                <th>ID</th>
                <th>First Name</th>
                <th>Last Name</th>
                <th>Username</th>
                <th>Email</th>
                <th>Action</th>
            </tr>
            <?php
            $logged_in_user_id = $_SESSION["id"]; // get the ID of the logged-in user
            $sql = "SELECT * FROM users";
            $result = $con->query($sql);
            if ($result->num_rows > 0) {
                while ($col = $result->fetch_assoc()) {
                    echo "<tr>";
                    echo "<td>" . $col["id"] . "</td>";
                    echo "<td>" . $col["first_name"] . "</td>";
                    echo "<td>" . $col["last_name"] . "</td>";
                    echo "<td>" . $col["username"] . "</td>";
                    echo "<td>" . $col["email"] . "</td>";
                    // check for delete submission
                    if (isset($_POST['delete_id'])) {
                        $delete_id = $_POST['delete_id'];
                        // delete specific row
                        $sql_delete = "DELETE FROM users WHERE id = $delete_id";
                        if ($con->query($sql_delete) === TRUE) {
                            // delete success
                            header("Location: dashboard.php"); // Redirect to refresh the page
                        } else {
                            echo "Error deleting record: " . $con->error;
                        }
                    }
                    if ($col["id"] != $logged_in_user_id) {
                        echo '<td>
                            <form method="post" action="">
                                <input type="hidden" name="delete_id" value="' . $col["id"] . '">
                                <input type="submit" value="Delete">
                            </form>
                        </td>';
                    }else{
                        // Display a message or placeholder in the "Action" column
                        echo '<td>Self</td>';
                    }
                    echo "</tr>";
                }
            } else {
                echo "No users found.";
            }
            // Close the database connection
            $con->close();
            ?>
        </table>
        <p><a href="registration.php">Register Another User</a></p>
        <p><a href="logout.php">Logout</a></p>
    </div>
</body>
</html>
