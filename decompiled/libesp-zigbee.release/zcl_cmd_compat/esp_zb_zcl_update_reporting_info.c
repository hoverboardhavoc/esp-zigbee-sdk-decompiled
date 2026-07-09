/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_update_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_update_reporting_info(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_18 [12];
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x40);
    uVar2 = 0x102;
    if (iVar1 != 0) {
      memcpy(auStack_18,(void *)(param_1 + 0x20),8);
      ezb_zcl_reporting_info_update
                (iVar1,*(undefined2 *)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x1a),auStack_18);
      uVar2 = esp_zigbee_err_to_esp();
    }
    return uVar2;
  }
  return 0x102;
}

