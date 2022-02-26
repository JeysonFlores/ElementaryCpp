#include "MainWindow.h"

bool MainWindow::on_delete_event(GdkEventAny* event)
{
    int width, height;
    int pos_x, pos_y;

    auto settings = Gio::Settings::create("com.github.jeysonflores.elementarycpp");

    this->get_size((int&)width, (int&)height);
    this->get_position((int&)pos_x, (int&)pos_y);

    settings->set_int("window-width", width);
    settings->set_int("window-height", height);

    settings->set_int("pos-x", pos_x);
    settings->set_int("pos-y", pos_y);

    return false;
}

void MainWindow::on_gtkmm_button_clicked()
{
    Gio::AppInfo::launch_default_for_uri("https://www.gtkmm.org/en/");
}

MainWindow::MainWindow()
{
    this->get_style_context()->add_class("rounded");

    m_title.set_text("Welcome to ElementaryCpp");
    m_title.get_style_context()->add_class("h1");

    m_subtitle.set_text("Welcome to ElementaryCpp");
    m_subtitle.set_margin_bottom(30);

    auto subtitle_context = m_subtitle.get_style_context();
    subtitle_context->add_class("h2");
    subtitle_context->add_class("dim-label");

    m_gtkmm_button.set_label("Gtkmm Docs");
    m_gtkmm_button.set_can_focus(false);
    m_gtkmm_button.set_margin_bottom(30);
    m_gtkmm_button.set_halign(Gtk::ALIGN_CENTER);
    // libsigc++ signal connecting
    m_gtkmm_button.signal_clicked().connect(sigc::mem_fun(this, &MainWindow::on_gtkmm_button_clicked));
    m_gtkmm_button.get_style_context()->add_class("suggested-action");

    m_edocs_button.set_label("eOS Dev Docs");
    m_edocs_button.set_can_focus(false);
    m_edocs_button.set_halign(Gtk::ALIGN_CENTER);
    // lambda signal connecting
    m_edocs_button.signal_clicked().connect([&] {
        Gio::AppInfo::launch_default_for_uri("https://docs.elementary.io/develop/");
    });
    m_edocs_button.get_style_context()->add_class("suggested-action");

    m_box.set_orientation(Gtk::ORIENTATION_VERTICAL);
    m_box.set_valign(Gtk::ALIGN_CENTER);
    m_box.pack_start(m_title);
    m_box.pack_start(m_subtitle);
    m_box.pack_start(m_gtkmm_button);
    m_box.pack_start(m_edocs_button);

    m_headerbar.set_title("Test App");
    m_headerbar.set_show_close_button(true);
    m_headerbar.set_decoration_layout("close:");
    m_headerbar.get_style_context()->add_class("flat");

    this->set_titlebar(m_headerbar);
    this->set_title("Elementary Cpp");
    this->add(m_box);
    this->show_all();
}
