double Calc(Type a)
{
    /* 根据题目的意思计算 */
}

void Solve()
{
    double Left, Right;
    double mid, midmid;
    double mid_value, midmid_value;
    Left = MIN; Right = MAX;
    while (Right - Left > eps)
    {
        mid = (Left + Right) / 2;
        midmid = (mid + Right) / 2;
        mid_value = Calc(mid);
        midmid_value = Calc(midmid);
        // 假设求解最大极值.
        if (mid_value >= midmid_value) Right = midmid;
        else Left = mid;
    }
}
