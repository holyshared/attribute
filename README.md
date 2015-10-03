attribute
====================

Attribute for Hack

[![Build Status](https://travis-ci.org/holyshared/attribute.svg?branch=master)](https://travis-ci.org/holyshared/attribute)
[![Dependency Status](https://www.versioneye.com/user/projects/560ff3b5a193340015000001/badge.svg?style=flat)](https://www.versioneye.com/user/projects/560ff3b5a193340015000001)

ClassAttribute
--------------------

```hack
<?hh //strict

namespace example;

use attribute\ClassAttribute;

final class Tag extends ClassAttribute
{

    public function __construct(
        private string $name
    )
    {
    }

    public function value() : string
    {
        return $this->name;
    }

}
```

```hack
<?hh //strict

namespace example;

<<Tag('important')>>
class TaggedTarget
{
}

```

```hack
<?hh //strict

namespace example;

$attribute = Tag::findByClassName(TaggedTarget::class);
var_dump($attribute->value()); // Tag attribute instance

$attribute = Tag::findByClass(new ReflectionClass(TaggedTarget::class));
var_dump($attribute->value()); // Tag attribute instance
```

MethodAttribute
--------------------

```hack
<?hh //strict

namespace example;

use attribute\MethodAttribute;

final class Tag extends MethodAttribute
{

    public function __construct(
        private string $name
    )
    {
    }

    public function value() : string
    {
        return $this->name;
    }

}
```

```hack
<?hh //strict

namespace example;

class TaggedTarget
{

    public function __construct(
        private string $name
    )
    {
    }

    <<Tag('important')>>
    public function getName() : string
    {
        return $this->name;
    }

}
```


```hack
<?hh //strict

namespace example;

$attributes = Tag::findByClassName(TaggedTarget::class);
var_dump($attributes->at('getName')->value()); // important

$attributes = Tag::findByClass(new ReflectionClass(TaggedTarget::class));
var_dump($attributes->at('getName')->value()); // important

$attribute = Tag::findByMethod(new ReflectionMethod(TaggedTarget::class, 'getName'));
var_dump($attribute->value()); // important
```


Run the test
--------------------

	composer install
	composer test
