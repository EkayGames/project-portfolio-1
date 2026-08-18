#include "Powerup.h"

Powerup::Powerup(int pow)
{
	_power = static_cast<Power>(pow);
}

Powerup::Powerup(Power pow)
{
    _power = pow;
}

Powerup::~Powerup()
{
}

Powerup::Powerup(const Powerup& other) :
	_power(other._power)
{
}

Powerup& Powerup::operator=(const Powerup& other)
{
    if (this == &other)
    {
        return *this;
    }

    Powerup::operator=(other);

    _power = other._power;

    return *this;
}

void Powerup::PrintPower()
{
    switch (_power)
    {
    case Power::HealthUp:
        std::cout << "Increase Health by 5\n";
        break;
    case Power::DamageUp:
        std::cout << "Increase base damage by 1\n";
        break;
    case Power::LungeDamage:
        std::cout << "Lunge does double damage on win\n";
        break;
    case Power::BlockDamage:
        std::cout << "Block has a chance to stun enemy\n";
        break;
    case Power::DashDamage:
        std::cout << "Dash does half damage on tie\n";
    }
}

void Powerup::RerollDuplicates(Powerup* dupe)
{
    bool dupe = true;
    do
    {
        SetPower(Helper::RandomNumberGenerator(1, static_cast<int>(Power::Count) - 1));

        if (_power != dupe->GetPower())
        {
            dupe = false;
        }
    } while (dupe);
}

void Powerup::RerollDuplicates(Powerup* dupe, Powerup* dupe2)
{
    bool dupe = true;
    do
    {
        SetPower(Helper::RandomNumberGenerator(1, static_cast<int>(Power::Count) - 1));

        if (_power != dupe->GetPower() &&
            _power != dupe2->GetPower())
        {
            dupe = false;
        }
    } while (dupe);
}

Power Powerup::GetPower() const
{
    return _power;
}

void Powerup::SetPower(int pow)
{
    _power = static_cast<Power>(pow);
}
