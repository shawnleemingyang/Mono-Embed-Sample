// ECS Singleton
#ifndef SAMPLEECS_H
#define SAMPLEECS_H

#include <vector>
#include <string>

namespace SLives
{
	class ECS
	{
	public:
		static ECS& GetInstance();
		static void PrintData();
		static void AddData(const std::string& _newData);

	private:
		void IPrintData();
		void IAddData(const std::string& _newData);

	private:
		std::vector<std::string> mSampleData;
	};
}


#endif
