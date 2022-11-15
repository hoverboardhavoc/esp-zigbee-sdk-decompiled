/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
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
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined1 uStack_25;
  undefined4 uStack_24;
  
  uStack_24 = CONCAT22(5,(undefined2)uStack_24);
  if (param_1 < 4) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_L0,uVar5,&_LC3);
    return;
  }
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC38,uVar5,&_LC3);
    return;
  }
  puVar2 = (ushort *)zb_buf_initial_alloc_func(10);
  pcVar8 = (char *)*param_2;
  sVar3 = strlen(pcVar8);
  iVar4 = parse_hex_str(pcVar8,sVar3 & 0xff,&uStack_24,2,1);
  if (iVar4 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC57,uVar5,&_LC3);
  }
  else {
    *(char *)puVar2 = (char)uStack_24;
    *(char *)((int)puVar2 + 1) = (char)(uStack_24 >> 8);
    uVar5 = esp_log_timestamp();
    esp_log_write(3,&_LC3,&_LC63,uVar5,&_LC3,uStack_24 & 0xffff);
    pcVar8 = (char *)param_2[1];
    sVar3 = strlen(pcVar8);
    iVar4 = parse_hex_str(pcVar8,sVar3 & 0xff,&uStack_24,2,1);
    if (iVar4 == 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC64,uVar5,&_LC3);
    }
    else {
      uVar5 = esp_log_timestamp();
      esp_log_write(3,&_LC3,&_LC65,uVar5,&_LC3,uStack_24 & 0xffff);
      *(undefined1 *)(puVar2 + 1) = (undefined1)uStack_24;
      *(char *)((int)puVar2 + 3) = (char)(uStack_24 >> 8);
      pcVar8 = (char *)param_2[2];
      sVar3 = strlen(pcVar8);
      iVar4 = parse_hex_str(pcVar8,sVar3 & 0xff,&uStack_24,2,1);
      if (iVar4 == 0) {
        uVar5 = esp_log_timestamp();
        esp_log_write(1,&_LC3,&_LC66,uVar5,&_LC3);
      }
      else {
        *(undefined1 *)(puVar2 + 2) = (undefined1)uStack_24;
        *(char *)((int)puVar2 + 5) = (char)(uStack_24 >> 8);
        uVar5 = esp_log_timestamp();
        esp_log_write(3,&_LC3,&_LC67,uVar5,&_LC3,uStack_24 & 0xffff);
        iVar6 = sscan_uint8(param_2[3],&uStack_25);
        if (iVar6 == 0) {
          uVar5 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC68,uVar5,&_LC3);
        }
        else {
          *(undefined1 *)(puVar2 + 3) = uStack_25;
          uVar5 = esp_log_timestamp();
          esp_log_write(3,&_LC3,&_LC69,uVar5,&_LC3,uStack_25);
          if ((byte)puVar2[3] == 0) {
            iVar6 = 2;
          }
          else {
            zb_buf_alloc_right_func(iVar1,(uint)(byte)puVar2[3] * 2 + -2);
            iVar6 = sscan_cluster_list(param_2 + 4,(char)puVar2[3],puVar2 + 4);
            if (iVar6 == 0) {
              uVar5 = esp_log_timestamp();
              esp_log_write(1,&_LC3,&_LC70,uVar5,&_LC3);
              goto _L0;
            }
            iVar6 = 0;
          }
          uStack_25 = 0;
          iVar7 = sscan_uint8(param_2[(byte)puVar2[3] + 4],&uStack_25);
          if (iVar7 == 0) {
            uVar5 = esp_log_timestamp();
            esp_log_write(1,&_LC3,&_LC71,uVar5,&_LC3);
          }
          else {
            *(undefined1 *)((int)puVar2 + 7) = uStack_25;
            uVar5 = esp_log_timestamp();
            esp_log_write(3,&_LC3,&_LC72,uVar5,&_LC3,*(undefined1 *)((int)puVar2 + 7));
            if (*(byte *)((int)puVar2 + 7) != 0) {
              zb_buf_alloc_right_func(iVar1,(uint)*(byte *)((int)puVar2 + 7) * 2 - iVar6);
              iVar6 = sscan_cluster_list(param_2 + (byte)puVar2[3] + 5,
                                         *(undefined1 *)((int)puVar2 + 7),
                                         puVar2 + (byte)puVar2[3] + 4);
              if (iVar6 == 0) {
                uVar5 = esp_log_timestamp();
                esp_log_write(1,&_LC3,&_LC73,uVar5,&_LC3);
                goto _L0;
              }
            }
            iVar6 = (byte)puVar2[3] + 5 + (uint)*(byte *)((int)puVar2 + 7);
            if (iVar6 + 2U == param_1) {
              iVar7 = strcmp((char *)param_2[iVar6],"timeout");
              if (iVar7 == 0) {
                iVar6 = sscanf((char *)param_2[iVar6 + 1],"%hd");
                if (iVar6 != 1) {
                  uStack_24 = CONCAT22(5,(undefined2)uStack_24);
                  uVar5 = esp_log_timestamp();
                  esp_log_write(1,&_LC3,&_LC76,uVar5,&_LC3);
                }
                uVar5 = esp_log_timestamp();
                esp_log_write(3,&_LC3,&_LC77,uVar5,&_LC3,uStack_24 >> 0x10);
              }
              else {
                uVar5 = esp_log_timestamp();
                esp_log_write(1,&_LC3,&_LC78,uVar5,&_LC3);
                iVar4 = 0;
              }
            }
            else {
              iVar4 = 0;
            }
            iVar6 = get_free_ctx();
            if (iVar6 == 0) {
              uVar5 = esp_log_timestamp();
              esp_log_write(1,&_LC3,&_LC40,uVar5,&_LC3);
            }
            else {
              *(bool *)(iVar6 + 6) = 0xfff7 < *puVar2;
              uVar5 = esp_log_timestamp();
              if (*(char *)(iVar6 + 6) == '\0') {
                pcVar8 = "unicast";
              }
              else {
                pcVar8 = "broadcast";
              }
              esp_log_write(3,&_LC3,&_LC79,uVar5,&_LC3,pcVar8);
              iVar7 = zb_zdo_match_desc_req(iVar1,cmd_zb_match_desc_cb);
              *(char *)(iVar6 + 4) = (char)iVar7;
              if (iVar7 != 0xff) {
                if ((iVar4 == 0) && (*(char *)(iVar6 + 6) != '\0')) {
                  return;
                }
                iVar1 = zb_schedule_app_alarm(cmd_zb_match_desc_timeout,(uStack_24 >> 0x10) * 0x42);
                if (iVar1 == 0) {
                  return;
                }
                uVar5 = esp_log_timestamp();
                esp_log_write(1,&_LC3,&_LC42,uVar5,&_LC3);
                invalidate_ctx(iVar6);
                return;
              }
              uVar5 = esp_log_timestamp(0xff);
              esp_log_write(3,&_LC3,&_LC80,uVar5,&_LC3);
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

