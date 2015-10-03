<?hh //strict

namespace attribute;

use ReflectionClass;

interface Attribute
{
    public static function name() : string;
    public static function reflection() : ReflectionClass;
    public static function fromParameters(array<mixed> $parameters) : this;
}
