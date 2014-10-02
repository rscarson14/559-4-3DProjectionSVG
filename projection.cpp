#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#define IMG_WIDTH (300)
#define IMG_HEIGHT (300)

std::ofstream svg;
std::ifstream in_file;


void header(){
	svg << "<svg xmlns=\"http://www.w3.org/2000/svg\"" << std::endl
	<< "xmlns:xlink=\"http://www.w3.org/1999/xlink\"" << std::endl
	<< "xmlns:ev=\"http://www/w3/org/2001/xml-events\">" << std::endl
	<< "width=\"" << IMG_WIDTH << "\"" << std::endl
	<< "height=\"" << IMG_HEIGHT << "\">" << std::endl;

	svg << "<rect width=\"" << IMG_WIDTH << "\" height=\"" << IMG_HEIGHT << "\""
		<< " x=\"0\" y=\"0\" fill=\"black\"/>" << std::endl;
}

void footer(){
	svg << "</svg>" << std::endl;
}

int main(int argc, char* argv[]){
	
	if(argc != 2){
		fprintf(stderr, "Usage: projection <filename>\n");
		exit(0);
	}

	svg.open("projection_result.svg");
	if(svg.fail()){
		fprintf(stderr, "Could not open results!\n");
		exit(0);
	}

	in_file.open(argv[1]);
	if(in_file.fail()){
		fprintf(stderr, "Could not open input file!\n");
		exit(0);
	}
	
	header();
	footer();

	svg.close();
	in_file.close();

	std::cout << "Hello World!" << std::endl;

	return 0;
}

