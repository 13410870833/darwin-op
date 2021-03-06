#include "CM730.h"
#include "MX28.h"
#include "joint.h"

Joint::Joint(CM730 &cm730, unsigned char id):
	DxlPeripheral(cm730)
{
	m_id = id;
}

bool Joint::WriteTorqueEnable(bool enable)
{
	int result;
	if (enable)
		result = sub_controller.WriteByte(m_id, MX28::P_TORQUE_ENABLE, 1, 0);
	else
		result = sub_controller.WriteByte(m_id, MX28::P_TORQUE_ENABLE, 0, 0);
	return (result == CM730::SUCCESS);
}

bool Joint::WriteRawPosition(unsigned short pos)
{
	int result;
	result = sub_controller.WriteWord(m_id, MX28::P_GOAL_POSITION_L, pos, 0);
	return (result == CM730::SUCCESS);
}

bool Joint::ReadTorqueEnable(bool &enable)
{
	int result, value;
	result = sub_controller.ReadByte(m_id, MX28::MX28::P_TORQUE_ENABLE, &value, 0);
	enable = (value != 0);
	return (result == CM730::SUCCESS);
}

bool Joint::ReadRawPosition(unsigned short &pos)
{
	int result, value;
	result = sub_controller.ReadWord(m_id, MX28::P_PRESENT_POSITION_L, &value, 0);
	pos = value;
	return (result == CM730::SUCCESS);
}

