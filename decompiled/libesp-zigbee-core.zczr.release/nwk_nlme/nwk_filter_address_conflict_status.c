/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_filter_address_conflict_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_filter_address_conflict_status(int param_1,undefined4 param_2)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  char local_11 [5];
  
  local_11[0] = '\0';
  uVar2 = zmsg_get_offset();
  zmsg_read_bytes(param_1,uVar2,1,local_11);
  uVar3 = 0;
  if ((*(ushort *)(param_1 + 0x16) & 8) == 0) {
    uVar3 = 0;
    if (local_11[0] == '\x03') {
      sVar1 = zmsg_get_offset(param_1);
      uVar3 = zmsg_compare_bytes(param_1,sVar1 + 1,param_2,3);
    }
  }
  return uVar3 & 1;
}

