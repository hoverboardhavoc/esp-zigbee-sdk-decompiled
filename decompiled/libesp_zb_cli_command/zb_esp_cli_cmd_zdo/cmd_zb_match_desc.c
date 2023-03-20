/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_match_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_match_desc(uint param_1,undefined4 *param_2)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined1 uStack_25;
  undefined4 uStack_24;
  
  uStack_24 = CONCAT22(5,(undefined2)uStack_24);
  if (param_1 < 4) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_L0,uVar4,&_LC3);
    return;
  }
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC38,uVar4,&_LC3);
    return;
  }
  puVar2 = (ushort *)zb_buf_initial_alloc_func(10);
  iVar3 = parse_hex_u16(*param_2,&uStack_24);
  if (iVar3 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC39,uVar4,&_LC3);
  }
  else {
    *(char *)puVar2 = (char)uStack_24;
    *(char *)((int)puVar2 + 1) = (char)(uStack_24 >> 8);
    uVar4 = esp_log_timestamp();
    esp_log_write(3,&_LC3,&_LC63,uVar4,&_LC3,uStack_24 & 0xffff);
    iVar3 = parse_hex_u16(param_2[1],&uStack_24);
    if (iVar3 == 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC64,uVar4,&_LC3);
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log_write(3,&_LC3,&_LC65,uVar4,&_LC3,uStack_24 & 0xffff);
      *(undefined1 *)(puVar2 + 1) = (undefined1)uStack_24;
      *(char *)((int)puVar2 + 3) = (char)(uStack_24 >> 8);
      iVar3 = parse_hex_u16(param_2[2],&uStack_24);
      if (iVar3 == 0) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,&_LC3,&_LC66,uVar4,&_LC3);
      }
      else {
        *(undefined1 *)(puVar2 + 2) = (undefined1)uStack_24;
        *(char *)((int)puVar2 + 5) = (char)(uStack_24 >> 8);
        uVar4 = esp_log_timestamp();
        esp_log_write(3,&_LC3,&_LC67,uVar4,&_LC3,uStack_24 & 0xffff);
        iVar5 = sscan_uint8(param_2[3],&uStack_25);
        if (iVar5 == 0) {
          uVar4 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC68,uVar4,&_LC3);
        }
        else {
          *(undefined1 *)(puVar2 + 3) = uStack_25;
          uVar4 = esp_log_timestamp();
          esp_log_write(3,&_LC3,&_LC69,uVar4,&_LC3,uStack_25);
          if ((byte)puVar2[3] == 0) {
            iVar5 = 2;
          }
          else {
            zb_buf_alloc_right_func(iVar1,(uint)(byte)puVar2[3] * 2 + -2);
            iVar5 = sscan_cluster_list(param_2 + 4,(char)puVar2[3],puVar2 + 4);
            if (iVar5 == 0) {
              uVar4 = esp_log_timestamp();
              esp_log_write(1,&_LC3,&_LC70,uVar4,&_LC3);
              goto _L0;
            }
            iVar5 = 0;
          }
          uStack_25 = 0;
          iVar6 = sscan_uint8(param_2[(byte)puVar2[3] + 4],&uStack_25);
          if (iVar6 == 0) {
            uVar4 = esp_log_timestamp();
            esp_log_write(1,&_LC3,&_LC71,uVar4,&_LC3);
          }
          else {
            *(undefined1 *)((int)puVar2 + 7) = uStack_25;
            uVar4 = esp_log_timestamp();
            esp_log_write(3,&_LC3,&_LC72,uVar4,&_LC3,*(undefined1 *)((int)puVar2 + 7));
            if (*(byte *)((int)puVar2 + 7) != 0) {
              zb_buf_alloc_right_func(iVar1,(uint)*(byte *)((int)puVar2 + 7) * 2 - iVar5);
              iVar5 = sscan_cluster_list(param_2 + (byte)puVar2[3] + 5,
                                         *(undefined1 *)((int)puVar2 + 7),
                                         puVar2 + (byte)puVar2[3] + 4);
              if (iVar5 == 0) {
                uVar4 = esp_log_timestamp();
                esp_log_write(1,&_LC3,&_LC73,uVar4,&_LC3);
                goto _L0;
              }
            }
            iVar5 = (byte)puVar2[3] + 5 + (uint)*(byte *)((int)puVar2 + 7);
            if (iVar5 + 2U == param_1) {
              iVar6 = strcmp((char *)param_2[iVar5],"timeout");
              if (iVar6 == 0) {
                iVar5 = sscanf((char *)param_2[iVar5 + 1],"%hd");
                if (iVar5 != 1) {
                  uStack_24 = CONCAT22(5,(undefined2)uStack_24);
                  uVar4 = esp_log_timestamp();
                  esp_log_write(1,&_LC3,&_LC76,uVar4,&_LC3);
                }
                uVar4 = esp_log_timestamp();
                esp_log_write(3,&_LC3,&_LC77,uVar4,&_LC3,uStack_24 >> 0x10);
              }
              else {
                uVar4 = esp_log_timestamp();
                esp_log_write(1,&_LC3,&_LC78,uVar4,&_LC3);
                iVar3 = 0;
              }
            }
            else {
              iVar3 = 0;
            }
            iVar5 = get_free_ctx();
            if (iVar5 == 0) {
              uVar4 = esp_log_timestamp();
              esp_log_write(1,&_LC3,&_LC40,uVar4,&_LC3);
            }
            else {
              *(bool *)(iVar5 + 6) = 0xfff7 < *puVar2;
              uVar4 = esp_log_timestamp();
              if (*(char *)(iVar5 + 6) == '\0') {
                pcVar7 = "unicast";
              }
              else {
                pcVar7 = "broadcast";
              }
              esp_log_write(3,&_LC3,&_LC79,uVar4,&_LC3,pcVar7);
              iVar6 = zb_zdo_match_desc_req(iVar1,cmd_zb_match_desc_cb);
              *(char *)(iVar5 + 4) = (char)iVar6;
              if (iVar6 != 0xff) {
                if ((iVar3 == 0) && (*(char *)(iVar5 + 6) != '\0')) {
                  return;
                }
                iVar1 = zb_schedule_app_alarm(cmd_zb_match_desc_timeout,(uStack_24 >> 0x10) * 0x42);
                if (iVar1 == 0) {
                  return;
                }
                uVar4 = esp_log_timestamp();
                esp_log_write(1,&_LC3,&_LC45,uVar4,&_LC3);
                invalidate_ctx(iVar5);
                return;
              }
              uVar4 = esp_log_timestamp(0xff);
              esp_log_write(3,&_LC3,&_LC80,uVar4,&_LC3);
            }
          }
        }
      }
    }
  }
_L0:
  zb_buf_free_func(iVar1);
  return;
}

