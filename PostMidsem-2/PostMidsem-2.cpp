#include<bits/stdc++.h>
using namespace std;

struct point 
{ 
    int x, y; 
}; 

point p0;

point nextToTop(stack<point> &S)
{
    point p= S.top();
    S.pop();
    point secon = S.top();
    S.push(p);
    return secon;
}

int swap(point &p1, point &p2)
{
    point temp = p1;
    p1=p2;
    p2 = temp;
}

int dist(point p1, point p2)
{
    int val = (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
    return val;
}

int orien(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val==0) return 0;
    return (val>0) ? 1 : 2;
}

int compare(const void *pa1, const void *pa2)
{
    point *p1 = (point *)pa1;
    point *p2 = (point *)pa2; 

    int o = orien(p0, *p1, *p2);

    if(o==0)
        return (dist(p0, *p2)>=dist(p0, *p1)) ? -1 : 1;
    return (o==1) ? -1 : 1;
}


int main()
{
    int n;
	cin>>n;
    point p[n]; 
	for (int a= 0; a<n;a++)
	{
			cin>>p[a].x>>p[a].y;
	}

    int xmin = p[0].x, min =0;
    for(int i= 1;i<n; i++)
    {
        int x = p[i].x;
        if((x<xmin) || (xmin == x && p[i].y<p[min].y))
        {
            xmin = p[i].x, min = i;
        }
    }  

    swap(p[0],p[min]);

    p0 = p[0];
    qsort(&p[1], n-1, sizeof(point), compare);

    int m = 1;

    for(int i= 1; i<n; i++)
    {
        while( i<n-1 && orien(p0, p[i], p[i+1])==0)
            i++;
        p[m]=p[i];
        m++;
    }  
    if (m<3) 
        {   
            cout<<"NO CONVEX HULL";
            return 0;
         }    
    
    
    
    stack<point> S;
    S.push(p[0]);
    S.push(p[1]);
    S.push(p[2]);

    for(int i =3; i<m; i++)
    {
        while(orien(nextToTop(S), S.top(), p[i])!= 1)
            S.pop();
        S.push(p[i]);
    }
    stack<point> S1;
    cout<<S.size()<<endl;
    while(!S.empty())
    {
        S1.push(S.top());
        S.pop();
    }

     while(!S1.empty())
    {
        point p = S1.top();
        cout<<p.x<<" "<<p.y<<endl;
        S1.pop();
    }

	return 0;
}