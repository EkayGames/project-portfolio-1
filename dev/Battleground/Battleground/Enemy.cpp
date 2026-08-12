#include "Enemy.h"

Enemy::Enemy(int health, int attack, int x, int y, EnemyType type) :
	Entity::Entity(health, attack, x, y)
{
    _enemyType = type;
}

Enemy::Enemy(int health, int attack, Position pos, EnemyType type) :
	Entity::Entity(health, attack, pos._xpos, pos._ypos)
{
    _enemyType = type;
}

Enemy::~Enemy()
{
}

Enemy::Enemy(const Enemy& other) :
    Entity::Entity(other)
{
    _enemyType = other._enemyType;
}

Enemy& Enemy::operator=(const Enemy& other)
{
    if (this == &other)
    {
        return *this;
    }

    Entity::operator=(other);

    _enemyType = other._enemyType;

    return *this;
}

void Enemy::PrintEnemy()
{
    switch (_enemyType)
    {
    case EnemyType::WizardShroom:
        std::cout << R"(
                 _
                / \
               / * \
              / * * \
             / * * * \
            / *__*__* \
            `-(-o^o-)-'
               \(_)/
                ) (
                """
)";
        break;
    case EnemyType::Skeleton:
        std::cout << R"(
                  .-.
                 (o.o)
                  |=|
                 __|__
               //.=|=.\\
              // .=|=. \\
              \\ .=|=. //
               \\(_=_)//
                (:| |:)
                 || ||
                 () ()
                 || ||
                 || ||
                ==' '==
)";
        break;
    case EnemyType::Hippie:
        std::cout << R"(
                  &&&&&          
              / &&    && \       
             && .+&    &. &&     
            &+;XX  o o  Xxx &    
            & .XX&  |  &XXX: &   
             &&&X+ --- +;: &&    
              &  &&& &&&&&&      
             & &&  &&&  +&x&     
              & & :& &; & &      
          &&  & & .& &; & &      
        &&  && &: .& &+ &  &&& &&
        $   &&&&   &:&   &     &&
         &&/    &&&&&&&&&&  \&& &
                &:..&  &         
                 &&.:&&          
                 &&&+ X&         
              &&&$; && & & &     
            && &  &&&&+ $& &&    
            &&&&&&&&&&&&&&&&&&   )";
        break;
    }
}
//Getter for enemy type
EnemyType Enemy::GetEnemyType() const
{
    return _enemyType;
}
