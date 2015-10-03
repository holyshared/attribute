<?hh //strict

namespace example;

use attribute\ClassAttribute;

final class MyClassAttribute extends ClassAttribute
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
