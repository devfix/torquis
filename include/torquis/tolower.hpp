//
// Created by core on 05/03/2021.
//

#ifndef TORQUIS_HPP
#error "Do not include this file directly, include tho torquis.hpp"
#endif

#ifndef TORQUIS_TOLOWER_HPP
#define TORQUIS_TOLOWER_HPP

namespace torquis
{

	/**
	 * \brief converts the ascii-characters of a string to their lower case inplace
	 * \tparam CharT underlying character type of the string
	 * \param str input string
	 * \param len input string length
	 */
	template<typename CharT>
	void tolower(CharT* str, std::size_t len)
	{
		static_assert(!std::is_const_v<CharT>, "no const type allowed");
		for (; len--; str++) { *str = std::tolower(*str); }
	}

	/**
	 * \brief converts the ascii-characters of a string to their lower case inplace
	 * \tparam CharT underlying character type of the string
	 * \param str input string
	 */
	template<typename CharT>
	void tolower(std::basic_string<CharT>& str)
	{
		if (!str.empty()) { tolower(&str[0], str.length()); }
	}

	/**
	 * \brief converts the ascii-characters of a string to their lower case and returns it
	 * \tparam CharT underlying character type of the string
	 * \param str input string
	 */
	template<typename CharT>
	std::basic_string<CharT> tolowerc(const std::basic_string_view<CharT> str)
	{
		std::basic_string<CharT> copy(str);
		tolower(copy);
		return copy;
	}

	/**
	 * \brief converts the ascii-characters of a string to their lower case and returns it
	 * \tparam CharT underlying character type of the string
	 * \param str input string
	 */
	template<typename CharT>
	std::basic_string<CharT> tolowerc(const std::basic_string<CharT>& str)
	{
		std::basic_string<CharT> copy(str);
		tolower(copy);
		return copy;
	}

	/**
	 * \brief converts the ascii-characters of a string to their lower case and returns it
	 * \tparam CharT underlying character type of the string
	 * \param str input string
	 */
	template<typename CharT>
	std::basic_string<CharT> tolowerc(const CharT* str)
	{
		std::basic_string<CharT> copy(str);
		tolower(copy);
		return copy;
	}

}

#endif //TORQUIS_TOLOWER_HPP
