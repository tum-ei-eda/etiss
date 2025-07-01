logo_chars = {
    "v": [" __      __",
          " \ \    / /",
          "  \ \  / / ",
          "   \ \/ /  ",
          "    \  /   ",
          "     \/    "],
    "e": [
        "  ______ ",
        " |  ____|",
        " | |__   ",
        " |  __|  ",
        " | |____ ",
        " |______|"],
    "i": [
        " _____ ",
        "|_   _|",
        "  | |  ",
        "  | |  ",
        " _| |_ ",
        "|_____|"],
    "c": [
        "   _____ ",
        "  / ____|",
        " | |     ",
        " | |     ",
        " | |____ ",
        "  \_____|"],
    "a": [
        "           ",
        "     /\    ",
        "    /  \   ",
        "   / /\ \  ",
        "  / ____ \ ",
        " /_/    \_"'\\'],
    "t": [
        " _______ ",
        "|__   __|",
        "   | |   ",
        "   | |   ",
        "   | |   ",
        "   |_|   "],
    "o": [
        "  ____  ",
        " / __ \ ",
        "| |  | |",
        "| |  | |",
        "| |__| |",
        " \____/ "],
    "r": [
        " _____  ",
        "|  __ \ ",
        "| |__) |",
        "|  _  / ",
        "| | \ \ ",
        "|_|  \_\\"],
    "f": [
        " ______ ",
        "|  ____|",
        "| |__   ",
        "|  __|  ",
        "| |     ",
        "|_|     "],
    "s": [
        "  _____ ",
        " / ____|",
        "| (___  ",
        " \___ \\ ",
        " ____) |",
        "|_____/ "],
    "-": [
        "      ",
        "      ",
        "  __  ",
        " |__| ",
        "      ",
        "      "],
    "b": [
        " ____  ",
        "|  _ \ ",
        "| |_) |",
        "|  _ < ",
        "| |_) |",
        "|____/ "],

    "g": [
        "  ____  ",
        " / ___| ",
        "| |  __ ",
        "| | |_ |",
        "| |__| |",
        " \\____/ "],

    "n": [
        " _   _ ",
        "| \ | |",
        "|  \| |",
        "| . ` |",
        "| |\  |",
        "|_| \_|"],
    "d": [
        " _____  ",
        "|  __ \ ",
        "| |  | |",
        "| |  | |",
        "| |__| |",
        "|_____/ "],

    "copyright": [
        "(not-a-trademark)",
        "                 ",
        "                 ",
        "                 ",
        "                 ",
        "                 ",
    ]
}

WIDTH = 100

def print_word(title) -> str:
    """
    Generate an ASCII art representation of the given word using predefined character logos.

    Args:
        title (str): The word to print in ASCII art.

    Returns:
        str: The ASCII art string representing the word, centered within a fixed width.
    """
    total_length = 0
    for c in title:
        total_length += len(logo_chars[c][0])
    output = ""
    logo_height = len(logo_chars['v'])
    for i in range(logo_height):
        output += " " * int((WIDTH - total_length) / 2)
        for c in title:
            if c in logo_chars:
                output += f"{logo_chars[c][i]}"
        output += '\n'
    return output

def print_section_break(symbol: str = "=") -> str:
    """
    Create a horizontal section break line using a repeated symbol.

    Args:
        symbol (str): The character to repeat for the break line (default '=').

    Returns:
        str: A string of repeated symbols forming a line with a newline.
    """
    return WIDTH * symbol + "\n"

def print_centered_line(text: str) -> str:
    """
    Center-align a line of text within the fixed width.

    Args:
        text (str): The text to center.

    Returns:
        str: The centered text padded with spaces and ending with a newline.
    """
    padding = WIDTH - len(text)
    left_padding = padding // 2
    right_padding = padding - left_padding
    return left_padding*" " + text + right_padding*" " + '\n'

def print_section_title(text, symbol: str = "=", prefix: str = "\n") -> str:
    """
    Print a section title with surrounding break lines and optional prefix.

    Args:
        text (str): The title text to display.
        symbol (str): The symbol to use for the break lines (default '=').
        prefix (str): A string to prepend before the section (default newline).

    Returns:
        str: Formatted string with prefix, break line, centered title, and another break line.
    Notes:
        - prefix newline is useful if method is invoked in logger argument.
    """
    output = 'Printing title for next section'
    output += prefix
    output += print_section_break(symbol)
    output += print_centered_line(text)
    output += print_section_break(symbol)
    return output


def print_logo():
    """
    Return the ASCII art logo for the word 'etiss-gts'.

    Returns:
        str: The ASCII art string of 'etiss-gts'.
    """
    return print_word(title = "etiss-gts")

def print_begin():
    """
    Return the ASCII art for the word 'begin'.

    Returns:
        str: The ASCII art string of 'begin'.
    """
    return print_word("begin")

def print_end():
    """
    Return the ASCII art for the word 'end'.

    Returns:
        str: The ASCII art string of 'end'.
    """
    return print_word("end")

if __name__ == "__main__":
    print(print_word("begin"))
