//
// Created by core on 05/03/2021.
//

#ifndef TORQUIS_INCLUDE_GUARD
#error "Do not include this file directly, include the torquis.hpp"
#endif

#ifndef TORQUIS_JOIN_HPP
#define TORQUIS_JOIN_HPP

namespace torquis
{

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

}

#endif //TORQUIS_JOIN_HPP
