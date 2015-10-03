<?hh // strict

namespace attribute
{
    use Generator;

    type MethodAttributeMap = ImmMap<string, MethodAttribute>;
    type MethodAttributeParameters = Generator<string, array<mixed>, void>;
}
