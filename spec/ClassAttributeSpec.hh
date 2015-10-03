<?hh //partial

use attribute\fixtures\Target;
use attribute\fixtures\UserClassAttribute;

describe(ClassAttribute::class, function() {
  describe('lookup()', function() {
    it('returns attribute', function () {
      $attribute = UserClassAttribute::lookup(Target::class);
      expect($attribute)->toBeAnInstanceOf(UserClassAttribute::class);
    });
  });
});
