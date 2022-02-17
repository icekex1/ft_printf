# ft_printf
My implementation of the C function printf.

<img width="197" alt="Screenshot 2022-02-17 at 12 55 35 AM" src="https://user-images.githubusercontent.com/65648486/154377425-c4740643-0675-48ff-8c46-bc3bb055f221.png">

implemented conversions: 
• %c Prints a single character.  
• %s Prints a string (as defined by the common C convention).  
• %p The void * pointer argument has to be printed in hexadecimal format.  
• %d Prints a decimal (base 10) number.  
• %i Prints an integer in base 10.  
• %u Prints an unsigned decimal (base 10) number.  
• %x Prints a number in hexadecimal (base 16) lowercase format.  
• %X Prints a number in hexadecimal (base 16) uppercase format.  
• %% Prints a percent sign. 

implemented flags: 
• -                     Left justify the output within the specified field.
• 0                     Pad a field with leading zeros.
• .                     Precision.
• field minimum width   The converted argument will be printed in a field at least this wide, and wider if necessary.
• #                     Prefix 0 to the output value when used with the octal conversion character o.
• space                 Print a space before a positive value not printed with the + flag.
• +                     Display a plus sign preceding positive values and a minus sign preceding negative values.
## Usage

``make`` without bonus functions.

``make bonus`` to compile with bonuses.
