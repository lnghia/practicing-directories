#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main(){
    int pid;

	printf("hi ");
	pid = fork();
	if (pid > 0){
	    fork();
	    fork();
	    printf("hello ");
	}
    // else
	//     fork();
	printf("bye ");

    return 0;
}