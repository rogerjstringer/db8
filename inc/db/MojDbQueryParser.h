/* @@@LICENSE
*
*      Copyright (c) 2012 Hewlett-Packard Development Company, L.P.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* LICENSE@@@ */


#ifndef MOJDBQUERYPARSER_H_
#define MOJDBQUERYPARSER_H_

#include "db/MojDbDefs.h"

class MojDbQueryParser
{
public:
	MojDbQueryParser();

	MojErr parse(const MojChar* str, MojSize len = MojSizeMax);

private:
	typedef enum {
		StateWhitespace,
		StateSelect,
		StatePropName,
		StateObject,
		StateComp
	} State;

	static const MojSize MaxStackDepth = 3;

	State m_stack[MaxStackDepth];
	MojSize m_depth;
};

#endif /* MOJDBQUERYPARSER_H_ */
