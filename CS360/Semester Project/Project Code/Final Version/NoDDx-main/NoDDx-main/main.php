<?php
function mainfunc(){
    require_once 'algorithm.php';

    $host = "localhost";
    $username = "root";
    $password = "";
    $database = "noddx";

    $conn = new mysqli($host, $username, $password, $database);
    if ($conn->connect_error)die("Connection failed: " . $conn->connect_error);

    // Fetch all submissions from the submissions table
    $sql = "SELECT * FROM submissions";
    if (!($subs = $conn->query($sql))) die("Query failed: " . $conn->error);
    while ($submission = $subs->fetch_assoc()){
        echo '<hr>';
        $sid = $submission['id'];
        $qid = $submission['question_id'];

        $sql = "SELECT * FROM questions WHERE id = $qid";
        if(!($result = $conn->query($sql))) die("Query failed: " . $conn->error);
        $question = $result->fetch_assoc();

        $qtype = $question["type"];
        if($qtype == 1 || $qtype == 2){
            $qentries = array();
            $sql = "SELECT * FROM qentries WHERE question_id = $qid";
            if(!($result = $conn->query($sql))) die("Query failed: " . $conn->error);
            while ($row = $result->fetch_assoc()) $qentries[$row["numline"]] = new Entry1($row);

            $entries = array();
            if($qtype == 1) $entrytable = "entries01";
            if($qtype == 2) $entrytable = "entries02";
            $sql = "SELECT * FROM $entrytable WHERE submission_id = $sid";
            if(!($result = $conn->query($sql))) die("Query failed: " . $conn->error);

            while($row = $result->fetch_assoc()){
                if($qtype == 1) $entries[$row["numline"]] = new Entry1($row);
                if($qtype == 2) $entries[$row["numline"]] = new Entry2($row);
            }
            ?>
            <h2><?php echo 'Question#' . $qid; ?></h2>
            <p><?php echo $question["name"]; ?></p>
            <h3><?php echo "Submission#" . $sid; ?></h3>
            <table border="1">
                <tr>
                    <th>#</th>
                    <th>Entry</th>
                    <th>Justification</th>
                    <th>Valid?</th>
                </tr>
            <?php 
            for($i = 1; $i <= count($qentries); $i++): ?>
                <tr>
                    <td><?php echo $i; ?></td>
                    <td><?php echo GetSetString($qentries[$i]->left) . '&#x27F6;' . GetSetString($qentries[$i]->right); ?></td>
                    <td>Given</td>
                    <td></td>
                </tr>
            <?php endfor; ?>
                <tr style="font-weight: bold;">
                    <td colspan="4" style ="text-align: center;">Student entries</td>
                </tr>
            <?php
            if($qtype == 1){
                unset($lastrow);
                $feedback = -1;
                for($i=1; $i <= count($entries); $i++):
                    $row = $entries[$i];
                    if(!isset($lastrow) || $lastrow->numline < $i) $lastrow = $row;
                    $a = ($feedback = LogicalStep($i, $entries, $qentries)) ? "&#x2717" : "&#x2713;"; //if ($feedback!=0) ? $a=xmark, else: checkmark.
                    ?>
                    <tr>
                        <td><?php echo $i + count($qentries); ?></td>
                        <td><?php echo GetSetString($row->left) . '&#x27F6;' . GetSetString($row->right); ?></td>
                        <td><?php echo GetRuleString($row->rule) . " " . implode(", ",$row->refs); ?></td>
                        <td><?php echo $a; ?></td>
                    </tr>
                    <?php 
                    if($feedback) break;
                endfor;
                echo '</table>';
                $qfinal = new Entry1(array("sideleft" => $question["data1"], "sideright" => $question["data2"]));
                if($feedback == 0) $feedback = GivenCheck($lastrow, $qfinal) ? 0 : 4;
                printfb($feedback);
            }elseif($qtype == 2){
                unset($lastrow);
                $feedback = -1;
                $previouslist = $question["data1"];
                for($i = 1; $i <= count($entries); $i++){
                    $row = $entries[$i];
                    if(!isset($lastrow) || $lastrow->numline < $i) $lastrow = $row;
                    $a = ($feedback = ClosureStep($row, $qentries, $previouslist)) ? "&#x2717" : "&#x2713;";
                    ?>
                    <tr>
                        <td></td>
                        <td><?php echo '{' . GetSetString($question["data1"]) . '}+ = {' . GetSetString($row->list) .'}'; ?></td>
                        <td><?php echo GetRuleString($row->rule) . " " . implode(", ",$row->refs); ?></td>
                        <td><?php echo $a; ?></td>
                    </tr>
                    <?php
                    if($feedback) break;
                }
                echo '</table>';
                if($feedback == 0) $feedback = $lastrow->list == AttributeClosure($question["data1"], $qentries) ? 0 : 4;
                printfb($feedback);
            }else{
                echo "<br>unimplemented question type.";
            }
        }

    }
    $conn->close();
}

function printfb($feedback){
    echo "<h3>Result:</h3>";
    switch($feedback){
        case -1:
            echo "No entries provided with this submission.";
            return -1;
        case 0:
            echo "Correct!";
            return 0;
        case 1:
            echo "Incorrect. There's a problem with the logic.";
            return 1;
        case 2:
            echo "Incorrect. There's a problem with the submission format.";
            return 2;
        case 3:
            echo "error sanityfail.";
            return 3;
        case 4:
            echo "Incorrect. The answer is incomplete.";
            return 4;
        default:
            echo "error, (feedback=$feedback).";
            die;
    }
}
?>