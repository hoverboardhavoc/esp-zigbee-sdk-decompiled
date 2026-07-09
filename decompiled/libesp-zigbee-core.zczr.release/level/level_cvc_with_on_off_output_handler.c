/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> level_cvc_with_on_off_output_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void level_cvc_with_on_off_output_handler(undefined4 param_1,byte param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  undefined1 uStack_11;
  
  level_cvc_output_handler();
  iVar2 = ezb_zcl_get_attr_desc(6,1,0,0);
  iVar3 = level_srv_get_attr_desc(param_1,2);
  if (iVar2 != 0) {
    bVar4 = 0;
    if (iVar3 != 0) {
      bVar4 = **(byte **)(iVar3 + 8);
    }
    if (bVar4 < param_2) {
      uStack_11 = 1;
      if (**(char **)(iVar2 + 8) == '\0') {
_L105:
        iVar2 = zcl_set_attr_value(6,1,0,0,&uStack_11,0);
        if (iVar2 == 0) {
          uVar1 = ezb_zcl_get_attr_desc(param_1,6,1,0,0);
          zcl_message_notify_attr_value(param_1,6,1,uVar1);
        }
        return;
      }
    }
    else if (**(char **)(iVar2 + 8) != '\0') {
      uStack_11 = 0;
      goto _L105;
    }
  }
  return;
}

