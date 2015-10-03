<?hh //strict

namespace attribute\fixtures;

use attribute\ClassAttribute;

final class UserClassAttribute extends ClassAttribute
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
