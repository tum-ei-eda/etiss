class Peekable:
    """
    Iterator wrapper that allows peeking at the next element without consuming it.

    Example usage:
        p = Peekable([1, 2, 3])
        print(p.peek())  # Output: 1
        print(next(p))   # Output: 1
        print(next(p))   # Output: 2
    """

    def __init__(self, iterable):
        """
        Initialize the Peekable iterator.

        Args:
            iterable: Any iterable (like a list, generator, etc.)
        """
        self._it = iter(iterable)
        self._buffer = None

    def peek(self):
        """
        Peek at the next element in the iterator without consuming it.

        Returns:
            The next element if available, or None if the iterator is exhausted.
        """
        if self._buffer is None:
            self._buffer = next(self._it, None)
        return self._buffer

    def __next__(self):
        """
        Return the next element from the iterator, consuming it.

        Returns:
            The next element from the iterator.

        Raises:
            StopIteration: When the iterator is exhausted.
        """
        if self._buffer is not None:
            result = self._buffer
            self._buffer = None
            return result
        return next(self._it)

    def __iter__(self):
        """
        Return the iterator itself.

        Returns:
            self
        """
        return self
