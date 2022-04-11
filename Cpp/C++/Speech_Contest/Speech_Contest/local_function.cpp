#include "local_function.h"

LocalFunction::LocalFunction()
{
	string referees_name = " 编号    姓名   ";
	for (int i = 0; i < 10; i++)
	{
		referees_name += "裁判" + std::to_string(i + 1) + "   ";
	}
	referees_name += "最终得分";
	sprintf_s(this->referees, sizeof(this->referees), "%s", referees_name.c_str());
}

void LocalFunction::show_header()
{
	string headers[4];
	headers[0] = " 编号";
	headers[1] = " 姓名";
	headers[2] = "淘汰赛成绩";
	headers[3] = "决赛成绩";
	char output[1024];
	sprintf_s(output, sizeof(output), "%-6s  %-6s  %4s  %4s", headers[0].c_str(), headers[1].c_str(), headers[2].c_str(), headers[3].c_str());
	cout << output << endl;
}

float LocalFunction::show_get_scorelab(const Person& p)
{
	char output_score[1024];
	float scores[10];
	int min_scores_index = 0;
	int max_scores_index = 0;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		scores[i] = rand() % 3000 / 100. + 70;
		if (scores[i] > scores[max_scores_index])
		{
			max_scores_index = i;
		}
		if (scores[i] < scores[min_scores_index])
		{
			min_scores_index = i;
		}
	}
	string contestant_number = std::to_string(p.m_number);
	contestant_number = string((6 - contestant_number.size()), '0') + contestant_number;
	string output_lable = contestant_number + string(3, ' ') + p.m_name + string(3, ' ');
	float average_score = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i == max_scores_index or i == min_scores_index)
		{
			output_lable += "(" + std::to_string(scores[i]).substr(0, 5) + ") ";
		}
		else
		{
			output_lable += " " + std::to_string(scores[i]).substr(0, 5) + "  ";
			average_score += scores[i];
		}
	}
	average_score /= 8;
	output_lable += "   " + std::to_string(average_score).substr(0, 5);
	sprintf_s(output_score, sizeof(output_score), "%s", output_lable.c_str());
	cout << this->referees << endl;
	cout << output_score << endl;
	return average_score;
}


