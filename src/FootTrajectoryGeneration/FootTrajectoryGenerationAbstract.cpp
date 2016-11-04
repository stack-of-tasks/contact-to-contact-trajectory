/*
 * Copyright 2008, 2009, 2010, 
 *
 * Francois Keith
 * Olivier Stasse
 *
 * JRL, CNRS/AIST
 *
 * This file is part of walkGenJrl.
 * walkGenJrl is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * walkGenJrl is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Lesser Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License
 * along with walkGenJrl.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Research carried out within the scope of the 
 *  Joint Japanese-French Robotics Laboratory (JRL)
 */

/*!\file FootTrajectoryGenerationAbstract.h
   \brief This class determinate how it s generate all the values for the foot trajectories.

   @ingroup foottrajectorygeneration
*/
#include <Debug.hh>
#include "FootTrajectoryGeneration/FootTrajectoryGenerationAbstract.hh"

using namespace PatternGeneratorJRL;

FootTrajectoryGenerationAbstract::FootTrajectoryGenerationAbstract(FootSpecifications *aFoot) 
{
  m_Omega = 0.0;
  m_Foot= aFoot;  
  m_SamplingPeriod = 0.005;
  m_TSingle = 0.7;
  m_TDouble = 0.1;
}

void FootTrajectoryGenerationAbstract::UpdateFootPosition(std::deque<FootAbsolutePosition> & , //SupportFootAbsolutePositions,
							  std::deque<FootAbsolutePosition> &, //NoneSupportFootAbsolutePositions,
							  int , //CurrentAbsoluteIndex,  
							  int , //IndexInitial, 
							  double , //ModulatedSingleSupportTime,
							  int , //StepType, 
							  int ) //LeftOrRight)
{
  LTHROW("FootTrajectoryGenerationAbstract::UpdateFootPosition-1: To be implemented ");
}

void FootTrajectoryGenerationAbstract::UpdateFootPosition(std::deque<FootAbsolutePosition> & ,//SupportFootAbsolutePositions,
							  std::deque<FootAbsolutePosition> & ,//NoneSupportFootAbsolutePositions,
							  int , // StartIndex, 
							  int , //k,
							  double , //LocalInterpolationStartTime,
							  double , //ModulatedSingleSupportTime,
							  int , //StepType, 
							  int ) //LeftOrRight)
{
  LTHROW("FootTrajectoryGenerationAbstract::UpdateFootPosition-2: To be implemented ");
}
