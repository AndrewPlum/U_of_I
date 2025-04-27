<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <title>Complex Webpage</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.3.1/dist/css/bootstrap.min.css"
        integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <link rel="stylesheet" href="main.css">

</head>

<body>
    <div class="row">
        <div class="col-auto">
            <div class="row px-2 gray">
                <div class="col">Consequence of F</div>
            </div>
            <div class="row pink givens">
                <div class="col offset-3">
                    <div class="row">
                        <input class="form-check-input" type="checkbox" value="" id="given1">
                        <label class="form-check-label" for="given1">1. A->B</label>
                    </div>
                    <div class="row">
                        <input class="form-check-input" type="checkbox" value="" id="given2">
                        <label class="form-check-label" for="given2">2. B->C</label>
                    </div>
                    <div class="row">
                        <input class="form-check-input" type="checkbox" value="" id="given3">
                        <label class="form-check-label" for="given3">3. BC->AD</label>
                    </div>
                    <div class="row">
                        <input class="form-check-input" type="checkbox" value="" id="given4">
                        <label class="form-check-label" for="given4">4. BCD->E</label>
                    </div>
                </div>
            </div>
        </div>
        <div class="col-auto gray" id="row-container">
            <div class="row align-items-center">
                <div class="col-auto">
                    <input type="checkbox" id="left-a">
                    <label for="left-a">A</label>
                </div>
                <div class="col-auto">
                    <input type="checkbox" id="left-b">
                    <label for="left-b">B</label>
                </div>
                <div class="col-auto">
                    <input type="checkbox" id="left-c">
                    <label for="left-c">C</label>
                </div>
                <div class="col-auto">
                    <input type="checkbox" id="left-d">
                    <label for="left-d">D</label>
                </div>
                <div class="col-auto">
                    <input type="checkbox" id="left-e">
                    <label for="left-e">E</label>
                </div>
                <div class="col-auto" style="font-size: x-large">
                    &rarr;
                </div>
                <div class="col-auto">
                    <input type="checkbox" id="right-a">
                    <label for="right-a">A</label>
                </div>
                <div class="col-auto">
                    <input type="checkbox" id="right-b">
                    <label for="right-b">B</label>
                </div>
                <div class="col-auto">
                    <input type="checkbox" id="right-c">
                    <label for="right-c">C</label>
                </div>
                <div class="col-auto">
                    <input type="checkbox" id="right-d">
                    <label for="right-d">D</label>
                </div>
                <div class="col-auto">
                    <input type="checkbox" id="right-e">
                    <label for="right-e">E</label>
                </div>
                <div class="col-auto form-group">
                    <label for="form-rules-dropdown">Select a Rule:</label>
                    <select class="form-control" id="form-rules-dropdown" name="form-rules">
                        <option value="given">Given</option>
                        <option value="reflexivity">Reflexivity</option>
                        <option value="transitivity">Transitivity</option>
                        <option value="augmentation">Augmentation</option>
                        <option value="union">Union</option>
                        <option value="decomposition">Decomposition</option>
                        <option value="pseudoTransitivity">Pseudo Transitivity</option>
                    </select>
                </div>                
            </div>
        </div>
        <div class="col-auto">
            <button id="createButton">Create a New Row</button>
        </div>

    </div>
<script src="myscript.js"></script>
</body>

</html>