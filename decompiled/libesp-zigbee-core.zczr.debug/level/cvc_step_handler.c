/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> cvc_step_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cvc_step_handler(undefined4 param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int unaff_s4;
  undefined1 local_40 [4];
  uint uStack_3c;
  uint uStack_38;
  undefined2 uStack_34;
  uint uStack_30;
  undefined1 uStack_2c;
  code *pcStack_28;
  undefined4 uStack_24;
  
  if (param_3 == (char *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level.c",0x1ab,
                  "cvc_step_handler","param");
  }
  else {
    unaff_s4 = level_srv_get_attr_desc(0);
    iVar1 = level_srv_get_attr_desc(param_1,2);
    param_4 = level_srv_get_attr_desc(param_1,3);
    if (iVar1 != 0) {
      uVar3 = (uint)**(byte **)(iVar1 + 8);
      goto _L0;
    }
  }
  uVar3 = 0;
_L0:
  if (param_4 == 0) {
    uVar2 = 0xff;
  }
  else {
    uVar2 = (uint)**(byte **)(param_4 + 8);
  }
  uStack_3c = (uint)**(byte **)(unaff_s4 + 8);
  local_40[0] = (undefined1)param_1;
  uStack_34 = 1;
  uStack_30 = (uint)*(ushort *)(param_3 + 2);
  uStack_2c = 0;
  if (param_2 == 0) {
    pcStack_28 = level_cvc_output_handler;
  }
  else {
    pcStack_28 = level_cvc_with_on_off_output_handler;
  }
  uStack_24 = 0;
  if (*param_3 == '\0') {
    uStack_38 = (byte)param_3[1] + uStack_3c;
    if ((uVar2 <= uStack_38) && (uStack_38 = uVar2, (byte)param_3[1] != 0)) {
      uStack_30 = (uStack_30 * (uVar2 - uStack_3c)) / (uint)(byte)param_3[1];
    }
  }
  else {
    uStack_38 = uStack_3c - (byte)param_3[1];
    if (((int)uStack_38 <= (int)uVar3) && (uStack_38 = uVar3, (byte)param_3[1] != 0)) {
      uStack_30 = (uStack_30 * (uStack_3c - uVar3)) / (uint)(byte)param_3[1];
    }
  }
  schedule_cvc_level(param_1,local_40);
  return;
}

