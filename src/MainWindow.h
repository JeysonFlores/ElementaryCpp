#pragma once

#include <gtkmm.h>

class MainWindow : public Gtk::ApplicationWindow {
public:
    MainWindow();
    void on_gtkmm_button_clicked();
    bool on_delete_event(GdkEventAny* event) override;

private:
    Gtk::Label m_title;
    Gtk::Label m_subtitle;
    Gtk::Button m_gtkmm_button;
    Gtk::Button m_edocs_button;
    Gtk::HeaderBar m_headerbar;
    Gtk::Box m_box;
};
