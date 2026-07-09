/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> move_cvc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void move_cvc_handler(undefined4 param_1,int param_2,char *param_3)

{
  int iVar1;
  uint uVar2;
  int unaff_s3;
  uint uVar3;
  int unaff_s4;
  undefined1 local_40 [4];
  uint uStack_3c;
  uint uStack_38;
  undefined2 uStack_34;
  int iStack_30;
  undefined1 uStack_2c;
  code *pcStack_28;
  undefined4 uStack_24;
  
  if (param_3 == (char *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level.c",0x16b,
                  "move_cvc_handler","param");
  }
  else {
    iVar1 = level_srv_get_attr_desc(2);
    unaff_s3 = level_srv_get_attr_desc(param_1,3);
    unaff_s4 = level_srv_get_attr_desc(param_1,0x14);
    if (iVar1 != 0) {
      uVar2 = (uint)**(byte **)(iVar1 + 8);
      goto _L0;
    }
  }
  uVar2 = 0;
_L0:
  if (unaff_s3 == 0) {
    uVar3 = 0xff;
  }
  else {
    uVar3 = (uint)**(byte **)(unaff_s3 + 8);
  }
  local_40[0] = (undefined1)param_1;
  iVar1 = level_srv_get_attr_desc(param_1,0);
  uStack_3c = (uint)**(byte **)(iVar1 + 8);
  if (*param_3 == '\0') {
    uVar2 = uVar3;
  }
  uStack_34 = 1;
  uStack_2c = 0;
  if (param_2 == 0) {
    pcStack_28 = level_cvc_output_handler;
  }
  else {
    pcStack_28 = level_cvc_with_on_off_output_handler;
  }
  uStack_24 = 0;
  if ((byte)param_3[1] == 0xff) {
    if (unaff_s4 == 0) {
      iStack_30 = 0xffff;
    }
    else {
      if (uStack_3c < uVar2) {
        iVar1 = uVar2 - uStack_3c;
      }
      else {
        iVar1 = uStack_3c - uVar2;
      }
      iStack_30 = (iVar1 * 10) / (int)(uint)**(byte **)(unaff_s4 + 8);
    }
  }
  else {
    if (uStack_3c < uVar2) {
      iVar1 = uVar2 - uStack_3c;
    }
    else {
      iVar1 = uStack_3c - uVar2;
    }
    iStack_30 = (iVar1 * 10) / (int)(uint)(byte)param_3[1];
  }
  uStack_38 = uVar2;
  schedule_cvc_level(param_1,local_40);
  return;
}

