//
// Created by core on 05/03/2021.
//

#ifndef TORQUIS_INCLUDE_GUARD
#error "Do not include this file directly, include the torquis.hpp"
#endif

#ifndef TORQUIS_REPLACE_HPP
#define TORQUIS_REPLACE_HPP

namespace torquis
{
	template<typename CharT>
	using sv = std::basic_string_view<CharT>;

	template<typename CharT>
	using cs = const CharT*;

	template<typename CharT>
	using s = std::basic_string<CharT>;

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const sv<CharT> str, const sv<CharT> oldval, const sv<CharT> newval)
	{
		std::basic_string<CharT> repl;

		std::size_t lpos = 0;
		while (lpos != str.npos)
		{
			auto pos = str.find(oldval, lpos);
			repl += str.substr(lpos, pos - lpos);
			if (pos != str.npos)
			{
				repl += newval;
				lpos = pos + oldval.length();
			}
			else { lpos = str.npos; }
		}

		return repl;
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const sv<CharT> str, const sv<CharT> oldval, const cs<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const sv<CharT> str, const sv<CharT> oldval, const s<CharT>& newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const sv<CharT> str, const cs<CharT> oldval, const sv<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const sv<CharT> str, const cs<CharT> oldval, const cs<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const sv<CharT> str, const cs<CharT> oldval, const s<CharT>& newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const sv<CharT> str, const s<CharT>& oldval, const sv<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const sv<CharT> str, const s<CharT>& oldval, const cs<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const sv<CharT> str, const s<CharT>& oldval, const s<CharT>& newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const cs<CharT> str, const sv<CharT> oldval, const sv<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const cs<CharT> str, const sv<CharT> oldval, const cs<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const cs<CharT> str, const sv<CharT> oldval, const s<CharT>& newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const cs<CharT> str, const cs<CharT> oldval, const sv<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const cs<CharT> str, const cs<CharT> oldval, const cs<CharT> newval)
	{
		return replace(sv<CharT>{str}, sv<CharT>{oldval}, sv<CharT>{newval});
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const cs<CharT> str, const cs<CharT> oldval, const s<CharT>& newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const cs<CharT> str, const s<CharT>& oldval, const sv<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const cs<CharT> str, const s<CharT>& oldval, const cs<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const cs<CharT> str, const s<CharT>& oldval, const s<CharT>& newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const s<CharT>& str, const sv<CharT> oldval, const sv<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const s<CharT>& str, const sv<CharT> oldval, const cs<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const s<CharT>& str, const sv<CharT> oldval, const s<CharT>& newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const s<CharT>& str, const cs<CharT> oldval, const sv<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const s<CharT>& str, const cs<CharT> oldval, const cs<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const s<CharT>& str, const cs<CharT> oldval, const s<CharT>& newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const s<CharT>& str, const s<CharT>& oldval, const sv<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const s<CharT>& str, const s<CharT>& oldval, const cs<CharT> newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}

	template<typename CharT>
	[[nodiscard]] s<CharT> replace(const s<CharT>& str, const s<CharT>& oldval, const s<CharT>& newval)
	{
		return replace(sv<CharT>(str), sv<CharT>(oldval), sv<CharT>(newval));
	}
}

#endif //TORQUIS_REPLACE_HPP
