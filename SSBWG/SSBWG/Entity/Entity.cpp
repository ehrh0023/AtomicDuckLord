#include "Entity.h"

Entity::Entity::Entity(float posX,float posY,float width,float height)
	:body(posX, posY, width, height),
	velocity(0, 0),
	col(new Collision::AABBCollider(body, this)),
	remove(false),
	group(Group::none),
	health(100),
	ghost(false)
{
	clearCollisionData();
}

Entity::Entity::Entity(Rect rectBody)
	:body(rectBody),
	velocity(0, 0),
	col(new Collision::AABBCollider(body, this)),
	remove(false),
	group(Group::none),
	health(100),
	ghost(false)
{
	clearCollisionData();
}

void Entity::Entity::update()
{
	body.setTopLeft(body.getTopLeft() + velocity);
}

void Entity::Entity::draw(System::Window& window)
{
	window.drawRect(body);
}

void Entity::Entity::clearCollisionData()
{
	col->clearCollisionData();
}

void Entity::Entity::collideWith(Entity* other)
{
	col->collide(other->col);
}

bool Entity::Entity::containsPoint(Vector2f point)
{
	return body.containsPoint(point);
}

bool Entity::Entity::canOverlap(Entity* otherEntity)
{
	return !isGhost() && !otherEntity->isGhost() && (group != otherEntity->group);
}

bool Entity::Entity::overlaps(Entity* otherEntity)
{
	return body.overlaps(otherEntity->getBody());
}

Vector2f Entity::Entity::getVelocity() const
{
	return velocity;
}

float Entity::Entity::getMaxSpeed() const
{
	return maxSpeed;
}

bool Entity::Entity::isGhost() const
{
	return ghost;
}

bool Entity::Entity::shouldRemoveThis() const
{
	return remove;
}

Rect Entity::Entity::getBody() const
{
	return body;
}

Vector2f Entity::Entity::getPosition() const
{
	return body.getTopLeft();
}

Vector2f Entity::Entity::getCenter() const
{
	return body.getCenter();
}

float Entity::Entity::getWidth() const
{
	return body.getWidth();
}

float Entity::Entity::getHeight() const
{
	return body.getHeight();
}

Vector2f Entity::Entity::setVelocity(Vector2f vel)
{
	velocity = vel;
	return vel;
}

float Entity::Entity::setMaxSpeed(float speed)
{
	maxSpeed = speed;
	return speed;
}

bool Entity::Entity::setGhost(bool isGhost)
{
	ghost = isGhost;
	return ghost;
}

void Entity::Entity::removeThis()
{
	remove = true;
}

Rect Entity::Entity::setBody(Rect newBody)
{
	body = newBody;
	return newBody;
}

Vector2f Entity::Entity::setPosition(Vector2f position)
{
	body.setTopLeft(position);
	return position;
}

Vector2f Entity::Entity::setCenter(Vector2f position)
{
	body.setCenter(position);
	return position;
}

float Entity::Entity::setWidth(float width)
{
	body.setWidth(width);
	return width;
}

float Entity::Entity::setHeight(float height)
{
	body.setHeight(height);
	return height;
}

Vector2f Entity::Entity::getHeading()
{
	return heading;
}


Entity::Group::Group Entity::Entity::getGroup()
{
	return group;
}


float Entity::Entity::takeDamage(float damage)
{
	health -= damage;

	if(health <= 0)
		removeThis();

	return health;
}

float Entity::Entity::getHealth()
{
	return health;
}


void Entity::Entity::collide(Entity* entity)
{
	col->collide(entity->col);
}
