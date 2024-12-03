#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

struct Player {
    string name;
    int moves[10];
    int money = 100;
    int distance = 0;
    int position = 0;
    int neww = 0;
};

tuple<int, int, int> location(int position, char* mapp, int money, int N, int distance) {
    if (position < 0) {
        position = (position + N) % N;
    }
    if (position >= N) {
        position = position % N;
    }

    if (mapp[position] == 'O') {
        return make_tuple(position, money, distance);
    } else if (mapp[position] == 'R') {
        return make_tuple(position, money + 50, distance);
    } else if (mapp[position] == 'P') {
        return make_tuple(position, money - 50, distance);
    } else if (mapp[position] == 'F') {
        return location(position + 2, mapp, money, N, distance + 2);
    } else if (mapp[position] == 'B') {
        return location(position - 2, mapp, money, N, distance - 2);
    }
    return make_tuple(position, money, distance);
}

void count(Player& player, char* mapp, int N) {
    for (int move : player.moves) {
        player.position = (player.position + move) % N;
        player.distance += move;
        auto result = location(player.position, mapp, player.money, N, 0);
        player.position = get<0>(result);
        player.money = get<1>(result);
        player.distance += get<2>(result);
    }
}

int main() {
    int N;
    cin >> N;
    char mapp[N];
    for (int i = 0; i < N; ++i)
        cin >> mapp[i];

    int M;
    cin >> M;
    vector<Player> players(M);
    for (int i = 0; i < M; ++i) {
        cin >> players[i].name;
        players[i].neww = i;
        for (int j = 0; j < 10; ++j)
            cin >> players[i].moves[j];
    }

    for (auto& player : players) {
        count(player, mapp, N);
    }

    sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
        if (a.money != b.money)
            return a.money > b.money;
        if (a.distance != b.distance)
            return a.distance > b.distance;
        return a.neww < b.neww;
    });

    for (const auto& player : players) {
        cout << player.name << " " << player.money << " " << player.distance << " " << endl;
    }

    return 0;
}
