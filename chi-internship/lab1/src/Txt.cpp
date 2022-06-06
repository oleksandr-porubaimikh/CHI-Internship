#include <fstream>
#include <utility>

#include "Txt.h"

l1::Txt::Txt()
	: text(nullptr)
	, text_size(0u) 
{ }

l1::Txt::Txt(const std::string &filepath) {
	std::ifstream file(filepath);
	if (!file) {
		text_size = 0u;
		return;
	}

	size_t count = 0;
	std::string line;
	for (; std::getline(file, line); count++);

	text = new std::string[count];
	if (!text) {
		text_size = 0u;
		return;
	}

	file.clear();
	file.seekg(0);
	for (size_t x = 0; std::getline(file, line); x++) {
		text[x] = line;
	}

	text_size = count;
}

l1::Txt::Txt(const Txt &txt)
	: text_size(txt.size()) 
{
	text = new std::string[text_size];
	if (!text) {
		text_size = 0;
		return;
	}

	for (size_t x = 0; x < size(); x++) {
		text[x] = txt.text[x];
	}
}

l1::Txt::Txt(Txt &&txt) noexcept
	: text_size(std::exchange(txt.text_size, 0))
	, text(std::exchange(txt.text, nullptr)) 
{ }

l1::Txt::~Txt() {
	if (text) {
		delete[] text;
	}
}

l1::Txt &l1::Txt::operator =(const Txt &txt) {
	if (text) {
		delete[] text;
	}

	text_size = txt.size();
	text = new std::string[text_size];
	if (!text) {
		text_size = 0;
		return *this;
	}

	for (size_t x = 0; x < size(); x++) {
		text[x] = txt.text[x];
	}

	return *this;
}

l1::Txt &l1::Txt::operator =(Txt &&txt) noexcept {
  text = std::exchange(txt.text, nullptr);
  text_size = std::exchange(txt.text_size, 0u);

  return *this;
}

size_t l1::Txt::size() const {
	return text_size;
}