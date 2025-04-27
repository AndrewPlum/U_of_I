<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider and all of them will
| be assigned to the "web" middleware group. Make something great!
|
*/

Route::get('/UI_Website_Home', function () {
    return view('UI_Website_Home');
})->name('UI_Website_Home');

Route::get('/UI_Website_Photos', function () {
    return view('UI_Website_Photos');
})->name('UI_Website_Photos');

Route::get('/UI_Website_Bio', function () {
    return view('UI_Website_Bio');
})->name('UI_Website_Bio');

Route::get('/UI_Website_Blog', function () {
    return view('UI_Website_Blog');
})->name('UI_Website_Blog');
