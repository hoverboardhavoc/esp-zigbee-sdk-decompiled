/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_general_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zb_zcl_general_cmd_handler(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if (*(char *)(iVar1 + 0x14) == '\x01') {
    if (zb_core_action_cb == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (uint)*(byte *)(iVar1 + 0x13);
      if (uVar2 < 0x17) {
        if (uVar2 < 7) {
          if (uVar2 == 1) {
            iVar3 = zcl_cmd_read_attr_resp_handler(param_1);
          }
          else {
            if (uVar2 != 4) {
              return 0;
            }
            iVar3 = zcl_cmd_write_attr_resp_handler(param_1);
          }
        }
        else {
          uVar2 = 1 << (uVar2 & 0x1f);
          if ((uVar2 & 0x542000) != 0) {
            uVar4 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC25,uVar4,"ESP_ZIGBEE_CORE",
                          *(undefined1 *)(iVar1 + 0x13));
            return 0;
          }
          if ((uVar2 & 0x200) == 0) {
            if ((uVar2 >> 7 & 1) == 0) {
              return 0;
            }
            iVar3 = zcl_cmd_config_report_resp_handler(param_1);
          }
          else {
            iVar3 = zcl_cmd_read_report_config_resp_handler(param_1);
          }
        }
        uVar2 = (uint)*(byte *)(iVar1 + 0x17);
        if (uVar2 == 0) {
          uVar2 = zb_zcl_send_default_handler(param_1,iVar1,iVar3 != 0);
        }
      }
      else {
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

