#include <Commands/Command.h>
#include "../CommandBase.h"
#include "Commands/Subsystem.h"
#include "../Robot.h"

class ClimbWithButton: public CommandBase {
public:
	typedef enum {
		climbExtend,
		climbRetract
	} climbDirection;
	float speed;

	ClimbWithButton(climbDirection dir, float Value);
	virtual void Execute();
	virtual void Initialize();
	virtual bool IsFinished();
	virtual void End();
	virtual ~ClimbWithButton();
private:
	climbDirection direction;
};
