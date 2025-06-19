import logging


def init_logger(debug: bool = False) -> None:
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
    file_handler = logging.FileHandler('pyelftools_test.log')

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