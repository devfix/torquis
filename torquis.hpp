//
// Created by core on 03/02/2021.
//

#ifndef TORQUIS_HPP
#define TORQUIS_HPP

#include <string>
#include <string_view>

namespace torquis
{
	/**
	 * \brief splits a string by a single delim character
	 * \tparam CharT underlying character type of the string
	 * \param sv input string
	 * \param delim separator character
	 */
	template<typename CharT>
	std::vector<std::basic_string_view<CharT>> split(std::basic_string_view<CharT> sv, CharT delim)
	{
		std::vector<std::basic_string_view<CharT>> parts;
		std::size_t prev = 0, curr;
		do
		{
			curr = sv.find(delim, prev);
			if (curr == std::string::npos) { parts.push_back(sv.substr(prev)); }
			else { parts.push_back(sv.substr(prev, curr - prev)); }
			prev = curr + 1;
		} while (curr != std::string::npos);
		return parts;
	}

	/**
	 * \brief splits a string by a delim string
	 * \tparam CharT underlying character type of the string
	 * \param sv input string
	 * \param delim separator character
	 */
	template<typename CharT>
	std::vector<std::basic_string_view<CharT>> split(std::basic_string_view<CharT> sv, std::basic_string_view<CharT> delim)
	{
		std::vector<std::basic_string_view<CharT>> parts;
		if (delim.length())
		{
			std::size_t prev = 0, curr;
			do
			{
				curr = sv.find(delim, prev);
				if (curr == std::string::npos) { parts.push_back(sv.substr(prev)); }
				else { parts.push_back(sv.substr(prev, curr - prev)); }
				prev = curr + delim.length();
			} while (curr != std::string::npos && prev <= sv.length());
		}
		else
		{
			for (std::size_t i = 0; i < sv.length(); i++)
			{
				parts.push_back(sv.substr(i, 1));
			}
		}
		return parts;
	}
}

#endif //TORQUIS_HPP
