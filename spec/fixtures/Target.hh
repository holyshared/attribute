<?hh //strict

namespace attribute\fixtures;

<<UserClassAttribute('text')>>
final class Target
{

    public function __construct(
        private string $attribute
    )
    {
    }

    <<UserMethodAttribute('text', 100)>>
    public function attribute() : string
    {
        return $this->attribute;
    }

}
