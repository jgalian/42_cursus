#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>

class Point
{
	private:
		int		_x;
		int		_y;
	public:
		int		getX(void) const { return (this->_x); }
		int		getY(void) const { return (this->_y); }
		void	printCoords(void) const { std::cout << this->_x << ", " << this->_y << std::endl; }
		void	setCoords(int x, int y) { this->_x = x; this->_y = y;}
};

#endif /* *********************************************************** POINT_H */
