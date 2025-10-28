import logging


def init_logger(debug: bool = False) -> None:
    """
    Initialize the root logger with console and file handlers.

    Args:
        debug (bool): If True, set logging level to DEBUG; otherwise INFO.

    Behavior:
        - Clears existing handlers to avoid duplicate logs.
        - Logs to both console and 'verification_report.log' file.
        - Formats logs with timestamp, level, filename, line number, and message.
    """

    # Clear existing handlers (if running multiple times, like in Jupyter or REPL)
    logging.basicConfig(datefmt='%Y-%m-%dT%H:%M:%S')
    root_logger = logging.getLogger()  # root logger

    # Set logging level for all loggers
    if not debug:
        root_logger.setLevel(logging.INFO)
    else:
        root_logger.setLevel(logging.DEBUG)
    root_logger.handlers.clear()

    # File handler
    file_handler = logging.FileHandler('verification_report.log')

    # Console handler
    console_handler = logging.StreamHandler()

    if debug:
        console_handler.setLevel(logging.DEBUG)
        file_handler.setLevel(logging.DEBUG)
    else:
        console_handler.setLevel(logging.INFO)
        file_handler.setLevel(logging.INFO)

    # Formatter
    # formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
    formatter = logging.Formatter('%(asctime)s,%(msecs)03d %(levelname)-8s [%(filename)s:%(lineno)d] %(message)s')
    file_handler.setFormatter(formatter)
    console_handler.setFormatter(formatter)

    # Add handlers to the logger
    root_logger.addHandler(file_handler)
    root_logger.addHandler(console_handler)