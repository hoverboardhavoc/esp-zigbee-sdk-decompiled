/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_report_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint esp_zb_zcl_report_attr_cmd_req(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  byte *pbVar8;
  int iVar9;
  byte bVar10;
  int iVar11;
  char cVar12;
  undefined2 uVar13;
  
  if ((*(byte *)(param_1 + 0x12) & 4) == 0) {
    cVar12 = '\x02';
  }
  else {
    cVar12 = '\x01';
  }
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 == 0) {
    uVar7 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC7,uVar7,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_report_attr_cmd_req",0xed,*(undefined1 *)(param_1 + 9));
    uVar5 = 0x105;
  }
  else {
    if ((*(byte *)(param_1 + 0x12) & 3) == 0) {
      *(undefined2 *)(param_1 + 0x14) = 0xffff;
    }
    iVar4 = zb_zcl_get_attr_desc_manuf_a
                      (*(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x10),cVar12,
                       *(undefined2 *)(param_1 + 0x16),*(undefined2 *)(param_1 + 0x14));
    if (iVar4 == 0) {
      uVar7 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC8,uVar7,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_report_attr_cmd_req",0xf4,*(undefined2 *)(param_1 + 0x16));
      uVar5 = 0x105;
    }
    else if ((*(byte *)(iVar4 + 3) & 4) == 0) {
      uVar7 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC9,uVar7,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_report_attr_cmd_req",0xf5,*(undefined2 *)(param_1 + 0x16));
      uVar5 = 0x106;
    }
    else if ((byte)(*(char *)(iVar4 + 2) + 0xb8U) < 10) {
      uVar7 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC10,uVar7,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_report_attr_cmd_req",0xf8,*(undefined2 *)(param_1 + 0x16));
      uVar5 = 0x106;
    }
    else {
      uVar1 = *(uint *)(iVar3 + 0x1b);
      for (bVar10 = 0; bVar10 < *(byte *)(iVar3 + 0x1a); bVar10 = bVar10 + 1) {
        if ((((*(short *)(uVar1 + 2) == *(short *)(param_1 + 0x10)) &&
             (cVar12 == *(char *)(uVar1 + 4))) &&
            (*(short *)(uVar1 + 6) == *(short *)(param_1 + 0x16))) &&
           (*(short *)(uVar1 + 0x36) == *(short *)(param_1 + 0x14))) {
          uVar5 = esp_zb_zcl_send_report_attr_command(param_1,uVar1);
          goto _L0;
        }
        uVar1 = uVar1 + 0x38;
      }
      uVar5 = 0;
_L0:
      if (*(int *)(iVar3 + 0x1b) + (uint)*(byte *)(iVar3 + 0x1a) * 0x38 <= uVar1) {
        iVar3 = zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zcl_command.c"
                          ,0x107);
        iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(iVar3 + 9));
        if (iVar4 == 0) {
          uVar13 = 0x104;
        }
        else {
          uVar13 = *(undefined2 *)(iVar4 + 1);
        }
        iVar4 = zb_buf_get_out_func();
        if (iVar4 == 0) {
          uVar7 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC5,uVar7,"ESP_ZIGBEE_COMMAND",
                        "esp_zb_zcl_config_report_cmd_req",0x113,"esp_zb_zcl_config_report_cmd_req")
          ;
          pbVar8 = (byte *)zb_zcl_get_ctx();
          uVar5 = (uint)*pbVar8;
          *pbVar8 = *pbVar8 + 1;
        }
        else {
          uVar5 = *(uint *)(iVar3 + 0x10);
          puVar6 = (undefined1 *)
                   zb_zcl_construct_general_command_header
                             (uVar5 >> 0x12 & 1,uVar5 >> 0x10 & 3,*(undefined2 *)(iVar3 + 0x14),
                              uVar5 >> 0x13 & 1,6);
          iVar11 = 0;
          while ((iVar11 < (int)(uint)*(ushort *)(iVar3 + 0x16) && (*(int *)(iVar3 + 0x18) != 0))) {
            piVar2 = (int *)(*(int *)(iVar3 + 0x18) + iVar11 * 0x14);
            if (*piVar2 == 0) {
              *puVar6 = 0;
              puVar6 = (undefined1 *)zb_put_next_htole16(puVar6 + 1,(short)piVar2[1]);
              *puVar6 = (char)piVar2[2];
              zb_put_next_htole16(puVar6 + 1,*(undefined2 *)((int)piVar2 + 10));
              puVar6 = (undefined1 *)zb_put_next_htole16((short)piVar2[3]);
              iVar9 = zb_zcl_is_analog_data_type((char)piVar2[2]);
              if (iVar9 != 0) {
                puVar6 = (undefined1 *)zb_zcl_put_value_to_packet(puVar6,(char)piVar2[2],piVar2[4]);
              }
            }
            else {
              *puVar6 = 1;
              zb_put_next_htole16(puVar6 + 1,(short)piVar2[1]);
              puVar6 = (undefined1 *)zb_put_next_htole16((short)piVar2[2]);
            }
            iVar11 = iVar11 + 1;
          }
          zb_zcl_finish_and_send_packet
                    (iVar4,puVar6,iVar3,*(undefined1 *)(iVar3 + 0xc),*(undefined1 *)(iVar3 + 8),
                     *(undefined1 *)(iVar3 + 9),uVar13,*(undefined2 *)(iVar3 + 0x10));
          uVar5 = zb_zcl_frame_get_sequence_number(iVar4);
        }
        return uVar5;
      }
    }
  }
  return uVar5;
}

