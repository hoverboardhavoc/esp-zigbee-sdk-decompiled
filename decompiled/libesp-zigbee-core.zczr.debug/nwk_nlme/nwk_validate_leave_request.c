/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_validate_leave_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_validate_leave_request(ezb_shortaddr_t src_addr,ezb_shortaddr_t dst_addr,_Bool rejoin)

{
  undefined2 in_register_0000202a;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 in_register_0000202e;
  undefined3 in_register_00002031;
  
  iVar1 = nwk_is_device_zc();
  if (iVar1 == 0) {
    iVar1 = 0;
    iVar4 = iVar1;
    if (0xfff7 < CONCAT22(in_register_0000202e,dst_addr)) goto _L0;
    iVar2 = nwk_is_device_zr();
    if (iVar2 != 0) {
      iVar3 = core_globals_get();
      if ((((*(byte *)(iVar3 + 0xa2a) & 2) != 0) &&
          (iVar4 = CONCAT31(in_register_00002031,rejoin), CONCAT31(in_register_00002031,rejoin) == 0
          )) && (iVar3 = core_globals_get(), iVar4 = iVar1, (*(byte *)(iVar3 + 0xa2a) & 4) != 0)) {
        iVar4 = iVar2;
      }
      goto _L0;
    }
    iVar4 = nwk_is_device_zed();
    if (iVar4 != 0) {
      iVar1 = nwk_get_parent_shortaddr();
      if (iVar1 != CONCAT22(in_register_0000202a,src_addr)) {
        iVar4 = iVar2;
      }
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x22f,
                  "nwk_validate_leave_request",&_LC18);
  }
  iVar4 = 0;
_L0:
  return SUB41(iVar4,0);
}

