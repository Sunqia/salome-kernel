// Copyright (C) 2005  OPEN CASCADE, EADS/CCR, LIP6, CEA/DEN,
// CEDRAT, EDF R&D, LEG, PRINCIPIA R&D, BUREAU VERITAS
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either 
// version 2.1 of the License.
// 
// This library is distributed in the hope that it will be useful 
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public  
// License along with this library; if not, write to the Free Software 
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//
#ifndef  SALOMEDSCLIENT_DEF_HXX
#define  SALOMEDSCLIENT_DEF_HXX

#include <boost/shared_ptr.hpp> 

template<class T> class clt_shared_ptr: public boost::shared_ptr<T>
{
public:
  clt_shared_ptr() {}
  
  template<class Y>
    explicit clt_shared_ptr(Y * p)
      {
	reset(p);
      }
  
  template<class Y>
    clt_shared_ptr(clt_shared_ptr<Y> const & r):
      boost::shared_ptr<T>(r,boost::detail::dynamic_cast_tag())
	{}
  
  template<class Y>
    clt_shared_ptr & operator=(clt_shared_ptr<Y> const & r)
      {
	clt_shared_ptr<T>(r).swap(*this);
	return *this;
      }
  
  template<class Y> clt_shared_ptr& operator()(Y * p) // Y must be complete
    {
      if(T* pt = dynamic_cast<T*>(p))
	boost::shared_ptr<T>::reset(pt);
      else
	boost::throw_exception(std::bad_cast());
      return *this;
    }
    
};

#define _PTR(Class) clt_shared_ptr<SALOMEDSClient_##Class>
#define _CAST(Class, shared_ptr_Obj) dynamic_cast<SALOMEDS_##Class*>(shared_ptr_Obj.get())

struct STextColor
{
    double R;
    double G;
    double B;
};

#endif
