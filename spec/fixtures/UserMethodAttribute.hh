<?hh //strict

namespace attribute\fixtures;

use attribute\MethodAttribute;

final class UserMethodAttribute extends MethodAttribute
{

    public function __construct(
        private string $name,
        private int $quantity
    )
    {
    }

    public function getName() : string
    {
        return $this->name;
    }

    public function getQuantity() : int
    {
        return $this->quantity;
    }

}
