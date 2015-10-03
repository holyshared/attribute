<?hh //strict

namespace example;

use attribute\MethodAttribute;

final class MyMethodAttribute extends MethodAttribute
{

    public function __construct(
        private string $description
    )
    {
    }

    public function getDescription() : string
    {
        return $this->description;
    }

}
