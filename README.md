![Screenshot](https://github.com/JeysonFlores/ElementaryCpp/blob/main/data/screenshots/Screenshot-1.png) 
# Description
ElementaryCpp is a template for eOS applications, meaning that it's built over Gtkmm and C++17.

# Features
 - GSchema Support
 - Flatpak Manifest Example
 
 # Build & Run
 ```
git clone https://github.com/JeysonFlores/ElementaryCpp
cd ElementaryLua
flatpak-builder build com.github.jeysonflores.elementarycpp.json --user --install --force-clean
flatpak run com.github.jeysonflores.elementarycpp
 ```
