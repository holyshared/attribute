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

    <<UserMethodAttribute('text')>>
    public function getDescription() : string
    {
        return $this->description;
    }

}
