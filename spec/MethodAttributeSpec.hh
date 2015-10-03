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

      $attribute = $attributes->at('attribute');
      expect($attribute)->toBeAnInstanceOf(UserMethodAttribute::class);
      expect($attribute->getName())->toBe('text');
    });
  });

  describe('findByMethod()', function() {
    it('returns attribute', function () {
      $attribute = UserMethodAttribute::findByMethod(new ReflectionMethod(Target::class, 'attribute'));

      expect($attribute)->toBeAnInstanceOf(UserMethodAttribute::class);
      expect($attribute->getName())->toBe('text');
      expect($attribute->getQuantity())->toBe(100);
    });
  });

});
