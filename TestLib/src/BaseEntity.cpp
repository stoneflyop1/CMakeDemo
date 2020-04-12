#pragma once
#include <TestLib/Generator.h>
#include <TestLib/BaseEntity.h>

namespace TestLib {
	BaseEntity::BaseEntity() {
		id_ = Generator::NextId();
	}
}