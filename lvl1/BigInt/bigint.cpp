/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:47:58 by eric              #+#    #+#             */
/*   Updated: 2025/09/29 16:34:18 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

void bigint::remove_leading_zero()
{
	while (_value.size() > 1 &&_value[0] == '0')
		_value.erase(0, 1);
}

bigint bigint::operator+(const bigint& src) const
{
	std::string a = _value;
	std::string b = src._value;
	std::string result = "";

	int carry = 0;
	int i = a.size() -1;
	int j = b.size() - 1;

	while (i >=0 || j >= 0 || carry)
	{
		int sum = carry;
		if (i >= 0)
			sum += a[i--] - '0';
		if (j >= 0)
			sum += b[j--] - '0';
		result.insert(result.begin(), (sum% 10) + '0');
		carry = sum / 10;
	}
	bigint res;
	res._value = result;
	res.remove_leading_zero();
	return (res);
}

bigint bigint::operator<<(size_t shift) const
{
	bigint res(*this);
	res <<= shift;
	return res;
}

bigint& bigint::operator<<=(size_t shift)
{
	if (!(_value.size() == 1 && _value[0] == '0'))
		_value.append(shift, '0');
	return *this;
}

bigint bigint::operator>>(size_t shift) const
{
	bigint res(*this);
	res >>= shift;
	return res;
}

bigint& bigint::operator>>=(size_t shift)
{
	if (shift >= _value.length())
		_value = "0";
	else
		_value = _value.substr(0, _value.length() - shift);
	remove_leading_zero();
	return *this;
}

// Comparaison pour trie
bool bigint::operator<(const bigint& src) const
{
	if (_value.length() != src._value.length())
		return _value.length() < src._value.length();
	return _value < src._value;
}

bigint& bigint::operator++()
{
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint temp = *this;
	++(*this);
	return *this;
}
