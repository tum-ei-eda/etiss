import logging


def init_logger() -> None:
    # Clear existing handlers (if running multiple times, like in Jupyter or REPL)
    root_logger = logging.getLogger()  # root logger

    # Set logging level for all loggers
    root_logger.setLevel(logging.INFO)
    root_logger.handlers.clear()

    # File handler
    file_handler = logging.FileHandler('pyelftools_test.log')
    file_handler.setLevel(logging.DEBUG)

    # Console handler
    console_handler = logging.StreamHandler()
    console_handler.setLevel(logging.INFO)

    # Formatter
    formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
    file_handler.setFormatter(formatter)
    console_handler.setFormatter(formatter)

    # Add handlers to the logger
    root_logger.addHandler(file_handler)
    root_logger.addHandler(console_handler)