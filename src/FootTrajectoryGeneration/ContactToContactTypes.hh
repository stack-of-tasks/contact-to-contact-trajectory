
/*
 * Copyright 2008, 2009, 2010, 2016
 *
 * Olivier Stasse
 *
 * JRL, CNRS/AIST
 * LAAS, CNRS
 *
 * This file is part of contact-to-contact-trajectory.
 * contact-to-contact-trajectory is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * contact-to-contact-trajectory is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Lesser Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License
 * along with contact-to-contact-trajectory.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _CONTACT_TO_CONTACT_TYPES_H_
#define _CONTACT_TO_CONTACT_TYPES_H_

namespace PatternGeneratorJRL
{
  /// Structure to store the absolute foot position.
  struct FootAbsolutePosition_t
  {
    /*! px, py in meters, theta in DEGREES. */
    double x,y,z, theta, omega, omega2;
    /*! Speed of the foot. */
    double dx,dy,dz, dtheta, domega, domega2;
    /*! Acceleration of the foot. */
    double ddx,ddy,ddz, ddtheta, ddomega, ddomega2;
    /*! Time at which this position should be reached. */
    double time;
    /*! 1:normal walking 2:one step before obstacle
      3:first leg over obstacle 4:second leg over obstacle 5:one step after obstacle
      +10 if double support phase
      (-1) if support foot  */
    int stepType;
  };
  typedef struct FootAbsolutePosition_t FootAbsolutePosition;

  inline std::ostream & operator<<(std::ostream & os, const FootAbsolutePosition & fap)
  {
    os << "x " << fap.x << " y " << fap.y << " z " << fap.z << " theta " << fap.theta << " omega " << fap.omega << " omega2 " << fap.omega2 << std::endl;
    os << "dx " << fap.dx << " dy " << fap.dy << " dz " << fap.dz << " dtheta " << fap.dtheta << " domega " << fap.domega << " domega2 " << fap.domega2 << std::endl;
    os << "ddx " << fap.ddx << " ddy " << fap.ddy << " ddz " << fap.ddz << " ddtheta " << fap.ddtheta << " ddomega " << fap.ddomega << " ddomega2 " << fap.ddomega2 << std::endl;
    os << "time " << fap.time << " stepType " << fap.stepType;
    return os;
  }

  /** Structure to store each foot position when the user is specifying
      a sequence of relative positions. */
  struct RelativeFootPosition_s
  {
    double sx,sy,theta;
    double SStime;
    double DStime;
    int stepType;     //1:normal walking 2:one step before obstacle
                      //3:first leg over obstacle 4:second leg over obstacle 5:one step after obstacle
    double DeviationHipHeight;
  };
  typedef struct RelativeFootPosition_s RelativeFootPosition;

  inline std::ostream & operator<<(std::ostream & os, const RelativeFootPosition_s & rfp)
  {
    os << "sx " << rfp.sx << " sy " << rfp.sy << " theta " << rfp.theta << std::endl;
    os << "SStime " << rfp.SStime << " DStime " << rfp.DStime << " stepType " << rfp.stepType << " DeviationHipHeight " << rfp.DeviationHipHeight;
    return os;
  }

  /// \name Enum types
  /// \{
  enum foot_type_e
  {
    LEFT, RIGHT
  };

  inline std::ostream & operator<<(std::ostream & out, const foot_type_e & ft)
  {
    switch(ft)
    {
      case LEFT:
        out << "LEFT";
        break;
      default:
        out << "RIGHT";
    }
    return out;
  }

  enum PhaseType
  {
    SS, DS
  };

  inline std::ostream & operator<<(std::ostream & out, const PhaseType & pt)
  {
    switch(pt)
    {
      case SS:
        out << "SingleSupport";
        break;
      default:
        out << "DoubleSupport";
    }
    return out;
  }

  /// \brief Support state of the robot at a certain point in time
  struct support_state_t
  {

    /// \brief Support phase
    PhaseType Phase;
    /// \brief Support foot
    foot_type_e Foot;
    /// \brief Number steps left before double support
    unsigned int NbStepsLeft;
    /// \brief Number of step previewed
    unsigned int StepNumber;
    /// \brief Number of samplings passed in this phase
    unsigned int NbInstants;

    /// \brief Time until StateChanged == true
    double TimeLimit;
    /// \brief start time
    double StartTime;
    /// \brief Position and orientation on a plane
    double X,Y,Yaw;

    /// \brief (true) -> New single support state
    bool StateChanged;

    struct support_state_t & operator = (const support_state_t &aSS);

    void reset();

    support_state_t();
  };

  inline std::ostream & operator<<(std::ostream & out, const support_state_t & st)
  {
    out << "SupportState" << std::endl;
    out << "PhaseType " << st.Phase << std::endl;
    out << "Foot " << st.Foot << std::endl;
    out << "NbStepsLeft " << st.NbStepsLeft << std::endl;
    out << "StepNumber " << st.StepNumber << std::endl;
    out << "NbInstants " << st.NbInstants << std::endl;
    out << "TimeLimit " << st.TimeLimit << std::endl;
    out << "StartTime " << st.StartTime << std::endl;
    out << "X " << st.X << std::endl;
    out << "Y " << st.Y << std::endl;
    out << "Yaw " << st.Yaw << std::endl;
    out << "StateChanged " << st.StateChanged;
    return out;
  }

}

#endif
