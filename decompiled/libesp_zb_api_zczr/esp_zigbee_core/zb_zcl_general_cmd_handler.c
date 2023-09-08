/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_general_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zb_zcl_general_cmd_handler(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = zb_buf_get_tail_func(0x1b);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else if (*(char *)(iVar2 + 0x14) == '\x01') {
    if (zb_core_action_cb == 0) {
      uVar3 = 0;
    }
    else {
      bVar1 = *(byte *)(iVar2 + 0x13);
      if (bVar1 == 7) {
        iVar5 = zcl_cmd_config_report_resp_handler(param_1);
      }
      else if (bVar1 < 8) {
        if (bVar1 == 1) {
          iVar5 = zcl_cmd_read_attr_resp_handler(param_1);
        }
        else {
          if (bVar1 != 4) {
            return 0;
          }
          iVar5 = zcl_cmd_write_attr_resp_handler(param_1);
        }
      }
      else if (bVar1 == 0xd) {
        iVar5 = zcl_cmd_disc_attr_resp_handler(param_1);
      }
      else {
        if (0xd < bVar1) {
          if (((bVar1 != 0x14) && (bVar1 != 0x16)) && (bVar1 != 0x12)) {
            return 0;
          }
          uVar4 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC27,uVar4,"ESP_ZIGBEE_CORE",
                        *(undefined1 *)(iVar2 + 0x13));
          return 0;
        }
        if (bVar1 != 9) {
          return 0;
        }
        iVar5 = zcl_cmd_read_report_config_resp_handler(param_1);
      }
      uVar3 = (uint)*(byte *)(iVar2 + 0x17);
      if (uVar3 == 0) {
        uVar3 = zb_zcl_send_default_handler(param_1,iVar2,iVar5 != 0);
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

