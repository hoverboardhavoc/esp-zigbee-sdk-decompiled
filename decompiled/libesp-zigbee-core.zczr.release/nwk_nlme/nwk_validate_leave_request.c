/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_validate_leave_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_validate_leave_request(ezb_shortaddr_t src_addr,ezb_shortaddr_t dst_addr,_Bool rejoin)

{
  uint uVar1;
  undefined2 in_register_0000202a;
  int iVar2;
  undefined2 in_register_0000202e;
  undefined3 in_register_00002031;
  
  uVar1 = CONCAT31(in_register_00002031,rejoin);
  iVar2 = nwk_is_device_zc();
  if ((iVar2 == 0) && (CONCAT22(in_register_0000202e,dst_addr) < 0xfff8)) {
    iVar2 = nwk_is_device_zr();
    if (iVar2 == 0) {
      iVar2 = nwk_is_device_zed();
      if (iVar2 != 0) {
        iVar2 = nwk_get_parent_shortaddr();
        uVar1 = (uint)(iVar2 == CONCAT22(in_register_0000202a,src_addr));
        goto _L0;
      }
      __assert_func(0,0,0);
    }
    else {
      iVar2 = core_globals_get();
      if ((*(byte *)(iVar2 + 0xa2a) & 2) != 0) {
        if (uVar1 == 0) {
          iVar2 = core_globals_get();
          uVar1 = *(ushort *)(iVar2 + 0xa2a) >> 2 & 1;
        }
        goto _L0;
      }
    }
  }
  uVar1 = 0;
_L0:
  return SUB41(uVar1,0);
}

