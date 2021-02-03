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

#endif //TORQUIS_HPP
