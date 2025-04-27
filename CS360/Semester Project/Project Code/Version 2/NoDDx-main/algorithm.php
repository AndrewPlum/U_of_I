<?php
// convert a (int) binary set of up to 16 object to a (string) list of up to 16 letters
class Entry1{
    public int $left;
    public int $right;
    public $numline;
    public $rule;
    public $refs;

    function __construct($entry){
        $this->left = ($entry["sideleft"] ?? 0);
        $this->right = ($entry["sideright"] ?? 0);
        $this->numline = ($entry["numline"] ?? 0);
        $this->rule = ($entry["rule"] ?? -1);
        $this->refs = ReadRefs($entry["refs"] ?? "");
    }
}

class Entry2{
    public int $list;
    public $numline;
    public $rule;
    public $refs;

    function __construct($entry){
        $this->list = ($entry["list"] ?? 0);
        $this->numline = ($entry["numline"] ?? 0);
        $this->rule = ($entry["rule"] ?? -1);
        $this->refs = ReadRefs($entry["refs"] ?? "");
    }
}

function GetSetString($set){
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

function GetRuleString($rule) {
    switch ($rule) {
        case 0: return "Given";
        case 1: return "Reflexivity";
        case 2: return "Transitivity";
        case 3: return "Augmentation";
        case 4: return "Union";
        case 5: return "Decomposition";
        case 6: return "PseudoTransitivity";
        case -1: return "";
        default: return "Invalid Rule";
    }
}

//parse a comma separated list of basis references:
function ReadRefs($list){
    $arr = [];
    if(!empty($list)){
        $i = 0;
        $item = "";
        do{
            if($i == strlen($list) || $list[$i] == ','){
                if(is_numeric($item)){
                    $arr[] = (int)$item;
                    $item = "";
                }else{
                    $item = "";
                    trigger_error("ignored non-numberic reference");
                }
            }else{
                $item .= $list[$i];
            }
        }while($i++ < strlen($list));
    }
    return $arr;
}

function GivenCheck($fd, $ref1){
    return $fd->left == $ref1->left && $fd->right == $ref1->right;
}

function ReflexivityCheck($fd){
    return $fd->right == ($fd->right & $fd->left);
}

function TransitivityCheck($fd, $ref1, $ref2) {
    $forward = $fd->left == $ref1->left && $ref2->left == $ref1->right && $ref2->right == $fd->right;
    $reverse = $fd->left == $ref2->left && $ref1->left == $ref2->right && $ref1->right == $fd->right;
    return $forward || $reverse;
}

function UnionCheck($fd, $ref1, $ref2){
    $left_equal = $fd->left == $ref1->left && $ref1->left == $ref2->left;
    $right_union = $fd->right == ($ref1->right | $ref2->right);
    return $left_equal && $right_union;
}

function DecompositionCheck($fd, $ref1){
    $left_equal = $fd->left == $ref1->left;
    $right_subset = $fd->right == ($fd->right & $ref1->right);
    return $left_equal && $right_subset;
}

function AugmentationCheck($fd, $ref1){
    $r1_subeq_rx = $ref1->right == ($ref1->right & $fd->right);
    $l1_subeq_lx = $ref1->left == ($ref1->left & $fd->left); 
    $difference = $fd->right ^ $ref1->right;
    $diff_subeq_lx = $difference == ($difference & $fd->left);
    return $r1_subeq_rx && $l1_subeq_lx && $diff_subeq_lx;
}

function PseudoTransitivityCheck($fd, $ref1, $ref2){ 
    $condition1a = $ref1->right == ($ref1->right & $ref2->left);
    $condition2a = $fd->left == ($ref1->right ^ $ref2->left | $ref1->left);
    $condition3a = $fd->right == $ref2->right;
    
    $condition1b = $ref2->right == ($ref2->right & $ref1->left);
    $condition2b = $fd->left == ($ref2->right ^ $ref1->left | $ref2->left);
    $condition3b = $fd->right == $ref1->right;
    return $condition1a && $condition2a && $condition3a || $condition1b && $condition2b && $condition3b;     
}

/* Generalized Logical Consequences (Given LR1,LR2,LX, maximize RX)
    LX > L1 | ((R1 & L2) ^ L2)
    RX < R1 | R2 | LX

    function logical(L1, R1, L2, R2, LX, RX)
    return (((L2 ^ (R1 & L2) | L1) == (LX & (L2 ^ (R1 & L2) | L1)) 
    || (L1 ^ (R2 & L1) | L2) == (LX & L1 ^ (R2 & L1) | L2)) 
    && RX == (RX & (R1 | R2 | LX)))

    function logical($fd, $ref1, $ref2){
        $L1_plus_L2_less_R1 = $ref1->right & $ref2->left ^ $ref2->left | $ref1->left;
        $L2_plus_L1_less_R2 = $ref2->right & $ref1->left ^ $ref1->left | $ref2->left;

        $LX_superset_a = $L1_plus_L2_less_R1 == ($L1_plus_L2_less_R1 & $fd->left);
        $LX_superset_b = $L2_plus_L1_less_R2 == ($L2_plus_L1_less_R2 & $fd->left);

        $RX_subset = $fd->right == ($fd->right & ($ref1->right | $ref2->right | $fd->left));
        return ($LX_superset_a || $LX_superset_b) && $RX_subset;
    }
*/

function LogicalStep($i, $user_entries, $question_entries){ // 0 = user success, 1 = user check fail, 2 = user format fail, 3 = sanityfail
    $row = $user_entries[$i];
    $refcount = count($row->refs);
    if($n = $row->refs[0] ?? false){
        if($n > $row->numline + count($question_entries)) return 3;
        $ref1 = $n <= count($question_entries) ? $question_entries[$n] : $user_entries[$n-count($question_entries)];
    }
    if($n = $row->refs[1] ?? false){
        if($n > $row->numline + count($question_entries)) return 3;
        $ref2 = $n <= count($question_entries) ? $question_entries[$n] : $user_entries[$n-count($question_entries)];
    }
    
    switch ($row->rule){
        /*
            case Given = 0;
            case Reflexivity = 1;
            case Transitivity = 2;
            case Augmentation = 3;
            case Union = 4;
            case Decomposition = 5;
            case PseudoTransitivity = 6;
        */
        case 0: return $refcount == 1 ? (GivenCheck($row, $ref1) ? 0 : 1) : 2;
        case 1: return $refcount == 0 ? (ReflexivityCheck($row) ? 0 : 1) : 2;
        case 2: return $refcount == 2 ? (TransitivityCheck($row, $ref1, $ref2) ? 0 : 1) : 2;
        case 3: return $refcount == 1 ? (AugmentationCheck($row, $ref1) ? 0 : 1) : 2;
        case 4: return $refcount == 2 ? (UnionCheck($row, $ref1, $ref2) ? 0 : 1) : 2;
        case 5: return $refcount == 1 ? (DecompositionCheck($row, $ref1) ? 0 : 1) : 2;
        case 6: return $refcount == 2 ? (PseudoTransitivityCheck($row, $ref1, $ref2) ? 0 : 1) : 2;
        default:
            trigger_error("Error Invalid Rule");
            return 3;
    }
}

function ClosureStep($row, $qentries, &$previouslist){
    if(count($row->refs) > 1 || !($row->rule == -1 || $row->rule == 0 || $row->rule == 1)) return 2; //invalid refs or rules, formatfail
    if(count($row->refs) == 0) return $row->list == $previouslist ? 0 : 1; //logic for Reflexivity
    if($row->refs[0] > count($qentries) || $row->rule == 1) return 2; //invalid ref, or Reflexivity format fails
    $qrow = $qentries[$row->refs[0]];
    if($qrow->left == ($qrow->left & $previouslist) && $row->list == ($qrow->right | $previouslist)){ //compare step with ref and previous step.
        $previouslist = $row->list;
        return 0;
    }
    return 1;
}

function AttributeClosure($set, $qentries){
    $closure = (int)$set;
    do{
        $memory = $closure;
        foreach($qentries as $row){
            if($row->left == ($row->left & $closure)){
                $closure = $closure | $row->right;
            }
        }
    }while($memory != $closure);
    return $closure;
}

?>