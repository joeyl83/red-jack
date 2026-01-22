#include "../include/main_menu.h"

#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void MainMenu::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("_on_start_pressed"), &MainMenu::_on_start_pressed);
    ClassDB::bind_method(D_METHOD("_on_options_pressed"), &MainMenu::_on_options_pressed);
    ClassDB::bind_method(D_METHOD("_on_exit_pressed"), &MainMenu::_on_exit_pressed);
}

void MainMenu::_ready()
{
    Button *start_button = get_node<Button>("VBoxContainer/StartButton");
    Button *options_button = get_node<Button>("VBoxContainer/OptionsButton");
    Button *exit_button = get_node<Button>("VBoxContainer/ExitButton");

    if (start_button)
    {
        start_button->connect("pressed", Callable(this, "_on_start_pressed"));
    }
    if (options_button)
    {
        options_button->connect("pressed", Callable(this, "_on_options_pressed"));
    }
    if (exit_button)
    {
        exit_button->connect("pressed", Callable(this, "_on_exit_pressed"));
    }
}

void MainMenu::_on_start_pressed()
{
    // Logic to start the game
    UtilityFunctions::print("Start button pressed. Starting the game...");
    // Example: get_tree()->change_scene("res://path_to_game_scene.tscn");
    get_tree()->change_scene_to_file("res://scenes/game_scene.tscn");
}

void MainMenu::_on_options_pressed()
{
    // Logic to open options menu
    UtilityFunctions::print("Options button pressed. Opening options menu...");
    // Example: get_tree()->change_scene("res://path_to_options_scene.tscn");
}

void MainMenu::_on_exit_pressed()
{
    // Logic to exit the game
    UtilityFunctions::print("Exit button pressed. Exiting the game...");
    get_tree()->quit();
}