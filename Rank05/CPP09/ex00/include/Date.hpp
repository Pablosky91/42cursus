#ifndef DATE_HPP
# define DATE_HPP

#include <iostream>

class Date
{
	public:
		Date();
		Date(const Date &other);
		~Date();
		Date	&operator =(const Date &other);

		int		getDay() const;
		int		getMonth() const;
		int		getYear() const;

		void	setDay(int day);
		void	setMonth(int month);
		void	setYear(int year);

		bool	operator ==(const Date &other) const;
		bool	operator !=(const Date &other) const;
		bool	operator <(const Date &other) const;
		bool	operator >(const Date &other) const;
		bool	operator <=(const Date &other) const;
		bool	operator >=(const Date &other) const;

		void	checkValid() const;

	private:
		int		_day;
		int		_month;
		int		_year;
};

std::ostream	&operator <<(std::ostream &os, const Date &date);
std::istream	&operator >>(std::istream &is, Date &date);

#endif
