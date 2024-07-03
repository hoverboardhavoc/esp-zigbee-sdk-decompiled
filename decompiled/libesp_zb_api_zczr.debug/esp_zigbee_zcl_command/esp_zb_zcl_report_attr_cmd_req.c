/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_report_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint esp_zb_zcl_report_attr_cmd_req(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  byte *pbVar8;
  int iVar9;
  byte bVar10;
  int iVar11;
  int iVar12;
  undefined2 uVar13;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar2 == 0) {
    uVar7 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar7,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_report_attr_cmd_req",0x130,*(undefined1 *)(param_1 + 9));
    uVar4 = 0x105;
  }
  else {
    iVar3 = zb_zcl_get_attr_desc_manuf_a
                      (*(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x10),
                       *(undefined1 *)(param_1 + 0x12),*(undefined2 *)(param_1 + 0x14),0xffff);
    if (iVar3 == 0) {
      uVar7 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC8,uVar7,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_report_attr_cmd_req",0x135,*(undefined2 *)(param_1 + 0x14));
      uVar4 = 0x105;
    }
    else if ((*(byte *)(iVar3 + 3) & 4) == 0) {
      uVar7 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC9,uVar7,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_report_attr_cmd_req",0x136,*(undefined2 *)(param_1 + 0x14));
      uVar4 = 0x106;
    }
    else if ((byte)(*(char *)(iVar3 + 2) + 0xb8U) < 10) {
      uVar7 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC10,uVar7,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_report_attr_cmd_req",0x139,*(undefined2 *)(param_1 + 0x14));
      uVar4 = 0x106;
    }
    else {
      uVar4 = *(uint *)(iVar2 + 0x1b);
      for (bVar10 = 0; bVar10 < *(byte *)(iVar2 + 0x1a); bVar10 = bVar10 + 1) {
        if ((*(short *)(uVar4 + 2) == *(short *)(param_1 + 0x10)) &&
           (*(short *)(uVar4 + 6) == *(short *)(param_1 + 0x14))) {
          esp_zb_zcl_send_report_attr_command(param_1,uVar4);
          break;
        }
        uVar4 = uVar4 + 0x38;
      }
      if (*(int *)(iVar2 + 0x1b) + (uint)*(byte *)(iVar2 + 0x1a) * 0x38 <= uVar4) {
        iVar2 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zcl_command.c"
                          ,0x145);
        iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(iVar2 + 9));
        if (iVar3 == 0) {
          uVar13 = 0x104;
        }
        else {
          uVar13 = *(undefined2 *)(iVar3 + 1);
        }
        iVar3 = zb_buf_get_out_func();
        if (iVar3 == 0) {
          uVar7 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar7,"ESP_ZIGBEE_COMMAND",
                        "esp_zb_zcl_config_report_cmd_req",0x151,"esp_zb_zcl_config_report_cmd_req")
          ;
          pbVar8 = (byte *)zb_zcl_get_ctx();
          uVar4 = (uint)*pbVar8;
          *pbVar8 = *pbVar8 + 1;
        }
        else {
          if (**(int **)(iVar2 + 0x14) == 0) {
            puVar5 = (undefined1 *)zb_buf_reuse_func();
            *puVar5 = 0;
            pcVar6 = (char *)zb_zcl_get_ctx();
            cVar1 = *pcVar6;
            *pcVar6 = cVar1 + '\x01';
            puVar5[1] = cVar1;
            puVar5[2] = 6;
          }
          else {
            puVar5 = (undefined1 *)zb_buf_reuse_func();
            *puVar5 = 8;
            pcVar6 = (char *)zb_zcl_get_ctx();
            cVar1 = *pcVar6;
            *pcVar6 = cVar1 + '\x01';
            puVar5[1] = cVar1;
            puVar5[2] = 6;
          }
          puVar5 = puVar5 + 3;
          iVar12 = 0;
          while ((iVar12 < (int)(uint)*(ushort *)(iVar2 + 0x12) && (*(int *)(iVar2 + 0x14) != 0))) {
            *puVar5 = 0;
            iVar11 = iVar12 * 0x10;
            puVar5 = (undefined1 *)
                     zb_put_next_htole16(puVar5 + 1,
                                         *(undefined2 *)(*(int *)(iVar2 + 0x14) + iVar11 + 4));
            *puVar5 = *(undefined1 *)(*(int *)(iVar2 + 0x14) + iVar11 + 6);
            zb_put_next_htole16(puVar5 + 1,*(undefined2 *)(*(int *)(iVar2 + 0x14) + iVar11 + 8));
            puVar5 = (undefined1 *)
                     zb_put_next_htole16(*(undefined2 *)(*(int *)(iVar2 + 0x14) + iVar11 + 10));
            iVar9 = zb_zcl_is_analog_data_type(*(undefined1 *)(*(int *)(iVar2 + 0x14) + iVar11 + 6))
            ;
            if (iVar9 != 0) {
              iVar11 = *(int *)(iVar2 + 0x14) + iVar11;
              puVar5 = (undefined1 *)
                       zb_zcl_put_value_to_packet
                                 (puVar5,*(undefined1 *)(iVar11 + 6),*(undefined4 *)(iVar11 + 0xc));
            }
            iVar12 = iVar12 + 1;
          }
          zb_zcl_finish_and_send_packet
                    (iVar3,puVar5,iVar2,*(undefined1 *)(iVar2 + 0xc),*(undefined1 *)(iVar2 + 8),
                     *(undefined1 *)(iVar2 + 9),uVar13,*(undefined2 *)(iVar2 + 0x10));
          uVar4 = zb_zcl_frame_get_sequence_number(iVar3);
        }
        return uVar4;
      }
      uVar4 = 0;
    }
  }
  return uVar4;
}

