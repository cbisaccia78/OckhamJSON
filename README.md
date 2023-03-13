____________________________________________________________________________
# NAME: OckhamJSON
# PURPOSE: A C Libary for the Serialization/De-Serialization of JSON text data
Adhere's to RFC8259 as the authority for defining JSON text data. 
____________________________________________________________________________

# INTRODUCTION (From RFC8259):

   JavaScript Object Notation (JSON) is a text format for the
   serialization of structured data.  It is derived from the object
   literals of JavaScript, as defined in the ECMAScript Programming
   Language Standard, Third Edition [ECMA-262].

   JSON can represent four primitive types (strings, numbers, booleans,
   and null) and two structured types (objects and arrays).

   A string is a sequence of zero or more Unicode characters [UNICODE].
   Note that this citation references the latest version of Unicode
   rather than a specific release.  It is not expected that future
   changes in the Unicode specification will impact the syntax of JSON.

   An object is an unordered collection of zero or more name/value
   pairs, where a name is a string and a value is a string, number,
   boolean, null, object, or array.

   An array is an ordered sequence of zero or more values.

   The terms "object" and "array" come from the conventions of
   JavaScript.

   JSON's design goals were for it to be minimal, portable, textual, and
   a subset of JavaScript.

Future Changes:
    ECMA and IETF will work together to reconcile any differences between
    RFC8259 and [ECMA-404]. 

JSON Grammar:

    Preliminary:
        White space "ws" is defined as:
            ws = *(
            %x20 /              ; Space
            %x09 /              ; Horizontal tab
            %x0A /              ; Line feed or New line
            %x0D )              ; Carriage return

    JSON text will be defined as a sequence of tokens.

    We will be working with the tokens defined in RFC8259

        6 structural tokens
            ______________________________________________________
            begin-array     = ws %x5B ws  ; [ left square bracket

            begin-object    = ws %x7B ws  ; { left curly bracket

            end-array       = ws %x5D ws  ; ] right square bracket

            end-object      = ws %x7D ws  ; } right curly bracket

            name-separator  = ws %x3A ws  ; : colon

            value-separator = ws %x2C ws  ; , comma
            ______________________________________________________

            Insignificant ws is allowed before or after any of the 6 structural characters.

            
        Strings

        Numbers

        3 literal names
            false
            null
            true

    Objects
        object = begin-object [ member *( value-separator member ) ]
               end-object

        member = string name-separator value

        Names of members must be unique in this implementation,
        although one could concievably modify this to allow for
        non-unique member names. 
        
    
    Arrays

        array = begin-array [ value *( value-separator value ) ] end-array

        There is no requirement that the values in an array be of the same
        type.

    Numbers
        The representation of numbers is similar to that used in most
        programming languages.  A number is represented in base 10 using
        decimal digits.  It contains an integer component that may be
        prefixed with an optional minus sign, which may be followed by a
        fraction part and/or an exponent part.  Leading zeros are not
        allowed.

        A fraction part is a decimal point followed by one or more digits.

        An exponent part begins with the letter E in uppercase or lowercase,
        which may be followed by a plus or minus sign.  The E and optional
        sign are followed by one or more digits.

        Numeric values that cannot be represented in the grammar below (such
        as Infinity and NaN) are not permitted.

        This implementation will approximate JSON numbers within the precision limits of the machine

        number = [ minus ] int [ frac ] [ exp ]

        decimal-point = %x2E       ; .

        digit1-9 = %x31-39         ; 1-9

        e = %x65 / %x45            ; e E

        exp = e [ minus / plus ] 1*DIGIT

        frac = decimal-point 1*DIGIT

        int = zero / ( digit1-9 *DIGIT )

        minus = %x2D               ; -

        plus = %x2B                ; +

        zero = %x30                ; 0

    Strings
        The representation of strings is similar to conventions used in the C
        family of programming languages.  A string begins and ends with
        quotation marks.  All Unicode characters may be placed within the
        quotation marks, except for the characters that MUST be escaped:
        quotation mark, reverse solidus, and the control characters (U+0000
        through U+001F).

        Any character may be escaped.  If the character is in the Basic
        Multilingual Plane (U+0000 through U+FFFF), then it may be
        represented as a six-character sequence: a reverse solidus, followed
        by the lowercase letter u, followed by four hexadecimal digits that
        encode the character's code point.  The hexadecimal letters A through
        F can be uppercase or lowercase.  So, for example, a string
        containing only a single reverse solidus character may be represented
        as "\u005C".

        Alternatively, there are two-character sequence escape
        representations of some popular characters.  So, for example, a
        string containing only a single reverse solidus character may be
        represented more compactly as "\\".

        This implementation will not be able to handle characters
        that are not in the Basic Multilingual Plane. But an explanation
        on how to do so is provided below for future development ideas:

            To escape an extended character that is not in the Basic Multilingual
            Plane, the character is represented as a 12-character sequence,
            encoding the UTF-16 surrogate pair.  So, for example, a string
            containing only the G clef character (U+1D11E) may be represented as
            "\uD834\uDD1E".

        string = quotation-mark *char quotation-mark

        char = unescaped /
            escape (
                %x22 /          ; "    quotation mark  U+0022
                %x5C /          ; \    reverse solidus U+005C
                %x2F /          ; /    solidus         U+002F
                %x62 /          ; b    backspace       U+0008
                %x66 /          ; f    form feed       U+000C
                %x6E /          ; n    line feed       U+000A
                %x72 /          ; r    carriage return U+000D
                %x74 /          ; t    tab             U+0009
                %x75 4HEXDIG )  ; uXXXX                U+XXXX

        escape = %x5C              ; \

        quotation-mark = %x22      ; "

        unescaped = %x20-21 / %x23-5B / %x5D-10FFFF

    Parser
        Will accept all text streams that conform to JSON grammer
        Will not accept non-JSON forms or extensions, although 
        this could be an interesting area of future development
    
    Generator
        Produces JSON text which strictly conforms to JSON grammar rules
        defined above
