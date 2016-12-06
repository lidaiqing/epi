#include <bits/stdc++.h>

using namespace std;

// check if two Rectangle intersec

struct Rectangle
{
	int x, y; // lower left x and y
	int width, length;
};

bool isIntersect(const Rectangle& R1, const Rectangle& R2)
{
	return R1.x <= R2.x + R2.width && R2.x <= R1.x + R1.width
		&& R1.y <= R2.y + R2.length && R2.y <= R1.y + R1.length;
}

Rectangle FindIntersection(const Rectangle& R1, const Rectangle& R2)
{
	if (isIntersect(R1, R2))
	{
		return {max(R1.x,R2.x), max(R1.y,R2.y),
			min(R1.x+R1.width,R2.x+R2.width) - max(R1.x,R2.x),
			min(R1.y+R1.length,R2.y+R2.length) - max(R1.y,R2.y)};
	}
	return {0, 0, -1, -1};
}


int main()
{
	Rectangle R1{0,0,3,4};
	Rectangle R2{0,0,2,5};

	cout << "Result: " << endl;
	Rectangle R = FindIntersection(R1,R2);

	cout << R.x << " " << R.y << " " << R.width << " " << R.length << endl;
	return 0;
}
	
