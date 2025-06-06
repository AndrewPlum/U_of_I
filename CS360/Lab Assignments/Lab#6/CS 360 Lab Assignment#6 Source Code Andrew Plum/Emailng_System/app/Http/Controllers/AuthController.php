<?php

namespace App\Http\Controllers;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Auth;
use Session;
use App\Models\User;
use Hash;

class AuthController extends Controller
{
    public function index(){
        return view('auth.login');
    }
    
    public function registration(){
        return view('auth.registration');
    }
    
    public function postLogin(Request $request){
        $request->validate([
            'email' => 'required',
            'password' => 'required',
        ]);
        $credentials = $request->only('email','password');
        if(Auth::attempt($credentials)){
            return redirect()->intended('dashboard')
                ->withSuccess('You have logged in to your account!');
        }
        return redirect("login")->withSuccess('You have entered invalid credentials.');
    }

    public function postRegistration(Request $request){
        $request->validate([
            'name' => 'required',
            'email' => 'required|email|unique:users',
            'password' => 'required|min:6',
        ]);
        $data = $request->all();
        $check = $this->create($data);
        return redirect("dashboard")->withSuccess('You have successfully logged into the system.');
    }

    public function dashboard(){
        if(Auth::check()){
            return view('auth.dashboard');
        }
        return redirect("login")->withsuccess('You do not have access to the system.');
    }

    public function create(array $data){
        return User::create([
            'name'=>$data['name'],
            'email' =>$data['email'],
            'password'=>Hash::make($data['password'])
        ]);
    }
    
    public function logout(){
        Session::flush();
        Auth::logout();
        return Redirect('login');
    }
}
