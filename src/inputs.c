
#include <bbsh/shlib.h>
#include <bbsh/utils.h>
#include <bbsh/inputs.h>

/* TODO for tokenizer:
 * - parse_normal_words should only take account normal unquoted words
 * - parse_quoted_words is self explanatory
 *
 * This tokenizer needs to check for these characters below:
 * - tabs, spaces
 * - quotation marks
 */

char *parse_normal_words(const char **input)
{
        const char *start = *input;
        const char *end = start;

        // check for whitespaces, quotation marks, and null terminators
        while (*end != '\0' && *end != ' ' && *end != '"') {
                ++end;
        }

        /* subtract those two memory addresses to get the length of the string
         * then allocate space for each token
         */
        uint16_t input_len = end - start;
        char *token = malloc(input_len + 1);

        if (token == NULL) {
                perror("Token Allocation");
                exit(1);
        }
        
        strncpy(token, start, input_len);
        token[input_len] = '\0';

        // put the input pointer to the end of the string to start there after we end the function
        *input = end;
        return token;
}

char *parse_quoted_words(const char **input)
{
        /* get the address and dereference the quoted character
         * then skip that quoted character to start after that
         */
        const char *quote = *input;
        const char *start = quote + 1;
        const char *end = start;

        while (*end != '\0' && *end != *quote) {
                ++end;
        }        

        uint16_t input_len = end - start;
        char *token = malloc(input_len + 1);

        if (token == NULL) {
                perror("Token Memory Allocation");
                exit(1);
        }

        strncpy(token, start, input_len);
        token[input_len] = '\0';

        if (*end != *quote) {
                free(token);
                return NULL;
        }

        // point to the last character and advance one character more to skip the last quotation mark
        *input = end + 1;
        return token;
}

char **tokenizer(const char *string, uint16_t *token_amount)
{
        uint16_t storage_size = MAX_BUF;
        uint16_t token_count = 0;
        const char *input = string;
        char **token_holder = malloc(storage_size * sizeof(char *));

        if (token_holder == NULL) {
                perror("Token Holder Allocation");
                exit(1);
        }

        while (*input != '\0') {
                
                while (*input == ' ')
                        input++;

                if (*input == '\0')
                        break;

                char *token = NULL;

                if (*input == '"') {
                        token = parse_quoted_words(&input);

                        if (token == NULL) {
                                free_tokens(token_holder, token_count);
                                return NULL;
                        }

                } else {
                        token = parse_normal_words(&input);
                }

                if (token_count == storage_size) {
                        printf("Reallocating token array, current prompt is too big...\n");
                        storage_size *= 2;

                        printf("Storage size: %u\n", storage_size);
                        char **temp_token_holder = realloc(token_holder, storage_size * sizeof(char *));

                        if (temp_token_holder == NULL) {
                                perror("Temporary Token Holder Reallocation");
                                exit(1);
                        }
                        
                        token_holder = temp_token_holder;
                }
                token_holder[token_count++] = token;
        }

        token_holder[token_count] = NULL;

        *token_amount = token_count;
        return token_holder;
}

// Dynamically sized input
char *d_input(char *buffer)
{
        int16_t character = 0;
        uint16_t buffer_idx = 0;
        uint16_t buffer_size = MAX_BUF;

        while ((character = fgetc(stdin)) != EOF) {

                if (character == '\n') {
                        buffer[buffer_idx] = '\0';
                        break;
                }

                if (buffer_idx + 1 >= buffer_size) {
                        buffer_size *= 2;
                        char *big_buf = realloc(buffer, buffer_size);

                        if (big_buf == NULL) {
                                perror("Bigger Buffer Reallocation");
                                exit(1);
                        }

                        buffer = big_buf;
                }

                buffer[buffer_idx++] = (unsigned char)character;
        }

        if (character == -1) {
                printf("Exited shell successfully.\n");
                free(buffer);
                exit(0);
        }

        return buffer;
}
