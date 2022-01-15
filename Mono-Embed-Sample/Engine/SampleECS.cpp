#include "SampleECS.h"

#include <iostream>

namespace SLives
{
	ECS& ECS::GetInstance() { static ECS instance; return instance; }

	void ECS::PrintData() { ECS::GetInstance().IPrintData(); }

	void ECS::AddData(const std::string& _newData) { ECS::GetInstance().IAddData(_newData); }


	void ECS::IPrintData()
	{
		std::cout << "\nPrinting ECS data...\n";
		for (const std::string& data : mSampleData) { std::cout << data << std::endl; }
		std::cout << "Printing complete.\n\n";
	}

	void ECS::IAddData(const std::string& _newData)
	{
		mSampleData.emplace_back(_newData);
	}
}
