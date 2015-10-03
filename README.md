attribute
====================

Attribute for Hack

[![Build Status](https://travis-ci.org/holyshared/attribute.svg?branch=master)](https://travis-ci.org/holyshared/attribute)
[![Dependency Status](https://www.versioneye.com/user/projects/560ff3b5a193340015000001/badge.svg?style=flat)](https://www.versioneye.com/user/projects/560ff3b5a193340015000001)

Basic usage
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

$attribute = Tag::findByClassName(new ReflectionClass(TaggedTarget::class));
var_dump($attribute->value()); // Tag attribute instance
```
