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

    public static function findByClassName(string $className) : ImmMap<string, MethodAttribute>
    {
        return static::findByReflection(new ReflectionClass($className));
    }

    public static function findByReflection(ReflectionClass $reflection) : ImmMap<string, MethodAttribute>
    {
        $result = Map {};
        $finder = new AttributeFinder($reflection);
        $attributes = $finder->findMethodAttribute(static::name());

        foreach ($attributes as $key => $parameters) {
            $attribute = static::reflection()->newInstanceArgs($parameters);
            $result->set($key, $attribute);
        }

        return $result->toImmMap();
    }

}
