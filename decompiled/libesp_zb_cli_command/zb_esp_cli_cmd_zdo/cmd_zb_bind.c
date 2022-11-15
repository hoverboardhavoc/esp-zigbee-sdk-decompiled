/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> cmd_zb_bind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_bind(int param_1,undefined4 *param_2)

{
  bool bVar1;
  char *pcVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  size_t sVar8;
  undefined4 uVar9;
  
  if (param_1 != 7) {
    uVar9 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_L0,uVar9,&_LC3);
    return;
  }
  pcVar2 = (char *)*param_2;
  iVar5 = strcmp(pcVar2,"on");
  if (iVar5 == 0) {
    bVar1 = true;
  }
  else {
    iVar5 = strcmp(pcVar2,"off");
    if (iVar5 != 0) {
      uVar9 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC89,uVar9,&_LC3);
      iVar5 = 0;
      goto _L0;
    }
    bVar1 = false;
  }
  iVar5 = zb_buf_get_out_func();
  if (iVar5 == 0) {
    uVar9 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC38,uVar9,&_LC3);
    return;
  }
  iVar6 = zb_buf_get_tail_func(0x18);
  iVar7 = parse_address(param_2[1],iVar6,3);
  if (iVar7 == 0) {
    uVar9 = esp_log_timestamp();
    esp_log_write(1,&_LC3,&_LC90,uVar9,&_LC3);
  }
  else {
    iVar7 = sscan_uint8(param_2[2],iVar6 + 8);
    if (iVar7 == 0) {
      uVar9 = esp_log_timestamp();
      esp_log_write(1,&_LC3,&_LC91,uVar9,&_LC3);
    }
    else {
      cVar3 = parse_address(param_2[3],iVar6 + 0xd,1);
      *(char *)(iVar6 + 0xc) = cVar3;
      if (cVar3 == '\0') {
        uVar9 = esp_log_timestamp();
        esp_log_write(1,&_LC3,&_LC92,uVar9,&_LC3);
      }
      else {
        iVar7 = sscan_uint8(param_2[4],iVar6 + 0x15);
        if (iVar7 == 0) {
          uVar9 = esp_log_timestamp();
          esp_log_write(1,&_LC3,&_LC93,uVar9,&_LC3);
        }
        else {
          pcVar2 = (char *)param_2[5];
          sVar8 = strlen(pcVar2);
          iVar7 = parse_hex_str(pcVar2,sVar8 & 0xff,iVar6 + 10,2,1);
          if (iVar7 == 0) {
            uVar9 = esp_log_timestamp();
            esp_log_write(1,&_LC3,&_LC94,uVar9,&_LC3);
          }
          else {
            iVar6 = parse_address(param_2[6],iVar6 + 0x16,2);
            if (iVar6 == 0) {
              uVar9 = esp_log_timestamp();
              esp_log_write(1,&_LC3,&_LC95,uVar9,&_LC3);
            }
            else {
              iVar6 = get_free_ctx();
              if (iVar6 == 0) {
                uVar9 = esp_log_timestamp();
                esp_log_write(1,&_LC3,&_LC40,uVar9,&_LC3);
              }
              else {
                if (bVar1) {
                  uVar4 = zb_zdo_bind_req(iVar5,cmd_zb_bind_unbind_cb);
                  *(undefined1 *)(iVar6 + 4) = uVar4;
                }
                else {
                  uVar4 = zb_zdo_unbind_req(iVar5,cmd_zb_bind_unbind_cb);
                  *(undefined1 *)(iVar6 + 4) = uVar4;
                }
                if (*(char *)(iVar6 + 4) != -1) {
                  iVar5 = zb_schedule_app_alarm(cmd_zb_bind_unbind_timeout,0x14a);
                  if (iVar5 == 0) {
                    return;
                  }
                  uVar9 = esp_log_timestamp();
                  esp_log_write(1,&_LC3,&_LC42,uVar9,&_LC3);
                  invalidate_ctx(iVar6);
                  return;
                }
                uVar9 = esp_log_timestamp();
                esp_log_write(1,&_LC3,&_LC41,uVar9,&_LC3);
              }
              if (iVar6 != 0) {
                invalidate_ctx(iVar6);
              }
            }
          }
        }
      }
    }
  }
_L0:
  zb_buf_free_func(iVar5);
  return;
}

