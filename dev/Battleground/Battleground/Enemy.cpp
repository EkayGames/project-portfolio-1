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

//Print correct enemy based on type
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
            -==-            
           -#%%#-           
       --===@@@@==---       
     -==-==*@@@@*==-==-     
     ======+@#%@*======-    
     =======%++@=======-    
      :--====@@======-:     
       -#*+==##==+++-       
      -#==##-==-*##*--      
       *@=##-@--##+--:      
       *@=##-+@-##+@#       
  =*  -%@=##-@#-##+@#   ==  
=@@@@@@@-###-+*-###-@---@=--
=+%@---:-##*-==-*##-=+++@=%=
 :-      :-=--------    -#*-
         :====----          
          --==---           
           --===-           
          -==--==           
      -@--#-=-:-=- -@-      
     --@-@@@=----**%@---    
     ------------------     )";
        break;
    case EnemyType::Unicorn:
        std::cout << R"(
                              /
                   __       //
                   -\= \=\ //
                 --=_\=---//=--
               -_==/  \/ //\/--
                ==/   /O   O\==--
   _ _ _ _     /_/    \  ]  /--
  /\ ( (- \    /       ] ] ]==-
 (\ _\_\_\-\__/     \  (,_,)--
(\_/                 \     \-
\/      /       (   ( \  ] /)
/      (         \   \_ \./ )
(       \         \      )  \
(       /\_ _ _ _ /---/ /\_  \
 \     / \     / ____/ /   \  \
  (   /   )   / /  /__ )   (  )
  (  )   / __/ '---`       / /
  \  /   \ \             _/ /
  ] ]     )_\_         /__\/
  /_\     ]___\
 (___)
)";
        break;
    }
}
void Enemy::SetEnemyType(EnemyType type)
{
    _enemyType = type;
}

//Getter for enemy type
EnemyType Enemy::GetEnemyType() const
{
    return _enemyType;
}
