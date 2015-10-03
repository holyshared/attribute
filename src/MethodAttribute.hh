<?hh //strict

namespace attribute;

use ReflectionClass;

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

    public static function lookup(string $className) : ImmMap<string, MethodAttribute>
    {
        $result = Map {};
        $finder = new AttributeFinder($className);
        $attributes = $finder->findMethodAttribute(static::name());

        foreach ($attributes as $key => $parameters) {
            $attribute = static::reflection()->newInstanceArgs($parameters);
            $result->set($key, $attribute);
        }

        return $result->toImmMap();
    }
}
