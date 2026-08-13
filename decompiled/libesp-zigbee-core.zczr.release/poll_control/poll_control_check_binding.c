/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> poll_control.o -> poll_control_check_binding
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 poll_control_check_binding(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [2];
  undefined1 auStack_1a [10];
  
  uStack_24 = 0;
  uStack_20 = 0;
  nwk_get_extended_address();
  iVar1 = aps_bind_table_find_src(param_1,0x20);
  if ((iVar1 != 0) && (iVar2 = nwk_address_extended_by_short(param_3,&uStack_24), iVar2 == 0)) {
    auStack_1c[0] = 3;
    memcpy(auStack_1a,&uStack_24,8);
    iVar2 = aps_bind_table_find_dst(auStack_1c,param_2);
    if (iVar2 != 0) {
      uVar3 = aps_bind_table_has_binding(iVar1,iVar2);
      return uVar3;
    }
  }
  return 0;
}

