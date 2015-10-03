<?hh //strict

namespace attribute;

use ReflectionClass;
use ReflectionMethod;
use Generator;

final class AttributeFinder
{

    public function __construct(
        private ReflectionClass $class
    )
    {
    }

    public static function fromClassName(string $name) : this
    { 
        return new AttributeFinder(new ReflectionClass($name));
    }

    public function findClassAttribute(string $attrName) : ?array<mixed>
    {
        $attributes = new ImmMap($this->class->getAttributes());

        if ($attributes->contains($attrName) === false) {
            return null;
        }
        return $attributes->at($attrName);
    }

    public function findMethodAttribute(string $attrName) : Generator<string, array<mixed>, void>
    {
        foreach ($this->class->getMethods() as $method) {
            $attributes = new ImmMap($method->getAttributes());

            if ($attributes->contains($attrName) === false) {
                continue;
            }
            yield $method->getName() => $attributes->at($attrName);
        }
    }

}
