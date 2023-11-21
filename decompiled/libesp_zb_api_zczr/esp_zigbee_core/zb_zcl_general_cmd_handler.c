/*
 * Last changed at upstream commit 6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * https://github.com/espressif/esp-zigbee-sdk/commit/6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * Upstream date: 2023-11-21 18:28:11 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.4(be3a8a97)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_general_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_general_cmd_handler(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
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
        iVar4 = zcl_cmd_config_report_resp_handler(param_1);
      }
      else if (bVar1 < 8) {
        if (bVar1 == 1) {
          if (*(short *)(iVar2 + 0xf) == 10) {
            return 0;
          }
          iVar4 = zcl_cmd_read_attr_resp_handler(param_1);
        }
        else {
          if (bVar1 != 4) {
            return 0;
          }
          iVar4 = zcl_cmd_write_attr_resp_handler(param_1);
        }
      }
      else if (bVar1 == 0xd) {
        iVar4 = zcl_cmd_disc_attr_resp_handler(param_1);
      }
      else {
        if (0xd < bVar1) {
          if (((bVar1 != 0x14) && (bVar1 != 0x16)) && (bVar1 != 0x12)) {
            return 0;
          }
          uVar3 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC28,uVar3,"ESP_ZIGBEE_CORE",
                        *(undefined1 *)(iVar2 + 0x13));
          return 0;
        }
        if (bVar1 != 9) {
          return 0;
        }
        iVar4 = zcl_cmd_read_report_config_resp_handler(param_1);
      }
      zb_zcl_send_default_handler(param_1,iVar2,iVar4 != 0);
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

