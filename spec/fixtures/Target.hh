<?hh //strict

namespace attribute\fixtures;

<<UserClassAttribute('text')>>
final class Target
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
