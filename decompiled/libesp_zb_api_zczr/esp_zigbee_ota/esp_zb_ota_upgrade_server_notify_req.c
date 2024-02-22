/*
 * Last changed at upstream commit a67793c7af0a02d983345915fecc5d8fce7a0945
 * https://github.com/espressif/esp-zigbee-sdk/commit/a67793c7af0a02d983345915fecc5d8fce7a0945
 * Upstream date: 2024-02-22 20:57:09 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.2(af7a8c4d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ota.o -> esp_zb_ota_upgrade_server_notify_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ota_upgrade_server_notify_req(undefined1 *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  
  iVar2 = zb_zcl_get_ctx();
  if (*(int *)(iVar2 + 0xb8) == 0) {
    zb_zcl_ota_upgrade_init_server(*param_1,next_data_req_cb);
  }
  iVar2 = zb_zcl_get_attr_desc_a(*param_1,0x19,1,0xfff0);
  if (iVar2 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar5,0x10000,"esp_zb_ota_upgrade_server_notify_req",0x6d);
    uVar5 = 0xffffffff;
  }
  else {
    s_ota_server_variable = *(int *)(iVar2 + 6);
    if (s_ota_server_variable == 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC1,uVar5,0x10000,"esp_zb_ota_upgrade_server_notify_req",0x6f);
      uVar5 = 0x105;
    }
    else if ((byte)param_1[1] < *(byte *)(s_ota_server_variable + 8)) {
      puVar3 = (undefined1 *)malloc(0x38);
      if (*(int *)(param_1 + 0x14) == 0) {
        uVar5 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC7,uVar5,0x10000,"esp_zb_ota_upgrade_server_notify_req",0x74);
        uVar5 = 0x102;
      }
      else {
        *puVar3 = 0x1e;
        puVar3[1] = 0xf1;
        puVar3[2] = 0xee;
        puVar3[3] = 0xb;
        puVar3[4] = 0;
        puVar3[5] = 1;
        puVar3[6] = 0x38;
        puVar3[7] = 0;
        puVar3[8] = 0x10;
        puVar3[9] = 0;
        uVar1 = *(undefined2 *)(param_1 + 8);
        puVar3[10] = (char)uVar1;
        puVar3[0xb] = (char)((ushort)uVar1 >> 8);
        uVar1 = *(undefined2 *)(param_1 + 10);
        puVar3[0xc] = (char)uVar1;
        puVar3[0xd] = (char)((ushort)uVar1 >> 8);
        uVar5 = *(undefined4 *)(param_1 + 0xc);
        puVar3[0xe] = (char)uVar5;
        puVar3[0xf] = (char)((uint)uVar5 >> 8);
        puVar3[0x10] = (char)((uint)uVar5 >> 0x10);
        puVar3[0x11] = (char)((uint)uVar5 >> 0x18);
        puVar3[0x12] = 2;
        puVar3[0x13] = 0;
        memset(puVar3 + 0x14,0,0x20);
        iVar2 = *(int *)(param_1 + 0x10) + 0x38;
        puVar3[0x34] = (char)iVar2;
        puVar3[0x35] = (char)((uint)iVar2 >> 8);
        puVar3[0x36] = (char)((uint)iVar2 >> 0x10);
        puVar3[0x37] = (char)((uint)iVar2 >> 0x18);
        s_ota_next_data_cb = *(undefined4 *)(param_1 + 0x14);
        iVar2 = zb_buf_get_out_func();
        if (iVar2 == 0) {
          __assert_func("//home/xieqinan/ESP/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_ota.c",
                        0x83,"esp_zb_ota_upgrade_server_notify_req","bufid");
        }
        else {
          puVar4 = (undefined1 *)zb_buf_get_tail_func(0x10);
          *puVar4 = *param_1;
          puVar4[1] = param_1[1];
          *(undefined1 **)(puVar4 + 4) = puVar3;
          *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)(param_1 + 4);
          puVar4[8] = param_1[2];
          iVar2 = zb_zcl_ota_upgrade_insert_file(iVar2);
          if (iVar2 == 0) {
            return 0;
          }
        }
        uVar5 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC10,uVar5,0x10000,"esp_zb_ota_upgrade_server_notify_req",0x85,
                      param_1[1]);
        uVar5 = 0x102;
      }
    }
    else {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC6,uVar5,0x10000,"esp_zb_ota_upgrade_server_notify_req",0x70,
                    *(byte *)(s_ota_server_variable + 8) - 1);
      uVar5 = 0x102;
    }
  }
  return uVar5;
}

