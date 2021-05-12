#pragma once

#include <string>
#include <iostream>
#include <utility>
#include <vector>

class token {
public:
	enum class kind { value, name, op };
	kind kind;
	
	double value{};
	std::string name;

	token(double value) : kind(kind::value), value(value) {}
	token(std::string name) : kind(kind::name), name(std::move(name)) {}
	token(enum kind kind, std::string name) : kind(kind), name(std::move(name)) {}

	friend std::ostream& operator<<(std::ostream &out, const token &t);
};


std::vector<token> read_tokens(std::istream &in);

