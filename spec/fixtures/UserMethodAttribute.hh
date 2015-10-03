<?hh //strict

namespace attribute\fixtures;

use attribute\MethodAttribute;

final class UserMethodAttribute extends MethodAttribute
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
