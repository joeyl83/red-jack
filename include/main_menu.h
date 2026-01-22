#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <godot_cpp/classes/control.hpp>

using namespace godot;

class MainMenu : public Control {
    GDCLASS(MainMenu, Control);

    protected:
        static void _bind_methods();

    public:
        virtual void _ready() override;
        void _on_start_pressed();
        void _on_options_pressed();
        void _on_exit_pressed();
};

#endif