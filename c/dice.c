/*

Copyright 2017 David Miller

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/stdlib.h> /* For arc4random() */

void error() {
        fprintf(stderr, "Usage: dice <number of dice> <sides in dice>\n");
        exit(1);
}

int main(int argc, char *argv[]) {
        uint32_t num, limit, total = 0;

        if (argc != 3) {
                error();
        }

        for (int i = 0; i < strlen(argv[1]); i++) {
                if (isdigit(argv[1][i]) == 0) {
                        error();
                }
        }

        num = (uint32_t) atol(argv[1]);
        
        for (int i = 0; i < strlen(argv[2]); i++) {
                if (isdigit(argv[2][i]) == 0) {
                        error();
                }
        }

        limit = (uint32_t) atol(argv[2]);

        for (uint32_t i = 1; i <= num; i++) {
                uint32_t res = arc4random_uniform(limit) + 1;
                printf("Dice roll %lu: %lu\n", i, res);
                total += res;
        }

        printf("Total: %lu\n", total);

        exit(0);
}



