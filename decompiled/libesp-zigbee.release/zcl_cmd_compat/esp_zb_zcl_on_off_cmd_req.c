/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_on_off_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_on_off_cmd_req(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_28 [32];
  
  memset(auStack_28,0,0x18);
  if (param_1 != 0) {
    convert_to_ezb_specific_cmd_ctrl(auStack_28,param_1);
    cVar1 = *(char *)(param_1 + 0xb);
    if (cVar1 == '\x01') {
      iVar2 = ezb_zcl_on_off_on_cmd_req(auStack_28);
    }
    else if (cVar1 == '\x02') {
      iVar2 = ezb_zcl_on_off_toggle_cmd_req(auStack_28);
    }
    else {
      if (cVar1 != '\0') {
        return 0xff;
      }
      iVar2 = ezb_zcl_on_off_off_cmd_req(auStack_28);
    }
    if (iVar2 == 0) {
      uVar3 = zcl_get_current_tsn();
      return uVar3;
    }
  }
  return 0xff;
}

