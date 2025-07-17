//leet 733
/*
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.
*/
class Solution {
public:
    bool isvalid(int x, int y, int r, int c) {
        return (x >= 0 && y >= 0 && x < r && y < c);
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfsfillcolor(vector<vector<int>>& image, int sr, int sc, int rows,
                      int cols, int color, int initialcolorval) {
        image[sr][sc] = color;

        for (int i = 0; i < 4; i++) {
            int newx = sr + dx[i];
            int newy = sc + dy[i];

            // condition to do the floodfill
            if (isvalid(newx, newy, image.size(), image[0].size()) &&
                image[newx][newy] == initialcolorval) {
                dfsfillcolor(image, newx, newy, rows, cols, color,
                             initialcolorval);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if (image[sr][sc] == color)
            return image; // no flood fill happens
        int initialcolorval = image[sr][sc];
        dfsfillcolor(image, sr, sc, image.size(), image[0].size(), color,
                     initialcolorval);
        return image;
    }
};
