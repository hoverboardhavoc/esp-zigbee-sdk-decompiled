/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr_report.o -> cmd_zb_subscribe
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_subscribe(uint param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char *pcVar10;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined2 uStack_38;
  undefined1 auStack_36 [2];
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined1 auStack_30 [8];
  uint uStack_28;
  undefined1 auStack_24 [12];
  
  iVar3 = strcmp((char *)*param_2,"on");
  if (((param_1 - 7 < 3) || (iVar3 != 0)) && ((param_1 == 7 || (iVar3 == 0)))) {
    uStack_28 = parse_address(param_2[1],auStack_30,1);
    if (uStack_28 == 0) {
      uVar8 = esp_log_timestamp();
      esp_log_write(1,&_L0,&_LC18,uVar8,&_L0);
    }
    else {
      iVar4 = sscan_uint8(param_2[2],auStack_24);
      if (iVar4 == 0) {
        uVar8 = esp_log_timestamp();
        esp_log_write(1,&_L0,&_LC19,uVar8,&_L0);
      }
      else {
        pcVar10 = (char *)param_2[3];
        sVar5 = strlen(pcVar10);
        iVar4 = parse_hex_str(pcVar10,sVar5 & 0xff,&uStack_3a,2,1);
        if (iVar4 == 0) {
          uVar8 = esp_log_timestamp();
          esp_log_write(1,&_L0,&_LC20,uVar8,&_L0);
        }
        else {
          pcVar10 = (char *)param_2[4];
          sVar5 = strlen(pcVar10);
          iVar4 = parse_hex_str(pcVar10,sVar5 & 0xff,&uStack_3c,2,1);
          if (iVar4 == 0) {
            uVar8 = esp_log_timestamp();
            esp_log_write(1,&_L0,&_LC21,uVar8,&_L0);
          }
          else {
            pcVar10 = (char *)param_2[5];
            sVar5 = strlen(pcVar10);
            iVar4 = parse_hex_str(pcVar10,sVar5 & 0xff,&uStack_38,2,1);
            if (iVar4 == 0) {
              uVar8 = esp_log_timestamp();
              esp_log_write(1,&_L0,&_LC22,uVar8,&_L0);
            }
            else {
              pcVar10 = (char *)param_2[6];
              sVar5 = strlen(pcVar10);
              iVar4 = parse_hex_str(pcVar10,sVar5 & 0xff,auStack_36,1,1);
              if (iVar4 == 0) {
                uVar8 = esp_log_timestamp();
                esp_log_write(1,&_L0,&_LC23,uVar8,&_L0);
              }
              else {
                if (iVar3 == 0) {
                  uStack_34 = 1;
                  uStack_32 = 0x3c;
                }
                else {
                  uStack_34 = 0xf;
                  uStack_32 = 0xffff;
                }
                if ((param_1 < 8) || (iVar3 = sscanf((char *)param_2[7],"%hu"), iVar3 != 0)) {
                  if ((param_1 < 9) || (iVar3 = sscanf((char *)param_2[8],"%hu"), iVar3 != 0)) {
                    iVar3 = zb_buf_get_out_func();
                    if (iVar3 == 0) {
                      uVar8 = esp_log_timestamp();
                      esp_log_write(1,&_L0,&_LC27,uVar8,&_L0);
                    }
                    else {
                      puVar6 = (undefined1 *)get_free_tsn_ctx();
                      if (puVar6 == (undefined1 *)0x0) {
                        uVar8 = esp_log_timestamp();
                        esp_log_write(1,&_L0,&_LC28,uVar8,&_L0);
                        zb_buf_free_func(iVar3);
                      }
                      else {
                        puVar6[1] = 1;
                        puVar7 = (undefined1 *)zb_zcl_get_ctx();
                        *puVar6 = *puVar7;
                        uStack_44 = 0;
                        uStack_40 = 0;
                        puVar7 = (undefined1 *)zb_buf_reuse_func(iVar3);
                        *puVar7 = 0;
                        pcVar10 = (char *)zb_zcl_get_ctx();
                        cVar1 = *pcVar10;
                        *pcVar10 = cVar1 + '\x01';
                        puVar7[1] = cVar1;
                        puVar7[2] = 6;
                        puVar7[3] = 0;
                        puVar7 = (undefined1 *)zb_put_next_htole16(puVar7 + 4,uStack_38);
                        *puVar7 = auStack_36[0];
                        zb_put_next_htole16(puVar7 + 1,uStack_34);
                        uVar8 = zb_put_next_htole16(uStack_32);
                        iVar4 = zb_zcl_is_analog_data_type(auStack_36[0]);
                        if (iVar4 != 0) {
                          uVar8 = zb_zcl_put_value_to_packet(uVar8,auStack_36[0],&uStack_44);
                        }
                        uVar2 = uStack_28;
                        uVar9 = zb_cli_get_endpoint();
                        zb_zcl_finish_and_send_packet
                                  (iVar3,uVar8,auStack_30,uVar2 & 0xff,auStack_24[0],uVar9,uStack_3c
                                   ,uStack_3a);
                        iVar3 = zb_schedule_app_alarm
                                          (cmd_zb_subscribe_unsubscribe_timeout,*puVar6,0x14a);
                        if (iVar3 != 0) {
                          uVar8 = esp_log_timestamp();
                          esp_log_write(1,&_L0,&_LC29,uVar8,&_L0);
                          invalidate_ctx(puVar6);
                        }
                      }
                    }
                  }
                  else {
                    uVar8 = esp_log_timestamp();
                    esp_log_write(1,&_L0,&_LC26,uVar8,&_L0);
                  }
                }
                else {
                  uVar8 = esp_log_timestamp();
                  esp_log_write(1,&_L0,&_LC25,uVar8,&_L0);
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    uVar8 = esp_log_timestamp();
    esp_log_write(1,&_L0,&_LC17,uVar8,&_L0);
  }
  return;
}

