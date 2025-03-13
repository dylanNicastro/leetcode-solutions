void visitSubRooms(int roomIndex, int* markedRooms, int** rooms, int roomsSize, int* roomsColSize) {
    if (markedRooms[roomIndex] == 1) return;
    markedRooms[roomIndex] = 1;
    for (int keyIndex = 0; keyIndex < roomsColSize[roomIndex]; keyIndex++) {
        visitSubRooms(rooms[roomIndex][keyIndex], markedRooms, rooms, roomsSize, roomsColSize);
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int* markedRooms = calloc(roomsSize, sizeof(int));
    visitSubRooms(0, markedRooms, rooms, roomsSize, roomsColSize);
    for (int i = 0; i < roomsSize; i++) {
        if (markedRooms[i] == 0) {
            free(markedRooms);
            return false;
        }
    }
    free(markedRooms);
    return true;
}