<?hh //partial

use attribute\ClassAttribute;
use attribute\fixtures\Target;
use attribute\fixtures\UserClassAttribute;
use ReflectionClass;

describe(ClassAttribute::class, function() {
  describe('findByClassName()', function() {
    it('returns attribute', function () {
      $attribute = UserClassAttribute::findByClassName(Target::class);

      expect($attribute)->toBeAnInstanceOf(UserClassAttribute::class);
      expect($attribute->getDescription())->toBe('text');
    });
  });
  describe('findByReflection()', function() {
    beforeEach(function() {
      $this->class = new ReflectionClass(Target::class);
    });
    it('returns attribute', function () {
      $attribute = UserClassAttribute::findByReflection($this->class);

      expect($attribute)->toBeAnInstanceOf(UserClassAttribute::class);
      expect($attribute->getDescription())->toBe('text');
    });
  });
});
