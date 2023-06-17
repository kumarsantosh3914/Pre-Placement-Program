void towerOfHanoi(int n, Tower origin, Tower buffer, Tower destination)
{
    if (n == 1)
    {
        print("Move disc 1 from " + origin + " to " + destination);
        return;
    }
    towerOfHanoi(n - 1, origin, destination, buffer);
    print("Move disc " + n + " from " + origin + " to " + destination);
    towerOfHanoi(n - 1, buffer, origin, destination);
}