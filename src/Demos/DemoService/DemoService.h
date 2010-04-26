#pragma once

class DemoService : public AppSecInc::Service::ServiceImpl
{
public:
	DemoService();
protected:
	void Run();
};
