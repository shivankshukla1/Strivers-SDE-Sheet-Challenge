vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

void func(int i, int j, int old, int newcolor, vector<vector<int>>& image){
    image[i][j] = newcolor;
    for(int ind = 0; ind < 4; ind++){
        int x = i + dx[ind];
        int y = j + dy[ind];
        if(x >= 0 && y >= 0 && x < image.size() && y < image[0].size() && image[x][y] == old){
            func(x, y, old, newcolor, image);
        }
    }
}


vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    if(image[x][y] == newColor){
        return image;
    }
    int old = image[x][y];
    func(x, y, old, newColor, image);
    return image;
}