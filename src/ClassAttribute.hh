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
  
    public static function lookup(string $className) : ?this
    {
        $finder = new AttributeFinder($className);
        $parameters = $finder->findClassAttribute(static::name());

        if ($parameters === null) {
            return null;
        }

        return static::reflection()->newInstanceArgs($parameters);
    }
}
