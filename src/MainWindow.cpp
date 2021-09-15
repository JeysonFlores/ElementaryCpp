#include "MainWindow.h"
#include <stdio.h>

bool MainWindow::on_delete_event (GdkEventAny* event) {
    int width, height;
    int pos_x = 0, pos_y = 0;

    auto m_settings = Gio::Settings::create("com.github.jeysonflores.elementarycpp");
    
	this -> get_size((int&)width, (int&)height);
	this -> get_position((int&)pos_x, (int&)pos_y);
	
	m_settings -> set_int ("window-width", width);
	m_settings -> set_int ("window-height", height);

	m_settings -> set_int ("pos-x", pos_x);
	m_settings -> set_int ("pos-y", pos_y);
	
	return false;
}

void MainWindow::on_gtkmm_button_clicked() {
    std::system("xdg-open https://www.gtkmm.org/en/");
}

void MainWindow::on_edocs_button_clicked() {
    std::system("xdg-open https://docs.elementary.io/develop/");
}

MainWindow::MainWindow() {
	auto window_context = this -> get_style_context ();
    window_context -> add_class("rounded");
    
    title.set_text("Welcome to ElementaryCpp");
    auto title_context = title.get_style_context ();
    title_context -> add_class("h1");
    
    subtitle.set_text("Welcome to ElementaryCpp");
    auto subtitle_context = subtitle.get_style_context ();
    subtitle_context -> add_class("h2");
    subtitle_context -> add_class("dim-label");
    subtitle.set_margin_bottom(30);
    
    gtkmm_button.set_label("Gtkmm Docs");
    gtkmm_button.set_can_focus(false);
    gtkmm_button.set_margin_bottom(30);
    gtkmm_button.set_halign(Gtk::ALIGN_CENTER);
    gtkmm_button.signal_clicked().connect(sigc::mem_fun(this, &MainWindow::on_gtkmm_button_clicked));
    auto gtkmm_button_context = gtkmm_button.get_style_context ();
    //gtkmm_button_context -> add_class("keycap");
    gtkmm_button_context -> add_class("suggested-action");
    
    edocs_button.set_label("eOS Dev Docs");
    edocs_button.set_can_focus(false);
    edocs_button.set_halign(Gtk::ALIGN_CENTER);
    edocs_button.signal_clicked().connect(sigc::mem_fun(this, &MainWindow::on_edocs_button_clicked));
    auto edocs_button_context = edocs_button.get_style_context ();
    //edocs_button_context -> add_class("keycap");
    edocs_button_context -> add_class("suggested-action");
    
    box.set_orientation(Gtk::ORIENTATION_VERTICAL);
    box.set_valign(Gtk::ALIGN_CENTER);
    box.pack_start(title);
    box.pack_start(subtitle);
    box.pack_start(gtkmm_button);
    box.pack_start(edocs_button);
    
    headerbar.set_title("Test App");
    headerbar.set_show_close_button(true);
    headerbar.set_decoration_layout("close:");
    auto headerbar_context = headerbar.get_style_context();
    headerbar_context -> add_class("flat");
    
    this -> set_titlebar(headerbar);
    this -> set_title("Elementary Cpp");
    this -> add(box);
    this -> resize(400, 300);
    this -> show_all();

}


