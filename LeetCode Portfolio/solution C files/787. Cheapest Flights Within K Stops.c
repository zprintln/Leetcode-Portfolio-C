int findCheapestPrice(int numCities, int** flights, int numFlights, int* flightCols, int src, int dst, int maxStops){
    int cityFlights[100][100] = {}; // Adjacency list of flights for each city
    int numCityFlights[100] = {}; // Number of flights for each city

    // Build the adjacency list
    for (int i=0; i<numFlights; i++) {
        int from = flights[i][0];
        int to = flights[i][1];
        int price = flights[i][2];
        cityFlights[from][numCityFlights[from]] = i;
        numCityFlights[from]++;
    }

    int checkedPrice[100] = {}; // Prices of flights that have been checked
    for (int i=0; i<numCities; i++)
        checkedPrice[i] = INT_MAX;
    int queue[10000] = {}; // Queue for BFS traversal
    int queueStops[10000] = {}; // Number of stops for each city in queue
    int queuePrice[10000] = {}; // Current price for each city in queue
    queue[0] = src;
    checkedPrice[src] = 0;
    int queueIndex = 0;
    int queueEnd = 1;
    int minPrice = INT_MAX;
    while (queueIndex < queueEnd) {
        int tmpSrc = queue[queueIndex];
        int stops = queueStops[queueIndex];
        int price = queuePrice[queueIndex];
        queueIndex++;
        if (price < checkedPrice[tmpSrc])
            checkedPrice[tmpSrc] = price;

        if (tmpSrc == dst) {
            if (price < minPrice)
                minPrice = price;
        } else {
            if (stops <= maxStops && price < minPrice) {
                for (int z=0; z<numCityFlights[tmpSrc]; z++) {
                    int j = cityFlights[tmpSrc][z];
                    int tmpDst = flights[j][1];
                    int tmpPrice = flights[j][2];
                    int newPrice = price + tmpPrice;

                    if (newPrice < checkedPrice[tmpDst]) {
                        queue[queueEnd] = tmpDst;
                        queueStops[queueEnd] = stops+1;
                        queuePrice[queueEnd] = newPrice;
                        queueEnd++;
                    }
                }
            }
        }
    }
    if (minPrice == INT_MAX)
        return -1;
    return minPrice;
}
