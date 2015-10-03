<?hh //partial

namespace example;

require_once __DIR__ . '/../vendor/autoload.php';

$attributes = MyMethodAttribute::lookup(Target::class);
var_dump($attributes);

$attributes = MyClassAttribute::lookup(Target::class);
var_dump($attributes);
