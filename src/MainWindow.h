#pragma once

#include <gtkmm.h>

class MainWindow : public Gtk::Window
{
public:
	MainWindow();
	void on_gtkmm_button_clicked();
	void on_edocs_button_clicked();
	bool on_delete_event (GdkEventAny* event) override;
	
private:
	Gtk::Label title;
	Gtk::Label subtitle;
	Gtk::Button gtkmm_button;
	Gtk::Button edocs_button;
	Gtk::HeaderBar headerbar;
	Gtk::Box box;
};
