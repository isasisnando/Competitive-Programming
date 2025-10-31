bool primo[MAX];

void crivo()
{
    memset(primo,1,sizeof(primo));
    primo[0] = primo[1] = 0;
    for(int i = 2; i < MAX; i++)
    {
        if(!primo[i]) continue;
        for(int j = 2*i; j < MAX; j+=i) primo[j] = 0;
    }
    return;
}