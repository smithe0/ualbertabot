#pragma once;

#include <Common.h>
#include "MicroManager.h"

namespace UAlbertaBot
{
class TankManager : public MicroManager
{
public:

	TankManager();
	void executeMicro(const BWAPI::Unitset & targets);
	void executeSiegeDefense(const BWAPI::Unitset & targets); // orders a subset of tanks to siege at the closest chokepoint to our base (base entrance)
	BWAPI::Unit chooseTarget(BWAPI::Unit rangedUnit, const BWAPI::Unitset & targets, std::map<BWAPI::Unit, int> & numTargeting);
	BWAPI::Unit closestrangedUnit(BWAPI::Unit target, std::set<BWAPI::Unit> & rangedUnitsToAssign);

	int getAttackPriority(BWAPI::Unit rangedUnit, BWAPI::Unit target);
	BWAPI::Unit getTarget(BWAPI::Unit rangedUnit, const BWAPI::Unitset & targets);
};
}