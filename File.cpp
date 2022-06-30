#include "File.h"

File::File() {
    this->lines = "";
}

void File::open(std::string name) {
    file.open(name, std::ios::in | std::ios::out);
    if (!file) { // Validacion extra para windows
        name = "../" + name;
        file.open(name, std::ios::in | std::ios::out);
    }
}

std::string File::read() {
    getline(file, lines);
    if (lines[lines.length() - 1] == '\r') { // Validacion extra para windows
        lines = lines.substr(0, lines.length() - 1);
    }
    return lines;
}

bool File::eof() {
    return this->file.eof();
}

File::~File() {
    file.close();
}
