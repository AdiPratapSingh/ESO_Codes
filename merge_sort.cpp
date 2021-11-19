#include <bits/stdc++.h>
#include <time.h>

using namespace std;

std::string GetLocalTime() {
  auto now(std::chrono::system_clock::now());
  auto seconds_since_epoch(
    std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()));

  // Construct time_t using 'seconds_since_epoch' rather than 'now' since it is
  // implementation-defined whether the value is rounded or truncated.
  std::time_t now_t(
    std::chrono::system_clock::to_time_t(
      std::chrono::system_clock::time_point(seconds_since_epoch)));

  char temp[10];
  if (!std::strftime(temp, 10, "%H:%M:%S.", std::localtime(&now_t)))
    return "";

  std::string nanoseconds = std::to_string(
    (std::chrono::duration<long long, std::nano>(
      now.time_since_epoch() - seconds_since_epoch)).count());

  return std::string(temp) + std::string(9-nanoseconds.length(),'0') + nanoseconds;
}

void MergeSortedIntervals(vector<int> &v, int s, int m, int e) {
	
    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
	vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

// the MergeSort function
// Sorts the array in the range [s to e] in v using
// merge sort algorithm
void MergeSort(vector<int>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}

int Partition(vector<int> &v, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]<v[pivot]){
			swap(v[i],v[j]);
			++j;
		}
	}
	swap(v[j],v[pivot]);
	return j;
	
}

void Quicksort(vector<int> &v, int start, int end ){

	if(start<end){
		int p = Partition(v,start,end);
		Quicksort(v,start,p-1);
		Quicksort(v,p+1,end);
	}
	
}

string TimeDifference(string start, string end) {
    double s1 = std::stod(start.substr(6, start.length() - 6));
    double s2 = std::stod(end.substr(6, end.length() - 6));
    int h1 = std::stoi(start.substr(0, 2));
    int h2 = std::stoi(end.substr(0, 2));
    int m1 = std::stoi(start.substr(3, 2));
    int m2 = std::stoi(end.substr(3, 2));
    double s_diff = (s2 - s1 >= 0)? (s2-s1) : (60 + s2 - s1);
    int pwr = (s2 - s1 < 0);
    int m_diff = (m2-pwr - m1 >= 0)? (m2-pwr - m1) : (60 + m2-pwr - m1);
    pwr = (m2-pwr - m1 < 0);
    int h_diff = (h2-pwr - h1 >= 0)? (h2-pwr - h1) : (24 + h2-pwr - h1);
    return std::to_string(h_diff) + ":" + std::to_string(m_diff) + ":" + std::to_string(s_diff);
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = rand();
    }
    vector<int> v_copy(v);
    string startTime = GetLocalTime();
    MergeSort(v,0,n-1);
    string endTime = GetLocalTime();
    cout << "Merge Sort" << endl;
    cout << "Start Time: " << startTime << endl;
    cout << "End Time: " << endTime << endl;
    cout << "Time taken by MergeSort: " << TimeDifference(startTime,endTime) << endl;
    
    startTime = GetLocalTime();
    Quicksort(v_copy,0,n-1);
    endTime = GetLocalTime();
    cout << "Quick Sort" << endl;
    cout << "Start Time: " << startTime << endl;
    cout << "End Time: " << endTime << endl;
    cout << "Time taken by Quicksort: " << TimeDifference(startTime,endTime) << endl;

    return 0;
}

