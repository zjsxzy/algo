double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

//计算圆心
point f(point& a, point& b, double r){
    //算中点
    point mid((a.x + b.x) / 2.0,(a.y + b.y) / 2.0);
    //AB距离的一半
    double d = dist(a.x, a.y, mid.x, mid.y);
    //计算h
    double h = sqrt(r * r - d * d);
    //计算垂线
    point ba(b.x - a.x, b.y - a.y);
    point hd(-ba.y, ba.x);
    double len = sqrt(hd.x * hd.x + hd.y * hd.y);
    hd.x /= len, hd.y /= len;
    hd.x *= h, hd.y *= h;
    return point(hd.x + mid.x, hd.y + mid.y);
}


