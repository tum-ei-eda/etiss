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
        "  _____ ",
        " |_   _|",
        "   | |  ",
        "   | |  ",
        "  _| |_ ",
        " |_____|"],
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

def print_logo():
    return print_word(title = "ver-ise")

def print_begin():
    return print_word("begin")

def print_end():
    return print_word("end")

if __name__ == "__main__":
    print(print_word("begin"))
