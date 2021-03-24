#include<bits/stdc++.h>
#include "BurstDetector.h"
#include "CorrectBurstDetector.h"
#include "CMBurstDetector.h"
using namespace std;
map<uint64_t, int> D;
vector<pair<int, int> > S[2000000];
int w = 0;
int main()
{
	int mem = 60; // the size of memory
	double l = 0.3; // the ratio of the Running Track threshold to the burst threshold
	double r12 = 3.75; // the ratio of the size of Stage 1 to the size of Stage 2
	int screen_layer_threshold = l * threshold; // Running Track threshold
	int log_size = mem * 1024 / (12 * r12 + 20) / bucket_size; // number of buckets in Stage 2
	int screen_layer_size = log_size * r12 * bucket_size; // number of buckets in Stage 1
	int cm_size = mem * 1024 / (window_num + 2) / 4; // the size of CM Sketch
	BurstDetector A(screen_layer_size, screen_layer_threshold, log_size, threshold);
	CorrectBurstDetector B(threshold);
	CMBurstDetector C(cm_size, threshold);
	int window = 0, cnt = 0;
	
	int input_size = 30000000;  // 20000000 is the default value.
	int window_size = 10000;  // 40000 is the original value.

    ofstream inputData, labelData;
    inputData.open("input_flow.csv");
    labelData.open("bursts.csv");
	
	inputData << "id,window\n";
	labelData << "start_window,end_window,flow_id\n";

	for(int i = 0; i < input_size; i++)
	{
		
		uint64_t tim, id;
		fin.read((char *)&tim, sizeof(char) * 8);
		fin.read((char *)&id, sizeof(char) * 8);
		
		cnt++;
        if(cnt > window_size)
        {
        	cnt = 0;
        	window++;
        }
        A.insert(id, window);
        B.insert(id, window);
        C.insert(id, window);

        inputData << id << ',' << window << '\n';
	}

    printf("Totally %d distinct flows\n", B.w);
	printf("Actually there exist %lu bursts!\n", B.Record.size());
	printf("BurstSketch totally reports %lu bursts!\n", A.log.Record.size());
	printf("CM Burst detector totally reports %lu bursts!\n", C.Record.size());

    for (int i = 0, sz = B.Record.size(); i < sz; i++) {
        labelData << B.Record[i].start_window << ',' << B.Record[i].end_window << ',' << B.Record[i].flow_id << '\n';
    }

    inputData.close();
    labelData.close();

	return 0;
}
