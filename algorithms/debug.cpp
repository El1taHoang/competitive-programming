/*
Credit: Modified from Gennady Korotkevich's debug code (https://github.com/the-tourist/algo/blob/master/misc/debug.cpp). Many of the lines were modified by me (Aaron He).

Changes:

10 November 2022
- Fix issue with debug crashing while trying to output vector<bool>
- Now outputs 2D vectors in a grid format
- debug_out now outputs values in comma-separated format
- Added test
- Made several helper functions
- Queues, deques, stacks, and priority queues are can be debugged, with arrows pointing to where values enter, pointing away from where they can be taken out, and a double arrow if values are inserted in a special order
*/

using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

// Helper functions
template <typename A>
string to_csv(vector<A> v);

string wrap_round(string s) {
	return "(" + s + ")";
}

string wrap_curly(string s) {
	return "{" + s + "}";
}

string wrap_square(string s) {
	return "[" + s + "]";
}

string wrap_angle(string s) {
	return "<" + s + ">";
}

// Main functions
string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

string to_string(vector<bool> v) {
	return wrap_curly(to_csv(v));
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A>
string to_string(vector<vector<A>> v) {
  bool first = true;
  string res = "\n{";
  for (const auto x : v) {
    if (!first) {
      res += ", ";
			res += "\n";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A>
string to_string(queue<A> q) {
	vector<A> v;
	while (!q.empty()) {
		v.push_back(q.front());
		q.pop();
	}
	string res = "<=" + wrap_curly(to_csv(v)) + "<=";
	return res;
}

template <typename A>
string to_string(deque<A> dq) {
	vector<A> v;
	while (!dq.empty()) {
		v.push_back(dq.front());
		dq.pop_front();
	}
	string res = "<=>" + wrap_curly(to_csv(v)) + "<=>";
	return res;
}

template <typename A>
string to_string(stack<A> s) {
	vector<A> v;
	while (!s.empty()) {
		v.push_back(s.top());
		s.pop();
	}
	string res = "<=>" + wrap_curly(to_csv(v));
	return res;
}
template <typename A, typename B, typename C>
string to_string(priority_queue<A, B, C> q) {
	vector<A> v;
	while (!q.empty()) {
		v.push_back(q.top());
		q.pop();
	}
	string res = "<=>>" + wrap_curly(to_csv(v));
	return res;
}

template <typename A>
string to_csv(vector<A> v) {
	string res;
	bool first = true;
	for (A x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	return res;
}

void debug_out() { cerr << endl; }

template <typename Head>
void debug_out(Head H) {
	cerr << to_string(H) << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << to_string(H) << ", ";
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)