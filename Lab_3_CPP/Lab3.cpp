#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "queue.h"

typedef std::vector<int> DistRow;
typedef std::vector<DistRow> MazeDist;
typedef std::vector<long long> PathsRow;
typedef std::vector<PathsRow> MazePaths;


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input)
    {
        return 1;
    }

    std::vector<std::string> maze;
    std::string line;
    int start_x = -1;
    int start_y = -1;
    int end_x = -1;
    int end_y = -1;

    int y = 0;
    while (std::getline(input, line))
    {
        if (line.empty())
        {
            continue;
        }
        for (int x = 0; x < static_cast<int>(line.size()); ++x)
        {
            if (line[x] == 'Q')
            {
                start_x = x;
                start_y = y;
            }
            else if (line[x] == 'E')
            {
                end_x = x;
                end_y = y;
            }
        }
        maze.push_back(line);
        y++;
    }

    if (maze.empty())
    {
        return 1;
    }

    int height = static_cast<int>(maze.size());
    int width = static_cast<int>(maze[0].size());

    if (start_x == -1 || start_y == -1 || end_x == -1 || end_y == -1)
    {
        return 1;
    }

    MazeDist dist(height, DistRow(width, -1));
    MazePaths paths(height, PathsRow(width, 0));

    Queue *queue = queue_create();

    dist[start_y][start_x] = 0;
    paths[start_y][start_x] = 1;
    queue_insert(queue, start_y * width + start_x);

    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

    while (!queue_empty(queue))
    {
        int curr = queue_get(queue);
        queue_remove(queue);

        int cy = curr / width;
        int cx = curr % width;

        for (int i = 0; i < 8; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            while (nx >= 0 && nx < width && ny >= 0 && ny < height && maze[ny][nx] != '#')
            {
                if (dist[ny][nx] == -1)
                {
                    dist[ny][nx] = dist[cy][cx] + 1;
                    paths[ny][nx] = paths[cy][cx];
                    queue_insert(queue, ny * width + nx);
                }
                else if (dist[ny][nx] == dist[cy][cx] + 1)
                {
                    paths[ny][nx] += paths[cy][cx];
                }
                
                nx += dx[i];
                ny += dy[i];
            }
        }
    }

    std::cout << paths[end_y][end_x] << std::endl;

    queue_delete(queue);
    return 0;
}
