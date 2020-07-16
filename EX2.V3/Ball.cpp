#include "Ball.h"

// TODO: when making the ball into a shape add a loop 
void Ball::set( Point& center) {
	
	m_ballP = { (center )};
}

void Ball::moveBall() {
	if (m_ballP.getX() + m_ballP.getXDirection() > FIELD_MAX_X || m_ballP.getX() + m_ballP.getXDirection() < FIELD_MIN_X) {
		m_ballP.changeXDirection();
	}
	 if (m_ballP.getY() + m_ballP.getYDirection() > FIELD_MAX_Y || m_ballP.getY() + m_ballP.getYDirection() < FIELD_MIN_Y) {
		m_ballP.changeYDirection();
	}
	m_ballP.draw(' ');
	m_ballP.move();
	if (field.isCoordEmpty(m_ballP.getX(), m_ballP.getY()))
		m_ballP.draw();
}
void Ball::Rand_dir(){
	int rd = rand() % 2;
	if (rd == 0)
		this->m_ballP.setDirX(-1);
	else
		this->m_ballP.setDirX(1);

}