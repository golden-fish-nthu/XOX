#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 2000
#define MAXLEN 1000

// 用於表示圖的鄰接表結構
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    // 加邊 (src, dest)
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // 加邊 (dest, src)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(Graph* graph, int vertex) {
    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    graph->visited[vertex] = 1;

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int findGroups(char strings[][MAXLEN], int n) {
    Graph* graph = createGraph(n);
    int char_map[26][MAXN];
    int char_count[26] = {0};

    // 初始化字符映射表
    for (int i = 0; i < 26; i++) {
        char_count[i] = 0;
    }

    // 構建字符映射表
    for (int i = 0; i < n; i++) {
        int len = strlen(strings[i]);
        int unique[26] = {0};

        for (int j = 0; j < len; j++) {
            int c = strings[i][j] - 'a';
            if (!unique[c]) {
                unique[c] = 1;
                char_map[c][char_count[c]++] = i;
            }
        }
    }

    // 構建圖
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < char_count[i]; j++) {
            for (int k = j + 1; k < char_count[i]; k++) {
                addEdge(graph, char_map[i][j], char_map[i][k]);
            }
        }
    }

    // 計算連通分量的數量
    int numGroups = 0;
    for (int i = 0; i < n; i++) {
        if (graph->visited[i] == 0) {
            DFS(graph, i);
            numGroups++;
        }
    }

    // 釋放內存
    for (int i = 0; i < n; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);

    return numGroups;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char strings[MAXN][MAXLEN];
        for (int i = 0; i < n; i++) {
            scanf("%s", strings[i]);
        }

        int result = findGroups(strings, n);
        printf("%d\n", result);
    }

    return 0;
}
