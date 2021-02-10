/*
 *
 *  _______  _____   ______  _____  _     _ _____ _______
 *     |    |     | |_____/ |   __| |     |   |   |______
 *     |    |_____| |    \_ |____\| |_____| __|__ ______|
 *
 *                    c++ string library
 *
 *                        version 0.2
 *            written by Tristan Krause aka. devfix
 *              https://github.com/devfix/torquis
 *
 */

#ifndef TORQUIS_HPP
#define TORQUIS_HPP

#include <string>
#include <string_view>
#include <vector>

namespace torquis
{

	/*
	 * function group: split
	 */

	/**
	 * \brief splits a string by a single delim character
	 * \tparam CharT underlying character type of the string
	 * \param str input string
	 * \param delim separator character
	 */
	template<typename CharT>
	[[nodiscard]] std::vector<std::basic_string_view<CharT>> split(const std::basic_string_view<CharT> str, const CharT delim)
	{
		std::vector<std::basic_string_view<CharT>> parts;
		std::size_t prev = 0, curr;
		do
		{
			curr = str.find(delim, prev);
			if (curr == std::string::npos) { parts.push_back(str.substr(prev)); }
			else { parts.push_back(str.substr(prev, curr - prev)); }
			prev = curr + 1;
		} while (curr != std::string::npos);
		return parts;
	}

	/**
	 * \brief splits a string by a delim string
	 * \tparam CharT underlying character type of the string
	 * \param str input string
	 * \param delim separator character
	 */
	template<typename CharT>
	[[nodiscard]] std::vector<std::basic_string_view<CharT>> split(const std::basic_string_view<CharT> str,
		const std::basic_string_view<CharT> delim)
	{
		std::vector<std::basic_string_view<CharT>> parts;
		if (delim.length())
		{
			std::size_t prev = 0, curr;
			do
			{
				curr = str.find(delim, prev);
				if (curr == std::string::npos) { parts.push_back(str.substr(prev)); }
				else { parts.push_back(str.substr(prev, curr - prev)); }
				prev = curr + delim.length();
			} while (curr != std::string::npos && prev <= str.length());
		}
		else
		{
			for (std::size_t i = 0; i < str.length(); i++)
			{
				parts.push_back(str.substr(i, 1));
			}
		}
		return parts;
	}

	/**
	 * \brief splits a string by a delim string
	 * \tparam CharT underlying character type of the string
	 * \param sv input string
	 * \param delim separator character
	 */
	template<typename CharT>
	[[nodiscard]] std::vector<std::basic_string_view<CharT>> split(const std::basic_string_view<CharT> str,
		const std::basic_string<CharT>& delim)
	{
		return split<CharT>(std::basic_string_view<CharT>(str), std::basic_string_view<CharT>(delim));
	}

	/**
	 * \brief splits a string by a delim string
	 * \tparam CharT underlying character type of the string
	 * \param sv input string
	 * \param delim separator character
	 */
	template<typename CharT>
	[[nodiscard]] std::vector<std::basic_string_view<CharT>> split(const std::basic_string_view<CharT> str, const CharT* delim)
	{
		return split<CharT>(std::basic_string_view<CharT>(str), std::basic_string_view<CharT>(delim));
	}

	/**
	 * \brief splits a string by a delim string
	 * \tparam CharT underlying character type of the string
	 * \param sv input string
	 * \param delim separator character
	 */
	template<typename CharT>
	[[nodiscard]] std::vector<std::basic_string_view<CharT>> split(const std::basic_string<CharT>& str,
		const std::basic_string_view<CharT> delim)
	{
		return split<CharT>(std::basic_string_view<CharT>(str), std::basic_string_view<CharT>(delim));
	}

	/**
	 * \brief splits a string by a delim string
	 * \tparam CharT underlying character type of the string
	 * \param sv input string
	 * \param delim separator character
	 */
	template<typename CharT>
	[[nodiscard]] std::vector<std::basic_string_view<CharT>> split(const std::basic_string<CharT>& str,
		const std::basic_string<CharT>& delim)
	{
		return split<CharT>(std::basic_string_view<CharT>(str), std::basic_string_view<CharT>(delim));
	}

	/**
	 * \brief splits a string by a delim string
	 * \tparam CharT underlying character type of the string
	 * \param sv input string
	 * \param delim separator character
	 */
	template<typename CharT>
	[[nodiscard]] std::vector<std::basic_string_view<CharT>> split(const std::basic_string<CharT>& str, const CharT* delim)
	{
		return split<CharT>(std::basic_string_view<CharT>(str), std::basic_string_view<CharT>(delim));
	}

	/**
	 * \brief splits a string by a delim string
	 * \tparam CharT underlying character type of the string
	 * \param sv input string
	 * \param delim separator character
	 */
	template<typename CharT>
	[[nodiscard]] std::vector<std::basic_string_view<CharT>> split(const CharT* str, const std::basic_string_view<CharT> delim)
	{
		return split<CharT>(std::basic_string_view<CharT>(str), std::basic_string_view<CharT>(delim));
	}

	/**
	 * \brief splits a string by a delim string
	 * \tparam CharT underlying character type of the string
	 * \param sv input string
	 * \param delim separator character
	 */
	template<typename CharT>
	[[nodiscard]] std::vector<std::basic_string_view<CharT>> split(const CharT* str, const std::basic_string<CharT>& delim)
	{
		return split<CharT>(std::basic_string_view<CharT>(str), std::basic_string_view<CharT>(delim));
	}

	/**
	 * \brief splits a string by a delim string
	 * \tparam CharT underlying character type of the string
	 * \param sv input string
	 * \param delim separator character
	 */
	template<typename CharT>
	[[nodiscard]] std::vector<std::basic_string_view<CharT>> split(const CharT* str, const CharT* delim)
	{
		return split<CharT>(std::basic_string_view<CharT>(str), std::basic_string_view<CharT>(delim));
	}



	/*
	 * function group: join
	 */

	/**
	 * \brief takes all strings in a vector and joins them into one string
	 * \tparam CharT underlying character type of the string
	 * \tparam StringT type of the string, must use CharT as character type
	 * \param vec vector of strings
	 * \param delim delimiter string between each string
	 */
	template<typename CharT, typename StringT>
	[[nodiscard]] std::basic_string<CharT> join(const std::vector<StringT>& vec, const std::basic_string_view<CharT> delim)
	{
		if (vec.empty()) { return {}; }
		else
		{
			std::basic_string<CharT> str(vec[0]);
			for (std::size_t i = 1; i < vec.size(); i++)
			{
				str += delim;
				str += vec[i];
			}
			return str;
		}
	}

	/**
	 * \brief takes all strings in a vector and joins them into one string
	 * \tparam CharT underlying character type of the string
	 * \tparam StringT type of the string, must use CharT as character type
	 * \param vec vector of strings
	 * \param delim delimiter string between each string
	 */
	template<typename CharT, typename StringT>
	[[nodiscard]] std::basic_string<CharT> join(const std::vector<StringT>& vec, const std::basic_string<CharT>& delim)
	{
		return join<CharT, StringT>(vec, std::basic_string_view<CharT>(delim));
	}

	/**
	 * \brief takes all strings in a vector and joins them into one string
	 * \tparam CharT underlying character type of the string
	 * \tparam StringT type of the string, must use CharT as character type
	 * \param vec vector of strings
	 * \param delim delimiter string between each string
	 */
	template<typename CharT, typename StringT>
	[[nodiscard]] std::basic_string<CharT> join(const std::vector<StringT>& vec, const CharT* delim)
	{
		return join<CharT, StringT>(vec, std::basic_string_view<CharT>(delim));
	}

	/*
	 * function group: tolower
	 */

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

	/*
	 * function group: toupper
	 */

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

#endif //TORQUIS_HPP
