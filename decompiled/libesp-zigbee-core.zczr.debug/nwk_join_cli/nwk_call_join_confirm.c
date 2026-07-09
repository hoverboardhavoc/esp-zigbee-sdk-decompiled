/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_call_join_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_call_join_confirm(undefined1 param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + 0xac0) = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_1c._0_2_ = CONCAT11(param_1,(char)param_2);
  uStack_1c = (uint)(ushort)uStack_1c;
  if (param_2 == 0) {
    uVar1 = nwk_get_short_address();
  }
  else {
    uVar1 = 0xffff;
  }
  uStack_1c = CONCAT22(uVar1,(ushort)uStack_1c);
  puVar3 = (undefined4 *)nwk_get_extended_panid();
  uStack_18 = *puVar3;
  uStack_14 = puVar3[1];
  nwk_join_confirm(&uStack_1c);
  return;
}

