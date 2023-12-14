### KMP字符串匹配算法

```c++
class KMP
{

private:
    vector<vector<int>> m_dp;
    /*
    m_dp内容：
        m_dp[j][c]=next
        0<=j<M              M是 m_dst大小
        0<=c<256            256是所有的字符 ASCIII码
        0<=next<=M          代表下一个状态
        举个例子
        比如    m_dp[4]["A"]=3 表示 当前状态是4 如果遇到字符A，则m_dst转移到状态3
    */
    string m_dst{};

    //状态机
    void construct_dp(){
        size_t M{m_dst.size()};
        for (size_t i = 0; i < M;i++)
        {
            for (size_t j = 0; j < 256;j++)
            {
                //m_dp=next?
                /*
                1.状态推进： 如果遇到字符c==m_dist[j] 则状态应该向前推进一个，即next=j+1
                2.状态重启：如果遇到的字符c!=m_dist[j] 则状态回退(或者原地不动)
                 如果知道要退到哪个状态呢?
                    先定义 影子状态
                    影子状态：用变量 X 表示。所谓影子状态，就是和当前状态具有相同的前缀
                */
```
<div align=center><img src= "data/屏幕截图 2023-12-13 152438.png" width="475" height="120" #pic_center></div>  

```c++
                     /*
                    比如 m_dst: A->B->A->B->C
                                0->1->2->3->4->5
                    当前状态是 j=4 ，其影子状态为 X=2,因为它们都有相同的前缀AB

                    因为状态 X 和状态 j 存在相同的前缀，所以当状态 j 准备进行状态重启的时候
                    （遇到的字符 c 和 pat[j] 不匹配），可以通过 X 的状态转移图来获得最近的重启位置。

                    比如说刚才的情况，如果状态 j 遇到一个字符 "A"，应该转移到哪里呢？
                    首先只有遇到 "C" 才能推进状态，遇到 "A" 显然只能进行状态重启。
                    状态 j 会把这个字符委托给状态 X 处理，
                    也就是 m_dp[j]['A'] = m_dp[X]['A']:
                    */
```
<div align=center><img src= "data/屏幕截图 2023-12-13 154820.png" width="475" height="120" #pic_center></div>  



```c++
                /*
                    为什么这样可以呢？
                    因为：既然 j 这边已经确定字符 "A" 无法推进状态，只能回退，
                    而且 KMP 就是要尽可能少的回退，以免多余的计算。
                    那么 j 就可以去问问和自己具有相同前缀的 X，
                    如果 X 遇见 "A" 可以进行「状态推进」，那就转移过去，因为这样回退最少。
                */
            }
        }
    }
public:
    KMP(string dst)
        : m_dst{dst}
        {
            construct_dp();
            //构建dp数组
        }

    //根据构建的dp数组 匹配字符串 src
    int search(string src){
        size_t M{m_dst.size()};
        size_t N{src.size()};
        int j{0};
        for (size_t i = 0; i < N;i++){
            //当前状态是j，遇到字符src[i]
            // m_dst应该转移到哪个状态?
            j = m_dp[j][src[i]];
            //如果到达终止态，返回匹配开头的索引
            if(j==M)
            {
                return i - M + 1;
            }
        }
        return -1;
    }
};
```
