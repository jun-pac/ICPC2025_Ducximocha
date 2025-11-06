#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

// (Set 이름).order_of_key(NUM) : 
// ordered_set 에서 NUM 보다 작은(미만의) 원소의 개수를 반환한다. 

// (Set 이름).find_by_order(K) :
// ordered_set 에서 (K+1)번째 원소가 있는 iterator 을 반환한다. (K가 0이면 1번째)