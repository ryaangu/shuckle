<img src="media/shuckle.gif">

## The Shuckle Programming Language
**Shuckle** is a simple dynamically-typed language. It outputs a human readable [**C++**](https://en.wikipedia.org/wiki/C%2B%2B) code that tries to be fully statically-typed and faster than the [**Shuckle Pokémon**](https://www.pokemon.com/us/pokedex/shuckle).

## Example: Hello, World!
```js
function main()
{
    println("Hello, World!");
}
```

#### Expected C++ output:
```cpp
#include <stdio.h>

int main()
{
    puts("Hello, World!");
}
```

## License
This compiler is distributed under the [**Zlib License**](https://opensource.org/licenses/Zlib). See [**LICENSE**](https://github.com/ryaangu/shuckle/blob/main/LICENSE) for more details.