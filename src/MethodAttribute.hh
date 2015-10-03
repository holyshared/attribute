<?hh //strict

namespace attribute;

use ReflectionClass;
use ReflectionMethod;

abstract class MethodAttribute implements Attribute
{

    public static function name() : string
    {
        return preg_replace('/^(\w+\\\\)+/', '', static::class);
    }

    public static function reflection() : ReflectionClass
    {
        return new ReflectionClass(static::class);
    }

    public static function findByClassName(string $className) : MethodAttributeMap
    {
        return static::findByClass(new ReflectionClass($className));
    }

    public static function findByClass(ReflectionClass $class) : MethodAttributeMap
    {
        $result = Map {};
        $finder = new AttributeFinder($class);
        $attributes = $finder->findMethodAttribute(static::name());

        foreach ($attributes as $key => $parameters) {
            $attribute = static::reflection()->newInstanceArgs($parameters);
            $result->set($key, $attribute);
        }

        return $result->toImmMap();
    }

    public static function findByMethod(ReflectionMethod $method) : ?MethodAttribute
    {
        $parameters = $method->getAttribute(static::name());

        if ($parameters === null) {
            return null;
        }

        return static::reflection()->newInstanceArgs($parameters);
    }

}
