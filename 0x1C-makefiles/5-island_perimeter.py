#!/usr/bin/python3
"""
Module for island perimeter described in grid
"""


def island_perimeter(grid):
    """Returns the island perimeter described in grid

    Args:
        grid (list)= list of list of integers

    Returns:
        list= island perimeter defined in grid  
    """
    peri = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                peri += 4
                if i > 0 and grid[i - 1][j] == 1:
                    peri -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    peri -= 2
    return peri
