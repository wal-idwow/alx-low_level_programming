#!/usr/bin/python3"
"""define island perimeter described in grid"""


def island_perimeter(grid):
    """Calculates the island perimeter described in grid

    Args:
        grid (list): list of list of integers

    Returns:
        list: island perimeter defined in grid  
    """
    peri = 0
    r = len(grid)
    cols = len(grid[0])

    for i in range(r):
        for j in range(cols):
            if grid[i][j] == 1:
                peri += 4
                #check for top neighbor
                if i > 0 and grid[i - 1][j] == 1:
                    peri -= 2
                #check for left one
                if j > 0 and grid[i][j - 1] == 1:
                    peri -= 2
    return peri
