<?php

function Sixteen_bit_to_list($set){
    $list = "";
    if($set & 0x0001) $list .= "A";
    if($set & 0x0002) $list .= "B";
    if($set & 0x0004) $list .= "C";
    if($set & 0x0008) $list .= "D";
    if($set & 0x0010) $list .= "E";
    if($set & 0x0020) $list .= "F";
    if($set & 0x0040) $list .= "G";
    if($set & 0x0080) $list .= "H";
    if($set & 0x0100) $list .= "I";
    if($set & 0x0200) $list .= "J";
    if($set & 0x0400) $list .= "K";
    if($set & 0x0800) $list .= "L";
    if($set & 0x1000) $list .= "M";
    if($set & 0x2000) $list .= "N";
    if($set & 0x4000) $list .= "O";
    if($set & 0x8000) $list .= "P";
    return $list;
}

// Given
function GivenCheck($fd_check, $fd_ref1){
    if($fd_check["leftside"] == $fd_ref1["leftside"] && $fd_check["rightside"] == $fd_ref1["rightside"]){
        return true;
    }
    else{
        return false;
    }
}

// Example usage:
$referenceFD1 = ["leftside" => 0b0001, "rightside" => 0b0010];  // Example: A -> B
$referenceFD2 = ["leftside" => 0b0010, "rightside" => 0b0100];  // Example: B -> C
$referenceFD3 = ["leftside" => 0b1000, "rightside" => 0b0010];  // Example: D -> C
$derivedFD1 = ["leftside" => 0b0001, "rightside" => 0b0010];   // Example: A -> B
$derivedFD2 = ["leftside" => 0b0100, "rightside" => 0b1000];   // Example: C -> D
$derivedFD3 = ["leftside" => 0b1000, "rightside" => 0b0100];   // Example: D -> C

$result1 = GivenCheck($derivedFD1, $referenceFD1);
$result2 = GivenCheck($derivedFD2, $referenceFD2);
$result3 = GivenCheck($derivedFD3, $referenceFD3);

echo "The givens:<br>";
echo "1) " . Sixteen_bit_to_list($referenceFD1["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD1["rightside"]) . "<br>";
echo "2) " . Sixteen_bit_to_list($referenceFD2["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD2["rightside"]) . "<br>";
echo "3) " . Sixteen_bit_to_list($referenceFD3["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD3["rightside"]) . "<br>";

echo "<br>";

echo "Student derivations:<br>";
echo "1) " . Sixteen_bit_to_list($derivedFD1["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD1["rightside"]) . "<br>";
echo "2) " . Sixteen_bit_to_list($derivedFD2["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD2["rightside"]) . "<br>";
echo "3) " . Sixteen_bit_to_list($derivedFD3["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD3["rightside"]) . "<br>";

echo "<br>";

echo "GivenCheck Results:<br>";

echo "Result 1: " . ($result1 ? "True" : "False") . "<br>";
echo "Result 2: " . ($result2 ? "True" : "False") . "<br>";
echo "Result 3: " . ($result3 ? "True" : "False") . "<br>";

echo "<br>";

// Reflexivity
function ReflexivityCheck($fd_check){
    return (($fd_check["leftside"] & $fd_check["rightside"]) == $fd_check["rightside"]);
}

// Example usage:
$fd1 = ["leftside" => 0b0001, "rightside" => 0b0001];  // Example: A -> A
$fd2 = ["leftside" => 0b0010, "rightside" => 0b0011];  // Example: B -> AB
$fd3 = ["leftside" => 0b0111, "rightside" => 0b0010];  // Example: ABC -> B

$result1 = ReflexivityCheck($fd1);
$result2 = ReflexivityCheck($fd2);
$result3 = ReflexivityCheck($fd3);

echo "Student derivations:<br>";
echo "1) " . Sixteen_bit_to_list($fd1["leftside"]) . " ---> " . Sixteen_bit_to_list($fd1["rightside"]) . "<br>";
echo "2) " . Sixteen_bit_to_list($fd2["leftside"]) . " ---> " . Sixteen_bit_to_list($fd2["rightside"]) . "<br>";
echo "3) " . Sixteen_bit_to_list($fd3["leftside"]) . " ---> " . Sixteen_bit_to_list($fd3["rightside"]) . "<br>";
echo "<br>";

echo "Reflexivity Results:<br>";

echo "Result 1: " . ($result1 ? "True" : "False") . "<br>";
echo "Result 2: " . ($result2 ? "True" : "False") . "<br>";
echo "Result 3: " . ($result3 ? "True" : "False") . "<br>";

echo "<br>";

// Transitivity 
function TransitivityCheck($fd_check, $fd_ref1, $fd_ref2) {
    if( 
        ($fd_ref1["rightside"] == $fd_ref2["leftside"] && $fd_ref1["leftside"] == $fd_check["leftside"] && $fd_ref2["rightside"] == $fd_check["rightside"]) ||
        ($fd_ref2["rightside"] == $fd_ref1["leftside"] && $fd_ref2["leftside"] == $fd_check["leftside"] && $fd_ref1["rightside"] == $fd_check["rightside"])
    ){
        return true;
    }
    return false;
}

// Example usage:
$referenceFD1 = ["leftside" => 0b0001, "rightside" => 0b0010];  // Example: A -> B
$referenceFD2 = ["leftside" => 0b0010, "rightside" => 0b0100];  // Example: B -> CD
$referenceFD3 = ["leftside" => 0b0001, "rightside" => 0b0011];  // Example: D -> E
$derivedFD1 = ["leftside" => 0b0001, "rightside" => 0b0011];   // Example: A -> AB
$derivedFD2 = ["leftside" => 0b0010, "rightside" => 0b0011];  // Example: B -> AB
$derivedFD3 = ["leftside" => 0b0010, "rightside" => 0b0011];  // Example: A -> AB

$result1 = TransitivityCheck($derivedFD1, $referenceFD1, $referenceFD2);
$result2 = TransitivityCheck($derivedFD2, $referenceFD1, $referenceFD3);
$result3 = TransitivityCheck($derivedFD3, $referenceFD1, $referenceFD2);

echo "The givens:<br>";
echo "1) " . Sixteen_bit_to_list($referenceFD1["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD1["rightside"]) . "<br>";
echo "2) " . Sixteen_bit_to_list($referenceFD2["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD2["rightside"]) . "<br>";
echo "3) " . Sixteen_bit_to_list($referenceFD3["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD3["rightside"]) . "<br>";

echo "<br>"; // Add a newline

echo "The derived functional dependencies:<br>";
echo "1) " . Sixteen_bit_to_list($derivedFD1["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD1["rightside"]) . "<br>";
echo "2) " . Sixteen_bit_to_list($derivedFD2["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD2["rightside"]) . "<br>";
echo "3) " . Sixteen_bit_to_list($derivedFD3["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD3["rightside"]) . "<br>";

echo "<br>";

echo "Transitivity Results:<br>";

echo "Result 1: " . ($result1 ? "True" : "False") . "<br>";
echo "Result 2: " . ($result2 ? "True" : "False") . "<br>";
echo "Result 3: " . ($result3 ? "True" : "False") . "<br>";

echo "<br>";

// Union
// Should union with a ref and itself be allowed

function UnionCheck($fd_check, $fd_ref1, $fd_ref2){
    if($fd_ref1["leftside"] == $fd_ref2["leftside"] && $fd_check["leftside"] == $fd_ref1["leftside"]){
        $union_fd_right_side = $fd_ref1["rightside"] | $fd_ref2["rightside"];
        return ($union_fd_right_side == $fd_check["rightside"]);
    }
    else{
        return false;
    }
}

// Example usage:
$referenceFD1 = ["leftside" => 0b0001, "rightside" =>  0b0010];  // Example: A -> B
$referenceFD2 = ["leftside" => 0b0001, "rightside" => 0b0100];  // Example: A -> C
$referenceFD3 = ["leftside" => 0b0001, "rightside" => 0b0110];  // Example: A -> BC
$referenceFD4 = ["leftside" => 0b0001, "rightside" => 0b1010];  // Example: A -> BD
$derivedFD1 = ["leftside" => 0b0001, "rightside" => 0b0110];   // Example: A -> BC
$derivedFD2 = ["leftside" => 0b0010, "rightside" => 0b0100];   // Example: B -> C
$derivedFD3 = ["leftside" => 0b0001, "rightside" => 0b1110];   // Example: A -> BCD

$result1 = UnionCheck($derivedFD1, $referenceFD1, $referenceFD2);
$result2 = UnionCheck($derivedFD3, $referenceFD3, $referenceFD4);
$result3 = UnionCheck($derivedFD3, $referenceFD1, $referenceFD2);

echo "The givens:<br>";
echo "1) " . Sixteen_bit_to_list($referenceFD1["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD1["rightside"]) . "<br>";
echo "2) " . Sixteen_bit_to_list($referenceFD2["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD2["rightside"]) . "<br>";
echo "3) " . Sixteen_bit_to_list($referenceFD3["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD3["rightside"]) . "<br>";
echo "4) " . Sixteen_bit_to_list($referenceFD4["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD4["rightside"]) . "<br>";

echo "<br>"; // Add a newline

echo "The derived functional dependencies:<br>";
echo "1) " . Sixteen_bit_to_list($derivedFD1["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD1["rightside"]) . "<br>";
echo "2) " . Sixteen_bit_to_list($derivedFD2["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD2["rightside"]) . "<br>";
echo "3) " . Sixteen_bit_to_list($derivedFD3["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD3["rightside"]) . "<br>";

echo "<br>"; // Add a newline

echo "Union Results:<br>";

echo "Result 1: " . ($result1 ? "True" : "False") . "<br>";
echo "Result 2: " . ($result2 ? "True" : "False") . "<br>";
echo "Result 3: " . ($result3 ? "True" : "False") . "<br>";

echo "<br>";

// Decomposition
function DecompositionCheck($fd_check, $fd_ref1){
    if($fd_check["leftside"] == $fd_ref1["leftside"] && $fd_check["rightside"] == ($fd_check["rightside"] & $fd_ref1["rightside"])){
        return true;
    } 
    else{
        return false;
    }
}

// Example usage:
$referenceFD1 = ["leftside" => 0b0001, "rightside" => 0b11111];  // Example: A -> ABCDE
$referenceFD2 = ["leftside" => 0b1101, "rightside" => 0b00010];  // Example: ACD -> B
$referenceFD3 = ["leftside" => 0b0011, "rightside" => 0b01100];  // Example: AB -> CD
$derivedFD1 = ["leftside" => 0b0001, "rightside" => 0b001011];   // Example: A -> ABD
$derivedFD2 = ["leftside" => 0b1101, "rightside" => 0b010010];   // Example: ACD -> BE
$derivedFD3 = ["leftside" => 0b0011, "rightside" => 0b000100];   // Example: AB -> C

$result1 = DecompositionCheck($derivedFD1, $referenceFD1);
$result2 = DecompositionCheck($derivedFD2, $referenceFD2);
$result3 = DecompositionCheck($derivedFD3, $referenceFD3);

echo "The givens:<br>";
echo "1) " . Sixteen_bit_to_list($referenceFD1["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD1["rightside"]) . "<br>";
echo "2) " . Sixteen_bit_to_list($referenceFD2["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD2["rightside"]) . "<br>";
echo "3) " . Sixteen_bit_to_list($referenceFD3["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD3["rightside"]) . "<br>";

echo "<br>";

echo "The derived functional dependencies:<br>";
echo "1) " . Sixteen_bit_to_list($derivedFD1["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD1["rightside"]) . "<br>";
echo "2) " . Sixteen_bit_to_list($derivedFD2["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD2["rightside"]) . "<br>";
echo "3) " . Sixteen_bit_to_list($derivedFD3["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD3["rightside"]) . "<br>";

echo "<br>";

echo "Decomposition Results:<br>";

echo "Result 1: " . ($result1 ? "True" : "False") . "<br>";
echo "Result 2: " . ($result2 ? "True" : "False") . "<br>";
echo "Result 3: " . ($result3 ? "True" : "False") . "<br>";

echo "<br>";

// Augmentation 
function AugmentationCheck($fd_check, $fd_ref1){
    $condition1 = (($fd_check["rightside"] & $fd_ref1["rightside"]) == $fd_ref1["rightside"]);
    $condition2 = (($fd_check["leftside"] & $fd_ref1["leftside"]) == $fd_ref1["leftside"]); 
    $difference = $fd_check["rightside"] ^ $fd_ref1["rightside"];
    $condition3 = (($fd_check["leftside"] & $difference) == $difference);
    
    return $condition1 && $condition2 && $condition3;
}

// Example usage:
$referenceFD1 = ["leftside" => 0b0001, "rightside" => 0b0010];  // Example: A -> B
$referenceFD2 = ["leftside" => 0b0001, "rightside" => 0b10000];  // Example: A -> E
$referenceFD3 = ["leftside" => 0b0001, "rightside" => 0b0100];  // Example: A -> C
$derivedFD1 = ["leftside" => 0b0001, "rightside" => 0b0011];   // Example: A -> AB
$derivedFD2 = ["leftside" => 0b1100, "rightside" => 0b11100]; // Example: CD -> CDE
$derivedFD3 = ["leftside" => 0b0011, "rightside" => 0b0110];   // Example: AB -> BC

$result1 = AugmentationCheck($derivedFD1, $referenceFD1);
$result2 = AugmentationCheck($derivedFD2, $referenceFD2);
$result3 = AugmentationCheck($derivedFD3, $referenceFD3);

echo "The givens:<br>";
echo "1) " . Sixteen_bit_to_list($referenceFD1["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD1["rightside"]) . "<br>";
echo "2) " . Sixteen_bit_to_list($referenceFD2["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD2["rightside"]) . "<br>";
echo "3) " . Sixteen_bit_to_list($referenceFD3["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD3["rightside"]) . "<br>";
echo "4) " . Sixteen_bit_to_list($referenceFD4["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD4["rightside"]) . "<br>";

echo "<br>";

echo "The derived functional dependencies:<br>";
echo "1) " . Sixteen_bit_to_list($derivedFD1["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD1["rightside"]) . "<br>";
echo "2) " . Sixteen_bit_to_list($derivedFD2["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD2["rightside"]) . "<br>";
echo "3) " . Sixteen_bit_to_list($derivedFD3["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD3["rightside"]) . "<br>";

echo "<br>";

echo "Augmentation Results:<br>";

echo "Result 1: " . ($result1 ? "True" : "False") . "<br>";
echo "Result 2: " . ($result2 ? "True" : "False") . "<br>";
echo "Result 3: " . ($result3 ? "True" : "False") . "<br>";

echo "<br>";

// Pseudo Transitivity
function PseudoTransitivityCheck($fd_check, $fd_ref1, $fd_ref2){     
    $condition1 = (($fd_ref2["leftside"] & $fd_ref1["rightside"]) == $fd_ref1["rightside"]);
    $condition2 = ($fd_check["leftside"] == ($fd_ref1["leftside"] | ($fd_ref1["rightside"] ^ $fd_ref2["leftside"])));
    $condition3 = ($fd_check["rightside"] == $fd_ref2["rightside"]);
    
    $condition4 = (($fd_ref1["leftside"] & $fd_ref2["rightside"]) == $fd_ref2["rightside"]);
    $condition5 = ($fd_check["leftside"] == ($fd_ref2["leftside"] | ($fd_ref2["rightside"] ^ $fd_ref1["leftside"])));
    $condition6 = ($fd_check["rightside"] == $fd_ref1["rightside"]);
    
    return ($condition1 && $condition2 && $condition3) || ($condition4 && $condition5 && $condition6);     
}

// Example usage:
$referenceFD1 = ["leftside" => 0b0001, "rightside" => 0b0010];  // Example: A -> B
$referenceFD2 = ["leftside" => 0b0010, "rightside" => 0b0100];  // Example: B -> C
$referenceFD3 = ["leftside" => 0b0001, "rightside" => 0b0100];  // Example: A -> C
$derivedFD1 = ["leftside" => 0b0001, "rightside" => 0b0100];   // Example: A -> C
$derivedFD2 = ["leftside" => 0b0100, "rightside" => 0b1000];   // Example: C -> D
$derivedFD3 = ["leftside" => 0b0001, "rightside" => 0b1000];   // Example: A -> D


$result1 = PseudoTransitivityCheck($derivedFD1, $referenceFD1, $referenceFD2);
$result2 = PseudoTransitivityCheck($derivedFD2, $referenceFD2, $referenceFD3);
$result3 = PseudoTransitivityCheck($derivedFD3, $referenceFD1, $referenceFD2);

echo "The givens:<br>";
echo "1) " . Sixteen_bit_to_list($referenceFD1["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD1["rightside"]) . "<br>";
echo "2) " . Sixteen_bit_to_list($referenceFD2["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD2["rightside"]) . "<br>";
echo "3) " . Sixteen_bit_to_list($referenceFD3["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD3["rightside"]) . "<br>";
echo "4) " . Sixteen_bit_to_list($referenceFD4["leftside"]) . " ---> " . Sixteen_bit_to_list($referenceFD4["rightside"]) . "<br>";

echo "<br>";

echo "The derived functional dependencies:<br>";
echo "1) " . Sixteen_bit_to_list($derivedFD1["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD1["rightside"]) . "<br>";
echo "2) " . Sixteen_bit_to_list($derivedFD2["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD2["rightside"]) . "<br>";
echo "3) " . Sixteen_bit_to_list($derivedFD3["leftside"]) . " ---> " . Sixteen_bit_to_list($derivedFD3["rightside"]) . "<br>";

echo "<br>";

echo "Pseudo-Transitivity Results:<br>";

echo "Result 1: " . ($result1 ? "True" : "False") . "<br>";
echo "Result 2: " . ($result2 ? "True" : "False") . "<br>";
echo "Result 3: " . ($result3 ? "True" : "False") . "<br>";

echo "<br>";

?>