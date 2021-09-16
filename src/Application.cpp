#include "Application.h"
#include "MainWindow.h"

Application::Application()
: Gtk::Application("com.github.jeysonflores.elementarycpp")
{
}

Glib::RefPtr<Application> Application::create()
{
	return Glib::RefPtr<Application>(new Application());
}

void Application::on_prefers_color_scheme_changed()
{
	auto granite_settings = granite_settings_get_default();
	auto gtk_settings = Gtk::Settings::get_default();
	auto colour_scheme = granite_settings_get_prefers_color_scheme(granite_settings);

	gtk_settings->property_gtk_application_prefer_dark_theme().set_value(colour_scheme == GRANITE_SETTINGS_COLOR_SCHEME_DARK);
}

void Application::on_activate()
{
	// Initially set the preferred colour scheme
	on_prefers_color_scheme_changed();

	// Listen for changes to the colour scheme
	auto granite_settings = granite_settings_get_default();
	g_signal_connect(granite_settings, "notify::prefers-color-scheme", G_CALLBACK(&on_prefers_color_scheme_changed), NULL);

	auto appwindow = new MainWindow();
	add_window(*appwindow);

	auto m_settings = Gio::Settings::create("com.github.jeysonflores.elementarycpp");
	auto window_width = m_settings -> get_int ("window-width");
	auto window_height = m_settings -> get_int("window-height");
	auto pos_x = m_settings -> get_int("pos-x");
	auto pos_y = m_settings -> get_int("pos-y");

	appwindow -> resize(window_width, window_height);
	appwindow -> move(pos_x,pos_y);
}

int main (int argc, char *argv[]) {
	auto application = Application::create();
	return application->run(argc, argv);
}
