<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Complex Webpage</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.3.1/dist/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <link rel="stylesheet" href="main.css">
</head>
<body>
    <div class="container-fluid">
        <div class="top segment">
            <div class="container" id="segment1">
                <div class="col-md-12 gray-background">
                    <div class="white-box">Consequence of F ~</div>
                    <div class="top_checkboxes">
                        <div class="form-check" style="display: inline-block;">
                            <input class="form-check-input" type="checkbox" value="" id="checkbox1">
                            <label class="form-check-label" for="checkbox1">Given</label>
                        </div>
                        <div class="form-check" style="display: inline-block;">
                            <input class="form-check-input" type="checkbox" value="" id="checkbox2">
                            <label class="form-check-label" for="checkbox2">Reflexivity</label>
                        </div>
                        <div class="form-check" style="display: inline-block;">
                            <input class="form-check-input" type="checkbox" value="" id="checkbox3">
                            <label class="form-check-label" for="checkbox3">Transitivity</label>
                        </div>
                        <div class="form-check" style="display: inline-block;">
                            <input class="form-check-input" type="checkbox" value="" id="checkbox4">
                            <label class="form-check-label" for="checkbox4">Augmentation</label>
                        </div>
                        <div class="form-check" style="display: inline-block;">
                            <input class="form-check-input" type="checkbox" value="" id="checkbox5">
                            <label class="form-check-label" for="checkbox5">Union</label>
                        </div>
                        <div class="form-check" style="display: inline-block;">
                            <input class="form-check-input" type="checkbox" value="" id="checkbox6">
                            <label class="form-check-label" for="checkbox6">Decomposition</label>
                        </div>
                        <div class="form-check" style="display: inline-block;">
                            <input class="form-check-input" type="checkbox" value="" id="checkbox7">
                            <label class="form-check-label" for="checkbox7">Pseudo Transitivity</label>
                        </div>
                    </div>
                </div>
            </div>
        </div>

        <div class="bottom segment">

            <!-- 2nd Segment -->

            <div class="container" id="segment2">
                <div class="col-2 pink-background">
                    <div class="given_check">
                        <input class="form-check-input" type="checkbox" value="" id="checkbox8">
                        <label class="form-check-label" for="checkbox1">1. A->B</label>
                    </div>
                    <div class="given_check">
                        <input class="form-check-input" type="checkbox" value="" id="checkbox9">
                        <label class="form-check-label" for="checkbox2">2. B->C</label>
                    </div>
                    <div class="given_check">
                        <input class="form-check-input" type="checkbox" value="" id="checkbox10">
                        <label class="form-check-label" for="checkbox3">3. BC->AD</label>
                    </div>
                    <div class="given_check">
                        <input class="form-check-input" type="checkbox" value="" id="checkbox11">
                        <label class="form-check-label" for="checkbox4">4. BCD->E</label>
                    </div>
                </div>
            </div>


            <!-- 3rd Segment -->
            <div class="row segment" id="segment3">
                <div class="col-md-7 white-background">
                    <!-- 1st Section -->
                    <div class="section" style="display: inline-block;">
                        <div class="form-check">
                            <input class="form-check-input" type="checkbox" value="" id="checkbox5-1">
                            <label class="form-check-label" for="checkbox5-1">5.1</label>
                        </div>
                        <!-- Additional checkboxes for 1st section -->
                    </div>

                    <!-- 2nd Section -->
                    <div class="section" style="display: inline-block;">
                        <div class="arrows">-></div>
                        <!-- Additional arrows for 3rd section -->
                    </div>
                    
                    <!-- 3rd Section -->
                    <div class="section" style="display: inline-block;">
                        <div class="form-check">
                            <input class="form-check-input" type="checkbox" value="" id="checkbox5-2">
                            <label class="form-check-label" for="checkbox5-2">5.2</label>
                        </div>
                        <!-- Additional checkboxes for 2nd section -->
                    </div>

                    <!-- 4th Section -->
                    <div class="section" style="display: inline-block;">
                        <!-- Add checkboxes for the 4th section -->
                    </div>
                </div>
                <!-- Other content in the 3rd segment -->
            </div>


            <!-- 4th Segment -->
            <div class="row segment" id="segment4">
                <!-- Content for the 4th segment -->
            </div>

            <!-- 5th Segment -->
            <div class="row segment" id="segment5">
                <div class="col-md-2 brown-background">
                    <div class="yellow-checkboxes">
                        <div class="form-check">
                            <input class="form-check-input yellow-checkbox" type="checkbox" value="" id="yellow-checkbox1">
                            <label class="form-check-label" for="yellow-checkbox1">Yellow 1</label>
                        </div>
                        <div class="form-check">
                            <input class="form-check-input yellow-checkbox" type="checkbox" value="" id="yellow-checkbox1">
                            <label class="form-check-label" for="yellow-checkbox1">Yellow 1</label>
                        </div>
                        <!-- Additional yellow checkboxes will be dynamically added here -->
                    </div>
                </div>
                <div class="col-md-2 green-checkboxes">
                    <div class="form-check">
                        <input class="form-check-input green-checkbox" type="checkbox" value="" id="green-checkbox1">
                        <label class="form-check-label" for="green-checkbox1">Green 1</label>
                    </div>
                    <div class="form-check">
                        <input class="form-check-input green-checkbox" type="checkbox" value="" id="green-checkbox1">
                        <label class="form-check-label" for="green-checkbox1">Green 1</label>
                    </div>
                    <!-- Additional green checkboxes will be dynamically added here -->
                </div>
            </div>
        </div>
    </div>
</body>
</html>
