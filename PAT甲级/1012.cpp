#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<string, int> m_stu;
int main(void)
{

    int n, querys;
    cin >> n >> querys;
    string id;
    // 构造学生成绩数据
    vector<vector<int>> data{n, {0, 0, 0, 0}};
    for (int i = 0; i < n; i++)
    {
        cin >> id >> data[i][0] >> data[i][1] >> data[i][2];
        m_stu[id] = i;
        data[i][3] = (data[i][0] + data[i][1] + data[i][2]) / 3;
    }

    // 开始构造 各学生 各学科（包括A）的排名
    vector<vector<int>> ranks{n, {INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int temp_rank = 1;
            for (int k = 0; k < n; k++)
            {
                if (data[i][j] < data[k][j])
                    temp_rank++;
            }
            ranks[i][j] = temp_rank;
        }
    }

    // 开始查询学生成绩
    string query_id;
    for (int i = 0; i < querys; i++)
    {
        cin >> query_id;

        // 该学生存在
        if (m_stu.count(query_id))
        {
            // 获取A的排名
            int idx = m_stu[query_id];
            int min_idx = 3;
            int min_rank = ranks[idx][3];
            // 根据A及其他科目成绩得到最终排名
            for (int j = 0; j < 3; j++)
            {
                if (ranks[idx][j] < min_rank)
                {
                    min_idx = j;
                    min_rank = ranks[idx][j];
                }
            }
            // 输出最高排名及其学科
            cout << min_rank << " ";
            if (min_idx == 3)
                cout << 'A' << endl;
            if (min_idx == 0)
                cout << 'C' << endl;
            if (min_idx == 1)
                cout << 'M' << endl;
            if (min_idx == 2)
                cout << 'E' << endl;
        }
        else // 该学生不存在
        {
            cout << "N/A" << endl;
        }
    }
}