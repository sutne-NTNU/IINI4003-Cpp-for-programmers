#include <gtkmm.h>


class Window : public Gtk::Window {
public:
    Gtk::VBox vbox;
    Gtk::Label label1;
    Gtk::Entry firstname;
    Gtk::Label label2;
    Gtk::Entry lastname;
    Gtk::Button button;
    Gtk::Label result;

    Window() {
        set_title("04 - Containers, auto and lambda");

        label1.set_text("First name");
        vbox.pack_start(label1);
        vbox.pack_start(firstname);

        label2.set_text("Last name");
        vbox.pack_start(label2);
        vbox.pack_start(lastname);

        button.set_label("Combine names");
        button.set_sensitive(false);
        vbox.pack_start(button);

        vbox.pack_start(result);

        add(vbox);
        show_all();

        firstname.signal_changed().connect([this]() {
            button.set_sensitive((firstname.get_text() != "") && (lastname.get_text() != ""));
        });

        lastname.signal_changed().connect([this]() {
            button.set_sensitive((firstname.get_text() != "") && (lastname.get_text() != ""));
        });

        button.signal_clicked().connect([this]() {
            result.set_text("Combined names are: " + firstname.get_text() + " " + lastname.get_text());
        });
    }
};


int main() {
    Gtk::Main gtk_main;
    Window window;
    gtk_main.run(window);
}
