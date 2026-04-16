/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_frame_is_from_coord
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool mac_frame_is_from_coord(mac_device *dev,mac_frame_t *mac_frame)

{
  ezb_addr_mode_t eVar1;
  _Bool _Var2;
  
  eVar1 = (mac_frame->mhr).src_addr.addr_mode;
  if ((eVar1 == '\x02') && ((dev->pib).coord_shortaddr == (mac_frame->mhr).src_addr.u.short_addr)) {
    _Var2 = true;
  }
  else if (eVar1 == '\x03') {
    if (((mac_frame->mhr).src_addr.u.group_addr ==
         *(ezb_grpaddr_t *)&(dev->pib).coord_extaddr.field_0) &&
       (*(int *)((int)&(mac_frame->mhr).src_addr.u + 4) ==
        *(int *)((int)&(dev->pib).coord_extaddr.field_0 + 4))) {
      _Var2 = true;
    }
    else {
      _Var2 = false;
    }
  }
  else {
    _Var2 = false;
  }
  return _Var2;
}

