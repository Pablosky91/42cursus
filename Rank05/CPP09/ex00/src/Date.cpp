#include "Date.hpp"
#include <iomanip>

//DEFAULT CONSTRUCTOR

Date::Date(): _day(0), _month(0), _year(0)
{
}

//COPY CONSTRUCTOR

Date::Date(const Date &other)
{
	*this = other;
}

//DESTRUCTOR

Date::~Date()
{
}

//COPY ASSIGNMENT OPERATOR

Date	&Date::operator =(const Date &other)
{
	if (this != &other)
	{
		_day = other._day;
		_month = other._month;
		_year = other._year;
	}
	return (*this);
}

//GETTERS

int		Date::getDay() const
{
	return (_day);
}

int		Date::getMonth() const
{
	return (_month);
}

int		Date::getYear() const
{
	return (_year);
}

//SETTERS

void	Date::setDay(int day)
{
	_day = day;
}

void	Date::setMonth(int month)
{
	_month = month;
}

void	Date::setYear(int year)
{
	_year = year;
}

//COMPARISON OPERATORS

bool	Date::operator ==(const Date &other) const
{
	return (_day == other._day && _month == other._month && _year == other._year);
}

bool	Date::operator !=(const Date &other) const
{
	return (!operator ==(other));
}

bool	Date::operator <(const Date &other) const
{
	if (_year != other._year)
		return (_year < other._year);
	if (_month != other._month)
		return (_month < other._month);
	return (_day < other._day);
}

bool	Date::operator >(const Date &other) const
{
	return (!operator <=(other));
}

bool	Date::operator <=(const Date &other) const
{
	return (operator <(other) || operator ==(other));
}

bool	Date::operator >=(const Date &other) const
{
	return (!operator <(other));
}

//STREAM OPERATORS

std::ostream	&operator <<(std::ostream &os, const Date &date)
{
	os << date.getYear() << "-";
	os << std::setfill('0') << std::setw(2) << date.getMonth() << "-";
	os << std::setfill('0') << std::setw(2) << date.getDay();
	return (os);
}

std::istream	&operator >>(std::istream &is, Date &date)
{
	int		year;
	char	dash1;
	int		month;
	char	dash2;
	int		day;

	is >> year >> dash1 >> month >> dash2 >> day;

	if (is.eof())
		return (is);
	if (dash1 != '-' || dash2 != '-')
		throw std::runtime_error("Invalid date format: expected yyyy-mm-dd");

	date.setYear(year);
	date.setMonth(month);
	date.setDay(day);

	date.checkValid();

	return (is);
}

//PUBLIC MEMBER FUNCTIONS

void	Date::checkValid() const
{
	bool	isLeapYear;
	if (_month <= 0 || _month > 12)
		throw std::runtime_error("Invalid date: month must be between 1 and 12");
	switch (_month)
	{
	case 2:
		isLeapYear = (!(_year % 4) && (_year % 100)) || !(_year % 400);
		if (!isLeapYear && (_day <= 0 || _day > 28))
			throw std::runtime_error("Invalid date: day must be between 1 and 28");
		if (isLeapYear && (_day <= 0 || _day > 29))
			throw std::runtime_error("Invalid date: day must be between 1 and 29");
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (_day <= 0 || _day > 30)
			throw std::runtime_error("Invalid date: day must be between 1 and 30");
		break;
	default:
		if (_day <= 0 || _day > 31)
			throw std::runtime_error("Invalid date: day must be between 1 and 31");
		break;
	}
}
