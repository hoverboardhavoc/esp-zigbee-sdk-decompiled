/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_check_binding
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
  undefined1 auStack_24 [2];
  undefined2 uStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = 0;
  uStack_14 = 0;
  nwk_get_extended_address();
  iVar1 = aps_bind_table_find_src(param_1,0x20);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = nwk_address_extended_by_short(param_3,&uStack_18);
    if (iVar2 == 0) {
      auStack_24[0] = 3;
      uStack_22 = (undefined2)uStack_18;
      uStack_20 = uStack_18._2_2_;
      uStack_1e = (undefined2)uStack_14;
      uStack_1c = uStack_14._2_2_;
      iVar2 = aps_bind_table_find_dst(auStack_24,param_2);
      if (iVar2 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = aps_bind_table_has_binding(iVar1,iVar2);
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}

