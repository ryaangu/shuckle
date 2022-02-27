<img src="media/shuckle.gif">

## The Shuckle Programming Language
**Shuckle** is a simple dynamically typed, stack-oriented programming language. It can output C++ files that tries to be faster than the [**Shuckle Pokémon**](https://www.pokemon.com/us/pokedex/shuckle).

## Example:
```
include "std/io.se"

define main
{
    "Hello, World!" print
    0 return
}
```
#### C++ Output:
```cpp
int main()
{
    stack.push("Hello, World!");
    print(stack.pop());
    stack.push(0);
    return stack.pop();
}
```

## License
This compiler is distributed under the [**Zlib License**](https://opensource.org/licenses/Zlib). See [**LICENSE**](https://github.com/ryaangu/shuckle/blob/main/LICENSE) for more details.
