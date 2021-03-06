//
// Created by core on 05/03/2021.
//

#ifndef TORQUIS_INCLUDE_GUARD
#error "Do not include this file directly, include the torquis.hpp"
#endif

#ifndef TORQUIS_TOUPPER_HPP
#define TORQUIS_TOUPPER_HPP

namespace torquis
{

	/**
	 * \brief converts the ascii-characters of a string to their upper case inplace
	 * \tparam CharT underlying character type of the string
	 * \param str input string
	 * \param len input string length
	 */
	template<typename CharT>
	void toupper(CharT* str, std::size_t len)
	{
		static_assert(!std::is_const_v<CharT>, "no const type allowed");
		for (; len--; str++) { *str = std::toupper(*str); }
	}

	/**
	 * \brief converts the ascii-characters of a string to their upper case inplace
	 * \tparam CharT underlying character type of the string
	 * \param str input string
	 */
	template<typename CharT>
	void toupper(std::basic_string<CharT>& str)
	{
		if (!str.empty()) { toupper(&str[0], str.length()); }
	}

	/**
	 * \brief converts the ascii-characters of a string to their upper case and returns it
	 * \tparam CharT underlying character type of the string
	 * \param str input string
	 */
	template<typename CharT>
	std::basic_string<CharT> toupperc(const std::basic_string_view<CharT> str)
	{
		std::basic_string<CharT> copy(str);
		toupper(copy);
		return copy;
	}

	/**
	 * \brief converts the ascii-characters of a string to their upper case and returns it
	 * \tparam CharT underlying character type of the string
	 * \param str input string
	 */
	template<typename CharT>
	std::basic_string<CharT> toupperc(const std::basic_string<CharT>& str)
	{
		std::basic_string<CharT> copy(str);
		toupper(copy);
		return copy;
	}

	/**
	 * \brief converts the ascii-characters of a string to their upper case and returns it
	 * \tparam CharT underlying character type of the string
	 * \param str input string
	 */
	template<typename CharT>
	std::basic_string<CharT> toupperc(const CharT* str)
	{
		std::basic_string<CharT> copy(str);
		toupper(copy);
		return copy;
	}

}

#endif //TORQUIS_TOUPPER_HPP
