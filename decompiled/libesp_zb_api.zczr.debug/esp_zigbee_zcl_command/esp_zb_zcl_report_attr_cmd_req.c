/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_report_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint esp_zb_zcl_report_attr_cmd_req(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  byte *pbVar7;
  int iVar8;
  byte bVar9;
  int iVar10;
  char cVar11;
  undefined2 uVar12;
  
  if ((*(byte *)(param_1 + 0x12) & 4) == 0) {
    cVar11 = '\x02';
  }
  else {
    cVar11 = '\x01';
  }
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar2 == 0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC5,uVar6,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_report_attr_cmd_req",0xe2,*(undefined1 *)(param_1 + 9));
    uVar4 = 0x105;
  }
  else {
    if ((*(byte *)(param_1 + 0x12) & 3) == 0) {
      *(undefined2 *)(param_1 + 0x14) = 0xffff;
    }
    iVar3 = zb_zcl_get_attr_desc_manuf_a
                      (*(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x10),cVar11,
                       *(undefined2 *)(param_1 + 0x16),*(undefined2 *)(param_1 + 0x14));
    if (iVar3 == 0) {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar6,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_report_attr_cmd_req",0xe9,*(undefined2 *)(param_1 + 0x16));
      uVar4 = 0x105;
    }
    else if ((*(byte *)(iVar3 + 3) & 4) == 0) {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC7,uVar6,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_report_attr_cmd_req",0xea,*(undefined2 *)(param_1 + 0x16));
      uVar4 = 0x106;
    }
    else if ((byte)(*(char *)(iVar3 + 2) + 0xb8U) < 10) {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC8,uVar6,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_report_attr_cmd_req",0xed,*(undefined2 *)(param_1 + 0x16));
      uVar4 = 0x106;
    }
    else {
      uVar4 = *(uint *)(iVar2 + 0x1b);
      for (bVar9 = 0; bVar9 < *(byte *)(iVar2 + 0x1a); bVar9 = bVar9 + 1) {
        if ((((*(short *)(uVar4 + 2) == *(short *)(param_1 + 0x10)) &&
             (cVar11 == *(char *)(uVar4 + 4))) &&
            (*(short *)(uVar4 + 6) == *(short *)(param_1 + 0x16))) &&
           (*(short *)(uVar4 + 0x36) == *(short *)(param_1 + 0x14))) {
          esp_zb_zcl_send_report_attr_command(param_1,uVar4);
          break;
        }
        uVar4 = uVar4 + 0x38;
      }
      if (*(int *)(iVar2 + 0x1b) + (uint)*(byte *)(iVar2 + 0x1a) * 0x38 <= uVar4) {
        iVar2 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zcl_command.c"
                          ,0xfc);
        iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(iVar2 + 9));
        if (iVar3 == 0) {
          uVar12 = 0x104;
        }
        else {
          uVar12 = *(undefined2 *)(iVar3 + 1);
        }
        iVar3 = zb_buf_get_out_func();
        if (iVar3 == 0) {
          uVar6 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar6,"ESP_ZIGBEE_COMMAND",
                        "esp_zb_zcl_config_report_cmd_req",0x108,"esp_zb_zcl_config_report_cmd_req")
          ;
          pbVar7 = (byte *)zb_zcl_get_ctx();
          uVar4 = (uint)*pbVar7;
          *pbVar7 = *pbVar7 + 1;
        }
        else {
          uVar4 = *(uint *)(iVar2 + 0x10);
          puVar5 = (undefined1 *)
                   zb_zcl_construct_general_command_header
                             (uVar4 >> 0x12 & 1,uVar4 >> 0x10 & 3,*(undefined2 *)(iVar2 + 0x14),
                              uVar4 >> 0x13 & 1,6);
          iVar10 = 0;
          while ((iVar10 < (int)(uint)*(ushort *)(iVar2 + 0x16) && (*(int *)(iVar2 + 0x18) != 0))) {
            piVar1 = (int *)(*(int *)(iVar2 + 0x18) + iVar10 * 0x14);
            if (*piVar1 == 0) {
              *puVar5 = 0;
              puVar5 = (undefined1 *)zb_put_next_htole16(puVar5 + 1,(short)piVar1[1]);
              *puVar5 = (char)piVar1[2];
              zb_put_next_htole16(puVar5 + 1,*(undefined2 *)((int)piVar1 + 10));
              puVar5 = (undefined1 *)zb_put_next_htole16((short)piVar1[3]);
              iVar8 = zb_zcl_is_analog_data_type((char)piVar1[2]);
              if (iVar8 != 0) {
                puVar5 = (undefined1 *)zb_zcl_put_value_to_packet(puVar5,(char)piVar1[2],piVar1[4]);
              }
            }
            else {
              *puVar5 = 1;
              zb_put_next_htole16(puVar5 + 1,(short)piVar1[1]);
              puVar5 = (undefined1 *)zb_put_next_htole16((short)piVar1[2]);
            }
            iVar10 = iVar10 + 1;
          }
          zb_zcl_finish_and_send_packet
                    (iVar3,puVar5,iVar2,*(undefined1 *)(iVar2 + 0xc),*(undefined1 *)(iVar2 + 8),
                     *(undefined1 *)(iVar2 + 9),uVar12,*(undefined2 *)(iVar2 + 0x10));
          uVar4 = zb_zcl_frame_get_sequence_number(iVar3);
        }
        return uVar4;
      }
      uVar4 = 0;
    }
  }
  return uVar4;
}

