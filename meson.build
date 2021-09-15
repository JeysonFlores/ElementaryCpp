project('com.github.jeysonflores.elementarycpp', ['cpp', 'c'], 
          version: '0.1.0',
    meson_version: '>= 0.50.0',
  default_options: [ 'warning_level=2',
                     'cpp_std=gnu++17',
                   ],
)


subdir('data')

executable(
	meson.project_name(),
	['src/Application.cpp', 'src/MainWindow.cpp', ['src/MainWindow.h']],
	dependencies: [
		dependency('gtkmm-3.0'),
	],
	install: true
)


meson.add_install_script('build-aux/post_install.py')
