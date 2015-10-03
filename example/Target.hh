<?hh //strict

namespace example;

<<MyClassAttribute('bb')>>
class Target
{

    <<MyMethodAttribute('aa')>>
    public function example() : void
    {
    }

}
