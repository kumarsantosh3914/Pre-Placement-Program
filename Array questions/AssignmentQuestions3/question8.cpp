int minMeetingRooms(vector<vector<int>> &intervals)
{
    vector<int> starts;
    vector<int> ends;
    for (const auto &interval : intervals)
    {
        starts.push_back(interval[0]);
        ends.push_back(interval[1]);
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int meetingCount = 0;
    int currentCount = 0;
    int startPtr = 0;
    int endPtr = 0;

    while (startPtr < intervals.size())
    {
        if (starts[startPtr] < ends[endPtr])
        {
            startPtr++;
            currentCount++;
        }
        else
        {
            endPtr++;
            currentCount--;
        }
        meetingCount = max(meetingCount, currentCount);
    }

    return meetingCount;
}