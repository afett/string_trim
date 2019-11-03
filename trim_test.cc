#include <cassert>

#include <string/trim.h>

int main()
{
	std::string empty;

	assert(trim(empty) == std::string());
	assert(ltrim(empty) == std::string());
	assert(rtrim(empty) == std::string());

	std::string one("a");
	assert(trim(one) == std::string("a"));
	assert(ltrim(one) == std::string("a"));
	assert(rtrim(one) == std::string("a"));

	std::string two("ab");
	assert(trim(two) == std::string("ab"));
	assert(ltrim(two) == std::string("ab"));
	assert(rtrim(two) == std::string("ab"));

	std::string one_space(" ");
	assert(trim(one_space) == std::string());
	assert(ltrim(one_space) == std::string());
	assert(rtrim(one_space) == std::string());

	std::string two_space("  ");
	assert(trim(two_space) == std::string());
	assert(ltrim(two_space) == std::string());
	assert(rtrim(two_space) == std::string());

	std::string one_space_front(" a");
	assert(trim(one_space_front) == std::string("a"));
	assert(ltrim(one_space_front) == std::string("a"));
	assert(rtrim(one_space_front) == std::string(" a"));

	std::string two_space_front("  a");
	assert(trim(two_space_front) == std::string("a"));
	assert(ltrim(two_space_front) == std::string("a"));
	assert(rtrim(two_space_front) == std::string("  a"));

	std::string one_space_back("a ");
	assert(trim(one_space_back) == std::string("a"));
	assert(ltrim(one_space_back) == std::string("a "));
	assert(rtrim(one_space_back) == std::string("a"));

	std::string two_space_back("a  ");
	assert(trim(two_space_back) == std::string("a"));
	assert(ltrim(two_space_back) == std::string("a  "));
	assert(rtrim(two_space_back) == std::string("a"));

	std::string one_space_both(" a ");
	assert(trim(one_space_both) == std::string("a"));
	assert(ltrim(one_space_both) == std::string("a "));
	assert(rtrim(one_space_both) == std::string(" a"));

	std::string two_space_both("  a  ");
	assert(trim(two_space_both) == std::string("a"));
	assert(ltrim(two_space_both) == std::string("a  "));
	assert(rtrim(two_space_both) == std::string("  a"));

	std::string foobar(" foobar ");
	assert(trim(foobar) == std::string("foobar"));
	assert(ltrim(foobar) == std::string("foobar "));
	assert(rtrim(foobar) == std::string(" foobar"));

	return 0;
}
