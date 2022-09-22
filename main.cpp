#include <iostream>
#include <fstream>
int main(int argc, char** argv) {
    std::string filename;
    std::string options;
    std::string line;
    std::string line_of_output;
    int lines = 0;
    int words = 0;

    std::ifstream fin;

    std::cout << "Labwork1!\n";

    if (argc < 2) {
        std::cout << "Error: few arguments\n";
        return 0;
    }
    else if (argc == 2) {
        filename = argv[1];
        options = "-l-w-b";
    }
    else {
        filename = argv[argc - 1];
        for (int i = 1; i < argc - 1; i++) {
            options += argv[i];
        }
    }
    fin.open(filename, std::ifstream::ate | std::ifstream::binary);
    std::streamoff size = fin.tellg();
    fin.close();
    fin.open(filename);
    if (fin.is_open()) {
        while (getline(fin, line)) {
             lines++;
             int count_of_whitespaces = 0;
             for (int i = 1; i < line.length(); i++) {
                 if (line[i] == ' ') {
                     count_of_whitespaces++;
                 }
             }
             words += count_of_whitespaces + 1;
        }
    }

    if ((options.find("--lines") != std::string::npos) or (options.find("-l") != std::string::npos)) {
        std::cout << "lines - " << lines << " ";
    }
    if ((options.find("--words") != std::string::npos) or (options.find("-w") != std::string::npos)) {
        std::cout << "words - " << words << " ";
    }
    if ((options.find("--bytes") != std::string::npos) or (options.find("-b") != std::string::npos)) {
        std::cout << "bytes - " << size << " ";
    }
    std::cout << filename << std::endl;
    fin.close();
    return 0;
}