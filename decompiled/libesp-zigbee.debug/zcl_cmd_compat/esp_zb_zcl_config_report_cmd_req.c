/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_config_report_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_config_report_cmd_req(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  void *__ptr;
  int iVar3;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  void *pvStack_14;
  
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  pvStack_14 = (void *)0x0;
  if (param_1 == 0) {
    esp_log(0x11,"ZCL_CMD_COMPAT","%s(%d): Invalid Argument","esp_zb_zcl_config_report_cmd_req",
            0x107);
    uVar2 = 0xff;
  }
  else if ((*(ushort *)(param_1 + 0x12) == 0) || (*(int *)(param_1 + 0x14) == 0)) {
    esp_log(0x11,"ZCL_CMD_COMPAT","%s(%d): Invalid record","esp_zb_zcl_config_report_cmd_req",0x108)
    ;
    uVar2 = 0xff;
  }
  else {
    __ptr = malloc((uint)*(ushort *)(param_1 + 0x12) * 0x18);
    if (__ptr == (void *)0x0) {
      esp_log(0x11,"ZCL_CMD_COMPAT","%s(%d): Out of memory","esp_zb_zcl_config_report_cmd_req",0x10b
             );
      uVar2 = 0xff;
    }
    else {
      for (uVar1 = 0; uVar1 < *(ushort *)(param_1 + 0x12); uVar1 = uVar1 + 1 & 0xffff) {
        convert_esp_config_report_record_to_ezb
                  ((void *)(uVar1 * 0x18 + (int)__ptr),*(int *)(param_1 + 0x14) + uVar1 * 0x10);
      }
      convert_to_ezb_general_cmd_ctrl(&uStack_34,param_1);
      uStack_18 = CONCAT22(uStack_18._2_2_,*(undefined2 *)(param_1 + 0x12));
      pvStack_14 = __ptr;
      iVar3 = ezb_zcl_config_report_cmd_req(&uStack_34);
      if (iVar3 == 0) {
        uVar2 = zcl_get_current_tsn();
      }
      else {
        uVar2 = 0xff;
      }
      free(__ptr);
    }
  }
  return uVar2;
}

