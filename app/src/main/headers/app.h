/*
 * This C++ source file was generated by the Gradle 'init' task.
 */
#ifndef EMEL_LANG_H // BEGIN INCLUDE_GUARD("emellang.h")
#define EMEL_LANG_H

#include <string>

namespace emel_lang {
    namespace tokens {
        /// <summary>
        /// Represents a token.
        /// </summary>
        class Token(TokenType type, std::string value, int line, int column);

        /// <summary>
        /// Represents a token type.
        /// </summary>
        enum class TokenType {
            // Token bait.
            __BAITED,

            // Single-character tokens.
            LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
            COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

            // One or two character tokens.
            BANG, BANG_EQUAL,
            EQUAL, EQUAL_EQUAL,
            GREATER, GREATER_EQUAL,
            LESS, LESS_EQUAL,

            // Literals.
            IDENTIFIER, NUMBER,

            // Keywords.
            AND, OR, XOR, NOT, BOOL, FN, POLY, SET, 
            UNION, INTERSECT, DIFFERENCE, SYMMETRIC_DIFFERENCE, 
            IF, ELSE, ELIF, YES, NO, __NULL,

            // End of file.
            __EOF
        };
        /// <summary>
        /// Represents a stream of tokens.
        /// </summary>
        class TokenStream {
        public:
            TokenStream(std::string source);
            Token next();
            Token peek();
            bool isAtEnd();
        private:
            bool __process_string();
            std::string source;
            std::vector<Token> tokens;
            int current = 0;
        };
        /// <summary>
        /// Represents a token which is invalid.
        /// </summary>
        class BaitedToken: public Token {
        public:
            BaitedToken(std::string text, int line, int column) : Token(TokenType::__BAITED, text, line, column) {}
        };
    }
}

#endif // END INCLUDE_GUARD("emellang.h")
