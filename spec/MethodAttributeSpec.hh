<?hh //partial

use attribute\MethodAttribute;
use attribute\fixtures\Target;
use attribute\fixtures\UserMethodAttribute;
use ReflectionClass;
use ReflectionMethod;

describe(MethodAttribute::class, function() {

  describe('findByClassName()', function() {
    it('returns attribute', function () {
      $attributes = UserMethodAttribute::findByClassName(Target::class);

      expect($attributes)->toBeAnInstanceOf(ImmMap::class);
      expect($attributes)->toHaveLength(1);

      $attribute = $attributes->at('getDescription');
      expect($attribute)->toBeAnInstanceOf(UserMethodAttribute::class);
      expect($attribute->getDescription())->toBe('text');
    });
  });

  describe('findByMethod()', function() {
    it('returns attribute', function () {
      $attribute = UserMethodAttribute::findByMethod(new ReflectionMethod(Target::class, 'getDescription'));

      expect($attribute)->toBeAnInstanceOf(UserMethodAttribute::class);
      expect($attribute->getDescription())->toBe('text');
    });
  });

});
