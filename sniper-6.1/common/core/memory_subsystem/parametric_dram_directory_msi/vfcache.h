#ifndef VFCACHE_H
#define VFCACHE_H

#include "fixed_types.h"
#include "cache.h"

namespace ParametricDramDirectoryMSI
{
   class VFCACHE
   {
      private:
         //static const UInt32 SIM_PAGE_SHIFT = 12; // 4KB
         //static const IntPtr SIM_PAGE_SIZE = (1L << SIM_PAGE_SHIFT);
         //static const IntPtr SIM_PAGE_MASK = ~(SIM_PAGE_SIZE - 1);
	 static const UInt32 SIM_LINE_SIZE = 8; //unsure what to put here yet 

         UInt32 m_size;
         UInt32 m_associativity;
         Cache m_cache;

         VFCACHE *m_next_level;

         UInt64 m_access, m_miss;
      public:
         VFCACHE(String name, String cfgname, core_id_t core_id, UInt32 num_entries, UInt32 associativity, VFCACHE *next_level);
         bool lookup(IntPtr address, SubsecondTime now, bool allocate_on_miss = true);
         void allocate(IntPtr address, SubsecondTime now);
   };
}

#endif // TLB_H
