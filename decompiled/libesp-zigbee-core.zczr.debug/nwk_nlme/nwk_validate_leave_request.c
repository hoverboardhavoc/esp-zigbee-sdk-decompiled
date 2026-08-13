/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_validate_leave_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_validate_leave_request(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = nwk_is_device_zc();
  if (iVar1 == 0) {
    if (0xfff7 < param_2) {
      return 0;
    }
    iVar1 = nwk_is_device_zr();
    if (iVar1 != 0) {
      iVar2 = core_globals_get();
      if ((*(byte *)(iVar2 + 0xa2a) & 2) == 0) {
        return 0;
      }
      if (param_3 != 0) {
        return param_3;
      }
      iVar2 = core_globals_get();
      if ((*(byte *)(iVar2 + 0xa2a) & 4) == 0) {
        return 0;
      }
      return iVar1;
    }
    iVar1 = nwk_is_device_zed();
    if (iVar1 != 0) {
      iVar2 = nwk_get_parent_shortaddr();
      if (iVar2 == param_1) {
        return iVar1;
      }
      return 0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_nlme.c",0x233,
                  "nwk_validate_leave_request",&_LC18);
  }
  return 0;
}

