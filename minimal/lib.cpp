#include "lib.hpp"

//#include "Blueprint.h"
// #include "ParserCore.h"
// #include "SourceAnnotation.h"
// #include "Parser.h"
#include "SerializeJSON.h"
#include "snowcrash.h"

#include <iostream>
#include <string>

using namespace snowcrash;

std::string myfn() 
{
	snowcrash::SourceData blueprintSource = R"(
	# APINAME

	## GET /message
	+ Response 200 (text/plain)

	        Hello World!
	)";
	
	snowcrash::Result result;
	snowcrash::Blueprint blueprintAst;

	snowcrash::parse(blueprintSource, 0, result, blueprintAst);

	// ResourceGroup& resourceGroup = ast.resourceGroups.front();
	// Resource& resource = resourceGroup.resources.front();

	// std::cout << "URI Template: " << resource.uriTemplate << std::endl;

	std::stringstream jsonStream;
	SerializeJSON(blueprintAst, jsonStream);

	// std::cout << outputStream.rdbuf();
	// std::cerr << std::endl;


	return jsonStream.str();
}
