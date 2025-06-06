<!DOCTYPE html>
<!--
Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
Click nbfs://nbhost/SystemFileSystem/Templates/Other/html.html to edit this template
-->
<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>U of I Webpage</title>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/css/bootstrap.min.css" rel="stylesheet">
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/js/bootstrap.bundle.min.js"></script>
        <link rel="stylesheet" type="text/css" href="main.css">
    </head>
    <body>
        <div class="container-fluid">
            <div class="row">

                <!-- Menu on vertical left black side bar -->

                <div class="col-md-2">
                    <h1>U of I Website</h1>
                    <nav class="navbar-nav">
                        <a class="nav-link text-white" href="{{ route('UI_Website_Home') }}">Home</a>
                        <a class="nav-link text-white" href="{{ route('UI_Website_Photos') }}">Photos</a>
                        <a class="nav-link text-white" href="{{ route('UI_Website_Bio') }}">Bio</a>
                        <a class="nav-link text-white" href="{{ route('UI_Website_Blog') }}">Blog</a>
                    </nav>

                    <!-- Button to Open the Modal -->

                    <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#myModal">
                        Contact Us
                    </button>

                    <!-- The Modal -->

                    <div class="modal" id="myModal">
                        <div class="modal-dialog">
                            <div class="modal-content">

                                <!-- Modal Header -->

                                <div class="modal-header">
                                    <h4 class="modal-title">Contact Us</h4>
                                    <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
                                </div>

                                <!-- Modal body -->

                                <div class="modal-body">
                                    <form action="/action_page.php">
                                        <div class="mb-3 mt-3">
                                            <label for="email" class="form-label">Name:</label>
                                            <input type="email" class="form-control" id="name" placeholder="Enter name" name="name">
                                        </div>
                                        <div class="mb-3">
                                            <label for="pwd" class="form-label">Email:</label>
                                            <input type="password" class="form-control" id="email" placeholder="Enter email" name="email">
                                        </div>
                                        <button type="submit" class="btn btn-primary">Submit</button>
                                    </form>
                                </div>

                                <!-- Modal footer -->

                                <div class="modal-footer">
                                    <button type="button" class="btn btn-danger" data-bs-dismiss="modal">Close</button>
                                </div>

                            </div>
                        </div>
                    </div>

                    <!-- Social media buttons -->

                    <div>
                        <a href="https://www.facebook.com/" target="_blank">
                            <img src="Logos/Facebook_Logo.png" alt="Facebook Logo" style="width: 25px; height: 25px;">
                        </a>

                        <a href="https://twitter.com/" target="_blank">
                            <img src="Logos/Twitter_Logo.png" alt="Twitter Logo" style="width: 25px; height: 25px;">
                        </a>
                        <a href="https://www.instagram.com/" target="_blank">
                            <img src="Logos/Instagram_Logo.jpg" alt="Instagram Logo" style="width: 25px; height: 25px;">
                        </a>
                    </div>

                    <!-- Finish menu in vertical left black side bar -->

                </div>

                <!-- U of I photo gallery -->

                <div class="col-md-10">
                    <div class="row">
                        <div class="col-md-4">
                            <a href="#" data-bs-toggle="modal" data-bs-target="#image_modal_1">
                                <img src="UI_Pictures/UI_1.jpg" alt="Image 1" class="img-fluid">
                            </a>
                        </div>
                        <div class="col-md-4">
                            <a href="#" data-bs-toggle="modal" data-bs-target="#image_modal_2">
                                <img src="UI_Pictures/UI_2.jpg" alt="Image 2" class="img-fluid">
                            </a>
                        </div>
                        <div class="col-md-4">
                            <a href="#" data-bs-toggle="modal" data-bs-target="#image_modal_3">
                                <img src="UI_Pictures/UI_3.jpg" alt="Image 3" class="img-fluid">
                            </a>
                        </div>
                    </div>
                    <div class="row mt-4">
                        <div class="col-md-6">
                            <a href="#" data-bs-toggle="modal" data-bs-target="#image_modal_4">
                                <img src="UI_Pictures/UI_4.jpg" alt="Image 4" class="img-fluid">
                            </a>
                        </div>
                        <div class="col-md-6">
                            <a href="#" data-bs-toggle="modal" data-bs-target="#image_modal_5">
                                <img src="UI_Pictures/UI_5.jpg" alt="Image 5" class="img-fluid">
                            </a>
                        </div>
                    </div>
                    <div class="row mt-4">
                        <div class="col-md-4">
                            <a href="#" data-bs-toggle="modal" data-bs-target="#image_modal_6">
                                <img src="UI_Pictures/UI_6.jpg" alt="Image 6" class="img-fluid">
                            </a>
                        </div>
                        <div class="col-md-4">
                            <a href="#" data-bs-toggle="modal" data-bs-target="#image_modal_7">
                                <img src="UI_Pictures/UI_7.jpg" alt="Image 7" class="img-fluid">
                            </a>
                        </div>
                        <div class="col-md-4">
                            <a href="#" data-bs-toggle="modal" data-bs-target="#image_modal_8">
                                <img src="UI_Pictures/UI_8.jpg" alt="Image 8" class="img-fluid">
                            </a>
                        </div>
                    </div>
                </div>
            </div>
        </div>

        <!-- Click for image functionality -->

        <div class="modal" id="image_modal_1">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <img src="UI_Pictures/UI_1.jpg" alt="Image" class="img-fluid">
                    </div>
                </div>
            </div>
        </div>

        <div class="modal" id="image_modal_2">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <img src="UI_Pictures/UI_2.jpg" alt="Image" class="img-fluid">
                    </div>
                </div>
            </div>
        </div>

        <div class="modal" id="image_modal_3">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <img src="UI_Pictures/UI_3.jpg" alt="Image" class="img-fluid">
                    </div>
                </div>
            </div>
        </div>

        <div class="modal" id="image_modal_4">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <img src="UI_Pictures/UI_4.jpg" alt="Image" class="img-fluid">
                    </div>
                </div>
            </div>
        </div>

        <div class="modal" id="image_modal_5">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <img src="UI_Pictures/UI_5.jpg" alt="Image" class="img-fluid">
                    </div>
                </div>
            </div>
        </div>

        <div class="modal" id="image_modal_6">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <img src="UI_Pictures/UI_6.jpg" alt="Image" class="img-fluid">
                    </div>
                </div>
            </div>
        </div>

        <div class="modal" id="image_modal_7">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <img src="UI_Pictures/UI_7.jpg" alt="Image" class="img-fluid">
                    </div>
                </div>
            </div>
        </div>

        <div class="modal" id="image_modal_8">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <img src="UI_Pictures/UI_8.jpg" alt="Image" class="img-fluid">
                    </div>
                </div>
            </div>
        </div>
        
        <!--Text passage-->
        
        <div>
            <h2>My Blog</h2>
            <p>
                Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Tristique risus nec feugiat in fermentum posuere. Nullam non nisi est sit amet facilisis magna etiam. In nisl nisi scelerisque eu. Egestas pretium aenean pharetra magna ac. Dolor sit amet consectetur adipiscing elit ut aliquam. Vivamus at augue eget arcu. Et netus et malesuada fames. Tellus integer feugiat scelerisque varius. Ut eu sem integer vitae. At in tellus integer feugiat scelerisque varius morbi enim. In ornare quam viverra orci sagittis. Proin sagittis nisl rhoncus mattis rhoncus urna neque viverra justo. Feugiat scelerisque varius morbi enim. Enim nulla aliquet porttitor lacus luctus accumsan tortor posuere ac. Leo duis ut diam quam nulla. Viverra suspendisse potenti nullam ac. Diam vel quam elementum pulvinar. Rutrum quisque non tellus orci ac. Ultricies leo integer malesuada nunc vel.
            </p>
            <p>
                Enim sit amet venenatis urna cursus eget nunc. Venenatis urna cursus eget nunc scelerisque. Phasellus egestas tellus rutrum tellus pellentesque. Euismod nisi porta lorem mollis aliquam ut porttitor leo a. Est lorem ipsum dolor sit amet consectetur. Morbi tincidunt augue interdum velit euismod in. Risus in hendrerit gravida rutrum quisque non. Felis eget velit aliquet sagittis id consectetur purus. Nisi scelerisque eu ultrices vitae auctor eu augue. Tristique senectus et netus et malesuada fames ac turpis. Cras pulvinar mattis nunc sed blandit libero volutpat sed cras. Gravida in fermentum et sollicitudin ac orci phasellus. Etiam erat velit scelerisque in. Sit amet purus gravida quis blandit turpis cursus.
            </p>
            <p>
                Proin libero nunc consequat interdum. Sit amet consectetur adipiscing elit pellentesque habitant morbi. Porttitor eget dolor morbi non arcu risus. Elementum curabitur vitae nunc sed velit dignissim sodales ut eu. Condimentum id venenatis a condimentum vitae sapien pellentesque. Est placerat in egestas erat imperdiet sed euismod nisi porta. Commodo sed egestas egestas fringilla phasellus faucibus scelerisque. Consequat nisl vel pretium lectus quam id leo. Tempus egestas sed sed risus pretium quam vulputate. Sit amet volutpat consequat mauris.
            </p>
            <p>
                Id diam vel quam elementum pulvinar etiam non. Ipsum dolor sit amet consectetur adipiscing elit. Dictum non consectetur a erat nam at. Nunc mattis enim ut tellus elementum sagittis vitae et. Quis blandit turpis cursus in hac habitasse platea. Nisi lacus sed viverra tellus in hac habitasse platea dictumst. Sapien et ligula ullamcorper malesuada proin. Diam quis enim lobortis scelerisque fermentum dui faucibus. Pretium quam vulputate dignissim suspendisse in est ante. Ullamcorper malesuada proin libero nunc consequat interdum. Sem nulla pharetra diam sit amet nisl suscipit adipiscing bibendum. Eget velit aliquet sagittis id consectetur purus ut faucibus pulvinar. Pellentesque habitant morbi tristique senectus et netus et malesuada. Leo in vitae turpis massa sed elementum tempus egestas.
            </p>
            <p>
                Sodales ut etiam sit amet nisl purus in. Cras tincidunt lobortis feugiat vivamus at augue eget. Facilisis mauris sit amet massa vitae tortor condimentum lacinia. Amet nulla facilisi morbi tempus. Id donec ultrices tincidunt arcu non sodales neque sodales ut. Eu augue ut lectus arcu bibendum at. Nisi quis eleifend quam adipiscing. Suspendisse sed nisi lacus sed viverra tellus in hac habitasse. Lacus viverra vitae congue eu consequat. Convallis convallis tellus id interdum velit. Varius quam quisque id diam vel quam elementum pulvinar. Malesuada fames ac turpis egestas maecenas pharetra convallis. Cursus sit amet dictum sit amet justo donec. Purus ut faucibus pulvinar elementum integer enim neque volutpat. Ultricies mi eget mauris pharetra et ultrices neque. Risus pretium quam vulputate dignissim suspendisse in est.
            </p>
        </div>

    </body>
</html>
