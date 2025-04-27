<?php

require_once 'algorithm.php';

// Attribute Closure Checking Algorithm

/*
// L1 > ((R1 & L2) ^ L2)
// RX =: R1 | R2 | L1
function logic_cons($ref1, $ref2){
    if($ref1["sideleft"] == (($ref1["sideright"] & $ref2["sideleft"]) ^ $ref2["sideleft"] | $ref1["sideleft"])){
        $new_right = ($ref1["sideleft"] | $ref1["sideright"] | $ref2["sideright"]);
        return $new_right;
    }
    else return ($ref1["sideleft"] | $ref1["sideright"]);
}

$qtype=2;
$qid;
$sid;

$qentries;
$entries;//(from entries02)

$bignum = 0;
foreach($entries as $row){
    if($row["numline"] > $bignum){
        $lastrow = $row;
    }
}
unset($row);

$current;//da given
do{
    $old = $current;
    foreach($qentries as $row){
        $current =
        
    }

}

*/


function AttributeClosureCheck($total_attr_rows, $fdarray, $attr_array, $init_attr){
    // have initial check to make sure everything in prove is in acceptable form
        // first row check
            // should be checking if the attributes in attribute closure match 
            // the attributes checked in the the first row 
            // the justification used should be Given
        // check if every row after the first has only 1 reference FD
    // second row onward check
    
    //$total_rows = count($attr_closure_table); // still need to assign total rows in the proof
    for($i = 1; $i < $total_attr_rows; $i++){
        $prev_attr;//$attr_array[i - 1]["checked_attr"]; // still need to assign
        $curr_attr;//$attr_array[i]["checked_attr"]; // still need to assign
    
        $common_attr = $curr_attr & $prev_attr;
        $diff_attr = $curr_attr ^ $prev_attr;
    
        if($common_attr & $fd_ref["sideleft"] == $fd_ref["sideleft"]){
            if($diff_attr == $fd_ref["sideright"]){
                break; // want to break out of both ifs continue on in the for loop without returning
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    
    // check if final answer at the end of the proof is the correct answer

    $condition = true;
    $prev_attr = $init_attr;
    $curr_attr = $init_attr;
    $next_attr = $init_attr;
    
    while(condition){
        $prev_attr = $curr_attr;
        for($i = 0; $i < count($fdarray); $i++){
            /*
            // could compare by decrement or by subset
            // this is by decrement
            for($j = 0; $j < ; $j){
                $curr = $curr - 1;
                if($curr_attr == $fdarray[i]["sideleft"]){
                
                }
            }
            */
            // this is by subset
            if(($curr_attr & $fdarray[i]["sideleft"]) == $fdarray[i]["sideleft"]){
                $next_attr = $fdarray[i]["sideright"] | $next_attr;
            }
        }
        $curr_attr = $next_attr;
        $condition = $curr_attr != $prev_attr;
    }
    
    if($curr_attr != $attr_array[$total_attr_rows - 1]){ // $total_attr_rows - 1 should be the final row, -1 because attr_array indexed at 0
        return false; 
    }
    
    // retrun true if you haven't yet returned false
    
    return true; 
}



/*
$fd1 = array(
    "sideleft" => array("A"),
    "sideright" => array("B"),
    "justification" => Rule::Given,
    "basis" => array(1)
);

$fd2 = array(
    "sideleft" => array("B"),
    "sideright" => array("C"),
    "justification" => Rule::Reflexivity,
    "basis" => array()
);

$fd3 = array(
    "sideleft" => array("B", "C"),
    "sideright" => array("AD"),
    "justification" => Rule::Transitivity,
    "basis" => array(1,2)
);

$fd4 = array(
    "sideleft" => array("BCD"),
    "sideright" => array("E"),
    "justification" => Rule::Union,
    "basis" => array(1,2)
);

$fd5 = array(
    "sideleft" => array("AB"),
    "sideright" => array("F"),
    "justification" => Rule::Decomposition,
    "basis" => array(2)
);

$fdarray_initial = array(
    $fd1,
    $fd2,
    $fd3,
    $fd4,
    $fd5
);

$fdarray = array(
    $fd1,
    $fd2,
    $fd3,
    $fd4,
    $fd5
);
*/

//print_r($fdarray);

/*
print_r($fd1);
echo "<br>";
echo "<br>";
print_r($fd2);
echo "<br>";
echo "<br>";
print_r($fd3);
echo "<br>";
echo "<br>";
print_r($fd4);
echo "<br>";
echo "<br>";
print_r($fd5);
//*/

/*
$array = [1, "two", 3.14, true, ["apple", "banana"]];

foreach ($array as $element) {
    if (is_int($element)) {
        echo "$element is an integer.<br>";
    } elseif (is_string($element)) {
        echo "$element is a string.<br>";
    } elseif (is_float($element)) {
        echo "$element is a float.<br>";
    } elseif (is_bool($element)) {
        echo "$element is a boolean.<br>";
    } elseif (is_array($element)) {
        echo "An array is found.<br>";
    } else {
        echo "Unknown data type for $element.<br>";
    }
}
*/ 

>