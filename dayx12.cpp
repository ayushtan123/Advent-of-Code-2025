#include <bits/stdc++.h>
using namespace std;

// help taken from repo : https://github.com/srivatsan0611/aoc2025/blob/main/Day12/solution.cpp

/* ---------------- SHAPE STRUCT ---------------- */

struct Shape {
    vector<pair<int, int>> cells;

    void normalize() {
        if (cells.empty()) return;
        int minR = cells[0].first, minC = cells[0].second;
        for (auto [r, c] : cells) {
            minR = min(minR, r);
            minC = min(minC, c);
        }
        for (auto &[r, c] : cells) {
            r -= minR;
            c -= minC;
        }
        sort(cells.begin(), cells.end());
    }

    Shape rotate() const {
        Shape s;
        for (auto [r, c] : cells) {
            s.cells.push_back({c, -r});
        }
        s.normalize();
        return s;
    }

    Shape flip() const {
        Shape s;
        for (auto [r, c] : cells) {
            s.cells.push_back({r, -c});
        }
        s.normalize();
        return s;
    }

    bool operator<(const Shape &other) const {
        return cells < other.cells;
    }
};

/* ---------------- VARIANTS ---------------- */

vector<Shape> getVariants(const Shape &shape) {
    set<Shape> variants;
    Shape s = shape;
    for (int i = 0; i < 4; i++) {
        variants.insert(s);
        variants.insert(s.flip());
        s = s.rotate();
    }
    return vector<Shape>(variants.begin(), variants.end());
}

/* ---------------- GRID HELPERS ---------------- */

bool canPlace(const vector<vector<int>> &grid, const Shape &shape, int r, int c, int W, int H) {
    for (auto [dr, dc] : shape.cells) {
        int nr = r + dr, nc = c + dc;
        if (nr < 0 || nr >= H || nc < 0 || nc >= W || grid[nr][nc] != 0) {
            return false;
        }
    }
    return true;
}

void place(vector<vector<int>> &grid, const Shape &shape, int r, int c, int id) {
    for (auto [dr, dc] : shape.cells) {
        grid[r + dr][c + dc] = id;
    }
}

void remove(vector<vector<int>> &grid, const Shape &shape, int r, int c) {
    for (auto [dr, dc] : shape.cells) {
        grid[r + dr][c + dc] = 0;
    }
}

/* ---------------- BACKTRACK ---------------- */

bool solve(vector<vector<int>> &grid, vector<int> &counts,
           const vector<vector<Shape>> &allVariants, int W, int H) {
    
    // Check if all pieces are placed
    bool allZero = true;
    for (int c : counts) {
        if (c > 0) {
            allZero = false;
            break;
        }
    }
    if (allZero) return true;

    // Pick first shape type that still needs to be placed
    int shapeIdx = -1;
    for (int i = 0; i < 6; i++) {
        if (counts[i] > 0) {
            shapeIdx = i;
            break;
        }
    }

    if (shapeIdx == -1) return false;

    // Try all possible positions for this shape
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            for (const Shape &variant : allVariants[shapeIdx]) {
                if (canPlace(grid, variant, r, c, W, H)) {
                    place(grid, variant, r, c, shapeIdx + 1);
                    counts[shapeIdx]--;

                    if (solve(grid, counts, allVariants, W, H)) {
                        return true;
                    }

                    counts[shapeIdx]++;
                    remove(grid, variant, r, c);
                }
            }
        }
    }

    return false;
}

/* ---------------- MAIN ---------------- */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Shape> shapes(6);
    string line;

    for (int shapeIdx = 0; shapeIdx < 6; shapeIdx++) {
        getline(cin, line); // Skip shape index line
        vector<string> pattern;
        while (getline(cin, line) && !line.empty()) {
            pattern.push_back(line);
        }

        for (int r = 0; r < (int)pattern.size(); r++) {
            for (int c = 0; c < (int)pattern[r].size(); c++) {
                if (pattern[r][c] == '#') {
                    shapes[shapeIdx].cells.push_back({r, c});
                }
            }
        }
        shapes[shapeIdx].normalize();
    }

    // Precompute all variants
    vector<vector<Shape>> allVariants(6);
    for (int i = 0; i < 6; i++) {
        allVariants[i] = getVariants(shapes[i]);
    }

    /* ---- regions ---- */
    int ans = 0;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        // Parse logic from Code 2 adapted to cin line
        size_t colonPos = line.find(':');
        string dimensions = line.substr(0, colonPos);
        size_t xPos = dimensions.find('x');
        int W = stoi(dimensions.substr(0, xPos));
        int H = stoi(dimensions.substr(xPos + 1));

        vector<int> cnt(6);
        size_t pos = colonPos + 1;
        for (int i = 0; i < 6; i++) {
            while (pos < line.size() && line[pos] == ' ') pos++;
            size_t endPos = pos;
            while (endPos < line.size() && line[endPos] != ' ') endPos++;
            if (pos < line.size()) {
                cnt[i] = stoi(line.substr(pos, endPos - pos));
                pos = endPos;
            }
        }

        // Quick area check
        int totalArea = 0;
        for (int i = 0; i < 6; i++) {
            totalArea += cnt[i] * shapes[i].cells.size();
        }

        if (totalArea > W * H) continue;

        // Try to solve
        vector<vector<int>> grid(H, vector<int>(W, 0));
        if (solve(grid, cnt, allVariants, W, H)) {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}

// ans = 460