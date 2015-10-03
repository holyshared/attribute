<?hh //strict

namespace attribute;

use ReflectionClass;
use ReflectionMethod;

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

    public function findMethodAttribute(string $attrName) : MethodAttributeParameters
    {
        foreach ($this->class->getMethods() as $method) {
            $attributes = new ImmMap($method->getAttributes());

            if ($attributes->contains($attrName) === false) {
                continue;
            }
            yield $method->getName() => new ImmVector($attributes->at($attrName));
        }
    }

}
