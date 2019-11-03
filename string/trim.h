/*
   Copyright (c) 2019 Andreas Fett.
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
   1. Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
   IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
   TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
   PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef STRING_TRIM_H
#define STRING_TRIM_H

#include <algorithm>
#include <cctype>
#include <string>

template <typename InputIt>
InputIt find_if_not_space(InputIt first, InputIt last)
{
	return std::find_if_not(first, last, [](int c) { return std::isspace(c); });
}

inline std::string ltrim(std::string const& s)
{
	return {find_if_not_space(begin(s), end(s)), end(s)};
}

inline std::string rtrim(std::string const& s)
{
	return {begin(s), find_if_not_space(rbegin(s), rend(s)).base()};
}

inline std::string trim(std::string const& s)
{
	auto begin = find_if_not_space(std::begin(s), std::end(s));
	return {begin, find_if_not_space(rbegin(s), decltype(rbegin(s))(begin)).base()};
}

#endif
