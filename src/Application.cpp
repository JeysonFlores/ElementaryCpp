#include "MainWindow.h"
#include <memory>
#include <gtkmm.h>


using namespace Glib;
using namespace Gtk;


int main (int argc, char *argv[]) {

	RefPtr<Gtk::Application> application = Gtk::Application::create(argc, argv);
	application -> set_id("com.github.jeysonflores.elementarycpp");
	
	auto m_settings = Gio::Settings::create("com.github.jeysonflores.elementarycpp");
	auto window_width = m_settings -> get_int ("window-width");
	auto window_height = m_settings -> get_int("window-height");
	auto pos_x = m_settings -> get_int("pos-x");
	auto pos_y = m_settings -> get_int("pos-y");

	MainWindow main_window;

	main_window.resize(window_width, window_height);
	main_window.move(pos_x,pos_y);

	return application->run(main_window);
}


