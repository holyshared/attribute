<?hh //strict

namespace attribute;

use ReflectionClass;

abstract class ClassAttribute implements Attribute
{

    public static function name() : string
    {
        return preg_replace('/^(\w+\\\\)+/', '', static::class);
    }

    public static function reflection() : ReflectionClass
    {
        return new ReflectionClass(static::class);
    }

    public static function findByClassName(string $className) : ?this
    {
        return static::findByClass(new ReflectionClass($className));
    }

    public static function findByClass(ReflectionClass $class) : ?this
    {
        $finder = new AttributeFinder($class);
        $parameters = $finder->findClassAttribute(static::name());

        if ($parameters === null) {
            return null;
        }

        return static::reflection()->newInstanceArgs($parameters);
    }

}
