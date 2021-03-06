//
// Created by core on 05/03/2021.
//

#ifndef TORQUIS_INCLUDE_GUARD
#error "Do not include this file directly, include tho torquis.hpp"
#endif

#ifndef TORQUIS_SPLIT_HPP
#define TORQUIS_SPLIT_HPP

namespace torquis
{
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

}

#endif //TORQUIS_SPLIT_HPP
