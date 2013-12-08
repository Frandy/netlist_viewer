/**
* @class Instance is an instance of a module
* keeps pointer to it's master module
* also keeps pointer to its parent module - where it have been instansiated
**/

#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include <string>
#include <vector>
#include "instance_port.hpp"
class Module;

class Instance
{
private:
//    Instance (const Instance&);
//    void operator=(const Instance&);
public:
	typedef std::vector<InstancePort> InstPortCollection;
	Instance(std::string n, const Module* mModule, const Module* pModule);
	
	const std::string& name() const;
	void setName(const std::string& n); 
    void addPort(const InstancePort& port);
    const InstPortCollection& ports() const;
	const Module* masterModule() const;	
    const Module* parentModule() const;	
    void setMasterModule(const Module* module);		
	void setParentModule(const Module* module);

private:
	std::string name_;
	const Module* masterModule_;
	const Module* parentModule_;
	InstPortCollection ports_;
};

#endif // INSTANCE_HPP