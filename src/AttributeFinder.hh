<?hh //strict

namespace attribute;

use ReflectionClass;
use ReflectionMethod;
use Generator;

final class AttributeFinder
{

    private ReflectionClass $class;

    public function __construct(string $className)
    {
        $this->class = new ReflectionClass($className);
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
