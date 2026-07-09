/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> move_to_cvc_level
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void move_to_cvc_level(undefined4 param_1,int param_2,byte *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 local_30 [4];
  uint uStack_2c;
  uint uStack_28;
  undefined2 uStack_24;
  uint uStack_20;
  undefined1 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (param_3 == (byte *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level.c",0x12a,
                  "move_to_cvc_level","payload");
  }
  else {
    local_30[0] = (undefined1)param_1;
    iVar1 = level_srv_get_attr_desc(0);
    uStack_2c = (uint)**(byte **)(iVar1 + 8);
    uStack_28 = (uint)*param_3;
    uStack_24 = 1;
    uStack_20 = (uint)*(ushort *)(param_3 + 2);
    uStack_1c = 0;
    if (param_2 != 0) {
      pcStack_18 = level_cvc_with_on_off_output_handler;
      goto _L0;
    }
  }
  pcStack_18 = level_cvc_output_handler;
_L0:
  uStack_14 = 0;
  iVar1 = level_srv_get_attr_desc(param_1,2);
  iVar2 = level_srv_get_attr_desc(param_1,3);
  if (iVar1 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (uint)**(byte **)(iVar1 + 8);
  }
  if (iVar2 == 0) {
    uVar3 = 0xff;
  }
  else {
    uVar3 = (uint)**(byte **)(iVar2 + 8);
  }
  uStack_28 = (uint)*param_3;
  if ((int)uStack_2c < (int)uStack_28) {
    if (uVar3 < uStack_28) {
      uStack_28 = uVar3;
    }
  }
  else if (uStack_28 < uVar4) {
    uStack_28 = uVar4;
  }
  uVar4 = (uint)*(ushort *)(param_3 + 2);
  if (*(ushort *)(param_3 + 2) == 0xffff) {
    iVar1 = level_srv_get_attr_desc(param_1,0x10);
    if (iVar1 == 0) {
      uStack_20 = 0xffff;
      uVar4 = uStack_20;
    }
    else {
      uVar4 = (uint)**(ushort **)(iVar1 + 8);
    }
  }
  uStack_20 = uVar4;
  schedule_cvc_level(param_1,local_30);
  return;
}

