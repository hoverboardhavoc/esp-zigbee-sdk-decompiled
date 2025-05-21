/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_general.o -> zb_zcl_general_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_general_cmd_handler(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = zb_buf_get_tail_func(0x1b);
  if (iVar3 == 0) {
    iVar2 = 0;
  }
  else {
    bVar1 = *(byte *)(iVar3 + 0x13);
    if (bVar1 == 9) {
      iVar4 = zcl_cmd_read_report_config_resp_handler(param_1);
      iVar2 = 1;
    }
    else if (bVar1 < 10) {
      if (bVar1 == 4) {
        iVar4 = zcl_cmd_write_attr_resp_handler(param_1);
        iVar2 = 1;
      }
      else if (bVar1 < 5) {
        if (bVar1 == 0) {
          if (*(short *)(iVar3 + 0xf) == 0x15) {
            esp_zcl_commissioning_sync_with_attributes();
            iVar4 = 0;
            iVar2 = 0;
          }
          else {
            iVar4 = 0;
            iVar2 = 0;
          }
        }
        else if (bVar1 == 1) {
          if ((*(short *)(iVar3 + 0xf) == 10) &&
             (iVar2 = zb_zcl_time_server_read_attr_handle(param_1), iVar2 != 0)) {
            iVar4 = 0;
          }
          else {
            iVar4 = zcl_cmd_read_attr_resp_handler(param_1);
            iVar2 = 1;
          }
        }
        else {
          iVar4 = 0;
          iVar2 = 0;
        }
      }
      else if (bVar1 == 7) {
        iVar4 = zcl_cmd_config_report_resp_handler(param_1);
        iVar2 = 1;
      }
      else {
        iVar4 = 0;
        iVar2 = 0;
      }
    }
    else if (bVar1 == 0xb) {
      if (*(short *)(iVar3 + 0xf) == 0x19) {
        iVar4 = 0;
        iVar2 = 0;
      }
      else if (*(short *)(iVar3 + 0xf) == -0x400) {
        iVar4 = 0;
        iVar2 = 0;
      }
      else {
        iVar4 = zcl_cmd_default_resp_handler(param_1);
        iVar2 = 1;
      }
    }
    else if (bVar1 < 0xc) {
      if (bVar1 == 10) {
        zb_zcl_report_attr_cmd_handler(param_1);
        iVar3 = 0;
        iVar4 = 0;
        iVar2 = 1;
      }
      else {
        iVar4 = 0;
        iVar2 = 0;
      }
    }
    else if (bVar1 == 0xd) {
      iVar4 = zcl_cmd_disc_attr_resp_handler(param_1);
      iVar2 = 1;
    }
    else if (bVar1 < 0xd) {
      iVar4 = 0;
      iVar2 = 0;
    }
    else if (((bVar1 == 0x14) || (bVar1 == 0x16)) || (bVar1 == 0x12)) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC8,uVar5,0x10000,*(undefined1 *)(iVar3 + 0x13));
      iVar4 = 0;
      iVar2 = 0;
    }
    else {
      iVar4 = 0;
      iVar2 = 0;
    }
    if ((iVar2 != 0) && (iVar3 != 0)) {
      zb_zcl_send_default_handler(param_1,iVar3,iVar4 != 0);
    }
  }
  return iVar2;
}

